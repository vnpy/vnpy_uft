int MdApi::reqDepthMarketDataSubscribe(const dict &req, int reqid)
{
	CHSReqDepthMarketDataField myreq = CHSReqDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqDepthMarketDataSubscribe(&myreq, reqid);
	return i;
};

int MdApi::reqDepthMarketDataCancel(const dict &req, int reqid)
{
	CHSReqDepthMarketDataField myreq = CHSReqDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqDepthMarketDataCancel(&myreq, reqid);
	return i;
};

int MdApi::reqForQuoteSubscribe(const dict &req, int reqid)
{
	CHSReqForQuoteField myreq = CHSReqForQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqForQuoteSubscribe(&myreq, reqid);
	return i;
};

int MdApi::reqForQuoteCancel(const dict &req, int reqid)
{
	CHSReqForQuoteField myreq = CHSReqForQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqForQuoteCancel(&myreq, reqid);
	return i;
};

