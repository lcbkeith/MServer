#pragma once

#include "../NetWork/TypeDefines.h"
class Obj
{
public:
	Obj() :m_id(0) {}
	void SetID(int64 id) { m_id = id; }
	int64 GetID() { return m_id; }
private:
	int64 m_id;
};