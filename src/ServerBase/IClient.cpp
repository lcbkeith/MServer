#include "IClient.h"
IClient::IClient()
{
	m_clientApp = new AsioClientApp;
}

IClient::~IClient()
{
	if (m_clientApp)
	{
		delete m_clientApp;
		m_clientApp = NULL;
	}
}

void IClient::Tick()
{
	m_clientApp->Tick();
}

void IClient::Start(const char* host, int port)
{
	m_clientApp->Start(host, port);
	m_clientApp->SetDelegateConnected(boost::bind(&IClient::OnServerConnected, this, _1));
	m_clientApp->SetDelegateConnClosed(boost::bind(&IClient::OnConnectionClosed, this, _1));
	m_clientApp->SetDelegateMsgRecv(boost::bind(&IClient::OnServerMsgRecv, this, _1, _2));
	OnStarted();
}

