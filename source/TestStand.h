#ifndef TESTSTAND_H
#define TESTSTAND_H
#include "DVS.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

enum typeEngine {	//Добавление названия для удобства передачи
	DVS1,			//ID конфига в listEngine
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
