#include <iostream>
#include "JsonHandler.h"
#include "ArmyBuilder.h"


void ShowList(){
	std::vector<UnitType> units = CreateList();
	bool exit = false;
	
	while (exit == false) {
		std::cout << std::endl;
		int x = 0;
		int check = 999;
		for (const auto& i : units) {
			std::cout << x + 1 << ": " << i.name << std::endl;
			x++;
		}
		std::cout << "0: Exit" << std::endl << "Enter ship number to check details: ";

		std::cin >> check;

		std::cout << std::endl;

		if (check == 0) {
			exit = true;
		}
		else {
			check--;
			std::cout << "Name: " << units[check].name << std::endl;
			std::cout << "Cost: " << units[check].cost << std::endl;
			std::cout << "Range: " << units[check].range << std::endl;
			std::cout << "Max Health: " << units[check].maxHealth << std::endl;
			std::cout << "Damage: " << units[check].damage << std::endl;
			std::cout << "Armor: " << units[check].armorAmount << std::endl;
			std::cout << "Armor Piercing Amount: " << units[check].armorPiercingAmount << std::endl;
			std::cout << "Speed: " << units[check].speed << std::endl;
		}
	}
}

