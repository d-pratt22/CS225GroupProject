#include <iostream>
#include "Battle.h"

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

bool Battle(std::vector<Unit>& units) {
    for (const auto& unit : units) {
        /*
        if (in range) {
        shoot at target
        }
        else{
        move up
        }
        */
    }
}
/*
-Grab list of armies
-Set up loop to go through each ship one by one
--See if ship is in range of another ship
--If not then move ships based on their movement speed
-If in range then attack the other ships and take into account how armor and all that

-Basically each ship needs to run through a loop to either move or shoot, then play a numbers game

-Create a vector (or something) of enemy x and y then see which one is closest by numbers then either move to it or shoot it
*/