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
	void OnCloseConnection(AsioTcpConnection* conn)
	{
		if (m_delegateConnClosed)
		{
			m_delegateConnClosed(conn);
		}
		conn->Close();
	}
protected:
	DelegateOnConnected			m_delegateConnected;
	DelegateOnConnClosed		m_delegateConnClosed;
	DelegateMsgRecv				m_delegateMsgRecv;
};
