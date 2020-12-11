#include "TestStand.h"

int main() {
	TestStand stand(DVS1);
	stand.run();
	stand.printResult();
	stand.end();
	return 0;
}
