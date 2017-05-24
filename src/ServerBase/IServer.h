#pragma once
#include "AsioServerApp.h"

class IServer
{
public:
	IServer();
	virtual ~IServer();
	void Tick();
	void Start(int port);
	virtual void OnStarted() {}

	virtual void OnClientConnected(AsioTcpConnection* conn) = 0;
	virtual void OnClientClosed(AsioTcpConnection* conn) = 0;
	virtual bool OnClientMsgRecv(AsioTcpConnection* conn, NetMessage* message) = 0;
protected:
	AsioServerApp* m_serverApp;
};