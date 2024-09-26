/**
* @author �ٺط�
* @company �������ӹɷ����޹�˾
* @file HSStruct.h
* @brief �����˽ӿ�ʹ�õ�ҵ�����ݽṹ
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
    /// API�ṹ��汾У��
    HSCheckVersion          APICheckVersion;
    /// ͨѶ֤��
    HSLicenseFile           CommLicense;
    /// ��ȫ����
    HSSafeLevel             SafeLevel;
    /// ͨѶ����
    HSLicensePassward       CommPassword;
    /// SSL�汾
    HSSslVersion            SslVersion;
    /// SSL֤��
    HSLicenseFile           CertLicense;
    /// SSL����
    HSLicensePassward       CertPassword;
    /// �������ã�֤��������û���(�ʽ��˺�)
    HSSksUser	            SksUser;
    /// �������ã�֤�����������(��������)
    HSSksPassword	        SksPassword;
    /// �������ã�֤�������pin����
    HSSksPin	            SksPin;
    /// �������ã�֤������̸�֤��У��
    HSSksCheckCertFlag      SksCheckCertFlag;
};

struct CHSRspInfoField
{
    /// �������
    HSErrorID                     ErrorID;
    /// ������ʾ
    HSErrorMsg                    ErrorMsg;
};

///������֤
struct CHSReqAuthenticateField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����
    HSPassword                    Password;
    /// �ͻ���id
    HSAppID                       AppID;
    /// ��֤��
    HSAuthCode                    AuthCode;
};

///������֤Ӧ��
struct CHSRspAuthenticateField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// �ͻ���ID
    HSAppID                       AppID;
    /// ��֤��
    HSAuthCode                    AuthCode;
    /// �ͻ���ID����
    HSAppIDType                   AppIDType;
};


///�û���Ϣ�ϱ�����
struct CHSReqUserSystemInfoField
{
    /// �ͻ��˵�½ʱ��
    HSStrTime                    AppLoginTime;
    /// �ͻ��˹�����ַ
    HSIPAddress                  AppPublicAdrr;
    /// �ͻ���ϵͳ��Ϣ
    HSAppSysInfo                 AppSysInfo;
    /// �ͻ���ϵͳ��Ϣ�ɼ�������
    HSAppSysInfoIntegrity        AppSysInfoIntegrity;
    /// �ͻ���ϵͳ��Ϣ�ɼ��쳣��ʶ
    HSAppAbnormalType            AppAbnormalType;
};

///�û���Ϣ�ϱ�Ӧ��
struct CHSRspUserSystemInfoField
{
};

///�ͻ���¼
struct CHSReqUserLoginField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����
    HSPassword                    Password;
    /// Ͷ���߶�Ӧ�����
    HSUserApplicationType         UserApplicationType;
    /// Ͷ���߶�Ӧ����Ϣ
    HSUserApplicationInfo         UserApplicationInfo;
    /// Ͷ����Mac��ַ
    HSMacAddress                  MacAddress;
    /// Ͷ����IP��ַ
    HSIPAddress                   IPAddress;
    /// Ͷ����վ����Ϣ
    HSUserStationInfo             UserStationInfo;
};
///�ͻ���¼Ӧ��
struct CHSRspUserLoginField
{
    /// Ӫҵ����
    HSNum                         BranchID;
    /// �˺�
    HSAccountID                   AccountID;
    /// Ͷ��������
    HSUserName                    UserName;
    /// ������
    HSDate                        TradingDay;
    /// �ϸ�������
    HSDate                        PreTradingDay;
    /// �˵�ȷ�ϱ�־
    HSBillConfirmFlag             BillConfirmFlag;
    /// �Ự����
    HSSessionID                   SessionID;
    /// Ͷ���߶�Ӧ�����
    HSUserApplicationType         UserApplicationType;
    /// Ͷ���߶�Ӧ����Ϣ
    HSUserApplicationInfo         UserApplicationInfo;
    /// ���յȼ�
    HSRiskLevel                   RiskLevel;
    /// Ͷ�����ϴε�½��Mac��ַ
    HSMacAddress                  LastMacAddress;
    /// Ͷ�����ϴε�½��IP��ַ
    HSIPAddress                   LastIPAddress;
    /// �ϴε�¼�ɹ�ʱ��
    HSTime                        LastLoginTime;
    /// ֣������ǰʱ��
    HSTime                        CZCETime;
    /// ��������ǰʱ��
    HSTime                        DCETime;
    /// ��������ǰʱ��
    HSTime                        SHFETime;
    /// �н�����ǰʱ��
    HSTime                        CFFEXTime;
    /// ��Դ���ĵ�ǰʱ��
    HSTime                        INETime;
    /// ��󱨵�����(���ػỰ�ϴ���󱨵�����)
    HSRef                         MaxOrderRef;
    /// �ͻ����
    HSUserID                      UserID;
    /// ��������ǰʱ��
    HSTime                        GFEXTime;
};

///�������
struct CHSReqUserPasswordUpdateField
{
    /// ��������
    HSPasswordType                PasswordType;
    /// ����
    HSPassword                    Password;
    /// ������
    HSPassword                    NewPassword;
};
///�������Ӧ��
struct CHSRspUserPasswordUpdateField
{
};

///����¼��
struct CHSReqOrderInsertField
{
    /// ��������
    HSRef                         OrderRef;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��������
    HSDirection                   Direction;
    /// ��ƽ��־
    HSOffsetFlag                  OffsetFlag;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// �����۸�
    HSPrice                       OrderPrice;
    /// ��������
    HSVolume                      OrderVolume;
    /// ����ָ��
    HSOrderCommand                OrderCommand;
    /// ��С�ɽ���
    HSVolume                      MinVolume;
    /// ֹ��ֹӯ��
    HSPrice                       SpringPrice;
    /// ������־
    HSSwapOrderFlag               SwapOrderFlag;
    /// ��ϳֱֲ���
    HSCombPositionID              CombPositionID;
    /// ���ױ���
    HSExchangeAccountID           ExchangeAccountID;
    /// ϯλ����
    HSSeatIndex                   SeatIndex;
};
///����¼��Ӧ��
struct CHSRspOrderInsertField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ��������
    HSOrderSysID                  OrderSysID;
    /// ���͹�˾��������
    HSBrokerOrderID               BrokerOrderID;
    /// �Ự����
    HSSessionID                   SessionID;
    /// ��������
    HSRef                         OrderRef;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��������
    HSDirection                   Direction;
    /// ��ƽ��־
    HSOffsetFlag                  OffsetFlag;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// �����۸�
    HSPrice                       OrderPrice;
    /// ��������
    HSVolume                      OrderVolume;
    /// ����״̬
    HSOrderStatus                 OrderStatus;
    /// ����ָ��
    HSOrderCommand                OrderCommand;
    /// ����ʱ��
    HSTime                        InsertTime;
    /// ��С�ɽ���
    HSVolume                      MinVolume;
    /// ֹ��ֹӯ��
    HSPrice                       SpringPrice;
    /// ������־
    HSSwapOrderFlag               SwapOrderFlag;
    /// ��ϳֱֲ���
    HSCombPositionID              CombPositionID;
    /// ���ױ���
    HSExchangeAccountID           ExchangeAccountID;
    /// ϯλ����
    HSSeatIndex                   SeatIndex;
};

///����
struct CHSReqOrderActionField
{
    /// ��������
    HSOrderSysID                  OrderSysID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// �Ự����
    HSSessionID                   SessionID;
    /// ��������
    HSRef                         OrderRef;
    /// ������������
    HSRef                         OrderActionRef;
};
///����Ӧ��
struct CHSRspOrderActionField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ��������
    HSOrderSysID                  OrderSysID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// �Ự����
    HSSessionID                   SessionID;
    /// ��������
    HSRef                         OrderRef;
    /// ����״̬
    HSOrderStatus                 OrderStatus;
    /// ����ʱ��
    HSTime                        InsertTime;
    /// ������������
    HSRef                         OrderActionRef;
};

///��Ȩ¼��
struct CHSReqExerciseOrderInsertField
{
    /// ��Ȩ����
    HSRef                         ExerciseRef;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��������
    HSVolume                      OrderVolume;
    /// ��Ȩ��ʽ
    HSExerciseType                ExerciseType;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// ��ƽ��־
    HSOffsetFlag                  OffsetFlag;
    /// ��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
    HSCloseFlag                   CloseFlag;
};
///��Ȩ¼��Ӧ��
struct CHSRspExerciseOrderInsertField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// �Ự����
    HSSessionID                   SessionID;
    /// ��Ȩ��������
    HSOrderSysID                  ExerciseOrderSysID;
    /// ��Ȩ����
    HSRef                         ExerciseRef;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��������
    HSVolume                      OrderVolume;
    /// ��Ȩ��ʽ
    HSExerciseType                ExerciseType;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// ����״̬
    HSOrderStatus                 OrderStatus;
    /// ����ʱ��
    HSTime                        InsertTime;
    /// ��ƽ��־
    HSOffsetFlag                  OffsetFlag;
    /// ��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
    HSCloseFlag                   CloseFlag;
    /// ���͹�˾��Ȩ��������
    HSBrokerOrderID               ExerciseBrokerOrderID;
};

///��Ȩ����
struct CHSReqExerciseOrderActionField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ȩ��������
    HSOrderSysID                  ExerciseOrderSysID;
    /// ��Ȩ����
    HSRef                         ExerciseRef;
    /// �Ự����
    HSSessionID                   SessionID;
    /// ��Ȩ��������
    HSRef                         ExecOrderActionRef;
};
///��Ȩ����Ӧ��
struct CHSRspExerciseOrderActionField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ȩ��������
    HSOrderSysID                  ExerciseOrderSysID;
    /// ��Ȩ����
    HSRef                         ExerciseRef;
    /// �Ự����
    HSSessionID                   SessionID;
    /// ����״̬
    HSOrderStatus                 OrderStatus;
    /// ��Ȩ��������
    HSRef                         ExecOrderActionRef;
};

///����¼��
struct CHSReqLockInsertField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ��������
    HSLockType                    LockType;
    /// ��������
    HSVolume                      OrderVolume;
    /// ��������
    HSRef                         LockRef;
};
///����¼��Ӧ��
struct CHSRspLockInsertField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ������������
    HSOrderSysID                  LockOrderSysID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ��������
    HSLockType                    LockType;
    /// ��������
    HSVolume                      OrderVolume;
    /// ����ｻ���˺�
    HSAccountID                   UnderlyingAccountID;
    /// ����״̬
    HSOrderStatus                 OrderStatus;
    /// ����ʱ��
    HSTime                        InsertTime;
    /// ��������
    HSRef                         LockRef;
};

///ѯ��¼��
struct CHSReqForQuoteInsertField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
};
///ѯ��¼��Ӧ��
struct CHSRspForQuoteInsertField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ����״̬
    HSOrderStatus                 OrderStatus;
};

///����¼��
struct CHSReqQuoteInsertField
{
    /// �������
    HSExchangeID                   ExchangeID;
    /// ��Լ����
    HSInstrumentID                 InstrumentID;
    /// �򷽿�ƽ����
    HSOffsetFlag                   BidOffsetFlag;
    /// ���ױ���־
    HSHedgeType                    BidHedgeType;
    /// �򷽱��ۼ۸�
    HSPrice                        BidOrderPrice;
    /// �򷽱�������
    HSVolume                       BidOrderVolume;
    /// �򷽱�������
    HSRef                          BidOrderRef;
    /// ������ƽ����
    HSOffsetFlag                   AskOffsetFlag;
    /// �����ױ���־
    HSHedgeType                    AskHedgeType;
    /// �������ۼ۸�
    HSPrice                        AskOrderPrice;
    /// ������������
    HSVolume                       AskOrderVolume;
    /// ����ί������
    HSRef                          AskOrderRef;
    /// ѯ�۱�������
    HSOrderSysID                   ForQuoteSysID;
    /// ����ί������
    HSRef                          QuoteRef;
    /// ��������
    HSTopOrderType                 TopOrderType;
    /// ���۱�������
    HSOrderSysID                   QuoteSysID;    
};
///����¼��Ӧ��
struct CHSRspQuoteInsertField
{
    /// �˺�
    HSAccountID                    AccountID;
    /// �������
    HSExchangeID                   ExchangeID;
    /// ��Լ����
    HSInstrumentID                 InstrumentID;
    /// �򷽿�ƽ����
    HSOffsetFlag                   BidOffsetFlag;
    /// ���ױ���־
    HSHedgeType                    BidHedgeType;
    /// �򷽱��ۼ۸�
    HSPrice                        BidOrderPrice;
    /// �򷽱�������
    HSVolume                       BidOrderVolume;
    /// ��ί������
    HSRef                          BidOrderRef;
    /// ������ƽ����
    HSOffsetFlag                   AskOffsetFlag;
    /// �����ױ���־
    HSHedgeType                    AskHedgeType;
    /// �������ۼ۸�
    HSPrice                        AskOrderPrice;
    /// ������������
    HSVolume                       AskOrderVolume;
    /// ����ί������
    HSRef                          AskOrderRef;
    /// ѯ�۱�������
    HSOrderSysID                   ForQuoteSysID;
    /// ����ί������
    HSRef                          QuoteRef;
    /// ���۱��
    HSBrokerOrderID                QuoteBrokerID;
    /// �򷽱�������
    HSOrderSysID                   BidOrderSysID;
    /// ������������
    HSOrderSysID                   AskOrderSysID;
    /// �Ự���
    HSSessionID                    SessionID;
    /// ����ʱ��
    HSTime                         InsertTime;
    /// ����״̬
    HSOrderStatus                  OrderStatus;
    /// ��������
    HSTopOrderType                 TopOrderType;
    /// ���۱�������
    HSOrderSysID                   QuoteSysID;
};

///���۳���
struct CHSReqQuoteActionField
{
    /// ���۱�������
    HSOrderSysID                   QuoteSysID;
    /// �������
    HSExchangeID                   ExchangeID;
    /// �Ự���
    HSSessionID                    SessionID;
    /// ����ί������
    HSRef                          QuoteRef;
    /// ���۲�������
    HSRef                          QuoteActionRef;
    /// ��Լ����
    HSInstrumentID                 InstrumentID;
};

///���۳���Ӧ��
struct CHSRspQuoteActionField
{
    /// �˺�
    HSAccountID                    AccountID;
    /// ���۱�������
    HSOrderSysID                   QuoteSysID;
    /// �������
    HSExchangeID                   ExchangeID;
    /// �Ự���
    HSSessionID                    SessionID;
    /// ����ί������
    HSRef                          QuoteRef;
    /// ���۲�������
    HSRef                          QuoteActionRef;
    /// ����״̬
    HSOrderStatus                  OrderStatus;
    /// ����ʱ��
    HSTime                         InsertTime;
    /// ��Լ����
    HSInstrumentID                 InstrumentID;
};

///�������¼��
struct CHSReqCombActionInsertField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��ϲ��Ա���
    HSCombStrategyID              CombStrategyID;
    /// ��ϳֱֲ���
    HSCombPositionID              CombPositionID;
    /// ���ָ���
    HSCombDirection               CombDirection;
    /// ��������
    HSVolume                      OrderVolume;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// ��������
    HSDirection                   Direction;
    /// �ڶ���Ͷ��/�ױ�/��������
    HSHedgeType                   SecondHedgeType;
    /// ��ϱ�������
    HSRef                         CombOrderRef;
};
///�������¼��Ӧ��
struct CHSRspCombActionInsertField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ��ϱ�������
    HSOrderSysID                  CombOrderSysID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��ϲ��Ա���
    HSCombStrategyID              CombStrategyID;
    /// ��ϳֱֲ���
    HSCombPositionID              CombPositionID;
    /// ���ָ���
    HSCombDirection               CombDirection;
    /// ��������
    HSVolume                      OrderVolume;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// ����״̬
    HSOrderStatus                 OrderStatus;
    /// ����ʱ��
    HSTime                        InsertTime;
    /// ��������
    HSDirection                   Direction;
    /// �ڶ���Ͷ��/�ױ�/��������
    HSHedgeType                   SecondHedgeType;
    /// ��ϱ�������
    HSRef                         CombOrderRef;
};

///��󱨵�������ȡ
struct CHSReqQueryMaxOrderVolumeField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ����ָ��
    HSOrderCommand                OrderCommand;
    /// ��������
    HSDirection                   Direction;
    /// ��ƽ��־
    HSOffsetFlag                  OffsetFlag;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// �����۸�
    HSPrice                       OrderPrice;
    /// ��ϳֱֲ���
    HSCombPositionID              CombPositionID;
};
///��󱨵�������ȡӦ��
struct CHSRspQueryMaxOrderVolumeField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ��󱨵���
    HSVolume                      MaxOrderVolume;
    /// ������󱨵���
    HSVolume                      MaxOrderVolumeUnit;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ����ָ��
    HSOrderCommand                OrderCommand;
    /// ��������
    HSDirection                   Direction;
    /// ��ƽ��־
    HSOffsetFlag                  OffsetFlag;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// �����۸�
    HSPrice                       OrderPrice;
    /// ��ϳֱֲ���
    HSCombPositionID              CombPositionID;
    /// ��ʾ��Ϣ
    HSErrorMsg                    ErrorMsg;
};

///������������ȡ
struct CHSReqQryLockVolumeField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ��������
    HSLockType                    LockType;
};
///������������ȡӦ��
struct CHSRspQryLockVolumeField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ��������
    HSLockType                    LockType;
    /// ���óֲ�����
    HSVolume                      AvailablePositionVolume;
};

///����Ȩ������ȡ
struct CHSReqQueryExerciseVolumeField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
};
///����Ȩ������ȡӦ��
struct CHSRspQueryExerciseVolumeField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ��󱨵���
    HSVolume                      MaxOrderVolumeUnit;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
};

///����������������ȡ
struct CHSReqQryCombVolumeField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��ϲ��Ա���
    HSCombStrategyID              CombStrategyID;
    /// ��ϳֱֲ���
    HSCombPositionID              CombPositionID;
    /// ���ָ���
    HSCombDirection               CombDirection;
};
///����������������ȡӦ��
struct CHSRspQryCombVolumeField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��ϲ��Ա���
    HSCombStrategyID              CombStrategyID;
    /// ��ϳֱֲ���
    HSCombPositionID              CombPositionID;
    /// ���ָ���
    HSCombDirection               CombDirection;
    /// ������󱨵���
    HSVolume                      MaxOrderVolumeUnit;
};

///�ֲֻ��ܲ�ѯ
struct CHSReqQryPositionField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
};
///�ֲֻ��ܲ�ѯӦ��
struct CHSRspQryPositionField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��������
    HSDirection                   Direction;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// ���ճֲ�����
    HSVolume                      YdPositionVolume;
    /// �ֲ�����
    HSVolume                      PositionVolume;
    /// ���ճֲ�����
    HSVolume                      TodayPositionVolume;
    /// ���óֲ�����
    HSVolume                      AvailablePositionVolume;
    /// ���տ��óֲ�����
    HSVolume                      TodayAvailablePositionVolume;
    /// �ֱֲ�֤��
    HSBalance                     PositionMargin;
    /// Ȩ����
    HSBalance                     Premium;
    /// ������
    HSBalance                     Commission;
    /// ���ֶ�������
    HSVolume                      OpenFrozenVolume;
    /// ƽ�ֶ�������
    HSVolume                      CloseFrozenVolume;
    /// �������
    HSVolume                      CombVolume;
    /// ��Ȩ��������
    HSVolume                      ExerciseFrozenVolume;
    /// ���ᱣ֤��
    HSBalance                     FrozenMargin;
    /// ��Ȩ���ᱣ֤��
    HSBalance                     ExerciseFrozenMargin;
    /// ����Ȩ����
    HSBalance                     FrozenPremium;
    /// ����������
    HSBalance                     FrozenCommission;
    /// ������
    HSVolume                      OpenVolume;
    /// ƽ����
    HSVolume                      CloseVolume;
    /// ���ֽ��
    HSBalance                     OpenBalance;
    /// ƽ�ֽ��
    HSBalance                     CloseBalance;
    /// ���ֳɱ�
    HSBalance                     OpenCost;
    /// �ֲֳɱ�
    HSBalance                     PositionCost;
    /// �ֲ�ӯ��
    HSBalance                     PositionProfit;
    /// ƽ��ӯ��
    HSBalance                     CloseProfit;
    /// ��Ȩ��ֵ
    HSBalance                     OptionsMarketValue;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// TAS�ֲ�����
    HSVolume                      TASPositionVolume;
};

///�ʽ��˻���ѯ
struct CHSReqQryTradingAccountField
{
};
///�ʽ��˻���ѯӦ��
struct CHSRspQryTradingAccountField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// �������
    HSBalance                     YdBalance;
    /// ���ճֱֲ�֤��
    HSBalance                     YdPositionMargin;
    /// �����ʽ�Ȩ��
    HSBalance                     YdFundEquity;
    /// �ʽ�Ȩ��
    HSBalance                     FundEquity;
    /// ��Ȩ��ֵ
    HSBalance                     OptionsMarketValue;
    /// ��Ȩ��
    HSBalance                     Equity;
    /// �����ʽ�
    HSBalance                     AvailableBalance;
    /// ��ȡ�ʽ�
    HSBalance                     WithdrawBalance;
    /// ��֤��
    HSBalance                     Margin;
    /// ���ᱣ֤��
    HSBalance                     FrozenMargin;
    /// ��Ȩ���ᱣ֤��
    HSBalance                     ExerciseFrozenMargin;
    /// ���ն�
    HSRiskDegree                  RiskDegree;
    /// Ȩ����
    HSBalance                     Premium;
    /// ����Ȩ����
    HSBalance                     FrozenPremium;
    /// ������
    HSBalance                     Commission;
    /// ����������
    HSBalance                     FrozenCommission;
    /// ƽ��ӯ��
    HSBalance                     CloseProfit;
    /// �ֲ�ӯ��
    HSBalance                     PositionProfit;
    /// ƽ�ֶ���ӯ��
    HSBalance                     CloseProfitByDate;
    /// �ֲֶ���ӯ��
    HSBalance                     PositionProfitByDate;
    /// ת����
    HSBalance                     Deposit;
    /// ת�����
    HSBalance                     Withdraw;
    /// ������Ѻ���
    HSBalance                     FundMortgage;
    /// �ֵ���Ѻ���
    HSBalance                     WarrantMortgage;
    /// �����ʽ�
    HSBalance                     FrozenBalance;
    /// �ⶳ�ʽ�
    HSBalance                     UnFrozenBalance;
    /// ����
    HSCurrencyID                  CurrencyID;
    /// �Գ���ն�
    HSRiskDegree                  HedgeRiskDegree;
    /// �Ϻ������޹����
    HSBalance                     ShUsedBuyQuota;
    /// ���������޹����
    HSBalance                     SzUsedBuyQuota;
    /// �Ϻ������޹����
    HSBalance                     ShAvailableBuyQuota;
    /// ���ڿ����޹����
    HSBalance                     SzAvailableBuyQuota;
    /// ���ղֵ���Ѻ���
    HSBalance                     YdWarrantMortgage;
};

///������ѯ
struct CHSReqQryOrderField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��������
    HSOrderSysID                  OrderSysID;
    /// ���ױ���
    HSExchangeAccountID           ExchangeAccountID;
};

///��ʷ������ѯ
struct CHSReqQryHistOrderField
{
    /// ����������
    HSExchangeID                   ExchangeID;
    /// ��Լ����
    HSInstrumentID                 InstrumentID;
    /// ��������
    HSOrderSysID                   OrderSysID;
    /// ��ʼ����
    HSDate                         BeginDate;
    /// ��������
    HSDate                         EndDate;
    /// ���ױ���
    HSExchangeAccountID            ExchangeAccountID;
};

///������Ϣ
struct CHSOrderField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ��������
    HSOrderSysID                  OrderSysID;
    /// ���͹�˾��������
    HSBrokerOrderID               BrokerOrderID;
    /// �Ự����
    HSSessionID                   SessionID;
    /// ��������
    HSRef                         OrderRef;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��������
    HSDirection                   Direction;
    /// ��ƽ��־
    HSOffsetFlag                  OffsetFlag;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// �����۸�
    HSPrice                       OrderPrice;
    /// ��������
    HSVolume                      OrderVolume;
    /// ����״̬
    HSOrderStatus                 OrderStatus;
    /// �ɽ�����
    HSVolume                      TradeVolume;
    /// ��������
    HSVolume                      CancelVolume;
    /// �ɽ��۸�
    HSPrice                       TradePrice;
    /// ������
    HSDate                        TradingDay;
    /// ��������
    HSDate                        InsertDate;
    /// ����ʱ��
    HSTime                        InsertTime;
    /// �걨ʱ��
    HSTime                        ReportTime;
    /// ����ָ��
    HSOrderCommand                OrderCommand;
    /// ��С�ɽ���
    HSVolume                      MinVolume;
    /// ֹ��ֹӯ��
    HSPrice                       SpringPrice;
    /// ������־
    HSSwapOrderFlag               SwapOrderFlag;
    /// ǿƽԭ��
    HSForceCloseReason            ForceCloseReason;
    /// ������Ϣ
    HSErrorMsg                    ErrorMsg;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ��������
    HSOrderSource                 OrderSource;
    /// ��ϳֱֲ���
    HSCombPositionID              CombPositionID;
    /// ���ױ���
    HSExchangeAccountID           ExchangeAccountID;
    /// ϯλ����
    HSSeatIndex                   SeatIndex;
};

///�ɽ���ѯ
struct CHSReqQryTradeField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ���ױ���
    HSExchangeAccountID           ExchangeAccountID;
};

///��ʷ�ɽ���ѯ
struct CHSReqQryHistTradeField
{
    /// ����������
    HSExchangeID                   ExchangeID;
    /// ��Լ����
    HSInstrumentID                 InstrumentID;
    /// ��ʼ����
    HSDate                         BeginDate;
    /// ��������
    HSDate                         EndDate;
    /// ���ױ���
    HSExchangeAccountID            ExchangeAccountID;
};

///�ɽ���Ϣ
struct CHSTradeField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// �ɽ�����
    HSTradeID                     TradeID;
    /// ��������
    HSOrderSysID                  OrderSysID;
    /// ���͹�˾��������
    HSBrokerOrderID               BrokerOrderID;
    /// �Ự����
    HSSessionID                   SessionID;
    /// ��������
    HSRef                         OrderRef;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��������
    HSDirection                   Direction;
    /// ��ƽ��־
    HSOffsetFlag                  OffsetFlag;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// �ɽ�����
    HSVolume                      TradeVolume;
    /// �ɽ��۸�
    HSPrice                       TradePrice;
    /// ������
    HSDate                        TradingDay;
    /// �ɽ�ʱ��
    HSTime                        TradeTime;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ��ϳֱֲ���
    HSCombPositionID              CombPositionID;
    /// �ɽ�������
    HSBalance                     TradeCommission;
    /// ���ױ���
    HSExchangeAccountID           ExchangeAccountID;
};

///��Ȩ��ѯ
struct CHSReqQryExerciseField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��Ȩ��������
    HSOrderSysID                  ExerciseOrderSysID;
};

///��ʷ��Ȩ��ѯ
struct CHSReqQryHistExerciseField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��Ȩ��������
    HSOrderSysID                  ExerciseOrderSysID;
    /// ��ʼ����
    HSDate                        BeginDate;
    /// ��������
    HSDate                        EndDate;
};

///��Ȩ��Ϣ
struct CHSExerciseField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ��Ȩ��������
    HSOrderSysID                  ExerciseOrderSysID;
    /// �Ự����
    HSSessionID                   SessionID;
    /// ��Ȩ����
    HSRef                         ExerciseRef;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// ��Ȩ��ʽ
    HSExerciseType                ExerciseType;
    /// ��Ȩ����
    HSVolume                      OrderVolume;
    /// ����״̬
    HSOrderStatus                 OrderStatus;
    /// ��������
    HSDate                        InsertDate;
    /// ����ʱ��
    HSTime                        InsertTime;
    /// ������Ϣ
    HSErrorMsg                    ErrorMsg;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ��������
    HSOrderSource                 OrderSource;
    /// ��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
    HSCloseFlag                   CloseFlag;
    /// ��ƽ��־
    HSOffsetFlag                  OffsetFlag;
    /// ��ȨԤ����������
    HSBalance                     ExercisePreFrozenCommission;
    /// ��ȨԤ���ᱣ֤��
    HSBalance                     ExercisePreFrozenMargin;
    /// ���͹�˾��Ȩ��������
    HSBrokerOrderID               ExerciseBrokerOrderID;
    /// ���ױ���
    HSExchangeAccountID           ExchangeAccountID;
};

///������ѯ
struct CHSReqQryLockField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ������������
    HSOrderSysID                  LockOrderSysID;
};

///��ʷ������ѯ
struct CHSReqQryHistLockField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ������������
    HSOrderSysID                  LockOrderSysID;
    /// ��ʼ����
    HSDate                        BeginDate;
    /// ��������
    HSDate                        EndDate;
};

///������Ϣ
struct CHSLockField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ������������
    HSOrderSysID                  LockOrderSysID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ��������
    HSLockType                    LockType;
    /// ��������
    HSVolume                      OrderVolume;
    /// ����״̬
    HSOrderStatus                 OrderStatus;
    /// ������
    HSDate                        TradingDay;
    /// ����ʱ��
    HSTime                        InsertTime;
    /// ������Ϣ
    HSErrorMsg                    ErrorMsg;
    /// ��������
    HSOrderSource                 OrderSource;
    /// ��������
    HSRef                         LockRef;
    /// �Ự����
    HSSessionID                   SessionID;
};

///������ϲ�ѯ
struct CHSReqQryCombActionField
{
    /// ��ϱ�������
    HSOrderSysID                  CombOrderSysID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
};

///��ʷ������ϲ�ѯ
struct CHSReqQryHistCombActionField
{
    /// ��ϱ�������
    HSOrderSysID                  CombOrderSysID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��ʼ����
    HSDate                        BeginDate;
    /// ��������
    HSDate                        EndDate;
};

///���������Ϣ
struct CHSCombActionField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ��ϱ�������
    HSOrderSysID                  CombOrderSysID;
    /// ��ϳֱֲ���
    HSCombPositionID              CombPositionID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��ϲ��Ա���
    HSCombStrategyID              CombStrategyID;
    /// ��������
    HSDirection                   Direction;
    /// ���ָ���
    HSCombDirection               CombDirection;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// ��������
    HSVolume                      OrderVolume;
    /// ����״̬
    HSOrderStatus                 OrderStatus;
    /// ������
    HSDate                        TradingDay;
    /// ��������
    HSDate                        InsertDate;
    /// ����ʱ��
    HSTime                        InsertTime;
    /// ������Ϣ
    HSErrorMsg                    ErrorMsg;
    /// ��������
    HSOrderSource                 OrderSource;
    /// �ڶ���Ͷ��/�ױ�/��������
    HSHedgeType                   SecondHedgeType;
    /// ��ϱ�������
    HSRef                         CombOrderRef;
    /// �Ự����
    HSSessionID                   SessionID;
};

///ѯ�۶��ģ�����ȡ������
struct CHSReqForQuoteField
{
    HSExchangeID                  ExchangeID;
    HSInstrumentID                InstrumentID;
};

///ѯ�۲�ѯ
struct CHSReqQryForQuoteField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ѯ�۱�������
    HSOrderSysID                  ForQuoteSysID;
};

///ѯ����Ϣ
struct CHSForQuoteField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ѯ�۱�������
    HSOrderSysID                  ForQuoteSysID;
    /// ������
    HSDate                        TradingDay;
    /// ������ʱ��
    HSTime                        UpdateTime;
};

///���۲�ѯ
struct CHSReqQryQuoteField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ���۱�������
    HSOrderSysID                  QuoteSysID;
    /// ���۱��
    HSBrokerOrderID               QuoteBrokerID;
};

///������Ϣ
struct CHSQuoteField
{
    /// �˺�
    HSAccountID                    AccountID;
    /// �������
    HSExchangeID                   ExchangeID;
    /// ��Լ����
    HSInstrumentID                 InstrumentID;
    /// ���۱��
    HSBrokerOrderID                QuoteBrokerID;
    /// ����״̬
    HSOrderStatus                  OrderStatus;
    /// �򷽿�ƽ����
    HSOffsetFlag                   BidOffsetFlag;
    /// ���ױ���־
    HSHedgeType                    BidHedgeType;
    /// �򷽱��ۼ۸�
    HSPrice                        BidOrderPrice;
    /// �򷽱�������
    HSVolume                       BidOrderVolume;
    /// ������ƽ����
    HSOffsetFlag                   AskOffsetFlag;
    /// �����ױ���־
    HSHedgeType                    AskHedgeType;
    /// �������ۼ۸�
    HSPrice                        AskOrderPrice;
    /// ������������
    HSVolume                       AskOrderVolume;
    /// ����ί������
    HSRef                          QuoteRef;
    /// ѯ�۱�������
    HSOrderSysID                   ForQuoteSysID;
    /// ��ʾ��Ϣ
    HSErrorMsg                     ErrorMsg;
    /// ���۱�������
    HSOrderSysID                   QuoteSysID;
    /// �򷽱�������
    HSOrderSysID                   BidOrderSysID;
    /// ������������
    HSOrderSysID                   AskOrderSysID;
    /// ��ί�б��
    HSBrokerOrderID                BidBrokerOrderID;
    /// ����ί�б��
    HSBrokerOrderID                AskBrokerOrderID;
    /// ��ί������
    HSRef                          BidOrderRef;
    /// ����ί������
    HSRef                          AskOrderRef;
    /// �Ự���
    HSSessionID                    SessionID;
    /// ������
    HSDate                         TradingDay;
    /// ��������
    HSDate                         InsertDate;
    /// ����ʱ��
    HSTime                         InsertTime;
    /// �걨ʱ��
    HSTime                         ReportTime;
    /// ��������
    HSTopOrderType                 TopOrderType;
};


///��ϳֲ���ϸ��ѯ
struct CHSReqQryPositionCombineDetailField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��ϲ��Ա���
    HSCombStrategyID              CombStrategyID;
};
///��ϳֲ���ϸ��ѯӦ��
struct CHSRspQryPositionCombineDetailField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ��ϳֱֲ���
    HSCombPositionID              CombPositionID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��ϲ��Ա���
    HSCombStrategyID              CombStrategyID;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// ��������
    HSDirection                   Direction;
    /// ���ճֲ�����
    HSVolume                      YdPositionVolume;
    /// ���óֲ�����
    HSVolume                      AvailablePositionVolume;
    /// ��ϻ�������
    HSVolume                      TotalCombVolume;
    /// ��ֻ�������
    HSVolume                      TotalSplitVolume;
    /// �ֱֲ�֤��
    HSBalance                     PositionMargin;
    /// ��������
    HSDate                        OpenDate;
    /// �ڶ���Ͷ��/�ױ�/��������
    HSHedgeType                   SecondHedgeType;
};

///��Լ��Ϣ��ѯ
struct CHSReqQryInstrumentField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
};
///��Լ��Ϣ��ѯӦ��
struct CHSRspQryInstrumentField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��Լ����
    HSInstrumentName              InstrumentName;
    /// ��ԼӢ������
    HSInstrumentEngName           InstrumentEngName;
    /// ��ԼƷ�ֱ���
    HSProductID                   ProductID;
    /// ��Ʒ����
    HSProductType                 ProductType;
    /// �м۵���󱨵���
    HSVolume                      MaxMarketOrderVolume;
    /// �м۵���С������
    HSVolume                      MinMarketOrderVolume;
    /// �޼۵���󱨵���
    HSVolume                      MaxLimitOrderVolume;
    /// �޼۵���С������
    HSVolume                      MinLimitOrderVolume;
    /// ��Լ��������
    HSVolume                      VolumeMultiple;
    /// ��С�䶯��λ
    HSPrice                       PriceTick;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ��Ȩ��
    HSPrice                       ExercisePrice;
    /// ��Ȩ����
    HSOptionsType                 OptionsType;
    /// ���ױ�־
    HSTradingFlag                 TradingFlag;
    /// ������
    HSDate                        MarketDate;
    /// ������
    HSDate                        ExpireDate;
    /// ��Ȩ��ʼ����
    HSDate                        BeginExerciseDate;
    /// ��Ȩ��������
    HSDate                        EndExerciseDate;
    /// ��ʼ������
    HSDate                        BeginDeliveryDate;
    /// ����������
    HSDate                        EndDeliveryDate;
    /// ����
    HSCurrencyID                  CurrencyID;
    /// �������
    HSCombType                    CombType;
};

///����ȱ�ڲ�ѯ
struct CHSReqQryCoveredShortField
{
    /// ����������
    HSExchangeID                  ExchangeID;
};
///����ȱ�ڲ�ѯӦ��
struct CHSRspQryCoveredShortField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ������������
    HSVolume                      CoveredLockVolume;
    /// ����ȱ������
    HSVolume                      CoveredShortVolume;
    /// ����Ԥ��ȱ������
    HSVolume                      CoveredEstimateShortVolume;
    /// ��Ϣ����
    HSMsgContent                  MsgContent;
};

///��Ȩָ�ɲ�ѯ
struct CHSReqQryExerciseAssignField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// �ֲ�����
    HSPositionType                PositionType;
};
///��Ȩָ�ɲ�ѯӦ��
struct CHSRspQryExerciseAssignField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// �ֲ�����
    HSPositionType                PositionType;
    /// ��Ȩ����
    HSOptionsType                 OptionsType;
    /// ��Ȩ��
    HSPrice                       ExercisePrice;
    /// ��Ȩ����
    HSVolume                      ExerciseVolume;
    /// ��������
    HSVolume                      DeliveryVolume;
    /// ��Ȩ�����ʽ�
    HSBalance                     ExerciseFrozenBalance;
    /// ������
    HSBalance                     SettlementBalance;
};

///����ת��
struct CHSReqTransferField
{
    /// ���д���
    HSBankID                      BankID;
    /// ת������
    HSTransferType                TransferType;
    /// �������
    HSBalance                     OccurBalance;
    /// �ʽ�����
    HSPassword                    FundPassword;
    /// ��������
    HSPassword                    BankPassword;
    /// ����
    HSCurrencyID                  CurrencyID;
    /// ת�˳���
    HSOccasion                    TransferOccasion;
};
///����ת��Ӧ��
struct CHSRspTransferField
{
    /// ת����ˮ
    HSNum                         TransferSerialID;
    /// ���д���
    HSBankID                      BankID;
    /// ת������
    HSTransferType                TransferType;
    /// �������
    HSBalance                     OccurBalance;
    /// ����
    HSCurrencyID                  CurrencyID;
    /// ת�˳���
    HSOccasion                    TransferOccasion;
};

///����ת�˲�ѯ
struct CHSReqQryTransferField
{
    /// ���д���
    HSBankID                      BankID;
    /// ת����ˮ
    HSNum                         TransferSerialID;
};
///����ת�˲�ѯӦ��
struct CHSRspQryTransferField
{
    /// ת����ˮ
    HSNum                         TransferSerialID;
    /// ���д���
    HSBankID                      BankID;
    /// ��������
    HSBankName                    BankName;
    /// ҵ������
    HSBusinessName                BusinessName;
    /// �������
    HSBalance                     OccurBalance;
    /// ���ʽ��
    HSBalance                     PostBalance;
    /// ת��ʱ��
    HSTime                        TransferTime;
    /// ת��״̬
    HSTransferStatus              TransferStatus;
    /// ת�˷���
    HSTransferSource              TransferSource;
    /// ��ע
    HSRemarks                     Remarks;
    /// ����
    HSCurrencyID                  CurrencyID;
    /// ���׷�������
    HSDate                        OrderSourceDate;
    /// ��������
    HSDate                        TradingDay;
    /// ת�˳���
    HSOccasion                    TransferOccasion;
};

///��������ѯ
struct CHSReqQueryBankBalanceField
{
    /// ���д���
    HSBankID                      BankID;
    /// �ʽ�����
    HSPassword                    FundPassword;
    /// ��������
    HSPassword                    BankPassword;
    /// ����
    HSCurrencyID                  CurrencyID;
};
///��������ѯӦ��
struct CHSRspQueryBankBalanceField
{
    /// ת����ˮ
    HSNum                         TransferSerialID;
};

///�����˻���ѯ
struct CHSReqQueryBankAccountField
{
    /// ���д���
    HSBankID                      BankID;
    /// ����
    HSCurrencyID                  CurrencyID;
};
///�����˻���ѯӦ��
struct CHSRspQueryBankAccountField
{
    /// ���д���
    HSBankID                      BankID;
    /// ��������
    HSBankName                    BankName;
    /// �����˺�
    HSBankAccountID               BankAccountID;
    /// ����
    HSCurrencyID                  CurrencyID;
};

///�������ʽ����
struct CHSReqMultiCentreFundTransField
{
    /// ����
    HSCurrencyID                  CurrencyID;
    /// �������
    HSBalance                     OccurBalance;
    /// ��������
    HSTransDirection              TransDirection;
};
///�������ʽ����Ӧ��
struct CHSRspMultiCentreFundTransField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����
    HSCurrencyID                  CurrencyID;
    /// �������
    HSBalance                     OccurBalance;
    /// ��������
    HSTransDirection              TransDirection;
    /// ���������ʽ������ˮ��
    HSNum                         LocalTransferSerialID;
    /// �Զ������ʽ������ˮ��
    HSNum                         OppositeTransferSerialID;
};

///�ͻ��˵���ѯ
struct CHSReqQueryBillContentField
{
    /// ��ʼ����
    HSDate                        BeginDate;
    /// ��������
    HSDate                        EndDate;
};
///�ͻ��˵���ѯӦ��
struct CHSRspQueryBillContentField
{
    /// �˵�����
    HSBillContent                 BillContent;
};

///�ͻ��˵�ȷ��
struct CHSReqBillConfirmField
{
};
///�ͻ��˵�ȷ��Ӧ��
struct CHSRspBillConfirmField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// �˵�ȷ��״̬
    HSBillConfirmStatus           BillConfirmStatus;
    /// ȷ������
    HSDate                        ConfirmDate;
    /// ȷ��ʱ��
    HSTime                        ConfirmTime;
};

///��֤���ѯ
struct CHSReqQryMarginField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
};
///��֤���ѯӦ��
struct CHSRspQryMarginField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// ��ͷ��֤����
    HSRate                        LongMarginRatio;
    /// ��ͷ��֤��
    HSBalance                     LongMargin;
    /// ��ͷ��֤����
    HSRate                        ShortMarginRatio;
    /// ��ͷ��֤��
    HSBalance                     ShortMargin;
};

///�����Ѳ�ѯ
struct CHSReqQryCommissionField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ʒ����
    HSProductType                 ProductType;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
};
///�����Ѳ�ѯӦ��
struct CHSRspQryCommissionField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ʒ����
    HSProductType                 ProductType;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ��ͷ������������
    HSRate                        LongOpenCommissionRatio;
    /// ��ͷ����������
    HSBalance                     LongOpenCommission;
    /// ��ͷƽ����������
    HSRate                        LongCloseCommissionRatio;
    /// ��ͷƽ��������
    HSBalance                     LongCloseCommission;
    /// ��ͷƽ����������
    HSRate                        LongCloseTodayCommissionRatio;
    /// ��ͷƽ��������
    HSBalance                     LongCloseTodayCommission;
    /// ��ͷ������������
    HSRate                        ShortOpenCommissionRatio;
    /// ��ͷ����������
    HSBalance                     ShortOpenCommission;
    /// ��ͷƽ����������
    HSRate                        ShortCloseCommissionRatio;
    /// ��ͷƽ��������
    HSBalance                     ShortCloseCommission;
    /// ��ͷƽ����������
    HSRate                        ShortCloseTodayCommissionRatio;
    /// ��ͷƽ��������
    HSBalance                     ShortCloseTodayCommission;
    /// ��Ȩ��������
    HSRate                        ExerciseCommissionRatio;
    /// ��Ȩ������
    HSBalance                     ExerciseCommission;
    /// �ɽ���ֵ����
    HSRate                        TradeValueRatio;
    /// ��Ʊ��ֵ
    HSBalance                     StockValue;
};

///���ʲ�ѯ
struct CHSReqQryExchangeRateField
{
    /// ԭ����
    HSCurrencyID                  FromCurrencyID;
    /// Ŀ�����
    HSCurrencyID                  ToCurrencyID;
};
///���ʲ�ѯӦ��
struct CHSRspQryExchangeRateField
{
    /// ԭ����
    HSCurrencyID                  FromCurrencyID;
    /// Ŀ�����
    HSCurrencyID                  ToCurrencyID;
    /// ����
    HSExchangeRate                ExchangeRate;
    /// ԭ����������λ
    HSVolume                      FromCurrencyUnit;
};

///�ֲ���ϸ��ѯ
struct CHSReqQryPositionDetailField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
};
///�ֲ���ϸ��ѯӦ��
struct CHSRspQryPositionDetailField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// �ɽ�����
    HSTradeID                     TradeID;
    /// ��������
    HSDate                        OpenDate;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��������
    HSDirection                   Direction;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// �ɽ�����
    HSVolume                      TradeVolume;
    /// �ֲּ۸�
    HSPrice                       PositionPrice;
    /// ����ƽ������
    HSVolume                      TodayCloseVolume;
    /// �����ֲֺ�
    HSArbitPositionID             ArbitragePositionID;
    /// �Ⱥ�
    HSLegID                       LegID;
    /// �ɽ�����
    HSTradeType                   TradeType;
    /// �ֱֲ�֤��
    HSBalance                     PositionMargin;
    /// ��Ϻ�Լ����
    HSInstrumentID                CombInstrumentID;
    /// ��ǰ�ֲ�����
    HSVolume                      CurrentPositionVolume;
    /// �����
    HSPrice                       SettlementPrice;
    /// �ֲ���ˮ��
    HSNum                         PositionSerialID;
};

///���͹�˾���ò�����ѯ
struct CHSReqQrySysConfigField
{
};
///���͹�˾���ò�����ѯӦ��
struct CHSRspQrySysConfigField
{
    /// ���ñ��
    HSConfigNo                    ConfigNo;
    /// ���ÿ���״̬
    HSConfigValue                 ConfigValue;
};

///���鶩�ģ�ȡ����������
struct CHSReqDepthMarketDataField
{
    HSExchangeID                  ExchangeID;
    HSInstrumentID                InstrumentID;
};

///�����ѯ
struct CHSReqQryDepthMarketDataField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
};

///������Ϣ
struct CHSDepthMarketDataField
{
    /// ������
    HSDate                        TradingDay;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ���¼�
    HSPrice                       LastPrice;
    /// ������
    HSPrice                       PreSettlementPrice;
    /// �����̼�
    HSPrice                       PreClosePrice;
    /// ���̼�
    HSPrice                       OpenPrice;
    /// ��߼�
    HSPrice                       HighestPrice;
    /// ��ͼ�
    HSPrice                       LowestPrice;
    /// �ɽ�����
    HSVolume                      TradeVolume;
    /// �ɽ����
    HSBalance                     TradeBalance;
    /// �ܳ���
    HSVolume                      OpenInterest;
    /// ���̼�
    HSPrice                       ClosePrice;
    /// �����
    HSPrice                       SettlementPrice;
    /// ��ͣ���
    HSPrice                       UpperLimitPrice;
    /// ��ͣ���
    HSPrice                       LowerLimitPrice;
    /// ����ʵ��
    HSDelta                       PreDelta;
    /// ����ʵ��
    HSDelta                       CurrDelta;
    /// ������ʱ��
    HSTime                        UpdateTime;
    /// �����һ
    HSPrice                       BidPrice1;
    /// ������һ
    HSVolume                      BidVolume1;
    /// ������һ
    HSPrice                       AskPrice1;
    /// ������һ
    HSVolume                      AskVolume1;
    /// ����۶�
    HSPrice                       BidPrice2;
    /// ��������
    HSVolume                      BidVolume2;
    /// �����۶�
    HSPrice                       AskPrice2;
    /// ��������
    HSVolume                      AskVolume2;
    /// �������
    HSPrice                       BidPrice3;
    /// ��������
    HSVolume                      BidVolume3;
    /// ��������
    HSPrice                       AskPrice3;
    /// ��������
    HSVolume                      AskVolume3;
    /// �������
    HSPrice                       BidPrice4;
    /// ��������
    HSVolume                      BidVolume4;
    /// ��������
    HSPrice                       AskPrice4;
    /// ��������
    HSVolume                      AskVolume4;
    /// �������
    HSPrice                       BidPrice5;
    /// ��������
    HSVolume                      BidVolume5;
    /// ��������
    HSPrice                       AskPrice5;
    /// ��������
    HSVolume                      AskVolume5;
    /// ƽ���۸�
    HSPrice                       AveragePrice;
    /// ��ֲ���
    HSVolume                      PreOpenInterest;
    /// ��Լ����״̬
    HSInstrumentTradeStatus       InstrumentTradeStatus;
    /// ��Լʵʱ��������
    HSOpenRestriction             OpenRestriction;
    /// ����ݶ�ο���ֵ
    HSPrice                       IOPV;
    /// ��̬�ο��۸�
    HSPrice                       AuctionPrice;
    /// ���鷢��ʱ��
    HSTime                        SendingTime;
};

///������Ϣ
struct CHSOrderActionField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ��������
    HSOrderSysID                  OrderSysID;
    /// ���͹�˾��������
    HSBrokerOrderID               BrokerOrderID;
    /// �Ự����
    HSSessionID                   SessionID;
    /// ��������
    HSRef                         OrderRef;
    /// ��������
    HSRef                         OrderActionRef;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��������
    HSDirection                   Direction;
    /// ��ƽ��־
    HSOffsetFlag                  OffsetFlag;
    /// Ͷ��/�ױ�/��������
    HSHedgeType                   HedgeType;
    /// �����۸�
    HSPrice                       OrderPrice;
    /// ��������
    HSVolume                      OrderVolume;
    /// ����״̬
    HSOrderStatus                 OrderActionStatus;
    /// ����״̬
    HSOrderStatus                 OrderStatus;
    /// ������
    HSDate                        TradingDay;
    /// ��������
    HSDate                        ActionDate;
    /// ����ʱ��
    HSTime                        ActionTime;
    /// ������Ϣ
    HSErrorMsg                    ErrorMsg;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ��������
    HSOrderSource                 OrderSource;
};

///���ٽ����뼯�н���֮���ʽ��������
struct CHSReqFundTransField
{
    /// ��������
    HSTransDirection              TransDirection;
    /// ����
    HSCurrencyID                  CurrencyID;
    /// �������
    HSBalance                     OccurBalance;
};

///���ٽ����뼯�н���֮���ʽ����Ӧ��
struct CHSRspFundTransField
{
    /// �ʽ������ˮ
    HSNum                         FundTransSerialID;
};

///�ʽ������ˮ��ѯ����
struct CHSReqQryFundTransField
{

};

///�ʽ������ˮ��ѯӦ��
struct CHSRspQryFundTransField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ��������
    HSDate                        TradingDay;
    /// ��������
    HSDate                        OccurDate;
    /// ����ʱ��
    HSTime                        OccurTime;
    /// ת����ˮ
    HSNum                         TransferSerialID;
    /// ����
    HSCurrencyID                  CurrencyID;
    /// �������
    HSBalance                     OccurBalance;
    /// ���ʽ��
    HSBalance                     PostBalance;
};

///�ͻ�֪ͨ��ѯ
struct CHSReqQryClientNoticeField
{

};

///�ͻ�֪ͨ��Ϣ
struct CHSClientNoticeField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ��Ϣ����
    HSMsgBody                     MsgBody;
    /// ��Ϣ����
    HSMsgTitle                    MsgTitle;
    /// ��Ϣ����
    HSMsgType                     MsgType;
    /// ��Ϣ����
    HSDate                        MsgDate;
    /// ��Ϣʱ��
    HSTime                        MsgTime;
};

///��Ȩ�����Ϣ��ѯ
struct CHSReqQryOptUnderlyField
{
    /// ����������
    HSExchangeID                   ExchangeID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                 UnderlyingInstrID;
};

///��Ȩ�����Ϣ��ѯӦ��
struct CHSRspQryOptUnderlyField
{
    /// ����������
    HSExchangeID                   ExchangeID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                 UnderlyingInstrID;
    /// ��Ȩ��Ӧ���������
    HSStockType                    UnderlyingType;
    /// ����
    HSCurrencyID                   CurrencyID;
    /// ��Ȩ��Ӧ�����״̬
    HSStatus                       UnderlyingStatus;
    /// ��ͣ���
    HSPrice                        UpperLimitPrice;
    /// ��ͣ���
    HSPrice                        LowerLimitPrice;
    /// ��Ȩ��Ӧ��Ľ����������
    HSVolume                       UnderlyingHighAmount;
    /// ��Ȩ��Ӧ��Ľ����������
    HSVolume                       UnderlyingLowAmount;
    /// ��Լ��������
    HSVolume                       VolumeMultiple;
    /// ���뵥λ
    HSNum                          BuyUnit;
    /// ������λ
    HSNum                          SellUnit;
    /// ��С�۲�(��)
    HSNum                          PriceStep;
    /// ������
    HSDate                         MarketDate;
    /// ��������
    HSDate                         DelistDate;
    /// ��Ȩ��Ӧ����м۽����������
    HSVolume                       UnderlyingMarketHighAmount;
    /// ��Ȩ��Ӧ����м۽����������
    HSVolume                       UnderlyingMarketLowAmount;
    /// ���������
    HSInstrumentName               UnderlyingName;
    /// �м����뵥λ
    HSNum                          MarketBuyUnit;
    /// �м�������λ
    HSNum                          MarketSellUnit;
    /// ��Ȩ��Ӧ�������Ч����
    HSDate                         UnderlyingValidDate;
    /// ��������
    HSNum                          UpdateType;
};

///֤ȯ�����ѯ
struct CHSReqQrySecuDepthMarketField
{
    /// ����������
    HSExchangeID                   ExchangeID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                 UnderlyingInstrID;
};

///֤ȯ�����ѯӦ��
struct CHSRspQrySecuDepthMarketField
{
    /// ����������
    HSExchangeID                   ExchangeID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                 UnderlyingInstrID;
    /// ���������
    HSInstrumentName               UnderlyingName;
    /// ���¼�
    HSPrice                        LastPrice;
    /// ���̼�
    HSPrice                        OpenPrice;
    /// ����������̼�
    HSPrice                        UnderlyingPreClosePrice;
    /// ��߼�
    HSPrice                        HighestPrice;
    /// ��ͼ�
    HSPrice                        LowestPrice;
    /// �ɽ����
    HSBalance                      TradeBalance;
    /// �ɽ�����
    HSVolume                       TradeVolume;
    /// �����һ
    HSPrice                        BidPrice1;
    /// ������һ
    HSVolume                       BidVolume1;
    /// ������һ
    HSPrice                        AskPrice1;
    /// ������һ
    HSVolume                       AskVolume1;
    /// ����۶�
    HSPrice                        BidPrice2;
    /// ��������
    HSVolume                       BidVolume2;
    /// �����۶�
    HSPrice                        AskPrice2;
    /// ��������
    HSVolume                       AskVolume2;
    /// �������
    HSPrice                        BidPrice3;
    /// ��������
    HSVolume                       BidVolume3;
    /// ��������
    HSPrice                        AskPrice3;
    /// ��������
    HSVolume                       AskVolume3;
    /// �������
    HSPrice                        BidPrice4;
    /// ��������
    HSVolume                       BidVolume4;
    /// ��������
    HSPrice                        AskPrice4;
    /// ��������
    HSVolume                       AskVolume4;
    /// �������
    HSPrice                        BidPrice5;
    /// ��������
    HSVolume                       BidVolume5;
    /// ��������
    HSPrice                        AskPrice5;
    /// ��������
    HSVolume                       AskVolume5;
};

///������״̬��Ϣ
struct CHSExchangeStatusField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ������״̬
    HSExchangeStatus              ExchangeStatus;
    /// �걨��־
    HSTradingFlag                 TradingFlag;
};

///��ԼƷ��״̬��Ϣ
struct CHSProductStatusField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Ʒ����
    HSProductType                 ProductType;
    /// ��ԼƷ�ִ���
    HSProductID                   ProductID;
    /// �걨��־
    HSTradingFlag                 TradingFlag;
    /// ��ԼƷ�ֽ���״̬
    HSExchangeStatus              ProductStatus;
};

///��ȡ�ʽ��ѯ����
struct CHSReqQryWithdrawFundField
{
    /// �������
    HSCurrencyID                  CurrencyID;
    /// ϵͳ�ڵ��
    HSSysnodeID                   SysNodeID;
};

///��ȡ�ʽ��ѯӦ��
struct CHSRspQryWithdrawFundField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// �������
    HSCurrencyID                  CurrencyID;
    /// ϵͳ�ڵ��
    HSSysnodeID                   SysNodeID;
    /// ϵͳ�ڵ�����
    HSSysnodeName                 SysNodeName;
    /// ��ȡ�ʽ�
    HSBalance                     WithdrawBalance;
};

///��Ϻ�Լ��ѯ
struct CHSReqQryCombInstrumentField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
};

///��Ϻ�Լ��ѯӦ��
struct CHSRspQryCombInstrumentField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��������
    HSDirection                   Direction;
    /// �ڶ�����������
    HSDirection                   SecondDirection;
    /// ��ϲ�������
    HSCombStrategyType            CombStrategyType;
    /// ��ϱ�֤��ϵ��
    HSVolume                      CombMarginCoeff;
    /// ���ȼ�
    HSVolume                      PriorityLevel;
};

///ϯλ��ѯ����
struct CHSReqQrySeatIDField
{
    /// �������
    HSExchangeID                  ExchangeID;
};

///ϯλ��ѯӦ��
struct CHSRspQrySeatIDField
{
    /// �������
    HSExchangeID                  ExchangeID;
    /// ϯλ����
    HSSeatIndex                   SeatIndex;
    /// ϯλ��
    HSSeatID                      SeatID;
};

///��Ȩ�Գ���������
struct CHSReqOptionSelfCloseField
{
    /// ����������
    HSExchangeID	              ExchangeID;
    /// ��Լ����
    HSInstrumentID	              InstrumentID;
    /// ��������
    HSVolume	                  OrderVolume;
    /// �Գ�����
    HSSelfCloseType	              SelfCloseType;
};

///��Ȩ�Գ�����Ӧ��
struct CHSRspOptionSelfCloseField
{
    /// �ʽ��˺�
    HSAccountID	                  AccountID;
    /// ����������
    HSExchangeID	              ExchangeID;
    /// ��Լ����
    HSInstrumentID	              InstrumentID;
    /// ��������
    HSVolume	                  OrderVolume;
    /// �Գ�����
    HSSelfCloseType	              SelfCloseType;
};

///��Ȩ�Գ�����ȡ������
struct CHSReqOptionSelfCloseActionField
{
    /// ����������
    HSExchangeID	              ExchangeID;
    /// ��Լ����
    HSInstrumentID	              InstrumentID;
    /// �Գ�����
    HSSelfCloseType	              SelfCloseType;
};

///��Ȩ�Գ�����ȡ��Ӧ��
struct CHSRspOptionSelfCloseActionField
{
    /// �ʽ��˺�
    HSAccountID	                  AccountID;
    /// ����������
    HSExchangeID	              ExchangeID;
    /// ��Լ����
    HSInstrumentID	              InstrumentID;
    /// �Գ�����
    HSSelfCloseType	              SelfCloseType;
};

///��ѯ��Ȩ�ԶԳ�����
struct CHSReqQryOptionSelfCloseField
{
    /// ����������
    HSExchangeID	              ExchangeID;
    /// ��Լ����
    HSInstrumentID	              InstrumentID;
};

///��Ȩ�ԶԳ���Ϣ
struct CHSOptionSelfCloseField
{
    /// �ʽ��˺�
    HSAccountID	                  AccountID;
    /// ����������
    HSExchangeID	              ExchangeID;
    /// ��Լ����
    HSInstrumentID	              InstrumentID;
    /// ��������
    HSVolume	                  OrderVolume;
    /// �Գ�����
    HSSelfCloseType	              SelfCloseType;
    /// ����״̬
    HSOrderStatus	              OrderStatus;
    /// �Գ����ò�������
    HSSetSelfCloseType	          SetSelfCloseType;
    /// ������Ϣ
    HSErrorMsg	                  ErrorMsg;
    /// ��������
    HSOrderSysID	              SelfCloseOrderSysID;
};

///��Ȩ�Գ����ý����ѯ����
struct CHSReqQryOptionSelfCloseResultField
{
    /// ����������
    HSExchangeID	              ExchangeID;
    /// ��Լ����
    HSInstrumentID	              InstrumentID;
};

///��Ȩ�Գ����ý����ѯӦ��
struct CHSRspQryOptionSelfCloseResultField
{
    /// �ʽ��˺�
    HSAccountID	                  AccountID;
    /// ����������
    HSExchangeID	              ExchangeID;
    /// ��Լ����
    HSInstrumentID	              InstrumentID;
    /// �Գ�����
    HSSelfCloseType	              SelfCloseType;
    /// ��������
    HSVolume	                  OrderVolume;
};

///����ת����Ϣ
struct CHSTransferField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ת����ˮ
    HSNum                         TransferSerialID;
    /// ���д���
    HSBankID                      BankID;
    /// ��������
    HSBankName                    BankName;
    /// ҵ������
    HSBusinessName                BusinessName;
    /// �������
    HSBalance                     OccurBalance;
    /// ���ʽ��
    HSBalance                     PostBalance;
    /// ת��ʱ��
    HSTime                        TransferTime;
    /// ת��״̬
    HSTransferStatus              TransferStatus;
    /// ת�˷���
    HSTransferSource              TransferSource;
    /// ��ע
    HSRemarks                     Remarks;
    /// ����
    HSCurrencyID                  CurrencyID;
    /// ���׷�������
    HSDate                        OrderSourceDate;
    /// ��������
    HSDate                        TradingDay;
    /// ת�˳���
    HSOccasion                    TransferOccasion;
};

/// ����֤����Ϣ
struct CHSSMCertInfoField
{
    /// ֤���ʶ
    HSCertID	                  CertID;
    /// ����Ա�˺�
    HSAccountID	                  OperatorID;
    /// �豸��ʶ
    HSDeviceID	                  DeviceID;
    /// ֤����Ϣ
    HSCertInfo	                  CertInfo;
    /// SKSpin����
    HSSksPin	                  SksPin;
    /// �Ƿ�ǰ���豸��ʶ
    HSIsCurrent                   IsCurrent;
};

///��Ʊ��Ȩ����¼��
struct CHSReqOptQuoteInsertField
{
    /// �������
    HSExchangeID                   ExchangeID;
    /// ��Լ����
    HSInstrumentID                 InstrumentID;
    /// �򷽿�ƽ����
    HSOffsetFlag                   BidOffsetFlag;
    /// �򷽱��ۼ۸�
    HSPrice                        BidOrderPrice;
    /// �򷽱�������
    HSVolume                       BidOrderVolume;
    /// ������ƽ����
    HSOffsetFlag                   AskOffsetFlag;
    /// �������ۼ۸�
    HSPrice                        AskOrderPrice;
    /// ������������
    HSVolume                       AskOrderVolume;	
    /// ����ί������
    HSRef                          QuoteRef;
	/// ѯ����������
    HSOrderSysID                   ForQuoteSysID;
};

///��Ʊ��Ȩ����¼��Ӧ��
struct CHSRspOptQuoteInsertField
{
    /// �˺�
    HSAccountID                    AccountID;
    /// �������
    HSExchangeID                   ExchangeID;
    /// ��Լ����
    HSInstrumentID                 InstrumentID;
    /// �򷽿�ƽ����
    HSOffsetFlag                   BidOffsetFlag;
    /// �򷽱��ۼ۸�
    HSPrice                        BidOrderPrice;
    /// �򷽱�������
    HSVolume                       BidOrderVolume;
    /// ������ƽ����
    HSOffsetFlag                   AskOffsetFlag;
    /// �������ۼ۸�
    HSPrice                        AskOrderPrice;
    /// ������������
    HSVolume                       AskOrderVolume;
    /// ���۱��
    HSBrokerOrderID                QuoteBrokerID;
    /// ����ʱ��
    HSTime                         InsertTime;
    /// �򷽱���״̬
    HSOrderStatus                  BidOrderStatus;
    /// ��������״̬
    HSOrderStatus                  AskOrderStatus;
    /// ����ί������
    HSRef                          QuoteRef;
	/// ѯ����������
    HSOrderSysID                   ForQuoteSysID;
	/// ����״̬
    HSOrderStatus       	       OrderStatus;
    /// �Ự���
    HSSessionID                    SessionID;
};

///��Ʊ��Ȩ���۳���
struct CHSReqOptQuoteActionField
{
    /// �������
    HSExchangeID                   ExchangeID;
    /// ��Լ����
    HSInstrumentID                 InstrumentID;
    /// �򷽱��۳�������
    HSVolume                       BidWithdrawVolume;
    /// �������۳�������
    HSVolume                       AskWithdrawVolume;
    /// ���۳���ί������
    HSRef                          QuoteActionRef;
};

///��Ʊ��Ȩ���۳���Ӧ��
struct CHSRspOptQuoteActionField
{
    /// �˺�
    HSAccountID                    AccountID;
    /// �������
    HSExchangeID                   ExchangeID;
    /// ��Լ����
    HSInstrumentID                 InstrumentID;
    /// ����ʱ��
    HSTime                         InsertTime;
    /// ���۱��
    HSBrokerOrderID                QuoteBrokerID;
    /// �򷽱��۳�������
    HSVolume                       BidWithdrawVolume;
    /// �������۳�������
    HSVolume                       AskWithdrawVolume;
    /// �򱨵�״̬
    HSOrderStatus                  BidOrderStatus;
    /// ������״̬
    HSOrderStatus                  AskOrderStatus;
    /// ���۳���ί������
    HSRef                          QuoteActionRef;
	/// ����״̬
    HSOrderStatus       	       OrderStatus;
    /// �Ự���
    HSSessionID                    SessionID;
};

///��Ʊ��Ȩ���۲�ѯ
struct CHSReqQryOptQuoteField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ��ѯģʽ
    HSType                        QuoteQueryType;
    /// ���۱��
    HSBrokerOrderID               QuoteBrokerID;
};

///��Ʊ��Ȩ������Ϣ
struct CHSOptQuoteField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ���۱��
    HSBrokerOrderID               QuoteBrokerID;
    /// �򷽿�ƽ����
    HSOffsetFlag                  BidOffsetFlag;
    /// �򷽱��ۼ۸�
    HSPrice                       BidOrderPrice;
    /// �򷽱�������
    HSVolume                      BidOrderVolume;
    /// �򷽳ɽ��۸�
    HSPrice                       BidTradePrice;
    /// �򷽳ɽ�����
    HSVolume                      BidTradeVolume;
    /// �򷽳�������
    HSVolume                      BidCancelVolume;
    /// ��ί�б��
    HSBrokerOrderID               BidBrokerOrderID;
    /// �򷽱���״̬
    HSOrderStatus                 BidOrderStatus;
    /// ������ƽ����
    HSOffsetFlag                  AskOffsetFlag;
    /// �������ۼ۸�
    HSPrice                       AskOrderPrice;
    /// ������������
    HSVolume                      AskOrderVolume;
    /// �����ɽ��۸�
    HSPrice                       AskTradePrice;
    /// �����ɽ�����
    HSVolume                      AskTradeVolume;
    /// ������������
    HSVolume                      AskCancelVolume;
    /// ����ί�б��
    HSBrokerOrderID               AskBrokerOrderID;
    /// ��������״̬
    HSOrderStatus                 AskOrderStatus;
    /// ��ʾ��Ϣ
    HSErrorMsg                    ErrorMsg;
    /// ������
    HSDate                        TradingDay;
    /// ��������
    HSDate                        InsertDate;
    /// ����ʱ��
    HSTime                        InsertTime;
    /// �걨ʱ��
    HSTime                        ReportTime;
    /// �Ự���
    HSSessionID                   SessionID;
    /// ��Ȩ��Ӧ�ı�ĺ�Լ����
    HSInstrumentID                UnderlyingInstrID;
    /// ����ί������
    HSRef                          QuoteRef;
    /// ѯ�۱�������
    HSOrderSysID                   ForQuoteSysID;
    /// ����״̬
    HSOrderStatus                  OrderStatus;
};

//��Ʊ��Ȩ���۳�����Ϣ
struct CHSOptQuoteActionField
{
    /// �˺�
    HSAccountID                   AccountID;
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��Լ����
    HSInstrumentID                InstrumentID;
    /// ������
    HSDate                        TradingDay;
    /// ��������
    HSDate                        InsertDate;
    /// ����ʱ��
    HSTime                        InsertTime;
    /// �걨ʱ��
    HSTime                        ReportTime;
    /// �Ự���
    HSSessionID                   SessionID;
    /// ���۳���ί������
    HSRef                         QuoteActionRef;
    /// ��ʾ��Ϣ
    HSErrorMsg                    ErrorMsg;
};

//��Ʊ��Ȩ��ϲ�����Ϣ��ѯ����
struct CHSReqQryOptCombStrategyField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��ϲ��Ա���
    HSCombStrategyID              CombStrategyID;
};

//��Ʊ��Ȩ��ϲ�����Ϣ��ѯӦ��
struct CHSRspQryOptCombStrategyField
{
    /// ����������
    HSExchangeID                  ExchangeID;
    /// ��ϲ��Ա���
    HSCombStrategyID              CombStrategyID;
    /// ��ϲ�������
    HSCombStrategyName            CombStrategyName;
    /// �������Ƿ���ͬ
    HSFlag                        EndDateSameFlag;
    /// ���֤ȯ�Ƿ���ͬ
    HSFlag                        UnderlySameFlag;
    /// ��Լ��λ�Ƿ���ͬ
    HSFlag                        UnitSameFlag;
    /// �ɷֺ�Լ����
    HSNum                         ComponentNum;
    /// ��һ�Ⱥ�Լ����
    HSOptionsType                 FirstOptionsType;
    /// ��һ�Ⱥ�Լ�ֲ�����
    HSPositionType                FirstPositionType;
    /// ��һ�Ⱥ�Լ��Ȩ�۸�˳��
    HSNum                         FirstExercisePriceSeq;
    /// ÿ�ݵ�һ�Ⱥ�Լ����
    HSNum                         FirstPerInstrumentAmount;
    /// �ڶ��Ⱥ�Լ����
    HSOptionsType                 SecondOptionsType;
    /// �ڶ��Ⱥ�Լ�ֲ�����
    HSPositionType                SecondPositionType;
    /// �ڶ��Ⱥ�Լ��Ȩ�۸�˳��
    HSNum                         SecondExercisePriceSeq;
    /// ÿ�ݵڶ��Ⱥ�Լ����
    HSNum                         SecondPerInstrumentAmount;
    /// ��ϵ�����ǰ�������
    HSNum                         NearSplitDays;
    /// �Ƿ�ʹ�÷Ǳ��Լ
    HSFlag                        NonStandardInstrumentFlag;
};

#pragma pack(pop)
#endif
