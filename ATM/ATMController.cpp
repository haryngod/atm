#include "ATMController.h"

ATMController::ATMController() : is_card_inserted(false), is_acount_selected(false)
{
}

bool ATMController::checkVaildCardNumber(string card_number)
{
	is_card_inserted = true;
	// search card number in cardpool and get card object
	return false;
}

bool ATMController::inputPinNumber(int pin_number)
{
	if(is_card_inserted)
		return inserted_card.checkPinNumber(pin_number);
	return false;
}

unordered_map<string, string> ATMController::getAccountList()
{
	if(is_card_inserted)
		return inserted_card.getAccountList();
	return unordered_map<string, string>();
}

void ATMController::selectAccount(string account_number)
{
	selected_account = inserted_card.selectAccount(account_number);
	is_acount_selected = true;
}

int ATMController::showAccountBalance()
{
	if (is_acount_selected)
		return selected_account.showBalance();
	else
		return -1;
}

void ATMController::depositToAccount(int amount)
{
	selected_account.deposit(amount);
}

void ATMController::withdrawToAccount(int amount)
{
	selected_account.withdraw(amount);
}