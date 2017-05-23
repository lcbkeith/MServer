#pragma once
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"

class JsonConfig
{
public:
	JsonConfig();
	~JsonConfig();
	bool Parse(const std::string& fileName);

	int GetInt(const std::string& key);
	const char* GetString(const std::string& key);
protected:
private:
	rapidjson::Document m_configJson;
	
};