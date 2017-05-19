#pragma once
#include <mutex>
class AutoLocker
{
public:
	AutoLocker(std::mutex& mutex):m_mutex(mutex) { m_mutex.lock(); }
	~AutoLocker() { m_mutex.unlock(); }
protected:
private:
	std::mutex& m_mutex;
};
