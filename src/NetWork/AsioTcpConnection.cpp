#include "AsioTcpConnection.h"

AsioTcpConnection::AsioTcpConnection(io_service& io_service):m_socket(io_service)
{

}

AsioTcpConnection::~AsioTcpConnection()
{

}

void AsioTcpConnection::Start()
{

}

void AsioTcpConnection::Update()
{

}

void AsioTcpConnection::HandleRead(const boost::system::error_code& error, size_t bytesTransfered)
{

}

void AsioTcpConnection::HandleWrite(const boost::system::error_code& error, size_t bytesTransfered)
{

}

boost::asio::ip::tcp::socket& AsioTcpConnection::GetSocket()
{
	return m_socket;
}
