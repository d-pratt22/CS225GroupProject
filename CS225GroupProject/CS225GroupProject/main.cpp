#include <iostream>
#include <vector>
#include "StartGame.h"
#include "ArmyBuilder.h"
#include "UnitType.h"
#include "Unit.h"
#include "Planets.h"
#include "GeneratePlanets.h"
#include "Display.h"
#include "Battle.h"
#include "Player.h"
#include "PlanetClaim.h"
#include "Resources.h"
#include "CheckWinner.h"

int main() {
	Player player;
	Planet p;
	std::vector<UnitType> army;
	std::vector<UnitType> eArmy;
	std::vector<Planet> planets;
	std::vector<Unit> units;
	std::vector<Unit> eUnits;
	srand(time(NULL));
	bool winner = false;
	bool isOnPlanet;
	bool playerWon = false;
	int turnNumber = 0;
	int resources = 0;
	int planetAmount;

	planetAmount = GeneratePlanets(planets);

	int winAmount = planetAmount - 5;

	StartGame(winAmount);
	resources = MakeDefaultArmy(army);
	
	while (winner == false) {
		turnNumber++;
		std::cout << "********  Turn " << turnNumber << "  ********" << std::endl;

		Display(player, planets);
		isOnPlanet = OnPlanet(player, planets);
		if (isOnPlanet) {
			p = GetPlanet(player, planets);
		}

		if (isOnPlanet && p.claimed != 1) {
			units = SetupBattlefield(army);
			MakeSimpleEnemyArmy(eArmy); 
			eUnits = SetupEnemyBattlefield(eArmy);
			playerWon = Battle(units, eUnits, resources);
		}

		if (playerWon && isOnPlanet) {
			ClaimPlanet(p);
		}

		GetPlanetResources(resources, planets);
		PurchaseList(resources, army);

		winner = CheckWinner(planets, winAmount);
	}

	return 0;
}
