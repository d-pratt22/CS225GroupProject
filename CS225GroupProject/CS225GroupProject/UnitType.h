#ifndef UNITTYPE_H
#define UNITTYPE_H

#include <string>

using namespace std;

struct UnitType {
	string name;
	int cost;
	int range;
	int maxHealth;
	int damage;
	string damageType;
	int armorAmount; //out of 100, chance to reflect damage
	int armorPiercingAmount; //out of 100, amount of armor to ignore
	int speed;
};

#endif
