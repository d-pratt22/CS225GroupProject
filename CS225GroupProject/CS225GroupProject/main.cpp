#include <iostream>
#include <vector>
#include "StartGame.h"
#include "Movement.h"
#include "ArmyBuilder.h"
#include "UnitType.h"

int main() {
	std::vector<UnitType> army;
	bool winner = false;
	int turnNumber = 0;
	int resources;

	StartGame();
	resources = MakeDefaultArmy(army);
	
	while (winner == false) {
		turnNumber++;
		std::cout << "********  Turn " << turnNumber << "  ********" << std::endl;

		//Movement
		Move();

		//Battle


		//Check For Winner


		//Build New Ships
		PurchaseList(resources, army);

		winner = true;
	}

	return 0;
}
