#include <iostream>
#include <vector>
#include "StartGame.h"
#include "ArmyBuilder.h"
#include "UnitType.h"
#include "Planets.h"
#include "GeneratePlanets.h"
#include "Display.h"
#include "Battle.h"
#include "Player.h"
#include "PlanetClaim.h"

int main() {
	Player player;
	std::vector<UnitType> army;
	std::vector<Planet> planets;
	srand(time(NULL));
	bool winner = false;
	bool isOnPlanet;
	int turnNumber = 0;
	int resources;

	StartGame();
	resources = MakeDefaultArmy(army);
	GeneratePlanets(planets);
	
	while (winner == false) {
		turnNumber++;
		std::cout << "********  Turn " << turnNumber << "  ********" << std::endl;

		//Movement
		Display(player, planets);
		isOnPlanet = OnPlanet(player, planets);

		//Battle
		SetupBattlefield(army);

		//Check For Winner


		//Build New Ships
		PurchaseList(resources, army);

		winner = true;
	}

	return 0;
}
