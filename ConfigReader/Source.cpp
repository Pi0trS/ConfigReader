#include<iostream>
#include <string>

#include"ConfigReader.h"
using namespace std;
int main()
{
	int i;
	std::string s;
	//ConfigReader a("ConfigData.txt");


	ConfigReader a((std::getline(std::cin,s)));
	
	a.checkData();
	cin >>  i;
	return 0;
}