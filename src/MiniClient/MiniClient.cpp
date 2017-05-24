#include "MiniClient.h"

MiniClient::MiniClient()
{

}

MiniClient::~MiniClient()
{

}

void MiniClient::Update()
{
	IClient::Tick();
}

void MiniClient::OnStarted()
{
	
}

void MiniClient::OnServerConnected(AsioTcpConnection* conn)
{
	std::cout << "AsioClientApp::Connected,thread:" << boost::this_thread::get_id() << ",ip:" << conn->GetSocket().remote_endpoint().address() << std::endl;
}

void MiniClient::OnConnectionClosed(AsioTcpConnection* conn)
{
	std::cout << "AsioClientApp::Closed,thread:" << boost::this_thread::get_id() << ",ip:" << conn->GetSocket().remote_endpoint().address() << std::endl;
}

bool MiniClient::OnServerMsgRecv(AsioTcpConnection* conn, NetMessage* msg)
{
	switch (msg->MessageId)
	{
	case 1:
	{
		MsgMarkClient* castMsg = (MsgMarkClient*)msg;
		m_serverMarkId = castMsg->m_markId;

		MsgClientResponse newMsg;
		newMsg.m_responseId = m_serverMarkId;
		SendMessage(newMsg);
	}
	break;
	default:
		break;
	}
	return true;
}

void MiniClient::SendMessage(NetMessage& msg)
{
	m_clientApp->GetConnect()->Send(msg);
}
