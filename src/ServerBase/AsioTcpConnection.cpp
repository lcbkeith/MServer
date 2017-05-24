#include "AsioTcpConnection.h"
int64 AsioTcpConnection::m_connAllocID = 1024;
AsioTcpConnection::AsioTcpConnection(io_service& io_service)
	: m_socket(io_service)
	, m_unHandledSize(0)
	, m_connID(m_connAllocID++)
	, m_sendingBytes(0)
	, m_close(false)
	, m_isRecving(false)
	, m_isSending(false)
{
	static MemoryPool pool;
	m_inQueue = new MessageQueue(&pool);
	m_outQueue = new MessageQueue(&pool);
}

AsioTcpConnection::~AsioTcpConnection()
{

}

void AsioTcpConnection::Start()
{
	m_socket.set_option(boost::asio::socket_base::linger(true, 0));				//如果为true，套接字会在有未发送数据的情况下挂起close()
	m_socket.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));	//如果为true，套接字能绑定到一个已用的地址(TODO 啥意思?)

	m_isRecving = true;
	char* buf = m_recvBuffer + m_unHandledSize;
	int size = sizeof(m_recvBuffer) - m_unHandledSize;
	m_socket.async_read_some(boost::asio::buffer(buf, size),
		boost::bind(&AsioTcpConnection::HandleRead, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

void AsioTcpConnection::Update()
{
	//close check return
	ForceSend();
}

void AsioTcpConnection::HandleRead(const boost::system::error_code& error, size_t bytesTransfered)
{
	if (!error && m_isRecving)
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
 		m_close = true;
 		m_isRecving = false;
	}
}

void AsioTcpConnection::HandleWrite(const boost::system::error_code& error, size_t bytesTransfered)
{
	memcpy(m_sendBuffer, m_sendBuffer + bytesTransfered, m_sendingBytes - bytesTransfered);
	ForceSend();
	m_isSending = false;
	if (error)
	{
		m_close = true;
	}	
}

void AsioTcpConnection::OnReceiveData(int size)
{
	if (size <= 0)
	{
		return;
	}
	m_unHandledSize += size;
	NetMessage* msg = (NetMessage*)m_recvBuffer;
	while (m_unHandledSize > 0)
	{
		short msgLength = msg->Length;
		//todo assert length;
		if (m_unHandledSize >= msgLength)
		{
			m_inQueue->PushMessage(msg);
			m_unHandledSize -= msgLength;
		}
		else
		{
			break;
		}
	}
	
	
}

void AsioTcpConnection::Send(NetMessage& msg)
{
	m_outQueue->PushMessage(&msg);
	//check
	ForceSend();
}


void AsioTcpConnection::ForceSend()
{
	if (m_outQueue->Empty())
	{
		return;
	}
	int bytes = m_outQueue->PopEnoughMessage(m_sendBuffer + m_sendingBytes, sizeof(m_sendBuffer) - m_sendingBytes);
	if (bytes > 0)
	{
		m_sendingBytes += bytes;
		m_socket.async_write_some(boost::asio::buffer(m_sendBuffer, m_sendingBytes),
			boost::bind(&AsioTcpConnection::HandleWrite, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)
		);
	}
}


bool AsioTcpConnection::GetMessage(NetMessage* msg)
{
	if (m_inQueue->Empty())
	{
		return false;
	}
	if (m_inQueue->PopMessage(msg))
	{
		return true;
	}
	return false;
}

boost::asio::ip::tcp::socket& AsioTcpConnection::GetSocket()
{
	return m_socket;
}


