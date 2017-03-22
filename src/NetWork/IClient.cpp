#include "IClient.h"
#include <string>
#include <boost/thread.hpp>

IClient::IClient(io_service* io_svc) :m_sharedSvc(true), m_socket(nullptr)
{
	if (io_svc == nullptr)
	{
		m_sharedSvc = false;
		io_svc = new io_service;
	}
	m_ioService = io_svc;
	m_resolver = new ip::tcp::resolver(*m_ioService);
}

IClient::~IClient()
{
	if (!m_sharedSvc)
	{
		delete m_ioService;
		m_ioService = nullptr;
	}
	delete m_resolver;
	m_resolver = nullptr;
	delete m_socket;
	m_socket = nullptr;
}

void IClient::Start(const char* host, int port)
{
	ip::tcp::resolver::query query(host, std::to_string(port).c_str());
	m_rsvIter = m_resolver->resolve(query);
	m_socket = new ip::tcp::socket(*m_ioService);
	boost::asio::async_connect(*m_socket, m_rsvIter, boost::bind(&IClient::OnConn, this, m_socket, boost::asio::placeholders::error) );

	m_workThread = boost::thread(boost::bind(&io_service::run, m_ioService));
}

void IClient::OnConn(ip::tcp::socket* socket, const boost::system::error_code& err)
{
	std::cout << "accept" << socket->remote_endpoint().address() << std::endl;
}

