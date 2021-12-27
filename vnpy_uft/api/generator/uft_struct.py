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

CHSReqCombActionInsertField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "CombStrategyID": "string",
    "CombPositionID": "string",
    "CombDirection": "char",
    "OrderVolume": "double",
    "HedgeType": "char",
    "Direction": "char",
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
}

CHSReqQryOrderField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "OrderSysID": "string",
}

CHSReqQryHistOrderField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "OrderSysID": "string",
    "BeginDate": "int32",
    "EndDate": "int32",
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
}

CHSReqQryTradeField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
}

CHSReqQryHistTradeField = {
    "ExchangeID": "string",
    "InstrumentID": "string",
    "BeginDate": "int32",
    "EndDate": "int32",
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
}

CHSReqQryPositionCombineDetailField = {
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
    "MsgContent": "string",
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
