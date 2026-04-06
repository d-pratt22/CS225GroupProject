/*
https://stackoverflow.com/questions/26438222/print-a-filled-square-in-console
*/

#include<iostream>
#include<windows.h>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <conio.h>
#include "Display.h"
using namespace std::chrono_literals;

#define MapSize 40

void SetConsoleColor(int textColor, int bgColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor +
		(bgColor * 16)));
}

void MakePixel(int color) {
	SetConsoleColor(4, color);
	std::cout << "  ";
	SetConsoleColor(0, 0);
}

void SetDisplay(Player& player, std::vector<Planet> planets) {
	system("cls");

	for (int row = MapSize - 1; row >= 0; --row) {
		for (int col = 0; col < MapSize; ++col) {
			if (player.x == col && player.y == row) {
				MakePixel(5);
				continue;
			}
			
			bool isPlanet = false;
			bool playerClaimed = false;
			bool enemyClaimed = false;

			for (const auto& planet : planets) {
				if (planet.x == col && planet.y == row) {
					isPlanet = true;
					if (planet.claimed == 1) {
						playerClaimed = true;
					}
					else if (planet.claimed == 0) {
						playerClaimed = false;
						enemyClaimed = false;
					}
					else {
						enemyClaimed = true;
					}
					break;
				}
			}

			if (isPlanet) {
				if (playerClaimed) {
					MakePixel(4);
				}
				else if (enemyClaimed) {
					MakePixel(3);
				}
				else {
					MakePixel(2);
				}
			}
			else {
				MakePixel(7);
			}
			
		}

		std::cout << std::endl;

	}
	SetConsoleColor(3, 0);
	std::cout << "X:" << player.x << " " << "Y:" << player.y << std::endl;
	SetConsoleColor(7, 0);
}

void Display(Player& player, std::vector<Planet> planets) {
	bool looping = true;
	int moveCount = 0;

	std::cout << "Press WASD to move (any other key to exit)" << std::endl;
	std::this_thread::sleep_for(2000ms);
	std::cout << "You get " << player.range << " moves" << std::endl;
	std::this_thread::sleep_for(2000ms);

	SetDisplay(player, planets);

	while (looping && moveCount < player.range) {
		if (_kbhit()) {
			char key = _getch();

			switch (key) {
			case 'w':
				std::cout << "Move forward." << std::endl;
				player.y++;
				SetDisplay(player, planets);
				break;
			case 'a':
				std::cout << "Move left." << std::endl;
				player.x--;
				SetDisplay(player, planets);
				break;
			case 's':
				std::cout << "Move back." << std::endl;
				player.y--;
				SetDisplay(player, planets);
				break;
			case 'd':
				std::cout << "Move right." << std::endl;
				player.x++;
				SetDisplay(player, planets);
				break;
			default:
				std::cout << "Exited." << std::endl;
				looping = false;
				break;
			}
			moveCount++;
			std::cout << "You have done " << moveCount << " moves\n";
		}
	}
}

void DisplayBattle(std::vector<Unit> units, std::vector<Unit> eUnits) {
	system("cls");

	for (int row = MapSize - 1; row >= 0; --row) {
		for (int col = 0; col < MapSize; ++col) {

			bool drawn = false;

			for (const auto& unit : units) {

				if (unit.xPos == col && unit.yPos == row) {
					MakePixel(5);
					drawn = true;
					break;
				}
			}

			for (const auto& eUnit : eUnits) {
				if (eUnit.xPos == col && eUnit.yPos == row) {
					MakePixel(3);
					drawn = true;
					break;
				}
			}	
			if (!drawn) {
				MakePixel(7);
			}
		}

		std::this_thread::sleep_for(10ms);

		std::cout << std::endl;

	}
	SetConsoleColor(7, 0);
}