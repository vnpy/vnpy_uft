.def("reqDepthMarketDataSubscribe", &MdApi::reqDepthMarketDataSubscribe)
.def("reqDepthMarketDataCancel", &MdApi::reqDepthMarketDataCancel)
.def("reqForQuoteSubscribe", &MdApi::reqForQuoteSubscribe)
.def("reqForQuoteCancel", &MdApi::reqForQuoteCancel)

.def("onFrontConnected", &MdApi::onFrontConnected)
.def("onFrontDisconnected", &MdApi::onFrontDisconnected)
.def("onRspDepthMarketDataSubscribe", &MdApi::onRspDepthMarketDataSubscribe)
.def("onRspDepthMarketDataCancel", &MdApi::onRspDepthMarketDataCancel)
.def("onRtnDepthMarketData", &MdApi::onRtnDepthMarketData)
.def("onRspForQuoteSubscribe", &MdApi::onRspForQuoteSubscribe)
.def("onRspForQuoteCancel", &MdApi::onRspForQuoteCancel)
.def("onRtnForQuote", &MdApi::onRtnForQuote)
;
