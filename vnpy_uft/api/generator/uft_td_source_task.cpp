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

void TdApi::OnRspQryWithdrawFund(CHSRspQryWithdrawFundField *pRspQryWithdrawFund, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYWITHDRAWFUND;
	if (pRspQryWithdrawFund)
	{
		CHSRspQryWithdrawFundField *task_data = new CHSRspQryWithdrawFundField();
		*task_data = *pRspQryWithdrawFund;
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

void TdApi::OnRspErrorOptQuoteInsert(CHSRspOptQuoteInsertField *pRspOptQuoteInsert, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPERROROPTQUOTEINSERT;
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

void TdApi::OnRspQryOptCombStrategy(CHSRspQryOptCombStrategyField *pRspQryOptCombStrategy, CHSRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYOPTCOMBSTRATEGY;
	if (pRspQryOptCombStrategy)
	{
		CHSRspQryOptCombStrategyField *task_data = new CHSRspQryOptCombStrategyField();
		*task_data = *pRspQryOptCombStrategy;
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

void TdApi::OnRtnTransfer(CHSTransferField *pRtnTransfer) 
{
	Task task = Task();
	task.task_name = ONRTNTRANSFER;
	if (pRtnTransfer)
	{
		CHSTransferField *task_data = new CHSTransferField();
		*task_data = *pRtnTransfer;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnErrRtnOptQuoteAction(CHSOptQuoteActionField *pRtnOptQuoteAction) 
{
	Task task = Task();
	task.task_name = ONERRRTNOPTQUOTEACTION;
	if (pRtnOptQuoteAction)
	{
		CHSOptQuoteActionField *task_data = new CHSOptQuoteActionField();
		*task_data = *pRtnOptQuoteAction;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

