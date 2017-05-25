#pragma once
#include "includes.h"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "IAsioApp.h"

using namespace boost;
using namespace boost::asio;

class AsioClientApp : public IAsioApp
{
public:
	AsioClientApp();
	virtual ~AsioClientApp();

	virtual void Start(const char* host, int port);
	void OnConn(AsioTcpConnection* conn, const boost::system::error_code& err);
	void SetIOService(io_service& ioService);
	void Tick();
	AsioTcpConnection* GetConnect() { return m_conn; }
	void StartConnect();
protected:
private:
	bool						m_sharedSvc; 
	bool						m_autoReconnect;
	bool						m_isConnecting;
	io_service*					m_ioService;
	ip::tcp::resolver::query*	m_query;
	ip::tcp::resolver*			m_resolver;
	ip::tcp::resolver::iterator m_rsvIter;
	AsioTcpConnection*			m_conn;
};