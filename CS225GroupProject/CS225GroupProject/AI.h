#ifndef AI_H
#define AI_H

#include <stdlib.h>

class AI {
public:
	int x;
	int y;
	int claimNumber;

	AI(int cn) {
		x = rand() % 40;
		y = rand() % 40;
		claimNumber = cn;
	}
};

#endif
