#include "AsioTcpConnection.h"

AsioTcpConnection::AsioTcpConnection(io_service& io_service):m_socket(io_service)
{

}

boost::asio::ip::tcp::socket& AsioTcpConnection::GetSocket()
{
	return m_socket;
}
