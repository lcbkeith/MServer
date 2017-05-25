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
		std::cout << "HandleAccept ,thread:" << boost::this_thread::get_id()<< ",ip:" << conn->GetSocket().remote_endpoint().address() << std::endl;
		m_connList.push_back(conn);
		std::cout << "count" << m_connList.size() << std::endl;
		std::cout << "------------" << std::endl;
		conn->m_funcProcRecvMsg = m_delegateMsgRecv;
		conn->Start();
		if (m_delegateConnected)
		{
			m_delegateConnected(conn);
		}
	}
	StartAccept();
}

void AsioServerApp::Tick()
{
	if (m_workThreads.empty() && m_ioService)
	{
		m_ioService->poll_one();
	}
	char msg_copy_buffer[32 * 1024];
	NetMessage* recv_msg = (NetMessage*)&msg_copy_buffer[0];

	auto iter = m_connList.begin();
	for (; iter!= m_connList.end();)
	{
		AsioTcpConnection* conn = *iter;
		if (conn->IsClose())
		{
			if (conn->CanClose())
			{
				OnCloseConnection(conn);
				iter = m_connList.erase(iter);
			}
			else
			{
				iter++;
			}
			continue;
		}
		conn->Update();
		while (conn->GetMessage(recv_msg))
		{
			if (!conn->m_funcProcRecvMsg(conn, recv_msg))
			{
				break;
			}
		}
		iter++;
	}
}
