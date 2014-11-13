Player::Player(int maxHealth, int dmg, int maxMana) : _maxHealth(maxHealth), _currentHealth(maxHealth),
 		_dmg(dmg), _currentDmg(dmg), _maxMana(maxMana)
{
	_useableMana = 1;
	_fatigue = 0;
}

void Player::setDeck(list<Card> deck)
{
	if(deck.size() == 30){
		_deck = deck;
		_currentDeck = deck;
	}
}

bool Player::drawCard()
{
	if(currentDeck.size > 0)
	{
		//TODO
	}
}