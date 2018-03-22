#include<iostream>
#include"ConfigReader.h"
using namespace std;
int main()
{
	int i;
	
	ConfigReader a("ConfigData.txt");
	a.checkData();
	cin >>  i;
	return 0;
}