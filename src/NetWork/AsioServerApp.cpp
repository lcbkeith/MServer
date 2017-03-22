#include "AsioServerApp.h"

AsioServerApp::AsioServerApp():
	m_ioService(nullptr),
	m_accecptor(nullptr)
{
	m_ioService = new boost::asio::io_service;
}

AsioServerApp::~AsioServerApp()
{
	if (m_ioService)
	{
		delete m_ioService;
		m_ioService = nullptr;
	}
	if (m_accecptor)
	{
		delete m_accecptor;
		m_accecptor = nullptr;
	}
}

void AsioServerApp::AppStart(int port, int threadCount)
{
	if (!m_accecptor)
	{
		m_accecptor = new tcp::acceptor(*m_ioService, tcp::endpoint(tcp::v4(), port));
	}
}

void AsioServerApp::StartAccept()
{
	if (!m_accecptor)
	{
		return;
	}

	AsioTcpConnection* newConn = new AsioTcpConnection(*m_ioService);
	m_accecptor->async_accept(
		newConn->GetSocket(),
		boost::bind(&AsioServerApp::HandleAccept, this, newConn, boost::asio::placeholders::error) );

}

void AsioServerApp::HandleAccept(AsioTcpConnection* conn, const boost::system::error_code& err)
{
	if (err)
	{
		delete conn;
	}
	else
	{
		//Set event funcs;
		std::cout << "HandleAccept " << conn->GetSocket().remote_endpoint().address() << std::endl;
	}
	StartAccept();
}
