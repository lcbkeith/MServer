#pragma once
#include "../ServerBase/IClient.h"
#include "../ServerBase/Obj.h"

class MiniClient : public IClient, public Obj
{
public:
	MiniClient();
	virtual ~MiniClient();
	void SetIOService(io_service& service) { m_clientApp->SetIOService(service); }
	void Update();
	virtual void OnStarted();

	void OnClientConnected(AsioTcpConnection* conn);
	void OnClientClosed(AsioTcpConnection* conn);
	bool OnMsgRecv(AsioTcpConnection* conn, NetMessage* msg);

	void SendMessage(NetMessage& msg);

protected:
private:
	int64 m_serverMarkId;
};