#pragma once
#include "includes.h"
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include "AsioTcpConnection.h"
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

class AsioServerApp
{
public:
	AsioServerApp();
	~AsioServerApp();

	void AppStart(int port, int threadCount);
	void StartAccept();
	void HandleAccept(AsioTcpConnection* conn, const boost::system::error_code& err);
	void Tick();

	void SetDelegateConnected(DelegateOnConnected func);
	void SetDelegateConnClosed(DelegateOnConnClosed func);
	void SetDelegateMsgRecv();
private:
	io_service*							m_ioService;
	ip::tcp::acceptor*					m_accecptor;

	std::vector<AsioTcpConnection*>		m_connList;
	std::vector<boost::thread*>			m_workThreads;

	DelegateOnConnected m_delegateConnected;
	DelegateOnConnClosed m_delegateConnClosed;
};