#include "MessageQueue.h"
#include "AutoLocker.h"

MessageQueue::MessageQueue(MemoryPool* pool)
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
	AutoLocker locker(m_mutex);
	m_queue.PushBack(netMessage);
	return true;
}

NetMessage* MessageQueue::PopMessage()
{
	if (m_queue.Empty())
	{
		return nullptr;
	}
	AutoLocker locker(m_mutex);
	NetMessage** msg = m_queue.Back();
	if (nullptr != msg)
	{
		m_queue.PopBack();
		return *msg;
	}
	return nullptr;
}
