#pragma once
#include "includes.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "NetMessage.h"
#include "MessageQueue.h"
using namespace boost;
using namespace boost::asio;


class AsioTcpConnection
{
public:
	AsioTcpConnection(io_service& io_service);
	~AsioTcpConnection();
	int64 GetID() { return m_connID; }

	void Start();
	void Update();
	void Close();
	void HandleRead(const boost::system::error_code& error, size_t bytesTransfered);
	void HandleWrite(const boost::system::error_code& error, size_t bytesTransfered);

	void OnReceiveData(int size);
	void Send(NetMessage& msg);
	void ForceSend();
	bool GetMessage(NetMessage* msg);

	void ReqClose();
	bool IsClose() { return m_close; }
	bool CanClose() { return !m_isRecving && !m_isSending; }
	bool IsStoped() { return m_stoped; }
	
	ip::tcp::socket& GetSocket();
	boost::function<bool(AsioTcpConnection*, NetMessage*)> m_funcProcRecvMsg;
private:
	ip::tcp::socket m_socket;
	char m_recvBuffer[4 * 1024];
	char m_sendBuffer[4 * 1024];

	MessageQueue* m_inQueue;
	MessageQueue* m_outQueue;

	int m_sendingBytes;
	int m_unHandledSize;
	int64 m_connID;
	static int64 m_connAllocID;

	bool m_stoped;
	bool m_close;
	bool m_isRecving;
	bool m_isSending;
};


