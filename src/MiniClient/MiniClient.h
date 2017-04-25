#pragma once
#include "..\ServerBase\IClient.h"
class MiniClient : public IClient
{
public:
	MiniClient() {}
	virtual ~MiniClient() {};
	void SetIOService(io_service& service) { m_clientApp->SetIOService(service); }
protected:
private:
};