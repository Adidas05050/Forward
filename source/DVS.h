#include "Engine.h"
#pragma once

class DVS : public Engine {
public:
	DVS(double temp, std::string filename);
	int speedHeatEngine(int i);		// Vh - скорость нагрева двиг.
	void speedCoolEngine();			// Vc - скорость охлаждения двиг.
	int isOverHeat();
	void parsing();

protected:
	double currentV = 0, currentM = 0;
	double speedHeat = 0, speedCooling = 0;
	double speedCrankshaft = 0;
	double T; //T -перегрев
	double I; //I - Инерция вращения двигателя
	std::vector<double> M; //M - крутящий момент
	std::vector<double> V; // V -скорость вращения коленвала
	double Hm; //Hm - нагрев от скорости крут. момента
	double Hv; //Hv - нагрев от скорости вращения коленвала
	double C; //C - охлаждение от температуры двиг. и окр.сред.
};
