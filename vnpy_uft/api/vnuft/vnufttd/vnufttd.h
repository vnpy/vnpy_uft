//系统
#ifdef WIN32
#include "pch.h"
#endif

#include "vnuft.h"
#include "pybind11/pybind11.h"
#include "uft/HSTradeApi.h"


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
#define ONRSPERRORCOMBACTIONINSERT 12
#define ONRSPQUERYMAXORDERVOLUME 13
#define ONRSPQRYLOCKVOLUME 14
#define ONRSPQUERYEXERCISEVOLUME 15
#define ONRSPQRYCOMBVOLUME 16
#define ONRSPQRYPOSITION 17
#define ONRSPQRYTRADINGACCOUNT 18
#define ONRSPQRYORDER 19
#define ONRSPQRYTRADE 20
#define ONRSPQRYEXERCISE 21
#define ONRSPQRYLOCK 22
#define ONRSPQRYCOMBACTION 23
#define ONRSPQRYPOSITIONCOMBINEDETAIL 24
#define ONRSPQRYINSTRUMENT 25
#define ONRSPQRYCOVEREDSHORT 26
#define ONRSPQRYEXERCISEASSIGN 27
#define ONRSPTRANSFER 28
#define ONRSPQRYTRANSFER 29
#define ONRSPQUERYBANKBALANCE 30
#define ONRSPQUERYBANKACCOUNT 31
#define ONRSPMULTICENTREFUNDTRANS 32
#define ONRSPQUERYBILLCONTENT 33
#define ONRSPBILLCONFIRM 34
#define ONRSPQRYMARGIN 35
#define ONRSPQRYCOMMISSION 36
#define ONRSPQRYPOSITIONDETAIL 37
#define ONRSPQRYEXCHANGERATE 38
#define ONRSPQRYSYSCONFIG 39
#define ONRSPQRYDEPTHMARKETDATA 40
#define ONRSPFUNDTRANS 41
#define ONRSPQRYFUNDTRANS 42
#define ONRSPQRYCLIENTNOTICE 43
#define ONRSPQRYOPTUNDERLY 44
#define ONRSPQRYSECUDEPTHMARKET 45
#define ONRSPQRYHISTORDER 46
#define ONRSPQRYHISTTRADE 47
#define ONRTNTRADE 48
#define ONRTNORDER 49
#define ONRTNEXERCISE 50
#define ONRTNCOMBACTION 51
#define ONRTNLOCK 52
#define ONERRRTNORDERACTION 53
#define ONRTNCLIENTNOTICE 54


