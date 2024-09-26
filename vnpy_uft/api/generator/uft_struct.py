CHSInitConfigField = {
    "APICheckVersion": "int32",
    "CommLicense": "string",
    "SafeLevel": "string",
    "CommPassword": "string",
    "SslVersion": "string",
    "CertLicense": "string",
    "CertPassword": "string",
    "SksUser": "string",
    "SksPassword": "string",
    "SksPin": "string",
    "SksCheckCertFlag": "char",
}

CHSRspInfoField = {
    "ErrorID": "int32",
    "ErrorMsg": "string",
}

CHSReqAuthenticateField = {
    "AccountID": "string",
    "Password": "string",
    "AppID": "string",
    "AuthCode": "string",
}

CHSRspAuthenticateField = {
    "AccountID": "string",
    "AppID": "string",
    "AuthCode": "string",
    "AppIDType": "char",
}

CHSReqUserSystemInfoField = {
    "AppLoginTime": "string",
    "AppPublicAdrr": "string",
    "AppSysInfo": "string",
    "AppSysInfoIntegrity": "string",
    "AppAbnormalType": "char",
}

CHSRspUserSystemInfoField = {
}

CHSReqUserLoginField = {
    "AccountID": "string",
    "Password": "string",
    "UserApplicationType": "char",
    "UserApplicationInfo": "string",
    "MacAddress": "string",
    "IPAddress": "string",
    "UserStationInfo": "string",
}

CHSRspUserLoginField = {
    "BranchID": "int32",
    "AccountID": "string",
    "UserName": "string",
    "TradingDay": "int32",
    "PreTradingDay": "int32",
    "BillConfirmFlag": "char",
    "SessionID": "int32",
    "UserApplicationType": "char",
    "UserApplicationInfo": "string",
    "RiskLevel": "string",
    "LastMacAddress": "string",
    "LastIPAddress": "string",
    "LastLoginTime": "int32",
    "CZCETime": "int32",
    "DCETime": "int32",
    "SHFETime": "int32",
    "CFFEXTime": "int32",
    "INETime": "int32",
    "MaxOrderRef": "string",
    "UserID": "string",
    "GFEXTime": "int32",
}

CHSReqUserPasswordUpdateField = {
    "PasswordType": "char",
    "Password": "string",
    "NewPassword": "string",
}

CHSRspUserPasswordUpdateField = {
}

CHSReqOrderInsertField = {
    "OrderRef": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "Direction": "char",
    "OffsetFlag": "char",
    "HedgeType": "char",
    "OrderPrice": "double",
    "OrderVolume": "double",
    "OrderCommand": "int32",
    "MinVolume": "double",
    "SpringPrice": "double",
    "SwapOrderFlag": "char",
    "CombPositionID": "string",
    "ExchangeAccountID": "string",
    "SeatIndex": "int32",
}

CHSRspOrderInsertField = {
    "AccountID": "string",
    "OrderSysID": "string",
    "BrokerOrderID": "string",
    "SessionID": "int32",
    "OrderRef": "string",
    "InstrumentID": "string",
    "ExchangeID": "string",
    "Direction": "char",
    "OffsetFlag": "char",
    "HedgeType": "char",
    "OrderPrice": "double",
    "OrderVolume": "double",
    "OrderStatus": "char",
    "OrderCommand": "int32",
    "InsertTime": "int32",
    "MinVolume": "double",
    "SpringPrice": "double",
    "SwapOrderFlag": "char",
    "CombPositionID": "string",
    "ExchangeAccountID": "string",
    "SeatIndex": "int32",
}

CHSReqOrderActionField = {
    "OrderSysID": "string",
    "ExchangeID": "string",
    "SessionID": "int32",
    "OrderRef": "string",
    "OrderActionRef": "string",
}

CHSRspOrderActionField = {
    "AccountID": "string",
    "OrderSysID": "string",
    "ExchangeID": "string",
    "SessionID": "int32",
    "OrderRef": "string",
    "OrderStatus": "char",
    "InsertTime": "int32",
    "OrderActionRef": "string",
}

CHSReqExerciseOrderInsertField = {
    "ExerciseRef": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "OrderVolume": "double",
    "ExerciseType": "char",
    "HedgeType": "char",
    "OffsetFlag": "char",
    "CloseFlag": "char",
}

CHSRspExerciseOrderInsertField = {
    "AccountID": "string",
    "SessionID": "int32",
    "ExerciseOrderSysID": "string",
    "ExerciseRef": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "OrderVolume": "double",
    "ExerciseType": "char",
    "HedgeType": "char",
    "OrderStatus": "char",
    "InsertTime": "int32",
    "OffsetFlag": "char",
    "CloseFlag": "char",
    "ExerciseBrokerOrderID": "string",
}

