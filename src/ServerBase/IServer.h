#pragma once
#include "../NetWork/AsioServerApp.h"

class IServer
{
public:
	IServer();
	virtual ~IServer();
	void Tick();
	void Start(int port);
	virtual void OnStarted() {}
protected:
	AsioServerApp* m_serverApp;
};