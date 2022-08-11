#include "Account.h"

Account::Account(string cname, string name, string anum, int bal):
	customer_name(cname), name(name), account_number(anum), balance(bal)
{}

int Account::deposit(int amount)
{
	balance += amount;
	return showBalance();
}

int Account::withdraw(int amount)
{
	balance -= amount;
	return showBalance();
}

int Account::showBalance()
{
	return balance;
}

string Account::getAccountNumber()
{
	return account_number;
}

string Account::getName()
{
	return name;
}

vector<int> Account::getAcccountDigitNumber()
{
	vector<int> digit_number;
	account_number.erase(remove(account_number.begin(), account_number.end(), '-'), account_number.end());
	for (auto i : account_number)
		digit_number.push_back(i - '0');
	return digit_number;
}