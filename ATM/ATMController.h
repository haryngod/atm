#pragma once
#include <string>
#include "Card.h"
#include "Account.h"
class ATMController {
private:
	bool is_card_inserted;
	bool is_acount_selected;
	Card inserted_card;
	Account selected_account;
public:
	ATMController();
	bool checkVaildCardNumber(string card_number);
	bool inputPinNumber(int pin_number);
	unordered_map<string, string>  getAccountList();
	void selectAccount(string account_number);
	int showAccountBalance();
	void depositToAccount(int amount);
	void withdrawToAccount(int amount);
};