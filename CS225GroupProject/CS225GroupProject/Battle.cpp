#include <iostream>
#include "Battle.h"
#include "Display.h"
#include "ErrorHandling.h"

std::vector<Unit> SetupBattlefield(std::vector<UnitType>& army) {
	std::vector<Unit> units;

    for (int i = 0; i < army.size(); i++) {
        const UnitType& type = army[i];

        int x = 0;
        int y = 0;

        std::cout << "Enter x coordinate of ship #" << i + 1 << " the " << type.name << " (0-39): ";
        std::cin >> x;
        x = BetweenTwoValues(0, 39, x);
        std::cout << "Enter y coordinate (0-15): ";
        std::cin >> y;
        y = BetweenTwoValues(0, 15, y);

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
    bool looping = true;

    while (looping) {
        int destroyedCount = 0;
        int playerDestroyedCount = 0;
        for (auto& unit : units) {
            if (unit.destroyed) continue;
            bool fired = false;
            for (auto& eUnit : eUnits) {
                if (eUnit.destroyed) continue;
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
                for (auto& eUnit : eUnits) {
                    if (eUnit.destroyed) continue;

                    if (unit.xPos < eUnit.xPos) unit.xPos += unit.Type.speed / 2;
                    else if (unit.xPos > eUnit.xPos) unit.xPos -= unit.Type.speed / 2;

                    if (unit.yPos < eUnit.yPos) unit.yPos += unit.Type.speed / 2;
                    else if (unit.yPos > eUnit.yPos) unit.yPos -= unit.Type.speed / 2;

                    break;
                }
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
            if (eUnit.destroyed) continue;
            bool fired = false;
            for (auto& unit : units) {
                if (unit.destroyed) continue;
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
                for (auto& unit : units) {
                    if (unit.destroyed) continue;

                    if (eUnit.xPos < unit.xPos) eUnit.xPos += eUnit.Type.speed / 2;
                    else if (eUnit.xPos > unit.xPos) eUnit.xPos -= eUnit.Type.speed / 2;

                    if (eUnit.yPos < unit.yPos) eUnit.yPos += eUnit.Type.speed / 2;
                    else if (eUnit.yPos > unit.yPos) eUnit.yPos -= eUnit.Type.speed / 2;

                    break;
                }
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
    
}

float FastBattleSim(std::vector<Unit>& units, std::vector<Unit>& eUnits) {
    const int maxTurns = 50;
    int rangeVal = 999;

    for (int turn = 0; turn < maxTurns; turn++) {
        for (auto& unit : units) {
            if (unit.destroyed) continue;

            Unit* target = nullptr;
            int bestDist = INT_MAX;

            for (auto& eUnit : eUnits) {
                if (eUnit.destroyed) continue;

                int dist = abs(eUnit.xPos - unit.xPos) +
                    abs(eUnit.yPos - unit.yPos);

                if (dist < bestDist) {
                    bestDist = dist;
                    target = &eUnit;
                }
            }

            if (!target) continue;

            int range = unit.Type.range / 10;

            if (bestDist <= range) {
                int armor = std::max(0,
                    target->Type.armorAmount - unit.Type.armorPiercingAmount);

                float hitChance = 1.0f - (armor / 100.0f);
                float damage = unit.Type.damage * hitChance;

                target->currentHealth -= (int)damage;

                if (target->currentHealth <= 0) {
                    target->destroyed = true;
                }
            }
            else {
                if (unit.xPos < target->xPos) {
                    unit.xPos += unit.Type.speed / 2;
                }
                else if (unit.xPos > target->xPos) {
                    unit.xPos -= unit.Type.speed / 2;
                }

                if (unit.yPos < target->yPos) {
                    unit.yPos += unit.Type.speed / 2;
                }
                else if (unit.yPos > target->yPos) {
                    unit.yPos -= unit.Type.speed / 2;
                }
            }
        }

        for (auto& eUnit : eUnits) {
            if (eUnit.destroyed) continue;

            Unit* target = nullptr;
            int bestDist = INT_MAX;

            for (auto& unit : units) {
                if (unit.destroyed) continue;

                int dist = abs(unit.xPos - eUnit.xPos) +
                    abs(unit.yPos - eUnit.yPos);

                if (dist < bestDist) {
                    bestDist = dist;
                    target = &unit;
                }
            }

            if (!target) continue;

            int range = eUnit.Type.range / 10;

            if (bestDist <= range) {
                int armor = std::max(0,
                    target->Type.armorAmount - eUnit.Type.armorPiercingAmount);

                float hitChance = 1.0f - (armor / 100.0f);
                float damage = eUnit.Type.damage * hitChance;

                target->currentHealth -= (int)damage;

                if (target->currentHealth <= 0) {
                    target->destroyed = true;
                }
            }
            else {
                if (eUnit.xPos < target->xPos) {
                    eUnit.xPos += eUnit.Type.speed / 2;
                }
                else if (eUnit.xPos > target->xPos) {
                    eUnit.xPos -= eUnit.Type.speed / 2;
                }

                if (eUnit.yPos < target->yPos) {
                    eUnit.yPos += eUnit.Type.speed / 2;
                }
                else if (eUnit.yPos > target->yPos) {
                    eUnit.yPos -= eUnit.Type.speed / 2;
                }
            }
        }
    }
    float playerDestroyedCount = 0;
    float destroyedCount = 0;
    float totalPHealth = 0;
    float totalEHealth = 0;

    for (auto& u : units) {
        if (!u.destroyed) {
            totalPHealth += u.currentHealth;
        }
    }

    for (auto& e : eUnits) {
        if (!e.destroyed) {
            totalEHealth += e.currentHealth;
        }
    }

    for (const auto& unit : units) {
        if (unit.destroyed) {
            playerDestroyedCount++;
        }
    }

    for (const auto& eUnit : eUnits) {
        if (eUnit.destroyed) {
            destroyedCount++;
        }
    }

    float score =
        (totalPHealth * 1.5f)
        - (totalEHealth * 1.2f)
        + (destroyedCount * 100)
        - (playerDestroyedCount * 80);

    return score;
}