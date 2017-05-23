#include "JsonConfig.h"
#include <fstream>
#include <sstream>
#include <assert.h>


bool JsonConfig::Parse(const char* fileName)
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

int JsonConfig::GetInt(const char* key)
{
	assert(m_configJson.HasMember(key));
	assert(m_configJson[key].IsString());
	return m_configJson[key].GetInt();
}

const char* JsonConfig::GetString(const char* key)
{
	assert(m_configJson.HasMember(key));
	assert(m_configJson[key].IsString());

	return m_configJson[key].GetString();
}
