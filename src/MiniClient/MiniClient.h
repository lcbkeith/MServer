#pragma once
#include "../ServerBase/IClient.h"
#include "../ServerBase/Obj.h"

class MiniClient : public IClient, public Obj
{
public:
	MiniClient();
	virtual ~MiniClient();
	void SetIOService(io_service& service) { m_clientApp->SetIOService(service); }	
	virtual void OnServerConnected (AsioTcpConnection* conn) override;
	virtual void OnConnectionClosed(AsioTcpConnection* conn) override;
	virtual bool OnServerMsgRecv(AsioTcpConnection* conn, NetMessage* msg) override;

	void SendMessage(NetMessage& msg);

protected:
private:
	int64 m_serverMarkId;
};