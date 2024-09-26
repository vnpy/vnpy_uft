#ifndef __HSSMCERTSDK_H
#define __HSSMCERTSDK_H
#include <stdlib.h>

#ifdef _WIN32
    #define SM_CERT_EXPORT
#else
    #ifdef HSTRADEAPI_EXPORTS
        #define SM_CERT_EXPORT __attribute__((visibility("default"))) 
    #else
        #define SM_CERT_EXPORT
    #endif
#endif

/* Эͬǩ�����ö��� */
struct HSGMCertUserConfig
{
    char  UserAccount[32];          /* �û���Account */
    char  UserPin[32];              /* �û��ı���PIN�� */
    char  UserPassword[32];         /* �û������룬�����û���֤У�� */
    char  ServerIP[64];             /* Эͬǩ����������ַ */
    char  Version[16];              /* ���ܳ���  ���:gergmssl  �Ű�:xasjgmssl ����ָ��*/
};

/* ֤����Ϣ */
struct HSSMCert
{
    char CertID[50];      /* ֤��Ψһ��ʶ�����ֶ�Ϊ�Զ����Ψһ��ʶ����Ϊ���û�֤���Ψһ֤���ʶ*/
    char UserAccount[32]; /* �û�ID�����ֶ�Ϊ�������ʱ�����UserID */
    char CertInfo[1024];  /* ֤����Ϣ�����ֶ�����Ϊ֤���֤�����⣬֤�������ÿ���ֶμ���'/'�ָ���
                            �ն˿�����ȡ��������Ͷ�Ӧֵ����չʾ��
                            user_cert_cid         ֤��Ψһ��ʶ
                            subject_common_name   �û�ID
                            term_desc             �豸��ʶ
                            cert_last_use_time    ���ʹ��ʱ��
                            user_cert_not_before  ��ʼ����
                            user_cert_not_after   ��ֹ����
                            */
};

//����֤�������
class CHSSMCertApi
{
public:
    /**
     * @brief ��ʼ������֤��������
     * 
     *
     * @param config  [in] �û���������
     * @return int    �ɹ����� 0
     *                ʧ�ܷ��ش�����
     */
    virtual int Init(const HSGMCertUserConfig* pUserConfig) = 0;

    /**
     * @brief �ͷŴ������֤��Ķ���
     *
     * @param  [in] Conn �������Ӷ���
     * @param  [in] CertMgr ����֤��������
     * @param  [in] pCert ��Ÿ��û���������֤��Ķ���
     * @return int  �ɹ����� 0
     *              ʧ�ܷ��ش�����
     */
    virtual void Release() = 0;

    /**
     * @brief ���ݴ������ȡ��ϸ������Ϣ
     * 
     * @param [in]  nErrorCode �����룬֤����ر�����֤����֤�����ڡ����ٲ�����ķ���ֵ
     * @return const char*  �ɹ����ش�����Ϣ
     */
    virtual const char* GetSMErrorMsg(int nErrorCode) = 0;

    /**
     * @brief �����û�֤�飬�������û�PIN�룬PIN�볤�Ȳ���С��6λ
     *
     * �����������Ч֤�飬����API��У��PIN
     * ��PINУ��ʧ�ܣ����ش�����
     * ������Ч֤�飬ֱ�Ӽ���ǩ��֤������
     *
     * ����Ч֤��ʱ����̨��У���û�����
     * ����̨У��UserPasswordʧ�ܣ����ش�����
     * ����̨У��UserPassword�ɹ�������ǩ��֤������
     *
     * @return int   �ɹ����� 0
     *               ʧ�ܷ��ش�����
     *
     */
    virtual int ReqCertEnroll() = 0;

    /**
     * @brief ���ڱ��豸�û�֤��
     *
     * ��̨��У���û�����
     * ����̨У��UserPasswordʧ�ܣ����ش�����
     * ����̨У��UserPassword�ɹ����ſ��Լ�������֤�顣
     *
     * @return int  �ɹ����� 0
     *              ʧ�ܷ��ش�����
     *
     */
    virtual int ReqCertDelay() = 0;

    /**
    * @brief �ϳ����豸�û�֤��
    *
    * ��̨��У���û�����
    * ����̨У��UserPasswordʧ�ܣ����ش�����
    * ����̨У��UserPassword�ɹ����ſ��Լ����ϳ����豸�û�֤�顣
    *
    * @return int  �ɹ����� 0
    *              ʧ�ܷ��ش�����
    *
    */
    virtual int ReqCertRevoke() = 0;

    /**
     * @brief ����CertID�����û�֤��
     *
     * ��̨��У���û�����
     * ����̨У��PASSWORDʧ�ܣ����ش�����
     * ����̨У��PASSWORD�ɹ����ſ��Լ�������֤�顣
     * 
     * @param [in]  CertID ֤��Ψһ��ʶ
     * @return int   �ɹ����� 0
     *               ʧ�ܷ��ش�����
     *
     */
    virtual int ReqCertRevokeByID(const char* pszCertID) = 0;

    /**
     * @brief ����PIN
     *
     * ��̨��У���û�����
     * ����̨У��PASSWORDʧ�ܣ����ش�����
     * ����̨У��PASSWORD�ɹ����ſɼ�������PIN��
     *
     * ��У��ɵ�PIN��ֻ���ñ���֤��PIN 
     *
     * @param [in]  NewPIN �µ�PIN��
     * @return int  �ɹ����� 0
     *              ʧ�ܷ��ش�����
     *
     */
    virtual int ReqResetPin(const char* pszNewPIN) = 0;

    /**
     * @brief ��ѯ�û������������Ч��֤����Ϣ
     *
     * �����û��ڵ�¼֮ǰ���ã���ѯ���Լ���֤�飬�Ը�֪��̨����Ա֤����Ϣ��ע�������֤�顣
     * ��̨��У���û�����
     * ����̨У��UserPasswordʧ�ܣ����ش�����
     * ����̨У��UserPassword�ɹ����ſ��Լ�����ѯ֤�顣
     *
     * pCertָ��ָ����ڴ棬��API�ڲ�����
     *
     * @param [out] pCert ��Ÿ��û���������֤��Ķ���
     * @param [out] count ���û���������֤�����
     * @return int
     *
     */
    virtual int ReqCertQuery(HSSMCert** pCert, int* count) = 0;
};

#ifdef __cplusplus
extern "C" {
#endif 
    /**
     * @brief ��ȡ����֤�����ӿڰ汾��
     */
    SM_CERT_EXPORT const char* GetSMCertApiVersion();

    /**
     * @brief ��������֤�����ӿ�
     */
    SM_CERT_EXPORT CHSSMCertApi* NewSMCertApi(const char* pszFlowPath);

#ifdef __cplusplus
}
#endif
#endif