CHSReqExerciseOrderActionField = {
    "ExchangeID": "string",
    "ExerciseOrderSysID": "string",
    "ExerciseRef": "string",
    "SessionID": "int32",
    "ExecOrderActionRef": "string",
}

CHSRspExerciseOrderActionField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "ExerciseOrderSysID": "string",
    "ExerciseRef": "string",
    "SessionID": "int32",
    "OrderStatus": "char",
    "ExecOrderActionRef": "string",
}

CHSReqLockInsertField = {
    "ExchangeID": "string",
    "UnderlyingInstrID": "string",
    "LockType": "char",
    "OrderVolume": "double",
    "LockRef": "string",
}

CHSRspLockInsertField = {
    "AccountID": "string",
    "LockOrderSysID": "string",
    "ExchangeID": "string",
    "UnderlyingInstrID": "string",
    "LockType": "char",
    "OrderVolume": "double",
    "UnderlyingAccountID": "string",
    "OrderStatus": "char",
    "InsertTime": "int32",
    "LockRef": "string",
}

CHSReqForQuoteInsertField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSRspForQuoteInsertField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "OrderStatus": "char",
}

CHSReqQuoteInsertField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "BidOffsetFlag": "char",
    "BidHedgeType": "char",
    "BidOrderPrice": "double",
    "BidOrderVolume": "double",
    "BidOrderRef": "string",
    "AskOffsetFlag": "char",
    "AskHedgeType": "char",
    "AskOrderPrice": "double",
    "AskOrderVolume": "double",
    "AskOrderRef": "string",
    "ForQuoteSysID": "string",
    "QuoteRef": "string",
    "TopOrderType": "char",
    "QuoteSysID": "string",
}

CHSRspQuoteInsertField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "BidOffsetFlag": "char",
    "BidHedgeType": "char",
    "BidOrderPrice": "double",
    "BidOrderVolume": "double",
    "BidOrderRef": "string",
    "AskOffsetFlag": "char",
    "AskHedgeType": "char",
    "AskOrderPrice": "double",
    "AskOrderVolume": "double",
    "AskOrderRef": "string",
    "ForQuoteSysID": "string",
    "QuoteRef": "string",
    "QuoteBrokerID": "string",
    "BidOrderSysID": "string",
    "AskOrderSysID": "string",
    "SessionID": "int32",
    "InsertTime": "int32",
    "OrderStatus": "char",
    "TopOrderType": "char",
    "QuoteSysID": "string",
}

CHSReqQuoteActionField = {
    "QuoteSysID": "string",
    "ExchangeID": "string",
    "SessionID": "int32",
    "QuoteRef": "string",
    "QuoteActionRef": "string",
    "InstrumentID": "string",
}

CHSRspQuoteActionField = {
    "AccountID": "string",
    "QuoteSysID": "string",
    "ExchangeID": "string",
    "SessionID": "int32",
    "QuoteRef": "string",
    "QuoteActionRef": "string",
    "OrderStatus": "char",
    "InsertTime": "int32",
    "InstrumentID": "string",
}

CHSReqCombActionInsertField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "CombStrategyID": "string",
    "CombPositionID": "string",
    "CombDirection": "char",
    "OrderVolume": "double",
    "HedgeType": "char",
    "Direction": "char",
    "SecondHedgeType": "char",
    "CombOrderRef": "string",
}

CHSRspCombActionInsertField = {
    "AccountID": "string",
    "CombOrderSysID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "CombStrategyID": "string",
    "CombPositionID": "string",
    "CombDirection": "char",
    "OrderVolume": "double",
    "HedgeType": "char",
    "OrderStatus": "char",
    "InsertTime": "int32",
    "Direction": "char",
    "SecondHedgeType": "char",
    "CombOrderRef": "string",
}

CHSReqQueryMaxOrderVolumeField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "OrderCommand": "int32",
    "Direction": "char",
    "OffsetFlag": "char",
    "HedgeType": "char",
    "OrderPrice": "double",
    "CombPositionID": "string",
}

CHSRspQueryMaxOrderVolumeField = {
    "AccountID": "string",
    "MaxOrderVolume": "double",
    "MaxOrderVolumeUnit": "double",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "OrderCommand": "int32",
    "Direction": "char",
    "OffsetFlag": "char",
    "HedgeType": "char",
    "OrderPrice": "double",
    "CombPositionID": "string",
    "ErrorMsg": "string",
}

CHSReqQryLockVolumeField = {
    "ExchangeID": "string",
    "UnderlyingInstrID": "string",
    "LockType": "char",
}

