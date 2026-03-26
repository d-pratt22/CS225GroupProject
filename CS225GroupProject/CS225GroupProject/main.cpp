#include <iostream>
#include "StartGame.h"
#include "Movement.h"
#include "JsonHandler.h"

using namespace std;

int main() {
	bool winner = false;
	StartGame();

	CreateList();

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
