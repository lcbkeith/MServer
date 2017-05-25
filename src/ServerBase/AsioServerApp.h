#pragma once
#include "includes.h"
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include "IAsioApp.h"

using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

class AsioServerApp : public IAsioApp
{
public:
	AsioServerApp();
	~AsioServerApp();

	void AppStart(int port, int threadCount);
	void StartAccept();
	void HandleAccept(AsioTcpConnection* conn, const boost::system::error_code& err);
	void Tick();
private:
	io_service*							m_ioService;
	ip::tcp::acceptor*					m_accecptor;

	std::vector<AsioTcpConnection*>		m_connList;
	std::vector<boost::thread*>			m_workThreads;
};