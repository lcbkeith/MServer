#pragma once
#include "..\NetWork\AsioClientApp.h"

class IClient
{
public:
	IClient();
	virtual ~IClient();

	virtual void Tick();
	void Start(const char* host, int port);
protected:
private:
	AsioClientApp* m_clientApp;
};