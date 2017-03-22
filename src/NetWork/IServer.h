#pragma once

#include "TypeDefines.h"
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/thread.hpp>
#include "TCPAcceptor.h"
#include <iostream>
#include <thread>

using namespace boost::asio;
class IServer
{
public:
	virtual ~IServer();
	void Start(int port);
	void Tick(uint diff);


	void HandleAccept(ip::tcp::socket& socket);
private:

	TCPAcceptor* m_acceptor;
	io_service m_ioService;
	boost::thread m_workThread;
	
};