CHSRspQryLockVolumeField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "UnderlyingInstrID": "string",
    "LockType": "char",
    "AvailablePositionVolume": "double",
}

CHSReqQueryExerciseVolumeField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSRspQueryExerciseVolumeField = {
    "AccountID": "string",
    "MaxOrderVolumeUnit": "double",
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSReqQryCombVolumeField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "CombStrategyID": "string",
    "CombPositionID": "string",
    "CombDirection": "char",
}

CHSRspQryCombVolumeField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "CombStrategyID": "string",
    "CombPositionID": "string",
    "CombDirection": "char",
    "MaxOrderVolumeUnit": "double",
}

CHSReqQryPositionField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSRspQryPositionField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "Direction": "char",
    "HedgeType": "char",
    "YdPositionVolume": "double",
    "PositionVolume": "double",
    "TodayPositionVolume": "double",
    "AvailablePositionVolume": "double",
    "TodayAvailablePositionVolume": "double",
    "PositionMargin": "double",
    "Premium": "double",
    "Commission": "double",
    "OpenFrozenVolume": "double",
    "CloseFrozenVolume": "double",
    "CombVolume": "double",
    "ExerciseFrozenVolume": "double",
    "FrozenMargin": "double",
    "ExerciseFrozenMargin": "double",
    "FrozenPremium": "double",
    "FrozenCommission": "double",
    "OpenVolume": "double",
    "CloseVolume": "double",
    "OpenBalance": "double",
    "CloseBalance": "double",
    "OpenCost": "double",
    "PositionCost": "double",
    "PositionProfit": "double",
    "CloseProfit": "double",
    "OptionsMarketValue": "double",
    "UnderlyingInstrID": "string",
    "TASPositionVolume": "double",
}

CHSReqQryTradingAccountField = {
}

CHSRspQryTradingAccountField = {
    "AccountID": "string",
    "YdBalance": "double",
    "YdPositionMargin": "double",
    "YdFundEquity": "double",
    "FundEquity": "double",
    "OptionsMarketValue": "double",
    "Equity": "double",
    "AvailableBalance": "double",
    "WithdrawBalance": "double",
    "Margin": "double",
    "FrozenMargin": "double",
    "ExerciseFrozenMargin": "double",
    "RiskDegree": "double",
    "Premium": "double",
    "FrozenPremium": "double",
    "Commission": "double",
    "FrozenCommission": "double",
    "CloseProfit": "double",
    "PositionProfit": "double",
    "CloseProfitByDate": "double",
    "PositionProfitByDate": "double",
    "Deposit": "double",
    "Withdraw": "double",
    "FundMortgage": "double",
    "WarrantMortgage": "double",
    "FrozenBalance": "double",
    "UnFrozenBalance": "double",
    "CurrencyID": "char",
    "HedgeRiskDegree": "double",
    "ShUsedBuyQuota": "double",
    "SzUsedBuyQuota": "double",
    "ShAvailableBuyQuota": "double",
    "SzAvailableBuyQuota": "double",
    "YdWarrantMortgage": "double",
}

CHSReqQryOrderField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "OrderSysID": "string",
    "ExchangeAccountID": "string",
}

CHSReqQryHistOrderField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "OrderSysID": "string",
    "BeginDate": "int32",
    "EndDate": "int32",
    "ExchangeAccountID": "string",
}

CHSOrderField = {
    "AccountID": "string",
    "OrderSysID": "string",
    "BrokerOrderID": "string",
    "SessionID": "int32",
    "OrderRef": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "Direction": "char",
    "OffsetFlag": "char",
    "HedgeType": "char",
    "OrderPrice": "double",
    "OrderVolume": "double",
    "OrderStatus": "char",
    "TradeVolume": "double",
    "CancelVolume": "double",
    "TradePrice": "double",
    "TradingDay": "int32",
    "InsertDate": "int32",
    "InsertTime": "int32",
    "ReportTime": "int32",
    "OrderCommand": "int32",
    "MinVolume": "double",
    "SpringPrice": "double",
    "SwapOrderFlag": "char",
    "ForceCloseReason": "char",
    "ErrorMsg": "string",
    "UnderlyingInstrID": "string",
    "OrderSource": "char",
    "CombPositionID": "string",
    "ExchangeAccountID": "string",
    "SeatIndex": "int32",
}

CHSReqQryTradeField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "ExchangeAccountID": "string",
}

CHSReqQryHistTradeField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "BeginDate": "int32",
    "EndDate": "int32",
    "ExchangeAccountID": "string",
}

