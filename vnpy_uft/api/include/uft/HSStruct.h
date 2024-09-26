/**
* @author 寿贺飞
* @company 恒生电子股份有限公司
* @file HSStruct.h
* @brief 定义了接口使用的业务数据结构
* @date    20170927
*/
#ifndef _HS_API_STRUCT_H_
#define _HS_API_STRUCT_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "./HSDataType.h"
#define API_STRUCT_CHECK_VERSION    240002
#pragma pack(push,8)
struct CHSInitConfigField
{
    /// API结构体版本校验
    HSCheckVersion          APICheckVersion;
    /// 通讯证书
    HSLicenseFile           CommLicense;
    /// 安全级别
    HSSafeLevel             SafeLevel;
    /// 通讯密码
    HSLicensePassward       CommPassword;
    /// SSL版本
    HSSslVersion            SslVersion;
    /// SSL证书
    HSLicenseFile           CertLicense;
    /// SSL密码
    HSLicensePassward       CertPassword;
    /// 国密配置：证书服务商用户名(资金账号)
    HSSksUser	            SksUser;
    /// 国密配置：证书服务商密码(交易密码)
    HSSksPassword	        SksPassword;
    /// 国密配置：证书服务商pin密码
    HSSksPin	            SksPin;
    /// 国密配置：证书服务商根证书校验
    HSSksCheckCertFlag      SksCheckCertFlag;
};

struct CHSRspInfoField
{
    /// 错误代码
    HSErrorID                     ErrorID;
    /// 错误提示
    HSErrorMsg                    ErrorMsg;
};

///接入认证
struct CHSReqAuthenticateField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 密码
    HSPassword                    Password;
    /// 客户端id
    HSAppID                       AppID;
    /// 认证码
    HSAuthCode                    AuthCode;
};

///接入认证应答
struct CHSRspAuthenticateField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 客户端ID
    HSAppID                       AppID;
    /// 认证码
    HSAuthCode                    AuthCode;
    /// 客户端ID类型
    HSAppIDType                   AppIDType;
};


///用户信息上报请求
struct CHSReqUserSystemInfoField
{
    /// 客户端登陆时间
    HSStrTime                    AppLoginTime;
    /// 客户端公网地址
    HSIPAddress                  AppPublicAdrr;
    /// 客户端系统信息
    HSAppSysInfo                 AppSysInfo;
    /// 客户端系统信息采集完整度
    HSAppSysInfoIntegrity        AppSysInfoIntegrity;
    /// 客户端系统信息采集异常标识
    HSAppAbnormalType            AppAbnormalType;
};

///用户信息上报应答
struct CHSRspUserSystemInfoField
{
};

///客户登录
struct CHSReqUserLoginField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 密码
    HSPassword                    Password;
    /// 投资者端应用类别
    HSUserApplicationType         UserApplicationType;
    /// 投资者端应用信息
    HSUserApplicationInfo         UserApplicationInfo;
    /// 投资者Mac地址
    HSMacAddress                  MacAddress;
    /// 投资者IP地址
    HSIPAddress                   IPAddress;
    /// 投资者站点信息
    HSUserStationInfo             UserStationInfo;
};
///客户登录应答
struct CHSRspUserLoginField
{
    /// 营业部号
    HSNum                         BranchID;
    /// 账号
    HSAccountID                   AccountID;
    /// 投资者姓名
    HSUserName                    UserName;
    /// 交易日
    HSDate                        TradingDay;
    /// 上个交易日
    HSDate                        PreTradingDay;
    /// 账单确认标志
    HSBillConfirmFlag             BillConfirmFlag;
    /// 会话编码
    HSSessionID                   SessionID;
    /// 投资者端应用类别
    HSUserApplicationType         UserApplicationType;
    /// 投资者端应用信息
    HSUserApplicationInfo         UserApplicationInfo;
    /// 风险等级
    HSRiskLevel                   RiskLevel;
    /// 投资者上次登陆的Mac地址
    HSMacAddress                  LastMacAddress;
    /// 投资者上次登陆的IP地址
    HSIPAddress                   LastIPAddress;
    /// 上次登录成功时间
    HSTime                        LastLoginTime;
    /// 郑商所当前时间
    HSTime                        CZCETime;
    /// 大商所当前时间
    HSTime                        DCETime;
    /// 上期所当前时间
    HSTime                        SHFETime;
    /// 中金所当前时间
    HSTime                        CFFEXTime;
    /// 能源中心当前时间
    HSTime                        INETime;
    /// 最大报单引用(返回会话上次最大报单引用)
    HSRef                         MaxOrderRef;
    /// 客户编号
    HSUserID                      UserID;
    /// 广期所当前时间
    HSTime                        GFEXTime;
};

///密码更改
struct CHSReqUserPasswordUpdateField
{
    /// 密码类型
    HSPasswordType                PasswordType;
    /// 密码
    HSPassword                    Password;
    /// 新密码
    HSPassword                    NewPassword;
};
///密码更改应答
struct CHSRspUserPasswordUpdateField
{
};

///报单录入
struct CHSReqOrderInsertField
{
    /// 报单引用
    HSRef                         OrderRef;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 买卖方向
    HSDirection                   Direction;
    /// 开平标志
    HSOffsetFlag                  OffsetFlag;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 报单价格
    HSPrice                       OrderPrice;
    /// 报单数量
    HSVolume                      OrderVolume;
    /// 报单指令
    HSOrderCommand                OrderCommand;
    /// 最小成交量
    HSVolume                      MinVolume;
    /// 止损止盈价
    HSPrice                       SpringPrice;
    /// 互换标志
    HSSwapOrderFlag               SwapOrderFlag;
    /// 组合持仓编码
    HSCombPositionID              CombPositionID;
    /// 交易编码
    HSExchangeAccountID           ExchangeAccountID;
    /// 席位索引
    HSSeatIndex                   SeatIndex;
};
///报单录入应答
struct CHSRspOrderInsertField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 报单编码
    HSOrderSysID                  OrderSysID;
    /// 经纪公司报单编码
    HSBrokerOrderID               BrokerOrderID;
    /// 会话编码
    HSSessionID                   SessionID;
    /// 报单引用
    HSRef                         OrderRef;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 买卖方向
    HSDirection                   Direction;
    /// 开平标志
    HSOffsetFlag                  OffsetFlag;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 报单价格
    HSPrice                       OrderPrice;
    /// 报单数量
    HSVolume                      OrderVolume;
    /// 报单状态
    HSOrderStatus                 OrderStatus;
    /// 报单指令
    HSOrderCommand                OrderCommand;
    /// 报单时间
    HSTime                        InsertTime;
    /// 最小成交量
    HSVolume                      MinVolume;
    /// 止损止盈价
    HSPrice                       SpringPrice;
    /// 互换标志
    HSSwapOrderFlag               SwapOrderFlag;
    /// 组合持仓编码
    HSCombPositionID              CombPositionID;
    /// 交易编码
    HSExchangeAccountID           ExchangeAccountID;
    /// 席位索引
    HSSeatIndex                   SeatIndex;
};

///撤单
struct CHSReqOrderActionField
{
    /// 报单编码
    HSOrderSysID                  OrderSysID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 会话编码
    HSSessionID                   SessionID;
    /// 报单引用
    HSRef                         OrderRef;
    /// 报单操作引用
    HSRef                         OrderActionRef;
};
///撤单应答
struct CHSRspOrderActionField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 报单编码
    HSOrderSysID                  OrderSysID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 会话编码
    HSSessionID                   SessionID;
    /// 报单引用
    HSRef                         OrderRef;
    /// 报单状态
    HSOrderStatus                 OrderStatus;
    /// 报单时间
    HSTime                        InsertTime;
    /// 报单操作引用
    HSRef                         OrderActionRef;
};

///行权录入
struct CHSReqExerciseOrderInsertField
{
    /// 行权引用
    HSRef                         ExerciseRef;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 报单数量
    HSVolume                      OrderVolume;
    /// 行权方式
    HSExerciseType                ExerciseType;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 开平标志
    HSOffsetFlag                  OffsetFlag;
    /// 期权行权后生成的头寸是否自动平仓
    HSCloseFlag                   CloseFlag;
};
///行权录入应答
struct CHSRspExerciseOrderInsertField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 会话编码
    HSSessionID                   SessionID;
    /// 行权报单编码
    HSOrderSysID                  ExerciseOrderSysID;
    /// 行权引用
    HSRef                         ExerciseRef;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 报单数量
    HSVolume                      OrderVolume;
    /// 行权方式
    HSExerciseType                ExerciseType;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 报单状态
    HSOrderStatus                 OrderStatus;
    /// 报单时间
    HSTime                        InsertTime;
    /// 开平标志
    HSOffsetFlag                  OffsetFlag;
    /// 期权行权后生成的头寸是否自动平仓
    HSCloseFlag                   CloseFlag;
    /// 经纪公司行权报单编码
    HSBrokerOrderID               ExerciseBrokerOrderID;
};

