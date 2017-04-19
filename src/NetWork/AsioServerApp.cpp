#include "AsioServerApp.h"

AsioServerApp::AsioServerApp()
	:m_ioService(nullptr),
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
	StartAccept();
	for (int i = 0; i < threadCount; i++)
	{
		boost::thread* t = new boost::thread(boost::bind(&boost::asio::io_service::run, m_ioService));
		m_workThreads.push_back(t);
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
		m_connList.push_back(conn);
	}
	StartAccept();
}

void AsioServerApp::Tick()
{
	if (m_workThreads.empty() && m_ioService)
	{
		m_ioService->poll_one();
	}
}