CHSTradeField = {
    "AccountID": "string",
    "TradeID": "string",
    "OrderSysID": "string",
    "BrokerOrderID": "string",
    "SessionID": "int32",
    "OrderRef": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "Direction": "char",
    "OffsetFlag": "char",
    "HedgeType": "char",
    "TradeVolume": "double",
    "TradePrice": "double",
    "TradingDay": "int32",
    "TradeTime": "int32",
    "UnderlyingInstrID": "string",
    "CombPositionID": "string",
    "TradeCommission": "double",
    "ExchangeAccountID": "string",
}

CHSReqQryExerciseField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "ExerciseOrderSysID": "string",
}

CHSReqQryHistExerciseField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "ExerciseOrderSysID": "string",
    "BeginDate": "int32",
    "EndDate": "int32",
}

CHSExerciseField = {
    "AccountID": "string",
    "ExerciseOrderSysID": "string",
    "SessionID": "int32",
    "ExerciseRef": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "HedgeType": "char",
    "ExerciseType": "char",
    "OrderVolume": "double",
    "OrderStatus": "char",
    "InsertDate": "int32",
    "InsertTime": "int32",
    "ErrorMsg": "string",
    "UnderlyingInstrID": "string",
    "OrderSource": "char",
    "CloseFlag": "char",
    "OffsetFlag": "char",
    "ExercisePreFrozenCommission": "double",
    "ExercisePreFrozenMargin": "double",
    "ExerciseBrokerOrderID": "string",
    "ExchangeAccountID": "string",
}

CHSReqQryLockField = {
    "ExchangeID": "string",
    "UnderlyingInstrID": "string",
    "LockOrderSysID": "string",
}

CHSReqQryHistLockField = {
    "ExchangeID": "string",
    "UnderlyingInstrID": "string",
    "LockOrderSysID": "string",
    "BeginDate": "int32",
    "EndDate": "int32",
}

CHSLockField = {
    "AccountID": "string",
    "LockOrderSysID": "string",
    "ExchangeID": "string",
    "UnderlyingInstrID": "string",
    "LockType": "char",
    "OrderVolume": "double",
    "OrderStatus": "char",
    "TradingDay": "int32",
    "InsertTime": "int32",
    "ErrorMsg": "string",
    "OrderSource": "char",
    "LockRef": "string",
    "SessionID": "int32",
}

CHSReqQryCombActionField = {
    "CombOrderSysID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSReqQryHistCombActionField = {
    "CombOrderSysID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "BeginDate": "int32",
    "EndDate": "int32",
}

CHSCombActionField = {
    "AccountID": "string",
    "CombOrderSysID": "string",
    "CombPositionID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "CombStrategyID": "string",
    "Direction": "char",
    "CombDirection": "char",
    "HedgeType": "char",
    "OrderVolume": "double",
    "OrderStatus": "char",
    "TradingDay": "int32",
    "InsertDate": "int32",
    "InsertTime": "int32",
    "ErrorMsg": "string",
    "OrderSource": "char",
    "SecondHedgeType": "char",
    "CombOrderRef": "string",
    "SessionID": "int32",
}

CHSReqForQuoteField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSReqQryForQuoteField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "ForQuoteSysID": "string",
}

CHSForQuoteField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "ForQuoteSysID": "string",
    "TradingDay": "int32",
    "UpdateTime": "int32",
}

CHSReqQryQuoteField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "QuoteSysID": "string",
    "QuoteBrokerID": "string",
}

CHSQuoteField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "QuoteBrokerID": "string",
    "OrderStatus": "char",
    "BidOffsetFlag": "char",
    "BidHedgeType": "char",
    "BidOrderPrice": "double",
    "BidOrderVolume": "double",
    "AskOffsetFlag": "char",
    "AskHedgeType": "char",
    "AskOrderPrice": "double",
    "AskOrderVolume": "double",
    "QuoteRef": "string",
    "ForQuoteSysID": "string",
    "ErrorMsg": "string",
    "QuoteSysID": "string",
    "BidOrderSysID": "string",
    "AskOrderSysID": "string",
    "BidBrokerOrderID": "string",
    "AskBrokerOrderID": "string",
    "BidOrderRef": "string",
    "AskOrderRef": "string",
    "SessionID": "int32",
    "TradingDay": "int32",
    "InsertDate": "int32",
    "InsertTime": "int32",
    "ReportTime": "int32",
    "TopOrderType": "char",
}

CHSReqQryPositionCombineDetailField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "CombStrategyID": "string",
}

CHSRspQryPositionCombineDetailField = {
    "AccountID": "string",
    "CombPositionID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "CombStrategyID": "string",
    "HedgeType": "char",
    "Direction": "char",
    "YdPositionVolume": "double",
    "AvailablePositionVolume": "double",
    "TotalCombVolume": "double",
    "TotalSplitVolume": "double",
    "PositionMargin": "double",
    "OpenDate": "int32",
    "SecondHedgeType": "char",
}

