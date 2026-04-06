#include "Resources.h"

void GetPlanetResources(int& resources, std::vector<Planet> planets) {
	for (const auto& planet : planets) {
		if (planet.claimed == 1) {
			resources += planet.resourceAmount;
		}
	}
}