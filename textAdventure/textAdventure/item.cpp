#include "item.h"



Item::Item()
{
	_itemName = nullptr;
	_itemID = 0;
	_itemState = 0;

	_lookList = nullptr;
	_takeList = nullptr;
	_useList = nullptr;
}

Item::Item(string& itemName, int& itemID, int& itemState, list<string>& lookList, list<string>& takeList, list<string>& useList)
{
	_itemName = nullptr;
	_lookList = nullptr;
	_takeList = nullptr;
	_useList = nullptr;

	initialize(itemName, itemID, itemState, lookList, takeList, useList);
}

Item::~Item()
{
	deleteItem();
}



// Initialize an Item object to the argument values
int Item::initialize(string& itemName, int& itemID, int& itemState, list<string>& lookList, list<string>& takeList, list<string>& useList)
{
	int successValue = 0;

	successValue = deleteItem();

	if (successValue != 0)
	{
		_itemName = new string;
		*_itemName = itemName;

		_itemID = itemID;
		_itemState = itemState;

		// Use the list copy constructor to clone the incoming lists
		_lookList = new list<string>(lookList);
		_takeList = new list<string>(takeList);
		_useList = new list<string>(useList);

		successValue = 1;
	}

	return successValue;
}

// Deallocate the contents of an Item object
int Item::deleteItem()
{
	int successValue = 0;

	if (_itemName != nullptr)
	{
		delete _itemName;
		_itemName = nullptr;
	}

	_itemID = 0;
	_itemState = 0;

	if (_lookList != nullptr)
	{
		_lookList->clear();
		delete _lookList;
		_lookList = nullptr;
	}

	if (_takeList != nullptr)
	{
		_takeList->clear();
		delete _takeList;
		_takeList = nullptr;
	}

	if (_useList != nullptr)
	{
		_useList->clear();
		delete _useList;
		_useList = nullptr;
	}

	// If all pointers are null then return success
	if ((_itemName == nullptr) && (_lookList == nullptr) && (_takeList == nullptr) && (_useList == nullptr))
	{
		successValue = 1;
	}

	return successValue;
}


// Returns 0 for general failure, -1 if the state is larger than the available phrases, and 1 for success.
int Item::display()
{
	int successValue = 0;

	if ((_itemName != nullptr) && (_lookList != nullptr))
	{
		int i = 0;
		cout << "Item name: " << *_itemName << endl;
		cout << "Item ID: " << _itemID << endl;
		cout << "Item state: " << _itemState << endl;
		
		// https://www.cplusplus.com/reference/list/list/begin/
		// https://stackoverflow.com/questions/5733842/how-to-get-a-certain-element-in-a-list-given-the-position
		
		// If the size of the phrase lists can accommodate the requested item state
		if (unsigned(_itemState) < _lookList->size())
		{
			cout << "Look command phrase for current state: " << getLookPhrase() << endl;
			cout << "Take command phrase for current state: " << getTakePhrase() << endl;
			cout << "Use command phrase for current state: " << getUsePhrase() << endl;
			
			/*
			// Set currentPhrase to the beginning of the _lookList
			currentPhrase = Item::_lookList->begin();

			// Iterate to the desired location
			advance(currentPhrase, _itemState);

			// Display the look phrase for the item's current state
			cout << "\"" << *currentPhrase << "\"" << endl;
			*/

			successValue = 1;
		}
		else
		{
			successValue = -1;
		}
	}

	return successValue;
}


int Item::getItemID()
{
	return _itemID;
}

string Item::getLookPhrase()
{
	return getStatePhrase(*_lookList, _itemState);
}

string Item::getTakePhrase()
{
	return getStatePhrase(*_takeList, _itemState);
}

string Item::getUsePhrase()
{
	return getStatePhrase(*_useList, _itemState);
}

string Item::getUsePhrase(int& phraseState)
{
	return getStatePhrase(*_useList, phraseState);
}

string Item::getStatePhrase(list<string>& aList, int& phraseState)
{
	list<string>::iterator	currentPhrase;
	string			statePhrase = "\n";

	if (unsigned(_itemState) < aList.size())
	{
		// Set currentPhrase to the beginning of the _lookList
		currentPhrase = aList.begin();

		// Iterate to the desired location
		advance(currentPhrase, _itemState);

		// Display the look phrase for the item's current state
		statePhrase = *currentPhrase;
	}

	return statePhrase;
}