#pragma once
#include <functional>
#include <boost/asio.hpp>

class TCPAcceptor
{
public:
	TCPAcceptor(boost::asio::io_service& ioService,
		const std::string& bindAddress, int port,
		std::function<void(boost::asio::ip::tcp::socket&)> acceptHandler)
		: m_acceptor(ioService,
			boost::asio::ip::tcp::endpoint(
				boost::asio::ip::address::from_string(bindAddress),
				port)),
		m_acceptSocket(ioService)
	{
		m_acceptHandler = acceptHandler;
		Accept();
	}

private:
	boost::asio::ip::tcp::acceptor m_acceptor;
	boost::asio::ip::tcp::socket m_acceptSocket;
	std::function<void(boost::asio::ip::tcp::socket&)> m_acceptHandler;

	void Accept();
};
