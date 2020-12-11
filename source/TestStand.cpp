#include "TestStand.h"

TestStand::TestStand(int configId) {
	double temp;
	std::cout << "Input ambient temp: ";
	std::cin >> temp;
	listEngine.insert(std::make_pair<int, std::string>(DVS1, "configs/dvs1.txt")); //добавление конфиг файла
	dvs = new DVS(temp, (*listEngine.find(configId)).second);
	dvs->parsing();
}

void TestStand::run() {
	int i = 0;
	timer = 0;
	while(dvs->isOverHeat() == 0) {
		i = dvs->speedHeatEngine(i);
		dvs->speedCoolEngine();
		timer++;
	}
	if(dvs->isOverHeat() == -1)
		std::cout << "Infinity\n";
}


void TestStand::printResult() {
	std::cout << "Time(sec): "<< timer;
}

void TestStand::end() {
	delete dvs;
}
