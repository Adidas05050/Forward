#include "DVS.h"

DVS::DVS(double temp, std::string fileName) {
	tempAmbient = temp;
	tempEngine = temp;
	filename = fileName;
}

void DVS::parsing() {
	std::ifstream file(filename);
	std::string number, temp;
	while (!file.eof()) {
		int i = 0;
		file >> temp;
		if (temp == "I") {
			file >> temp;
			temp.clear();
			file >> temp;
			I = stof(temp);
		}
		else if (temp == "M") {
			file >> temp;
			temp.clear();
			getline(file, temp);
			for (int i = 0; i < temp.size(); i++) { //parsing
				if (temp[i] != ' ' and temp[i] != ',' and temp[i] != '{' and temp[i] != '}') {
					number.push_back(temp[i]);
				}
				else if (temp[i] == ',' or temp[i] != '}') {
					if (number.size()) {
						M.push_back(stof(number));
						number.clear();
					}
				}
			}
			if (number.size()) {
				M.push_back(stof(number));
				number.clear();
			}
		}
		else if (temp == "V") {
			file >> temp;
			temp.clear();
			getline(file, temp);
			for (int i = 0; i < temp.size(); i++) { //parsing
				if (temp[i] != ' ' and temp[i] != ',' and temp[i] != '{' and temp[i] != '}') {
					number.push_back(temp[i]);
				}
				else if (temp[i] == ',' or temp[i] != '}') {
					if (number.size()) {
						V.push_back(stof(number));
						number.clear();
					}
				}
			}
			if (number.size()) {
				V.push_back(stof(number));
				number.clear();
			}
		}
		else if (temp == "Toh") {
			file >> temp;
			temp.clear();
			file >> temp;
			T = stof(temp);
		}
		else if (temp == "Hm") {
			file >> temp;
			temp.clear();
			file >> temp;
			Hm = stof(temp);
		}
		else if (temp == "Hv") {
			file >> temp;
			temp.clear();
			file >> temp;
			Hv = stof(temp);
		}
		else if (temp == "C") {
			file >> temp;
			temp.clear();
			file >> temp;
			C = stof(temp);
		}
	}
}

void DVS::speedCoolEngine() {
	speedCooling = C * (tempAmbient - tempEngine);
	tempEngine += speedCooling;
}

int DVS::isOverHeat() {
	if (fabs(V[V.size() - 1] - currentV) < 1e-6)
		return -1; // двигатель не перегреется при таких условиях
	return (tempEngine > T);
}

int DVS::speedHeatEngine(int i) {
	if (speedCrankshaft < V[i + 1])
		currentV = speedCrankshaft;
	else
		currentV = V[i + 1];

	currentM = ((M[i + 1] - M[i]) / V[i + 1]) * currentV + M[i];
	speedHeat = currentM * Hm + (currentV * currentV) * Hv;
	speedCrankshaft += currentM / I;

	tempEngine += speedHeat;
	if (currentV >= V[i + 1] and i < M.size() - 2)
		i++;
	return i;
}
