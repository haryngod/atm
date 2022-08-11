#include "Cards.h"

Cards::Cards(){ }

Cards::Cards(string path)
{
	loadCardInformationFromFile(path);
}

// load data for test from file
loadCardInformationFromJSON(string path)
{
	//read file and fill the cards information
}

bool Cards::getCardInfo(string number, Card& card)
{
	if (cards.find(number) != cards.end())
	{
		card = cards[number];
		return true;
	}
	return false;
}
