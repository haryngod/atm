#pragma once
#include <string>
#include <vector>
using namespace std;

class Account {
public: 
	Account() {};
	Account(string cname, string name, string anum, int bal);
private:
	string customer_name;
	string name;
	string account_number;
	int balance;
public:
	/// <summary>
	/// deposit to account
	/// </summary>
	/// <param name="amount"></param>
	/// <returns>account balance</returns>
	int deposit(int amount);

	/// <summary>
	/// withdraw from account
	/// </summary>
	/// <param name="amount"></param>
	/// <returns>account balance</returns>
	int withdraw(int amount);

	/// <summary>
	/// get account balance
	/// </summary>
	/// <returns>account balance</returns>
	int showBalance();
	
	/// <summary>
	/// get account name
	/// </summary>
	/// <returns>account name</returns>
	string getName();

	/// <summary>
	/// get account number as string
	/// </summary>
	/// <returns>account number including '-'</returns>
	string getAccountNumber();

	/// <summary>
	/// get account number as digit number
	/// </summary>
	/// <returns>digit number of vector</returns>
	vector<int> getAcccountDigitNumber();
};