CHSReqQryInstrumentField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSRspQryInstrumentField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "InstrumentName": "string",
    "InstrumentEngName": "string",
    "ProductID": "string",
    "ProductType": "char",
    "MaxMarketOrderVolume": "double",
    "MinMarketOrderVolume": "double",
    "MaxLimitOrderVolume": "double",
    "MinLimitOrderVolume": "double",
    "VolumeMultiple": "double",
    "PriceTick": "double",
    "UnderlyingInstrID": "string",
    "ExercisePrice": "double",
    "OptionsType": "char",
    "TradingFlag": "char",
    "MarketDate": "int32",
    "ExpireDate": "int32",
    "BeginExerciseDate": "int32",
    "EndExerciseDate": "int32",
    "BeginDeliveryDate": "int32",
    "EndDeliveryDate": "int32",
    "CurrencyID": "char",
    "CombType": "char",
}

CHSReqQryCoveredShortField = {
    "ExchangeID": "string",
}

CHSRspQryCoveredShortField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "UnderlyingInstrID": "string",
    "CoveredLockVolume": "double",
    "CoveredShortVolume": "double",
    "CoveredEstimateShortVolume": "double",
    "MsgContent": "string",
}

CHSReqQryExerciseAssignField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "PositionType": "char",
}

CHSRspQryExerciseAssignField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "UnderlyingInstrID": "string",
    "InstrumentID": "string",
    "PositionType": "char",
    "OptionsType": "char",
    "ExercisePrice": "double",
    "ExerciseVolume": "double",
    "DeliveryVolume": "double",
    "ExerciseFrozenBalance": "double",
    "SettlementBalance": "double",
}

CHSReqTransferField = {
    "BankID": "string",
    "TransferType": "char",
    "OccurBalance": "double",
    "FundPassword": "string",
    "BankPassword": "string",
    "CurrencyID": "char",
    "TransferOccasion": "string",
}

CHSRspTransferField = {
    "TransferSerialID": "int32",
    "BankID": "string",
    "TransferType": "char",
    "OccurBalance": "double",
    "CurrencyID": "char",
    "TransferOccasion": "string",
}

CHSReqQryTransferField = {
    "BankID": "string",
    "TransferSerialID": "int32",
}

CHSRspQryTransferField = {
    "TransferSerialID": "int32",
    "BankID": "string",
    "BankName": "string",
    "BusinessName": "string",
    "OccurBalance": "double",
    "PostBalance": "double",
    "TransferTime": "int32",
    "TransferStatus": "char",
    "TransferSource": "char",
    "Remarks": "string",
    "CurrencyID": "char",
    "OrderSourceDate": "int32",
    "TradingDay": "int32",
    "TransferOccasion": "string",
}

CHSReqQueryBankBalanceField = {
    "BankID": "string",
    "FundPassword": "string",
    "BankPassword": "string",
    "CurrencyID": "char",
}

CHSRspQueryBankBalanceField = {
    "TransferSerialID": "int32",
}

CHSReqQueryBankAccountField = {
    "BankID": "string",
    "CurrencyID": "char",
}

CHSRspQueryBankAccountField = {
    "BankID": "string",
    "BankName": "string",
    "BankAccountID": "string",
    "CurrencyID": "char",
}

CHSReqMultiCentreFundTransField = {
    "CurrencyID": "char",
    "OccurBalance": "double",
    "TransDirection": "char",
}

CHSRspMultiCentreFundTransField = {
    "AccountID": "string",
    "CurrencyID": "char",
    "OccurBalance": "double",
    "TransDirection": "char",
    "LocalTransferSerialID": "int32",
    "OppositeTransferSerialID": "int32",
}

CHSReqQueryBillContentField = {
    "BeginDate": "int32",
    "EndDate": "int32",
}

CHSRspQueryBillContentField = {
    "BillContent": "string",
}

CHSReqBillConfirmField = {
}

CHSRspBillConfirmField = {
    "AccountID": "string",
    "BillConfirmStatus": "char",
    "ConfirmDate": "int32",
    "ConfirmTime": "int32",
}

CHSReqQryMarginField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "UnderlyingInstrID": "string",
    "HedgeType": "char",
}

CHSRspQryMarginField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "UnderlyingInstrID": "string",
    "HedgeType": "char",
    "LongMarginRatio": "double",
    "LongMargin": "double",
    "ShortMarginRatio": "double",
    "ShortMargin": "double",
}

