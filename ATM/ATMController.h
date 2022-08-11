#pragma once
#include <string>
#include "Card.h"
#include "Cards.h"
#include "Account.h"
class ATMController {
private:
	bool is_card_inserted;
	bool is_acount_selected;
	Cards card_pool;
	Card inserted_card;
	Account selected_account;
public:
	ATMController();

	/// <summary>
	/// Todo: implement
	/// load data from db
	/// </summary>
	/// <returns>if cannot load data false</returns>
	bool loadDataFromDB();

	/// <summary>
	/// read data from json file for test
	/// </summary>
	/// <param name="path"></param>
	/// <returns>if cannot read data false</returns>
	bool testDataWithJson(string path);

	/// <summary>
	/// check card number is valid or not and get card obj
	/// </summary>
	/// <param name="card_number"></param>
	/// <returns>if there is no card false</returns>
	bool checkVaildCardNumber(string card_number);

	/// <summary>
	/// reset all information
	/// </summary>
	void takeoffCard();

	/// <summary>
	/// check the card pin number
	/// </summary>
	/// <param name="pin_number"></param>
	/// <returns>if it is incorrect false</returns>
	bool inputPinNumber(int pin_number);

	/// <summary>
	/// get account list using
	/// </summary>
	/// <returns>account number and name list</returns>
	unordered_map<string, string>  getAccountList();

	/// <summary>
	/// select account using account number
	/// </summary>
	/// <param name="account_number"></param>
	void selectAccount(string account_number);

	/// <summary>
	/// get account balance
	/// </summary>
	/// <returns>account balance</returns>
	int showAccountBalance();

	/// <summary>
	/// deposit to account
	/// </summary>
	/// <param name="amount"></param>
	/// <returns>account balance</returns>
	int depositToAccount(int amount);

	/// <summary>
	/// withdraw from account
	/// </summary>
	/// <param name="amount"></param>
	/// <returns>account balance</returns>
	int withdrawFromAccount(int amount);
};