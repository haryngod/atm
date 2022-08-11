#include <fstream>
#include "Cards.h"
#include "Card.h"
#include "Account.h"

Cards::Cards(){}


bool Cards::loadCardInformationFromDB()
{
	return false;
}

bool Cards::loadCardInformationFromJSON(string path)
{
	//read file and fill the cards information
	Json::Value root;
	Json::Reader reader;

	ifstream json(path);
	if (!json)
	{
		// error handle
		cout << "File is not exist. Please check.." << endl;
		return false;
	}

	try {
		reader.parse(json, root);

		for (auto& value : root)
		{
			
			string card_number = value["card_number"].asString();
			int pnum = value["pin"].asInt();
			string cname = value["customer_name"].asString();
			Card card(card_number, pnum, cname);

			vector<Account> ac_list;

			const Json::Value account_list_ = value["account_list"];
			for (auto& account : account_list_)
			{
				auto cname = account["customer_name"].asString();
				auto aname = account["account_name"].asString();				
				auto balance = account["balance"].asInt();
				auto anumber = account["account_number"].asString();

				Account ac(cname, aname, anumber, balance);
				ac_list.push_back(ac);
			}
			card.setAccountList(ac_list);
			card_list.insert(pair<string, Card>(card_number, card));
		}
	}
	catch (exception& e)
	{
		// Todo: error handle
		std::cout << "error accoured : " << e.what() << endl;
		return false;
	}
	json.close();
	return true;
}

bool Cards::getCardInfo(string number, Card& card)
{
	if (card_list.find(number) != card_list.end())
	{
		card = card_list[number];
		return true;
	}
	return false;
}
