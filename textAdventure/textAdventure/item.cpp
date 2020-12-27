#include "item.h"



Item::Item()
{
	_itemName = nullptr;
	_itemID = 0;
	_itemState = 0;

	_lookPhrases = nullptr;
	_lookFlag = nullptr;

	_takePhrases = nullptr;
	_takeFlag = nullptr;

	_usableWithList = nullptr;

	_searchPhrases = nullptr;
	_searchFlag = nullptr;
	_itemsContained = nullptr;

	_climbPhrases = nullptr;
	_climbFlag = nullptr;

	_equipPhrases = nullptr;
	_equipFlag = nullptr;
}

Item::Item(
	const string& itemName,
	const int& itemID,
	const int& itemState,
	const list<string>& lookPhrases,
	const list<int>& lookFlag,
	const list<string>& takePhrases,
	const list<int>& takeFlag,
	const list<list<tuple<string, int, int>>>& usableWithList,
	const list<string>& searchPhrases,
	const list<int>& searchFlag,
	const list<Item>& itemsContained,
	const list<string>& climbPhrases,
	const list<int>& climbFlag,
	const list<string>& equipPhrases,
	const list<int>& equipFlag)
{
	_itemName = nullptr;

	_lookPhrases = nullptr;
	_lookFlag = nullptr;

	_takePhrases = nullptr;
	_takeFlag = nullptr;

	_usableWithList = nullptr;

	_searchPhrases = nullptr;
	_searchFlag = nullptr;
	_itemsContained = nullptr;

	_climbPhrases = nullptr;
	_climbFlag = nullptr;

	_equipPhrases = nullptr;
	_equipFlag = nullptr; nullptr;
	_takePhrases = nullptr;

	initialize(
		itemName, 
		itemID, 
		itemState,
		lookPhrases, 
		lookFlag,
		takePhrases,
		takeFlag,
		usableWithList,
		searchPhrases,
		searchFlag,
		itemsContained,
		climbPhrases,
		climbFlag,
		equipPhrases,
		equipFlag);
}

Item::Item(const Item& anItem)
{
	_itemName = nullptr;

	_lookPhrases = nullptr;
	_lookFlag = nullptr;

	_takePhrases = nullptr;
	_takeFlag = nullptr;

	_usableWithList = nullptr;

	_searchPhrases = nullptr;
	_searchFlag = nullptr;
	_itemsContained = nullptr;

	_climbPhrases = nullptr;
	_climbFlag = nullptr;

	anItem._lookPhrases;

	_equipPhrases = nullptr;
	_equipFlag = nullptr; nullptr;
	_takePhrases = nullptr;

	initialize(
		*anItem._itemName,
		anItem._itemID,
		anItem._itemState,
		*anItem._lookPhrases,
		*anItem._lookFlag,
		*anItem._takePhrases,
		*anItem._takeFlag,
		*anItem._usableWithList,
		*anItem._searchPhrases,
		*anItem._searchFlag,
		*anItem._itemsContained,
		*anItem._climbPhrases,
		*anItem._climbFlag,
		*anItem._equipPhrases,
		*anItem._equipFlag);

}

Item::~Item()
{
	deleteItem();
}



// Initialize an Item object to the argument values
int Item::initialize(
	const string& itemName,
	const int& itemID,
	const int& itemState,
	const list<string>& lookPhrases,
	const list<int>& lookFlag,
	const list<string>& takePhrases,
	const list<int>& takeFlag,
	const list<list<tuple<string, int, int>>>& usableWithList,
	const list<string>& searchPhrases,
	const list<int>& searchFlag,
	const list<Item>& itemsContained,
	const list<string>& climbPhrases,
	const list<int>& climbFlag,
	const list<string>& equipPhrases,
	const list<int>& equipFlag)
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
		_lookPhrases = new list<string>(lookPhrases);
		_lookFlag = new list<int>(lookFlag);

		_takePhrases = new list<string>(takePhrases);
		_takeFlag = new list<int>(takeFlag);

		_usableWithList = new list<list<tuple<string, int, int>>>(usableWithList);

		_searchPhrases = new list<string>(searchPhrases);
		_searchFlag = new list<int>(searchFlag);
		_itemsContained = new list<Item>(itemsContained);

		_climbPhrases = new list<string>(climbPhrases);
		_climbFlag = new list<int>(climbFlag);

		_equipPhrases = new list<string>(equipPhrases);
		_equipFlag = new list<int>(equipFlag);


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

	deleteList(_lookPhrases);
	deleteList(_lookFlag);

	deleteList(_takePhrases);
	deleteList(_takeFlag);

	deleteList(_usableWithList);

	deleteList(_searchPhrases);
	deleteList(_searchFlag);
	
	if (_itemsContained != nullptr)
	{
		_itemsContained->clear();
		delete _itemsContained;
	}

	deleteList(_climbPhrases);
	deleteList(_climbFlag);

	deleteList(_equipPhrases);
	deleteList(_equipFlag);
	
	// If all pointers are null then return success
	if (
		(_itemName == nullptr) && 
		(_lookPhrases == nullptr) && 
		(_lookFlag == nullptr) &&
		(_takePhrases == nullptr) &&
		(_takeFlag == nullptr)&&
		(_usableWithList == nullptr) &&
		(_searchPhrases == nullptr) &&
		(_searchFlag == nullptr) &&
		(_itemsContained == nullptr) &&
		(_climbPhrases == nullptr) &&
		(_climbFlag == nullptr) &&
		(_equipPhrases == nullptr) &&
		(_equipFlag == nullptr))
	{
		successValue = 1;
	}

	return successValue;
}



