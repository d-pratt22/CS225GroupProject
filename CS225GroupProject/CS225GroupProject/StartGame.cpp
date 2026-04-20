#include <iostream>
#include "StartGame.h"
#include "ErrorHandling.h"

void StartGame(int winAmount) {
	std::cout << "Greetings general, it your time to take your rightful place as ruler of the galaxy.\n";
	std::cout << "In order to win and conquer the galaxy, you must conquer a total of " << winAmount << " planets.\n";
	std::cout << "Lets begin. \nYou must build your army of space ships to defeat the alien threat.\n";
	std::cout << "Time to go to the army builder, good luck gerneal...\n";
}

int StartInstantAction() {
	int resources;
	std::cout << "Welcome to the combat simulation, also known as Instant Action\n";
	std::cout << "Here you can test differnt ships and face difficult challenges\n";
	std::cout << "You may acquire up to 1000000 resources to test any number of ships\n";
	std::cout << "Please enter a number of resources to use to build your army: ";
	std::cin >> resources;
	resources = BetweenTwoValues(0, 1000000, resources);
	std::cout << "Good luck in the simulation general\n";
	return resources;
}

int StartGeneticAlgorithm() {
	int resources;
	std::cout << "Welcome to the AI combat simulation, using a Genetic Algorithm\n";
	std::cout << "Here you can test the AI with different armies and see what it comes up with\n";
	std::cout << "You may acquire up to 1000000 resources, the AI will receive the same number\n";
	std::cout << "Please enter a number of resources to use: ";
	std::cin >> resources;
	resources = BetweenTwoValues(0, 1000000, resources);
	std::cout << "Good luck with the AI\n";
	return resources;
}