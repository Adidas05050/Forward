#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

class Engine
{
	public:
		virtual int speedHeatEngine(int i) = 0;		// Vh - �������� ������� ����.
		virtual void speedCoolEngine() = 0;			// Vc - �������� ���������� ����.
		virtual int isOverHeat() = 0;
		virtual void parsing() = 0;
			
	protected:
		std::string filename;
		double tempAmbient, tempEngine;
};

#endif