CHSReqQryCommissionField = {
    "ExchangeID": "string",
    "ProductType": "char",
    "InstrumentID": "string",
    "UnderlyingInstrID": "string",
}

CHSRspQryCommissionField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "ProductType": "char",
    "InstrumentID": "string",
    "UnderlyingInstrID": "string",
    "LongOpenCommissionRatio": "double",
    "LongOpenCommission": "double",
    "LongCloseCommissionRatio": "double",
    "LongCloseCommission": "double",
    "LongCloseTodayCommissionRatio": "double",
    "LongCloseTodayCommission": "double",
    "ShortOpenCommissionRatio": "double",
    "ShortOpenCommission": "double",
    "ShortCloseCommissionRatio": "double",
    "ShortCloseCommission": "double",
    "ShortCloseTodayCommissionRatio": "double",
    "ShortCloseTodayCommission": "double",
    "ExerciseCommissionRatio": "double",
    "ExerciseCommission": "double",
    "TradeValueRatio": "double",
    "StockValue": "double",
}

CHSReqQryExchangeRateField = {
    "FromCurrencyID": "char",
    "ToCurrencyID": "char",
}

CHSRspQryExchangeRateField = {
    "FromCurrencyID": "char",
    "ToCurrencyID": "char",
    "ExchangeRate": "double",
    "FromCurrencyUnit": "double",
}

CHSReqQryPositionDetailField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSRspQryPositionDetailField = {
    "AccountID": "string",
    "TradeID": "string",
    "OpenDate": "int32",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "Direction": "char",
    "HedgeType": "char",
    "TradeVolume": "double",
    "PositionPrice": "double",
    "TodayCloseVolume": "double",
    "ArbitragePositionID": "string",
    "LegID": "double",
    "TradeType": "char",
    "PositionMargin": "double",
    "CombInstrumentID": "string",
    "CurrentPositionVolume": "double",
    "SettlementPrice": "double",
    "PositionSerialID": "int32",
}

CHSReqQrySysConfigField = {
}

CHSRspQrySysConfigField = {
    "ConfigNo": "double",
    "ConfigValue": "string",
}

CHSReqDepthMarketDataField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSReqQryDepthMarketDataField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSDepthMarketDataField = {
    "TradingDay": "int32",
    "InstrumentID": "string",
    "ExchangeID": "string",
    "LastPrice": "double",
    "PreSettlementPrice": "double",
    "PreClosePrice": "double",
    "OpenPrice": "double",
    "HighestPrice": "double",
    "LowestPrice": "double",
    "TradeVolume": "double",
    "TradeBalance": "double",
    "OpenInterest": "double",
    "ClosePrice": "double",
    "SettlementPrice": "double",
    "UpperLimitPrice": "double",
    "LowerLimitPrice": "double",
    "PreDelta": "double",
    "CurrDelta": "double",
    "UpdateTime": "int32",
    "BidPrice1": "double",
    "BidVolume1": "double",
    "AskPrice1": "double",
    "AskVolume1": "double",
    "BidPrice2": "double",
    "BidVolume2": "double",
    "AskPrice2": "double",
    "AskVolume2": "double",
    "BidPrice3": "double",
    "BidVolume3": "double",
    "AskPrice3": "double",
    "AskVolume3": "double",
    "BidPrice4": "double",
    "BidVolume4": "double",
    "AskPrice4": "double",
    "AskVolume4": "double",
    "BidPrice5": "double",
    "BidVolume5": "double",
    "AskPrice5": "double",
    "AskVolume5": "double",
    "AveragePrice": "double",
    "PreOpenInterest": "double",
    "InstrumentTradeStatus": "char",
    "OpenRestriction": "string",
    "IOPV": "double",
    "AuctionPrice": "double",
    "SendingTime": "int32",
}

CHSOrderActionField = {
    "AccountID": "string",
    "OrderSysID": "string",
    "BrokerOrderID": "string",
    "SessionID": "int32",
    "OrderRef": "string",
    "OrderActionRef": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "Direction": "char",
    "OffsetFlag": "char",
    "HedgeType": "char",
    "OrderPrice": "double",
    "OrderVolume": "double",
    "OrderActionStatus": "char",
    "OrderStatus": "char",
    "TradingDay": "int32",
    "ActionDate": "int32",
    "ActionTime": "int32",
    "ErrorMsg": "string",
    "UnderlyingInstrID": "string",
    "OrderSource": "char",
}

CHSReqFundTransField = {
    "TransDirection": "char",
    "CurrencyID": "char",
    "OccurBalance": "double",
}

CHSRspFundTransField = {
    "FundTransSerialID": "int32",
}

CHSReqQryFundTransField = {
}