///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class TdApi : public CHSTradeSpi
{
private:
	CHSTradeApi* api;                     //API对象
    thread task_thread;                    //工作线程指针（向python中推送数据）
    TaskQueue task_queue;                //任务队列
    bool active = false;                //工作状态

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
	virtual void OnFrontConnected();

	/// Description:当客户端与交易后台通信连接异常时，该方法被调用。
	/// Others     :通过GetApiErrorMsg(nResult)获取详细错误信息。
	virtual void OnFrontDisconnected(int nResult);

	/// Description:客户认证
	virtual void OnRspAuthenticate(CHSRspAuthenticateField *pRspAuthenticate, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:终端信息上报接口(中继模式)
	virtual void OnRspSubmitUserSystemInfo(CHSRspUserSystemInfoField *pRspUserSystemInfo, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:客户登录
	virtual void OnRspUserLogin(CHSRspUserLoginField *pRspUserLogin, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:密码更改
	virtual void OnRspUserPasswordUpdate(CHSRspUserPasswordUpdateField *pRspUserPasswordUpdate, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:报单录入
	/// Others     :报单错误此方法被回调，pRspOrderInsert保存了请求时出错的结构体数据。
	virtual void OnRspErrorOrderInsert(CHSRspOrderInsertField *pRspOrderInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:撤单
	virtual void OnRspOrderAction(CHSRspOrderActionField *pRspOrderAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:行权录入
	/// Others     :行权录入错误此方法被回调，pRspExerciseOrderInsert保存了请求时出错的结构体数据。
	virtual void OnRspErrorExerciseOrderInsert(CHSRspExerciseOrderInsertField *pRspExerciseOrderInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:行权撤单
	virtual void OnRspExerciseOrderAction(CHSRspExerciseOrderActionField *pRspExerciseOrderAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:锁定录入
	/// Others     :锁定错误此方法被回调，pRspExerciseOrderAction保存了请求时出错的结构体数据。
	virtual void OnRspErrorLockInsert(CHSRspLockInsertField *pRspExerciseOrderAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:询价录入
	virtual void OnRspForQuoteInsert(CHSRspForQuoteInsertField *pRspForQuoteInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:申请组合录入
	virtual void OnRspErrorCombActionInsert(CHSRspCombActionInsertField *pRspCombActionInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:最大报单数量获取
	virtual void OnRspQueryMaxOrderVolume(CHSRspQueryMaxOrderVolumeField *pRspQueryMaxOrderVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:可锁定数量获取
	virtual void OnRspQryLockVolume(CHSRspQryLockVolumeField *pRspQryLockVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:可行权数量获取
	virtual void OnRspQueryExerciseVolume(CHSRspQueryExerciseVolumeField *pRspQueryExerciseVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:申请组合最大数量获取
	virtual void OnRspQryCombVolume(CHSRspQryCombVolumeField *pRspQryCombVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:持仓查询
	virtual void OnRspQryPosition(CHSRspQryPositionField *pRspQryPosition, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:资金账户查询
	virtual void OnRspQryTradingAccount(CHSRspQryTradingAccountField *pRspQryTradingAccount, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:报单查询
	virtual void OnRspQryOrder(CHSOrderField *pRspQryOrder, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:成交查询
	virtual void OnRspQryTrade(CHSTradeField *pRspQryTrade, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:行权查询
	virtual void OnRspQryExercise(CHSExerciseField *pRspQryExercise, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:锁定查询
	virtual void OnRspQryLock(CHSLockField *pRspQryLock, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:申请组合查询
	virtual void OnRspQryCombAction(CHSCombActionField *pRspQryCombAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:组合持仓明细查询
	virtual void OnRspQryPositionCombineDetail(CHSRspQryPositionCombineDetailField *pRspQryPositionCombineDetail, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:合约信息查询
	virtual void OnRspQryInstrument(CHSRspQryInstrumentField *pRspQryInstrument, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:备兑缺口查询
	virtual void OnRspQryCoveredShort(CHSRspQryCoveredShortField *pRspQryCoveredShort, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:行权指派查询
	virtual void OnRspQryExerciseAssign(CHSRspQryExerciseAssignField *pRspQryExerciseAssign, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:银行转账
	virtual void OnRspTransfer(CHSRspTransferField *pRspTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:银行转账查询
	virtual void OnRspQryTransfer(CHSRspQryTransferField *pRspQryTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:银行余额查询
	virtual void OnRspQueryBankBalance(CHSRspQueryBankBalanceField *pRspQueryBankBalance, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:银行账户查询
	virtual void OnRspQueryBankAccount(CHSRspQueryBankAccountField *pRspQueryBankAccount, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:多中心资金调拨
	virtual void OnRspMultiCentreFundTrans(CHSRspMultiCentreFundTransField *pRspMultiCentreFundTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:客户账单查询
	virtual void OnRspQueryBillContent(CHSRspQueryBillContentField *pRspQueryBillContent, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:客户账单确认
	virtual void OnRspBillConfirm(CHSRspBillConfirmField *pRspBillConfirm, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:保证金查询
	virtual void OnRspQryMargin(CHSRspQryMarginField *pRspQryMargin, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:手续费查询
	virtual void OnRspQryCommission(CHSRspQryCommissionField *pRspQryCommission, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:持仓明细查询
	virtual void OnRspQryPositionDetail(CHSRspQryPositionDetailField *pRspQryPositionDetail, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:汇率查询
	virtual void OnRspQryExchangeRate(CHSRspQryExchangeRateField *pRspQryExchangeRate, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:经纪公司配置参数查询
	virtual void OnRspQrySysConfig(CHSRspQrySysConfigField *pRspQrySysConfig, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:行情查询
	virtual void OnRspQryDepthMarketData(CHSDepthMarketDataField *pRspQryDepthMarketData, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:资金调拨
	virtual void OnRspFundTrans(CHSRspFundTransField *pRspFundTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:资金调拨流水查询
	virtual void OnRspQryFundTrans(CHSRspQryFundTransField *pRspQryFundTrans, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:查询客户通知
	virtual void OnRspQryClientNotice(CHSClientNoticeField *pRspQryClientNotice, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:期权标的信息查询
	virtual void OnRspQryOptUnderly(CHSRspQryOptUnderlyField *pRspQryOptUnderly, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:证券行情查询
	virtual void OnRspQrySecuDepthMarket(CHSRspQrySecuDepthMarketField *pRspQrySecuDepthMarket, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:历史报单查询
	virtual void OnRspQryHistOrder(CHSOrderField *pRspQryHistOrder, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:历史成交查询
	virtual void OnRspQryHistTrade(CHSTradeField *pRspQryHistTrade, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 主推-成交回报
	virtual void OnRtnTrade(CHSTradeField *pRtnTrade);

	/// Description: 主推-报单回报
	virtual void OnRtnOrder(CHSOrderField *pRtnOrder);

	/// Description: 主推-行权
	virtual void OnRtnExercise(CHSExerciseField *pRtnExercise);

	/// Description: 主推-申请组合
	virtual void OnRtnCombAction(CHSCombActionField *pRtnCombAction);

	/// Description: 主推-锁定
	virtual void OnRtnLock(CHSLockField *pRtnLock);

	/// Description: 主推-撤单错误回报
	virtual void OnErrRtnOrderAction(CHSOrderActionField *pRtnOrder);

	/// Description: 主推-客户通知
	virtual void OnRtnClientNotice(CHSClientNoticeField *pRtnClientNotice);

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

	void processRtnTrade(Task *task);

	void processRtnOrder(Task *task);

	void processRtnExercise(Task *task);

	void processRtnCombAction(Task *task);

	void processRtnLock(Task *task);

	void processErrRtnOrderAction(Task *task);

	void processRtnClientNotice(Task *task);

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

	virtual void onRtnTrade(const dict &data) {};

	virtual void onRtnOrder(const dict &data) {};

	virtual void onRtnExercise(const dict &data) {};

	virtual void onRtnCombAction(const dict &data) {};

	virtual void onRtnLock(const dict &data) {};

	virtual void onErrRtnOrderAction(const dict &data) {};

	virtual void onRtnClientNotice(const dict &data) {};

    //-------------------------------------------------------------------------------------
    //req:主动函数的请求字典
    //-------------------------------------------------------------------------------------

	void newTradeApi(string pszFlowPath);

    int init(string pszLicFile, string pszSafeLevel, string pszPwd, string pszSslFile, string pszSslPwd);

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
};
