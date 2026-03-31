#ifndef ARMYBUILDER_H
#define ARMYBUILDER_H

#include <vector>
#include "UnitType.h"

void ShowList();

void PurchaseList(int& resource, std::vector<UnitType>& army);

int MakeDefaultArmy(std::vector<UnitType>& army);

#endif
