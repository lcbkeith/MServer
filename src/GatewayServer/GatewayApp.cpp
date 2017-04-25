#include "GatewayApp.h"

void GatewayApp::OnStarted()
{
	m_serverApp->SetDelegateConnected(boost::bind(&GatewayApp::OnClientConnected, this, _1));
	m_serverApp->SetDelegateConnClosed(boost::bind(&GatewayApp::OnClientClosed, this, _1));
}

void GatewayApp::OnClientConnected(AsioTcpConnection* conn)
{
	std::cout << " GatewayApp::OnClientConnected:" << conn->GetID() << std::endl;
	conns.insert(std::make_pair(conn->GetID(), conn));
}

void GatewayApp::OnClientClosed(AsioTcpConnection* conn)
{
	std::cout << " GatewayApp::OnClientClosed:" << conn->GetID() << std::endl;
	conns.erase(conn->GetID());
}
