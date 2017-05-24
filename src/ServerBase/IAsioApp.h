#pragma once
#include "AsioTcpConnection.h"

class IAsioApp
{
public:
	typedef boost::function<void(AsioTcpConnection*)>				DelegateOnConnected;
	typedef boost::function<void(AsioTcpConnection*)>				DelegateOnConnClosed;
	typedef boost::function<bool(AsioTcpConnection*, NetMessage*)>	DelegateMsgRecv;

	void SetDelegateConnected(DelegateOnConnected func) { m_delegateConnected = func; }
	void SetDelegateConnClosed(DelegateOnConnClosed func) { m_delegateConnClosed = func; }
	void SetDelegateMsgRecv(DelegateMsgRecv func) { m_delegateMsgRecv = func; }
protected:
	DelegateOnConnected m_delegateConnected;
	DelegateOnConnClosed m_delegateConnClosed;
	DelegateMsgRecv m_delegateMsgRecv;
private:
};