///行权撤单
struct CHSReqExerciseOrderActionField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 行权报单编码
    HSOrderSysID                  ExerciseOrderSysID;
    /// 行权引用
    HSRef                         ExerciseRef;
    /// 会话编码
    HSSessionID                   SessionID;
    /// 行权操作引用
    HSRef                         ExecOrderActionRef;
};
///行权撤单应答
struct CHSRspExerciseOrderActionField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 行权报单编码
    HSOrderSysID                  ExerciseOrderSysID;
    /// 行权引用
    HSRef                         ExerciseRef;
    /// 会话编码
    HSSessionID                   SessionID;
    /// 报单状态
    HSOrderStatus                 OrderStatus;
    /// 行权操作引用
    HSRef                         ExecOrderActionRef;
};

///锁定录入
struct CHSReqLockInsertField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 锁定类型
    HSLockType                    LockType;
    /// 报单数量
    HSVolume                      OrderVolume;
    /// 锁定引用
    HSRef                         LockRef;
};
///锁定录入应答
struct CHSRspLockInsertField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 锁定报单编码
    HSOrderSysID                  LockOrderSysID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 锁定类型
    HSLockType                    LockType;
    /// 报单数量
    HSVolume                      OrderVolume;
    /// 标的物交易账号
    HSAccountID                   UnderlyingAccountID;
    /// 报单状态
    HSOrderStatus                 OrderStatus;
    /// 报单时间
    HSTime                        InsertTime;
    /// 锁定引用
    HSRef                         LockRef;
};

///询价录入
struct CHSReqForQuoteInsertField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
};
///询价录入应答
struct CHSRspForQuoteInsertField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 报单状态
    HSOrderStatus                 OrderStatus;
};

///报价录入
struct CHSReqQuoteInsertField
{
    /// 交易类别
    HSExchangeID                   ExchangeID;
    /// 合约代码
    HSInstrumentID                 InstrumentID;
    /// 买方开平方向
    HSOffsetFlag                   BidOffsetFlag;
    /// 买方套保标志
    HSHedgeType                    BidHedgeType;
    /// 买方报价价格
    HSPrice                        BidOrderPrice;
    /// 买方报价数量
    HSVolume                       BidOrderVolume;
    /// 买方报单引用
    HSRef                          BidOrderRef;
    /// 卖方开平方向
    HSOffsetFlag                   AskOffsetFlag;
    /// 卖方套保标志
    HSHedgeType                    AskHedgeType;
    /// 卖方报价价格
    HSPrice                        AskOrderPrice;
    /// 卖方报价数量
    HSVolume                       AskOrderVolume;
    /// 卖方委托引用
    HSRef                          AskOrderRef;
    /// 询价报单编码
    HSOrderSysID                   ForQuoteSysID;
    /// 报价委托引用
    HSRef                          QuoteRef;
    /// 顶单类型
    HSTopOrderType                 TopOrderType;
    /// 报价报单编码
    HSOrderSysID                   QuoteSysID;    
};
///报价录入应答
struct CHSRspQuoteInsertField
{
    /// 账号
    HSAccountID                    AccountID;
    /// 交易类别
    HSExchangeID                   ExchangeID;
    /// 合约代码
    HSInstrumentID                 InstrumentID;
    /// 买方开平方向
    HSOffsetFlag                   BidOffsetFlag;
    /// 买方套保标志
    HSHedgeType                    BidHedgeType;
    /// 买方报价价格
    HSPrice                        BidOrderPrice;
    /// 买方报价数量
    HSVolume                       BidOrderVolume;
    /// 买方委托引用
    HSRef                          BidOrderRef;
    /// 卖方开平方向
    HSOffsetFlag                   AskOffsetFlag;
    /// 卖方套保标志
    HSHedgeType                    AskHedgeType;
    /// 卖方报价价格
    HSPrice                        AskOrderPrice;
    /// 卖方报价数量
    HSVolume                       AskOrderVolume;
    /// 卖方委托引用
    HSRef                          AskOrderRef;
    /// 询价报单编码
    HSOrderSysID                   ForQuoteSysID;
    /// 报价委托引用
    HSRef                          QuoteRef;
    /// 报价编号
    HSBrokerOrderID                QuoteBrokerID;
    /// 买方报单编码
    HSOrderSysID                   BidOrderSysID;
    /// 卖方报单编码
    HSOrderSysID                   AskOrderSysID;
    /// 会话编号
    HSSessionID                    SessionID;
    /// 报单时间
    HSTime                         InsertTime;
    /// 报单状态
    HSOrderStatus                  OrderStatus;
    /// 顶单类型
    HSTopOrderType                 TopOrderType;
    /// 报价报单编码
    HSOrderSysID                   QuoteSysID;
};

///报价撤单
struct CHSReqQuoteActionField
{
    /// 报价报单编码
    HSOrderSysID                   QuoteSysID;
    /// 交易类别
    HSExchangeID                   ExchangeID;
    /// 会话编号
    HSSessionID                    SessionID;
    /// 报价委托引用
    HSRef                          QuoteRef;
    /// 报价操作引用
    HSRef                          QuoteActionRef;
    /// 合约代码
    HSInstrumentID                 InstrumentID;
};

///报价撤单应答
struct CHSRspQuoteActionField
{
    /// 账号
    HSAccountID                    AccountID;
    /// 报价报单编码
    HSOrderSysID                   QuoteSysID;
    /// 交易类别
    HSExchangeID                   ExchangeID;
    /// 会话编号
    HSSessionID                    SessionID;
    /// 报价委托引用
    HSRef                          QuoteRef;
    /// 报价操作引用
    HSRef                          QuoteActionRef;
    /// 报单状态
    HSOrderStatus                  OrderStatus;
    /// 报单时间
    HSTime                         InsertTime;
    /// 合约代码
    HSInstrumentID                 InstrumentID;
};

///申请组合录入
struct CHSReqCombActionInsertField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 组合策略编码
    HSCombStrategyID              CombStrategyID;
    /// 组合持仓编码
    HSCombPositionID              CombPositionID;
    /// 组合指令方向
    HSCombDirection               CombDirection;
    /// 报单数量
    HSVolume                      OrderVolume;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 买卖方向
    HSDirection                   Direction;
    /// 第二腿投机/套保/备兑类型
    HSHedgeType                   SecondHedgeType;
    /// 组合报单引用
    HSRef                         CombOrderRef;
};
///申请组合录入应答
struct CHSRspCombActionInsertField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 组合报单编码
    HSOrderSysID                  CombOrderSysID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 组合策略编码
    HSCombStrategyID              CombStrategyID;
    /// 组合持仓编码
    HSCombPositionID              CombPositionID;
    /// 组合指令方向
    HSCombDirection               CombDirection;
    /// 报单数量
    HSVolume                      OrderVolume;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 报单状态
    HSOrderStatus                 OrderStatus;
    /// 报单时间
    HSTime                        InsertTime;
    /// 买卖方向
    HSDirection                   Direction;
    /// 第二腿投机/套保/备兑类型
    HSHedgeType                   SecondHedgeType;
    /// 组合报单引用
    HSRef                         CombOrderRef;
};

///最大报单数量获取
struct CHSReqQueryMaxOrderVolumeField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 报单指令
    HSOrderCommand                OrderCommand;
    /// 买卖方向
    HSDirection                   Direction;
    /// 开平标志
    HSOffsetFlag                  OffsetFlag;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 报单价格
    HSPrice                       OrderPrice;
    /// 组合持仓编码
    HSCombPositionID              CombPositionID;
};
///最大报单数量获取应答
struct CHSRspQueryMaxOrderVolumeField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 最大报单量
    HSVolume                      MaxOrderVolume;
    /// 单笔最大报单量
    HSVolume                      MaxOrderVolumeUnit;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 报单指令
    HSOrderCommand                OrderCommand;
    /// 买卖方向
    HSDirection                   Direction;
    /// 开平标志
    HSOffsetFlag                  OffsetFlag;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 报单价格
    HSPrice                       OrderPrice;
    /// 组合持仓编码
    HSCombPositionID              CombPositionID;
    /// 提示信息
    HSErrorMsg                    ErrorMsg;
};

///可锁定数量获取
struct CHSReqQryLockVolumeField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 锁定类型
    HSLockType                    LockType;
};
///可锁定数量获取应答
struct CHSRspQryLockVolumeField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 锁定类型
    HSLockType                    LockType;
    /// 可用持仓数量
    HSVolume                      AvailablePositionVolume;
};

