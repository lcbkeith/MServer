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

void IClient::Start(const char* host, int port, int threadCount)
{
	m_clientApp->Start(host, port, threadCount);
	OnStarted();
}

