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

int TdApi::reqQryWithdrawFund(const dict &req, int reqid)
{
	CHSReqQryWithdrawFundField myreq = CHSReqQryWithdrawFundField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "CurrencyID", &myreq.CurrencyID);
	getInt32(req, "SysNodeID", &myreq.SysNodeID);
	int i = this->api->ReqQryWithdrawFund(&myreq, reqid);
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
	getString(req, "QuoteActionRef", myreq.QuoteActionRef);
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

int TdApi::reqQryOptCombStrategy(const dict &req, int reqid)
{
	CHSReqQryOptCombStrategyField myreq = CHSReqQryOptCombStrategyField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "CombStrategyID", myreq.CombStrategyID);
	int i = this->api->ReqQryOptCombStrategy(&myreq, reqid);
	return i;
};

