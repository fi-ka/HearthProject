#ifndef HEARTHBOT_CARD_MANAGER_
#define HEARTHBOT_CARD_MANAGER_

#include "card.h"
#include "minion.h"
#include "spell.h"
#include "mongo/client/dbclient.h"

class CardManager
{
public:
	CardManager(mongo::DBClientConnection* clientConnection);
	~CardManager() = default;

	Card* GetCard(string name);

private:
	void ConnectDatabase();
	Minion* ConvertToMinion(mongo::BSONObj bson_card);
	Spell* ConvertToSpell(mongo::BSONObj bson_card);

	const string CARD_DATABASE = "hearthbot.cards";
	bool connected;
	mongo::DBClientConnection* _c;
};
#endif