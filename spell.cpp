#include "spell.h"
#include <iostream>

Spell::Spell(string name, int cost) : Card(name, cost)
{}

void Spell::print()
{
	std::cout << _name << ": cost: " << _cost << std::endl;
}