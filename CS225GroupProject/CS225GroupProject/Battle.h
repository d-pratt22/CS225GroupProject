#ifndef BATTLE_H
#define BATTLE_H

#include <vector>
#include "Unit.h"
#include "UnitType.h"

std::vector<Unit> SetupBattlefield(std::vector<UnitType>& army);

bool Battle(std::vector<Unit>& units);

#endif