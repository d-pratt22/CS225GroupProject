#ifndef UNIT_H
#define UNIT_H

#include "UnitType.h"

class Unit {
public:
	Unit(const UnitType& Type, int x, int y) : Type{ Type }, xPos{ x }, yPos{ y }, currentHealth{ Type.maxHealth } {}

	const UnitType& Type;

	int xPos;
	int yPos;
	int currentHealth;
};

#endif
