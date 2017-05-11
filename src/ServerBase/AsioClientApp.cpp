#include "AsioClientApp.h"
#include <boost/thread/detail/thread.hpp>
AsioClientApp::AsioClientApp()
	:m_sharedSvc(false)
{
}

AsioClientApp::~AsioClientApp()
{
	if (!m_sharedSvc)
	{
		delete m_ioService;
		m_ioService = nullptr;
	}
	delete m_resolver;
	m_resolver = nullptr;
	delete m_conn;
	m_conn = nullptr;
}

void AsioClientApp::Start(const char* host, int port, int threadCount)
{
	if (m_ioService == nullptr)
	{
		m_ioService = new io_service;
	}
	m_resolver = new ip::tcp::resolver(*m_ioService);
	m_query = new ip::tcp::resolver::query(host, std::to_string(port).c_str());
	m_rsvIter = m_resolver->resolve(*m_query);

	m_conn = new AsioTcpConnection(*m_ioService);

	boost::asio::async_connect(m_conn->GetSocket(), m_rsvIter, boost::bind(&AsioClientApp::OnConn, this, m_conn, boost::asio::placeholders::error));

	for (int idx = 0; idx < threadCount; idx++)
	{
		boost::thread* thread = new boost::thread(boost::bind(&boost::asio::io_service::run, m_ioService));
		m_workThreads.push_back(thread);
	}
}

void AsioClientApp::OnConn(AsioTcpConnection* conn, const boost::system::error_code& err)
{
	if (err)
	{
		//reconn config
		boost::asio::async_connect(conn->GetSocket(), m_rsvIter,
			boost::bind(&AsioClientApp::OnConn, this, conn, boost::asio::placeholders::error));
	}
	else
	{
		std::cout << "AsioClientApp::OnConn,thread" << boost::this_thread::get_id()<< ",ip:" << conn->GetSocket().remote_endpoint().address() << std::endl;

		conn->Start();
	}
}

void AsioClientApp::SetIOService(io_service& ioService)
{
	m_ioService = &ioService;
	m_sharedSvc = true;
}

void AsioClientApp::Tick()
{
	m_conn->Update();
	if (m_workThreads.empty())
	{
		m_ioService->poll_one();
	}

}

