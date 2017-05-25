#pragma once
#include "../ServerBase/IServer.h"
class GatewayApp : public IServer
{
public:
	GatewayApp(){}
	virtual ~GatewayApp() {}
	virtual void OnStarted();
protected:
	virtual void OnClientConnected(AsioTcpConnection* conn) override;
	virtual void OnClientClosed(AsioTcpConnection* conn) override;
	virtual bool OnClientMsgRecv(AsioTcpConnection* conn, NetMessage* msg) override;

	void SendMessage(int64 connId, NetMessage& message);
private:
	std::map<int64, AsioTcpConnection*> conns;
};