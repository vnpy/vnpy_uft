//系统
#ifdef WIN32
#include "pch.h"
#endif

#include "vnuft.h"
#include "pybind11/pybind11.h"
#include "uft/HSTradeApi.h"
#include "uft/HSDataType.h"


using namespace pybind11;

//常量
#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONRSPAUTHENTICATE 2
#define ONRSPSUBMITUSERSYSTEMINFO 3
#define ONRSPUSERLOGIN 4
#define ONRSPUSERPASSWORDUPDATE 5
#define ONRSPERRORORDERINSERT 6
#define ONRSPORDERACTION 7
#define ONRSPERROREXERCISEORDERINSERT 8
#define ONRSPEXERCISEORDERACTION 9
#define ONRSPERRORLOCKINSERT 10
#define ONRSPFORQUOTEINSERT 11
#define ONRSPERRORQUOTEINSERT 12
#define ONRSPQUOTEACTION 13
#define ONRSPERRORCOMBACTIONINSERT 14
#define ONRSPQUERYMAXORDERVOLUME 15
#define ONRSPQRYLOCKVOLUME 16
#define ONRSPQUERYEXERCISEVOLUME 17
#define ONRSPQRYCOMBVOLUME 18
#define ONRSPQRYPOSITION 19
#define ONRSPQRYTRADINGACCOUNT 20
#define ONRSPQRYORDER 21
#define ONRSPQRYTRADE 22
#define ONRSPQRYEXERCISE 23
#define ONRSPQRYLOCK 24
#define ONRSPQRYCOMBACTION 25
#define ONRSPQRYFORQUOTE 26
#define ONRSPQRYQUOTE 27
#define ONRSPQRYPOSITIONCOMBINEDETAIL 28
#define ONRSPQRYINSTRUMENT 29
#define ONRSPQRYCOVEREDSHORT 30
#define ONRSPQRYEXERCISEASSIGN 31
#define ONRSPTRANSFER 32
#define ONRSPQRYTRANSFER 33
#define ONRSPQUERYBANKBALANCE 34
#define ONRSPQUERYBANKACCOUNT 35
#define ONRSPMULTICENTREFUNDTRANS 36
#define ONRSPQUERYBILLCONTENT 37
#define ONRSPBILLCONFIRM 38
#define ONRSPQRYMARGIN 39
#define ONRSPQRYCOMMISSION 40
#define ONRSPQRYPOSITIONDETAIL 41
#define ONRSPQRYEXCHANGERATE 42
#define ONRSPQRYSYSCONFIG 43
#define ONRSPQRYDEPTHMARKETDATA 44
#define ONRSPFUNDTRANS 45
#define ONRSPQRYFUNDTRANS 46
#define ONRSPQRYCLIENTNOTICE 47
#define ONRSPQRYOPTUNDERLY 48
#define ONRSPQRYSECUDEPTHMARKET 49
#define ONRSPQRYHISTORDER 50
#define ONRSPQRYHISTTRADE 51
#define ONRSPQRYWITHDRAWFUND 52
#define ONRSPQRYCOMBINSTRUMENT 53
#define ONRSPQRYSEATID 54
#define ONRSPOPTIONSELFCLOSE 55
#define ONRSPOPTIONSELFCLOSEACTION 56
#define ONRSPQRYOPTIONSELFCLOSERESULT 57
#define ONRSPQRYOPTIONSELFCLOSE 58
#define ONRSPERROROPTQUOTEINSERT 59
#define ONRSPOPTQUOTEACTION 60
#define ONRSPQRYOPTQUOTE 61
#define ONRSPQRYOPTCOMBSTRATEGY 62
#define ONRTNTRADE 63
#define ONRTNORDER 64
#define ONRTNEXERCISE 65
#define ONRTNCOMBACTION 66
#define ONRTNLOCK 67
#define ONERRRTNORDERACTION 68
#define ONRTNCLIENTNOTICE 69
#define ONRTNFORQUOTE 70
#define ONRTNQUOTE 71
#define ONRTNEXCHANGESTATUS 72
#define ONRTNPRODUCTSTATUS 73
#define ONRTNOPTIONSELFCLOSE 74
#define ONRTNOPTQUOTE 75
#define ONRTNTRANSFER 76
#define ONERRRTNOPTQUOTEACTION 77

