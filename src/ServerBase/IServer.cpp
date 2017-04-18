#include "IServer.h"

void IServer::Start(int port)
{
	m_serverApp->AppStart(port, 4);
}

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

}