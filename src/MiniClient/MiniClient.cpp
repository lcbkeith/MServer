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

	char msg_copy_buffer[32 * 1024];
	NetMessage* msg = (NetMessage*)msg_copy_buffer;
	while (m_clientApp->GetConnect()->GetMessage(msg))
	{
		if (!OnMsgRecv(m_clientApp->GetConnect(), msg))
		{
			break;
		}
	}

}

void MiniClient::OnStarted()
{
	m_clientApp->SetDelegateConnected(boost::bind(&MiniClient::OnClientConnected, this, _1));
	m_clientApp->SetDelegateConnClosed(boost::bind(&MiniClient::OnClientClosed, this, _1));
	m_clientApp->SetDelegateMsgRecv(boost::bind(&MiniClient::OnMsgRecv, this, _1, _2));
}

void MiniClient::OnClientConnected(AsioTcpConnection* conn)
{
	std::cout << "AsioClientApp::Connected,thread:" << boost::this_thread::get_id() << ",ip:" << conn->GetSocket().remote_endpoint().address() << std::endl;
}

void MiniClient::OnClientClosed(AsioTcpConnection* conn)
{
	std::cout << "AsioClientApp::Closed,thread:" << boost::this_thread::get_id() << ",ip:" << conn->GetSocket().remote_endpoint().address() << std::endl;
}

bool MiniClient::OnMsgRecv(AsioTcpConnection* conn, NetMessage* msg)
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