///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class TdApi : public CHSTradeSpi
{
private:
	CHSTradeApi* api;                    //API对象
	thread task_thread;                  //工作线程指针（向python中推送数据）
	TaskQueue task_queue;                //任务队列
	bool active = false;                 //工作状态

public:
	TdApi()
	{
	};

	~TdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};

	//-------------------------------------------------------------------------------------
	//API回调函数
	//-------------------------------------------------------------------------------------

	/// Description: 当客户端与交易后台开始建立通信连接，连接成功后此方法被回调。
	void OnFrontConnected();

	/// Description:当客户端与交易后台通信连接异常时，该方法被调用。
	/// Others     :通过GetApiErrorMsg(nResult)获取详细错误信息。
	void OnFrontDisconnected(int nResult);

	/// Description:客户认证
	void OnRspAuthenticate(CHSRspAuthenticateField *pRspAuthenticate, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:终端信息上报接口(中继模式)
	void OnRspSubmitUserSystemInfo(CHSRspUserSystemInfoField *pRspUserSystemInfo, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:客户登录
	void OnRspUserLogin(CHSRspUserLoginField *pRspUserLogin, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:密码更改
	void OnRspUserPasswordUpdate(CHSRspUserPasswordUpdateField *pRspUserPasswordUpdate, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:报单录入
	/// Others     :报单错误此方法被回调，pRspOrderInsert保存了请求时出错的结构体数据。
	void OnRspErrorOrderInsert(CHSRspOrderInsertField *pRspOrderInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:撤单
	void OnRspOrderAction(CHSRspOrderActionField *pRspOrderAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:行权录入
	/// Others     :行权录入错误此方法被回调，pRspExerciseOrderInsert保存了请求时出错的结构体数据。
	void OnRspErrorExerciseOrderInsert(CHSRspExerciseOrderInsertField *pRspExerciseOrderInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:行权撤单
	void OnRspExerciseOrderAction(CHSRspExerciseOrderActionField *pRspExerciseOrderAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:锁定录入
	/// Others     :锁定错误此方法被回调，pRspExerciseOrderAction保存了请求时出错的结构体数据。
	void OnRspErrorLockInsert(CHSRspLockInsertField *pRspExerciseOrderAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:询价录入
	void OnRspForQuoteInsert(CHSRspForQuoteInsertField *pRspForQuoteInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:报价录入
	/// Others     :报价错误此方法被回调，pRspQuoteInsert保存了请求时出错的结构体数据。
	void OnRspErrorQuoteInsert(CHSRspQuoteInsertField *pRspQuoteInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:报价撤单
	void OnRspQuoteAction(CHSRspQuoteActionField *pRspQuoteAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:申请组合录入
	void OnRspErrorCombActionInsert(CHSRspCombActionInsertField *pRspCombActionInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:最大报单数量获取
	void OnRspQueryMaxOrderVolume(CHSRspQueryMaxOrderVolumeField *pRspQueryMaxOrderVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:可锁定数量获取
	void OnRspQryLockVolume(CHSRspQryLockVolumeField *pRspQryLockVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:可行权数量获取
	void OnRspQueryExerciseVolume(CHSRspQueryExerciseVolumeField *pRspQueryExerciseVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:申请组合最大数量获取
	void OnRspQryCombVolume(CHSRspQryCombVolumeField *pRspQryCombVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:持仓查询
	void OnRspQryPosition(CHSRspQryPositionField *pRspQryPosition, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:资金账户查询
	void OnRspQryTradingAccount(CHSRspQryTradingAccountField *pRspQryTradingAccount, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:报单查询
	void OnRspQryOrder(CHSOrderField *pRspQryOrder, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:成交查询
	void OnRspQryTrade(CHSTradeField *pRspQryTrade, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:行权查询
	void OnRspQryExercise(CHSExerciseField *pRspQryExercise, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:锁定查询
	void OnRspQryLock(CHSLockField *pRspQryLock, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:申请组合查询
	void OnRspQryCombAction(CHSCombActionField *pRspQryCombAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:询价查询
	void OnRspQryForQuote(CHSForQuoteField *pRspQryForQuote, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:报价查询
	void OnRspQryQuote(CHSQuoteField *pRspQryQuote, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:组合持仓明细查询
	void OnRspQryPositionCombineDetail(CHSRspQryPositionCombineDetailField *pRspQryPositionCombineDetail, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:合约信息查询
	void OnRspQryInstrument(CHSRspQryInstrumentField *pRspQryInstrument, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:备兑缺口查询
	void OnRspQryCoveredShort(CHSRspQryCoveredShortField *pRspQryCoveredShort, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:行权指派查询
	void OnRspQryExerciseAssign(CHSRspQryExerciseAssignField *pRspQryExerciseAssign, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:银行转账
	void OnRspTransfer(CHSRspTransferField *pRspTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:银行转账查询
	void OnRspQryTransfer(CHSRspQryTransferField *pRspQryTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:银行余额查询
	void OnRspQueryBankBalance(CHSRspQueryBankBalanceField *pRspQueryBankBalance, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:银行账户查询
	void OnRspQueryBankAccount(CHSRspQueryBankAccountField *pRspQueryBankAccount, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:多中心资金调拨
	void OnRspMultiCentreFundTrans(CHSRspMultiCentreFundTransField *pRspMultiCentreFundTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:客户账单查询
	void OnRspQueryBillContent(CHSRspQueryBillContentField *pRspQueryBillContent, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:客户账单确认
	void OnRspBillConfirm(CHSRspBillConfirmField *pRspBillConfirm, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:保证金查询
	void OnRspQryMargin(CHSRspQryMarginField *pRspQryMargin, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:手续费查询
	void OnRspQryCommission(CHSRspQryCommissionField *pRspQryCommission, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:持仓明细查询
	void OnRspQryPositionDetail(CHSRspQryPositionDetailField *pRspQryPositionDetail, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:汇率查询
	void OnRspQryExchangeRate(CHSRspQryExchangeRateField *pRspQryExchangeRate, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:经纪公司配置参数查询
	void OnRspQrySysConfig(CHSRspQrySysConfigField *pRspQrySysConfig, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:行情查询
	void OnRspQryDepthMarketData(CHSDepthMarketDataField *pRspQryDepthMarketData, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:资金调拨
	void OnRspFundTrans(CHSRspFundTransField *pRspFundTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:资金调拨流水查询
	void OnRspQryFundTrans(CHSRspQryFundTransField *pRspQryFundTrans, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:查询客户通知
	void OnRspQryClientNotice(CHSClientNoticeField *pRspQryClientNotice, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:期权标的信息查询
	void OnRspQryOptUnderly(CHSRspQryOptUnderlyField *pRspQryOptUnderly, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:证券行情查询
	void OnRspQrySecuDepthMarket(CHSRspQrySecuDepthMarketField *pRspQrySecuDepthMarket, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:历史报单查询
	void OnRspQryHistOrder(CHSOrderField *pRspQryHistOrder, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:历史成交查询
	void OnRspQryHistTrade(CHSTradeField *pRspQryHistTrade, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:可取资金查询
	void OnRspQryWithdrawFund(CHSRspQryWithdrawFundField *pRspQryWithdrawFund, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:组合合约查询
	void OnRspQryCombInstrument(CHSRspQryCombInstrumentField *pRspQryCombInstrument, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:席位查询
	void OnRspQrySeatID(CHSRspQrySeatIDField *pRspQrySeatID, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:期权自对冲设置
	void OnRspOptionSelfClose(CHSRspOptionSelfCloseField *pReqOptionSelfClose, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:期权自对冲设置取消
	void OnRspOptionSelfCloseAction(CHSRspOptionSelfCloseActionField *pReqOptionSelfCloseAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:期权自对冲设置结果查询
	void OnRspQryOptionSelfCloseResult(CHSRspQryOptionSelfCloseResultField *pReqQryOptionSelfCloseResult, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:期权自对冲查询
	void OnRspQryOptionSelfClose(CHSOptionSelfCloseField *pRspQryOptionSelfClose, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:股票期权报价录入
	/// Others     :股票期权报价录入错误此方法被回调，pRspOptQuoteInsert保存了请求时出错的结构体数据。
	void OnRspErrorOptQuoteInsert(CHSRspOptQuoteInsertField *pRspOptQuoteInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:股票期权报价撤单
	void OnRspOptQuoteAction(CHSRspOptQuoteActionField *pRspOptQuoteAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:股票期权报价查询
	void OnRspQryOptQuote(CHSOptQuoteField *pRspQryOptQuote, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:股票期权组合策略信息查询
	void OnRspQryOptCombStrategy(CHSRspQryOptCombStrategyField *pRspQryOptCombStrategy, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 主推-成交回报
	void OnRtnTrade(CHSTradeField *pRtnTrade);

	/// Description: 主推-报单回报
	void OnRtnOrder(CHSOrderField *pRtnOrder);

	/// Description: 主推-行权
	void OnRtnExercise(CHSExerciseField *pRtnExercise);

	/// Description: 主推-申请组合
	void OnRtnCombAction(CHSCombActionField *pRtnCombAction);

	/// Description: 主推-锁定
	void OnRtnLock(CHSLockField *pRtnLock);

	/// Description: 主推-撤单错误回报
	void OnErrRtnOrderAction(CHSOrderActionField *pRtnOrder);

	/// Description: 主推-客户通知
	void OnRtnClientNotice(CHSClientNoticeField *pRtnClientNotice);

	/// Description: 主推-询价回报
	void OnRtnForQuote(CHSForQuoteField *pRtnForQuote);

	/// Description: 主推-报价回报
	void OnRtnQuote(CHSQuoteField *pRtnQuote);

	/// Description: 主推-交易所状态
	void OnRtnExchangeStatus(CHSExchangeStatusField *pRtnExchangeStatus);

	/// Description: 主推-合约品种状态
	void OnRtnProductStatus(CHSProductStatusField *pRtnProductStatus);

	/// Description: 主推-期权自对冲
	void OnRtnOptionSelfClose(CHSOptionSelfCloseField *pRtnOptionSelfClose);

	/// Description: 主推-股票期权报价回报
	void OnRtnOptQuote(CHSOptQuoteField *pRtnOptQuote);

	/// Description: 主推-银行转账回报
	void OnRtnTransfer(CHSTransferField *pRtnTransfer);

	/// Description: 主推-股票期权报价撤单错误回报
	void OnErrRtnOptQuoteAction(CHSOptQuoteActionField *pRtnOptQuoteAction);

	//-------------------------------------------------------------------------------------
	//task：任务
	//-------------------------------------------------------------------------------------
	void processTask();

	void processFrontConnected(Task *task);

	void processFrontDisconnected(Task *task);

	void processRspAuthenticate(Task *task);

	void processRspSubmitUserSystemInfo(Task *task);

	void processRspUserLogin(Task *task);

	void processRspUserPasswordUpdate(Task *task);

	void processRspErrorOrderInsert(Task *task);

	void processRspOrderAction(Task *task);

	void processRspErrorExerciseOrderInsert(Task *task);

	void processRspExerciseOrderAction(Task *task);

	void processRspErrorLockInsert(Task *task);

	void processRspForQuoteInsert(Task *task);

	void processRspErrorQuoteInsert(Task *task);

	void processRspQuoteAction(Task *task);

	void processRspErrorCombActionInsert(Task *task);

	void processRspQueryMaxOrderVolume(Task *task);

	void processRspQryLockVolume(Task *task);

	void processRspQueryExerciseVolume(Task *task);

	void processRspQryCombVolume(Task *task);

	void processRspQryPosition(Task *task);

	void processRspQryTradingAccount(Task *task);

	void processRspQryOrder(Task *task);

	void processRspQryTrade(Task *task);

	void processRspQryExercise(Task *task);

	void processRspQryLock(Task *task);

	void processRspQryCombAction(Task *task);

	void processRspQryForQuote(Task *task);

	void processRspQryQuote(Task *task);

	void processRspQryPositionCombineDetail(Task *task);

	void processRspQryInstrument(Task *task);

	void processRspQryCoveredShort(Task *task);

	void processRspQryExerciseAssign(Task *task);

	void processRspTransfer(Task *task);

	void processRspQryTransfer(Task *task);

	void processRspQueryBankBalance(Task *task);

	void processRspQueryBankAccount(Task *task);

	void processRspMultiCentreFundTrans(Task *task);

	void processRspQueryBillContent(Task *task);

	void processRspBillConfirm(Task *task);

	void processRspQryMargin(Task *task);

	void processRspQryCommission(Task *task);

	void processRspQryPositionDetail(Task *task);

	void processRspQryExchangeRate(Task *task);

	void processRspQrySysConfig(Task *task);

	void processRspQryDepthMarketData(Task *task);

	void processRspFundTrans(Task *task);

	void processRspQryFundTrans(Task *task);

	void processRspQryClientNotice(Task *task);

	void processRspQryOptUnderly(Task *task);

	void processRspQrySecuDepthMarket(Task *task);

	void processRspQryHistOrder(Task *task);

	void processRspQryHistTrade(Task *task);

	void processRspQryWithdrawFund(Task *task);

	void processRspQryCombInstrument(Task *task);

	void processRspQrySeatID(Task *task);

	void processRspOptionSelfClose(Task *task);

	void processRspOptionSelfCloseAction(Task *task);

	void processRspQryOptionSelfCloseResult(Task *task);

	void processRspQryOptionSelfClose(Task *task);

	void processRspErrorOptQuoteInsert(Task *task);

	void processRspOptQuoteAction(Task *task);

	void processRspQryOptQuote(Task *task);

	void processRspQryOptCombStrategy(Task *task);

	void processRtnTrade(Task *task);

	void processRtnOrder(Task *task);

	void processRtnExercise(Task *task);

	void processRtnCombAction(Task *task);

	void processRtnLock(Task *task);

	void processErrRtnOrderAction(Task *task);

	void processRtnClientNotice(Task *task);

	void processRtnForQuote(Task *task);

	void processRtnQuote(Task *task);

	void processRtnExchangeStatus(Task *task);

	void processRtnProductStatus(Task *task);

	void processRtnOptionSelfClose(Task *task);

	void processRtnOptQuote(Task *task);

	void processRtnTransfer(Task *task);

	void processErrRtnOptQuoteAction(Task *task);

	//-------------------------------------------------------------------------------------
	//data：回调函数的数据字典
	//error：回调函数的错误字典
	//id：请求id
	//last：是否为最后返回
	//i：整数
	//-------------------------------------------------------------------------------------    

	virtual void onFrontConnected() {};

	virtual void onFrontDisconnected(int reqid) {};

	virtual void onRspAuthenticate(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspSubmitUserSystemInfo(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspUserLogin(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspUserPasswordUpdate(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspErrorOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspOrderAction(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspErrorExerciseOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspExerciseOrderAction(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspErrorLockInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspForQuoteInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspErrorQuoteInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQuoteAction(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspErrorCombActionInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQueryMaxOrderVolume(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryLockVolume(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQueryExerciseVolume(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryCombVolume(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryPosition(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryTradingAccount(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOrder(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryTrade(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryExercise(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryLock(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryCombAction(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryForQuote(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryQuote(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryPositionCombineDetail(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryInstrument(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryCoveredShort(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryExerciseAssign(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspTransfer(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryTransfer(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQueryBankBalance(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQueryBankAccount(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspMultiCentreFundTrans(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQueryBillContent(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspBillConfirm(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryMargin(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryCommission(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryPositionDetail(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryExchangeRate(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQrySysConfig(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryDepthMarketData(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspFundTrans(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryFundTrans(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryClientNotice(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOptUnderly(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQrySecuDepthMarket(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryHistOrder(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryHistTrade(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryWithdrawFund(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryCombInstrument(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQrySeatID(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspOptionSelfClose(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspOptionSelfCloseAction(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOptionSelfCloseResult(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOptionSelfClose(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspErrorOptQuoteInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspOptQuoteAction(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOptQuote(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOptCombStrategy(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRtnTrade(const dict &data) {};

	virtual void onRtnOrder(const dict &data) {};

	virtual void onRtnExercise(const dict &data) {};

	virtual void onRtnCombAction(const dict &data) {};

	virtual void onRtnLock(const dict &data) {};

	virtual void onErrRtnOrderAction(const dict &data) {};

	virtual void onRtnClientNotice(const dict &data) {};

	virtual void onRtnForQuote(const dict &data) {};

	virtual void onRtnQuote(const dict &data) {};

	virtual void onRtnExchangeStatus(const dict &data) {};

	virtual void onRtnProductStatus(const dict &data) {};

	virtual void onRtnOptionSelfClose(const dict &data) {};

	virtual void onRtnOptQuote(const dict &data) {};

	virtual void onRtnTransfer(const dict &data) {};

	virtual void onErrRtnOptQuoteAction(const dict &data) {};

	//-------------------------------------------------------------------------------------
	//req:主动函数的请求字典
	//-------------------------------------------------------------------------------------

	void newTradeApi(string pszFlowPath);

	int init(dict pInitCfgField);

	int join();

	int exit();

	int rgisterSubModel(int eSubType);

	int registerFront(string pszFrontAddress);

	int registerFensServer(string pszFensAddress, string pszAccountID);

	string getApiErrorMsg(int nErrorCode);

	int getTradingDate();

	int reqAuthenticate(const dict &req, int reqid);

	int reqSubmitUserSystemInfo(const dict &req, int reqid);

	int reqUserLogin(const dict &req, int reqid);

	int reqUserPasswordUpdate(const dict &req, int reqid);

	int reqOrderInsert(const dict &req, int reqid);

	int reqOrderAction(const dict &req, int reqid);

	int reqExerciseOrderInsert(const dict &req, int reqid);

	int reqExerciseOrderAction(const dict &req, int reqid);

	int reqLockInsert(const dict &req, int reqid);

	int reqForQuoteInsert(const dict &req, int reqid);

	int reqQuoteInsert(const dict &req, int reqid);

	int reqQuoteAction(const dict &req, int reqid);

	int reqCombActionInsert(const dict &req, int reqid);

	int reqQueryMaxOrderVolume(const dict &req, int reqid);

	int reqQryLockVolume(const dict &req, int reqid);

	int reqQueryExerciseVolume(const dict &req, int reqid);

	int reqQryCombVolume(const dict &req, int reqid);

	int reqQryPosition(const dict &req, int reqid);

	int reqQryTradingAccount(const dict &req, int reqid);

	int reqQryOrder(const dict &req, int reqid);

	int reqQryTrade(const dict &req, int reqid);

	int reqQryExercise(const dict &req, int reqid);

	int reqQryLock(const dict &req, int reqid);

	int reqQryCombAction(const dict &req, int reqid);

	int reqQryForQuote(const dict &req, int reqid);

	int reqQryQuote(const dict &req, int reqid);

	int reqQryPositionCombineDetail(const dict &req, int reqid);

	int reqQryInstrument(const dict &req, int reqid);

	int reqQryCoveredShort(const dict &req, int reqid);

	int reqQryExerciseAssign(const dict &req, int reqid);

	int reqTransfer(const dict &req, int reqid);

	int reqQryTransfer(const dict &req, int reqid);

	int reqQueryBankBalance(const dict &req, int reqid);

	int reqQueryBankAccount(const dict &req, int reqid);

	int reqMultiCentreFundTrans(const dict &req, int reqid);

	int reqQueryBillContent(const dict &req, int reqid);

	int reqBillConfirm(const dict &req, int reqid);

	int reqQryMargin(const dict &req, int reqid);

	int reqQryCommission(const dict &req, int reqid);

	int reqQryExchangeRate(const dict &req, int reqid);

	int reqQryPositionDetail(const dict &req, int reqid);

	int reqQrySysConfig(const dict &req, int reqid);

	int reqQryDepthMarketData(const dict &req, int reqid);

	int reqFundTrans(const dict &req, int reqid);

	int reqQryFundTrans(const dict &req, int reqid);

	int reqQryClientNotice(const dict &req, int reqid);

	int reqQryOptUnderly(const dict &req, int reqid);

	int reqQrySecuDepthMarket(const dict &req, int reqid);

	int reqQryHistOrder(const dict &req, int reqid);

	int reqQryHistTrade(const dict &req, int reqid);

	int reqQryWithdrawFund(const dict &req, int reqid);

	int reqQryCombInstrument(const dict &req, int reqid);

	int reqQrySeatID(const dict &req, int reqid);

	int reqOptionSelfClose(const dict &req, int reqid);

	int reqOptionSelfCloseAction(const dict &req, int reqid);

	int reqQryOptionSelfCloseResult(const dict &req, int reqid);

	int reqQryOptionSelfClose(const dict &req, int reqid);

	int reqOptQuoteInsert(const dict &req, int reqid);

	int reqOptQuoteAction(const dict &req, int reqid);

	int reqQryOptQuote(const dict &req, int reqid);

	int reqQryOptCombStrategy(const dict &req, int reqid);
};