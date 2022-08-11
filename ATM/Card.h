#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Account.h"
using namespace std;

class Card{
public:
	Card();
	Card(string cnum, int pnum, string cname);
private:
	string card_number;

	// Note: pin number just for test
	int pin_number;

	string customer_name;
	// account number, account mapping
	unordered_map<string, Account> account_list;
public:
	/// <summary>
	/// Todo: connect bank API and check pin number there
	/// check pin number
	/// </summary>
	/// <returns>if it is incorrect false</returns>
	bool checkPinNumber(int pin);

	/// <summary>
	/// get account list
	/// </summary>
	/// <returns> account number and name</returns>
	unordered_map<string, string> getAccountList();

	/// <summary>
	/// select account
	/// </summary>
	/// <returns> account object </returns>
	Account selectAccount(string number);

	/// <summary>
	/// set account list
	/// </summary>
	void setAccountList(vector<Account> ac_list);

	/// <summary>
	/// get card number as digit number
	/// </summary>
	/// <returns> digit number as vector of integer </returns>
	vector<int> getCardDigitNumber();
};