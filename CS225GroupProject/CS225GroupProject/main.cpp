#include <iostream>
#include "StartGame.h"
#include "Movement.h"
#include "ArmyBuilder.h"

int main() {
	bool winner = false;
	StartGame();

	ShowList();

	while (winner == false) {
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
