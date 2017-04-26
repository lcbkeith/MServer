#pragma once
#include "includes.h"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "AsioTcpConnection.h"

using namespace boost;
using namespace boost::asio;

class AsioClientApp
{
public:
	AsioClientApp();
	virtual ~AsioClientApp();

	virtual void Start(const char* host, int port, int threadCount = 0);
	void OnConn(AsioTcpConnection* conn, const boost::system::error_code& err);
	void SetIOService(io_service& ioService);
	void Tick();
protected:
private:
	bool m_sharedSvc;
	io_service* m_ioService;
	ip::tcp::resolver::query* m_query;
	ip::tcp::resolver* m_resolver;
	ip::tcp::resolver::iterator m_rsvIter;

	std::vector<boost::thread*> m_workThreads;

	AsioTcpConnection* m_conn;
};