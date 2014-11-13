#include <cstdlib>
#include <iostream>

#include "card_manager.h"
#include "deck_manager.h"
#include "card.h"
#include "mongo/client/dbclient.h"

using namespace std;




int main() {
    mongo::DBClientConnection clientConnection;
	
    CardManager cm(&clientConnection);
	DeckManager deckManager(cm);
	list<Card*> deck = deckManager.GetDeck("deck1.txt");

	for(Card* c : deck)
		c->print();

    return EXIT_SUCCESS;
}