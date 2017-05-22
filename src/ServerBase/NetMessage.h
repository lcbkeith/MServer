#pragma once
#include "TypeDefines.h"
struct NetMessage
{
	NetMessage()
		:Length(sizeof(NetMessage)),
		MessageId(0)
	{
	}

	short Length;
	short MessageId;
};

struct MsgMarkClient : public NetMessage
{
	MsgMarkClient()
	{
		this->Length = sizeof(*this);
		this->MessageId = 1;
	}
	int64 m_markId;
};

struct MsgClientResponse : public NetMessage
{
	MsgClientResponse()
	{
		this->Length = sizeof(*this);
		this->MessageId = 2;
	}
	int64 m_responseId;
};