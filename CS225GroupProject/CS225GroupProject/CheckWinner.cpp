#include "CheckWinner.h"

bool CheckWinner(std::vector<Planet> planets, int winAmount) {
	int playerPlanetCount = 0;

	for (const auto& planet : planets) {
		if (planet.claimed == 1) {
			playerPlanetCount++;
		}
	}

	if (playerPlanetCount >= winAmount) {
		return true;
	}
	else {
		return false;
	}
}