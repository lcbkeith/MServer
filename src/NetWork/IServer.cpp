#include "IServer.h"
#include <boost/bind.hpp>

IServer::~IServer()
{
	if (m_acceptor)
	{
		delete m_acceptor;
		m_acceptor = nullptr;
	}
}

void IServer::Start(int port)
{
	std::string selfIp = "127.0.0.1";
	m_acceptor = new TCPAcceptor(m_ioService, selfIp, port, boost::bind(&IServer::HandleAccept,this,_1));

	m_workThread = boost::thread(boost::bind(&io_service::run, &m_ioService));

}

void IServer::Tick(uint diff)
{
	m_ioService.poll_one();
}

void IServer::HandleAccept(ip::tcp::socket& socket)
{
	std::cout << "accept" << socket.remote_endpoint().address() << std::endl;
}
