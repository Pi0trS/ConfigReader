#pragma once
#include<map>

class ConfigReader 
{
public:
	ConfigReader(); 
	ConfigReader::ConfigReader(std::string);
	void checkData();

private: 
	std::map<std::string, std::string>config;
	const char separator = ':';
	std::string hash, hashType, salt, dictionaryPath;
	int numberOfThreads;

	std::string trim(std::string s);
};