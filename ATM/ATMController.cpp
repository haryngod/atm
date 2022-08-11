#include "ATMController.h"

ATMController::ATMController() : 
	is_card_inserted(false), is_acount_selected(false),
	card_pool(), inserted_card(), selected_account()
{}

bool ATMController::loadDataFromDB()
{
	return card_pool.loadCardInformationFromDB();
}

bool ATMController::testDataWithJson(string path)
{
	return card_pool.loadCardInformationFromJSON(path);
}

bool ATMController::checkVaildCardNumber(string card_number)
{
	is_card_inserted = true;
	// search card number in cardpool and get card object
	if (card_pool.getCardInfo(card_number, inserted_card))
		return true;
	return false;
}

void ATMController::takeoffCard()
{
	inserted_card = Card();
	selected_account = Account();
	is_card_inserted = false;
	is_acount_selected = false;
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

int ATMController::depositToAccount(int amount)
{
	return selected_account.deposit(amount);
}

int ATMController::withdrawFromAccount(int amount)
{
	return selected_account.withdraw(amount);
}