CHSRspQryFundTransField = {
    "AccountID": "string",
    "TradingDay": "int32",
    "OccurDate": "int32",
    "OccurTime": "int32",
    "TransferSerialID": "int32",
    "CurrencyID": "char",
    "OccurBalance": "double",
    "PostBalance": "double",
}

CHSReqQryClientNoticeField = {
}

CHSClientNoticeField = {
    "AccountID": "string",
    "MsgBody": "string",
    "MsgTitle": "string",
    "MsgType": "char",
    "MsgDate": "int32",
    "MsgTime": "int32",
}

CHSReqQryOptUnderlyField = {
    "ExchangeID": "string",
    "UnderlyingInstrID": "string",
}

CHSRspQryOptUnderlyField = {
    "ExchangeID": "string",
    "UnderlyingInstrID": "string",
    "UnderlyingType": "string",
    "CurrencyID": "char",
    "UnderlyingStatus": "char",
    "UpperLimitPrice": "double",
    "LowerLimitPrice": "double",
    "UnderlyingHighAmount": "double",
    "UnderlyingLowAmount": "double",
    "VolumeMultiple": "double",
    "BuyUnit": "int32",
    "SellUnit": "int32",
    "PriceStep": "int32",
    "MarketDate": "int32",
    "DelistDate": "int32",
    "UnderlyingMarketHighAmount": "double",
    "UnderlyingMarketLowAmount": "double",
    "UnderlyingName": "string",
    "MarketBuyUnit": "int32",
    "MarketSellUnit": "int32",
    "UnderlyingValidDate": "int32",
    "UpdateType": "int32",
}

CHSReqQrySecuDepthMarketField = {
    "ExchangeID": "string",
    "UnderlyingInstrID": "string",
}

CHSRspQrySecuDepthMarketField = {
    "ExchangeID": "string",
    "UnderlyingInstrID": "string",
    "UnderlyingName": "string",
    "LastPrice": "double",
    "OpenPrice": "double",
    "UnderlyingPreClosePrice": "double",
    "HighestPrice": "double",
    "LowestPrice": "double",
    "TradeBalance": "double",
    "TradeVolume": "double",
    "BidPrice1": "double",
    "BidVolume1": "double",
    "AskPrice1": "double",
    "AskVolume1": "double",
    "BidPrice2": "double",
    "BidVolume2": "double",
    "AskPrice2": "double",
    "AskVolume2": "double",
    "BidPrice3": "double",
    "BidVolume3": "double",
    "AskPrice3": "double",
    "AskVolume3": "double",
    "BidPrice4": "double",
    "BidVolume4": "double",
    "AskPrice4": "double",
    "AskVolume4": "double",
    "BidPrice5": "double",
    "BidVolume5": "double",
    "AskPrice5": "double",
    "AskVolume5": "double",
}

CHSExchangeStatusField = {
    "ExchangeID": "string",
    "ExchangeStatus": "char",
    "TradingFlag": "char",
}

CHSProductStatusField = {
    "ExchangeID": "string",
    "ProductType": "char",
    "ProductID": "string",
    "TradingFlag": "char",
    "ProductStatus": "char",
}

CHSReqQryWithdrawFundField = {
    "CurrencyID": "char",
    "SysNodeID": "int32",
}

CHSRspQryWithdrawFundField = {
    "AccountID": "string",
    "CurrencyID": "char",
    "SysNodeID": "int32",
    "SysNodeName": "string",
    "WithdrawBalance": "double",
}

CHSReqQryCombInstrumentField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSRspQryCombInstrumentField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "Direction": "char",
    "SecondDirection": "char",
    "CombStrategyType": "char",
    "CombMarginCoeff": "double",
    "PriorityLevel": "double",
}

CHSReqQrySeatIDField = {
    "ExchangeID": "string",
}

CHSRspQrySeatIDField = {
    "ExchangeID": "string",
    "SeatIndex": "int32",
    "SeatID": "string",
}

CHSReqOptionSelfCloseField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "OrderVolume": "double",
    "SelfCloseType": "char",
}

CHSRspOptionSelfCloseField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "OrderVolume": "double",
    "SelfCloseType": "char",
}

CHSReqOptionSelfCloseActionField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "SelfCloseType": "char",
}

CHSRspOptionSelfCloseActionField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "SelfCloseType": "char",
}

CHSReqQryOptionSelfCloseField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSOptionSelfCloseField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "OrderVolume": "double",
    "SelfCloseType": "char",
    "OrderStatus": "char",
    "SetSelfCloseType": "char",
    "ErrorMsg": "string",
    "SelfCloseOrderSysID": "string",
}

