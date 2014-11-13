#include "minion.h"
#include <iostream>

Minion::Minion(string name, int cost, int hp, int dmg) : Card(name, cost), _hp(hp), _dmg(dmg)
{}

void Minion::print()
{
	std::cout << _name << ": cost: " << _cost << " hp: " << _hp << " dmg: " << _dmg << std::endl;
}