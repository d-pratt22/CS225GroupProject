#ifndef UNITTYPE_H
#define UNITTYPE_H

#include <string>

using namespace std;

struct UnitType {
	string name;
	int range;
	int maxHealth;
	int damage;
	string damageType;
	int armorAmount;
	int armorPiercingAmount;
	float speed;
};

#endif
