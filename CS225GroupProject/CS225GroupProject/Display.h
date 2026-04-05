#ifndef DISPLAY_H
#define DISPLAY_H

#include "Player.h"
#include "Ship.h"

void SetConsoleColor(int textColor, int bgColor);

void MakePixel(int color);

void SetDisplay(Player& player, Ship& ship);

void Display();

#endif