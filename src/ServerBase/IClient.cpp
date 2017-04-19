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

}

void IClient::Start(const char* host, int port)
{
	m_clientApp->Start(host, port);
}

