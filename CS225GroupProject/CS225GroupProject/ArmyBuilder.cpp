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

void PurchaseList(int& resource, std::vector<UnitType>& army) {
	std::vector<UnitType> units = CreateList();
	bool exit = false;

	while (exit == false) {
		std::cout << std::endl << "Your current resource count: " << resource << std::endl;
		int x = 0;
		int check = 999;
		int	quantity = 999;
		for (const auto& i : units) {
			std::cout << x + 1 << ": " << i.name << " -- " << i.cost << " resources" << std::endl;
			x++;
		}
		std::cout << "0: Exit" << std::endl << "Enter a number to build a ship for your army: ";
		std::cin >> check;

		if (check == 0) {
			exit = true;
		}
		else {
			check--;
			std::cout << units[check].name << " costs " << units[check].cost << " resources" << std::endl;
			std::cout << "Enter quantity of ships to purchase(0-" << resource / units[check].cost << "): ";
			std::cin >> quantity;
			for (int i = 0; i < quantity; i++) {
				army.push_back(units[check]);
				resource = resource - units[check].cost;
			}
		}
	}
}

int MakeDefaultArmy(std::vector<UnitType>& army) {
	bool exit = false;
	int resource = 1000;
	std::cout << "General, you currently have 1000 resources at your disposal" << std::endl;
	std::cout << "Use them as you see fit..." << std::endl << std::endl;
	while (exit == false) {
		int check = 999;
		std::cout << "Please select one of the following options:" << std::endl;
		std::cout << "1: Show list of ships\n";
		std::cout << "2: Purchase ships\n";
		std::cout << "0: Exit\n";
		std::cin >> check;

		if (check == 1) {
			ShowList();
		}
		else if (check == 2) {
			PurchaseList(resource, army);
		}
		else {
			exit = true;
		}

	}
	return resource;
	
}
