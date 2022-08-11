#include "ATMController.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "===========================================" << endl;
	cout << "*             ATM Test Start              *" << endl;
	cout << "===========================================" << endl;

	ATMController atm = ATMController();
	if (atm.testDataWithJson("atm_test.json"))
	{
		cout << ">> " << "json file load successfully " << endl;
	}
	else
	{
		cout << ">> " << "error: Json file load fail " << endl;
	}

	string card_number_ = "1234567812345678";
	if (atm.checkVaildCardNumber(card_number_))
	{
		cout << ">>>> " << card_number_ << " valid card number " << endl;
		
		if (atm.inputPinNumber(1234))
		{
			cout << ">>>>>> " << card_number_ << " valid pin number " << endl;
			auto account_list_ = atm.getAccountList();
			auto selected_account_ = account_list_.begin()->first;
			atm.selectAccount(selected_account_);
			cout << ">>>>>>>> [showAccountBlance] : " << atm.showAccountBalance() << endl;
			cout << ">>>>>>>> [depositToAccount(10)] : " << atm.depositToAccount(10) << endl;
			cout << ">>>>>>>> [withdrawFromAccount(100)] : " << atm.withdrawFromAccount(100) << endl;
		}
		else
		{
			cout << ">>>> " << "error: invalid pin number " << endl;
		}
	}
	else
	{
		cout << ">>>> " << "error: invalid card number " << endl;
	}

	atm.takeoffCard();
}