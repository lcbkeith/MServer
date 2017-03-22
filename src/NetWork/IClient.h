#pragma once
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <boost/thread.hpp>
#include <boost/interprocess/ipc/message_queue.hpp>
using namespace boost::asio;
class IClient
{
public:
	IClient(io_service* io_svc = NULL);
	virtual ~IClient();

	virtual void Start(const char* host, int port);
	void OnConn(ip::tcp::socket* socket, const boost::system::error_code& err);
private:
	bool m_sharedSvc;
	io_service* m_ioService;
	ip::tcp::resolver* m_resolver;
	ip::tcp::resolver::iterator m_rsvIter;
	ip::tcp::socket* m_socket;

	boost::thread m_workThread;
};