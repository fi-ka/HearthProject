#include "card.h"
class Minion : public Card
{
public:
	Minion(string name, int cost, int hp, int dmg);
	~Minion();

	void print();
private:
	int _hp;
	int _dmg;
};