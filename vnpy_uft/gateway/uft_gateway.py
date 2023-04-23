import sys
from datetime import datetime
from typing import Dict, List
from pathlib import Path

from vnpy.event import EventEngine
from vnpy.trader.constant import (
    Direction,
    Offset,
    Exchange,
    OrderType,
    Product,
    Status,
    OptionType
)
from vnpy.trader.gateway import BaseGateway
from vnpy.trader.object import (
    TickData,
    OrderData,
    TradeData,
    PositionData,
    AccountData,
    ContractData,
    OrderRequest,
    CancelRequest,
    SubscribeRequest,
)
from vnpy.trader.utility import get_folder_path, TRADER_DIR, ZoneInfo
from vnpy.trader.event import EVENT_TIMER

from ..api import (
    FUTURES_LICENSE,
    OPTION_LICENSE,
    MdApi,
    TdApi,
    HS_EI_CFFEX,
    HS_EI_SHFE,
    HS_EI_DCE,
    HS_EI_CZCE,
    HS_EI_INE,
    HS_EI_GFEX,
    HS_EI_SZSE,
    HS_EI_SSE,
    HS_OS_Reported,
    HS_OS_Abandoned,
    HS_OS_PartsTraded,
    HS_OS_Traded,
    HS_OS_Canceled,
    HS_OS_CanceledWithPartsTraded,
    HS_DC_Buy,
    HS_DC_Sell,
    HS_CT_Limit,
    HS_CT_Market,
    HS_OF_Open,
    HS_OF_Close,
    HS_OF_CloseToday,
    HS_PTYPE_Futures,
    HS_PTYPE_OptFutu,
    HS_PTYPE_OptStock,
    HS_PTYPE_Combination,
    HS_OT_CallOptions,
    HS_OT_PutOptions,
    HS_TERT_RESUME
)


# 委托状态映射
STATUS_UFT2VT: Dict[str, Status] = {
    HS_OS_Reported: Status.NOTTRADED,
    HS_OS_Abandoned: Status.REJECTED,
    HS_OS_PartsTraded: Status.PARTTRADED,
    HS_OS_Traded: Status.ALLTRADED,
    HS_OS_Canceled: Status.CANCELLED,
    HS_OS_CanceledWithPartsTraded: Status.CANCELLED
}

# 多空方向映射
DIRECTION_VT2UFT: Dict[Direction, str] = {
    Direction.LONG: HS_DC_Buy,
    Direction.SHORT: HS_DC_Sell
}
DIRECTION_UFT2VT: Dict[str, Direction] = {v: k for k, v in DIRECTION_VT2UFT.items()}

# 委托类型映射
ORDERTYPE_VT2UFT: Dict[OrderType, str] = {
    OrderType.LIMIT: HS_CT_Limit,
    OrderType.MARKET: HS_CT_Market
}
ORDERTYPE_UFT2VT: Dict[str, OrderType] = {v: k for k, v in ORDERTYPE_VT2UFT.items()}

# 开平方向映射
OFFSET_VT2UFT: Dict[Offset, str] = {
    Offset.OPEN: HS_OF_Open,
    Offset.CLOSE: HS_OF_Close,
    Offset.CLOSETODAY: HS_OF_CloseToday
}
OFFSET_UFT2VT: Dict[str, Offset] = {v: k for k, v in OFFSET_VT2UFT.items()}
OFFSET_VT2UFT[Offset.CLOSEYESTERDAY] = HS_OF_Close

# 交易所映射
EXCHANGE_UFT2VT: Dict[str, Exchange] = {
    HS_EI_CFFEX: Exchange.CFFEX,
    HS_EI_SHFE: Exchange.SHFE,
    HS_EI_CZCE: Exchange.CZCE,
    HS_EI_DCE: Exchange.DCE,
    HS_EI_INE: Exchange.INE,
    HS_EI_GFEX: Exchange.GFEX,
    HS_EI_SSE: Exchange.SSE,
    HS_EI_SZSE: Exchange.SZSE,
}
EXCHANGE_VT2UFT: Dict[Exchange, str] = {v: k for k, v in EXCHANGE_UFT2VT.items()}

