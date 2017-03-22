#include "TCPAcceptor.h"

void TCPAcceptor::Accept()
{
	m_acceptor.async_accept(m_acceptSocket,
		[this](boost::system::error_code err) {
		if (!err)
			m_acceptHandler(m_acceptSocket);
		Accept();
	});
}
