#include "AsioTcpConnection.h"
int64 AsioTcpConnection::m_connAllocID = 1024;
AsioTcpConnection::AsioTcpConnection(io_service& io_service)
	:m_socket(io_service)
	, m_unHandledSize(0)
	, m_connID(m_connAllocID++)
	, m_isReceiving(false)
{

}

AsioTcpConnection::~AsioTcpConnection()
{

}

void AsioTcpConnection::Start()
{
	m_socket.set_option(boost::asio::socket_base::linger(true, 0));				//如果为true，套接字会在有未发送数据的情况下挂起close()
	m_socket.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));	//如果为true，套接字能绑定到一个已用的地址(TODO 啥意思?)

//	m_isRecving = true;
	char* buf = m_recvBuffer + m_unHandledSize;
	int size = sizeof(m_recvBuffer) - m_unHandledSize;
	m_socket.async_read_some(boost::asio::buffer(buf, size),
		boost::bind(&AsioTcpConnection::HandleRead, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

void AsioTcpConnection::Update()
{

}

void AsioTcpConnection::HandleRead(const boost::system::error_code& error, size_t bytesTransfered)
{
	if (!error)
	{
		OnReceiveData(bytesTransfered);

		char* buf = m_recvBuffer + m_unHandledSize;
		int size = sizeof(m_recvBuffer) - m_unHandledSize;
		m_socket.async_read_some(boost::asio::buffer(buf, size),
			boost::bind(&AsioTcpConnection::HandleRead, this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}
	else
	{
// 		m_close = true;
// 		m_isRecving = false;
	}
}

void AsioTcpConnection::HandleWrite(const boost::system::error_code& error, size_t bytesTransfered)
{

}


void AsioTcpConnection::OnReceiveData(int size)
{
	if (size <= 0)
	{
		return;
	}
	m_unHandledSize += size;
	while (m_unHandledSize > 0)
	{
		for (int idx = 0; idx < sizeof(m_recvBuffer); idx++)
		{
			if (m_recvBuffer[idx] == '\n')
			{
				int readSize = idx + 1;
				std::cout << std::string(m_recvBuffer) << std::endl;
				m_unHandledSize -= readSize;
				if (m_unHandledSize > 0)
				{
					memcpy(m_recvBuffer, m_recvBuffer + readSize, sizeof(m_recvBuffer) - readSize);
				}
				
				break;
			}
		}
	}
	
	
}

boost::asio::ip::tcp::socket& AsioTcpConnection::GetSocket()
{
	return m_socket;
}


