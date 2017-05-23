#include "JsonConfig.h"
#include <fstream>
#include <sstream>
#include <assert.h>


bool JsonConfig::Parse(const std::string& fileName)
{
	std::ifstream file(fileName, std::ios::in | std::ios::binary);
	if (file.is_open())
	{
		std::stringstream sin;
		sin << file.rdbuf();
		//获取字符串流中的字符串  
		std::string str = sin.str();
		file.close();
		file.clear();

		m_configJson.Parse(str.c_str());
		return true;
	}
	return false;

}

int JsonConfig::GetInt(const std::string& key)
{
	assert(m_configJson.HasMember(key.c_str()));
	assert(m_configJson[key.c_str()].IsString());
	return m_configJson[key.c_str()].GetInt();
}

const char* JsonConfig::GetString(const std::string& key)
{
	assert(m_configJson.HasMember(key.c_str()));
	assert(m_configJson[key.c_str()].IsString());
	return m_configJson[key.c_str()].GetString();
}