///可行权数量获取
struct CHSReqQueryExerciseVolumeField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
};
///可行权数量获取应答
struct CHSRspQueryExerciseVolumeField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 最大报单量
    HSVolume                      MaxOrderVolumeUnit;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
};

///申请组合最大数量获取
struct CHSReqQryCombVolumeField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 组合策略编码
    HSCombStrategyID              CombStrategyID;
    /// 组合持仓编码
    HSCombPositionID              CombPositionID;
    /// 组合指令方向
    HSCombDirection               CombDirection;
};
///申请组合最大数量获取应答
struct CHSRspQryCombVolumeField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 组合策略编码
    HSCombStrategyID              CombStrategyID;
    /// 组合持仓编码
    HSCombPositionID              CombPositionID;
    /// 组合指令方向
    HSCombDirection               CombDirection;
    /// 单笔最大报单量
    HSVolume                      MaxOrderVolumeUnit;
};

///持仓汇总查询
struct CHSReqQryPositionField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
};
///持仓汇总查询应答
struct CHSRspQryPositionField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 买卖方向
    HSDirection                   Direction;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 上日持仓数量
    HSVolume                      YdPositionVolume;
    /// 持仓数量
    HSVolume                      PositionVolume;
    /// 今日持仓数量
    HSVolume                      TodayPositionVolume;
    /// 可用持仓数量
    HSVolume                      AvailablePositionVolume;
    /// 今日可用持仓数量
    HSVolume                      TodayAvailablePositionVolume;
    /// 持仓保证金
    HSBalance                     PositionMargin;
    /// 权利金
    HSBalance                     Premium;
    /// 手续费
    HSBalance                     Commission;
    /// 开仓冻结数量
    HSVolume                      OpenFrozenVolume;
    /// 平仓冻结数量
    HSVolume                      CloseFrozenVolume;
    /// 组合数量
    HSVolume                      CombVolume;
    /// 行权冻结数量
    HSVolume                      ExerciseFrozenVolume;
    /// 冻结保证金
    HSBalance                     FrozenMargin;
    /// 行权冻结保证金
    HSBalance                     ExerciseFrozenMargin;
    /// 冻结权利金
    HSBalance                     FrozenPremium;
    /// 冻结手续费
    HSBalance                     FrozenCommission;
    /// 开仓量
    HSVolume                      OpenVolume;
    /// 平仓量
    HSVolume                      CloseVolume;
    /// 开仓金额
    HSBalance                     OpenBalance;
    /// 平仓金额
    HSBalance                     CloseBalance;
    /// 开仓成本
    HSBalance                     OpenCost;
    /// 持仓成本
    HSBalance                     PositionCost;
    /// 持仓盈亏
    HSBalance                     PositionProfit;
    /// 平仓盈亏
    HSBalance                     CloseProfit;
    /// 期权市值
    HSBalance                     OptionsMarketValue;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// TAS持仓数量
    HSVolume                      TASPositionVolume;
};

///资金账户查询
struct CHSReqQryTradingAccountField
{
};
///资金账户查询应答
struct CHSRspQryTradingAccountField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 上日余额
    HSBalance                     YdBalance;
    /// 上日持仓保证金
    HSBalance                     YdPositionMargin;
    /// 上日资金权益
    HSBalance                     YdFundEquity;
    /// 资金权益
    HSBalance                     FundEquity;
    /// 期权市值
    HSBalance                     OptionsMarketValue;
    /// 总权益
    HSBalance                     Equity;
    /// 可用资金
    HSBalance                     AvailableBalance;
    /// 可取资金
    HSBalance                     WithdrawBalance;
    /// 保证金
    HSBalance                     Margin;
    /// 冻结保证金
    HSBalance                     FrozenMargin;
    /// 行权冻结保证金
    HSBalance                     ExerciseFrozenMargin;
    /// 风险度
    HSRiskDegree                  RiskDegree;
    /// 权利金
    HSBalance                     Premium;
    /// 冻结权利金
    HSBalance                     FrozenPremium;
    /// 手续费
    HSBalance                     Commission;
    /// 冻结手续费
    HSBalance                     FrozenCommission;
    /// 平仓盈亏
    HSBalance                     CloseProfit;
    /// 持仓盈亏
    HSBalance                     PositionProfit;
    /// 平仓盯市盈亏
    HSBalance                     CloseProfitByDate;
    /// 持仓盯市盈亏
    HSBalance                     PositionProfitByDate;
    /// 转入金额
    HSBalance                     Deposit;
    /// 转出金额
    HSBalance                     Withdraw;
    /// 货币质押金额
    HSBalance                     FundMortgage;
    /// 仓单质押金额
    HSBalance                     WarrantMortgage;
    /// 冻结资金
    HSBalance                     FrozenBalance;
    /// 解冻资金
    HSBalance                     UnFrozenBalance;
    /// 币种
    HSCurrencyID                  CurrencyID;
    /// 对冲风险度
    HSRiskDegree                  HedgeRiskDegree;
    /// 上海已用限购额度
    HSBalance                     ShUsedBuyQuota;
    /// 深圳已用限购额度
    HSBalance                     SzUsedBuyQuota;
    /// 上海可用限购额度
    HSBalance                     ShAvailableBuyQuota;
    /// 深圳可用限购额度
    HSBalance                     SzAvailableBuyQuota;
    /// 上日仓单质押金额
    HSBalance                     YdWarrantMortgage;
};

///报单查询
struct CHSReqQryOrderField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 报单编码
    HSOrderSysID                  OrderSysID;
    /// 交易编码
    HSExchangeAccountID           ExchangeAccountID;
};

///历史报单查询
struct CHSReqQryHistOrderField
{
    /// 交易所代码
    HSExchangeID                   ExchangeID;
    /// 合约代码
    HSInstrumentID                 InstrumentID;
    /// 报单编码
    HSOrderSysID                   OrderSysID;
    /// 开始日期
    HSDate                         BeginDate;
    /// 结束日期
    HSDate                         EndDate;
    /// 交易编码
    HSExchangeAccountID            ExchangeAccountID;
};

///报单信息
struct CHSOrderField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 报单编码
    HSOrderSysID                  OrderSysID;
    /// 经纪公司报单编码
    HSBrokerOrderID               BrokerOrderID;
    /// 会话编码
    HSSessionID                   SessionID;
    /// 报单引用
    HSRef                         OrderRef;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 买卖方向
    HSDirection                   Direction;
    /// 开平标志
    HSOffsetFlag                  OffsetFlag;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 报单价格
    HSPrice                       OrderPrice;
    /// 报单数量
    HSVolume                      OrderVolume;
    /// 报单状态
    HSOrderStatus                 OrderStatus;
    /// 成交数量
    HSVolume                      TradeVolume;
    /// 撤单数量
    HSVolume                      CancelVolume;
    /// 成交价格
    HSPrice                       TradePrice;
    /// 交易日
    HSDate                        TradingDay;
    /// 报单日期
    HSDate                        InsertDate;
    /// 报单时间
    HSTime                        InsertTime;
    /// 申报时间
    HSTime                        ReportTime;
    /// 报单指令
    HSOrderCommand                OrderCommand;
    /// 最小成交量
    HSVolume                      MinVolume;
    /// 止损止盈价
    HSPrice                       SpringPrice;
    /// 互换标志
    HSSwapOrderFlag               SwapOrderFlag;
    /// 强平原因
    HSForceCloseReason            ForceCloseReason;
    /// 错误信息
    HSErrorMsg                    ErrorMsg;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 报单发起方
    HSOrderSource                 OrderSource;
    /// 组合持仓编码
    HSCombPositionID              CombPositionID;
    /// 交易编码
    HSExchangeAccountID           ExchangeAccountID;
    /// 席位索引
    HSSeatIndex                   SeatIndex;
};

///成交查询
struct CHSReqQryTradeField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 交易编码
    HSExchangeAccountID           ExchangeAccountID;
};

///历史成交查询
struct CHSReqQryHistTradeField
{
    /// 交易所代码
    HSExchangeID                   ExchangeID;
    /// 合约代码
    HSInstrumentID                 InstrumentID;
    /// 开始日期
    HSDate                         BeginDate;
    /// 结束日期
    HSDate                         EndDate;
    /// 交易编码
    HSExchangeAccountID            ExchangeAccountID;
};

///成交信息
struct CHSTradeField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 成交编码
    HSTradeID                     TradeID;
    /// 报单编码
    HSOrderSysID                  OrderSysID;
    /// 经纪公司报单编码
    HSBrokerOrderID               BrokerOrderID;
    /// 会话编码
    HSSessionID                   SessionID;
    /// 报单引用
    HSRef                         OrderRef;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 买卖方向
    HSDirection                   Direction;
    /// 开平标志
    HSOffsetFlag                  OffsetFlag;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 成交数量
    HSVolume                      TradeVolume;
    /// 成交价格
    HSPrice                       TradePrice;
    /// 交易日
    HSDate                        TradingDay;
    /// 成交时间
    HSTime                        TradeTime;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 组合持仓编码
    HSCombPositionID              CombPositionID;
    /// 成交手续费
    HSBalance                     TradeCommission;
    /// 交易编码
    HSExchangeAccountID           ExchangeAccountID;
};

