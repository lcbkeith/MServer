#pragma once
#include "..\NetWork\AsioClientApp.h"

class IClient
{
public:
	IClient();
	virtual ~IClient();

	virtual void Tick();
	void Start(const char* host, int port, int threadCount = 0);
protected:
	AsioClientApp* m_clientApp;
private:
};