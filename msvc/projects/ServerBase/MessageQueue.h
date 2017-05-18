#pragma once
#include "CircleDeque.h"
#include "..\..\..\src\ServerBase\NetMessage.h"
class MessageQueue
{
public:
protected:
private:
	CircleDeque<NetMessage*> m_queue;
};
