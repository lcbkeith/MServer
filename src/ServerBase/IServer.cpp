#include "IServer.h"

IServer::IServer()
{
	m_serverApp = new AsioServerApp;
}

IServer::~IServer()
{
	if (m_serverApp)
	{
		delete m_serverApp;
		m_serverApp = NULL;
	}
}

void IServer::Tick()
{
	m_serverApp->Tick();
}

void IServer::Start(int port)
{
	m_serverApp->AppStart(port, 4);

	m_serverApp->SetDelegateConnected(boost::bind(&IServer::OnClientConnected, this, _1));
	m_serverApp->SetDelegateConnClosed(boost::bind(&IServer::OnClientClosed, this, _1));
	m_serverApp->SetDelegateMsgRecv(boost::bind(&IServer::OnClientMsgRecv, this, _1, _2));

	OnStarted();
}

