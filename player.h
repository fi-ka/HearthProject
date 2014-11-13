#include 
using namespace std;

class Player
{
public:
	Player(int, int, int);
	~Player() = default;

	enum Hero : unsigned char{
		MAGE = 0
	}

	void setDeck();
	bool drawCard();
	void discardCard();
protected:

	list<Card> _deck;
	list<Card> _currentDeck;
	int _fatigue;mon
	list<Card> _hand;
	int _maxHealth;
	int _currentHealth;
	int _startDmg;
	int _currentDmg;
	int _maxMana;
	int _useableMana;
};