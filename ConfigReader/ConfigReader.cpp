#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<cctype>
#include<map>
#include<exception>


#include "ConfigReader.h"

ConfigReader::ConfigReader()
{
	config["hash"] = "";
	config["hashType"] = "";
	config["salt"] = "";
	config["dictionaryPath"] = "";
	config["numberOfThreads"] = "";
}
ConfigReader::ConfigReader(std::string path)
{
	config["hash"] = "";
	config["hashType"] = "";
	config["salt"] = "";
	config["dictionaryPath"] = "";
	config["numberOfThreads"] = "";

	std::ifstream file(path);
	std::string line, left, right;
	if (!file.good()) throw std::exception("file is not good");
	while (std::getline(file, line))
	{
		size_t separatorIndex = line.find(separator);
		if (separatorIndex == std::string::npos) 
			continue;
		left = trim(line.substr(0, separatorIndex));
		right = trim(line.substr(separatorIndex + 1));
		if (left.length() > 0 && right.length() > 0 && config.find(left) != config.end() )
			config[left] = right;
		left = right = "";
	}
	
	hash =config["hash"];
	hashType = config["hashType"];
	salt =config["salt"];
	dictionaryPath =config["dictionaryPath"];
	numberOfThreads = std::stoi(config["numberOfThreads"]);

}
std::string ConfigReader::trim(std::string s)
{
	int whiteSpaceAtEnd = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (std::isspace(s[i]))
		{
			whiteSpaceAtEnd++;
		}
		else
			break;
	}
	bool flagBeginning = true;
	std::stringstream ss;
	for (int i = 0; i < s.length() - whiteSpaceAtEnd; i++)
	{
		if (flagBeginning && std::isspace(s[i])) continue;
		flagBeginning = false;
		ss << s[i];
	}
	return ss.str();
}
void ConfigReader::checkData()
{
	if (config.empty())std::cout << "Data is empty" << std::endl;
	else
	{
		std::string left, right, tmp, input;
		for (std::map<std::string, std::string>::iterator iter = config.begin(); iter != config.end(); iter++)
		{
			left = iter->first;
			right = iter->second;
			std::cout << left << ": " << right << "correctly loaded type y/n "<< std::endl;
			std::cin >> tmp;
			if (tmp == "y" || tmp == "Y") 
			{
				//iter++;
				continue;
			}
			else if (tmp == "n" || tmp == "N")
			{
				std::cout << "Corect:" << left << ": ";
				std::cin >> input;
				config[left] = trim(input);
				std::cout << std::endl;
				std::cout << "aftr corection:" << "config[" << left << "]:" << config[left] << std::endl;
				//iter++;
			}
			else
			{
				std::cout << "nope" << std::endl;	
				iter--;
			}
		}

		hash = config["hash"];
		hashType = config["hashType"];
		salt = config["salt"];
		dictionaryPath = config["dictionaryPath"];
		numberOfThreads = std::stoi(config["numberOfThreads"]);

		std::cout << "Corection end" << std::endl;
	}

}
