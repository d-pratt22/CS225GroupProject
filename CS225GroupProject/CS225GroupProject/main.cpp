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

	StartGame();
	MakeDefaultArmy(army);
	
	while (winner == false) {
		turnNumber++;
		std::cout << "********  Turn " << turnNumber << "  ********" << std::endl;

		Move();
		/*
			-Movement
			-Battle
			-Check for Winner
			-Build
		*/
		winner = true;
	}

	return 0;
}
