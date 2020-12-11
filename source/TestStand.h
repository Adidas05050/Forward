#ifndef TESTSTAND_H
#define TESTSTAND_H
#include "Engine.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

enum typeEngine {
	DVS1,
};

class TestStand
{
	public:
		TestStand(int configId);
		void run();
		void printResult();
		void end();

	protected:
		Engine *dvs;
		std::map<int, std::string> listEngine;
		int timer = 0;
};

#endif
