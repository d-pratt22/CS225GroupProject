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
	int pixelCount = 0;
	int color;
	for (int i = 1; i < MapSize * MapSize + 1; ++i) { // loops through and prints each pixel 
		pixelCount++;
		if (pixelCount == (MapSize * MapSize - player.x - player.y)) {
			MakePixel(5);
		}
		else {
			bool isPlanet = false;

			for (const auto& planet : planets) {
				if (pixelCount == (MapSize * MapSize - planet.x - planet.y * MapSize)) {
					isPlanet = true;
					break;
				}
			}

			if (isPlanet) {
				MakePixel(2);
			}
			else {
				MakePixel(7);
			}
		}
		//this_thread::sleep_for(chrono::nanoseconds(400));
		if (i % MapSize == 0) {
			std::cout << std::endl;
		}
	}
	SetConsoleColor(3, 0);
	std::cout << pixelCount << std::endl;
	std::cout << "X:" << player.x << " " << "Y:" << player.y / MapSize << std::endl;
	SetConsoleColor(7, 0);
	pixelCount = 0;
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
				player.y += MapSize;
				SetDisplay(player, planets);
				break;
			case 'a':
				std::cout << "Move left." << std::endl;
				player.x++;
				SetDisplay(player, planets);
				break;
			case 's':
				std::cout << "Move back." << std::endl;
				player.y -= MapSize;
				SetDisplay(player, planets);
				break;
			case 'd':
				std::cout << "Move right." << std::endl;
				player.x--;
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
	//SetConsoleColor(7, 0);
}