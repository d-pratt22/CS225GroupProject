#include <iostream>
#include "StartGame.h"
#include "Movement.h"

using namespace std;

int main() {
	bool winner = false;
	StartGame();

	while (winner == false) {
		Move();
		/*
			-Movement
			-Battle
			-Check for Winner
			-Build
		*/
	}

	return 0;
}
