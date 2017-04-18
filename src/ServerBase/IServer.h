#pragma once
#include "..\NetWork\AsioServerApp.h"

class IServer
{
public:
	IServer();
	virtual ~IServer();
	virtual void Tick();
	void Start(int port);

protected:
private:
	AsioServerApp* m_serverApp;
};