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

