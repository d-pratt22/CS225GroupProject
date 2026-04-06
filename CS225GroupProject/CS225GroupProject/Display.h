#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include "Player.h"
#include "Planets.h"
#include "Unit.h"

void SetConsoleColor(int textColor, int bgColor);

void MakePixel(int color);

void SetDisplay(Player& player, std::vector<Planet> planets);

void Display(Player& player, std::vector<Planet> planets);

void DisplayBattle(std::vector<Unit> units, std::vector<Unit> eUnits);

#endif