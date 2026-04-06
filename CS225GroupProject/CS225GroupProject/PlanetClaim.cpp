#include <iostream>
#include "PlanetClaim.h"

bool OnPlanet(Player player, std::vector<Planet>& planets) {
	for (const auto& planet : planets) {
		if (planet.x == player.x && planet.y == player.y) {
			return true;
		}
	}
	return false;
}

Planet& GetPlanet(Player player, std::vector<Planet>& planets) {
	for (auto& planet : planets) {
		if (planet.x == player.x && planet.y == player.y) {
			std::cout << "Planet is currently claimed by: ";
			if (planet.claimed == 1) {
				std::cout << "You\n";
			}
			else if (planet.claimed == 0) {
				std::cout << "No one, but there is a defending force\n";
			}
			else {
				std::cout << "The enemy, you must attack the defenders\n";
			}
			return planet;
		}
	}
}

void ClaimPlanet(Player player, std::vector<Planet>& planets) {
	for (auto& planet : planets) {
		if (planet.x == player.x && planet.y == player.y) {
			planet.claimed = 1;
			std::cout << "Planet claimed! You will now receive an additional " << planet.resourceAmount << " resources per turn!\n";
		}
	}
}