#include <json.hpp>
#include <fstream>
#include "JsonHandler.h"
using json = nlohmann::json;

void CreateList() {
	std::ifstream f("UnitTypes.json");
	json data = json::parse(f);
}

void AccessList() {

}