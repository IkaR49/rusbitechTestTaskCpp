#include <string>
#include "Animal.hpp"

Animal::Animal()
{
	//
}
Animal::A~Animal()
{
	//
}

// Getters
std::string Animal::AgetSpecies()
{
	//
}
std::string Animal::AgetMoniker()
{
	//
}
unsigned int Animal::AgetAge()
{
	//
}
unsigned float Animal::AgetCost()
{
	return _cost;
}

// Setters
void Animal::AsetSpecies(const std::string * species)
{
	_species = species.empty() ? "exotic" : species;
}
void Animal::AsetMoniker(const std::string * moniker)
{
	_moniker = moniker.empty() ? "none" : moniker;
}
void Animal::AsetBirthDate(/**/)
{
	//
}
void Animal::AsetCost(double cost)
{
	_cost = (cost > 0) ? cost : 0;
}

