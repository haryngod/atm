#include "Card.h"

Card::Card():
	card_number(""), pin_number(-1), customer_name("")
{ }


Card::Card(string cnum, int pnum, string cname):
	card_number(cnum), pin_number(pnum), customer_name(cname)
{ }

bool Card::checkPinNumber(int pin)
{
	// Todo: pin number should check with bank api like as below
	// return bank_api.verifyPinNumber(card_number, pin);
	if (pin == pin_number)
	{
		return true;
	}
	return false;
}

unordered_map<string, string> Card::getAccountList()
{
	unordered_map<string, string> map_account;
	for (auto ac : account_list)
	{
		map_account.insert(pair<string, string>(ac.first, ac.second.getName()));
	}
	return map_account;
}

Account Card::selectAccount(string number)
{
	if(account_list.find(number) != account_list.end())
		return account_list[number];
	return Account();
}

vector<int> Card::getCardDigitNumber()
{
	vector<int> digit_number;
	for (auto i : card_number)
		digit_number.push_back(i - '0');
	return digit_number;
}

void Card::setAccountList(vector<Account> ac_list)
{
	for (auto ac : ac_list)
	{
		account_list.insert(pair<string, Account>(ac.getName(), ac));
	}
}