///行权查询
struct CHSReqQryExerciseField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 行权报单编码
    HSOrderSysID                  ExerciseOrderSysID;
};

///历史行权查询
struct CHSReqQryHistExerciseField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 行权报单编码
    HSOrderSysID                  ExerciseOrderSysID;
    /// 开始日期
    HSDate                        BeginDate;
    /// 结束日期
    HSDate                        EndDate;
};

///行权信息
struct CHSExerciseField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 行权报单编码
    HSOrderSysID                  ExerciseOrderSysID;
    /// 会话编码
    HSSessionID                   SessionID;
    /// 行权引用
    HSRef                         ExerciseRef;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 行权方式
    HSExerciseType                ExerciseType;
    /// 行权数量
    HSVolume                      OrderVolume;
    /// 报单状态
    HSOrderStatus                 OrderStatus;
    /// 报单日期
    HSDate                        InsertDate;
    /// 报单时间
    HSTime                        InsertTime;
    /// 错误信息
    HSErrorMsg                    ErrorMsg;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 报单发起方
    HSOrderSource                 OrderSource;
    /// 期权行权后生成的头寸是否自动平仓
    HSCloseFlag                   CloseFlag;
    /// 开平标志
    HSOffsetFlag                  OffsetFlag;
    /// 行权预冻结手续费
    HSBalance                     ExercisePreFrozenCommission;
    /// 行权预冻结保证金
    HSBalance                     ExercisePreFrozenMargin;
    /// 经纪公司行权报单编码
    HSBrokerOrderID               ExerciseBrokerOrderID;
    /// 交易编码
    HSExchangeAccountID           ExchangeAccountID;
};

///锁定查询
struct CHSReqQryLockField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 锁定报单编码
    HSOrderSysID                  LockOrderSysID;
};

///历史锁定查询
struct CHSReqQryHistLockField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 锁定报单编码
    HSOrderSysID                  LockOrderSysID;
    /// 开始日期
    HSDate                        BeginDate;
    /// 结束日期
    HSDate                        EndDate;
};

///锁定信息
struct CHSLockField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 锁定报单编码
    HSOrderSysID                  LockOrderSysID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 锁定类型
    HSLockType                    LockType;
    /// 锁定数量
    HSVolume                      OrderVolume;
    /// 报单状态
    HSOrderStatus                 OrderStatus;
    /// 交易日
    HSDate                        TradingDay;
    /// 锁定时间
    HSTime                        InsertTime;
    /// 错误信息
    HSErrorMsg                    ErrorMsg;
    /// 报单发起方
    HSOrderSource                 OrderSource;
    /// 锁定引用
    HSRef                         LockRef;
    /// 会话编码
    HSSessionID                   SessionID;
};

///申请组合查询
struct CHSReqQryCombActionField
{
    /// 组合报单编码
    HSOrderSysID                  CombOrderSysID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
};

///历史申请组合查询
struct CHSReqQryHistCombActionField
{
    /// 组合报单编码
    HSOrderSysID                  CombOrderSysID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 开始日期
    HSDate                        BeginDate;
    /// 结束日期
    HSDate                        EndDate;
};

///申请组合信息
struct CHSCombActionField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 组合报单编码
    HSOrderSysID                  CombOrderSysID;
    /// 组合持仓编码
    HSCombPositionID              CombPositionID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 组合策略编码
    HSCombStrategyID              CombStrategyID;
    /// 买卖方向
    HSDirection                   Direction;
    /// 组合指令方向
    HSCombDirection               CombDirection;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 报单数量
    HSVolume                      OrderVolume;
    /// 报单状态
    HSOrderStatus                 OrderStatus;
    /// 交易日
    HSDate                        TradingDay;
    /// 报单日期
    HSDate                        InsertDate;
    /// 报单时间
    HSTime                        InsertTime;
    /// 错误信息
    HSErrorMsg                    ErrorMsg;
    /// 报单发起方
    HSOrderSource                 OrderSource;
    /// 第二腿投机/套保/备兑类型
    HSHedgeType                   SecondHedgeType;
    /// 组合报单引用
    HSRef                         CombOrderRef;
    /// 会话编码
    HSSessionID                   SessionID;
};

///询价订阅，订阅取消请求
struct CHSReqForQuoteField
{
    HSExchangeID                  ExchangeID;
    HSInstrumentID                InstrumentID;
};

///询价查询
struct CHSReqQryForQuoteField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 询价报单编码
    HSOrderSysID                  ForQuoteSysID;
};

///询价信息
struct CHSForQuoteField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 询价报单编码
    HSOrderSysID                  ForQuoteSysID;
    /// 交易日
    HSDate                        TradingDay;
    /// 最后更新时间
    HSTime                        UpdateTime;
};

///报价查询
struct CHSReqQryQuoteField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 报价报单编码
    HSOrderSysID                  QuoteSysID;
    /// 报价编号
    HSBrokerOrderID               QuoteBrokerID;
};

///报价信息
struct CHSQuoteField
{
    /// 账号
    HSAccountID                    AccountID;
    /// 交易类别
    HSExchangeID                   ExchangeID;
    /// 合约代码
    HSInstrumentID                 InstrumentID;
    /// 报价编号
    HSBrokerOrderID                QuoteBrokerID;
    /// 报价状态
    HSOrderStatus                  OrderStatus;
    /// 买方开平方向
    HSOffsetFlag                   BidOffsetFlag;
    /// 买方套保标志
    HSHedgeType                    BidHedgeType;
    /// 买方报价价格
    HSPrice                        BidOrderPrice;
    /// 买方报价数量
    HSVolume                       BidOrderVolume;
    /// 卖方开平方向
    HSOffsetFlag                   AskOffsetFlag;
    /// 卖方套保标志
    HSHedgeType                    AskHedgeType;
    /// 卖方报价价格
    HSPrice                        AskOrderPrice;
    /// 卖方报价数量
    HSVolume                       AskOrderVolume;
    /// 报价委托引用
    HSRef                          QuoteRef;
    /// 询价报单编码
    HSOrderSysID                   ForQuoteSysID;
    /// 提示信息
    HSErrorMsg                     ErrorMsg;
    /// 报价报单编码
    HSOrderSysID                   QuoteSysID;
    /// 买方报单编码
    HSOrderSysID                   BidOrderSysID;
    /// 卖方报单编码
    HSOrderSysID                   AskOrderSysID;
    /// 买方委托编号
    HSBrokerOrderID                BidBrokerOrderID;
    /// 卖方委托编号
    HSBrokerOrderID                AskBrokerOrderID;
    /// 买方委托引用
    HSRef                          BidOrderRef;
    /// 卖方委托引用
    HSRef                          AskOrderRef;
    /// 会话编号
    HSSessionID                    SessionID;
    /// 交易日
    HSDate                         TradingDay;
    /// 报单日期
    HSDate                         InsertDate;
    /// 报单时间
    HSTime                         InsertTime;
    /// 申报时间
    HSTime                         ReportTime;
    /// 顶单类型
    HSTopOrderType                 TopOrderType;
};


///组合持仓明细查询
struct CHSReqQryPositionCombineDetailField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 组合策略编码
    HSCombStrategyID              CombStrategyID;
};
///组合持仓明细查询应答
struct CHSRspQryPositionCombineDetailField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 组合持仓编码
    HSCombPositionID              CombPositionID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 组合策略编码
    HSCombStrategyID              CombStrategyID;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 买卖方向
    HSDirection                   Direction;
    /// 上日持仓数量
    HSVolume                      YdPositionVolume;
    /// 可用持仓数量
    HSVolume                      AvailablePositionVolume;
    /// 组合汇总数量
    HSVolume                      TotalCombVolume;
    /// 拆分汇总数量
    HSVolume                      TotalSplitVolume;
    /// 持仓保证金
    HSBalance                     PositionMargin;
    /// 开仓日期
    HSDate                        OpenDate;
    /// 第二腿投机/套保/备兑类型
    HSHedgeType                   SecondHedgeType;
};

