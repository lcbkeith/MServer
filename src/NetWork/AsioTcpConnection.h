#pragma once
#include <boost/asio.hpp>
#include <boost/bind.hpp>
using namespace boost;
using namespace boost::asio;

class AsioTcpConnection
{
public:
	AsioTcpConnection(io_service& io_service);
	~AsioTcpConnection();

	void Start();
	void Update();
	void HandleRead(const boost::system::error_code& error, size_t bytesTransfered);
	void HandleWrite(const boost::system::error_code& error, size_t bytesTransfered);
	
	ip::tcp::socket& GetSocket();
private:
	ip::tcp::socket m_socket;

	char m_recvBuffer[4*1024];
	int m_unHandledSize;
};
