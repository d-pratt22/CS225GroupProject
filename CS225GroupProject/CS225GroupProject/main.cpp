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
#include "AI.h"
#include "ErrorHandling.h"
#include "GeneticAlgorithm.h"
#include "JsonHandler.h"

int main() {
	int gameModeSelect;
	std::cout << "Greetings player, please select a game mode" << std::endl;
	std::cout << "1: Campaign Mode\n2: Instant Action\n3: Genetic AI Algorithm\nEnter a number to select a game mode: ";
	std::cin >> gameModeSelect;
	gameModeSelect = BetweenTwoValues(1, 3, gameModeSelect);

	// ---- CAMPAIGN MODE ---- //
	if (gameModeSelect == 1) {
		Player player;
		AI ai1(2);
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
				Planet& p = GetPlanet(player, planets);
			}

			if (isOnPlanet && p.claimed != 1) {
				units = SetupBattlefield(army);
				MakeSimpleEnemyArmy(eArmy);
				eUnits = SetupEnemyBattlefield(eArmy);
				playerWon = Battle(units, eUnits, resources);
			}

			if (playerWon && isOnPlanet) {
				ClaimPlanet(player, planets);
			}

			GetPlanetResources(resources, planets);
			PurchaseList(resources, army);

			winner = CheckWinner(planets, winAmount);
		}

		return 0;
	}

	// ---- INSTANT ACTION ---- //
	else if (gameModeSelect == 2) {
		int resources = 0;
		int enemyResources = 0;
		int exitCheck;
		bool armyCheck = true;
		std::vector<UnitType> army;

		resources = StartInstantAction();
		enemyResources = resources;

		while (armyCheck) {
			ShowList();
			PurchaseList(resources, army);
			std::cout << "Would you like to check lists again? (0 = NO, 1 = YES): ";
			std::cin >> exitCheck;
			exitCheck = BetweenTwoValues(0, 1, exitCheck);
			if (exitCheck == 0) {
				armyCheck = false;
			}
		}
		
	}

	// ---- GENETIC ALGORITHM ---- //
	//Genome runGeneticAlgorithm(std::vector<UnitType>&types, std::vector<Unit>&enemyUnits, int resources)
	else {
		int resources = 0;
		int aiResources = 0;
		int listCount = 1;
		int replayCheck;
		int listCheck;
		int exitCheck;
		bool armyCheck = true;
		Genome finalAI;
		std::vector<UnitType> army;
		std::vector<Unit> units;
		std::vector<UnitType> types;
		std::vector<Unit> aiUnits;

		types = CreateList();

		resources = StartGeneticAlgorithm();
		aiResources = resources;

		while (armyCheck) {
			ShowList();
			PurchaseList(resources, army);
			std::cout << "Would you like to check lists again? (0 = NO, 1 = YES): ";
			std::cin >> exitCheck;
			exitCheck = BetweenTwoValues(0, 1, exitCheck);
			if (exitCheck == 0) {
				armyCheck = false;
			}
		}

		units = SetupBattlefield(army);

		finalAI = runGeneticAlgorithm(types, units, resources);

		aiUnits = buildUnits(finalAI);

		std::cout << "AI has completed training, see the final list? (0 = NO, 1 = YES): ";
		std::cin >> listCheck;
		listCheck = BetweenTwoValues(0, 1, listCheck);

		if (listCheck == 1) {
			for (const auto& u : finalAI.units){
				std::cout << "Ship #" << listCount << ": " << u.type->name << std::endl;
				listCount++;
			}
		}

		std::cout << "Would you like to watch the final battle? (0 = NO, 1 = YES): ";
		std::cin >> replayCheck;
		replayCheck = BetweenTwoValues(0, 1, replayCheck);

		if (replayCheck == 1) {
			DisplayBattle(units, aiUnits);
		}
	}
}