///合约信息查询
struct CHSReqQryInstrumentField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
};
///合约信息查询应答
struct CHSRspQryInstrumentField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 合约名称
    HSInstrumentName              InstrumentName;
    /// 合约英文名称
    HSInstrumentEngName           InstrumentEngName;
    /// 合约品种编码
    HSProductID                   ProductID;
    /// 产品类型
    HSProductType                 ProductType;
    /// 市价单最大报单量
    HSVolume                      MaxMarketOrderVolume;
    /// 市价单最小报单量
    HSVolume                      MinMarketOrderVolume;
    /// 限价单最大报单量
    HSVolume                      MaxLimitOrderVolume;
    /// 限价单最小报单量
    HSVolume                      MinLimitOrderVolume;
    /// 合约数量乘数
    HSVolume                      VolumeMultiple;
    /// 最小变动价位
    HSPrice                       PriceTick;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 行权价
    HSPrice                       ExercisePrice;
    /// 期权类型
    HSOptionsType                 OptionsType;
    /// 交易标志
    HSTradingFlag                 TradingFlag;
    /// 上市日
    HSDate                        MarketDate;
    /// 到期日
    HSDate                        ExpireDate;
    /// 行权开始日期
    HSDate                        BeginExerciseDate;
    /// 行权截至日期
    HSDate                        EndExerciseDate;
    /// 开始交割日
    HSDate                        BeginDeliveryDate;
    /// 结束交割日
    HSDate                        EndDeliveryDate;
    /// 币种
    HSCurrencyID                  CurrencyID;
    /// 组合类型
    HSCombType                    CombType;
};

///备兑缺口查询
struct CHSReqQryCoveredShortField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
};
///备兑缺口查询应答
struct CHSRspQryCoveredShortField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 备兑锁定数量
    HSVolume                      CoveredLockVolume;
    /// 备兑缺口数量
    HSVolume                      CoveredShortVolume;
    /// 备兑预估缺口数量
    HSVolume                      CoveredEstimateShortVolume;
    /// 消息正文
    HSMsgContent                  MsgContent;
};

///行权指派查询
struct CHSReqQryExerciseAssignField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 持仓类型
    HSPositionType                PositionType;
};
///行权指派查询应答
struct CHSRspQryExerciseAssignField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 持仓类型
    HSPositionType                PositionType;
    /// 期权类型
    HSOptionsType                 OptionsType;
    /// 行权价
    HSPrice                       ExercisePrice;
    /// 行权数量
    HSVolume                      ExerciseVolume;
    /// 交割数量
    HSVolume                      DeliveryVolume;
    /// 行权冻结资金
    HSBalance                     ExerciseFrozenBalance;
    /// 结算金额
    HSBalance                     SettlementBalance;
};

///银行转账
struct CHSReqTransferField
{
    /// 银行代码
    HSBankID                      BankID;
    /// 转账类型
    HSTransferType                TransferType;
    /// 发生金额
    HSBalance                     OccurBalance;
    /// 资金密码
    HSPassword                    FundPassword;
    /// 银行密码
    HSPassword                    BankPassword;
    /// 币种
    HSCurrencyID                  CurrencyID;
    /// 转账场景
    HSOccasion                    TransferOccasion;
};
///银行转账应答
struct CHSRspTransferField
{
    /// 转账流水
    HSNum                         TransferSerialID;
    /// 银行代码
    HSBankID                      BankID;
    /// 转账类型
    HSTransferType                TransferType;
    /// 发生金额
    HSBalance                     OccurBalance;
    /// 币种
    HSCurrencyID                  CurrencyID;
    /// 转账场景
    HSOccasion                    TransferOccasion;
};

///银行转账查询
struct CHSReqQryTransferField
{
    /// 银行代码
    HSBankID                      BankID;
    /// 转账流水
    HSNum                         TransferSerialID;
};
///银行转账查询应答
struct CHSRspQryTransferField
{
    /// 转账流水
    HSNum                         TransferSerialID;
    /// 银行代码
    HSBankID                      BankID;
    /// 银行名称
    HSBankName                    BankName;
    /// 业务名称
    HSBusinessName                BusinessName;
    /// 发生金额
    HSBalance                     OccurBalance;
    /// 后资金额
    HSBalance                     PostBalance;
    /// 转账时间
    HSTime                        TransferTime;
    /// 转账状态
    HSTransferStatus              TransferStatus;
    /// 转账发起方
    HSTransferSource              TransferSource;
    /// 备注
    HSRemarks                     Remarks;
    /// 币种
    HSCurrencyID                  CurrencyID;
    /// 交易发起方日期
    HSDate                        OrderSourceDate;
    /// 交易日期
    HSDate                        TradingDay;
    /// 转账场景
    HSOccasion                    TransferOccasion;
};

///银行余额查询
struct CHSReqQueryBankBalanceField
{
    /// 银行代码
    HSBankID                      BankID;
    /// 资金密码
    HSPassword                    FundPassword;
    /// 银行密码
    HSPassword                    BankPassword;
    /// 币种
    HSCurrencyID                  CurrencyID;
};
///银行余额查询应答
struct CHSRspQueryBankBalanceField
{
    /// 转账流水
    HSNum                         TransferSerialID;
};

///银行账户查询
struct CHSReqQueryBankAccountField
{
    /// 银行代码
    HSBankID                      BankID;
    /// 币种
    HSCurrencyID                  CurrencyID;
};
///银行账户查询应答
struct CHSRspQueryBankAccountField
{
    /// 银行代码
    HSBankID                      BankID;
    /// 银行名称
    HSBankName                    BankName;
    /// 银行账号
    HSBankAccountID               BankAccountID;
    /// 币种
    HSCurrencyID                  CurrencyID;
};

///多中心资金调拨
struct CHSReqMultiCentreFundTransField
{
    /// 币种
    HSCurrencyID                  CurrencyID;
    /// 发生金额
    HSBalance                     OccurBalance;
    /// 调拨方向
    HSTransDirection              TransDirection;
};
///多中心资金调拨应答
struct CHSRspMultiCentreFundTransField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 币种
    HSCurrencyID                  CurrencyID;
    /// 发生金额
    HSBalance                     OccurBalance;
    /// 调拨方向
    HSTransDirection              TransDirection;
    /// 接入中心资金调拨流水号
    HSNum                         LocalTransferSerialID;
    /// 对端中心资金调拨流水号
    HSNum                         OppositeTransferSerialID;
};

///客户账单查询
struct CHSReqQueryBillContentField
{
    /// 开始日期
    HSDate                        BeginDate;
    /// 结束日期
    HSDate                        EndDate;
};
///客户账单查询应答
struct CHSRspQueryBillContentField
{
    /// 账单内容
    HSBillContent                 BillContent;
};

///客户账单确认
struct CHSReqBillConfirmField
{
};
///客户账单确认应答
struct CHSRspBillConfirmField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 账单确认状态
    HSBillConfirmStatus           BillConfirmStatus;
    /// 确认日期
    HSDate                        ConfirmDate;
    /// 确认时间
    HSTime                        ConfirmTime;
};

///保证金查询
struct CHSReqQryMarginField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
};
///保证金查询应答
struct CHSRspQryMarginField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 多头保证金率
    HSRate                        LongMarginRatio;
    /// 多头保证金
    HSBalance                     LongMargin;
    /// 空头保证金率
    HSRate                        ShortMarginRatio;
    /// 空头保证金
    HSBalance                     ShortMargin;
};

///手续费查询
struct CHSReqQryCommissionField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 产品类型
    HSProductType                 ProductType;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
};
///手续费查询应答
struct CHSRspQryCommissionField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 产品类型
    HSProductType                 ProductType;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 多头开仓手续费率
    HSRate                        LongOpenCommissionRatio;
    /// 多头开仓手续费
    HSBalance                     LongOpenCommission;
    /// 多头平仓手续费率
    HSRate                        LongCloseCommissionRatio;
    /// 多头平仓手续费
    HSBalance                     LongCloseCommission;
    /// 多头平今手续费率
    HSRate                        LongCloseTodayCommissionRatio;
    /// 多头平今手续费
    HSBalance                     LongCloseTodayCommission;
    /// 空头开仓手续费率
    HSRate                        ShortOpenCommissionRatio;
    /// 空头开仓手续费
    HSBalance                     ShortOpenCommission;
    /// 空头平仓手续费率
    HSRate                        ShortCloseCommissionRatio;
    /// 空头平仓手续费
    HSBalance                     ShortCloseCommission;
    /// 空头平今手续费率
    HSRate                        ShortCloseTodayCommissionRatio;
    /// 空头平今手续费
    HSBalance                     ShortCloseTodayCommission;
    /// 行权手续费率
    HSRate                        ExerciseCommissionRatio;
    /// 行权手续费
    HSBalance                     ExerciseCommission;
    /// 成交面值比例
    HSRate                        TradeValueRatio;
    /// 股票面值
    HSBalance                     StockValue;
};

