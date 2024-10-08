//系统
#ifdef WIN32
#include "pch.h"
#endif

#include "vnuft.h"
#include "pybind11/pybind11.h"
#include "uft/HSMdApi.h"


using namespace pybind11;

//常量
#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONRSPDEPTHMARKETDATASUBSCRIBE 2
#define ONRSPDEPTHMARKETDATACANCEL 3
#define ONRTNDEPTHMARKETDATA 4
#define ONRSPFORQUOTESUBSCRIBE 5
#define ONRSPFORQUOTECANCEL 6
#define ONRTNFORQUOTE 7

///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class MdApi : public CHSMdSpi
{
private:
	CHSMdApi* api;				//API对象
	thread task_thread;			//工作线程指针（向python中推送数据）
	TaskQueue task_queue;		//任务队列
	bool active = false;		//工作状态

public:
	MdApi()
	{
	};

	~MdApi()
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

	/// Description: 订阅-行情应答
	virtual void OnRspDepthMarketDataSubscribe(CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 订阅取消-行情应答
	virtual void OnRspDepthMarketDataCancel(CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 主推-行情
	virtual void OnRtnDepthMarketData(CHSDepthMarketDataField *pDepthMarketData);

	/// Description: 订阅-询价应答
	virtual void OnRspForQuoteSubscribe(CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 订阅取消-询价应答
	virtual void OnRspForQuoteCancel(CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 主推-询价
	virtual void OnRtnForQuote(CHSForQuoteField *pForQuote);

	//-------------------------------------------------------------------------------------
	//task：任务
	//-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task *task);

	void processFrontDisconnected(Task *task);

	void processRspDepthMarketDataSubscribe(Task *task);

	void processRspDepthMarketDataCancel(Task *task);

	void processRtnDepthMarketData(Task *task);

	void processRspForQuoteSubscribe(Task *task);

	void processRspForQuoteCancel(Task *task);

	void processRtnForQuote(Task *task);

	//-------------------------------------------------------------------------------------
	//data：回调函数的数据字典
	//error：回调函数的错误字典
	//id：请求id
	//last：是否为最后返回
	//i：整数
	//-------------------------------------------------------------------------------------

	virtual void onFrontConnected() {};

	virtual void onFrontDisconnected(int reqid) {};

	virtual void onRspDepthMarketDataSubscribe(const dict &error, int reqid, bool last) {};

	virtual void onRspDepthMarketDataCancel(const dict &error, int reqid, bool last) {};

	virtual void onRtnDepthMarketData(const dict &data) {};

	virtual void onRspForQuoteSubscribe(const dict &error, int reqid, bool last) {};

	virtual void onRspForQuoteCancel(const dict &error, int reqid, bool last) {};

	virtual void onRtnForQuote(const dict &data) {};

	//-------------------------------------------------------------------------------------
	//req:主动函数的请求字典
	//-------------------------------------------------------------------------------------

	void newMdApi(string pszFlowPath);

	int init(dict pInitCfgField);

	int join(); 

	int exit();

	int registerFront(string pszFrontAddress);

	int registerFensServer(string pszFensAddress, string pszAccountID);

	int reqDepthMarketDataSubscribe(const dict &req, int reqid);

	int reqDepthMarketDataCancel(const dict &req, int reqid);

	int reqForQuoteSubscribe(const dict &req, int reqid);

	int reqForQuoteCancel(const dict &req, int reqid);

	string getApiErrorMsg(int nErrorCode);
};
