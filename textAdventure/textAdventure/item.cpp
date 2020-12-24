#include "item.h"



Item::Item()
{
	_itemName = nullptr;
	_itemID = 0;
	_phraseList = nullptr;
}

Item::Item(string& itemName, int& itemID, list<string>& phraseList)
{
	_itemName = new string;
	*_itemName = itemName;

	_itemID = itemID;

	// Uses list copy constructor to clone the incoming list
	_phraseList = new list<string>(phraseList);
}

Item::~Item()
{
	if (_itemName != nullptr)
	{
		delete _itemName;
		_itemName = nullptr;
	}

	_itemID = 0;

	if (_phraseList != nullptr)
	{
		_phraseList->clear();
		delete _phraseList;
		_phraseList = nullptr;
	}
}