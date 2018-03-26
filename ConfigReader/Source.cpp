#include<iostream>
#include"ConfigReader.h"
using namespace std;
int main()
{
	int i;
	
	//ConfigReader a("ConfigData.txt");


	ConfigReader a(std::cin );
	a.checkData();
	cin >>  i;
	return 0;
}