#include "PlanetClaim.h"

bool OnPlanet(Player player, std::vector<Planet> planets) {
	for (const auto& planet : planets) {
		if (planet.x == player.x && planet.y == player.y) {
			return true;
		}
	}
	return false;
}