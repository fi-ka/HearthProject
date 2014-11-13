#include "card_manager.h"

CardManager::CardManager(mongo::DBClientConnection* c) : _c(c){
	connected = false;
	ConnectDatabase();
}

void CardManager::ConnectDatabase(){
	try {
  		_c->connect("localhost");
  		connected = true;
  	    std::cout << "connected ok" << std::endl;
  	} catch( const mongo::DBException &e ) {
  	    std::cout << "Could not connect to database, caught " << e.what() << std::endl;
  	}
}

Card* CardManager::GetCard(string name){
  if(connected){
  	mongo::BSONObj cardQuery = mongo::BSONObjBuilder().appendRegex("name" , name).obj();
  	auto_ptr<mongo::DBClientCursor> cursor = _c->query(CARD_DATABASE, cardQuery);

  	while(cursor->more()){
  		mongo::BSONObj bson_card = cursor->next();
      if(bson_card["type"].String().compare("Minion") == 0){
  		  return ConvertToMinion(bson_card);
      }
      if(bson_card["type"].String().compare("Spell") == 0){
        return ConvertToSpell(bson_card);
      }
  	}
  	Minion* notFound = new Minion("nothing found", 0,0,0);
  	return notFound;
  }
  Minion* notConnected = new Minion("not connected", 0,0,0);
  return notConnected;
}

Minion* CardManager::ConvertToMinion(mongo::BSONObj bson_card)
{
  string name = bson_card["name"].String();
  int cost = bson_card["cost"].Int();
  int health = bson_card["health"].Int();
  int attack = bson_card["attack"].Int();
  Minion* minion = new Minion(name, cost, health, attack);
  return minion;
}

Spell* CardManager::ConvertToSpell(mongo::BSONObj bson_card)
{
  string name = bson_card["name"].String();
  int cost = bson_card["cost"].Int();
  Spell* spell = new Spell(name, cost);
  return spell;
}