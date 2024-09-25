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

case ONRSPDEPTHMARKETDATASUBSCRIBE:
{
	this->processRspDepthMarketDataSubscribe(&task);
	break;
}

case ONRSPDEPTHMARKETDATACANCEL:
{
	this->processRspDepthMarketDataCancel(&task);
	break;
}

case ONRTNDEPTHMARKETDATA:
{
	this->processRtnDepthMarketData(&task);
	break;
}

case ONRSPFORQUOTESUBSCRIBE:
{
	this->processRspForQuoteSubscribe(&task);
	break;
}

case ONRSPFORQUOTECANCEL:
{
	this->processRspForQuoteCancel(&task);
	break;
}

case ONRTNFORQUOTE:
{
	this->processRtnForQuote(&task);
	break;
}

