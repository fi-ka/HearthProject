#ifndef HEARTHBOT_CARD_H
#define HEARTHBOT_CARD_H

#include <string>

using namespace std;
class Card
{
public:
	Card(string name, int cost);
	~Card() = default;

	virtual void print() = 0;
protected:
	string _name;
	int _cost;
};

#endif