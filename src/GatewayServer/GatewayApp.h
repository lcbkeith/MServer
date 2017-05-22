#pragma once
#include "../ServerBase/IServer.h"
class GatewayApp : public IServer
{
public:
	GatewayApp(){}
	virtual ~GatewayApp() {}
	virtual void OnStarted();
protected:
	void OnClientConnected(AsioTcpConnection* conn);
	void OnClientClosed(AsioTcpConnection* conn);
	bool OnClientMsgRecv(AsioTcpConnection* conn, NetMessage* msg);
	void SendMessage(int64 connId, NetMessage& message);
	
	void Update();
private:
	std::map<int64, AsioTcpConnection*> conns;
};