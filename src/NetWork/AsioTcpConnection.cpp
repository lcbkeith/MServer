#include "AsioTcpConnection.h"

AsioTcpConnection::AsioTcpConnection(io_service& io_service)
	:m_socket(io_service)
	, m_unHandledSize(0)
{

}

AsioTcpConnection::~AsioTcpConnection()
{

}

void AsioTcpConnection::Start()
{

	m_socket.set_option(boost::asio::socket_base::linger(true, 0));				//���Ϊtrue���׽��ֻ�����δ�������ݵ�����¹���close()
	m_socket.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));	//���Ϊtrue���׽����ܰ󶨵�һ�����õĵ�ַ(TODO ɶ��˼?)

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
		//m_conn->ProcessRecvData(bytes_transferred);

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

boost::asio::ip::tcp::socket& AsioTcpConnection::GetSocket()
{
	return m_socket;
}