CHSReqQryOptionSelfCloseResultField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSRspQryOptionSelfCloseResultField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "SelfCloseType": "char",
    "OrderVolume": "double",
}

CHSTransferField = {
    "AccountID": "string",
    "TransferSerialID": "int32",
    "BankID": "string",
    "BankName": "string",
    "BusinessName": "string",
    "OccurBalance": "double",
    "PostBalance": "double",
    "TransferTime": "int32",
    "TransferStatus": "char",
    "TransferSource": "char",
    "Remarks": "string",
    "CurrencyID": "char",
    "OrderSourceDate": "int32",
    "TradingDay": "int32",
    "TransferOccasion": "string",
}

CHSSMCertInfoField = {
    "CertID": "string",
    "OperatorID": "string",
    "DeviceID": "string",
    "CertInfo": "string",
    "SksPin": "string",
    "IsCurrent": "int",
}

CHSReqOptQuoteInsertField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "BidOffsetFlag": "char",
    "BidOrderPrice": "double",
    "BidOrderVolume": "double",
    "AskOffsetFlag": "char",
    "AskOrderPrice": "double",
    "AskOrderVolume": "double",
    "QuoteRef": "string",
    "ForQuoteSysID": "string",
}

CHSRspOptQuoteInsertField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "BidOffsetFlag": "char",
    "BidOrderPrice": "double",
    "BidOrderVolume": "double",
    "AskOffsetFlag": "char",
    "AskOrderPrice": "double",
    "AskOrderVolume": "double",
    "QuoteBrokerID": "string",
    "InsertTime": "int32",
    "BidOrderStatus": "char",
    "AskOrderStatus": "char",
    "QuoteRef": "string",
    "ForQuoteSysID": "string",
    "OrderStatus": "char",
    "SessionID": "int32",
}

CHSReqOptQuoteActionField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "BidWithdrawVolume": "double",
    "AskWithdrawVolume": "double",
    "QuoteActionRef": "string",
}

CHSRspOptQuoteActionField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "InsertTime": "int32",
    "QuoteBrokerID": "string",
    "BidWithdrawVolume": "double",
    "AskWithdrawVolume": "double",
    "BidOrderStatus": "char",
    "AskOrderStatus": "char",
    "QuoteActionRef": "string",
    "OrderStatus": "char",
    "SessionID": "int32",
}

CHSReqQryOptQuoteField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "QuoteQueryType": "char",
    "QuoteBrokerID": "string",
}

CHSOptQuoteField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "QuoteBrokerID": "string",
    "BidOffsetFlag": "char",
    "BidOrderPrice": "double",
    "BidOrderVolume": "double",
    "BidTradePrice": "double",
    "BidTradeVolume": "double",
    "BidCancelVolume": "double",
    "BidBrokerOrderID": "string",
    "BidOrderStatus": "char",
    "AskOffsetFlag": "char",
    "AskOrderPrice": "double",
    "AskOrderVolume": "double",
    "AskTradePrice": "double",
    "AskTradeVolume": "double",
    "AskCancelVolume": "double",
    "AskBrokerOrderID": "string",
    "AskOrderStatus": "char",
    "ErrorMsg": "string",
    "TradingDay": "int32",
    "InsertDate": "int32",
    "InsertTime": "int32",
    "ReportTime": "int32",
    "SessionID": "int32",
    "UnderlyingInstrID": "string",
    "QuoteRef": "string",
    "ForQuoteSysID": "string",
    "OrderStatus": "char",
}

CHSOptQuoteActionField = {
    "AccountID": "string",
    "ExchangeID": "string",
    "InstrumentID": "string",
    "TradingDay": "int32",
    "InsertDate": "int32",
    "InsertTime": "int32",
    "ReportTime": "int32",
    "SessionID": "int32",
    "QuoteActionRef": "string",
    "ErrorMsg": "string",
}

CHSReqQryOptCombStrategyField = {
    "ExchangeID": "string",
    "CombStrategyID": "string",
}

CHSRspQryOptCombStrategyField = {
    "ExchangeID": "string",
    "CombStrategyID": "string",
    "CombStrategyName": "string",
    "EndDateSameFlag": "char",
    "UnderlySameFlag": "char",
    "UnitSameFlag": "char",
    "ComponentNum": "int32",
    "FirstOptionsType": "char",
    "FirstPositionType": "char",
    "FirstExercisePriceSeq": "int32",
    "FirstPerInstrumentAmount": "int32",
    "SecondOptionsType": "char",
    "SecondPositionType": "char",
    "SecondExercisePriceSeq": "int32",
    "SecondPerInstrumentAmount": "int32",
    "NearSplitDays": "int32",
    "NonStandardInstrumentFlag": "char",
}

