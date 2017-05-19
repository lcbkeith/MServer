#pragma once
#include "CircleDeque.h"
#include "NetMessage.h"
#include <mutex>
#include "MemoryPool.h"

class MessageQueue
{
public:
	MessageQueue(MemoryPool* pool);
	~MessageQueue();
	bool PushMessage(NetMessage* netMessage);
	NetMessage* PopMessage();

protected:
private:
	CircleDeque<NetMessage*> m_queue;
	std::mutex m_mutex;
	MemoryPool* m_pool;
};
