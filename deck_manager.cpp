#include "deck_manager.h"
#include <map>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <boost/algorithm/string/trim.hpp>

struct Line
{
    std::string lineData;

    operator std::string() const
    {
        return lineData;
    }
};

std::istream& operator>>(std::istream& str,Line& data)
{
    std::getline(str,data.lineData);
    return str;
}

DeckManager::DeckManager(CardManager cardManager) : _cardManager(cardManager)
{
}

list<Card*> DeckManager::GetDeck(string file_name){
	list<Card*> deck;

	map<string, int> deckList = GetDeckFromFile(file_name);
	for(pair<string, int> cardToken : deckList)
	{
		for(int i = 0; i < cardToken.second; i++){
			Card* card = _cardManager.GetCard(cardToken.first);
			deck.push_front(card);
		}
	}
	return deck;
}

map<string, int> DeckManager::GetDeckFromFile(string file_name)
{
	ifstream deckFile("decks/" + file_name);

	istream_iterator<Line> eof;
	istream_iterator<Line> ii(deckFile);
	vector<string> deckInput(ii, eof);

	map<string,int> deckList;
	for(string s  : deckInput){
		int splitPos = s.find(",");
		string name = s.substr(0,splitPos);
		string amountString = s.substr(splitPos+1);
		boost::algorithm::trim(name);
		boost::algorithm::trim(amountString);
		int amount = atoi(amountString.c_str());
		deckList[name]=amount;
	}

	deckFile.close();

	return deckList;
}