//ϵͳ
#ifdef WIN32
#include "pch.h"
#endif

#include "vnuft.h"
#include "pybind11/pybind11.h"
#include "uft/HSMdApi.h"


using namespace pybind11;

//����
#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONRSPDEPTHMARKETDATASUBSCRIBE 2
#define ONRSPDEPTHMARKETDATACANCEL 3
#define ONRTNDEPTHMARKETDATA 4
#define ONRSPFORQUOTESUBSCRIBE 5
#define ONRSPFORQUOTECANCEL 6
#define ONRTNFORQUOTE 7


///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class MdApi : public CHSMdSpi
{
private:
	CHSMdApi* api;				//API����
	thread task_thread;			//�����߳�ָ�루��python���������ݣ�
	TaskQueue task_queue;		//�������
	bool active = false;		//����״̬

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
	//API�ص�����
	//-------------------------------------------------------------------------------------

	/// Description: ���ͻ����뽻�׺�̨��ʼ����ͨ�����ӣ����ӳɹ���˷������ص���
	virtual void OnFrontConnected();

	/// Description:���ͻ����뽻�׺�̨ͨ�������쳣ʱ���÷��������á�
	/// Others     :ͨ��GetApiErrorMsg(nResult)��ȡ��ϸ������Ϣ��
	virtual void OnFrontDisconnected(int nResult);

	/// Description: ����-����Ӧ��
	virtual void OnRspDepthMarketDataSubscribe(CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ����ȡ��-����Ӧ��
	virtual void OnRspDepthMarketDataCancel(CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ����-����
	virtual void OnRtnDepthMarketData(CHSDepthMarketDataField *pDepthMarketData);

	/// Description: ����-ѯ��Ӧ��
	virtual void OnRspForQuoteSubscribe(CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ����ȡ��-ѯ��Ӧ��
	virtual void OnRspForQuoteCancel(CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ����-ѯ��
	virtual void OnRtnForQuote(CHSForQuoteField *pForQuote);

	//-------------------------------------------------------------------------------------
	//task������
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
	//data���ص������������ֵ�
	//error���ص������Ĵ����ֵ�
	//id������id
	//last���Ƿ�Ϊ��󷵻�
	//i������
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
	//req:���������������ֵ�
	//-------------------------------------------------------------------------------------

	void newMdApi(string pszFlowPath);

	int init(string pszLicFile, string pszSafeLevel, string pszPwd, string pszSslFile, string pszSslPwd);

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
