#include <iostream>
#include "GeneticAlgorithm.h"
#include "Battle.h"

//Converts Genome to Unit
std::vector<Unit>  buildUnits(const Genome& g) {
	std::vector<Unit> result;

	for (const auto& gene : g.units) {
		result.emplace_back(*gene.type, gene.x, gene.y);
	}

	return result;
}

//Grabs total cost of the army
int totalCost(const Genome& g) {
	int totalCost = 0;

	for (const auto& u : g.units) {
		totalCost += u.type->cost;
	}

	return totalCost;
}

//Checks and removes if over budget and makes sure everything is in range of the map
void normalize(Genome& g, int resources) {
	while (totalCost(g) > resources && !g.units.empty()) {
		int index = rand() % g.units.size();
		g.units.erase(g.units.begin() + index);
	}

	for (auto& u : g.units) {
		if (u.x < 0) u.x = 0;
		if (u.x > 39) u.x = 39;

		if (u.y < 25) u.y = 25;
		if (u.y > 39) u.y = 39;
	}
}

//Creates a random army 
Genome randomGenome(const std::vector<UnitType>& types, int resources) {
	Genome g;
	int currentCost = 0;

	while (true) {
		int index = rand() % types.size();
		const UnitType* type = &types[index];

		if (currentCost + type->cost > resources) {
			break;
		}

		UnitGene u;
		u.type = type;
		u.x = rand() % 40;
		u.y = rand() % 16 + 20;

		g.units.push_back(u);
		currentCost += type->cost;
	}

	return g;
}

//Runs the Battle Sim to evaluate score
float evaluateGenome(Genome& g, std::vector<UnitType>& types, std::vector<Unit>& enemyUnits) {
	std::vector<Unit> myUnits = buildUnits(g);

	float score = FastBattleSim(myUnits, enemyUnits);

	return score;
}

//Selects the best based on the score
Genome& selectParent(std::vector<Genome>& pop) {
	Genome* best = nullptr;

	for (int i = 0; i < 3; i++) {
		int index = rand() % pop.size();

		if (!best || pop[index].fitness > best->fitness) {
			best = &pop[index];
		}
	}

	return *best;
}

//Takes parts of two parents armies and combines them
Genome crossover(const Genome& a, const Genome& b) {
	Genome child;

	int size = std::max(a.units.size(), b.units.size());

	for (int i = 0; i < size; i++) {
		if (i < a.units.size() && i < b.units.size()) {
			child.units.push_back((rand() % 2) ? a.units[i] : b.units[i]);
		}
		else if (i < a.units.size()) child.units.push_back(a.units[i]);
		else if (i < b.units.size()) child.units.push_back(b.units[i]);
	}

	return child;
}

//Mutate. Randomly update some values and then see if it works better
void mutate(Genome& g, const std::vector<UnitType>& types, int resources) {
	for (auto& u : g.units) {
		if (rand() % 100 < 10) {
			u.x += rand() % 5 - 2;
			u.y += rand() % 5 - 2;
		}

		if (rand() % 100 < 5) {
			int idx = rand() % types.size();
			u.type = &types[idx];
		}
	}

	if (rand() % 100 < 5) {
		UnitGene u;
		int idx = rand() % types.size();
		u.type = &types[idx];
		u.x = rand() % 40;
		u.y = rand() % 16 + 20;

		g.units.push_back(u);
	}

	normalize(g, resources);
}

//Main run for the Genetic Algorithm
Genome runGeneticAlgorithm(std::vector<UnitType>& types, std::vector<Unit>& enemyUnits, int resources) {
	if (types.empty()) {
		std::cout << "ERROR : No UnitType loaded";
		exit(1);
	}

	const int popSize = 50;
	const int generations = 30;

	std::vector<Genome> population;

	for (int i = 0; i < popSize; i++) {
		population.push_back(randomGenome(types, resources));
	}

	Genome bestOverall;

	for (int gen = 0; gen < generations; gen++) {
		for (auto& g : population) {
			g.fitness = evaluateGenome(g, types, enemyUnits);
		}

		std::sort(population.begin(), population.end(), [](const Genome& a, const Genome& b) {
			return a.fitness > b.fitness;
		});

		float avg = 0.0f;
		for (auto& g : population) avg += g.fitness;
		avg /= population.size();
		std::cout << "Gen " << gen
			<< " Best: " << population[0].fitness
			<< " Avg: " << avg
			<< std::endl;

		if (gen == 0 || population[0].fitness > bestOverall.fitness) {
			bestOverall = population[0];
		}

		std::vector<Genome> newPop;
		newPop.push_back(population[0]);

		while (newPop.size() < popSize) {
			Genome& p1 = selectParent(population);
			Genome& p2 = selectParent(population);

			Genome child = crossover(p1, p2);

			if ((rand() % 100) < 15) {
				mutate(child, types, resources);
			}

			newPop.push_back(child);
		}
		population = newPop;
	}
	return bestOverall;
}