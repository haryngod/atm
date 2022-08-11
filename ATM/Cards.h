#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include "Card.h"
#include "json/json.h"
using namespace std;

class Cards 
{
private:
	unordered_map<string, Card>  card_list;
public:
	Cards();
	/// <summary>
	/// get the card object using card number
	/// </summary>
	/// <param name="number">card number</param>
	/// <param name="card">card obj</param>
	/// <returns>if error occure false</returns>
	bool getCardInfo(string number, Card& card);
	/// <summary>
	/// for test, it read json file to load card and account information
	/// </summary>
	/// <param name="path"> json file path</param>
	/// <returns>if cannot read data false</returns>
	bool loadCardInformationFromJSON(string path);
	
	/// <summary>
	/// in the future, it could be connected with db
	/// </summary>
	/// <returns></returns>
	bool loadCardInformationFromDB();
};