# 产品类型映射
PRODUCT_UFT2VT: Dict[str, Product] = {
    HS_PTYPE_Futures: Product.FUTURES,
    HS_PTYPE_OptFutu: Product.OPTION,
    HS_PTYPE_OptStock: Product.OPTION,
    HS_PTYPE_Combination: Product.SPREAD
}

# 期权类型映射
OPTIONTYPE_UFT2VT: Dict[str, OptionType] = {
    HS_OT_CallOptions: OptionType.CALL,
    HS_OT_PutOptions: OptionType.PUT
}

# 其他常量
MAX_FLOAT = sys.float_info.max                  # 浮点数极限值
CHINA_TZ = ZoneInfo("Asia/Shanghai")       # 中国时区

# 合约数据全局缓存字典
symbol_contract_map: Dict[str, ContractData] = {}


class UftGateway(BaseGateway):
    """
    VeighNa基于恒生极速API开发的交易接口。
    """

    default_name: str = "UFT"

    default_setting: Dict[str, str] = {
        "用户名": "",
        "密码": "",
        "行情服务器": "",
        "交易服务器": "",
        "服务器类型": ["期货", "ETF期权"],
        "产品名称": "",
        "授权编码": "",
        "委托类型": "q"
    }

    exchanges: List[Exchange] = list(EXCHANGE_UFT2VT.values())

    def __init__(self, event_engine: EventEngine, gateway_name: str) -> None:
        """构造函数"""
        super().__init__(event_engine, gateway_name)

        self.td_api: "UftTdApi" = UftTdApi(self)
        self.md_api: "UftMdApi" = UftMdApi(self)
        self.server: str = ""

    def connect(self, setting: dict) -> None:
        """连接交易接口"""
        userid: str = setting["用户名"]
        password: str = setting["密码"]
        md_address: str = setting["行情服务器"]
        td_address: str = setting["交易服务器"]
        self.server: str = setting["服务器类型"]
        appid: str = setting["产品名称"]
        auth_code: str = setting["授权编码"]
        application_type: str = setting["委托类型"]

        if not md_address.startswith("tcp://"):
            md_address = "tcp://" + md_address

        if not td_address.startswith("tcp://"):
            td_address = "tcp://" + td_address

        license_path: Path = TRADER_DIR.joinpath("license.dat")

        if license_path.exists():
            server_license: str = str(license_path)
        else:
            if self.server == "期货":
                server_license: str = FUTURES_LICENSE
            else:
                server_license: str = OPTION_LICENSE

        self.td_api.connect(
            td_address,
            server_license,
            userid,
            password,
            auth_code,
            appid,
            application_type
        )
        self.md_api.connect(
            md_address,
            server_license
        )

        self.init_query()

    def subscribe(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        self.md_api.subscribe(req)

    def send_order(self, req: OrderRequest) -> str:
        """委托下单"""
        return self.td_api.send_order(req)

    def cancel_order(self, req: CancelRequest) -> None:
        """委托撤单"""
        self.td_api.cancel_order(req)

    def query_account(self) -> None:
        """查询资金"""
        self.td_api.query_account()

    def query_position(self) -> None:
        """查询持仓"""
        self.td_api.query_position()

    def close(self) -> None:
        """关闭接口"""
        self.td_api.close()
        self.md_api.close()

    def write_error(self, msg: str, error: dict) -> None:
        """输出错误信息日志"""
        error_id: int = error["ErrorID"]
        error_msg: str = error["ErrorMsg"]
        msg: str = f"{msg}，代码：{error_id}，信息：{error_msg}"
        self.write_log(msg)

    def process_timer_event(self, event) -> None:
        """定时事件处理"""
        self.count += 1
        if self.count < 2:
            return
        self.count = 0

        func = self.query_functions.pop(0)
        func()
        self.query_functions.append(func)

    def init_query(self) -> None:
        """初始化查询任务"""
        self.count: int = 0
        self.query_functions: list = [self.query_account, self.query_position]
        self.event_engine.register(EVENT_TIMER, self.process_timer_event)


class UftMdApi(MdApi):
    """"""

    def __init__(self, gateway: UftGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: UftGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.reqid: int = 0

        self.connect_status: bool = False
        self.subscribed: set = set()

        self.userid: str = ""
        self.password: str = ""

    def onFrontConnected(self) -> None:
        """服务器连接成功回报"""
        self.gateway.write_log("行情服务器连接成功")

    def onFrontDisconnected(self, reason: int) -> None:
        """服务器连接断开回报"""
        msg: str = self.getApiErrorMsg(reason)
        self.gateway.write_log(f"行情服务器连接断开，原因：{reason}，{msg}")

    def onRspDepthMarketDataSubscribe(
        self,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """订阅行情回报"""
        if not error or not error["ErrorID"]:
            return

        self.gateway.write_error("行情订阅失败", error)

    def onRtnDepthMarketData(self, data: dict) -> None:
        """行情数据推送"""
        # 过滤没有时间戳的异常行情数据
        if not data["UpdateTime"]:
            return

        symbol: str = data["InstrumentID"]
        contract: ContractData = symbol_contract_map.get(symbol, None)
        if not contract:
            return

        timestamp: str = f"{data['TradingDay']} {data['UpdateTime']}000"

        # 过滤时间戳异常的行情数据
        try:
            dt: datetime = datetime.strptime(timestamp, "%Y%m%d %H%M%S%f")
        except ValueError:
            return

        dt: datetime = dt.replace(tzinfo=CHINA_TZ)

        tick: TickData = TickData(
            symbol=symbol,
            exchange=contract.exchange,
            datetime=dt,
            name=contract.name,
            volume=data["TradeVolume"],
            open_interest=data["OpenInterest"],
            last_price=data["LastPrice"],
            limit_up=data["UpperLimitPrice"],
            limit_down=data["LowerLimitPrice"],
            open_price=adjust_price(data["OpenPrice"]),
            high_price=adjust_price(data["HighestPrice"]),
            low_price=adjust_price(data["LowestPrice"]),
            pre_close=adjust_price(data["PreClosePrice"]),
            bid_price_1=adjust_price(data["BidPrice1"]),
            ask_price_1=adjust_price(data["AskPrice1"]),
            bid_volume_1=data["BidVolume1"],
            ask_volume_1=data["AskVolume1"],
            gateway_name=self.gateway_name
        )

        if data["BidVolume2"] or data["AskVolume2"]:
            tick.bid_price_2 = adjust_price(data["BidPrice2"])
            tick.bid_price_3 = adjust_price(data["BidPrice3"])
            tick.bid_price_4 = adjust_price(data["BidPrice4"])
            tick.bid_price_5 = adjust_price(data["BidPrice5"])

            tick.ask_price_2 = adjust_price(data["AskPrice2"])
            tick.ask_price_3 = adjust_price(data["AskPrice3"])
            tick.ask_price_4 = adjust_price(data["AskPrice4"])
            tick.ask_price_5 = adjust_price(data["AskPrice5"])

            tick.bid_volume_2 = adjust_price(data["BidVolume2"])
            tick.bid_volume_3 = adjust_price(data["BidVolume3"])
            tick.bid_volume_4 = adjust_price(data["BidVolume4"])
            tick.bid_volume_5 = adjust_price(data["BidVolume5"])

            tick.ask_volume_2 = adjust_price(data["AskVolume2"])
            tick.ask_volume_3 = adjust_price(data["AskVolume3"])
            tick.ask_volume_4 = adjust_price(data["AskVolume4"])
            tick.ask_volume_5 = adjust_price(data["AskVolume5"])

        self.gateway.on_tick(tick)

    def connect(self, address: str, server_license: str) -> None:
        """连接服务器"""
        if not self.connect_status:
            path = get_folder_path(self.gateway_name.lower())
            self.newMdApi((str(path) + "\\Md").encode("GBK"))

            self.registerFront(address)

            self.init(
                server_license,
                "",
                "",
                "",
                ""
            )

            self.connect_status = True

    def subscribe(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        symbol: str = req.symbol

        # 过滤重复的订阅
        if symbol in self.subscribed:
            return

        if self.connect_status:
            uft_req: dict = {
                "ExchangeID": EXCHANGE_VT2UFT[req.exchange],
                "InstrumentID": symbol
            }

            self.reqid += 1
            self.reqDepthMarketDataSubscribe(uft_req, self.reqid)

            self.subscribed.add(symbol)

    def close(self) -> None:
        """关闭连接"""
        if self.connect_status:
            self.exit()


class UftTdApi(TdApi):
    """"""

    def __init__(self, gateway: UftGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: UftGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.reqid: int = 0
        self.order_ref: int = 0

        self.connect_status: bool = False
        self.login_status: bool = False
        self.auth_staus: bool = False
        self.login_failed: bool = False

        self.userid: str = ""
        self.password: str = ""
        self.auth_code: str = ""
        self.appid: str = ""
        self.application_type: str = ""

        self.frontid: int = 0
        self.sessionid: int = 0

        self.positions: Dict[str, PositionData] = {}
        self.orders: Dict[str, OrderData] = {}

    def onFrontConnected(self) -> None:
        """服务器连接成功回报"""
        self.gateway.write_log("交易服务器连接成功")

        if self.auth_code:
            self.authenticate()
        else:
            self.login()

    def onFrontDisconnected(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.login_status = False

        msg: str = self.getApiErrorMsg(reason)
        self.gateway.write_log(f"交易服务器连接断开，原因：{reason}，{msg}")

    def onRspAuthenticate(
        self,
        data: dict,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """用户授权验证回报"""
        if not error["ErrorID"]:
            self.auth_staus = True
            self.gateway.write_log("交易服务器授权验证成功")
            self.login()
        else:
            self.gateway.write_error("交易服务器授权验证失败", error)

    def onRspUserLogin(
        self,
        data: dict,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """用户登录请求回报"""
        if not error["ErrorID"]:
            self.sessionid = data["SessionID"]
            self.login_status = True
            self.gateway.write_log("交易服务器登录成功")

            self.reqid += 1
            self.reqQryInstrument({}, self.reqid)
            self.reqid += 1
            self.reqBillConfirm({}, self.reqid)

            self.query_order()
            self.query_trade()
        else:
            self.login_failed = True

            self.gateway.write_error("交易服务器登录失败", error)

    def query_order(self) -> None:
        """查询委托"""
        self.reqid += 1
        self.reqQryOrder({}, self.reqid)

    def onRspQryOrder(
        self,
        data: dict,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """委托查询回报"""
        if not data and last:
            self.gateway.write_log("委托信息查询成功")
            return

        self.update_order(data)

    def onRspQryTrade(
        self,
        data: dict,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """成交委托查询回报"""
        if not data and last:
            self.gateway.write_log("成交信息查询成功")
            return

        self.update_trade(data)

    def query_trade(self) -> None:
        """查询成交委托"""
        self.reqid += 1
        self.reqQryTrade({}, self.reqid)

    def onRspErrorOrderInsert(
        self,
        data: dict,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """失败委托查询回报"""
        self.gateway.write_error("委托下单失败", error)

        order_ref: str = data["OrderRef"]
        orderid: str = f"{self.sessionid}_{order_ref}"

        symbol: str = data["InstrumentID"]
        exchange: Exchange = EXCHANGE_UFT2VT[data["ExchangeID"]]

        order: OrderData = OrderData(
            symbol=symbol,
            exchange=exchange,
            orderid=orderid,
            direction=DIRECTION_UFT2VT[data["Direction"]],
            offset=OFFSET_UFT2VT.get(data["OffsetFlag"], Offset.NONE),
            price=data["OrderPrice"],
            volume=data["OrderVolume"],
            status=Status.REJECTED,
            gateway_name=self.gateway_name
        )
        self.gateway.on_order(order)

        self.gateway.write_error("交易委托失败", error)

    def onRspOrderAction(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """撤单委托查询回报"""
        if error["ErrorID"]:
            self.gateway.write_error("交易撤单失败", error)

    def onRspBillConfirm(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """客户账单确认"""
        self.gateway.write_log("结算信息确认成功")

    def onRspQryPosition(
        self,
        data: dict,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """持仓查询回报"""
        if not data and last:
            for position in self.positions.values():
                self.gateway.on_position(position)

            self.positions.clear()
            return

        # 必须已经收到了合约信息后才能处理
        symbol: str = data["InstrumentID"]
        contract: ContractData = symbol_contract_map.get(symbol, None)

        if contract:
            # 获取之前缓存的持仓数据缓存
            key: str = f"{data['InstrumentID'], data['Direction']}"
            position: PositionData = self.positions.get(key, None)
            if not position:
                position: PositionData = PositionData(
                    symbol=data["InstrumentID"],
                    exchange=EXCHANGE_UFT2VT[data["ExchangeID"]],
                    direction=DIRECTION_UFT2VT[data["Direction"]],
                    gateway_name=self.gateway_name
                )
                self.positions[key] = position

            # 计算昨仓
            if self.gateway.server == "期货":
                position.yd_volume = data["PositionVolume"] - data["TodayPositionVolume"]

            # 获取合约的乘数信息
            size: float = contract.size

            # 计算之前已有仓位的持仓总成本
            cost: float = position.price * position.volume * size

            # 累加更新持仓数量和盈亏
            position.volume += data["PositionVolume"]
            position.pnl += data["PositionProfit"]

            # 计算更新后的持仓总成本和均价
            if position.volume and size:
                cost += data["PositionCost"]
                position.price = cost / (position.volume * size)

            # 更新仓位冻结数量
            position.frozen += data["CloseFrozenVolume"]

    def onRspQryTradingAccount(
        self,
        data: dict,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """资金查询回报"""
        if not data:
            return

        account: AccountData = AccountData(
            accountid=data["AccountID"],
            balance=data["FrozenBalance"] + data["AvailableBalance"],
            frozen=data["FrozenBalance"],
            gateway_name=self.gateway_name
        )

        self.gateway.on_account(account)

    def onRspQryInstrument(
        self,
        data: dict,
        error: dict,
        reqid: int,
        last: bool
    ) -> None:
        """合约查询回报"""
        if not data and last:
            self.gateway.write_log("合约信息查询成功")
            return

        product: Product = PRODUCT_UFT2VT.get(data["ProductType"], None)
        if product:
            contract: ContractData = ContractData(
                symbol=data["InstrumentID"],
                exchange=EXCHANGE_UFT2VT[data["ExchangeID"]],
                name=data["InstrumentName"],
                product=product,
                size=data["VolumeMultiple"],
                pricetick=data["PriceTick"],
                gateway_name=self.gateway_name
            )

            # 期权相关
            if contract.product == Product.OPTION:
                contract.option_type = OPTIONTYPE_UFT2VT.get(data["OptionsType"], None)
                contract.option_strike = data["ExercisePrice"]
                contract.option_expiry = datetime.strptime(str(data["ExpireDate"]), "%Y%m%d")

                # ETF期权
                if contract.exchange in {Exchange.SSE, Exchange.SZSE}:
                    contract.option_underlying = "-".join([data["UnderlyingInstrID"], str(data["EndExerciseDate"])[:-2]])
                    contract.option_portfolio = data["UnderlyingInstrID"] + "_O"

                    # 需要考虑标的分红导致的行权价调整后的索引
                    contract.option_index = get_option_index(contract.option_strike, data["InstrumentEngName"])
                # 期货期权
                else:
                    contract.option_underlying = data["UnderlyingInstrID"]

                    # 移除郑商所期权产品名称带有的C/P后缀
                    if contract.exchange == Exchange.CZCE:
                        contract.option_portfolio = data["ProductID"][:-1]
                    else:
                        contract.option_portfolio = data["ProductID"]

                    # 直接使用行权价作为索引
                    contract.option_index = str(contract.option_strike)

            self.gateway.on_contract(contract)

            symbol_contract_map[contract.symbol] = contract

    def onRtnOrder(self, data: dict) -> None:
        """委托更新推送"""
        self.update_order(data)

    def update_order(self, data: dict) -> None:
        """委托更新"""
        sessionid: str = data["SessionID"]
        order_ref: str = data["OrderRef"]
        orderid: str = f"{sessionid}_{order_ref}"

        order: OrderData = self.orders.get(orderid, None)
        insert_time: str = generate_time(data["InsertTime"])
        timestamp: str = f"{data['InsertDate']} {insert_time}"

        if "." in timestamp:
            fmt: str = "%Y%m%d %H:%M:%S.%f"
        else:
            fmt: str = "%Y%m%d %H:%M:%S"

        dt: datetime = datetime.strptime(timestamp, fmt)
        dt: datetime = dt.replace(tzinfo=CHINA_TZ)

        if not order:
            order: OrderData = OrderData(
                symbol=data["InstrumentID"],
                exchange=EXCHANGE_UFT2VT[data["ExchangeID"]],
                orderid=orderid,
                type=ORDERTYPE_UFT2VT[data["OrderCommand"]],
                direction=DIRECTION_UFT2VT[data["Direction"]],
                offset=OFFSET_UFT2VT[data["OffsetFlag"]],
                price=data["OrderPrice"],
                volume=data["OrderVolume"],
                traded=data["TradeVolume"],
                status=STATUS_UFT2VT.get(data["OrderStatus"], Status.SUBMITTING),
                datetime=dt,
                gateway_name=self.gateway_name
            )
            self.orders[orderid] = order
        else:
            order.traded = data["TradeVolume"]
            order.status = STATUS_UFT2VT.get(data["OrderStatus"], Status.SUBMITTING)

        self.gateway.on_order(order)

    def onRtnTrade(self, data: dict) -> None:
        """成交数据推送"""
        self.update_trade(data)

    def update_trade(self, data: dict) -> None:
        """成交委托更新"""
        if not data["TradeID"]:
            return

        symbol: str = data["InstrumentID"]
        exchange: Exchange = EXCHANGE_UFT2VT[data["ExchangeID"]]
        sessionid: str = data["SessionID"]
        order_ref: str = data["OrderRef"]
        orderid: str = f"{sessionid}_{order_ref}"

        order: OrderData = self.orders.get(orderid, None)
        if order:
            order.traded += data["TradeVolume"]

            if order.traded < order.volume:
                order.status = Status.PARTTRADED
            else:
                order.status = Status.ALLTRADED

            self.gateway.on_order(order)

        trade_time: str = generate_time(data["TradeTime"])
        timestamp: str = f"{data['TradingDay']} {trade_time}"
        dt: datetime = datetime.strptime(timestamp, "%Y%m%d %H:%M:%S")
        dt: datetime = dt.replace(tzinfo=CHINA_TZ)

        trade: TradeData = TradeData(
            symbol=symbol,
            exchange=exchange,
            orderid=orderid,
            tradeid=data["TradeID"],
            direction=DIRECTION_UFT2VT[data["Direction"]],
            offset=OFFSET_UFT2VT[data["OffsetFlag"]],
            price=data["TradePrice"],
            volume=data["TradeVolume"],
            datetime=dt,
            gateway_name=self.gateway_name
        )
        self.gateway.on_trade(trade)

    def connect(
        self,
        address: str,
        server_license: str,
        userid: str,
        password: str,
        auth_code: str,
        appid: str,
        application_type: str
    ) -> None:
        """连接服务器"""
        self.userid = userid
        self.password = password
        self.auth_code = auth_code
        self.appid = appid
        self.application_type = application_type

        if not self.connect_status:
            path: Path = get_folder_path(self.gateway_name.lower())
            self.newTradeApi((str(path) + "\\Td").encode("GBK"))

            self.rgisterSubModel(HS_TERT_RESUME)

            self.registerFront(address)
            self.init(
                server_license,
                "",
                "",
                "",
                ""
            )

            self.connect_status = True
        else:
            self.authenticate()

    def authenticate(self):
        """发起授权验证"""
        req: dict = {
            "AccountID": self.userid,
            "Password": self.password,
            "AuthCode": self.auth_code,
            "AppID": self.appid
        }

        self.reqid += 1
        self.reqAuthenticate(req, self.reqid)

    def login(self) -> None:
        """用户登录"""
        if self.login_failed:
            return

        req: dict = {
            "AccountID": self.userid,
            "Password": self.password,
            "UserApplicationType": self.application_type,
            "UserApplicationInfo": "",
            "MacAddress": "",
            "IPAddress": "",
        }

        self.reqid += 1
        self.reqUserLogin(req, self.reqid)

    def send_order(self, req: OrderRequest) -> str:
        """委托下单"""
        if req.offset not in OFFSET_VT2UFT:
            self.gateway.write_log("请选择开平方向")
            return ""

        self.order_ref += 1

        uft_req: dict = {
            "OrderRef": str(self.order_ref),
            "ExchangeID": EXCHANGE_VT2UFT[req.exchange],
            "InstrumentID": req.symbol,
            "Direction": DIRECTION_VT2UFT[req.direction],
            "OffsetFlag": OFFSET_VT2UFT[req.offset],
            "HedgeType": "0",
            "OrderPrice": req.price,
            "OrderVolume": int(req.volume),
            "OrderCommand": ORDERTYPE_VT2UFT[req.type],
            "SwapOrderFlag": "0"
        }

        self.reqid += 1
        self.reqOrderInsert(uft_req, self.reqid)

        orderid: str = f"{self.sessionid}_{self.order_ref}"
        order: OrderData = req.create_order_data(orderid, self.gateway_name)
        self.gateway.on_order(order)

        return order.vt_orderid

    def cancel_order(self, req: CancelRequest) -> None:
        """委托撤单"""
        sessionid, order_ref = req.orderid.split("_")

        uft_req: dict = {
            "SessionID": int(sessionid),
            "OrderRef": order_ref
        }

        self.reqid += 1
        self.reqOrderAction(uft_req, self.reqid)

    def query_account(self) -> None:
        """查询资金"""
        self.reqid += 1
        self.reqQryTradingAccount({}, self.reqid)

    def query_position(self) -> None:
        """查询持仓"""
        self.reqid += 1
        self.reqQryPosition({}, self.reqid)

    def close(self) -> None:
        """关闭连接"""
        if self.connect_status:
            self.exit()


def adjust_price(price: float) -> float:
    """将异常的浮点数最大值（MAX_FLOAT）数据调整为0"""
    if price == MAX_FLOAT:
        price = 0
    return price


def generate_time(data: int) -> str:
    """生成时间"""
    buf: str = str(data)
    buf_size: int = len(buf)

    # 不到6位数字的时间戳，精确到秒
    if buf_size < 6:
        buf = "0" + buf         # 补齐小时前面的0
    # 超过6位数字的时间戳，精确到毫秒
    elif buf_size > 6:
        # 不足9位
        if buf_size < 9:
            buf = "0" + buf     # 补齐小时前面的0

    hour: str = buf[0:2]
    minute: str = buf[2:4]
    second: str = buf[4:6]
    return f"{hour}:{minute}:{second}"


def get_option_index(strike_price: float, exchange_instrument_id: str) -> str:
    """获取期权指数"""
    exchange_instrument_id: str = exchange_instrument_id.replace(" ", "")

    if "M" in exchange_instrument_id:
        n: int = exchange_instrument_id.index("M")
    elif "A" in exchange_instrument_id:
        n: int = exchange_instrument_id.index("A")
    elif "B" in exchange_instrument_id:
        n: int = exchange_instrument_id.index("B")
    else:
        return str(strike_price)

    index: str = exchange_instrument_id[n:]
    option_index: str = f"{strike_price:.3f}-{index}"

    return option_index
