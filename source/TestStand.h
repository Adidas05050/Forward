#ifndef TESTSTAND_H
#define TESTSTAND_H
#include "DVS.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

enum typeEngine {	//���������� �������� ��� �������� ��������
	DVS1,			//ID ������� � listEngine
};

class TestStand
{
	public:
		TestStand(int configId);
		void run();
		void printResult();
		void end();

	protected:
		DVS *dvs;
		std::map<int, std::string> listEngine;
		int timer = 0;
};

#endif
