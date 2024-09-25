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

