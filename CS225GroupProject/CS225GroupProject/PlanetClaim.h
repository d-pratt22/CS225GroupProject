#ifndef PLANETCLAIM_H
#define PLANETCLAIM_H

#include <vector>
#include "Player.h"
#include "Planets.h"

bool OnPlanet(Player player, std::vector<Planet>& planets);

Planet& GetPlanet(Player player, std::vector<Planet>& planets);

void ClaimPlanet(Player player, std::vector<Planet>& planets);

#endif