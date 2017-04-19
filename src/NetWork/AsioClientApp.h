#pragma once
#include "includes.h"
#include <boost/asio.hpp>
#include <boost/thread.hpp>

using namespace boost;
using namespace boost::asio;

class AsioClientApp
{
public:
	AsioClientApp(io_service* io_svc = NULL);
	virtual ~AsioClientApp();

	virtual void Start(const char* host, int port);
	void OnConn(ip::tcp::socket* socket, const boost::system::error_code& err);

protected:
private:
	bool m_sharedSvc;
	io_service* m_ioService;
	ip::tcp::resolver::query* m_query;
	ip::tcp::resolver* m_resolver;
	ip::tcp::resolver::iterator m_rsvIter;
	ip::tcp::socket* m_socket;
	boost::thread m_workThread;
};