#include "MiniClient.h"

MiniClient::MiniClient()
{

}

MiniClient::~MiniClient()
{

}

void MiniClient::OnServerConnected(AsioTcpConnection* conn)
{
	std::cout << "AsioClientApp::Connected,thread:" << boost::this_thread::get_id() << std::endl;
}

void MiniClient::OnConnectionClosed(AsioTcpConnection* conn)
{
	std::cout << "ID" << GetID() << ",AsioClientApp::Closed,thread:" << boost::this_thread::get_id() << std::endl;
}

bool MiniClient::OnServerMsgRecv(AsioTcpConnection* conn, NetMessage* msg)
{
	switch (msg->MessageId)
	{
	case 1:
	{
		MsgMarkClient* castMsg = (MsgMarkClient*)msg;
		m_serverMarkId = castMsg->m_markId;

		std::cout << "MsgMarkClient :" << m_serverMarkId << std::endl;
		for (int index = 0; index < 10 ; index++)
		{
			MsgClientResponse newMsg;
			newMsg.m_responseId = m_serverMarkId;
			SendMessage(newMsg);
		}
		m_clientApp->GetConnect()->ReqClose();
		//boost::this_thread::sleep(boost::posix_time::milliseconds(3000));
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
