#ifndef GENETICALGORITHM_H
#define GENETICALGORITH_H

#include <vector>
#include "UnitType.h"
#include "Unit.h"

struct UnitGene {
	const UnitType* type;
	int x;
	int y;
};

//Sort of like an army in the regular mode
struct Genome {
	std::vector<UnitGene> units;
	float fitness = 0.0f;
};

std::vector<Unit>  buildUnits(const Genome& g);

int totalCost(const Genome& g);

void normalize(Genome& g, int resources);

Genome randomGenome(const std::vector<UnitType>& types, int resources);

float evaluateGenome(Genome& g, std::vector<UnitType>& types, std::vector<Unit>& enemyUnits);

Genome& selectParent(std::vector<Genome>& pop);

Genome crossover(const Genome& a, const Genome& b);

void mutate(Genome& g, const std::vector<UnitType>& types, int resources);

Genome runGeneticAlgorithm(std::vector<UnitType>& types, std::vector<Unit>& enemyUnits, int resources);

#endif