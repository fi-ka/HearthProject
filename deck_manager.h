#ifndef HEARTHBOT_DECK_MANAGER_
#define HEARTHBOT_DECK_MANAGER_

#include "card_manager.h"
#include "card.h"
class DeckManager
{
public:
	DeckManager(CardManager cardManager);
	~DeckManager() = default;

	list<Card*> GetDeck(string file_name);
private:
	map<string,int> GetDeckFromFile(string file_name);
	CardManager _cardManager;
};

#endif