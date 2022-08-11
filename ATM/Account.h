#pragma once
#include <string>

using namespace std;

class Account {
private:
	string name;
	int balance;
	string customer_name;
	string account_number;
public:
	void deposit(int amount);
	void withdraw(int amount);
	int showBalance();
	string getAccountNumber();
	string getName();
};