#include <iostream>
#include "Battle.h"
#include "Display.h"

std::vector<Unit> SetupBattlefield(std::vector<UnitType>& army) {
	std::vector<Unit> units;

    for (int i = 0; i < army.size(); i++) {
        const UnitType& type = army[i];

        int x = 0;
        int y = 0;

        std::cout << "Enter x coordinate of ship #" << i + 1 << " the " << type.name << " (0-39): ";
        std::cin >> x;
        std::cout << "Enter y coordinate (0-15): ";
        std::cin >> y;

        units.emplace_back(type, x, y);
    }
    return units;
}

std::vector<Unit> SetupEnemyBattlefield(std::vector<UnitType>& eArmy) {
    std::vector<Unit> eUnits;

    for (int i = 0; i < eArmy.size(); i++) {
        const UnitType& type = eArmy[i];

        int x = rand() % 40;
        int y = rand() % 15 + 24;

        eUnits.emplace_back(type, x, y);
    }
    return eUnits;
}

bool Battle(std::vector<Unit>& units, std::vector<Unit>& eUnits, int& resources) {
    int rangeVal = 999;
    int armorTotal = 0;
    int destroyedCount = 0;
    int playerDestroyedCount = 0;
    for (auto& unit : units) {
        bool fired = false;
        for (auto& eUnit : eUnits) {
            rangeVal = abs(eUnit.xPos - unit.xPos) + abs(eUnit.yPos - unit.yPos);
            if (rangeVal < unit.Type.range / 10) {
                fired = true;
                armorTotal = unit.Type.armorPiercingAmount - eUnit.Type.armorAmount;
                if (armorTotal < 0) {
                    armorTotal = 0;
                }

                if (rand() % 100 + 1 >= armorTotal) {
                    eUnit.currentHealth -= unit.Type.damage;
                    if (eUnit.currentHealth <= 0) {
                        eUnit.destroyed = true;
                    }
                    break;
                }
                else {
                    break;
                }
            }
        }
        if (!fired) {
            unit.yPos = unit.yPos + (unit.Type.speed / 2);
        }
        DisplayBattle(units, eUnits);
    }

    for (const auto& eUnit : eUnits) {
        if (eUnit.destroyed) {
            destroyedCount++;
        }
    }
    int totalCost = 0;
    if (destroyedCount >= eUnits.size())
    {
        for (const auto& eUnit : eUnits) {
            totalCost += eUnit.Type.cost;
        }
        resources += totalCost / 2;
        return true;
    }

    for (auto& eUnit : eUnits) {
        bool fired = false;
        for (auto& unit : units) {
            rangeVal = abs(unit.xPos - eUnit.xPos) + abs(unit.yPos - eUnit.yPos);
            if (rangeVal < eUnit.Type.range / 10) {
                fired = true;
                armorTotal = eUnit.Type.armorPiercingAmount - unit.Type.armorAmount;
                if (armorTotal < 0) {
                    armorTotal = 0;
                }

                if (rand() % 100 + 1 >= armorTotal) {
                    unit.currentHealth -= eUnit.Type.damage;
                    if (unit.currentHealth <= 0) {
                        unit.destroyed = true;
                    }
                    break;
                }
                else {
                    break;
                }
            }
        }
        if (!fired) {
            eUnit.yPos = eUnit.yPos - (eUnit.Type.speed / 2);
        }
        DisplayBattle(units, eUnits);
    }

    for (const auto& unit : units) {
        if (unit.destroyed) {
            playerDestroyedCount++;
        }
    }

    if (playerDestroyedCount >= units.size())
    {
        return false;
    }
}
