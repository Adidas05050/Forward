#include "Engine.h"
#pragma once

class DVS : public Engine {
public:
	DVS(double temp, std::string filename);
	int speedHeatEngine(int i);		// Vh - �������� ������� ����.
	void speedCoolEngine();			// Vc - �������� ���������� ����.
	int isOverHeat();
	void parsing();

protected:
	double currentV = 0, currentM = 0;
	double speedHeat = 0, speedCooling = 0;
	double speedCrankshaft = 0;
	double T; //T -��������
	double I; //I - ������� �������� ���������
	std::vector<double> M; //M - �������� ������
	std::vector<double> V; // V -�������� �������� ���������
	double Hm; //Hm - ������ �� �������� ����. �������
	double Hv; //Hv - ������ �� �������� �������� ���������
	double C; //C - ���������� �� ����������� ����. � ���.����.
};
