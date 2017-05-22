#include "MessageQueue.h"
#include "AutoLocker.h"

MessageQueue::MessageQueue(MemoryPool* pool)
	:m_pool(pool)
{

}

MessageQueue::~MessageQueue()
{

}

bool MessageQueue::PushMessage(NetMessage* netMessage)
{
	if (nullptr == netMessage || netMessage->Length <= 0)
	{
		return false;
	}
	void* buffer = m_pool->alloc(netMessage->Length);
	memcpy(buffer, netMessage, netMessage->Length);
	AutoLocker locker(m_mutex);
	NetMessage* pushMsg = reinterpret_cast<NetMessage*>(buffer);
	m_queue.PushBack(pushMsg);
	return true;
}

bool MessageQueue::PopMessage(NetMessage* netMessage)
{
	if (nullptr == netMessage)
	{
		return false;
	}
	AutoLocker locker(m_mutex);
	if (m_queue.Empty())
	{
		return false;
	}
	NetMessage* headMsg = m_queue.Front();
	if (nullptr != headMsg)
	{
		m_queue.PopBack();
		memcpy(netMessage, headMsg, headMsg->Length);
		m_pool->free(headMsg, headMsg->Length);
		return true;
	}
	return false;
}

int MessageQueue::PopEnoughMessage(char* buffer, std::size_t size)
{
	AutoLocker locker(m_mutex);
	int popLength = 0;
	while (!Empty())
	{
		NetMessage* frontMsg = m_queue.Front();
		if (frontMsg->Length > size)
		{
			break;
		}
		memcpy(buffer + popLength, frontMsg, frontMsg->Length);
		popLength += frontMsg->Length;
		m_pool->free(frontMsg,frontMsg->Length);
		m_queue.PopFront();
	}

	return popLength;
}
