#include "AsioClientApp.h"
#include <boost/thread/detail/thread.hpp>
AsioClientApp::AsioClientApp()
	:m_sharedSvc(false)
	, m_autoReconnect(true)
	, m_isConnecting(false)
{
}

AsioClientApp::~AsioClientApp()
{
	delete m_resolver;
	m_resolver = nullptr;
	delete m_conn;
	m_conn = nullptr;

	if (!m_sharedSvc)
	{
		delete m_ioService;
		m_ioService = nullptr;
	}
}

void AsioClientApp::Start(const char* host, int port)
{
	if (m_ioService == nullptr)
	{
		m_ioService = new io_service;
	}
	m_resolver = new ip::tcp::resolver(*m_ioService);
	m_query = new ip::tcp::resolver::query(host, std::to_string(port).c_str());
	m_rsvIter = m_resolver->resolve(*m_query);

	m_conn = new AsioTcpConnection(*m_ioService);
	StartConnect();
}

void AsioClientApp::OnConn(AsioTcpConnection* conn, const boost::system::error_code& err)
{
	m_isConnecting = false;
	if (!conn->GetSocket().is_open())
	{
		if (m_autoReconnect)
		{
			StartConnect();
		}
		return;
	}
	if (err)
	{
		m_conn->GetSocket().close();
		if (m_autoReconnect)
		{
			StartConnect();
		}
	}
	else
	{
		conn->m_funcProcRecvMsg = m_delegateMsgRecv;
		conn->Start();
		if (m_delegateConnected)
		{
			m_delegateConnected(conn);
		}
	}
}

void AsioClientApp::SetIOService(io_service& ioService)
{
	m_ioService = &ioService;
	m_sharedSvc = true;
}

void AsioClientApp::Tick()
{
	m_ioService->poll_one();
	if (m_conn->IsStoped())
	{
		StartConnect();
		return;
	}
	if (m_conn->IsClose())
	{
		if (m_conn->CanClose())
		{
			OnCloseConnection(m_conn);
		}
		return;
	}

	m_conn->Update();
	char msg_copy_buffer[32 * 1024];
	NetMessage* recv_msg = (NetMessage*)&msg_copy_buffer[0];
	while (m_conn->GetMessage(recv_msg))
	{
		if (!m_conn->m_funcProcRecvMsg(m_conn, recv_msg))
		{
			break;
		}
	}
}

void AsioClientApp::StartConnect()
{
	if (!m_isConnecting)
	{
		m_isConnecting = true;
		std::cout << "Client StartConnect " << std::endl;
		//m_conn->GetSocket().async_connect(m_rsvIter->endpoint(), boost::bind(&AsioClientApp::OnConn, this, m_conn, boost::asio::placeholders::error));
		boost::asio::async_connect(m_conn->GetSocket(), m_rsvIter, boost::bind(&AsioClientApp::OnConn, this, m_conn, boost::asio::placeholders::error));
	}
}

