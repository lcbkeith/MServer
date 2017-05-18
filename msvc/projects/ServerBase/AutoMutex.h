#pragma once
#include <mutex>
class AutoMutex
{
public:
	AutoMutex() { m_mutex.lock(); }
	~AutoMutex() { m_mutex.unlock(); }
protected:
private:
	std::mutex m_mutex;
};
