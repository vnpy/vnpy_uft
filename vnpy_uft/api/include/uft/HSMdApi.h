/**
* @author 寿贺飞
* @company 恒生电子股份有限公司
* @file HSMdApi.h
* @brief 定义了行情接口
* @date    20170927
*/
#ifndef _HS_MD_API_H_
#define _HS_MD_API_H_

#include "HSStruct.h"


#ifdef WIN32
    #define MD_API_EXPORT 
#else
    #ifdef HSMDAPI_EXPORTS
        #define MD_API_EXPORT __attribute__((visibility("default"))) 
    #else
        #define MD_API_EXPORT
    #endif
#endif

///回调虚类
class CHSMdSpi
{
public:
    /// Description: 当客户端与交易后台开始建立通信连接，连接成功后此方法被回调。
    virtual void OnFrontConnected(){};

    /// Description:当客户端与交易后台通信连接异常时，该方法被调用。
    /// Others     :通过GetApiErrorMsg(nResult)获取详细错误信息。
    virtual void OnFrontDisconnected(int nResult){};

    /// Description: 订阅-行情应答
    virtual void OnRspDepthMarketDataSubscribe(CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description: 订阅取消-行情应答
    virtual void OnRspDepthMarketDataCancel(CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description: 主推-行情
    virtual void OnRtnDepthMarketData(CHSDepthMarketDataField *pDepthMarketData) {};

    /// Description: 订阅-询价应答
    virtual void OnRspForQuoteSubscribe(CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description: 订阅取消-询价应答
    virtual void OnRspForQuoteCancel(CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

    /// Description: 主推-询价
    virtual void OnRtnForQuote(CHSForQuoteField *pForQuote) {};

};

///行情
class CHSMdApi
{
public:
    /// Description: 删除接口对象本身
    virtual void ReleaseApi() = 0;

    /// Description: 初始化连接
    ///              pInitCfgField            初始化入参
    ///              pExtraParam              初始化额外参数
    virtual int Init(const CHSInitConfigField *pInitCfgField, void* pExtraParam = (void*)0) = 0;

    /// Description: API和交易柜台建立连接，连接建立成功后，主线程会等待用户操作子线程退出
    /// Return     ：int 0表示连接建立成功，否则表示失败，通过调用GetApiErrorMsg可以获取详细错误信息
    virtual int Join() = 0;

    /// Description: 注册前置机网络地址
    /// Input      : pszFrontAddress            前置机网络地址  如：”tcp://127.0.0.1:17001”
    /// Return     : int 0表示设置成功，否则表示失败，通过调用GetApiErrorMsg可以获取详细错误信息
    virtual int RegisterFront(const char *pszFrontAddress) = 0;

    /// Description: 注册Fens网络地址
    /// Input      : pszFensAddress            Fens网络地址
    /// Input      : pszAccountID              账号
    /// Return     : int 0表示设置成功，否则表示失败，通过调用GetApiErrorMsg可以获取详细错误信息
    virtual int RegisterFensServer(const char *pszFensAddress, const char *pszAccountID) = 0;

    /// Description: 注册回调接口
    /// Input      : pSpi            派生自回调接口类的实例     
    virtual void RegisterSpi(CHSMdSpi *pSpi) = 0;

    /// Description: 订阅-行情请求
    /// Input      : pReqDepthMarketDataSubscribe[]        行情订阅请求结构体数组 
    ///              nCount                                订阅行情合约个数
    ///              nRequestID                            请求编号 
    virtual int ReqDepthMarketDataSubscribe(CHSReqDepthMarketDataField pReqDepthMarketDataSubscribe[], int nCount, int nRequestID) = 0;

    /// Description: 订阅取消-行情请求
    /// Input      : pReqDepthMarketDataCancel[]        行情订阅取消请求结构体数组 
    ///              nCount                             订阅取消行情合约个数
    ///              nRequestID                         请求编号 
    virtual int ReqDepthMarketDataCancel(CHSReqDepthMarketDataField pReqDepthMarketDataCancel[], int nCount, int nRequestID) = 0;

    /// Description: 订阅-询价请求
    /// Input      : pReqForQuoteSubscribe[]               询价订阅请求结构体数组 
    ///              nCount                                订阅询价合约个数
    ///              nRequestID                            请求编号 
    virtual int ReqForQuoteSubscribe(CHSReqForQuoteField pReqForQuoteSubscribe[], int nCount, int nRequestID) = 0;

    /// Description: 订阅取消-询价请求
    /// Input      : pReqForQuoteCancel[]                  询价订阅取消请求结构体数组 
    ///              nCount                                订阅取消询价合约个数
    ///              nRequestID                            请求编号
    virtual int ReqForQuoteCancel(CHSReqForQuoteField pReqForQuoteCancel[], int nCount, int nRequestID) = 0;

    ///////////////////////////////////////////////////////////////////////////////////////
    /// Description: 获得错误详细信息
    /// Input      : nErrorCode            错误号
    /// Return     ：错误信息
    ///////////////////////////////////////////////////////////////////////////////////////
    virtual const char* GetApiErrorMsg(int nErrorCode) = 0;

protected:
    ~CHSMdApi(){};
 };
#ifdef __cplusplus
extern "C"
{
#endif
    /// Description: 获取API版本号
    /// Return     : API版本号
    const char* GetMdApiVersion();

    /// Description: 创建行情接口
    /// Input      : pszFlowPath    日志路径   
    CHSMdApi* NewMdApi(const char *pszFlowPath);

#ifdef __cplusplus
}
#endif
#endif
