#ifndef PLANETS_H
#define PLANETS_H

#include <stdlib.h>
#include <time.h>

class Planet {
public:
	int resourceAmount;
	int x;
	int y;
	int claimed;

	Planet() {

		x = rand() % 40;
		y = rand() % 40;
		resourceAmount = rand() % 501 + 500;
		claimed = 0;
	}

};

#endif