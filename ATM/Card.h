#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Account.h"
using namespace std;

class Card{
public:
	Card();
private:
	string card_number;
	int pin_number;
	string customer_name;
	// account number, account mapping
	unordered_map<string, Account> account;
public:
	bool verifyCard(string number);
	bool checkPinNumber(int pin);
	unordered_map<string, string> getAccountList();
	Account selectAccount(string number);
};