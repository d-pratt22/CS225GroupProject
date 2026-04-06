#ifndef BATTLE_H
#define BATTLE_H

#include <vector>
#include "Unit.h"
#include "UnitType.h"

std::vector<Unit> SetupBattlefield(std::vector<UnitType>& army);

std::vector<Unit> SetupEnemyBattlefield(std::vector<UnitType>& eArmy);

bool Battle(std::vector<Unit>& units, std::vector<Unit>& eUnits);

#endif