#include "Account.h"

void Account::deposit(int amount)
{
	balance += amount;
}

void Account::withdraw(int amount)
{
	balance -= amount;
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