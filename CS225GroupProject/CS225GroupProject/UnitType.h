#ifndef UNITTYPE_H
#define UNITTYPE_H

#include <string>
#include <json.hpp>

using json = nlohmann::json;

struct UnitType {
	std::string name;
	int cost;
	int range;
	int maxHealth;
	int damage;
	int armorAmount; //out of 100, chance to reflect damage
	int armorPiercingAmount; //out of 100, amount of armor to ignore
	int speed;
};

inline void from_json(const json& j, UnitType& u) {
	j.at("name").get_to(u.name);
	j.at("cost").get_to(u.cost);
	j.at("range").get_to(u.range);
	j.at("maxHealth").get_to(u.maxHealth);
	j.at("damage").get_to(u.damage);
	j.at("armorAmount").get_to(u.armorAmount);
	j.at("armorPiercingAmount").get_to(u.armorPiercingAmount);
	j.at("speed").get_to(u.speed);
}

#endif
