// vnuftmd.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "vnufttd.h"


///-------------------------------------------------------------------------------------
///C++�Ļص����������ݱ��浽������
///-------------------------------------------------------------------------------------
void TdApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	this->task_queue.push(task);
};

void TdApi::OnFrontDisconnected(int nResult)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = nResult;
	this->task_queue.push(task);
};

void TdApi::OnRspAuthenticate(CHSRspAuthenticateField *pRspAuthenticate, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPAUTHENTICATE;
	if (pRspAuthenticate)
	{
		CHSRspAuthenticateField *task_data = new CHSRspAuthenticateField();
		*task_data = *pRspAuthenticate;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSubmitUserSystemInfo(CHSRspUserSystemInfoField *pRspUserSystemInfo, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSUBMITUSERSYSTEMINFO;
	if (pRspUserSystemInfo)
	{
		CHSRspUserSystemInfoField *task_data = new CHSRspUserSystemInfoField();
		*task_data = *pRspUserSystemInfo;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspUserLogin(CHSRspUserLoginField *pRspUserLogin, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGIN;
	if (pRspUserLogin)
	{
		CHSRspUserLoginField *task_data = new CHSRspUserLoginField();
		*task_data = *pRspUserLogin;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspUserPasswordUpdate(CHSRspUserPasswordUpdateField *pRspUserPasswordUpdate, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPUSERPASSWORDUPDATE;
	if (pRspUserPasswordUpdate)
	{
		CHSRspUserPasswordUpdateField *task_data = new CHSRspUserPasswordUpdateField();
		*task_data = *pRspUserPasswordUpdate;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspErrorOrderInsert(CHSRspOrderInsertField *pRspOrderInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPERRORORDERINSERT;
	if (pRspOrderInsert)
	{
		CHSRspOrderInsertField *task_data = new CHSRspOrderInsertField();
		*task_data = *pRspOrderInsert;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspOrderAction(CHSRspOrderActionField *pRspOrderAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPORDERACTION;
	if (pRspOrderAction)
	{
		CHSRspOrderActionField *task_data = new CHSRspOrderActionField();
		*task_data = *pRspOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspErrorExerciseOrderInsert(CHSRspExerciseOrderInsertField *pRspExerciseOrderInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPERROREXERCISEORDERINSERT;
	if (pRspExerciseOrderInsert)
	{
		CHSRspExerciseOrderInsertField *task_data = new CHSRspExerciseOrderInsertField();
		*task_data = *pRspExerciseOrderInsert;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspExerciseOrderAction(CHSRspExerciseOrderActionField *pRspExerciseOrderAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPEXERCISEORDERACTION;
	if (pRspExerciseOrderAction)
	{
		CHSRspExerciseOrderActionField *task_data = new CHSRspExerciseOrderActionField();
		*task_data = *pRspExerciseOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspErrorLockInsert(CHSRspLockInsertField *pRspExerciseOrderAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPERRORLOCKINSERT;
	if (pRspExerciseOrderAction)
	{
		CHSRspLockInsertField *task_data = new CHSRspLockInsertField();
		*task_data = *pRspExerciseOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspForQuoteInsert(CHSRspForQuoteInsertField *pRspForQuoteInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFORQUOTEINSERT;
	if (pRspForQuoteInsert)
	{
		CHSRspForQuoteInsertField *task_data = new CHSRspForQuoteInsertField();
		*task_data = *pRspForQuoteInsert;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspErrorQuoteInsert(CHSRspQuoteInsertField *pRspQuoteInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPERRORQUOTEINSERT;
	if (pRspQuoteInsert)
	{
		CHSRspQuoteInsertField *task_data = new CHSRspQuoteInsertField();
		*task_data = *pRspQuoteInsert;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQuoteAction(CHSRspQuoteActionField *pRspQuoteAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQUOTEACTION;
	if (pRspQuoteAction)
	{
		CHSRspQuoteActionField *task_data = new CHSRspQuoteActionField();
		*task_data = *pRspQuoteAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspErrorCombActionInsert(CHSRspCombActionInsertField *pRspCombActionInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPERRORCOMBACTIONINSERT;
	if (pRspCombActionInsert)
	{
		CHSRspCombActionInsertField *task_data = new CHSRspCombActionInsertField();
		*task_data = *pRspCombActionInsert;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQueryMaxOrderVolume(CHSRspQueryMaxOrderVolumeField *pRspQueryMaxOrderVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQUERYMAXORDERVOLUME;
	if (pRspQueryMaxOrderVolume)
	{
		CHSRspQueryMaxOrderVolumeField *task_data = new CHSRspQueryMaxOrderVolumeField();
		*task_data = *pRspQueryMaxOrderVolume;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryLockVolume(CHSRspQryLockVolumeField *pRspQryLockVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYLOCKVOLUME;
	if (pRspQryLockVolume)
	{
		CHSRspQryLockVolumeField *task_data = new CHSRspQryLockVolumeField();
		*task_data = *pRspQryLockVolume;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQueryExerciseVolume(CHSRspQueryExerciseVolumeField *pRspQueryExerciseVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQUERYEXERCISEVOLUME;
	if (pRspQueryExerciseVolume)
	{
		CHSRspQueryExerciseVolumeField *task_data = new CHSRspQueryExerciseVolumeField();
		*task_data = *pRspQueryExerciseVolume;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryCombVolume(CHSRspQryCombVolumeField *pRspQryCombVolume, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBVOLUME;
	if (pRspQryCombVolume)
	{
		CHSRspQryCombVolumeField *task_data = new CHSRspQryCombVolumeField();
		*task_data = *pRspQryCombVolume;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryPosition(CHSRspQryPositionField *pRspQryPosition, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITION;
	if (pRspQryPosition)
	{
		CHSRspQryPositionField *task_data = new CHSRspQryPositionField();
		*task_data = *pRspQryPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryTradingAccount(CHSRspQryTradingAccountField *pRspQryTradingAccount, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGACCOUNT;
	if (pRspQryTradingAccount)
	{
		CHSRspQryTradingAccountField *task_data = new CHSRspQryTradingAccountField();
		*task_data = *pRspQryTradingAccount;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryOrder(CHSOrderField *pRspQryOrder, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDER;
	if (pRspQryOrder)
	{
		CHSOrderField *task_data = new CHSOrderField();
		*task_data = *pRspQryOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryTrade(CHSTradeField *pRspQryTrade, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADE;
	if (pRspQryTrade)
	{
		CHSTradeField *task_data = new CHSTradeField();
		*task_data = *pRspQryTrade;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryExercise(CHSExerciseField *pRspQryExercise, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXERCISE;
	if (pRspQryExercise)
	{
		CHSExerciseField *task_data = new CHSExerciseField();
		*task_data = *pRspQryExercise;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryLock(CHSLockField *pRspQryLock, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYLOCK;
	if (pRspQryLock)
	{
		CHSLockField *task_data = new CHSLockField();
		*task_data = *pRspQryLock;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryCombAction(CHSCombActionField *pRspQryCombAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBACTION;
	if (pRspQryCombAction)
	{
		CHSCombActionField *task_data = new CHSCombActionField();
		*task_data = *pRspQryCombAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryForQuote(CHSForQuoteField *pRspQryForQuote, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYFORQUOTE;
	if (pRspQryForQuote)
	{
		CHSForQuoteField *task_data = new CHSForQuoteField();
		*task_data = *pRspQryForQuote;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryQuote(CHSQuoteField *pRspQryQuote, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYQUOTE;
	if (pRspQryQuote)
	{
		CHSQuoteField *task_data = new CHSQuoteField();
		*task_data = *pRspQryQuote;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryPositionCombineDetail(CHSRspQryPositionCombineDetailField *pRspQryPositionCombineDetail, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITIONCOMBINEDETAIL;
	if (pRspQryPositionCombineDetail)
	{
		CHSRspQryPositionCombineDetailField *task_data = new CHSRspQryPositionCombineDetailField();
		*task_data = *pRspQryPositionCombineDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryInstrument(CHSRspQryInstrumentField *pRspQryInstrument, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYINSTRUMENT;
	if (pRspQryInstrument)
	{
		CHSRspQryInstrumentField *task_data = new CHSRspQryInstrumentField();
		*task_data = *pRspQryInstrument;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryCoveredShort(CHSRspQryCoveredShortField *pRspQryCoveredShort, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOVEREDSHORT;
	if (pRspQryCoveredShort)
	{
		CHSRspQryCoveredShortField *task_data = new CHSRspQryCoveredShortField();
		*task_data = *pRspQryCoveredShort;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryExerciseAssign(CHSRspQryExerciseAssignField *pRspQryExerciseAssign, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXERCISEASSIGN;
	if (pRspQryExerciseAssign)
	{
		CHSRspQryExerciseAssignField *task_data = new CHSRspQryExerciseAssignField();
		*task_data = *pRspQryExerciseAssign;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspTransfer(CHSRspTransferField *pRspTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPTRANSFER;
	if (pRspTransfer)
	{
		CHSRspTransferField *task_data = new CHSRspTransferField();
		*task_data = *pRspTransfer;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryTransfer(CHSRspQryTransferField *pRspQryTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRANSFER;
	if (pRspQryTransfer)
	{
		CHSRspQryTransferField *task_data = new CHSRspQryTransferField();
		*task_data = *pRspQryTransfer;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQueryBankBalance(CHSRspQueryBankBalanceField *pRspQueryBankBalance, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQUERYBANKBALANCE;
	if (pRspQueryBankBalance)
	{
		CHSRspQueryBankBalanceField *task_data = new CHSRspQueryBankBalanceField();
		*task_data = *pRspQueryBankBalance;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQueryBankAccount(CHSRspQueryBankAccountField *pRspQueryBankAccount, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQUERYBANKACCOUNT;
	if (pRspQueryBankAccount)
	{
		CHSRspQueryBankAccountField *task_data = new CHSRspQueryBankAccountField();
		*task_data = *pRspQueryBankAccount;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspMultiCentreFundTrans(CHSRspMultiCentreFundTransField *pRspMultiCentreFundTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPMULTICENTREFUNDTRANS;
	if (pRspMultiCentreFundTransfer)
	{
		CHSRspMultiCentreFundTransField *task_data = new CHSRspMultiCentreFundTransField();
		*task_data = *pRspMultiCentreFundTransfer;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQueryBillContent(CHSRspQueryBillContentField *pRspQueryBillContent, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQUERYBILLCONTENT;
	if (pRspQueryBillContent)
	{
		CHSRspQueryBillContentField *task_data = new CHSRspQueryBillContentField();
		*task_data = *pRspQueryBillContent;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspBillConfirm(CHSRspBillConfirmField *pRspBillConfirm, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPBILLCONFIRM;
	if (pRspBillConfirm)
	{
		CHSRspBillConfirmField *task_data = new CHSRspBillConfirmField();
		*task_data = *pRspBillConfirm;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryMargin(CHSRspQryMarginField *pRspQryMargin, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYMARGIN;
	if (pRspQryMargin)
	{
		CHSRspQryMarginField *task_data = new CHSRspQryMarginField();
		*task_data = *pRspQryMargin;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryCommission(CHSRspQryCommissionField *pRspQryCommission, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMMISSION;
	if (pRspQryCommission)
	{
		CHSRspQryCommissionField *task_data = new CHSRspQryCommissionField();
		*task_data = *pRspQryCommission;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryPositionDetail(CHSRspQryPositionDetailField *pRspQryPositionDetail, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITIONDETAIL;
	if (pRspQryPositionDetail)
	{
		CHSRspQryPositionDetailField *task_data = new CHSRspQryPositionDetailField();
		*task_data = *pRspQryPositionDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryExchangeRate(CHSRspQryExchangeRateField *pRspQryExchangeRate, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXCHANGERATE;
	if (pRspQryExchangeRate)
	{
		CHSRspQryExchangeRateField *task_data = new CHSRspQryExchangeRateField();
		*task_data = *pRspQryExchangeRate;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQrySysConfig(CHSRspQrySysConfigField *pRspQrySysConfig, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSYSCONFIG;
	if (pRspQrySysConfig)
	{
		CHSRspQrySysConfigField *task_data = new CHSRspQrySysConfigField();
		*task_data = *pRspQrySysConfig;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryDepthMarketData(CHSDepthMarketDataField *pRspQryDepthMarketData, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYDEPTHMARKETDATA;
	if (pRspQryDepthMarketData)
	{
		CHSDepthMarketDataField *task_data = new CHSDepthMarketDataField();
		*task_data = *pRspQryDepthMarketData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFundTrans(CHSRspFundTransField *pRspFundTransfer, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFUNDTRANS;
	if (pRspFundTransfer)
	{
		CHSRspFundTransField *task_data = new CHSRspFundTransField();
		*task_data = *pRspFundTransfer;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryFundTrans(CHSRspQryFundTransField *pRspQryFundTrans, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYFUNDTRANS;
	if (pRspQryFundTrans)
	{
		CHSRspQryFundTransField *task_data = new CHSRspQryFundTransField();
		*task_data = *pRspQryFundTrans;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryClientNotice(CHSClientNoticeField *pRspQryClientNotice, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCLIENTNOTICE;
	if (pRspQryClientNotice)
	{
		CHSClientNoticeField *task_data = new CHSClientNoticeField();
		*task_data = *pRspQryClientNotice;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryOptUnderly(CHSRspQryOptUnderlyField *pRspQryOptUnderly, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYOPTUNDERLY;
	if (pRspQryOptUnderly)
	{
		CHSRspQryOptUnderlyField *task_data = new CHSRspQryOptUnderlyField();
		*task_data = *pRspQryOptUnderly;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQrySecuDepthMarket(CHSRspQrySecuDepthMarketField *pRspQrySecuDepthMarket, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSECUDEPTHMARKET;
	if (pRspQrySecuDepthMarket)
	{
		CHSRspQrySecuDepthMarketField *task_data = new CHSRspQrySecuDepthMarketField();
		*task_data = *pRspQrySecuDepthMarket;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryHistOrder(CHSOrderField *pRspQryHistOrder, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYHISTORDER;
	if (pRspQryHistOrder)
	{
		CHSOrderField *task_data = new CHSOrderField();
		*task_data = *pRspQryHistOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryHistTrade(CHSTradeField *pRspQryHistTrade, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYHISTTRADE;
	if (pRspQryHistTrade)
	{
		CHSTradeField *task_data = new CHSTradeField();
		*task_data = *pRspQryHistTrade;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryCombInstrument(CHSRspQryCombInstrumentField *pRspQryCombInstrument, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBINSTRUMENT;
	if (pRspQryCombInstrument)
	{
		CHSRspQryCombInstrumentField *task_data = new CHSRspQryCombInstrumentField();
		*task_data = *pRspQryCombInstrument;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQrySeatID(CHSRspQrySeatIDField *pRspQrySeatID, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSEATID;
	if (pRspQrySeatID)
	{
		CHSRspQrySeatIDField *task_data = new CHSRspQrySeatIDField();
		*task_data = *pRspQrySeatID;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspOptionSelfClose(CHSRspOptionSelfCloseField *pReqOptionSelfClose, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPOPTIONSELFCLOSE;
	if (pReqOptionSelfClose)
	{
		CHSRspOptionSelfCloseField *task_data = new CHSRspOptionSelfCloseField();
		*task_data = *pReqOptionSelfClose;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspOptionSelfCloseAction(CHSRspOptionSelfCloseActionField *pReqOptionSelfCloseAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPOPTIONSELFCLOSEACTION;
	if (pReqOptionSelfCloseAction)
	{
		CHSRspOptionSelfCloseActionField *task_data = new CHSRspOptionSelfCloseActionField();
		*task_data = *pReqOptionSelfCloseAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryOptionSelfCloseResult(CHSRspQryOptionSelfCloseResultField *pReqQryOptionSelfCloseResult, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYOPTIONSELFCLOSERESULT;
	if (pReqQryOptionSelfCloseResult)
	{
		CHSRspQryOptionSelfCloseResultField *task_data = new CHSRspQryOptionSelfCloseResultField();
		*task_data = *pReqQryOptionSelfCloseResult;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryOptionSelfClose(CHSOptionSelfCloseField *pRspQryOptionSelfClose, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYOPTIONSELFCLOSE;
	if (pRspQryOptionSelfClose)
	{
		CHSOptionSelfCloseField *task_data = new CHSOptionSelfCloseField();
		*task_data = *pRspQryOptionSelfClose;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspOptQuoteInsert(CHSRspOptQuoteInsertField *pRspOptQuoteInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPOPTQUOTEINSERT;
	if (pRspOptQuoteInsert)
	{
		CHSRspOptQuoteInsertField *task_data = new CHSRspOptQuoteInsertField();
		*task_data = *pRspOptQuoteInsert;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspOptQuoteAction(CHSRspOptQuoteActionField *pRspOptQuoteAction, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPOPTQUOTEACTION;
	if (pRspOptQuoteAction)
	{
		CHSRspOptQuoteActionField *task_data = new CHSRspOptQuoteActionField();
		*task_data = *pRspOptQuoteAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryOptQuote(CHSOptQuoteField *pRspQryOptQuote, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYOPTQUOTE;
	if (pRspQryOptQuote)
	{
		CHSOptQuoteField *task_data = new CHSOptQuoteField();
		*task_data = *pRspQryOptQuote;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSRspInfoField *task_error = new CHSRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRtnTrade(CHSTradeField *pRtnTrade)
{
	Task task = Task();
	task.task_name = ONRTNTRADE;
	if (pRtnTrade)
	{
		CHSTradeField *task_data = new CHSTradeField();
		*task_data = *pRtnTrade;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnOrder(CHSOrderField *pRtnOrder)
{
	Task task = Task();
	task.task_name = ONRTNORDER;
	if (pRtnOrder)
	{
		CHSOrderField *task_data = new CHSOrderField();
		*task_data = *pRtnOrder;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnExercise(CHSExerciseField *pRtnExercise)
{
	Task task = Task();
	task.task_name = ONRTNEXERCISE;
	if (pRtnExercise)
	{
		CHSExerciseField *task_data = new CHSExerciseField();
		*task_data = *pRtnExercise;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnCombAction(CHSCombActionField *pRtnCombAction)
{
	Task task = Task();
	task.task_name = ONRTNCOMBACTION;
	if (pRtnCombAction)
	{
		CHSCombActionField *task_data = new CHSCombActionField();
		*task_data = *pRtnCombAction;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnLock(CHSLockField *pRtnLock)
{
	Task task = Task();
	task.task_name = ONRTNLOCK;
	if (pRtnLock)
	{
		CHSLockField *task_data = new CHSLockField();
		*task_data = *pRtnLock;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnErrRtnOrderAction(CHSOrderActionField *pRtnOrder)
{
	Task task = Task();
	task.task_name = ONERRRTNORDERACTION;
	if (pRtnOrder)
	{
		CHSOrderActionField *task_data = new CHSOrderActionField();
		*task_data = *pRtnOrder;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnClientNotice(CHSClientNoticeField *pRtnClientNotice)
{
	Task task = Task();
	task.task_name = ONRTNCLIENTNOTICE;
	if (pRtnClientNotice)
	{
		CHSClientNoticeField *task_data = new CHSClientNoticeField();
		*task_data = *pRtnClientNotice;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};


void TdApi::OnRtnForQuote(CHSForQuoteField *pRtnForQuote)
{
	Task task = Task();
	task.task_name = ONRTNFORQUOTE;
	if (pRtnForQuote)
	{
		CHSForQuoteField *task_data = new CHSForQuoteField();
		*task_data = *pRtnForQuote;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnQuote(CHSQuoteField *pRtnQuote)
{
	Task task = Task();
	task.task_name = ONRTNQUOTE;
	if (pRtnQuote)
	{
		CHSQuoteField *task_data = new CHSQuoteField();
		*task_data = *pRtnQuote;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnExchangeStatus(CHSExchangeStatusField *pRtnExchangeStatus)
{
	Task task = Task();
	task.task_name = ONRTNEXCHANGESTATUS;
	if (pRtnExchangeStatus)
	{
		CHSExchangeStatusField *task_data = new CHSExchangeStatusField();
		*task_data = *pRtnExchangeStatus;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnProductStatus(CHSProductStatusField *pRtnProductStatus)
{
	Task task = Task();
	task.task_name = ONRTNPRODUCTSTATUS;
	if (pRtnProductStatus)
	{
		CHSProductStatusField *task_data = new CHSProductStatusField();
		*task_data = *pRtnProductStatus;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnOptionSelfClose(CHSOptionSelfCloseField *pRtnOptionSelfClose)
{
	Task task = Task();
	task.task_name = ONRTNOPTIONSELFCLOSE;
	if (pRtnOptionSelfClose)
	{
		CHSOptionSelfCloseField *task_data = new CHSOptionSelfCloseField();
		*task_data = *pRtnOptionSelfClose;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnOptQuote(CHSOptQuoteField *pRtnOptQuote)
{
	Task task = Task();
	task.task_name = ONRTNOPTQUOTE;
	if (pRtnOptQuote)
	{
		CHSOptQuoteField *task_data = new CHSOptQuoteField();
		*task_data = *pRtnOptQuote;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

///-------------------------------------------------------------------------------------
///�����̴߳Ӷ�����ȡ�����ݣ�ת��Ϊpython����󣬽�������
///-------------------------------------------------------------------------------------

void TdApi::processTask()
{
    try
    {
        while (this->active)
        {
            Task task = this->task_queue.pop();

			switch (task.task_name)
			{
			case ONFRONTCONNECTED:
			{
				this->processFrontConnected(&task);
				break;
			}

			case ONFRONTDISCONNECTED:
			{
				this->processFrontDisconnected(&task);
				break;
			}

			case ONRSPAUTHENTICATE:
			{
				this->processRspAuthenticate(&task);
				break;
			}

			case ONRSPSUBMITUSERSYSTEMINFO:
			{
				this->processRspSubmitUserSystemInfo(&task);
				break;
			}

			case ONRSPUSERLOGIN:
			{
				this->processRspUserLogin(&task);
				break;
			}

			case ONRSPUSERPASSWORDUPDATE:
			{
				this->processRspUserPasswordUpdate(&task);
				break;
			}

			case ONRSPERRORORDERINSERT:
			{
				this->processRspErrorOrderInsert(&task);
				break;
			}

			case ONRSPORDERACTION:
			{
				this->processRspOrderAction(&task);
				break;
			}

			case ONRSPERROREXERCISEORDERINSERT:
			{
				this->processRspErrorExerciseOrderInsert(&task);
				break;
			}

			case ONRSPEXERCISEORDERACTION:
			{
				this->processRspExerciseOrderAction(&task);
				break;
			}

			case ONRSPERRORLOCKINSERT:
			{
				this->processRspErrorLockInsert(&task);
				break;
			}

case ONRSPFORQUOTEINSERT:
{
	this->processRspForQuoteInsert(&task);
	break;
}

case ONRSPERRORQUOTEINSERT:
{
	this->processRspErrorQuoteInsert(&task);
	break;
}

case ONRSPQUOTEACTION:
{
	this->processRspQuoteAction(&task);
	break;
}

			case ONRSPERRORCOMBACTIONINSERT:
			{
				this->processRspErrorCombActionInsert(&task);
				break;
			}

			case ONRSPQUERYMAXORDERVOLUME:
			{
				this->processRspQueryMaxOrderVolume(&task);
				break;
			}

			case ONRSPQRYLOCKVOLUME:
			{
				this->processRspQryLockVolume(&task);
				break;
			}

			case ONRSPQUERYEXERCISEVOLUME:
			{
				this->processRspQueryExerciseVolume(&task);
				break;
			}

			case ONRSPQRYCOMBVOLUME:
			{
				this->processRspQryCombVolume(&task);
				break;
			}

			case ONRSPQRYPOSITION:
			{
				this->processRspQryPosition(&task);
				break;
			}

			case ONRSPQRYTRADINGACCOUNT:
			{
				this->processRspQryTradingAccount(&task);
				break;
			}

			case ONRSPQRYORDER:
			{
				this->processRspQryOrder(&task);
				break;
			}

			case ONRSPQRYTRADE:
			{
				this->processRspQryTrade(&task);
				break;
			}

			case ONRSPQRYEXERCISE:
			{
				this->processRspQryExercise(&task);
				break;
			}

			case ONRSPQRYLOCK:
			{
				this->processRspQryLock(&task);
				break;
			}

case ONRSPQRYCOMBACTION:
{
	this->processRspQryCombAction(&task);
	break;
}

case ONRSPQRYFORQUOTE:
{
	this->processRspQryForQuote(&task);
	break;
}

case ONRSPQRYQUOTE:
{
	this->processRspQryQuote(&task);
	break;
}

			case ONRSPQRYPOSITIONCOMBINEDETAIL:
			{
				this->processRspQryPositionCombineDetail(&task);
				break;
			}

			case ONRSPQRYINSTRUMENT:
			{
				this->processRspQryInstrument(&task);
				break;
			}

			case ONRSPQRYCOVEREDSHORT:
			{
				this->processRspQryCoveredShort(&task);
				break;
			}

			case ONRSPQRYEXERCISEASSIGN:
			{
				this->processRspQryExerciseAssign(&task);
				break;
			}

			case ONRSPTRANSFER:
			{
				this->processRspTransfer(&task);
				break;
			}

			case ONRSPQRYTRANSFER:
			{
				this->processRspQryTransfer(&task);
				break;
			}

			case ONRSPQUERYBANKBALANCE:
			{
				this->processRspQueryBankBalance(&task);
				break;
			}

			case ONRSPQUERYBANKACCOUNT:
			{
				this->processRspQueryBankAccount(&task);
				break;
			}

			case ONRSPMULTICENTREFUNDTRANS:
			{
				this->processRspMultiCentreFundTrans(&task);
				break;
			}

			case ONRSPQUERYBILLCONTENT:
			{
				this->processRspQueryBillContent(&task);
				break;
			}

			case ONRSPBILLCONFIRM:
			{
				this->processRspBillConfirm(&task);
				break;
			}

			case ONRSPQRYMARGIN:
			{
				this->processRspQryMargin(&task);
				break;
			}

			case ONRSPQRYCOMMISSION:
			{
				this->processRspQryCommission(&task);
				break;
			}

			case ONRSPQRYPOSITIONDETAIL:
			{
				this->processRspQryPositionDetail(&task);
				break;
			}

			case ONRSPQRYEXCHANGERATE:
			{
				this->processRspQryExchangeRate(&task);
				break;
			}

			case ONRSPQRYSYSCONFIG:
			{
				this->processRspQrySysConfig(&task);
				break;
			}

			case ONRSPQRYDEPTHMARKETDATA:
			{
				this->processRspQryDepthMarketData(&task);
				break;
			}

			case ONRSPFUNDTRANS:
			{
				this->processRspFundTrans(&task);
				break;
			}

			case ONRSPQRYFUNDTRANS:
			{
				this->processRspQryFundTrans(&task);
				break;
			}

			case ONRSPQRYCLIENTNOTICE:
			{
				this->processRspQryClientNotice(&task);
				break;
			}

			case ONRSPQRYOPTUNDERLY:
			{
				this->processRspQryOptUnderly(&task);
				break;
			}

			case ONRSPQRYSECUDEPTHMARKET:
			{
				this->processRspQrySecuDepthMarket(&task);
				break;
			}

			case ONRSPQRYHISTORDER:
			{
				this->processRspQryHistOrder(&task);
				break;
			}

case ONRSPQRYHISTTRADE:
{
	this->processRspQryHistTrade(&task);
	break;
}

case ONRSPQRYCOMBINSTRUMENT:
{
	this->processRspQryCombInstrument(&task);
	break;
}

case ONRSPQRYSEATID:
{
	this->processRspQrySeatID(&task);
	break;
}

case ONRSPOPTIONSELFCLOSE:
{
	this->processRspOptionSelfClose(&task);
	break;
}

case ONRSPOPTIONSELFCLOSEACTION:
{
	this->processRspOptionSelfCloseAction(&task);
	break;
}

case ONRSPQRYOPTIONSELFCLOSERESULT:
{
	this->processRspQryOptionSelfCloseResult(&task);
	break;
}

case ONRSPQRYOPTIONSELFCLOSE:
{
	this->processRspQryOptionSelfClose(&task);
	break;
}

case ONRSPOPTQUOTEINSERT:
{
	this->processRspOptQuoteInsert(&task);
	break;
}

case ONRSPOPTQUOTEACTION:
{
	this->processRspOptQuoteAction(&task);
	break;
}

case ONRSPQRYOPTQUOTE:
{
	this->processRspQryOptQuote(&task);
	break;
}

			case ONRTNTRADE:
			{
				this->processRtnTrade(&task);
				break;
			}

			case ONRTNORDER:
			{
				this->processRtnOrder(&task);
				break;
			}

			case ONRTNEXERCISE:
			{
				this->processRtnExercise(&task);
				break;
			}

			case ONRTNCOMBACTION:
			{
				this->processRtnCombAction(&task);
				break;
			}

			case ONRTNLOCK:
			{
				this->processRtnLock(&task);
				break;
			}

			case ONERRRTNORDERACTION:
			{
				this->processErrRtnOrderAction(&task);
				break;
			}

			case ONRTNCLIENTNOTICE:
			{
				this->processRtnClientNotice(&task);
				break;
			}

            case ONRTNFORQUOTE:
            {
                this->processRtnForQuote(&task);
                break;
            }

            case ONRTNQUOTE:
            {
                this->processRtnQuote(&task);
                break;
            }

            case ONRTNEXCHANGESTATUS:
            {
                this->processRtnExchangeStatus(&task);
                break;
            }

            case ONRTNPRODUCTSTATUS:
            {
                this->processRtnProductStatus(&task);
                break;
            }

            case ONRTNOPTIONSELFCLOSE:
            {
                this->processRtnOptionSelfClose(&task);
                break;
            }

            case ONRTNOPTQUOTE:
            {
                this->processRtnOptQuote(&task);
                break;
            }
			};
        }
    }
    catch (const TerminatedError&)
    {
    }
};

void TdApi::processFrontConnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontConnected();
};

void TdApi::processFrontDisconnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontDisconnected(task->task_id);
};

void TdApi::processRspAuthenticate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspAuthenticateField *task_data = (CHSRspAuthenticateField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["AppID"] = toUtf(task_data->AppID);
		data["AuthCode"] = toUtf(task_data->AuthCode);
		data["AppIDType"] = task_data->AppIDType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspAuthenticate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspSubmitUserSystemInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspUserSystemInfoField *task_data = (CHSRspUserSystemInfoField*)task->task_data;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSubmitUserSystemInfo(data, error, task->task_id, task->task_last);
};

void TdApi::processRspUserLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspUserLoginField *task_data = (CHSRspUserLoginField*)task->task_data;
		data["BranchID"] = task_data->BranchID;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["UserName"] = toUtf(task_data->UserName);
		data["TradingDay"] = task_data->TradingDay;
		data["PreTradingDay"] = task_data->PreTradingDay;
		data["BillConfirmFlag"] = task_data->BillConfirmFlag;
		data["SessionID"] = task_data->SessionID;
		data["UserApplicationType"] = task_data->UserApplicationType;
		data["UserApplicationInfo"] = toUtf(task_data->UserApplicationInfo);
		data["RiskLevel"] = toUtf(task_data->RiskLevel);
		data["LastMacAddress"] = toUtf(task_data->LastMacAddress);
		data["LastIPAddress"] = toUtf(task_data->LastIPAddress);
		data["LastLoginTime"] = task_data->LastLoginTime;
		data["CZCETime"] = task_data->CZCETime;
		data["DCETime"] = task_data->DCETime;
		data["SHFETime"] = task_data->SHFETime;
		data["CFFEXTime"] = task_data->CFFEXTime;
		data["INETime"] = task_data->INETime;
		data["MaxOrderRef"] = toUtf(task_data->MaxOrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["GFEXTime"] = task_data->GFEXTime;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogin(data, error, task->task_id, task->task_last);
};

void TdApi::processRspUserPasswordUpdate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspUserPasswordUpdateField *task_data = (CHSRspUserPasswordUpdateField*)task->task_data;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserPasswordUpdate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspErrorOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspOrderInsertField *task_data = (CHSRspOrderInsertField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["BrokerOrderID"] = toUtf(task_data->BrokerOrderID);
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeType"] = task_data->HedgeType;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderVolume"] = task_data->OrderVolume;
		data["OrderStatus"] = task_data->OrderStatus;
		data["OrderCommand"] = task_data->OrderCommand;
		data["InsertTime"] = task_data->InsertTime;
		data["MinVolume"] = task_data->MinVolume;
		data["SpringPrice"] = task_data->SpringPrice;
		data["SwapOrderFlag"] = task_data->SwapOrderFlag;
		data["CombPositionID"] = toUtf(task_data->CombPositionID);
		data["ExchangeAccountID"] = toUtf(task_data->ExchangeAccountID);
		data["SeatIndex"] = task_data->SeatIndex;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspErrorOrderInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspOrderActionField *task_data = (CHSRspOrderActionField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["OrderStatus"] = task_data->OrderStatus;
		data["InsertTime"] = task_data->InsertTime;
		data["OrderActionRef"] = toUtf(task_data->OrderActionRef);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspErrorExerciseOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspExerciseOrderInsertField *task_data = (CHSRspExerciseOrderInsertField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["SessionID"] = task_data->SessionID;
		data["ExerciseOrderSysID"] = toUtf(task_data->ExerciseOrderSysID);
		data["ExerciseRef"] = toUtf(task_data->ExerciseRef);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderVolume"] = task_data->OrderVolume;
		data["ExerciseType"] = task_data->ExerciseType;
		data["HedgeType"] = task_data->HedgeType;
		data["OrderStatus"] = task_data->OrderStatus;
		data["InsertTime"] = task_data->InsertTime;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["CloseFlag"] = task_data->CloseFlag;
		data["ExerciseBrokerOrderID"] = toUtf(task_data->ExerciseBrokerOrderID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspErrorExerciseOrderInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspExerciseOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspExerciseOrderActionField *task_data = (CHSRspExerciseOrderActionField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ExerciseOrderSysID"] = toUtf(task_data->ExerciseOrderSysID);
		data["ExerciseRef"] = toUtf(task_data->ExerciseRef);
		data["SessionID"] = task_data->SessionID;
		data["OrderStatus"] = task_data->OrderStatus;
		data["ExecOrderActionRef"] = toUtf(task_data->ExecOrderActionRef);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspExerciseOrderAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspErrorLockInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspLockInsertField *task_data = (CHSRspLockInsertField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["LockOrderSysID"] = toUtf(task_data->LockOrderSysID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["LockType"] = task_data->LockType;
		data["OrderVolume"] = task_data->OrderVolume;
		data["UnderlyingAccountID"] = toUtf(task_data->UnderlyingAccountID);
		data["OrderStatus"] = task_data->OrderStatus;
		data["InsertTime"] = task_data->InsertTime;
		data["LockRef"] = toUtf(task_data->LockRef);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspErrorLockInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspForQuoteInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspForQuoteInsertField *task_data = (CHSRspForQuoteInsertField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderStatus"] = task_data->OrderStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspForQuoteInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspErrorQuoteInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQuoteInsertField *task_data = (CHSRspQuoteInsertField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["BidOffsetFlag"] = task_data->BidOffsetFlag;
		data["BidHedgeType"] = task_data->BidHedgeType;
		data["BidOrderPrice"] = task_data->BidOrderPrice;
		data["BidOrderVolume"] = task_data->BidOrderVolume;
		data["BidOrderRef"] = toUtf(task_data->BidOrderRef);
		data["AskOffsetFlag"] = task_data->AskOffsetFlag;
		data["AskHedgeType"] = task_data->AskHedgeType;
		data["AskOrderPrice"] = task_data->AskOrderPrice;
		data["AskOrderVolume"] = task_data->AskOrderVolume;
		data["AskOrderRef"] = toUtf(task_data->AskOrderRef);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["QuoteBrokerID"] = toUtf(task_data->QuoteBrokerID);
		data["BidOrderSysID"] = toUtf(task_data->BidOrderSysID);
		data["AskOrderSysID"] = toUtf(task_data->AskOrderSysID);
		data["SessionID"] = task_data->SessionID;
		data["InsertTime"] = task_data->InsertTime;
		data["OrderStatus"] = task_data->OrderStatus;
		data["TopOrderType"] = task_data->TopOrderType;
		data["QuoteSysID"] = toUtf(task_data->QuoteSysID);
		data["BidOrderStatus"] = task_data->BidOrderStatus;
		data["AskOrderStatus"] = task_data->AskOrderStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspErrorQuoteInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQuoteAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQuoteActionField *task_data = (CHSRspQuoteActionField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["QuoteSysID"] = toUtf(task_data->QuoteSysID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["SessionID"] = task_data->SessionID;
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["QuoteActionRef"] = toUtf(task_data->QuoteActionRef);
		data["OrderStatus"] = task_data->OrderStatus;
		data["InsertTime"] = task_data->InsertTime;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["BidWithdrawVolume"] = task_data->BidWithdrawVolume;
		data["AskWithdrawVolume"] = task_data->AskWithdrawVolume;
		data["BidQuoteSysID"] = toUtf(task_data->BidQuoteSysID);
		data["AskQuoteSysID"] = toUtf(task_data->AskQuoteSysID);
		data["BidOrderStatus"] = task_data->BidOrderStatus;
		data["AskOrderStatus"] = task_data->AskOrderStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQuoteAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspErrorCombActionInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspCombActionInsertField *task_data = (CHSRspCombActionInsertField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CombOrderSysID"] = toUtf(task_data->CombOrderSysID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["CombStrategyID"] = toUtf(task_data->CombStrategyID);
		data["CombPositionID"] = toUtf(task_data->CombPositionID);
		data["CombDirection"] = task_data->CombDirection;
		data["OrderVolume"] = task_data->OrderVolume;
		data["HedgeType"] = task_data->HedgeType;
		data["OrderStatus"] = task_data->OrderStatus;
		data["InsertTime"] = task_data->InsertTime;
		data["Direction"] = task_data->Direction;
		data["SecondHedgeType"] = task_data->SecondHedgeType;
		data["CombOrderRef"] = toUtf(task_data->CombOrderRef);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspErrorCombActionInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQueryMaxOrderVolume(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQueryMaxOrderVolumeField *task_data = (CHSRspQueryMaxOrderVolumeField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["MaxOrderVolume"] = task_data->MaxOrderVolume;
		data["MaxOrderVolumeUnit"] = task_data->MaxOrderVolumeUnit;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderCommand"] = task_data->OrderCommand;
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeType"] = task_data->HedgeType;
		data["OrderPrice"] = task_data->OrderPrice;
		data["CombPositionID"] = toUtf(task_data->CombPositionID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQueryMaxOrderVolume(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryLockVolume(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryLockVolumeField *task_data = (CHSRspQryLockVolumeField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["LockType"] = task_data->LockType;
		data["AvailablePositionVolume"] = task_data->AvailablePositionVolume;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryLockVolume(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQueryExerciseVolume(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQueryExerciseVolumeField *task_data = (CHSRspQueryExerciseVolumeField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["MaxOrderVolumeUnit"] = task_data->MaxOrderVolumeUnit;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQueryExerciseVolume(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCombVolume(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryCombVolumeField *task_data = (CHSRspQryCombVolumeField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["CombStrategyID"] = toUtf(task_data->CombStrategyID);
		data["CombPositionID"] = toUtf(task_data->CombPositionID);
		data["CombDirection"] = task_data->CombDirection;
		data["MaxOrderVolumeUnit"] = task_data->MaxOrderVolumeUnit;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombVolume(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryPositionField *task_data = (CHSRspQryPositionField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Direction"] = task_data->Direction;
		data["HedgeType"] = task_data->HedgeType;
		data["YdPositionVolume"] = task_data->YdPositionVolume;
		data["PositionVolume"] = task_data->PositionVolume;
		data["TodayPositionVolume"] = task_data->TodayPositionVolume;
		data["AvailablePositionVolume"] = task_data->AvailablePositionVolume;
		data["TodayAvailablePositionVolume"] = task_data->TodayAvailablePositionVolume;
		data["PositionMargin"] = task_data->PositionMargin;
		data["Premium"] = task_data->Premium;
		data["Commission"] = task_data->Commission;
		data["OpenFrozenVolume"] = task_data->OpenFrozenVolume;
		data["CloseFrozenVolume"] = task_data->CloseFrozenVolume;
		data["CombVolume"] = task_data->CombVolume;
		data["ExerciseFrozenVolume"] = task_data->ExerciseFrozenVolume;
		data["FrozenMargin"] = task_data->FrozenMargin;
		data["ExerciseFrozenMargin"] = task_data->ExerciseFrozenMargin;
		data["FrozenPremium"] = task_data->FrozenPremium;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["OpenVolume"] = task_data->OpenVolume;
		data["CloseVolume"] = task_data->CloseVolume;
		data["OpenBalance"] = task_data->OpenBalance;
		data["CloseBalance"] = task_data->CloseBalance;
		data["OpenCost"] = task_data->OpenCost;
		data["PositionCost"] = task_data->PositionCost;
		data["PositionProfit"] = task_data->PositionProfit;
		data["CloseProfit"] = task_data->CloseProfit;
		data["OptionsMarketValue"] = task_data->OptionsMarketValue;
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["TASPositionVolume"] = task_data->TASPositionVolume;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPosition(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTradingAccount(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryTradingAccountField *task_data = (CHSRspQryTradingAccountField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["YdBalance"] = task_data->YdBalance;
		data["YdPositionMargin"] = task_data->YdPositionMargin;
		data["YdFundEquity"] = task_data->YdFundEquity;
		data["FundEquity"] = task_data->FundEquity;
		data["OptionsMarketValue"] = task_data->OptionsMarketValue;
		data["Equity"] = task_data->Equity;
		data["AvailableBalance"] = task_data->AvailableBalance;
		data["WithdrawBalance"] = task_data->WithdrawBalance;
		data["Margin"] = task_data->Margin;
		data["FrozenMargin"] = task_data->FrozenMargin;
		data["ExerciseFrozenMargin"] = task_data->ExerciseFrozenMargin;
		data["RiskDegree"] = task_data->RiskDegree;
		data["Premium"] = task_data->Premium;
		data["FrozenPremium"] = task_data->FrozenPremium;
		data["Commission"] = task_data->Commission;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["CloseProfit"] = task_data->CloseProfit;
		data["PositionProfit"] = task_data->PositionProfit;
		data["CloseProfitByDate"] = task_data->CloseProfitByDate;
		data["PositionProfitByDate"] = task_data->PositionProfitByDate;
		data["Deposit"] = task_data->Deposit;
		data["Withdraw"] = task_data->Withdraw;
		data["FundMortgage"] = task_data->FundMortgage;
		data["WarrantMortgage"] = task_data->WarrantMortgage;
		data["FrozenBalance"] = task_data->FrozenBalance;
		data["UnFrozenBalance"] = task_data->UnFrozenBalance;
		data["CurrencyID"] = task_data->CurrencyID;
		data["HedgeRiskDegree"] = task_data->HedgeRiskDegree;
		data["ShUsedBuyQuota"] = task_data->ShUsedBuyQuota;
		data["SzUsedBuyQuota"] = task_data->SzUsedBuyQuota;
		data["ShAvailableBuyQuota"] = task_data->ShAvailableBuyQuota;
		data["SzAvailableBuyQuota"] = task_data->SzAvailableBuyQuota;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingAccount(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSOrderField *task_data = (CHSOrderField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["BrokerOrderID"] = toUtf(task_data->BrokerOrderID);
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeType"] = task_data->HedgeType;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderVolume"] = task_data->OrderVolume;
		data["OrderStatus"] = task_data->OrderStatus;
		data["TradeVolume"] = task_data->TradeVolume;
		data["CancelVolume"] = task_data->CancelVolume;
		data["TradePrice"] = task_data->TradePrice;
		data["TradingDay"] = task_data->TradingDay;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["ReportTime"] = task_data->ReportTime;
		data["OrderCommand"] = task_data->OrderCommand;
		data["MinVolume"] = task_data->MinVolume;
		data["SpringPrice"] = task_data->SpringPrice;
		data["SwapOrderFlag"] = task_data->SwapOrderFlag;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["OrderSource"] = task_data->OrderSource;
		data["CombPositionID"] = toUtf(task_data->CombPositionID);
		data["ExchangeAccountID"] = toUtf(task_data->ExchangeAccountID);
		data["SeatIndex"] = task_data->SeatIndex;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrder(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSTradeField *task_data = (CHSTradeField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["TradeID"] = toUtf(task_data->TradeID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["BrokerOrderID"] = toUtf(task_data->BrokerOrderID);
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeType"] = task_data->HedgeType;
		data["TradeVolume"] = task_data->TradeVolume;
		data["TradePrice"] = task_data->TradePrice;
		data["TradingDay"] = task_data->TradingDay;
		data["TradeTime"] = task_data->TradeTime;
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["CombPositionID"] = toUtf(task_data->CombPositionID);
		data["TradeCommission"] = task_data->TradeCommission;
		data["ExchangeAccountID"] = toUtf(task_data->ExchangeAccountID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTrade(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryExercise(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSExerciseField *task_data = (CHSExerciseField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExerciseOrderSysID"] = toUtf(task_data->ExerciseOrderSysID);
		data["SessionID"] = task_data->SessionID;
		data["ExerciseRef"] = toUtf(task_data->ExerciseRef);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["HedgeType"] = task_data->HedgeType;
		data["ExerciseType"] = task_data->ExerciseType;
		data["OrderVolume"] = task_data->OrderVolume;
		data["OrderStatus"] = task_data->OrderStatus;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["OrderSource"] = task_data->OrderSource;
		data["CloseFlag"] = task_data->CloseFlag;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["ExercisePreFrozenCommission"] = task_data->ExercisePreFrozenCommission;
		data["ExercisePreFrozenMargin"] = task_data->ExercisePreFrozenMargin;
		data["ExerciseBrokerOrderID"] = toUtf(task_data->ExerciseBrokerOrderID);
		data["ExchangeAccountID"] = toUtf(task_data->ExchangeAccountID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExercise(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryLock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSLockField *task_data = (CHSLockField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["LockOrderSysID"] = toUtf(task_data->LockOrderSysID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["LockType"] = task_data->LockType;
		data["OrderVolume"] = task_data->OrderVolume;
		data["OrderStatus"] = task_data->OrderStatus;
		data["TradingDay"] = task_data->TradingDay;
		data["InsertTime"] = task_data->InsertTime;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["OrderSource"] = task_data->OrderSource;
		data["LockRef"] = toUtf(task_data->LockRef);
		data["SessionID"] = task_data->SessionID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryLock(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCombAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSCombActionField *task_data = (CHSCombActionField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CombOrderSysID"] = toUtf(task_data->CombOrderSysID);
		data["CombPositionID"] = toUtf(task_data->CombPositionID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["CombStrategyID"] = toUtf(task_data->CombStrategyID);
		data["Direction"] = task_data->Direction;
		data["CombDirection"] = task_data->CombDirection;
		data["HedgeType"] = task_data->HedgeType;
		data["OrderVolume"] = task_data->OrderVolume;
		data["OrderStatus"] = task_data->OrderStatus;
		data["TradingDay"] = task_data->TradingDay;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["OrderSource"] = task_data->OrderSource;
		data["SecondHedgeType"] = task_data->SecondHedgeType;
		data["CombOrderRef"] = toUtf(task_data->CombOrderRef);
		data["SessionID"] = task_data->SessionID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryForQuote(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSForQuoteField *task_data = (CHSForQuoteField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["TradingDay"] = task_data->TradingDay;
		data["UpdateTime"] = task_data->UpdateTime;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryForQuote(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryQuote(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSQuoteField *task_data = (CHSQuoteField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["QuoteBrokerID"] = toUtf(task_data->QuoteBrokerID);
		data["OrderStatus"] = task_data->OrderStatus;
		data["BidOffsetFlag"] = task_data->BidOffsetFlag;
		data["BidHedgeType"] = task_data->BidHedgeType;
		data["BidOrderPrice"] = task_data->BidOrderPrice;
		data["BidOrderVolume"] = task_data->BidOrderVolume;
		data["AskOffsetFlag"] = task_data->AskOffsetFlag;
		data["AskHedgeType"] = task_data->AskHedgeType;
		data["AskOrderPrice"] = task_data->AskOrderPrice;
		data["AskOrderVolume"] = task_data->AskOrderVolume;
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["QuoteSysID"] = toUtf(task_data->QuoteSysID);
		data["BidOrderSysID"] = toUtf(task_data->BidOrderSysID);
		data["AskOrderSysID"] = toUtf(task_data->AskOrderSysID);
		data["BidBrokerOrderID"] = toUtf(task_data->BidBrokerOrderID);
		data["AskBrokerOrderID"] = toUtf(task_data->AskBrokerOrderID);
		data["BidOrderRef"] = toUtf(task_data->BidOrderRef);
		data["AskOrderRef"] = toUtf(task_data->AskOrderRef);
		data["SessionID"] = task_data->SessionID;
		data["TradingDay"] = task_data->TradingDay;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["ReportTime"] = task_data->ReportTime;
		data["TopOrderType"] = task_data->TopOrderType;
		data["BidOrderStatus"] = task_data->BidOrderStatus;
		data["AskOrderStatus"] = task_data->AskOrderStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryQuote(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryPositionCombineDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryPositionCombineDetailField *task_data = (CHSRspQryPositionCombineDetailField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CombPositionID"] = toUtf(task_data->CombPositionID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["CombStrategyID"] = toUtf(task_data->CombStrategyID);
		data["HedgeType"] = task_data->HedgeType;
		data["Direction"] = task_data->Direction;
		data["YdPositionVolume"] = task_data->YdPositionVolume;
		data["AvailablePositionVolume"] = task_data->AvailablePositionVolume;
		data["TotalCombVolume"] = task_data->TotalCombVolume;
		data["TotalSplitVolume"] = task_data->TotalSplitVolume;
		data["PositionMargin"] = task_data->PositionMargin;
		data["OpenDate"] = task_data->OpenDate;
		data["SecondHedgeType"] = task_data->SecondHedgeType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPositionCombineDetail(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInstrument(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryInstrumentField *task_data = (CHSRspQryInstrumentField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["InstrumentName"] = toUtf(task_data->InstrumentName);
		data["InstrumentEngName"] = toUtf(task_data->InstrumentEngName);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["ProductType"] = task_data->ProductType;
		data["MaxMarketOrderVolume"] = task_data->MaxMarketOrderVolume;
		data["MinMarketOrderVolume"] = task_data->MinMarketOrderVolume;
		data["MaxLimitOrderVolume"] = task_data->MaxLimitOrderVolume;
		data["MinLimitOrderVolume"] = task_data->MinLimitOrderVolume;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["PriceTick"] = task_data->PriceTick;
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["ExercisePrice"] = task_data->ExercisePrice;
		data["OptionsType"] = task_data->OptionsType;
		data["TradingFlag"] = task_data->TradingFlag;
		data["MarketDate"] = task_data->MarketDate;
		data["ExpireDate"] = task_data->ExpireDate;
		data["BeginExerciseDate"] = task_data->BeginExerciseDate;
		data["EndExerciseDate"] = task_data->EndExerciseDate;
		data["BeginDeliveryDate"] = task_data->BeginDeliveryDate;
		data["EndDeliveryDate"] = task_data->EndDeliveryDate;
		data["CurrencyID"] = task_data->CurrencyID;
		data["CombType"] = task_data->CombType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInstrument(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCoveredShort(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryCoveredShortField *task_data = (CHSRspQryCoveredShortField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["CoveredLockVolume"] = task_data->CoveredLockVolume;
		data["CoveredShortVolume"] = task_data->CoveredShortVolume;
		data["CoveredEstimateShortVolume"] = task_data->CoveredEstimateShortVolume;
		data["MsgContent"] = toUtf(task_data->MsgContent);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCoveredShort(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryExerciseAssign(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryExerciseAssignField *task_data = (CHSRspQryExerciseAssignField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["PositionType"] = task_data->PositionType;
		data["OptionsType"] = task_data->OptionsType;
		data["ExercisePrice"] = task_data->ExercisePrice;
		data["ExerciseVolume"] = task_data->ExerciseVolume;
		data["DeliveryVolume"] = task_data->DeliveryVolume;
		data["ExerciseFrozenBalance"] = task_data->ExerciseFrozenBalance;
		data["SettlementBalance"] = task_data->SettlementBalance;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExerciseAssign(data, error, task->task_id, task->task_last);
};

void TdApi::processRspTransfer(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspTransferField *task_data = (CHSRspTransferField*)task->task_data;
		data["TransferSerialID"] = task_data->TransferSerialID;
		data["BankID"] = toUtf(task_data->BankID);
		data["TransferType"] = task_data->TransferType;
		data["OccurBalance"] = task_data->OccurBalance;
		data["CurrencyID"] = task_data->CurrencyID;
		data["TransferOccasion"] = toUtf(task_data->TransferOccasion);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspTransfer(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTransfer(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryTransferField *task_data = (CHSRspQryTransferField*)task->task_data;
		data["TransferSerialID"] = task_data->TransferSerialID;
		data["BankID"] = toUtf(task_data->BankID);
		data["BankName"] = toUtf(task_data->BankName);
		data["BusinessName"] = toUtf(task_data->BusinessName);
		data["OccurBalance"] = task_data->OccurBalance;
		data["PostBalance"] = task_data->PostBalance;
		data["TransferTime"] = task_data->TransferTime;
		data["TransferStatus"] = task_data->TransferStatus;
		data["TransferSource"] = task_data->TransferSource;
		data["Remarks"] = toUtf(task_data->Remarks);
		data["CurrencyID"] = task_data->CurrencyID;
		data["OrderSourceDate"] = task_data->OrderSourceDate;
		data["TradingDay"] = task_data->TradingDay;
		data["TransferOccasion"] = toUtf(task_data->TransferOccasion);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTransfer(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQueryBankBalance(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQueryBankBalanceField *task_data = (CHSRspQueryBankBalanceField*)task->task_data;
		data["TransferSerialID"] = task_data->TransferSerialID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQueryBankBalance(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQueryBankAccount(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQueryBankAccountField *task_data = (CHSRspQueryBankAccountField*)task->task_data;
		data["BankID"] = toUtf(task_data->BankID);
		data["BankName"] = toUtf(task_data->BankName);
		data["BankAccountID"] = toUtf(task_data->BankAccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQueryBankAccount(data, error, task->task_id, task->task_last);
};

void TdApi::processRspMultiCentreFundTrans(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspMultiCentreFundTransField *task_data = (CHSRspMultiCentreFundTransField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = task_data->CurrencyID;
		data["OccurBalance"] = task_data->OccurBalance;
		data["TransDirection"] = task_data->TransDirection;
		data["LocalTransferSerialID"] = task_data->LocalTransferSerialID;
		data["OppositeTransferSerialID"] = task_data->OppositeTransferSerialID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspMultiCentreFundTrans(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQueryBillContent(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQueryBillContentField *task_data = (CHSRspQueryBillContentField*)task->task_data;
		data["BillContent"] = toUtf(task_data->BillContent);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQueryBillContent(data, error, task->task_id, task->task_last);
};

void TdApi::processRspBillConfirm(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspBillConfirmField *task_data = (CHSRspBillConfirmField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["BillConfirmStatus"] = task_data->BillConfirmStatus;
		data["ConfirmDate"] = task_data->ConfirmDate;
		data["ConfirmTime"] = task_data->ConfirmTime;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspBillConfirm(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryMargin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryMarginField *task_data = (CHSRspQryMarginField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["HedgeType"] = task_data->HedgeType;
		data["LongMarginRatio"] = task_data->LongMarginRatio;
		data["LongMargin"] = task_data->LongMargin;
		data["ShortMarginRatio"] = task_data->ShortMarginRatio;
		data["ShortMargin"] = task_data->ShortMargin;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryMargin(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCommission(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryCommissionField *task_data = (CHSRspQryCommissionField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ProductType"] = task_data->ProductType;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["LongOpenCommissionRatio"] = task_data->LongOpenCommissionRatio;
		data["LongOpenCommission"] = task_data->LongOpenCommission;
		data["LongCloseCommissionRatio"] = task_data->LongCloseCommissionRatio;
		data["LongCloseCommission"] = task_data->LongCloseCommission;
		data["LongCloseTodayCommissionRatio"] = task_data->LongCloseTodayCommissionRatio;
		data["LongCloseTodayCommission"] = task_data->LongCloseTodayCommission;
		data["ShortOpenCommissionRatio"] = task_data->ShortOpenCommissionRatio;
		data["ShortOpenCommission"] = task_data->ShortOpenCommission;
		data["ShortCloseCommissionRatio"] = task_data->ShortCloseCommissionRatio;
		data["ShortCloseCommission"] = task_data->ShortCloseCommission;
		data["ShortCloseTodayCommissionRatio"] = task_data->ShortCloseTodayCommissionRatio;
		data["ShortCloseTodayCommission"] = task_data->ShortCloseTodayCommission;
		data["ExerciseCommissionRatio"] = task_data->ExerciseCommissionRatio;
		data["ExerciseCommission"] = task_data->ExerciseCommission;
		data["TradeValueRatio"] = task_data->TradeValueRatio;
		data["StockValue"] = task_data->StockValue;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCommission(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryPositionDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryPositionDetailField *task_data = (CHSRspQryPositionDetailField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["TradeID"] = toUtf(task_data->TradeID);
		data["OpenDate"] = task_data->OpenDate;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Direction"] = task_data->Direction;
		data["HedgeType"] = task_data->HedgeType;
		data["TradeVolume"] = task_data->TradeVolume;
		data["PositionPrice"] = task_data->PositionPrice;
		data["TodayCloseVolume"] = task_data->TodayCloseVolume;
		data["ArbitragePositionID"] = toUtf(task_data->ArbitragePositionID);
		data["LegID"] = task_data->LegID;
		data["TradeType"] = task_data->TradeType;
		data["PositionMargin"] = task_data->PositionMargin;
		data["CombInstrumentID"] = toUtf(task_data->CombInstrumentID);
		data["CurrentPositionVolume"] = task_data->CurrentPositionVolume;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["PositionSerialID"] = task_data->PositionSerialID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPositionDetail(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryExchangeRate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryExchangeRateField *task_data = (CHSRspQryExchangeRateField*)task->task_data;
		data["FromCurrencyID"] = task_data->FromCurrencyID;
		data["ToCurrencyID"] = task_data->ToCurrencyID;
		data["ExchangeRate"] = task_data->ExchangeRate;
		data["FromCurrencyUnit"] = task_data->FromCurrencyUnit;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExchangeRate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySysConfig(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQrySysConfigField *task_data = (CHSRspQrySysConfigField*)task->task_data;
		data["ConfigNo"] = task_data->ConfigNo;
		data["ConfigValue"] = toUtf(task_data->ConfigValue);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySysConfig(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryDepthMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSDepthMarketDataField *task_data = (CHSDepthMarketDataField*)task->task_data;
		data["TradingDay"] = task_data->TradingDay;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["LastPrice"] = task_data->LastPrice;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["TradeVolume"] = task_data->TradeVolume;
		data["TradeBalance"] = task_data->TradeBalance;
		data["OpenInterest"] = task_data->OpenInterest;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PreDelta"] = task_data->PreDelta;
		data["CurrDelta"] = task_data->CurrDelta;
		data["UpdateTime"] = task_data->UpdateTime;
		data["BidPrice1"] = task_data->BidPrice1;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["AveragePrice"] = task_data->AveragePrice;
		data["PreOpenInterest"] = task_data->PreOpenInterest;
		data["InstrumentTradeStatus"] = task_data->InstrumentTradeStatus;
		data["OpenRestriction"] = toUtf(task_data->OpenRestriction);
		data["IOPV"] = task_data->IOPV;
		data["AuctionPrice"] = task_data->AuctionPrice;
		data["SendingTime"] = task_data->SendingTime;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryDepthMarketData(data, error, task->task_id, task->task_last);
};

void TdApi::processRspFundTrans(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspFundTransField *task_data = (CHSRspFundTransField*)task->task_data;
		data["FundTransSerialID"] = task_data->FundTransSerialID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspFundTrans(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryFundTrans(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryFundTransField *task_data = (CHSRspQryFundTransField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["TradingDay"] = task_data->TradingDay;
		data["OccurDate"] = task_data->OccurDate;
		data["OccurTime"] = task_data->OccurTime;
		data["TransferSerialID"] = task_data->TransferSerialID;
		data["CurrencyID"] = task_data->CurrencyID;
		data["OccurBalance"] = task_data->OccurBalance;
		data["PostBalance"] = task_data->PostBalance;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryFundTrans(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryClientNotice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSClientNoticeField *task_data = (CHSClientNoticeField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["MsgBody"] = toUtf(task_data->MsgBody);
		data["MsgTitle"] = toUtf(task_data->MsgTitle);
		data["MsgType"] = task_data->MsgType;
		data["MsgDate"] = task_data->MsgDate;
		data["MsgTime"] = task_data->MsgTime;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryClientNotice(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOptUnderly(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryOptUnderlyField *task_data = (CHSRspQryOptUnderlyField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["UnderlyingType"] = toUtf(task_data->UnderlyingType);
		data["CurrencyID"] = task_data->CurrencyID;
		data["UnderlyingStatus"] = task_data->UnderlyingStatus;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["UnderlyingHighAmount"] = task_data->UnderlyingHighAmount;
		data["UnderlyingLowAmount"] = task_data->UnderlyingLowAmount;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["BuyUnit"] = task_data->BuyUnit;
		data["SellUnit"] = task_data->SellUnit;
		data["PriceStep"] = task_data->PriceStep;
		data["MarketDate"] = task_data->MarketDate;
		data["DelistDate"] = task_data->DelistDate;
		data["UnderlyingMarketHighAmount"] = task_data->UnderlyingMarketHighAmount;
		data["UnderlyingMarketLowAmount"] = task_data->UnderlyingMarketLowAmount;
		data["UnderlyingName"] = toUtf(task_data->UnderlyingName);
		data["MarketBuyUnit"] = task_data->MarketBuyUnit;
		data["MarketSellUnit"] = task_data->MarketSellUnit;
		data["UnderlyingValidDate"] = task_data->UnderlyingValidDate;
		data["UpdateType"] = task_data->UpdateType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOptUnderly(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySecuDepthMarket(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQrySecuDepthMarketField *task_data = (CHSRspQrySecuDepthMarketField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["UnderlyingName"] = toUtf(task_data->UnderlyingName);
		data["LastPrice"] = task_data->LastPrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["UnderlyingPreClosePrice"] = task_data->UnderlyingPreClosePrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["TradeBalance"] = task_data->TradeBalance;
		data["TradeVolume"] = task_data->TradeVolume;
		data["BidPrice1"] = task_data->BidPrice1;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySecuDepthMarket(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryHistOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSOrderField *task_data = (CHSOrderField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["BrokerOrderID"] = toUtf(task_data->BrokerOrderID);
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeType"] = task_data->HedgeType;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderVolume"] = task_data->OrderVolume;
		data["OrderStatus"] = task_data->OrderStatus;
		data["TradeVolume"] = task_data->TradeVolume;
		data["CancelVolume"] = task_data->CancelVolume;
		data["TradePrice"] = task_data->TradePrice;
		data["TradingDay"] = task_data->TradingDay;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["ReportTime"] = task_data->ReportTime;
		data["OrderCommand"] = task_data->OrderCommand;
		data["MinVolume"] = task_data->MinVolume;
		data["SpringPrice"] = task_data->SpringPrice;
		data["SwapOrderFlag"] = task_data->SwapOrderFlag;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["OrderSource"] = task_data->OrderSource;
		data["CombPositionID"] = toUtf(task_data->CombPositionID);
		data["ExchangeAccountID"] = toUtf(task_data->ExchangeAccountID);
		data["SeatIndex"] = task_data->SeatIndex;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryHistOrder(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryHistTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSTradeField *task_data = (CHSTradeField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["TradeID"] = toUtf(task_data->TradeID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["BrokerOrderID"] = toUtf(task_data->BrokerOrderID);
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeType"] = task_data->HedgeType;
		data["TradeVolume"] = task_data->TradeVolume;
		data["TradePrice"] = task_data->TradePrice;
		data["TradingDay"] = task_data->TradingDay;
		data["TradeTime"] = task_data->TradeTime;
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["CombPositionID"] = toUtf(task_data->CombPositionID);
		data["TradeCommission"] = task_data->TradeCommission;
		data["ExchangeAccountID"] = toUtf(task_data->ExchangeAccountID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryHistTrade(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCombInstrument(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryCombInstrumentField *task_data = (CHSRspQryCombInstrumentField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Direction"] = task_data->Direction;
		data["SecondDirection"] = task_data->SecondDirection;
		data["CombStrategyType"] = task_data->CombStrategyType;
		data["CombMarginCoeff"] = task_data->CombMarginCoeff;
		data["PriorityLevel"] = task_data->PriorityLevel;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombInstrument(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySeatID(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQrySeatIDField *task_data = (CHSRspQrySeatIDField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["SeatIndex"] = task_data->SeatIndex;
		data["SeatID"] = toUtf(task_data->SeatID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySeatID(data, error, task->task_id, task->task_last);
};

void TdApi::processRspOptionSelfClose(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspOptionSelfCloseField *task_data = (CHSRspOptionSelfCloseField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderVolume"] = task_data->OrderVolume;
		data["SelfCloseType"] = task_data->SelfCloseType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOptionSelfClose(data, error, task->task_id, task->task_last);
};

void TdApi::processRspOptionSelfCloseAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspOptionSelfCloseActionField *task_data = (CHSRspOptionSelfCloseActionField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["SelfCloseType"] = task_data->SelfCloseType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOptionSelfCloseAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOptionSelfCloseResult(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspQryOptionSelfCloseResultField *task_data = (CHSRspQryOptionSelfCloseResultField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["SelfCloseType"] = task_data->SelfCloseType;
		data["OrderVolume"] = task_data->OrderVolume;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOptionSelfCloseResult(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOptionSelfClose(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSOptionSelfCloseField *task_data = (CHSOptionSelfCloseField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderVolume"] = task_data->OrderVolume;
		data["SelfCloseType"] = task_data->SelfCloseType;
		data["OrderStatus"] = task_data->OrderStatus;
		data["SetSelfCloseType"] = task_data->SetSelfCloseType;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["SelfCloseOrderSysID"] = toUtf(task_data->SelfCloseOrderSysID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOptionSelfClose(data, error, task->task_id, task->task_last);
};

void TdApi::processRspOptQuoteInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspOptQuoteInsertField *task_data = (CHSRspOptQuoteInsertField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["BidOffsetFlag"] = task_data->BidOffsetFlag;
		data["BidOrderPrice"] = task_data->BidOrderPrice;
		data["BidOrderVolume"] = task_data->BidOrderVolume;
		data["AskOffsetFlag"] = task_data->AskOffsetFlag;
		data["AskOrderPrice"] = task_data->AskOrderPrice;
		data["AskOrderVolume"] = task_data->AskOrderVolume;
		data["QuoteBrokerID"] = toUtf(task_data->QuoteBrokerID);
		data["InsertTime"] = task_data->InsertTime;
		data["BidOrderStatus"] = task_data->BidOrderStatus;
		data["AskOrderStatus"] = task_data->AskOrderStatus;
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["OrderStatus"] = task_data->OrderStatus;
		data["SessionID"] = task_data->SessionID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOptQuoteInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspOptQuoteAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSRspOptQuoteActionField *task_data = (CHSRspOptQuoteActionField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["InsertTime"] = task_data->InsertTime;
		data["QuoteBrokerID"] = toUtf(task_data->QuoteBrokerID);
		data["BidWithdrawVolume"] = task_data->BidWithdrawVolume;
		data["AskWithdrawVolume"] = task_data->AskWithdrawVolume;
		data["BidOrderStatus"] = task_data->BidOrderStatus;
		data["AskOrderStatus"] = task_data->AskOrderStatus;
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["OrderStatus"] = task_data->OrderStatus;
		data["SessionID"] = task_data->SessionID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOptQuoteAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOptQuote(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSOptQuoteField *task_data = (CHSOptQuoteField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["QuoteBrokerID"] = toUtf(task_data->QuoteBrokerID);
		data["BidOffsetFlag"] = task_data->BidOffsetFlag;
		data["BidOrderPrice"] = task_data->BidOrderPrice;
		data["BidOrderVolume"] = task_data->BidOrderVolume;
		data["BidTradePrice"] = task_data->BidTradePrice;
		data["BidTradeVolume"] = task_data->BidTradeVolume;
		data["BidCancelVolume"] = task_data->BidCancelVolume;
		data["BidBrokerOrderID"] = toUtf(task_data->BidBrokerOrderID);
		data["BidOrderStatus"] = task_data->BidOrderStatus;
		data["AskOffsetFlag"] = task_data->AskOffsetFlag;
		data["AskOrderPrice"] = task_data->AskOrderPrice;
		data["AskOrderVolume"] = task_data->AskOrderVolume;
		data["AskTradePrice"] = task_data->AskTradePrice;
		data["AskTradeVolume"] = task_data->AskTradeVolume;
		data["AskCancelVolume"] = task_data->AskCancelVolume;
		data["AskBrokerOrderID"] = toUtf(task_data->AskBrokerOrderID);
		data["AskOrderStatus"] = task_data->AskOrderStatus;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["TradingDay"] = task_data->TradingDay;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["ReportTime"] = task_data->ReportTime;
		data["SessionID"] = task_data->SessionID;
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["OrderStatus"] = task_data->OrderStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSRspInfoField *task_error = (CHSRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOptQuote(data, error, task->task_id, task->task_last);
};

void TdApi::processRtnTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSTradeField *task_data = (CHSTradeField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["TradeID"] = toUtf(task_data->TradeID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["BrokerOrderID"] = toUtf(task_data->BrokerOrderID);
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeType"] = task_data->HedgeType;
		data["TradeVolume"] = task_data->TradeVolume;
		data["TradePrice"] = task_data->TradePrice;
		data["TradingDay"] = task_data->TradingDay;
		data["TradeTime"] = task_data->TradeTime;
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["CombPositionID"] = toUtf(task_data->CombPositionID);
		data["TradeCommission"] = task_data->TradeCommission;
		data["ExchangeAccountID"] = toUtf(task_data->ExchangeAccountID);
		delete task_data;
	}
	this->onRtnTrade(data);
};

void TdApi::processRtnOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSOrderField *task_data = (CHSOrderField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["BrokerOrderID"] = toUtf(task_data->BrokerOrderID);
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeType"] = task_data->HedgeType;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderVolume"] = task_data->OrderVolume;
		data["OrderStatus"] = task_data->OrderStatus;
		data["TradeVolume"] = task_data->TradeVolume;
		data["CancelVolume"] = task_data->CancelVolume;
		data["TradePrice"] = task_data->TradePrice;
		data["TradingDay"] = task_data->TradingDay;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["ReportTime"] = task_data->ReportTime;
		data["OrderCommand"] = task_data->OrderCommand;
		data["MinVolume"] = task_data->MinVolume;
		data["SpringPrice"] = task_data->SpringPrice;
		data["SwapOrderFlag"] = task_data->SwapOrderFlag;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["OrderSource"] = task_data->OrderSource;
		data["CombPositionID"] = toUtf(task_data->CombPositionID);
		data["ExchangeAccountID"] = toUtf(task_data->ExchangeAccountID);
		data["SeatIndex"] = task_data->SeatIndex;
		delete task_data;
	}
	this->onRtnOrder(data);
};

void TdApi::processRtnExercise(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSExerciseField *task_data = (CHSExerciseField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExerciseOrderSysID"] = toUtf(task_data->ExerciseOrderSysID);
		data["SessionID"] = task_data->SessionID;
		data["ExerciseRef"] = toUtf(task_data->ExerciseRef);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["HedgeType"] = task_data->HedgeType;
		data["ExerciseType"] = task_data->ExerciseType;
		data["OrderVolume"] = task_data->OrderVolume;
		data["OrderStatus"] = task_data->OrderStatus;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["OrderSource"] = task_data->OrderSource;
		data["CloseFlag"] = task_data->CloseFlag;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["ExercisePreFrozenCommission"] = task_data->ExercisePreFrozenCommission;
		data["ExercisePreFrozenMargin"] = task_data->ExercisePreFrozenMargin;
		data["ExerciseBrokerOrderID"] = toUtf(task_data->ExerciseBrokerOrderID);
		data["ExchangeAccountID"] = toUtf(task_data->ExchangeAccountID);
		delete task_data;
	}
	this->onRtnExercise(data);
};

void TdApi::processRtnCombAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSCombActionField *task_data = (CHSCombActionField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CombOrderSysID"] = toUtf(task_data->CombOrderSysID);
		data["CombPositionID"] = toUtf(task_data->CombPositionID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["CombStrategyID"] = toUtf(task_data->CombStrategyID);
		data["Direction"] = task_data->Direction;
		data["CombDirection"] = task_data->CombDirection;
		data["HedgeType"] = task_data->HedgeType;
		data["OrderVolume"] = task_data->OrderVolume;
		data["OrderStatus"] = task_data->OrderStatus;
		data["TradingDay"] = task_data->TradingDay;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["OrderSource"] = task_data->OrderSource;
		data["SecondHedgeType"] = task_data->SecondHedgeType;
		data["CombOrderRef"] = toUtf(task_data->CombOrderRef);
		data["SessionID"] = task_data->SessionID;
		delete task_data;
	}
	this->onRtnCombAction(data);
};

void TdApi::processRtnLock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSLockField *task_data = (CHSLockField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["LockOrderSysID"] = toUtf(task_data->LockOrderSysID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["LockType"] = task_data->LockType;
		data["OrderVolume"] = task_data->OrderVolume;
		data["OrderStatus"] = task_data->OrderStatus;
		data["TradingDay"] = task_data->TradingDay;
		data["InsertTime"] = task_data->InsertTime;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["OrderSource"] = task_data->OrderSource;
		data["LockRef"] = toUtf(task_data->LockRef);
		data["SessionID"] = task_data->SessionID;
		delete task_data;
	}
	this->onRtnLock(data);
};

void TdApi::processErrRtnOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSOrderActionField *task_data = (CHSOrderActionField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["BrokerOrderID"] = toUtf(task_data->BrokerOrderID);
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["OrderActionRef"] = toUtf(task_data->OrderActionRef);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeType"] = task_data->HedgeType;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderVolume"] = task_data->OrderVolume;
		data["OrderActionStatus"] = task_data->OrderActionStatus;
		data["OrderStatus"] = task_data->OrderStatus;
		data["TradingDay"] = task_data->TradingDay;
		data["ActionDate"] = task_data->ActionDate;
		data["ActionTime"] = task_data->ActionTime;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["OrderSource"] = task_data->OrderSource;
		delete task_data;
	}
	this->onErrRtnOrderAction(data);
};

void TdApi::processRtnClientNotice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSClientNoticeField *task_data = (CHSClientNoticeField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["MsgBody"] = toUtf(task_data->MsgBody);
		data["MsgTitle"] = toUtf(task_data->MsgTitle);
		data["MsgType"] = task_data->MsgType;
		data["MsgDate"] = task_data->MsgDate;
		data["MsgTime"] = task_data->MsgTime;
		delete task_data;
	}
	this->onRtnClientNotice(data);
};


void TdApi::processRtnForQuote(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSForQuoteField *task_data = (CHSForQuoteField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["TradingDay"] = task_data->TradingDay;
		data["UpdateTime"] = task_data->UpdateTime;
		delete task_data;
	}
	this->onRtnForQuote(data);
};

void TdApi::processRtnQuote(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSQuoteField *task_data = (CHSQuoteField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["QuoteBrokerID"] = toUtf(task_data->QuoteBrokerID);
		data["OrderStatus"] = task_data->OrderStatus;
		data["BidOffsetFlag"] = task_data->BidOffsetFlag;
		data["BidHedgeType"] = task_data->BidHedgeType;
		data["BidOrderPrice"] = task_data->BidOrderPrice;
		data["BidOrderVolume"] = task_data->BidOrderVolume;
		data["AskOffsetFlag"] = task_data->AskOffsetFlag;
		data["AskHedgeType"] = task_data->AskHedgeType;
		data["AskOrderPrice"] = task_data->AskOrderPrice;
		data["AskOrderVolume"] = task_data->AskOrderVolume;
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["QuoteSysID"] = toUtf(task_data->QuoteSysID);
		data["BidOrderSysID"] = toUtf(task_data->BidOrderSysID);
		data["AskOrderSysID"] = toUtf(task_data->AskOrderSysID);
		data["BidBrokerOrderID"] = toUtf(task_data->BidBrokerOrderID);
		data["AskBrokerOrderID"] = toUtf(task_data->AskBrokerOrderID);
		data["BidOrderRef"] = toUtf(task_data->BidOrderRef);
		data["AskOrderRef"] = toUtf(task_data->AskOrderRef);
		data["SessionID"] = task_data->SessionID;
		data["TradingDay"] = task_data->TradingDay;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["ReportTime"] = task_data->ReportTime;
		data["TopOrderType"] = task_data->TopOrderType;
		data["BidOrderStatus"] = task_data->BidOrderStatus;
		data["AskOrderStatus"] = task_data->AskOrderStatus;
		delete task_data;
	}
	this->onRtnQuote(data);
};

void TdApi::processRtnExchangeStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSExchangeStatusField *task_data = (CHSExchangeStatusField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ExchangeStatus"] = task_data->ExchangeStatus;
		data["TradingFlag"] = task_data->TradingFlag;
		delete task_data;
	}
	this->onRtnExchangeStatus(data);
};

void TdApi::processRtnProductStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSProductStatusField *task_data = (CHSProductStatusField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ProductType"] = task_data->ProductType;
		data["ProductID"] = toUtf(task_data->ProductID);
		data["TradingFlag"] = task_data->TradingFlag;
		data["ProductStatus"] = task_data->ProductStatus;
		delete task_data;
	}
	this->onRtnProductStatus(data);
};

void TdApi::processRtnOptionSelfClose(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSOptionSelfCloseField *task_data = (CHSOptionSelfCloseField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderVolume"] = task_data->OrderVolume;
		data["SelfCloseType"] = task_data->SelfCloseType;
		data["OrderStatus"] = task_data->OrderStatus;
		data["SetSelfCloseType"] = task_data->SetSelfCloseType;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["SelfCloseOrderSysID"] = toUtf(task_data->SelfCloseOrderSysID);
		delete task_data;
	}
	this->onRtnOptionSelfClose(data);
};

void TdApi::processRtnOptQuote(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSOptQuoteField *task_data = (CHSOptQuoteField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["QuoteBrokerID"] = toUtf(task_data->QuoteBrokerID);
		data["BidOffsetFlag"] = task_data->BidOffsetFlag;
		data["BidOrderPrice"] = task_data->BidOrderPrice;
		data["BidOrderVolume"] = task_data->BidOrderVolume;
		data["BidTradePrice"] = task_data->BidTradePrice;
		data["BidTradeVolume"] = task_data->BidTradeVolume;
		data["BidCancelVolume"] = task_data->BidCancelVolume;
		data["BidBrokerOrderID"] = toUtf(task_data->BidBrokerOrderID);
		data["BidOrderStatus"] = task_data->BidOrderStatus;
		data["AskOffsetFlag"] = task_data->AskOffsetFlag;
		data["AskOrderPrice"] = task_data->AskOrderPrice;
		data["AskOrderVolume"] = task_data->AskOrderVolume;
		data["AskTradePrice"] = task_data->AskTradePrice;
		data["AskTradeVolume"] = task_data->AskTradeVolume;
		data["AskCancelVolume"] = task_data->AskCancelVolume;
		data["AskBrokerOrderID"] = toUtf(task_data->AskBrokerOrderID);
		data["AskOrderStatus"] = task_data->AskOrderStatus;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["TradingDay"] = task_data->TradingDay;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["ReportTime"] = task_data->ReportTime;
		data["SessionID"] = task_data->SessionID;
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["OrderStatus"] = task_data->OrderStatus;
		delete task_data;
	}
	this->onRtnOptQuote(data);
};

///-------------------------------------------------------------------------------------
///��������
///-------------------------------------------------------------------------------------

void TdApi::newTradeApi(string pszFlowPath)
{
	this->api = NewTradeApi(pszFlowPath.c_str());
	this->api->RegisterSpi(this);
};

int TdApi::init(string pszLicFile, string pszSafeLevel, string pszPwd, string pszSslFile, string pszSslPwd)
{
	this->active = true;
	this->task_thread = thread(&TdApi::processTask, this);

	int i = this->api->Init(pszLicFile.c_str(), pszSafeLevel.c_str(), pszPwd.c_str(), pszSslFile.c_str(), pszSslPwd.c_str());
	return i;
};

int TdApi::join()
{
	int i = this->api->Join();
	return i;
};

int TdApi::exit()
{
	this->active = false;
	this->task_queue.terminate();
	this->task_thread.join();

	this->api->RegisterSpi(NULL);
	this->api->ReleaseApi();
	this->api = NULL;
	return 1;
};

int TdApi::rgisterSubModel(int eSubType)
{
	int i = this->api->RegisterSubModel((SUB_TERT_TYPE)eSubType);
	return i;
};

int TdApi::registerFront(string pszFrontAddress)
{
	int i = this->api->RegisterFront(pszFrontAddress.c_str());
	return i;
};

int TdApi::registerFensServer(string pszFensAddress, string pszAccountID)
{
	int i = this->api->RegisterFensServer(pszFensAddress.c_str(), pszAccountID.c_str());
	return i;
};

string TdApi::getApiErrorMsg(int nErrorCode)
{
	string error = toUtf(this->api->GetApiErrorMsg(nErrorCode));
	return error;
};

int TdApi::getTradingDate()
{
	int day = this->api->GetTradingDate();
	return day;
};

int TdApi::reqAuthenticate(const dict &req, int reqid)
{
	CHSReqAuthenticateField myreq = CHSReqAuthenticateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "Password", myreq.Password);
	getString(req, "AppID", myreq.AppID);
	getString(req, "AuthCode", myreq.AuthCode);
	int i = this->api->ReqAuthenticate(&myreq, reqid);
	return i;
};

int TdApi::reqSubmitUserSystemInfo(const dict &req, int reqid)
{
	CHSReqUserSystemInfoField myreq = CHSReqUserSystemInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AppLoginTime", myreq.AppLoginTime);
	getString(req, "AppPublicAdrr", myreq.AppPublicAdrr);
	getString(req, "AppSysInfo", myreq.AppSysInfo);
	getString(req, "AppSysInfoIntegrity", myreq.AppSysInfoIntegrity);
	getChar(req, "AppAbnormalType", &myreq.AppAbnormalType);
	int i = this->api->ReqSubmitUserSystemInfo(&myreq, reqid);
	return i;
};

int TdApi::reqUserLogin(const dict &req, int reqid)
{
	CHSReqUserLoginField myreq = CHSReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "Password", myreq.Password);
	getChar(req, "UserApplicationType", &myreq.UserApplicationType);
	getString(req, "UserApplicationInfo", myreq.UserApplicationInfo);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "UserStationInfo", myreq.UserStationInfo);
	int i = this->api->ReqUserLogin(&myreq, reqid);
	return i;
};

int TdApi::reqUserPasswordUpdate(const dict &req, int reqid)
{
	CHSReqUserPasswordUpdateField myreq = CHSReqUserPasswordUpdateField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "PasswordType", &myreq.PasswordType);
	getString(req, "Password", myreq.Password);
	getString(req, "NewPassword", myreq.NewPassword);
	int i = this->api->ReqUserPasswordUpdate(&myreq, reqid);
	return i;
};

int TdApi::reqOrderInsert(const dict &req, int reqid)
{
	CHSReqOrderInsertField myreq = CHSReqOrderInsertField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "OrderRef", myreq.OrderRef);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "Direction", &myreq.Direction);
	getChar(req, "OffsetFlag", &myreq.OffsetFlag);
	getChar(req, "HedgeType", &myreq.HedgeType);
	getDouble(req, "OrderPrice", &myreq.OrderPrice);
	getDouble(req, "OrderVolume", &myreq.OrderVolume);
	getInt32(req, "OrderCommand", &myreq.OrderCommand);
	getDouble(req, "MinVolume", &myreq.MinVolume);
	getDouble(req, "SpringPrice", &myreq.SpringPrice);
	getChar(req, "SwapOrderFlag", &myreq.SwapOrderFlag);
	getString(req, "CombPositionID", myreq.CombPositionID);
	getString(req, "ExchangeAccountID", myreq.ExchangeAccountID);
	getInt32(req, "SeatIndex", &myreq.SeatIndex);
	int i = this->api->ReqOrderInsert(&myreq, reqid);
	return i;
};

int TdApi::reqOrderAction(const dict &req, int reqid)
{
	CHSReqOrderActionField myreq = CHSReqOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "OrderSysID", myreq.OrderSysID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getInt32(req, "SessionID", &myreq.SessionID);
	getString(req, "OrderRef", myreq.OrderRef);
	getString(req, "OrderActionRef", myreq.OrderActionRef);
	int i = this->api->ReqOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqExerciseOrderInsert(const dict &req, int reqid)
{
	CHSReqExerciseOrderInsertField myreq = CHSReqExerciseOrderInsertField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExerciseRef", myreq.ExerciseRef);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getDouble(req, "OrderVolume", &myreq.OrderVolume);
	getChar(req, "ExerciseType", &myreq.ExerciseType);
	getChar(req, "HedgeType", &myreq.HedgeType);
	getChar(req, "OffsetFlag", &myreq.OffsetFlag);
	getChar(req, "CloseFlag", &myreq.CloseFlag);
	int i = this->api->ReqExerciseOrderInsert(&myreq, reqid);
	return i;
};

int TdApi::reqExerciseOrderAction(const dict &req, int reqid)
{
	CHSReqExerciseOrderActionField myreq = CHSReqExerciseOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ExerciseOrderSysID", myreq.ExerciseOrderSysID);
	getString(req, "ExerciseRef", myreq.ExerciseRef);
	getInt32(req, "SessionID", &myreq.SessionID);
	getString(req, "ExecOrderActionRef", myreq.ExecOrderActionRef);
	int i = this->api->ReqExerciseOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqLockInsert(const dict &req, int reqid)
{
	CHSReqLockInsertField myreq = CHSReqLockInsertField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "UnderlyingInstrID", myreq.UnderlyingInstrID);
	getChar(req, "LockType", &myreq.LockType);
	getDouble(req, "OrderVolume", &myreq.OrderVolume);
	getString(req, "LockRef", myreq.LockRef);
	int i = this->api->ReqLockInsert(&myreq, reqid);
	return i;
};

int TdApi::reqForQuoteInsert(const dict &req, int reqid)
{
	CHSReqForQuoteInsertField myreq = CHSReqForQuoteInsertField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqForQuoteInsert(&myreq, reqid);
	return i;
};

int TdApi::reqQuoteInsert(const dict &req, int reqid)
{
	CHSReqQuoteInsertField myreq = CHSReqQuoteInsertField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "BidOffsetFlag", &myreq.BidOffsetFlag);
	getChar(req, "BidHedgeType", &myreq.BidHedgeType);
	getDouble(req, "BidOrderPrice", &myreq.BidOrderPrice);
	getDouble(req, "BidOrderVolume", &myreq.BidOrderVolume);
	getString(req, "BidOrderRef", myreq.BidOrderRef);
	getChar(req, "AskOffsetFlag", &myreq.AskOffsetFlag);
	getChar(req, "AskHedgeType", &myreq.AskHedgeType);
	getDouble(req, "AskOrderPrice", &myreq.AskOrderPrice);
	getDouble(req, "AskOrderVolume", &myreq.AskOrderVolume);
	getString(req, "AskOrderRef", myreq.AskOrderRef);
	getString(req, "ForQuoteSysID", myreq.ForQuoteSysID);
	getString(req, "QuoteRef", myreq.QuoteRef);
	getChar(req, "TopOrderType", &myreq.TopOrderType);
	getString(req, "QuoteSysID", myreq.QuoteSysID);
	int i = this->api->ReqQuoteInsert(&myreq, reqid);
	return i;
};

int TdApi::reqQuoteAction(const dict &req, int reqid)
{
	CHSReqQuoteActionField myreq = CHSReqQuoteActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "QuoteSysID", myreq.QuoteSysID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getInt32(req, "SessionID", &myreq.SessionID);
	getString(req, "QuoteRef", myreq.QuoteRef);
	getString(req, "QuoteActionRef", myreq.QuoteActionRef);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getDouble(req, "BidWithdrawVolume", &myreq.BidWithdrawVolume);
	getDouble(req, "AskWithdrawVolume", &myreq.AskWithdrawVolume);
	int i = this->api->ReqQuoteAction(&myreq, reqid);
	return i;
};

int TdApi::reqCombActionInsert(const dict &req, int reqid)
{
	CHSReqCombActionInsertField myreq = CHSReqCombActionInsertField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "CombStrategyID", myreq.CombStrategyID);
	getString(req, "CombPositionID", myreq.CombPositionID);
	getChar(req, "CombDirection", &myreq.CombDirection);
	getDouble(req, "OrderVolume", &myreq.OrderVolume);
	getChar(req, "HedgeType", &myreq.HedgeType);
	getChar(req, "Direction", &myreq.Direction);
	getChar(req, "SecondHedgeType", &myreq.SecondHedgeType);
	getString(req, "CombOrderRef", myreq.CombOrderRef);
	int i = this->api->ReqCombActionInsert(&myreq, reqid);
	return i;
};

int TdApi::reqQueryMaxOrderVolume(const dict &req, int reqid)
{
	CHSReqQueryMaxOrderVolumeField myreq = CHSReqQueryMaxOrderVolumeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getInt32(req, "OrderCommand", &myreq.OrderCommand);
	getChar(req, "Direction", &myreq.Direction);
	getChar(req, "OffsetFlag", &myreq.OffsetFlag);
	getChar(req, "HedgeType", &myreq.HedgeType);
	getDouble(req, "OrderPrice", &myreq.OrderPrice);
	getString(req, "CombPositionID", myreq.CombPositionID);
	int i = this->api->ReqQueryMaxOrderVolume(&myreq, reqid);
	return i;
};

int TdApi::reqQryLockVolume(const dict &req, int reqid)
{
	CHSReqQryLockVolumeField myreq = CHSReqQryLockVolumeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "UnderlyingInstrID", myreq.UnderlyingInstrID);
	getChar(req, "LockType", &myreq.LockType);
	int i = this->api->ReqQryLockVolume(&myreq, reqid);
	return i;
};

int TdApi::reqQueryExerciseVolume(const dict &req, int reqid)
{
	CHSReqQueryExerciseVolumeField myreq = CHSReqQueryExerciseVolumeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQueryExerciseVolume(&myreq, reqid);
	return i;
};

int TdApi::reqQryCombVolume(const dict &req, int reqid)
{
	CHSReqQryCombVolumeField myreq = CHSReqQryCombVolumeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "CombStrategyID", myreq.CombStrategyID);
	getString(req, "CombPositionID", myreq.CombPositionID);
	getChar(req, "CombDirection", &myreq.CombDirection);
	int i = this->api->ReqQryCombVolume(&myreq, reqid);
	return i;
};

int TdApi::reqQryPosition(const dict &req, int reqid)
{
	CHSReqQryPositionField myreq = CHSReqQryPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryPosition(&myreq, reqid);
	return i;
};

int TdApi::reqQryTradingAccount(const dict &req, int reqid)
{
	CHSReqQryTradingAccountField myreq = CHSReqQryTradingAccountField();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->ReqQryTradingAccount(&myreq, reqid);
	return i;
};

int TdApi::reqQryOrder(const dict &req, int reqid)
{
	CHSReqQryOrderField myreq = CHSReqQryOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getString(req, "ExchangeAccountID", myreq.ExchangeAccountID);
	int i = this->api->ReqQryOrder(&myreq, reqid);
	return i;
};

int TdApi::reqQryTrade(const dict &req, int reqid)
{
	CHSReqQryTradeField myreq = CHSReqQryTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ExchangeAccountID", myreq.ExchangeAccountID);
	int i = this->api->ReqQryTrade(&myreq, reqid);
	return i;
};

int TdApi::reqQryExercise(const dict &req, int reqid)
{
	CHSReqQryExerciseField myreq = CHSReqQryExerciseField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ExerciseOrderSysID", myreq.ExerciseOrderSysID);
	int i = this->api->ReqQryExercise(&myreq, reqid);
	return i;
};

int TdApi::reqQryLock(const dict &req, int reqid)
{
	CHSReqQryLockField myreq = CHSReqQryLockField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "UnderlyingInstrID", myreq.UnderlyingInstrID);
	getString(req, "LockOrderSysID", myreq.LockOrderSysID);
	int i = this->api->ReqQryLock(&myreq, reqid);
	return i;
};

int TdApi::reqQryCombAction(const dict &req, int reqid)
{
	CHSReqQryCombActionField myreq = CHSReqQryCombActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "CombOrderSysID", myreq.CombOrderSysID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryCombAction(&myreq, reqid);
	return i;
};

int TdApi::reqQryForQuote(const dict &req, int reqid)
{
	CHSReqQryForQuoteField myreq = CHSReqQryForQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ForQuoteSysID", myreq.ForQuoteSysID);
	int i = this->api->ReqQryForQuote(&myreq, reqid);
	return i;
};

int TdApi::reqQryQuote(const dict &req, int reqid)
{
	CHSReqQryQuoteField myreq = CHSReqQryQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "QuoteSysID", myreq.QuoteSysID);
	getString(req, "QuoteBrokerID", myreq.QuoteBrokerID);
	int i = this->api->ReqQryQuote(&myreq, reqid);
	return i;
};

int TdApi::reqQryPositionCombineDetail(const dict &req, int reqid)
{
	CHSReqQryPositionCombineDetailField myreq = CHSReqQryPositionCombineDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "CombStrategyID", myreq.CombStrategyID);
	int i = this->api->ReqQryPositionCombineDetail(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrument(const dict &req, int reqid)
{
	CHSReqQryInstrumentField myreq = CHSReqQryInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInstrument(&myreq, reqid);
	return i;
};

int TdApi::reqQryCoveredShort(const dict &req, int reqid)
{
	CHSReqQryCoveredShortField myreq = CHSReqQryCoveredShortField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	int i = this->api->ReqQryCoveredShort(&myreq, reqid);
	return i;
};

int TdApi::reqQryExerciseAssign(const dict &req, int reqid)
{
	CHSReqQryExerciseAssignField myreq = CHSReqQryExerciseAssignField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "PositionType", &myreq.PositionType);
	int i = this->api->ReqQryExerciseAssign(&myreq, reqid);
	return i;
};

int TdApi::reqTransfer(const dict &req, int reqid)
{
	CHSReqTransferField myreq = CHSReqTransferField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BankID", myreq.BankID);
	getChar(req, "TransferType", &myreq.TransferType);
	getDouble(req, "OccurBalance", &myreq.OccurBalance);
	getString(req, "FundPassword", myreq.FundPassword);
	getString(req, "BankPassword", myreq.BankPassword);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getString(req, "TransferOccasion", myreq.TransferOccasion);
	int i = this->api->ReqTransfer(&myreq, reqid);
	return i;
};

int TdApi::reqQryTransfer(const dict &req, int reqid)
{
	CHSReqQryTransferField myreq = CHSReqQryTransferField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BankID", myreq.BankID);
	getInt32(req, "TransferSerialID", &myreq.TransferSerialID);
	int i = this->api->ReqQryTransfer(&myreq, reqid);
	return i;
};

int TdApi::reqQueryBankBalance(const dict &req, int reqid)
{
	CHSReqQueryBankBalanceField myreq = CHSReqQueryBankBalanceField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BankID", myreq.BankID);
	getString(req, "FundPassword", myreq.FundPassword);
	getString(req, "BankPassword", myreq.BankPassword);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	int i = this->api->ReqQueryBankBalance(&myreq, reqid);
	return i;
};

int TdApi::reqQueryBankAccount(const dict &req, int reqid)
{
	CHSReqQueryBankAccountField myreq = CHSReqQueryBankAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BankID", myreq.BankID);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	int i = this->api->ReqQueryBankAccount(&myreq, reqid);
	return i;
};

int TdApi::reqMultiCentreFundTrans(const dict &req, int reqid)
{
	CHSReqMultiCentreFundTransField myreq = CHSReqMultiCentreFundTransField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getDouble(req, "OccurBalance", &myreq.OccurBalance);
	getChar(req, "TransDirection", &myreq.TransDirection);
	int i = this->api->ReqMultiCentreFundTrans(&myreq, reqid);
	return i;
};

int TdApi::reqQueryBillContent(const dict &req, int reqid)
{
	CHSReqQueryBillContentField myreq = CHSReqQueryBillContentField();
	memset(&myreq, 0, sizeof(myreq));
	getInt32(req, "BeginDate", &myreq.BeginDate);
	getInt32(req, "EndDate", &myreq.EndDate);
	int i = this->api->ReqQueryBillContent(&myreq, reqid);
	return i;
};

int TdApi::reqBillConfirm(const dict &req, int reqid)
{
	CHSReqBillConfirmField myreq = CHSReqBillConfirmField();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->ReqBillConfirm(&myreq, reqid);
	return i;
};

int TdApi::reqQryMargin(const dict &req, int reqid)
{
	CHSReqQryMarginField myreq = CHSReqQryMarginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "UnderlyingInstrID", myreq.UnderlyingInstrID);
	getChar(req, "HedgeType", &myreq.HedgeType);
	int i = this->api->ReqQryMargin(&myreq, reqid);
	return i;
};

int TdApi::reqQryCommission(const dict &req, int reqid)
{
	CHSReqQryCommissionField myreq = CHSReqQryCommissionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getChar(req, "ProductType", &myreq.ProductType);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "UnderlyingInstrID", myreq.UnderlyingInstrID);
	int i = this->api->ReqQryCommission(&myreq, reqid);
	return i;
};

int TdApi::reqQryExchangeRate(const dict &req, int reqid)
{
	CHSReqQryExchangeRateField myreq = CHSReqQryExchangeRateField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "FromCurrencyID", &myreq.FromCurrencyID);
	getChar(req, "ToCurrencyID", &myreq.ToCurrencyID);
	int i = this->api->ReqQryExchangeRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryPositionDetail(const dict &req, int reqid)
{
	CHSReqQryPositionDetailField myreq = CHSReqQryPositionDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryPositionDetail(&myreq, reqid);
	return i;
};

int TdApi::reqQrySysConfig(const dict &req, int reqid)
{
	CHSReqQrySysConfigField myreq = CHSReqQrySysConfigField();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->ReqQrySysConfig(&myreq, reqid);
	return i;
};

int TdApi::reqQryDepthMarketData(const dict &req, int reqid)
{
	CHSReqQryDepthMarketDataField myreq = CHSReqQryDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryDepthMarketData(&myreq, reqid);
	return i;
};

int TdApi::reqFundTrans(const dict &req, int reqid)
{
	CHSReqFundTransField myreq = CHSReqFundTransField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "TransDirection", &myreq.TransDirection);
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getDouble(req, "OccurBalance", &myreq.OccurBalance);
	int i = this->api->ReqFundTrans(&myreq, reqid);
	return i;
};

int TdApi::reqQryFundTrans(const dict &req, int reqid)
{
	CHSReqQryFundTransField myreq = CHSReqQryFundTransField();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->ReqQryFundTrans(&myreq, reqid);
	return i;
};

int TdApi::reqQryClientNotice(const dict &req, int reqid)
{
	CHSReqQryClientNoticeField myreq = CHSReqQryClientNoticeField();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->ReqQryClientNotice(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptUnderly(const dict &req, int reqid)
{
	CHSReqQryOptUnderlyField myreq = CHSReqQryOptUnderlyField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "UnderlyingInstrID", myreq.UnderlyingInstrID);
	int i = this->api->ReqQryOptUnderly(&myreq, reqid);
	return i;
};

int TdApi::reqQrySecuDepthMarket(const dict &req, int reqid)
{
	CHSReqQrySecuDepthMarketField myreq = CHSReqQrySecuDepthMarketField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "UnderlyingInstrID", myreq.UnderlyingInstrID);
	int i = this->api->ReqQrySecuDepthMarket(&myreq, reqid);
	return i;
};

int TdApi::reqQryHistOrder(const dict &req, int reqid)
{
	CHSReqQryHistOrderField myreq = CHSReqQryHistOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getInt32(req, "BeginDate", &myreq.BeginDate);
	getInt32(req, "EndDate", &myreq.EndDate);
	getString(req, "ExchangeAccountID", myreq.ExchangeAccountID);
	int i = this->api->ReqQryHistOrder(&myreq, reqid);
	return i;
};

int TdApi::reqQryHistTrade(const dict &req, int reqid)
{
	CHSReqQryHistTradeField myreq = CHSReqQryHistTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getInt32(req, "BeginDate", &myreq.BeginDate);
	getInt32(req, "EndDate", &myreq.EndDate);
	getString(req, "ExchangeAccountID", myreq.ExchangeAccountID);
	int i = this->api->ReqQryHistTrade(&myreq, reqid);
	return i;
};


int TdApi::reqQryCombInstrument(const dict &req, int reqid)
{
	CHSReqQryCombInstrumentField myreq = CHSReqQryCombInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryCombInstrument(&myreq, reqid);
	return i;
};

int TdApi::reqQrySeatID(const dict &req, int reqid)
{
	CHSReqQrySeatIDField myreq = CHSReqQrySeatIDField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	int i = this->api->ReqQrySeatID(&myreq, reqid);
	return i;
};

int TdApi::reqOptionSelfClose(const dict &req, int reqid)
{
	CHSReqOptionSelfCloseField myreq = CHSReqOptionSelfCloseField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getDouble(req, "OrderVolume", &myreq.OrderVolume);
	getChar(req, "SelfCloseType", &myreq.SelfCloseType);
	int i = this->api->ReqOptionSelfClose(&myreq, reqid);
	return i;
};

int TdApi::reqOptionSelfCloseAction(const dict &req, int reqid)
{
	CHSReqOptionSelfCloseActionField myreq = CHSReqOptionSelfCloseActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "SelfCloseType", &myreq.SelfCloseType);
	int i = this->api->ReqOptionSelfCloseAction(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptionSelfCloseResult(const dict &req, int reqid)
{
	CHSReqQryOptionSelfCloseResultField myreq = CHSReqQryOptionSelfCloseResultField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOptionSelfCloseResult(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptionSelfClose(const dict &req, int reqid)
{
	CHSReqQryOptionSelfCloseField myreq = CHSReqQryOptionSelfCloseField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOptionSelfClose(&myreq, reqid);
	return i;
};

int TdApi::reqOptQuoteInsert(const dict &req, int reqid)
{
	CHSReqOptQuoteInsertField myreq = CHSReqOptQuoteInsertField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "BidOffsetFlag", &myreq.BidOffsetFlag);
	getDouble(req, "BidOrderPrice", &myreq.BidOrderPrice);
	getDouble(req, "BidOrderVolume", &myreq.BidOrderVolume);
	getChar(req, "AskOffsetFlag", &myreq.AskOffsetFlag);
	getDouble(req, "AskOrderPrice", &myreq.AskOrderPrice);
	getDouble(req, "AskOrderVolume", &myreq.AskOrderVolume);
	getString(req, "QuoteRef", myreq.QuoteRef);
	getString(req, "ForQuoteSysID", myreq.ForQuoteSysID);
	int i = this->api->ReqOptQuoteInsert(&myreq, reqid);
	return i;
};

int TdApi::reqOptQuoteAction(const dict &req, int reqid)
{
	CHSReqOptQuoteActionField myreq = CHSReqOptQuoteActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getDouble(req, "BidWithdrawVolume", &myreq.BidWithdrawVolume);
	getDouble(req, "AskWithdrawVolume", &myreq.AskWithdrawVolume);
	getString(req, "QuoteRef", myreq.QuoteRef);
	int i = this->api->ReqOptQuoteAction(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptQuote(const dict &req, int reqid)
{
	CHSReqQryOptQuoteField myreq = CHSReqQryOptQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "QuoteQueryType", &myreq.QuoteQueryType);
	getString(req, "QuoteBrokerID", myreq.QuoteBrokerID);
	int i = this->api->ReqQryOptQuote(&myreq, reqid);
	return i;
};
///-------------------------------------------------------------------------------------
///Boost.Python��װ
///-------------------------------------------------------------------------------------

class PyTdApi : public TdApi
{
public:
    using TdApi::TdApi;
    
	void onFrontConnected() override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFrontConnected);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onFrontDisconnected(int reqid) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFrontDisconnected, reqid);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspAuthenticate(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspAuthenticate, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubmitUserSystemInfo(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSubmitUserSystemInfo, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUserLogin(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspUserLogin, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUserPasswordUpdate(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspUserPasswordUpdate, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspErrorOrderInsert(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspErrorOrderInsert, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderAction(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspOrderAction, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspErrorExerciseOrderInsert(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspErrorExerciseOrderInsert, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspExerciseOrderAction(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspExerciseOrderAction, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspErrorLockInsert(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspErrorLockInsert, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

void onRspForQuoteInsert(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspForQuoteInsert, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspErrorQuoteInsert(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspErrorQuoteInsert, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQuoteAction(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQuoteAction, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

	void onRspErrorCombActionInsert(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspErrorCombActionInsert, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQueryMaxOrderVolume(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQueryMaxOrderVolume, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryLockVolume(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryLockVolume, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQueryExerciseVolume(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQueryExerciseVolume, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCombVolume(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryCombVolume, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPosition(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryPosition, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryTradingAccount(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryTradingAccount, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOrder(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryOrder, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryTrade(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryTrade, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryExercise(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryExercise, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryLock(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryLock, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

void onRspQryCombAction(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryCombAction, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryForQuote(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryForQuote, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryQuote(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryQuote, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

	void onRspQryPositionCombineDetail(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryPositionCombineDetail, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInstrument(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryInstrument, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCoveredShort(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryCoveredShort, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryExerciseAssign(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryExerciseAssign, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspTransfer(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspTransfer, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryTransfer(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryTransfer, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQueryBankBalance(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQueryBankBalance, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQueryBankAccount(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQueryBankAccount, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspMultiCentreFundTrans(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspMultiCentreFundTrans, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQueryBillContent(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQueryBillContent, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspBillConfirm(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspBillConfirm, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryMargin(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryMargin, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCommission(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryCommission, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPositionDetail(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryPositionDetail, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryExchangeRate(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryExchangeRate, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQrySysConfig(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQrySysConfig, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryDepthMarketData(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryDepthMarketData, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFundTrans(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFundTrans, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryFundTrans(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryFundTrans, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryClientNotice(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryClientNotice, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOptUnderly(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryOptUnderly, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQrySecuDepthMarket(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQrySecuDepthMarket, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryHistOrder(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryHistOrder, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

void onRspQryHistTrade(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryHistTrade, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCombInstrument(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryCombInstrument, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQrySeatID(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQrySeatID, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOptionSelfClose(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOptionSelfClose, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOptionSelfCloseAction(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOptionSelfCloseAction, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOptionSelfCloseResult(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryOptionSelfCloseResult, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOptionSelfClose(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryOptionSelfClose, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOptQuoteInsert(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOptQuoteInsert, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOptQuoteAction(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOptQuoteAction, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOptQuote(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryOptQuote, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

	void onRtnTrade(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnTrade, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnOrder(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnOrder, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnExercise(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnExercise, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnCombAction(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnCombAction, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnLock(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnLock, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnOrderAction(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onErrRtnOrderAction, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

void onRtnClientNotice(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnClientNotice, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnForQuote(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnForQuote, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnQuote(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnQuote, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnExchangeStatus(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnExchangeStatus, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnProductStatus(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnProductStatus, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnOptionSelfClose(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnOptionSelfClose, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnOptQuote(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnOptQuote, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};


PYBIND11_MODULE(vnufttd, m)
{
    class_<TdApi, PyTdApi> TdApi(m, "TdApi", module_local());
	TdApi
		.def(init<>())
		.def("newTradeApi", &TdApi::newTradeApi)
		.def("init", &TdApi::init)
		.def("join", &TdApi::join)
		.def("exit", &TdApi::exit)
		.def("rgisterSubModel", &TdApi::rgisterSubModel)
		.def("registerFront", &TdApi::registerFront)
		.def("registerFensServer", &TdApi::registerFensServer)
		.def("getApiErrorMsg", &TdApi::getApiErrorMsg)
		.def("getTradingDate", &TdApi::getTradingDate)



		.def("reqAuthenticate", &TdApi::reqAuthenticate)
		.def("reqSubmitUserSystemInfo", &TdApi::reqSubmitUserSystemInfo)
		.def("reqUserLogin", &TdApi::reqUserLogin)
		.def("reqUserPasswordUpdate", &TdApi::reqUserPasswordUpdate)
		.def("reqOrderInsert", &TdApi::reqOrderInsert)
		.def("reqOrderAction", &TdApi::reqOrderAction)
		.def("reqExerciseOrderInsert", &TdApi::reqExerciseOrderInsert)
		.def("reqExerciseOrderAction", &TdApi::reqExerciseOrderAction)
		.def("reqLockInsert", &TdApi::reqLockInsert)
		.def("reqForQuoteInsert", &TdApi::reqForQuoteInsert)
		.def("reqQuoteInsert", &TdApi::reqQuoteInsert)
        .def("reqQuoteAction", &TdApi::reqQuoteAction)

		.def("reqCombActionInsert", &TdApi::reqCombActionInsert)
		.def("reqQueryMaxOrderVolume", &TdApi::reqQueryMaxOrderVolume)
		.def("reqQryLockVolume", &TdApi::reqQryLockVolume)
		.def("reqQueryExerciseVolume", &TdApi::reqQueryExerciseVolume)
		.def("reqQryCombVolume", &TdApi::reqQryCombVolume)
		.def("reqQryPosition", &TdApi::reqQryPosition)
		.def("reqQryTradingAccount", &TdApi::reqQryTradingAccount)
		.def("reqQryOrder", &TdApi::reqQryOrder)
		.def("reqQryTrade", &TdApi::reqQryTrade)
		.def("reqQryExercise", &TdApi::reqQryExercise)
		.def("reqQryLock", &TdApi::reqQryLock)
		.def("reqQryCombAction", &TdApi::reqQryCombAction)

		.def("reqQryForQuote", &TdApi::reqQryForQuote)
        .def("reqQryQuote", &TdApi::reqQryQuote)

		.def("reqQryPositionCombineDetail", &TdApi::reqQryPositionCombineDetail)
		.def("reqQryInstrument", &TdApi::reqQryInstrument)
		.def("reqQryCoveredShort", &TdApi::reqQryCoveredShort)
		.def("reqQryExerciseAssign", &TdApi::reqQryExerciseAssign)
		.def("reqTransfer", &TdApi::reqTransfer)
		.def("reqQryTransfer", &TdApi::reqQryTransfer)
		.def("reqQueryBankBalance", &TdApi::reqQueryBankBalance)
		.def("reqQueryBankAccount", &TdApi::reqQueryBankAccount)
		.def("reqMultiCentreFundTrans", &TdApi::reqMultiCentreFundTrans)
		.def("reqQueryBillContent", &TdApi::reqQueryBillContent)
		.def("reqBillConfirm", &TdApi::reqBillConfirm)
		.def("reqQryMargin", &TdApi::reqQryMargin)
		.def("reqQryCommission", &TdApi::reqQryCommission)
		.def("reqQryExchangeRate", &TdApi::reqQryExchangeRate)
		.def("reqQryPositionDetail", &TdApi::reqQryPositionDetail)
		.def("reqQrySysConfig", &TdApi::reqQrySysConfig)
		.def("reqQryDepthMarketData", &TdApi::reqQryDepthMarketData)
		.def("reqFundTrans", &TdApi::reqFundTrans)
		.def("reqQryFundTrans", &TdApi::reqQryFundTrans)
		.def("reqQryClientNotice", &TdApi::reqQryClientNotice)
		.def("reqQryOptUnderly", &TdApi::reqQryOptUnderly)
		.def("reqQrySecuDepthMarket", &TdApi::reqQrySecuDepthMarket)
		.def("reqQryHistOrder", &TdApi::reqQryHistOrder)
		.def("reqQryHistTrade", &TdApi::reqQryHistTrade)
		.def("reqQryCombInstrument", &TdApi::reqQryCombInstrument)
        .def("reqQrySeatID", &TdApi::reqQrySeatID)
        .def("reqOptionSelfClose", &TdApi::reqOptionSelfClose)
        .def("reqOptionSelfCloseAction", &TdApi::reqOptionSelfCloseAction)
        .def("reqQryOptionSelfCloseResult", &TdApi::reqQryOptionSelfCloseResult)
        .def("reqQryOptionSelfClose", &TdApi::reqQryOptionSelfClose)
        .def("reqOptQuoteInsert", &TdApi::reqOptQuoteInsert)
        .def("reqOptQuoteAction", &TdApi::reqOptQuoteAction)
        .def("reqQryOptQuote", &TdApi::reqQryOptQuote)


		.def("onFrontConnected", &TdApi::onFrontConnected)
		.def("onFrontDisconnected", &TdApi::onFrontDisconnected)
		.def("onRspAuthenticate", &TdApi::onRspAuthenticate)
		.def("onRspSubmitUserSystemInfo", &TdApi::onRspSubmitUserSystemInfo)
		.def("onRspUserLogin", &TdApi::onRspUserLogin)
		.def("onRspUserPasswordUpdate", &TdApi::onRspUserPasswordUpdate)
		.def("onRspErrorOrderInsert", &TdApi::onRspErrorOrderInsert)
		.def("onRspOrderAction", &TdApi::onRspOrderAction)
		.def("onRspErrorExerciseOrderInsert", &TdApi::onRspErrorExerciseOrderInsert)
		.def("onRspExerciseOrderAction", &TdApi::onRspExerciseOrderAction)
		.def("onRspErrorLockInsert", &TdApi::onRspErrorLockInsert)
		.def("onRspForQuoteInsert", &TdApi::onRspForQuoteInsert)
		.def("onRspErrorQuoteInsert", &TdApi::onRspErrorQuoteInsert)
        .def("onRspQuoteAction", &TdApi::onRspQuoteAction)
		.def("onRspErrorCombActionInsert", &TdApi::onRspErrorCombActionInsert)
		.def("onRspQueryMaxOrderVolume", &TdApi::onRspQueryMaxOrderVolume)
		.def("onRspQryLockVolume", &TdApi::onRspQryLockVolume)
		.def("onRspQueryExerciseVolume", &TdApi::onRspQueryExerciseVolume)
		.def("onRspQryCombVolume", &TdApi::onRspQryCombVolume)
		.def("onRspQryPosition", &TdApi::onRspQryPosition)
		.def("onRspQryTradingAccount", &TdApi::onRspQryTradingAccount)
		.def("onRspQryOrder", &TdApi::onRspQryOrder)
		.def("onRspQryTrade", &TdApi::onRspQryTrade)
		.def("onRspQryExercise", &TdApi::onRspQryExercise)
		.def("onRspQryLock", &TdApi::onRspQryLock)
		.def("onRspQryCombAction", &TdApi::onRspQryCombAction)
		.def("onRspQryForQuote", &TdApi::onRspQryForQuote)
        .def("onRspQryQuote", &TdApi::onRspQryQuote)
		.def("onRspQryPositionCombineDetail", &TdApi::onRspQryPositionCombineDetail)
		.def("onRspQryInstrument", &TdApi::onRspQryInstrument)
		.def("onRspQryCoveredShort", &TdApi::onRspQryCoveredShort)
		.def("onRspQryExerciseAssign", &TdApi::onRspQryExerciseAssign)
		.def("onRspTransfer", &TdApi::onRspTransfer)
		.def("onRspQryTransfer", &TdApi::onRspQryTransfer)
		.def("onRspQueryBankBalance", &TdApi::onRspQueryBankBalance)
		.def("onRspQueryBankAccount", &TdApi::onRspQueryBankAccount)
		.def("onRspMultiCentreFundTrans", &TdApi::onRspMultiCentreFundTrans)
		.def("onRspQueryBillContent", &TdApi::onRspQueryBillContent)
		.def("onRspBillConfirm", &TdApi::onRspBillConfirm)
		.def("onRspQryMargin", &TdApi::onRspQryMargin)
		.def("onRspQryCommission", &TdApi::onRspQryCommission)
		.def("onRspQryPositionDetail", &TdApi::onRspQryPositionDetail)
		.def("onRspQryExchangeRate", &TdApi::onRspQryExchangeRate)
		.def("onRspQrySysConfig", &TdApi::onRspQrySysConfig)
		.def("onRspQryDepthMarketData", &TdApi::onRspQryDepthMarketData)
		.def("onRspFundTrans", &TdApi::onRspFundTrans)
		.def("onRspQryFundTrans", &TdApi::onRspQryFundTrans)
		.def("onRspQryClientNotice", &TdApi::onRspQryClientNotice)
		.def("onRspQryOptUnderly", &TdApi::onRspQryOptUnderly)
		.def("onRspQrySecuDepthMarket", &TdApi::onRspQrySecuDepthMarket)
		.def("onRspQryHistOrder", &TdApi::onRspQryHistOrder)
		.def("onRspQryHistTrade", &TdApi::onRspQryHistTrade)
		.def("onRspQryCombInstrument", &TdApi::onRspQryCombInstrument)
        .def("onRspQrySeatID", &TdApi::onRspQrySeatID)
        .def("onRspOptionSelfClose", &TdApi::onRspOptionSelfClose)
        .def("onRspOptionSelfCloseAction", &TdApi::onRspOptionSelfCloseAction)
        .def("onRspQryOptionSelfCloseResult", &TdApi::onRspQryOptionSelfCloseResult)
        .def("onRspQryOptionSelfClose", &TdApi::onRspQryOptionSelfClose)
        .def("onRspOptQuoteInsert", &TdApi::onRspOptQuoteInsert)
        .def("onRspOptQuoteAction", &TdApi::onRspOptQuoteAction)
        .def("onRspQryOptQuote", &TdApi::onRspQryOptQuote)
		.def("onRtnTrade", &TdApi::onRtnTrade)
		.def("onRtnOrder", &TdApi::onRtnOrder)
		.def("onRtnExercise", &TdApi::onRtnExercise)
		.def("onRtnCombAction", &TdApi::onRtnCombAction)
		.def("onRtnLock", &TdApi::onRtnLock)
		.def("onErrRtnOrderAction", &TdApi::onErrRtnOrderAction)
		.def("onRtnClientNotice", &TdApi::onRtnClientNotice)
		.def("onRtnForQuote", &TdApi::onRtnForQuote)
        .def("onRtnQuote", &TdApi::onRtnQuote)
        .def("onRtnExchangeStatus", &TdApi::onRtnExchangeStatus)
        .def("onRtnProductStatus", &TdApi::onRtnProductStatus)
        .def("onRtnOptionSelfClose", &TdApi::onRtnOptionSelfClose)
        .def("onRtnOptQuote", &TdApi::onRtnOptQuote)
		;
}
