#include <stdlib.h>
#include <time.h>
#include <vector>
#include "GeneratePlanets.h"


int GeneratePlanets(std::vector<Planet>& planets) {

	int planetAmount = rand() % 21 + 20;

	for (int i = 0; i < planetAmount; i++) {
		planets.push_back(Planet());
	}

	return planetAmount;
}