#pragma once
#include "AsioClientApp.h"
class IClient
{
public:
	IClient();
	virtual ~IClient();

	virtual void Tick();
	void Start(const char* host, int port, int threadCount = 0);
	virtual void OnStarted() {}
protected:
	AsioClientApp* m_clientApp;
private:
};