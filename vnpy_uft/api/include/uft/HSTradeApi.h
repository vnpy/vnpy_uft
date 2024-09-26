/**
* @author �ٺط�
* @company �������ӹɷ����޹�˾
* @file HSTradeApi.h
* @brief �����˽��׽ӿ�
* @date    20170927
*/
#ifndef _HS_TRADE_API_H_
#define _HS_TRADE_API_H_

#include "HSStruct.h"

#ifdef _WIN32
    #define TRADE_API_EXPORT
#else
    #ifdef HSTRADEAPI_EXPORTS
        #define TRADE_API_EXPORT __attribute__((visibility("default"))) 
    #else
        #define TRADE_API_EXPORT
    #endif
#endif

/// �ص�����
class CHSTradeSpi
{
public:
    /// Description: ���ͻ����뽻�׺�̨��ʼ����ͨ�����ӣ����ӳɹ���˷������ص���
    virtual void OnFrontConnected(){};

    /// Description:���ͻ����뽻�׺�̨ͨ�������쳣ʱ���÷��������á�
    /// Others     :ͨ��GetApiErrorMsg(nResult)��ȡ��ϸ������Ϣ��
    virtual void OnFrontDisconnected(int nResult){};

    /// Description:�ͻ���֤
    virtual void OnRspAuthenticate(CHSRspAuthenticateField *pRspAuthenticate, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�ն���Ϣ�ϱ��ӿ�(�м�ģʽ)
    virtual void OnRspSubmitUserSystemInfo(CHSRspUserSystemInfoField *pRspUserSystemInfo, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�ͻ���¼
    virtual void OnRspUserLogin(CHSRspUserLoginField *pRspUserLogin, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�������
    virtual void OnRspUserPasswordUpdate(CHSRspUserPasswordUpdateField *pRspUserPasswordUpdate, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:����¼��
    /// Others     :��������˷������ص���pRspOrderInsert����������ʱ����Ľṹ�����ݡ�
    virtual void OnRspErrorOrderInsert(CHSRspOrderInsertField *pRspOrderInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:����
    virtual void OnRspOrderAction(CHSRspOrderActionField *pRspOrderAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��Ȩ¼��
    /// Others     :��Ȩ¼�����˷������ص���pRspExerciseOrderInsert����������ʱ����Ľṹ�����ݡ�
    virtual void OnRspErrorExerciseOrderInsert(CHSRspExerciseOrderInsertField *pRspExerciseOrderInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��Ȩ����
    virtual void OnRspExerciseOrderAction(CHSRspExerciseOrderActionField *pRspExerciseOrderAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:����¼��
    /// Others     :��������˷������ص���pRspExerciseOrderAction����������ʱ����Ľṹ�����ݡ�
    virtual void OnRspErrorLockInsert(CHSRspLockInsertField *pRspExerciseOrderAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:ѯ��¼��
    virtual void OnRspForQuoteInsert(CHSRspForQuoteInsertField *pRspForQuoteInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:����¼��
    /// Others     :���۴���˷������ص���pRspQuoteInsert����������ʱ����Ľṹ�����ݡ�
    virtual void OnRspErrorQuoteInsert(CHSRspQuoteInsertField* pRspQuoteInsert, CHSRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description:���۳���
    virtual void OnRspQuoteAction(CHSRspQuoteActionField* pRspQuoteAction, CHSRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description:�������¼��
    virtual void OnRspErrorCombActionInsert(CHSRspCombActionInsertField *pRspCombActionInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��󱨵�������ȡ
    virtual void OnRspQueryMaxOrderVolume(CHSRspQueryMaxOrderVolumeField *pRspQueryMaxOrderVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:������������ȡ
    virtual void OnRspQryLockVolume(CHSRspQryLockVolumeField *pRspQryLockVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:����Ȩ������ȡ
    virtual void OnRspQueryExerciseVolume(CHSRspQueryExerciseVolumeField *pRspQueryExerciseVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:����������������ȡ
    virtual void OnRspQryCombVolume(CHSRspQryCombVolumeField *pRspQryCombVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�ֲֲ�ѯ
    virtual void OnRspQryPosition(CHSRspQryPositionField *pRspQryPosition, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�ʽ��˻���ѯ
    virtual void OnRspQryTradingAccount(CHSRspQryTradingAccountField *pRspQryTradingAccount, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:������ѯ
    virtual void OnRspQryOrder(CHSOrderField *pRspQryOrder, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�ɽ���ѯ
    virtual void OnRspQryTrade(CHSTradeField *pRspQryTrade, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��Ȩ��ѯ
    virtual void OnRspQryExercise(CHSExerciseField *pRspQryExercise, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:������ѯ
    virtual void OnRspQryLock(CHSLockField *pRspQryLock, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:������ϲ�ѯ
    virtual void OnRspQryCombAction(CHSCombActionField *pRspQryCombAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:ѯ�۲�ѯ
    virtual void OnRspQryForQuote(CHSForQuoteField* pRspQryForQuote, CHSRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description:���۲�ѯ
    virtual void OnRspQryQuote(CHSQuoteField* pRspQryQuote, CHSRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description:��ϳֲ���ϸ��ѯ
    virtual void OnRspQryPositionCombineDetail(CHSRspQryPositionCombineDetailField *pRspQryPositionCombineDetail, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��Լ��Ϣ��ѯ
    virtual void OnRspQryInstrument(CHSRspQryInstrumentField *pRspQryInstrument, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:����ȱ�ڲ�ѯ
    virtual void OnRspQryCoveredShort(CHSRspQryCoveredShortField *pRspQryCoveredShort, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��Ȩָ�ɲ�ѯ
    virtual void OnRspQryExerciseAssign(CHSRspQryExerciseAssignField *pRspQryExerciseAssign, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:����ת��
    virtual void OnRspTransfer(CHSRspTransferField *pRspTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:����ת�˲�ѯ
    virtual void OnRspQryTransfer(CHSRspQryTransferField *pRspQryTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��������ѯ
    virtual void OnRspQueryBankBalance(CHSRspQueryBankBalanceField *pRspQueryBankBalance, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�����˻���ѯ
    virtual void OnRspQueryBankAccount(CHSRspQueryBankAccountField *pRspQueryBankAccount, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�������ʽ����
    virtual void OnRspMultiCentreFundTrans(CHSRspMultiCentreFundTransField *pRspMultiCentreFundTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�ͻ��˵���ѯ
    virtual void OnRspQueryBillContent(CHSRspQueryBillContentField *pRspQueryBillContent, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�ͻ��˵�ȷ��
    virtual void OnRspBillConfirm(CHSRspBillConfirmField *pRspBillConfirm, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��֤���ѯ
    virtual void OnRspQryMargin(CHSRspQryMarginField *pRspQryMargin, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�����Ѳ�ѯ
    virtual void OnRspQryCommission(CHSRspQryCommissionField *pRspQryCommission, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�ֲ���ϸ��ѯ
    virtual void OnRspQryPositionDetail(CHSRspQryPositionDetailField *pRspQryPositionDetail, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:���ʲ�ѯ
    virtual void OnRspQryExchangeRate(CHSRspQryExchangeRateField *pRspQryExchangeRate, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:���͹�˾���ò�����ѯ
    virtual void OnRspQrySysConfig(CHSRspQrySysConfigField *pRspQrySysConfig, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�����ѯ
    virtual void OnRspQryDepthMarketData(CHSDepthMarketDataField *pRspQryDepthMarketData, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�ʽ����
    virtual void OnRspFundTrans(CHSRspFundTransField *pRspFundTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:�ʽ������ˮ��ѯ
    virtual void OnRspQryFundTrans(CHSRspQryFundTransField *pRspQryFundTrans, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��ѯ�ͻ�֪ͨ
    virtual void OnRspQryClientNotice(CHSClientNoticeField *pRspQryClientNotice, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��Ȩ�����Ϣ��ѯ
    virtual void OnRspQryOptUnderly(CHSRspQryOptUnderlyField *pRspQryOptUnderly, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:֤ȯ�����ѯ
    virtual void OnRspQrySecuDepthMarket(CHSRspQrySecuDepthMarketField *pRspQrySecuDepthMarket, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��ʷ������ѯ
    virtual void OnRspQryHistOrder(CHSOrderField *pRspQryHistOrder, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��ʷ�ɽ���ѯ
    virtual void OnRspQryHistTrade(CHSTradeField *pRspQryHistTrade, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��ȡ�ʽ��ѯ
    virtual void OnRspQryWithdrawFund(CHSRspQryWithdrawFundField *pRspQryWithdrawFund, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:��Ϻ�Լ��ѯ
    virtual void OnRspQryCombInstrument(CHSRspQryCombInstrumentField *pRspQryCombInstrument, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

    /// Description:ϯλ��ѯ
    virtual void OnRspQrySeatID(CHSRspQrySeatIDField *pRspQrySeatID, CHSRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description:��Ȩ�ԶԳ�����
    virtual void OnRspOptionSelfClose(CHSRspOptionSelfCloseField *pReqOptionSelfClose, CHSRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description:��Ȩ�ԶԳ�����ȡ��
    virtual void OnRspOptionSelfCloseAction(CHSRspOptionSelfCloseActionField *pReqOptionSelfCloseAction, CHSRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description:��Ȩ�ԶԳ����ý����ѯ
    virtual void OnRspQryOptionSelfCloseResult(CHSRspQryOptionSelfCloseResultField *pReqQryOptionSelfCloseResult, CHSRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description:��Ȩ�ԶԳ��ѯ
    virtual void OnRspQryOptionSelfClose(CHSOptionSelfCloseField *pRspQryOptionSelfClose, CHSRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description:��Ʊ��Ȩ����¼��
    /// Others     :��Ʊ��Ȩ����¼�����˷������ص���pRspOptQuoteInsert����������ʱ����Ľṹ�����ݡ�
    virtual void OnRspErrorOptQuoteInsert(CHSRspOptQuoteInsertField *pRspOptQuoteInsert, CHSRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description:��Ʊ��Ȩ���۳���
    virtual void OnRspOptQuoteAction(CHSRspOptQuoteActionField *pRspOptQuoteAction, CHSRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description:��Ʊ��Ȩ���۲�ѯ
    virtual void OnRspQryOptQuote(CHSOptQuoteField *pRspQryOptQuote, CHSRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description:��Ʊ��Ȩ��ϲ�����Ϣ��ѯ
    virtual void OnRspQryOptCombStrategy(CHSRspQryOptCombStrategyField *pRspQryOptCombStrategy, CHSRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description: ����-�ɽ��ر�
    virtual void OnRtnTrade(CHSTradeField *pRtnTrade) {};

    /// Description: ����-�����ر�
    virtual void OnRtnOrder(CHSOrderField *pRtnOrder) {};

    /// Description: ����-��Ȩ
    virtual void OnRtnExercise(CHSExerciseField *pRtnExercise) {};

    /// Description: ����-�������
    virtual void OnRtnCombAction(CHSCombActionField *pRtnCombAction) {};

    /// Description: ����-����
    virtual void OnRtnLock(CHSLockField *pRtnLock) {};

    /// Description: ����-��������ر�
    virtual void OnErrRtnOrderAction(CHSOrderActionField *pRtnOrder) {};

    /// Description: ����-�ͻ�֪ͨ
    virtual void OnRtnClientNotice(CHSClientNoticeField *pRtnClientNotice) {};

    /// Description: ����-ѯ�ۻر�
    virtual void OnRtnForQuote(CHSForQuoteField* pRtnForQuote) {};

    /// Description: ����-���ۻر�
    virtual void OnRtnQuote(CHSQuoteField* pRtnQuote) {};

    /// Description: ����-������״̬
    virtual void OnRtnExchangeStatus(CHSExchangeStatusField* pRtnExchangeStatus) {};

    /// Description: ����-��ԼƷ��״̬
    virtual void OnRtnProductStatus(CHSProductStatusField* pRtnProductStatus) {};

    /// Description: ����-��Ȩ�ԶԳ�
    virtual void OnRtnOptionSelfClose(CHSOptionSelfCloseField *pRtnOptionSelfClose) {};

    /// Description: ����-��Ʊ��Ȩ���ۻر�
    virtual void OnRtnOptQuote(CHSOptQuoteField* pRtnOptQuote) {};

    /// Description: ����-����ת�˻ر�
    virtual void OnRtnTransfer(CHSTransferField* pRtnTransfer) {};

    /// Description: ����-��Ʊ��Ȩ���۳�������ر�
    virtual void OnErrRtnOptQuoteAction(CHSOptQuoteActionField* pRtnOptQuoteAction) {};
};

///����
class  CHSTradeApi
{
public:
    /// Description: ɾ���ӿڶ�����
    virtual void ReleaseApi() = 0;

    /// Description: ��ʼ������
    ///              pInitCfgField            ��ʼ�����
    ///              pExtraParam              ��ʼ���������
    virtual int Init(const CHSInitConfigField *pInitCfgField, void* pExtraParam = (void*)0) = 0;

    /// Description: API�ͽ��׹�̨�������ӣ����ӽ����ɹ������̻߳�ȴ��û��������߳��˳�
    /// Return     : int 0��ʾ���ӽ����ɹ��������ʾʧ�ܣ�ͨ������GetApiErrorMsg���Ի�ȡ��ϸ������Ϣ
    virtual int Join() = 0;

    /// Description: ע�ᶩ��ģʽ����δ֧�֣�
    /// Input      : ���ķ�ʽ
    ///               HS_TERT_RESTART://�ӱ������տ�ʼ�ش�
    ///               HS_TERT_RESUME: //���ϴ��յ�������
    ///               HS_TERT_QUICK:  //�ӵ�¼�����µĿ�ʼ��
    virtual int RegisterSubModel(SUB_TERT_TYPE eSubType) = 0;

    /// Description: ע��ǰ�û������ַ
    /// Input      : pszFrontAddress           ǰ�û������ַ �磺��tcp://127.0.0.1:17001��
    /// Return     : int 0��ʾ���óɹ��������ʾʧ�ܣ�ͨ������GetApiErrorMsg���Ի�ȡ��ϸ������Ϣ
    virtual int RegisterFront(const char *pszFrontAddress) = 0;

    /// Description: ע��Fens�����ַ
    /// Input      : pszFensAddress            Fens�����ַ
    /// Input      : pszAccountID              �˺�
    /// Return     : int 0��ʾ���óɹ��������ʾʧ�ܣ�ͨ������GetApiErrorMsg���Ի�ȡ��ϸ������Ϣ
    virtual int RegisterFensServer(const char *pszFensAddress, const char *pszAccountID) = 0;

    /// Description: ע��ص��ӿ�
    /// Input      : pSpi            �����Իص��ӿ����ʵ��     
    virtual void RegisterSpi(CHSTradeSpi *pSpi) = 0;

    /// Description: ��ô�����ϸ��Ϣ
    virtual const char* GetApiErrorMsg(int nErrorCode) = 0;

    /// Description: ��ȡ��ǰ��������
    virtual int GetTradingDate() = 0;

    /// Description: �󶨻Ự����
    virtual int BindSessionID(const uint8 nSessionID) = 0;

    /// Description: ������֤ 
    virtual int ReqAuthenticate(CHSReqAuthenticateField *pReqAuthenticate,int nRequestID) = 0;

    /// Description: �ն���Ϣ�ϱ��ӿ�(�м�ģʽ)
    virtual int ReqSubmitUserSystemInfo(CHSReqUserSystemInfoField *pReqUserSystemInfo,int nRequestID) = 0;

    /// Description:�ͻ���¼
    virtual int  ReqUserLogin(CHSReqUserLoginField *pReqUserLogin, int nRequestID) = 0;

    /// Description:�������
    virtual int  ReqUserPasswordUpdate(CHSReqUserPasswordUpdateField *pReqUserPasswordUpdate, int nRequestID) = 0;

    /// Description:����¼��
    virtual int  ReqOrderInsert(CHSReqOrderInsertField *pReqOrderInsert, int nRequestID) = 0;

    /// Description:����
    virtual int  ReqOrderAction(CHSReqOrderActionField *pReqOrderAction, int nRequestID) = 0;

    /// Description:��Ȩ¼��
    virtual int  ReqExerciseOrderInsert(CHSReqExerciseOrderInsertField *pReqExerciseOrderInsert, int nRequestID) = 0;

    /// Description:��Ȩ����
    virtual int  ReqExerciseOrderAction(CHSReqExerciseOrderActionField *pReqExerciseOrderAction, int nRequestID) = 0;

    /// Description:����¼��
    virtual int  ReqLockInsert(CHSReqLockInsertField *pReqLockInsert, int nRequestID) = 0;

    /// Description:ѯ��¼��
    virtual int  ReqForQuoteInsert(CHSReqForQuoteInsertField *pReqForQuoteInsert, int nRequestID) = 0;

    /// Description:����¼��
    virtual int  ReqQuoteInsert(CHSReqQuoteInsertField* pReqQuoteInsert, int nRequestID) = 0;

    /// Description:���۳���
    virtual int  ReqQuoteAction(CHSReqQuoteActionField* pReqQuoteAction, int nRequestID) = 0;

    /// Description:�������¼��
    virtual int  ReqCombActionInsert(CHSReqCombActionInsertField *pReqCombActionInsert, int nRequestID) = 0;

    /// Description:��󱨵�������ȡ
    virtual int  ReqQueryMaxOrderVolume(CHSReqQueryMaxOrderVolumeField *pReqQueryMaxOrderVolume, int nRequestID) = 0;

    /// Description:������������ȡ
    virtual int  ReqQryLockVolume(CHSReqQryLockVolumeField *pReqQryLockVolume, int nRequestID) = 0;

    /// Description:����Ȩ������ȡ
    virtual int  ReqQueryExerciseVolume(CHSReqQueryExerciseVolumeField *pReqQueryExerciseVolume, int nRequestID) = 0;

    /// Description:����������������ȡ
    virtual int  ReqQryCombVolume(CHSReqQryCombVolumeField *pReqQryCombVolume, int nRequestID) = 0;

    /// Description:�ֲֻ��ܲ�ѯ
    virtual int  ReqQryPosition(CHSReqQryPositionField *pReqQryPosition, int nRequestID) = 0;

    /// Description:�ʽ��˻���ѯ
    virtual int  ReqQryTradingAccount(CHSReqQryTradingAccountField *pReqQryTradingAccount, int nRequestID) = 0;

    /// Description:������ѯ
    virtual int  ReqQryOrder(CHSReqQryOrderField *pReqQryOrder, int nRequestID) = 0;

    /// Description:�ɽ���ѯ
    virtual int  ReqQryTrade(CHSReqQryTradeField *pReqQryTrade, int nRequestID) = 0;

    /// Description:��Ȩ��ѯ
    virtual int  ReqQryExercise(CHSReqQryExerciseField *pReqQryExercise, int nRequestID) = 0;

    /// Description:������ѯ
    virtual int  ReqQryLock(CHSReqQryLockField *pReqQryLock, int nRequestID) = 0;

    /// Description:������ϲ�ѯ
    virtual int  ReqQryCombAction(CHSReqQryCombActionField *pReqQryCombAction, int nRequestID) = 0;

    /// Description:ѯ�۲�ѯ
    virtual int  ReqQryForQuote(CHSReqQryForQuoteField* pReqQryForQuote, int nRequestID) = 0;

    /// Description:���۲�ѯ
    virtual int  ReqQryQuote(CHSReqQryQuoteField* pReqQryQuote, int nRequestID) = 0;

    /// Description:��ϳֲ���ϸ��ѯ
    virtual int  ReqQryPositionCombineDetail(CHSReqQryPositionCombineDetailField *pReqQryPositionCombineDetail, int nRequestID) = 0;

    /// Description:��Լ��Ϣ��ѯ
    virtual int  ReqQryInstrument(CHSReqQryInstrumentField *pReqQryInstrument, int nRequestID) = 0;

    /// Description:����ȱ�ڲ�ѯ
    virtual int  ReqQryCoveredShort(CHSReqQryCoveredShortField *pReqQryCoveredShort, int nRequestID) = 0;

    /// Description:��Ȩָ�ɲ�ѯ
    virtual int  ReqQryExerciseAssign(CHSReqQryExerciseAssignField *pReqQryExerciseAssign, int nRequestID) = 0;

    /// Description:����ת��
    virtual int  ReqTransfer(CHSReqTransferField *pReqTransfer, int nRequestID) = 0;

    /// Description:����ת�˲�ѯ
    virtual int  ReqQryTransfer(CHSReqQryTransferField *pReqQryTransfer, int nRequestID) = 0;

    /// Description:��������ѯ
    virtual int  ReqQueryBankBalance(CHSReqQueryBankBalanceField *pReqQueryBankBalance, int nRequestID) = 0;

    /// Description:�����˻���ѯ
    virtual int  ReqQueryBankAccount(CHSReqQueryBankAccountField *pReqQueryBankAccount, int nRequestID) = 0;

    /// Description:�������ʽ����
    virtual int  ReqMultiCentreFundTrans(CHSReqMultiCentreFundTransField *pReqMultiCentreFundTransfer, int nRequestID) = 0;

    /// Description:�ͻ��˵���ѯ
    virtual int  ReqQueryBillContent(CHSReqQueryBillContentField *pReqQueryBillContent, int nRequestID) = 0;

    /// Description:�ͻ��˵�ȷ��
    virtual int  ReqBillConfirm(CHSReqBillConfirmField *pReqBillConfirm, int nRequestID) = 0;

    /// Description:��֤���ѯ
    virtual int  ReqQryMargin(CHSReqQryMarginField *pReqQryMargin, int nRequestID) = 0;

    /// Description:�����Ѳ�ѯ
    virtual int  ReqQryCommission(CHSReqQryCommissionField *pReqQryCommission, int nRequestID) = 0;

    /// Description:���ʲ�ѯ
    virtual int  ReqQryExchangeRate(CHSReqQryExchangeRateField *pReqQryExchangeRate, int nRequestID) = 0;

    /// Description:�ֲ���ϸ��ѯ
    virtual int  ReqQryPositionDetail(CHSReqQryPositionDetailField *pReqQryPositionDetail, int nRequestID) = 0;

    /// Description:���͹�˾���ò�����ѯ
    virtual int  ReqQrySysConfig(CHSReqQrySysConfigField *pReqQrySysConfig, int nRequestID) = 0;

    /// Description:�����ѯ
    virtual int  ReqQryDepthMarketData(CHSReqQryDepthMarketDataField *pReqQryDepthMarketData, int nRequestID) = 0;

    /// Description:�ʽ����
    virtual int  ReqFundTrans(CHSReqFundTransField *pReqFundTransfer, int nRequestID) = 0;

    /// Description:�ʽ������ˮ��ѯ
    virtual int  ReqQryFundTrans(CHSReqQryFundTransField *pReqQryFundTrans, int nRequestID) = 0;

    /// Description:�ͻ�֪ͨ��ѯ
    virtual int  ReqQryClientNotice(CHSReqQryClientNoticeField *pReqQryClientNotice, int nRequestID) = 0;

    /// Description:��Ȩ�����Ϣ��ѯ
    virtual int  ReqQryOptUnderly(CHSReqQryOptUnderlyField *pReqQryOptUnderly, int nRequestID) = 0;

    /// Description:֤ȯ�����ѯ
    virtual int  ReqQrySecuDepthMarket(CHSReqQrySecuDepthMarketField *pReqQrySecuDepthMarket, int nRequestID) = 0;

    /// Description:��ʷ������ѯ
    virtual int  ReqQryHistOrder(CHSReqQryHistOrderField *pReqQryHistOrder, int nRequestID) = 0;

    /// Description:��ʷ�ɽ���ѯ
    virtual int  ReqQryHistTrade(CHSReqQryHistTradeField *pReqQryHistTrade, int nRequestID) = 0;

    /// Description:��ȡ�ʽ��ѯ
    virtual int  ReqQryWithdrawFund(CHSReqQryWithdrawFundField *pReqQryWithdrawFund, int nRequestID) = 0;

    /// Description:��Ϻ�Լ��ѯ
    virtual int  ReqQryCombInstrument(CHSReqQryCombInstrumentField *pReqQryCombInstrument, int nRequestID) = 0;

    /// Description:ϯλ��ѯ
    virtual int  ReqQrySeatID(CHSReqQrySeatIDField *pReqQrySeatID, int nRequestID) = 0;

    /// Description:��Ȩ�ԶԳ�����
    virtual int  ReqOptionSelfClose(CHSReqOptionSelfCloseField *pReqOptionSelfClose, int nRequestID) = 0;

    /// Description:��Ȩ�ԶԳ�����ȡ��
    virtual int  ReqOptionSelfCloseAction(CHSReqOptionSelfCloseActionField *pReqOptionSelfCloseAction, int nRequestID) = 0;

    /// Description:��Ȩ�ԶԳ����ý����ѯ
    virtual int  ReqQryOptionSelfCloseResult(CHSReqQryOptionSelfCloseResultField *pReqQryOptionSelfCloseResult, int nRequestID) = 0;

    /// Description:��Ȩ�ԶԳ��ѯ
    virtual int  ReqQryOptionSelfClose(CHSReqQryOptionSelfCloseField *pReqQryOptionSelfClose, int nRequestID) = 0;

    /// Description:��Ʊ��Ȩ����¼��
    virtual int  ReqOptQuoteInsert(CHSReqOptQuoteInsertField *pReqOptQuoteInsert, int nRequestID) = 0;

    /// Description:��Ʊ��Ȩ���۳���
    virtual int  ReqOptQuoteAction(CHSReqOptQuoteActionField *pReqOptQuoteAction, int nRequestID) = 0;

    /// Description:��Ʊ��Ȩ���۲�ѯ
    virtual int  ReqQryOptQuote(CHSReqQryOptQuoteField *pReqQryOptQuote, int nRequestID) = 0;

    /// Description:��Ʊ��Ȩ��ϲ�����Ϣ��ѯ
    virtual int  ReqQryOptCombStrategy(CHSReqQryOptCombStrategyField *pReqQryOptCombStrategy, int nRequestID) = 0;
protected:
    ~CHSTradeApi(){};
};

#ifdef __cplusplus
extern "C"
{
#endif
    /// Description: ��ȡAPI�汾��
    TRADE_API_EXPORT const char*  GetTradeApiVersion();

    /// Description: �������׽ӿ�    
    /// Input      : pszFlowPath    ��־·��   
    TRADE_API_EXPORT CHSTradeApi* NewTradeApi(const char *pszFlowPath);

#ifdef __cplusplus
}
#endif
#endif


