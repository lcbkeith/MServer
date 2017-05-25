#include "GatewayApp.h"

void GatewayApp::OnStarted()
{
	
}

void GatewayApp::OnClientConnected(AsioTcpConnection* conn)
{
	std::cout << " GatewayApp::OnClientConnected:" << conn->GetID() << std::endl;
	conns.insert(std::make_pair(conn->GetID(), conn));

	MsgMarkClient msg;
	msg.m_markId = conn->GetID();
	SendMessage(conn->GetID(), msg);
}

void GatewayApp::OnClientClosed(AsioTcpConnection* conn)
{
	std::cout << " GatewayApp::OnClientClosed:" << conn->GetID() << std::endl;
	conns.erase(conn->GetID());
}


bool GatewayApp::OnClientMsgRecv(AsioTcpConnection* conn, NetMessage* msg)
{
	switch (msg->MessageId)
	{
	case 2:
	{
		MsgClientResponse* response = (MsgClientResponse*)msg;
		int64 resId = response->m_responseId;
		if (resId != conn->GetID())
		{
			std::cout << "not equal fuck!" << std::endl;
		}
	}
		break;
	default:
		break;
	}
	return true;
}

void GatewayApp::SendMessage(int64 connId, NetMessage& message)
{
	auto iter = conns.find(connId);
	if (iter == conns.end())
	{
		return;
	}
	AsioTcpConnection* conn = iter->second;
	conn->Send(message);
}

void GatewayApp::Update()
{
	IServer::Tick();
	char msg_copy_buffer[32 * 1024];
	NetMessage* msg = (NetMessage*)msg_copy_buffer;
	auto iter = conns.begin();
	for (; iter!= conns.end(); iter++)
	{
		AsioTcpConnection* conn = iter->second;
		while (conn->GetMessage(msg))
		{
			if (!OnClientMsgRecv(conn, msg))
			{
				break;
			}
		}
	}
	
}
