#pragma once
#include "includes.h"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "AsioTcpConnection.h"
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

class AsioServerApp
{
public:
// 	AsioServerApp();
// 	virtual ~AsioServerApp();

	void AppStart(int port, int threadCount);

	void StartAccept();
	void HandleAccept(AsioTcpConnection* conn, const boost::system::error_code& err);
private:
	io_service*			m_ioService;
	ip::tcp::acceptor*		m_accecptor;

	std::vector<AsioTcpConnection*>			m_connList;
	std::vector<boost::thread*>			m_workThreads;
};