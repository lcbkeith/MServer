#pragma once
#include <mutex>

class AutoLocker
{
public:
	inline AutoLocker(std::mutex& mutex) : mLock(&mutex)
	{
		mLock->lock();
	}
	inline AutoLocker(std::mutex* mutex) : mLock(mutex)
	{ 
		mLock->lock(); 
	}
 
	inline ~AutoLocker()
	{
		mLock->unlock(); 
	}
private:
	std::mutex * mLock;
};
