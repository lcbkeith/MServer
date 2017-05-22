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
	bool PopMessage(NetMessage* netMessage);
	bool Empty() { return m_queue.Empty(); }
	int PopEnoughMessage(char* buffer, std::size_t size);
protected:
private:
	CircleDeque<NetMessage*> m_queue;
	std::mutex m_mutex;
	MemoryPool* m_pool;
};
