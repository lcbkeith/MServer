#pragma once
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"

class JsonConfig
{
public:
	bool Parse(const char* fileName);

	int GetInt(const char* key);
	const char* GetString(const char* key);
protected:
private:
	rapidjson::Document m_configJson;
	
};