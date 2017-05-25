#pragma once
#include "AsioClientApp.h"
class IClient
{
public:
	IClient();
	virtual ~IClient();

	virtual void Tick();
	void Start(const char* host, int port);
	virtual void OnStarted() {}

	virtual void OnServerConnected(AsioTcpConnection* conn) = 0;
	virtual void OnConnectionClosed(AsioTcpConnection* conn) = 0;
	virtual bool OnServerMsgRecv(AsioTcpConnection* conn, NetMessage* msg) = 0;
protected:
	AsioClientApp* m_clientApp;
private:
};