#include "Card.h"

Card::Card() { }

bool Card::verifyCard(string number)
{
	if (number == card_number)
	{
		return true;
	}
	return false;
}

bool Card::checkPinNumber(int pin)
{
	if (pin == pin_number)
	{
		return true;
	}
	return false;
}

unordered_map<string, string> Card::getAccountList()
{
	unordered_map<string, string> map_account;
	for (auto ac : account)
	{
		map_account.insert(pair<string, string>(ac.first, ac.second.getName()));
	}
	return map_account;
}

Account Card::selectAccount(string number)
{
	return account[number];
}

