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
using namespace std;
using namespace std::chrono_literals;

#define MapSize 40

class Player {
public:
	int x;
	int y;
	int range;

	Player() {
		x = 0;
		y = 0;
		range = 3;
	}
};

class Ship {
public:
	int x;
	int y;

	Ship() {
		x = 10;
		y = 6;
	}
};

void SetConsoleColor(int textColor, int bgColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor +
		(bgColor * 16)));
}

void MakePixel(int color) {
	SetConsoleColor(4, color);
	cout << "  ";
	SetConsoleColor(0, 0);
}

void Display(Player& player, Ship& ship) {
	system("cls");
	int pixelCount = 0;
	int color;
	for (int i = 1; i < MapSize * MapSize + 1; ++i) { // loops through and prints each pixel 
		pixelCount++;
		if (pixelCount == (MapSize * MapSize - player.x - player.y)) {
			MakePixel(5);
		}
		else if (pixelCount == (MapSize * MapSize - ship.x - ship.y * MapSize)) {
			MakePixel(4);
		}
		else {
			MakePixel(7);
		}
		//this_thread::sleep_for(chrono::nanoseconds(400));
		if (i % MapSize == 0) {
			cout << endl;
		}
	}
	SetConsoleColor(3, 0);
	cout << pixelCount << endl;
	cout << "X:" << player.x << " " << "Y:" << player.y / MapSize << endl;
	SetConsoleColor(0, 0);
	pixelCount = 0;
}

srand(time(NULL));
bool looping = true;
Player player;
Ship ship;
Display(player, ship);

while (looping) {
	if (_kbhit()) {
		char key = _getch();


		switch (key) {
		case 'w':
			cout << "Move forward." << endl;
			player.y += MapSize;
			Display(player, ship);
			break;
		case 'a':
			cout << "Move left." << endl;
			player.x++;
			Display(player, ship);
			break;
		case 's':
			cout << "Move back." << endl;
			player.y -= MapSize;
			Display(player, ship);
			break;
		case 'd':
			cout << "Move right." << endl;
			player.x--;
			Display(player, ship);
			break;
		default:
			cout << "Exited." << endl;
			looping = false;
			break;
		}
	}
}