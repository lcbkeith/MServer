#pragma once
#include "../ServerBase/IClient.h"
#include "../ServerBase/Obj.h"
class MiniClient : public IClient, public Obj
{
public:
	MiniClient() {}
	virtual ~MiniClient() {};
	void SetIOService(io_service& service) { m_clientApp->SetIOService(service); }
protected:
private:
};