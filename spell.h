#include "card.h"
class Spell : public Card
{
public:
	Spell(string name, int cost);
	~Spell();
	void print();
};