///汇率查询
struct CHSReqQryExchangeRateField
{
    /// 原币种
    HSCurrencyID                  FromCurrencyID;
    /// 目标币种
    HSCurrencyID                  ToCurrencyID;
};
///汇率查询应答
struct CHSRspQryExchangeRateField
{
    /// 原币种
    HSCurrencyID                  FromCurrencyID;
    /// 目标币种
    HSCurrencyID                  ToCurrencyID;
    /// 汇率
    HSExchangeRate                ExchangeRate;
    /// 原币种数量单位
    HSVolume                      FromCurrencyUnit;
};

///持仓明细查询
struct CHSReqQryPositionDetailField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
};
///持仓明细查询应答
struct CHSRspQryPositionDetailField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 成交编码
    HSTradeID                     TradeID;
    /// 开仓日期
    HSDate                        OpenDate;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 买卖方向
    HSDirection                   Direction;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 成交数量
    HSVolume                      TradeVolume;
    /// 持仓价格
    HSPrice                       PositionPrice;
    /// 今日平仓数量
    HSVolume                      TodayCloseVolume;
    /// 套利持仓号
    HSArbitPositionID             ArbitragePositionID;
    /// 腿号
    HSLegID                       LegID;
    /// 成交类型
    HSTradeType                   TradeType;
    /// 持仓保证金
    HSBalance                     PositionMargin;
    /// 组合合约代码
    HSInstrumentID                CombInstrumentID;
    /// 当前持仓数量
    HSVolume                      CurrentPositionVolume;
    /// 结算价
    HSPrice                       SettlementPrice;
    /// 持仓流水号
    HSNum                         PositionSerialID;
};

///经纪公司配置参数查询
struct CHSReqQrySysConfigField
{
};
///经纪公司配置参数查询应答
struct CHSRspQrySysConfigField
{
    /// 配置编号
    HSConfigNo                    ConfigNo;
    /// 配置开关状态
    HSConfigValue                 ConfigValue;
};

///行情订阅，取消订阅请求
struct CHSReqDepthMarketDataField
{
    HSExchangeID                  ExchangeID;
    HSInstrumentID                InstrumentID;
};

///行情查询
struct CHSReqQryDepthMarketDataField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
};

///行情信息
struct CHSDepthMarketDataField
{
    /// 交易日
    HSDate                        TradingDay;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 最新价
    HSPrice                       LastPrice;
    /// 昨结算价
    HSPrice                       PreSettlementPrice;
    /// 昨收盘价
    HSPrice                       PreClosePrice;
    /// 开盘价
    HSPrice                       OpenPrice;
    /// 最高价
    HSPrice                       HighestPrice;
    /// 最低价
    HSPrice                       LowestPrice;
    /// 成交数量
    HSVolume                      TradeVolume;
    /// 成交金额
    HSBalance                     TradeBalance;
    /// 总持量
    HSVolume                      OpenInterest;
    /// 收盘价
    HSPrice                       ClosePrice;
    /// 结算价
    HSPrice                       SettlementPrice;
    /// 涨停板价
    HSPrice                       UpperLimitPrice;
    /// 跌停板价
    HSPrice                       LowerLimitPrice;
    /// 昨虚实度
    HSDelta                       PreDelta;
    /// 今虚实度
    HSDelta                       CurrDelta;
    /// 最后更新时间
    HSTime                        UpdateTime;
    /// 申买价一
    HSPrice                       BidPrice1;
    /// 申买量一
    HSVolume                      BidVolume1;
    /// 申卖价一
    HSPrice                       AskPrice1;
    /// 申卖量一
    HSVolume                      AskVolume1;
    /// 申买价二
    HSPrice                       BidPrice2;
    /// 申买量二
    HSVolume                      BidVolume2;
    /// 申卖价二
    HSPrice                       AskPrice2;
    /// 申卖量二
    HSVolume                      AskVolume2;
    /// 申买价三
    HSPrice                       BidPrice3;
    /// 申买量三
    HSVolume                      BidVolume3;
    /// 申卖价三
    HSPrice                       AskPrice3;
    /// 申卖量三
    HSVolume                      AskVolume3;
    /// 申买价四
    HSPrice                       BidPrice4;
    /// 申买量四
    HSVolume                      BidVolume4;
    /// 申卖价四
    HSPrice                       AskPrice4;
    /// 申卖量四
    HSVolume                      AskVolume4;
    /// 申买价五
    HSPrice                       BidPrice5;
    /// 申买量五
    HSVolume                      BidVolume5;
    /// 申卖价五
    HSPrice                       AskPrice5;
    /// 申卖量五
    HSVolume                      AskVolume5;
    /// 平均价格
    HSPrice                       AveragePrice;
    /// 昨持仓量
    HSVolume                      PreOpenInterest;
    /// 合约交易状态
    HSInstrumentTradeStatus       InstrumentTradeStatus;
    /// 合约实时开仓限制
    HSOpenRestriction             OpenRestriction;
    /// 基金份额参考净值
    HSPrice                       IOPV;
    /// 动态参考价格
    HSPrice                       AuctionPrice;
    /// 行情发送时间
    HSTime                        SendingTime;
};

///撤单信息
struct CHSOrderActionField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 报单编码
    HSOrderSysID                  OrderSysID;
    /// 经纪公司报单编码
    HSBrokerOrderID               BrokerOrderID;
    /// 会话编码
    HSSessionID                   SessionID;
    /// 报单引用
    HSRef                         OrderRef;
    /// 撤单引用
    HSRef                         OrderActionRef;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 买卖方向
    HSDirection                   Direction;
    /// 开平标志
    HSOffsetFlag                  OffsetFlag;
    /// 投机/套保/备兑类型
    HSHedgeType                   HedgeType;
    /// 报单价格
    HSPrice                       OrderPrice;
    /// 报单数量
    HSVolume                      OrderVolume;
    /// 撤单状态
    HSOrderStatus                 OrderActionStatus;
    /// 报单状态
    HSOrderStatus                 OrderStatus;
    /// 交易日
    HSDate                        TradingDay;
    /// 撤单日期
    HSDate                        ActionDate;
    /// 撤单时间
    HSTime                        ActionTime;
    /// 错误信息
    HSErrorMsg                    ErrorMsg;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 报单发起方
    HSOrderSource                 OrderSource;
};

///快速交易与集中交易之间资金调拨请求
struct CHSReqFundTransField
{
    /// 调拨方向
    HSTransDirection              TransDirection;
    /// 币种
    HSCurrencyID                  CurrencyID;
    /// 发生金额
    HSBalance                     OccurBalance;
};

///快速交易与集中交易之间资金调拨应答
struct CHSRspFundTransField
{
    /// 资金调拨流水
    HSNum                         FundTransSerialID;
};

///资金调拨流水查询请求
struct CHSReqQryFundTransField
{

};

///资金调拨流水查询应答
struct CHSRspQryFundTransField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 交易日期
    HSDate                        TradingDay;
    /// 发生日期
    HSDate                        OccurDate;
    /// 发生时间
    HSTime                        OccurTime;
    /// 转账流水
    HSNum                         TransferSerialID;
    /// 币种
    HSCurrencyID                  CurrencyID;
    /// 发生金额
    HSBalance                     OccurBalance;
    /// 后资金额
    HSBalance                     PostBalance;
};

///客户通知查询
struct CHSReqQryClientNoticeField
{

};

///客户通知信息
struct CHSClientNoticeField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 消息正文
    HSMsgBody                     MsgBody;
    /// 消息标题
    HSMsgTitle                    MsgTitle;
    /// 消息类型
    HSMsgType                     MsgType;
    /// 消息日期
    HSDate                        MsgDate;
    /// 消息时间
    HSTime                        MsgTime;
};

///期权标的信息查询
struct CHSReqQryOptUnderlyField
{
    /// 交易所代码
    HSExchangeID                   ExchangeID;
    /// 期权对应的标的合约代码
    HSInstrumentID                 UnderlyingInstrID;
};

///期权标的信息查询应答
struct CHSRspQryOptUnderlyField
{
    /// 交易所代码
    HSExchangeID                   ExchangeID;
    /// 期权对应的标的合约代码
    HSInstrumentID                 UnderlyingInstrID;
    /// 期权对应标的物类型
    HSStockType                    UnderlyingType;
    /// 币种
    HSCurrencyID                   CurrencyID;
    /// 期权对应标的物状态
    HSStatus                       UnderlyingStatus;
    /// 涨停板价
    HSPrice                        UpperLimitPrice;
    /// 跌停板价
    HSPrice                        LowerLimitPrice;
    /// 期权对应标的交易最高数量
    HSVolume                       UnderlyingHighAmount;
    /// 期权对应标的交易最低数量
    HSVolume                       UnderlyingLowAmount;
    /// 合约数量乘数
    HSVolume                       VolumeMultiple;
    /// 买入单位
    HSNum                          BuyUnit;
    /// 卖出单位
    HSNum                          SellUnit;
    /// 最小价差(厘)
    HSNum                          PriceStep;
    /// 上市日
    HSDate                         MarketDate;
    /// 退市日期
    HSDate                         DelistDate;
    /// 期权对应标的市价交易最高数量
    HSVolume                       UnderlyingMarketHighAmount;
    /// 期权对应标的市价交易最低数量
    HSVolume                       UnderlyingMarketLowAmount;
    /// 标的物名称
    HSInstrumentName               UnderlyingName;
    /// 市价买入单位
    HSNum                          MarketBuyUnit;
    /// 市价卖出单位
    HSNum                          MarketSellUnit;
    /// 期权对应标的物有效日期
    HSDate                         UnderlyingValidDate;
    /// 更新类型
    HSNum                          UpdateType;
};

