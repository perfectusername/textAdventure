#include "item.h"



Item::Item()
{
	_itemName = nullptr;
	_itemID = 0;

	_statePhrases = nullptr;
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

Item::Item(const list<string>& itemName,
	const int& itemID,
	const list<string>& statePhrases,
	const int& itemState,
	const list<string>& lookPhrases,
	const list<int>& lookFlag,
	const list<string>& takePhrases,
	const list<int>& takeFlag,
	const list<list<int>>& usableWithList,
	const list<string>& searchPhrases,
	const list<int>& searchFlag,
	const list<Item*>& itemsContained,
	const list<string>& climbPhrases,
	const list<int>& climbFlag,
	const list<string>& equipPhrases,
	const list<int>& equipFlag)
{
	_itemName = nullptr;
	_statePhrases = nullptr;

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
		statePhrases,
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
	_statePhrases = nullptr;

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
		*anItem._statePhrases,
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
int Item::initialize(const list<string>& itemName,
	const int& itemID,
	const list<string>& statePhrases,
	const int& itemState,
	const list<string>& lookPhrases,
	const list<int>& lookFlag,
	const list<string>& takePhrases,
	const list<int>& takeFlag,
	const list<list<int>>& usableWithList,
	const list<string>& searchPhrases,
	const list<int>& searchFlag,
	const list<Item*>& itemsContained,
	const list<string>& climbPhrases,
	const list<int>& climbFlag,
	const list<string>& equipPhrases,
	const list<int>& equipFlag)
{
	int successValue = 0;

	successValue = deleteItem();

	if (successValue != 0)
	{
		_itemName = new list<string>(itemName);
		*_itemName = itemName;

		_itemID = itemID;

		_statePhrases = new list<string>(statePhrases);
		_itemState = itemState;

		// Use the list copy constructor to clone the incoming lists
		_lookPhrases = new list<string>(lookPhrases);
		_lookFlag = new list<int>(lookFlag);

		_takePhrases = new list<string>(takePhrases);
		_takeFlag = new list<int>(takeFlag);

		_usableWithList = new list<list<int>>(usableWithList);

		_searchPhrases = new list<string>(searchPhrases);
		_searchFlag = new list<int>(searchFlag);
		_itemsContained = new list<Item*>(itemsContained);

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

	deleteList(_itemName);
	_itemID = 0;
	_itemState = 0;
	deleteList(_statePhrases);

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
		(_statePhrases == nullptr) &&
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
		cout << "Item name: " << getItemName() << endl;
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

void Item::setItemState(int& newState)
{
	_itemState = newState;
}

int Item::getItemID()
{
	return _itemID;
}

int Item::getItemState()
{
	return _itemState;
}

string Item::getStatePhrase()
{
	return getStateValue(*_statePhrases, _itemState);
}

string Item::getItemName()
{
	return getStateValue(*_itemName, _itemState);
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

// Returns the state value (which should always be >= 0) for success
// Returns -1 for failure if the position requested is too high for the list size
int Item::getStateValue(list<int>& aList, int& listposition)
{
	list<int>::iterator	currentInt;
	int			returnValue = -1;

	if (unsigned(listposition) < aList.size())
	{
		// Set currentPhrase to the beginning of the _lookPhrases
		currentInt = aList.begin();

		// Iterate to the desired location
		advance(currentInt, listposition);

		// Display the look phrase for the item's current state
		returnValue = *currentInt;
	}

	return returnValue;
}


/*
// Returns 1 for success, 0 for failure
int Item::getUsePhrase(int& itemID, string& usePhrase)
{
	int successValue = 0;

	// If the _usableWithList isn't null and it has more than 0 entries in it
	if ((_usableWithList != nullptr) && (_usableWithList->size() > 0))
	{
		// Outer list iterator (the list of lists)
		list<list<tuple<int, string>>>::iterator outerItr = _usableWithList->begin();

		// While the outer list hasn't ended
		// AND we haven't already found our match.
		while ((outerItr != _usableWithList->end()) && (successValue != 1))
		{
			// Create an iterator for the inner list
			list<tuple<int, string>>& singlePtr = *outerItr;
			list<tuple<int, string>>::iterator innerItr = singlePtr.begin();

			// Cycle through the inner list until:
			// We haven't reached the end of the inner list
			// AND we haven't found our matching item.
			while ((innerItr != singlePtr.end()) && (successValue != 1))
			{
				// If the item ID matches
				if (get<0>(*innerItr) == itemID)
				{
					// Copy the item's use string into usePhrase and set success to 1
					usePhrase = get<1>(*innerItr);
					successValue = 1;
				}
				// Otherwise the item ID doesn't match
				// And we aren't at the end, so iterate the inner list
				else
				{
					++innerItr;
				}
			}
			++outerItr;
		}
	}

	return successValue;
}
*/

string Item::getSearchPhrase()
{
	int	searchFlagValue = getStateValue(*_searchFlag, _itemState);
	string	returnString = "";
	string	stateString = "";

	// First check to see if the item is searchable.
	if (searchFlagValue != 0)
	{
		// List must not be null 
		// AND must not be empty
		if ((_itemsContained != nullptr) && (_itemsContained->size() > 0))
		{
			returnString = "You search the " + getItemName() + " and find that it contains " + getListOfItemsContained() + ".";
		}
		else
		{
			returnString = "You search the " + getItemName() + ", but it's empty.";
		}
	}
	else
	{
		returnString += "You cannot search the " + getItemName();
		stateString = getStatePhrase();

		if (stateString != "")
		{
			returnString += " because it is " + stateString + ".";
		}
		else
		{
			returnString += ".";
		}
	}

	return returnString;
}

string Item::getListOfItemsContained()
{
	string	returnString = "";
	int	itemsContainedSize;
	int	i;

	if ((_itemsContained != nullptr) && (_itemsContained->size() > 0))
	{
		itemsContainedSize = _itemsContained->size();

		// Create an iterator for the _itemsContained list
		list<Item*>::iterator itemsContainedItr = _itemsContained->begin();

		// If there is only 1 item in the _itemsContained list
		if (itemsContainedSize == 1)
		{
			returnString += addAOrAn((*itemsContainedItr)->getItemName());
		}
		// If there are only 2 words in the _itemsContained list
		else if (itemsContainedSize == 2)
		{
			returnString += addAOrAn((*itemsContainedItr)->getItemName());
			returnString += " and ";
			++itemsContainedItr;
			returnString += addAOrAn((*itemsContainedItr)->getItemName());
		}
		// Otherwise, there are 3 or more words in the _itemsContained list
		else
		{
			i = 0;
			while (i < (itemsContainedSize - 1))
			{
				returnString += addAOrAn((*itemsContainedItr)->getItemName());
				returnString += ", ";
				++itemsContainedItr;
				++i;
			}
			returnString += "and ";
			returnString += addAOrAn((*itemsContainedItr)->getItemName());
		}
	}

	return returnString;
}

string Item::getClimbPhrase()
{
	return "";
}

string Item::getEquipPhrase()
{
	return "";
}

/*
string Item::useItemWith(Door& aDoor)
{
	return aDoor.unlock(_itemID);
}
*/

/*
string Item::useItemWith(Item& anItem, int& successValue)
{
	// https://www.geeksforgeeks.org/nested-list-in-c-stl/

	successValue = 0;
	int	i = 0;
	
	string	returnString = "";
	string	stateStringBuffer = "";
	string	firstBuffer = "";
	string	secondBuffer = "";

	// Check the first list to see if the object is on it
	firstBuffer = this->checkUseList(anItem, successValue);
	
	// If the object *was* on the first list, then it also has to be on the second list
	if (successValue == 1)
	{
		secondBuffer = anItem.checkUseList(*this, successValue);

		// successValue should be 1 right now if the items are on each others lists
		// in their current states.
		if (successValue == 1)
		{
			// Build the return string
			// If neither buffer has any return phrase
			if ((firstBuffer == "") && (secondBuffer == ""))
			{
				returnString = "You use the " + this->getItemName();
				returnString += " with the " + anItem.getItemName() + ".";
			}
			// If only the firstBuffer has a return phrase
			else if ((firstBuffer != "") && (secondBuffer == ""))
			{
				returnString = firstBuffer;
			}
			// The only other two options left are:
			//
			// 1. Only the secondBuffer has a return phrase: ((firstBuffer == "") && (secondBuffer != ""))
			// and
			// 2. Both buffers have a return phrase: ((firstBuffer != "") && (secondBuffer != ""))
			//
			// In both cases we are just going to go with the secondBuffer,
			// so we only need an "else" here.
			else
			{
				returnString = secondBuffer;
			}
		}
	}

	// If the successValue is not 1 at this point you can't use the items together
	// in this state.
	if (successValue != 1)
	{
		returnString = "You can't use the " + this->getItemName();
		returnString += " with the " + anItem.getItemName() + " right now.";
	}

	return returnString;
}
*/

int Item::use(Item& withItem)
{
	int successValue = 0;
	int itemID;
	
	itemID = withItem.getItemID();
	successValue = this->checkUseList(itemID);

	if (successValue == 1)
	{
		itemID = this->getItemID();
		successValue = withItem.checkUseList(itemID);
	}

	return successValue;
}

int Item::checkUseList(int& itemID)
{
	int successValue = 0;
	int	i = 0;

	

	// If the size of the usable With list is greater than 0
	if ((_usableWithList != nullptr) && (_usableWithList->size() > 0))
	{
		list<list<int>>::iterator nestedItr = _usableWithList->begin();
		list<int> singlePtr;
		list<int>::iterator singleItr;

		// Iterate to the correct state
		while ((nestedItr != _usableWithList->end()) && (successValue != 1) && (i <= _itemState))
		{
			singlePtr = *nestedItr;
			singleItr = singlePtr.begin();
			++nestedItr;
			++i;
		}
		// Then iterate to the correct phrase
		while ((singleItr != singlePtr.end()) && (successValue != 1))
		{
			if (*singleItr != itemID)
			{
				++singleItr;
			}
			else
			{
				successValue = 1;
			}
		}
	}

	return successValue;
}
/*
string Item::checkUseList(Item& anItem, int& successValue)
{
	int	i = 0;
	int	itemID = 0;
	string	returnString = "";

	successValue = 0;

	// If the size of the usable With list is greater than 0
	if ((_usableWithList != nullptr) && (_usableWithList->size() > 0))
	{
		list<list<tuple<int, string>>>::iterator nestedItr = _usableWithList->begin();
		list<tuple<int, string>> singlePtr;
		list<tuple<int, string>>::iterator singleItr;

		// Iterate to the correct state
		while ((nestedItr != _usableWithList->end()) && (successValue != 1) && (i <= _itemState))
		{
			singlePtr = *nestedItr;
			singleItr = singlePtr.begin();
			++nestedItr;
			++i;
		}
		// Then iterate to the correct phrase
		while ((singleItr != singlePtr.end()) && (successValue != 1))
		{
			if (get<0>(*singleItr) != anItem.getItemID())
			{
				++singleItr;
			}
			else
			{
				returnString = get<1>(*singleItr);
				successValue = 1;
			}
		}
	}

	return returnString;
}
*/