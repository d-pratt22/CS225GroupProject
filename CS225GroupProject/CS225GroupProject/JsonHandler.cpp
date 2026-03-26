#include <json.hpp>
#include <fstream>
#include <vector>
#include "JsonHandler.h"
#include "UnitType.h"

using json = nlohmann::json;

std::vector<UnitType> CreateList() {
	std::ifstream f("UnitTypes.json");

	json j;

	f >> j;

	std::vector<UnitType> units;

	for (const auto& item : j["objects"]) {
		units.push_back(item.get<UnitType>());
	}

	return units;
}