///证券行情查询
struct CHSReqQrySecuDepthMarketField
{
    /// 交易所代码
    HSExchangeID                   ExchangeID;
    /// 期权对应的标的合约代码
    HSInstrumentID                 UnderlyingInstrID;
};

///证券行情查询应答
struct CHSRspQrySecuDepthMarketField
{
    /// 交易所代码
    HSExchangeID                   ExchangeID;
    /// 期权对应的标的合约代码
    HSInstrumentID                 UnderlyingInstrID;
    /// 标的物名称
    HSInstrumentName               UnderlyingName;
    /// 最新价
    HSPrice                        LastPrice;
    /// 开盘价
    HSPrice                        OpenPrice;
    /// 标的物昨收盘价
    HSPrice                        UnderlyingPreClosePrice;
    /// 最高价
    HSPrice                        HighestPrice;
    /// 最低价
    HSPrice                        LowestPrice;
    /// 成交金额
    HSBalance                      TradeBalance;
    /// 成交数量
    HSVolume                       TradeVolume;
    /// 申买价一
    HSPrice                        BidPrice1;
    /// 申买量一
    HSVolume                       BidVolume1;
    /// 申卖价一
    HSPrice                        AskPrice1;
    /// 申卖量一
    HSVolume                       AskVolume1;
    /// 申买价二
    HSPrice                        BidPrice2;
    /// 申买量二
    HSVolume                       BidVolume2;
    /// 申卖价二
    HSPrice                        AskPrice2;
    /// 申卖量二
    HSVolume                       AskVolume2;
    /// 申买价三
    HSPrice                        BidPrice3;
    /// 申买量三
    HSVolume                       BidVolume3;
    /// 申卖价三
    HSPrice                        AskPrice3;
    /// 申卖量三
    HSVolume                       AskVolume3;
    /// 申买价四
    HSPrice                        BidPrice4;
    /// 申买量四
    HSVolume                       BidVolume4;
    /// 申卖价四
    HSPrice                        AskPrice4;
    /// 申卖量四
    HSVolume                       AskVolume4;
    /// 申买价五
    HSPrice                        BidPrice5;
    /// 申买量五
    HSVolume                       BidVolume5;
    /// 申卖价五
    HSPrice                        AskPrice5;
    /// 申卖量五
    HSVolume                       AskVolume5;
};

///交易所状态信息
struct CHSExchangeStatusField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 交易所状态
    HSExchangeStatus              ExchangeStatus;
    /// 申报标志
    HSTradingFlag                 TradingFlag;
};

///合约品种状态信息
struct CHSProductStatusField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 产品类型
    HSProductType                 ProductType;
    /// 合约品种代码
    HSProductID                   ProductID;
    /// 申报标志
    HSTradingFlag                 TradingFlag;
    /// 合约品种交易状态
    HSExchangeStatus              ProductStatus;
};

///可取资金查询请求
struct CHSReqQryWithdrawFundField
{
    /// 币种类别
    HSCurrencyID                  CurrencyID;
    /// 系统节点号
    HSSysnodeID                   SysNodeID;
};

///可取资金查询应答
struct CHSRspQryWithdrawFundField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 币种类别
    HSCurrencyID                  CurrencyID;
    /// 系统节点号
    HSSysnodeID                   SysNodeID;
    /// 系统节点名称
    HSSysnodeName                 SysNodeName;
    /// 可取资金
    HSBalance                     WithdrawBalance;
};

///组合合约查询
struct CHSReqQryCombInstrumentField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
};

///组合合约查询应答
struct CHSRspQryCombInstrumentField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 买卖方向
    HSDirection                   Direction;
    /// 第二腿买卖方向
    HSDirection                   SecondDirection;
    /// 组合策略类型
    HSCombStrategyType            CombStrategyType;
    /// 组合保证金系数
    HSVolume                      CombMarginCoeff;
    /// 优先级
    HSVolume                      PriorityLevel;
};

///席位查询请求
struct CHSReqQrySeatIDField
{
    /// 交易类别
    HSExchangeID                  ExchangeID;
};

///席位查询应答
struct CHSRspQrySeatIDField
{
    /// 交易类别
    HSExchangeID                  ExchangeID;
    /// 席位索引
    HSSeatIndex                   SeatIndex;
    /// 席位号
    HSSeatID                      SeatID;
};

///期权对冲设置请求
struct CHSReqOptionSelfCloseField
{
    /// 交易所代码
    HSExchangeID	              ExchangeID;
    /// 合约代码
    HSInstrumentID	              InstrumentID;
    /// 报单数量
    HSVolume	                  OrderVolume;
    /// 对冲类型
    HSSelfCloseType	              SelfCloseType;
};

///期权对冲设置应答
struct CHSRspOptionSelfCloseField
{
    /// 资金账号
    HSAccountID	                  AccountID;
    /// 交易所代码
    HSExchangeID	              ExchangeID;
    /// 合约代码
    HSInstrumentID	              InstrumentID;
    /// 报单数量
    HSVolume	                  OrderVolume;
    /// 对冲类型
    HSSelfCloseType	              SelfCloseType;
};

///期权对冲设置取消请求
struct CHSReqOptionSelfCloseActionField
{
    /// 交易所代码
    HSExchangeID	              ExchangeID;
    /// 合约代码
    HSInstrumentID	              InstrumentID;
    /// 对冲类型
    HSSelfCloseType	              SelfCloseType;
};

///期权对冲设置取消应答
struct CHSRspOptionSelfCloseActionField
{
    /// 资金账号
    HSAccountID	                  AccountID;
    /// 交易所代码
    HSExchangeID	              ExchangeID;
    /// 合约代码
    HSInstrumentID	              InstrumentID;
    /// 对冲类型
    HSSelfCloseType	              SelfCloseType;
};

///查询期权自对冲请求
struct CHSReqQryOptionSelfCloseField
{
    /// 交易所代码
    HSExchangeID	              ExchangeID;
    /// 合约代码
    HSInstrumentID	              InstrumentID;
};

///期权自对冲信息
struct CHSOptionSelfCloseField
{
    /// 资金账号
    HSAccountID	                  AccountID;
    /// 交易所代码
    HSExchangeID	              ExchangeID;
    /// 合约代码
    HSInstrumentID	              InstrumentID;
    /// 报单数量
    HSVolume	                  OrderVolume;
    /// 对冲类型
    HSSelfCloseType	              SelfCloseType;
    /// 报单状态
    HSOrderStatus	              OrderStatus;
    /// 对冲设置操作类型
    HSSetSelfCloseType	          SetSelfCloseType;
    /// 错误信息
    HSErrorMsg	                  ErrorMsg;
    /// 报单编码
    HSOrderSysID	              SelfCloseOrderSysID;
};

///期权对冲设置结果查询请求
struct CHSReqQryOptionSelfCloseResultField
{
    /// 交易所代码
    HSExchangeID	              ExchangeID;
    /// 合约代码
    HSInstrumentID	              InstrumentID;
};

///期权对冲设置结果查询应答
struct CHSRspQryOptionSelfCloseResultField
{
    /// 资金账号
    HSAccountID	                  AccountID;
    /// 交易所代码
    HSExchangeID	              ExchangeID;
    /// 合约代码
    HSInstrumentID	              InstrumentID;
    /// 对冲类型
    HSSelfCloseType	              SelfCloseType;
    /// 报单数量
    HSVolume	                  OrderVolume;
};

///银行转账信息
struct CHSTransferField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 转账流水
    HSNum                         TransferSerialID;
    /// 银行代码
    HSBankID                      BankID;
    /// 银行名称
    HSBankName                    BankName;
    /// 业务名称
    HSBusinessName                BusinessName;
    /// 发生金额
    HSBalance                     OccurBalance;
    /// 后资金额
    HSBalance                     PostBalance;
    /// 转账时间
    HSTime                        TransferTime;
    /// 转账状态
    HSTransferStatus              TransferStatus;
    /// 转账发起方
    HSTransferSource              TransferSource;
    /// 备注
    HSRemarks                     Remarks;
    /// 币种
    HSCurrencyID                  CurrencyID;
    /// 交易发起方日期
    HSDate                        OrderSourceDate;
    /// 交易日期
    HSDate                        TradingDay;
    /// 转账场景
    HSOccasion                    TransferOccasion;
};

