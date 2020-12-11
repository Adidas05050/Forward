#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class Engine
{
	public:
		Engine(double temp, std::string filename);
		int speedHeatEngine(int i);		// Vh - �������� ������� ����.
		void speedCoolEngine();			// Vc - �������� ���������� ����.
		int isOverHeat();
		void parsing();
			
	protected:
		std::string filename;
		double currentV = 0, currentM = 0;
		double tempAmbient, tempEngine;
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

#endif
