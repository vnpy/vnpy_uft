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

/* 协同签名配置对象 */
struct HSGMCertUserConfig
{
    char  UserAccount[32];          /* 用户的Account */
    char  UserPin[32];              /* 用户的本地PIN码 */
    char  UserPassword[32];         /* 用户的密码，用于用户下证校验 */
    char  ServerIP[64];             /* 协同签名服务器地址 */
    char  Version[16];              /* 商密厂商  格尔:gergmssl  信安:xasjgmssl 必须指定*/
};

/* 证书信息 */
struct HSSMCert
{
    char CertID[50];      /* 证书唯一标识，该字段为自定义的唯一标识，作为该用户证书的唯一证书标识*/
    char UserAccount[32]; /* 用户ID，该字段为创建句柄时传入的UserID */
    char CertInfo[1024];  /* 证书信息，该字段内容为证书的证书主题，证书主题的每个字段间用'/'分隔，
                            终端可以提取以下主题和对应值进行展示：
                            user_cert_cid         证书唯一标识
                            subject_common_name   用户ID
                            term_desc             设备标识
                            cert_last_use_time    最后使用时间
                            user_cert_not_before  起始日期
                            user_cert_not_after   截止日期
                            */
};

//商密证书管理类
class CHSSMCertApi
{
public:
    /**
     * @brief 初始化商密证书管理对象
     * 
     *
     * @param config  [in] 用户参数配置
     * @return int    成功返回 0
     *                失败返回错误码
     */
    virtual int Init(const HSGMCertUserConfig* pUserConfig) = 0;

    /**
     * @brief 释放存放所有证书的对象
     *
     * @param  [in] Conn 商密连接对象
     * @param  [in] CertMgr 商密证书管理对象
     * @param  [in] pCert 存放该用户名下所有证书的对象
     * @return int  成功返回 0
     *              失败返回错误码
     */
    virtual void Release() = 0;

    /**
     * @brief 根据错误码获取详细错误信息
     * 
     * @param [in]  nErrorCode 错误码，证书相关比如下证、查证、延期、销毁操作后的返回值
     * @return const char*  成功返回错误信息
     */
    virtual const char* GetSMErrorMsg(int nErrorCode) = 0;

    /**
     * @brief 申请用户证书，并设置用户PIN码，PIN码长度不能小于6位
     *
     * 如果本地有有效证书，厂商API需校验PIN
     * 如PIN校验失败，返回错误码
     * 如无有效证书，直接继续签发证书流程
     *
     * 无有效证书时，后台需校验用户密码
     * 若后台校验UserPassword失败，返回错误码
     * 若后台校验UserPassword成功，继续签发证书流程
     *
     * @return int   成功返回 0
     *               失败返回错误码
     *
     */
    virtual int ReqCertEnroll() = 0;

    /**
     * @brief 延期本设备用户证书
     *
     * 后台需校验用户密码
     * 若后台校验UserPassword失败，返回错误码
     * 若后台校验UserPassword成功，才可以继续延期证书。
     *
     * @return int  成功返回 0
     *              失败返回错误码
     *
     */
    virtual int ReqCertDelay() = 0;

    /**
    * @brief 废除本设备用户证书
    *
    * 后台需校验用户密码
    * 若后台校验UserPassword失败，返回错误码
    * 若后台校验UserPassword成功，才可以继续废除本设备用户证书。
    *
    * @return int  成功返回 0
    *              失败返回错误码
    *
    */
    virtual int ReqCertRevoke() = 0;

    /**
     * @brief 根据CertID废弃用户证书
     *
     * 后台需校验用户密码
     * 若后台校验PASSWORD失败，返回错误码
     * 若后台校验PASSWORD成功，才可以继续废弃证书。
     * 
     * @param [in]  CertID 证书唯一标识
     * @return int   成功返回 0
     *               失败返回错误码
     *
     */
    virtual int ReqCertRevokeByID(const char* pszCertID) = 0;

    /**
     * @brief 重置PIN
     *
     * 后台需校验用户密码
     * 若后台校验PASSWORD失败，返回错误码
     * 若后台校验PASSWORD成功，才可继续重置PIN。
     *
     * 不校验旧的PIN，只重置本地证书PIN 
     *
     * @param [in]  NewPIN 新的PIN码
     * @return int  成功返回 0
     *              失败返回错误码
     *
     */
    virtual int ReqResetPin(const char* pszNewPIN) = 0;

    /**
     * @brief 查询用户服务端所有有效的证书信息
     *
     * 允许用户在登录之前调用，查询出自己的证书，以告知后台管理员证书信息，注销服务端证书。
     * 后台需校验用户密码
     * 若后台校验UserPassword失败，返回错误码
     * 若后台校验UserPassword成功，才可以继续查询证书。
     *
     * pCert指针指向的内存，由API内部申请
     *
     * @param [out] pCert 存放该用户名下所有证书的对象
     * @param [out] count 该用户名下所有证书个数
     * @return int
     *
     */
    virtual int ReqCertQuery(HSSMCert** pCert, int* count) = 0;
};

#ifdef __cplusplus
extern "C" {
#endif 
    /**
     * @brief 获取商密证书管理接口版本号
     */
    SM_CERT_EXPORT const char* GetSMCertApiVersion();

    /**
     * @brief 创建商密证书管理接口
     */
    SM_CERT_EXPORT CHSSMCertApi* NewSMCertApi(const char* pszFlowPath);

#ifdef __cplusplus
}
#endif
#endif