/// 国密证书信息
struct CHSSMCertInfoField
{
    /// 证书标识
    HSCertID	                  CertID;
    /// 操作员账号
    HSAccountID	                  OperatorID;
    /// 设备标识
    HSDeviceID	                  DeviceID;
    /// 证书信息
    HSCertInfo	                  CertInfo;
    /// SKSpin密码
    HSSksPin	                  SksPin;
    /// 是否当前的设备标识
    HSIsCurrent                   IsCurrent;
};

///股票期权报价录入
struct CHSReqOptQuoteInsertField
{
    /// 交易类别
    HSExchangeID                   ExchangeID;
    /// 合约代码
    HSInstrumentID                 InstrumentID;
    /// 买方开平方向
    HSOffsetFlag                   BidOffsetFlag;
    /// 买方报价价格
    HSPrice                        BidOrderPrice;
    /// 买方报价数量
    HSVolume                       BidOrderVolume;
    /// 卖方开平方向
    HSOffsetFlag                   AskOffsetFlag;
    /// 卖方报价价格
    HSPrice                        AskOrderPrice;
    /// 卖方报价数量
    HSVolume                       AskOrderVolume;	
    /// 报价委托引用
    HSRef                          QuoteRef;
	/// 询价主场单号
    HSOrderSysID                   ForQuoteSysID;
};

///股票期权报价录入应答
struct CHSRspOptQuoteInsertField
{
    /// 账号
    HSAccountID                    AccountID;
    /// 交易类别
    HSExchangeID                   ExchangeID;
    /// 合约代码
    HSInstrumentID                 InstrumentID;
    /// 买方开平方向
    HSOffsetFlag                   BidOffsetFlag;
    /// 买方报价价格
    HSPrice                        BidOrderPrice;
    /// 买方报价数量
    HSVolume                       BidOrderVolume;
    /// 卖方开平方向
    HSOffsetFlag                   AskOffsetFlag;
    /// 卖方报价价格
    HSPrice                        AskOrderPrice;
    /// 卖方报价数量
    HSVolume                       AskOrderVolume;
    /// 报价编号
    HSBrokerOrderID                QuoteBrokerID;
    /// 报单时间
    HSTime                         InsertTime;
    /// 买方报单状态
    HSOrderStatus                  BidOrderStatus;
    /// 卖方报单状态
    HSOrderStatus                  AskOrderStatus;
    /// 报价委托引用
    HSRef                          QuoteRef;
	/// 询价主场单号
    HSOrderSysID                   ForQuoteSysID;
	/// 报价状态
    HSOrderStatus       	       OrderStatus;
    /// 会话编号
    HSSessionID                    SessionID;
};

///股票期权报价撤单
struct CHSReqOptQuoteActionField
{
    /// 交易类别
    HSExchangeID                   ExchangeID;
    /// 合约代码
    HSInstrumentID                 InstrumentID;
    /// 买方报价撤单数量
    HSVolume                       BidWithdrawVolume;
    /// 卖方报价撤单数量
    HSVolume                       AskWithdrawVolume;
    /// 报价撤单委托引用
    HSRef                          QuoteActionRef;
};

///股票期权报价撤单应答
struct CHSRspOptQuoteActionField
{
    /// 账号
    HSAccountID                    AccountID;
    /// 交易类别
    HSExchangeID                   ExchangeID;
    /// 合约代码
    HSInstrumentID                 InstrumentID;
    /// 报单时间
    HSTime                         InsertTime;
    /// 报价编号
    HSBrokerOrderID                QuoteBrokerID;
    /// 买方报价撤单数量
    HSVolume                       BidWithdrawVolume;
    /// 卖方报价撤单数量
    HSVolume                       AskWithdrawVolume;
    /// 买报单状态
    HSOrderStatus                  BidOrderStatus;
    /// 卖报单状态
    HSOrderStatus                  AskOrderStatus;
    /// 报价撤单委托引用
    HSRef                          QuoteActionRef;
	/// 报价状态
    HSOrderStatus       	       OrderStatus;
    /// 会话编号
    HSSessionID                    SessionID;
};

///股票期权报价查询
struct CHSReqQryOptQuoteField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 查询模式
    HSType                        QuoteQueryType;
    /// 报价编号
    HSBrokerOrderID               QuoteBrokerID;
};

///股票期权报价信息
struct CHSOptQuoteField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 报价编号
    HSBrokerOrderID               QuoteBrokerID;
    /// 买方开平方向
    HSOffsetFlag                  BidOffsetFlag;
    /// 买方报价价格
    HSPrice                       BidOrderPrice;
    /// 买方报价数量
    HSVolume                      BidOrderVolume;
    /// 买方成交价格
    HSPrice                       BidTradePrice;
    /// 买方成交数量
    HSVolume                      BidTradeVolume;
    /// 买方撤单数量
    HSVolume                      BidCancelVolume;
    /// 买方委托编号
    HSBrokerOrderID               BidBrokerOrderID;
    /// 买方报单状态
    HSOrderStatus                 BidOrderStatus;
    /// 卖方开平方向
    HSOffsetFlag                  AskOffsetFlag;
    /// 卖方报价价格
    HSPrice                       AskOrderPrice;
    /// 卖方报价数量
    HSVolume                      AskOrderVolume;
    /// 卖方成交价格
    HSPrice                       AskTradePrice;
    /// 卖方成交数量
    HSVolume                      AskTradeVolume;
    /// 卖方撤单数量
    HSVolume                      AskCancelVolume;
    /// 卖方委托编号
    HSBrokerOrderID               AskBrokerOrderID;
    /// 卖方报单状态
    HSOrderStatus                 AskOrderStatus;
    /// 提示信息
    HSErrorMsg                    ErrorMsg;
    /// 交易日
    HSDate                        TradingDay;
    /// 报单日期
    HSDate                        InsertDate;
    /// 报单时间
    HSTime                        InsertTime;
    /// 申报时间
    HSTime                        ReportTime;
    /// 会话编号
    HSSessionID                   SessionID;
    /// 期权对应的标的合约代码
    HSInstrumentID                UnderlyingInstrID;
    /// 报价委托引用
    HSRef                          QuoteRef;
    /// 询价报单编码
    HSOrderSysID                   ForQuoteSysID;
    /// 报价状态
    HSOrderStatus                  OrderStatus;
};

//股票期权报价撤单信息
struct CHSOptQuoteActionField
{
    /// 账号
    HSAccountID                   AccountID;
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 合约代码
    HSInstrumentID                InstrumentID;
    /// 交易日
    HSDate                        TradingDay;
    /// 报单日期
    HSDate                        InsertDate;
    /// 报单时间
    HSTime                        InsertTime;
    /// 申报时间
    HSTime                        ReportTime;
    /// 会话编号
    HSSessionID                   SessionID;
    /// 报价撤单委托引用
    HSRef                         QuoteActionRef;
    /// 提示信息
    HSErrorMsg                    ErrorMsg;
};

//股票期权组合策略信息查询请求
struct CHSReqQryOptCombStrategyField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 组合策略编码
    HSCombStrategyID              CombStrategyID;
};

//股票期权组合策略信息查询应答
struct CHSRspQryOptCombStrategyField
{
    /// 交易所代码
    HSExchangeID                  ExchangeID;
    /// 组合策略编码
    HSCombStrategyID              CombStrategyID;
    /// 组合策略名称
    HSCombStrategyName            CombStrategyName;
    /// 到期日是否相同
    HSFlag                        EndDateSameFlag;
    /// 标的证券是否相同
    HSFlag                        UnderlySameFlag;
    /// 合约单位是否相同
    HSFlag                        UnitSameFlag;
    /// 成分合约个数
    HSNum                         ComponentNum;
    /// 第一腿合约种类
    HSOptionsType                 FirstOptionsType;
    /// 第一腿合约持仓类型
    HSPositionType                FirstPositionType;
    /// 第一腿合约行权价格顺序
    HSNum                         FirstExercisePriceSeq;
    /// 每份第一腿合约数量
    HSNum                         FirstPerInstrumentAmount;
    /// 第二腿合约种类
    HSOptionsType                 SecondOptionsType;
    /// 第二腿合约持仓类型
    HSPositionType                SecondPositionType;
    /// 第二腿合约行权价格顺序
    HSNum                         SecondExercisePriceSeq;
    /// 每份第二腿合约数量
    HSNum                         SecondPerInstrumentAmount;
    /// 组合到期提前拆分天数
    HSNum                         NearSplitDays;
    /// 是否使用非标合约
    HSFlag                        NonStandardInstrumentFlag;
};

#pragma pack(pop)
#endif