// Returns 0 for general failure, -1 if the state is larger than the available phrases, and 1 for success.
int Item::display()
{
	int successValue = 0;

	if ((_itemName != nullptr) && (_lookPhrases != nullptr))
	{
		int i = 0;
		cout << "Item name: " << *_itemName << endl;
		cout << "Item ID: " << _itemID << endl;
		cout << "Item state: " << _itemState << endl;
		
		// https://www.cplusplus.com/reference/list/list/begin/
		// https://stackoverflow.com/questions/5733842/how-to-get-a-certain-element-in-a-list-given-the-position
		
		// If the size of the phrase lists can accommodate the requested item state
		if (unsigned(_itemState) < _lookPhrases->size())
		{
			cout << "Look command phrase for current state: " << getLookPhrase() << endl;
			cout << "Take command phrase for current state: " << getTakePhrase() << endl;
			
			/*
			// Set currentPhrase to the beginning of the _lookPhrases
			currentPhrase = Item::_lookPhrases->begin();

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

string Item::getItemName()
{
	return *_itemName;
}

string Item::getLookPhrase()
{
	return getStateValue(*_lookPhrases, _itemState);
}

string Item::getTakePhrase()
{
	return getStateValue(*_takePhrases, _itemState);
}

string Item::getStateValue(list<string>& aList, int& phraseState)
{
	list<string>::iterator	currentPhrase;
	string			statePhrase = "\n";

	if (unsigned(phraseState) < aList.size())
	{
		// Set currentPhrase to the beginning of the _lookPhrases
		currentPhrase = aList.begin();

		// Iterate to the desired location
		advance(currentPhrase, phraseState);

		// Display the look phrase for the item's current state
		statePhrase = *currentPhrase;
	}

	return statePhrase;
}


string Item::useItemWith(Door& aDoor)
{
	return aDoor.unlock(_itemID);
}

string Item::useItemWith(Item& anItem)
{
	// https://www.geeksforgeeks.org/nested-list-in-c-stl/

	int			successFlag = 0;
	int			i = 0;
	

	string			returnString = "You cannot use this item.";

	// If the size of the usable With list is greater than 0
	if (anItem._usableWithList->size() > 0)
	{
		list<list<tuple<string, int, int>>>::iterator nestedItr = _usableWithList->begin();

		while (nestedItr != _usableWithList->end())
		{
			list<tuple<string, int, int>>& singlePtr = *nestedItr;
			list<tuple<string, int, int>>::iterator singleItr = singlePtr.begin();

			while (singleItr != singlePtr.end())
			{
				cout << get<1>(*singleItr);
				++singleItr;
			}
			++nestedItr;
		}	
	}

	/*
	list<list<int>> test{ {1, 2, 3}, {1, 2, 3} };
	list<list<int>>::iterator nestedItr = test.begin();

	while (nestedItr != test.end())
	{
		list<int>& singlePtr = *nestedItr;
		list<int>::iterator singleItr = singlePtr.begin();

		while (singleItr != singlePtr.end())
		{
			cout << *singleItr;
			++singleItr;
		}
		++nestedItr;
	}
	*/



	/*
	string			returnString = "You cannot use this item.";

	// If the size of the usable With list is greater than 0
	if (anItem._usableWithList->size() > 0)
	{
		
		currentTuple = anItem._usableWithList->begin();
		int i = get<1>(currentTuple);
		while ((get<1>(*currentTuple) != anItem._usableWithID->end()) && (successFlag != 1))
		{
			++ID;
			++i;
		}
		// Check the _usableWith list
	}
	*/

	return returnString;
}