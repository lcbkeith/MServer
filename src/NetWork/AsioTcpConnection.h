#pragma once
#include "includes.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "NetMessage.h"
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
	void HandleRead(const boost::system::error_code& error, size_t bytesTransfered);
	void HandleWrite(const boost::system::error_code& error, size_t bytesTransfered);
	
	ip::tcp::socket& GetSocket();
private:
	ip::tcp::socket m_socket;

	char m_recvBuffer[4*1024];
	int m_unHandledSize;
	int64 m_connID;
	bool m_isReceiving;
	static int64 m_connAllocID;
};

typedef boost::function<void(AsioTcpConnection*)>				DelegateOnConnected;
typedef boost::function<void(AsioTcpConnection*)>				DelegateOnConnClosed;
typedef boost::function<void(AsioTcpConnection*, NetMessage*)>	DelegateMsgRecv;