#include <stdlib.h>
#include <time.h>
#include <vector>
#include "GeneratePlanets.h"


void GeneratePlanets(std::vector<Planet>& planets) {

	int planetAmount = rand() % 21 + 20;

	for (int i = 0; i < planetAmount; i++) {
		planets.push_back(Planet());
	}
}