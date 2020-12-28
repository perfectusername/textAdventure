#include "door.h"


Door::Door()
{
	_doorID = 0;
	_doorState = 0;

	_destinationRoomID = nullptr;
	_defaultLocked = nullptr;
	_unlockedValue = nullptr;
	_lockedPointer = nullptr;
	_keyID = nullptr;

	_openPhrases = nullptr;
	_unlockPhrases = nullptr;
	_lookPhrases = nullptr;
	_lookFlag = nullptr;
}

Door::Door(
	const int& doorID,
	const int& doorState,
	const list<int>& destinationRoomID,
	const list<int>& defaultLocked,
	const list<int>& unlockedValue,
	const list<int>& keyID,
	const list<list<string>>& openPhrases,
	const list<string>& unlockPhrases,
	const list<string>& lookPhrases,
	const list<int>& lookFlag)
{
	_destinationRoomID = nullptr;
	_defaultLocked = nullptr;
	_unlockedValue = nullptr;
	_lockedPointer = nullptr;
	_keyID = nullptr;

	_openPhrases = nullptr;
	_unlockPhrases = nullptr;
	_lookPhrases = nullptr;
	_lookFlag = nullptr;

	initialize(doorID, 
		doorState,
		destinationRoomID,
		defaultLocked,
		unlockedValue,
		keyID,
		openPhrases,
		unlockPhrases,
		lookPhrases,
		lookFlag);
}

Door::~Door()
{
	deleteDoor();
}

int Door::initialize(
	const int& doorID,
	const int& doorState,
	const list<int>& destinationRoomID,
	const list<int>& defaultLocked,
	const list<int>& unlockedValue,
	const list<int>& keyID,
	const list<list<string>>& openPhrases,
	const list<string>& unlockPhrases,
	const list<string>& lookPhrases,
	const list<int>& lookFlag)
{
	int successValue = 0;

	successValue = deleteDoor();

	if (successValue != 0)
	{
		_doorID = doorID;
		_doorState = doorState;

		// Use the list copy constructor to clone the incoming lists
		_destinationRoomID = new list<int>(destinationRoomID);
		_defaultLocked = new list<int>(defaultLocked);
		_unlockedValue = new list<int>(unlockedValue);
		_lockedPointer = &_defaultLocked;
		_keyID = new list<int>(keyID);

		_openPhrases = new list<list<string>>(openPhrases);
		_unlockPhrases = new list<string>(unlockPhrases);
		_lookPhrases = new list<string>(lookPhrases);
		_lookFlag = new list<int>(lookFlag);

		successValue = 1;
	}

	return successValue;
}


// Deallocate the contents of an Item object
int Door::deleteDoor()
{
	int successValue = 0;

	_doorID = 0;
	_destinationRoomID = 0;
	_defaultLocked = 0;
	_keyID = 0;
	_doorState = 0;

	deleteList(_destinationRoomID);
	deleteList(_defaultLocked);
	deleteList(_unlockedValue);
	_lockedPointer = nullptr;
	deleteList(_keyID);
	deleteList(_openPhrases);
	deleteList(_unlockPhrases);
	deleteList(_lookPhrases);
	deleteList(_lookFlag);


	// If all pointers are null then return success
	if ((_destinationRoomID == nullptr) &&
		(_defaultLocked == nullptr) &&
		(_keyID == nullptr) &&
		(_openPhrases == nullptr) &&
		(_unlockPhrases == nullptr) &&
		(_lookPhrases == nullptr) &&
		(_lookFlag == nullptr))
	{
		successValue = 1;
	}

	return successValue;
}

// Get _destination room ID for current _doorState
int Door::getDestinationRoomID()
{
	return(getStateValue(*_destinationRoomID, _doorState));
}

// Get _defaultLocked status for curent _doorState
int Door::getLockedValue()
{
	int lockedValue = getStateValue(**_lockedPointer, _doorState);
	return(lockedValue);
}

// Get _keyID status for current _doorState
int Door::getKeyID()
{
	return(getStateValue(*_keyID, _doorState));
}


// Returns:
//	0 if door is already undefaultLocked
//	1 if the door was successfully undefaultLocked
//	2 if the key does not open the door
//	3 if the door is currently unlockable
string Door::unlock(int& keyID)
{
	int	successValue = 0;
	string	returnString;

	// If the door is not already undefaultLocked successValue = 0
	if (getLockedValue() == 1)
	{
		//If the door is currently impassable (not unlockable)
		// then the _keyValue will be 0 and the _defaultLocked value will be 1
		if (getKeyID() == 0)
		{
			successValue = 3;
		}
		else
		{
			// If the keyID matches the _keyID for the current door state, 
			// then unlock the door
			if (keyID == getKeyID())
			{
				setToUnlocked();
				successValue = 1; 
			}
			// Otherwise the keyID does not match the _keyID
			else
			{
				successValue = 2;
			}
		}
	}

	return getUnlockPhrase(successValue);
}

	

void Door::setToUnlocked()
{
	_lockedPointer = &_unlockedValue;
}
//
void Door::setLockedToDefault()
{
	_lockedPointer = &_defaultLocked;
}
string Door::openDoor()
{
	int defaultLockedValue = getLockedValue();
	return getOpenPhrase(defaultLockedValue);
}

string Door::getLookPhrase()
{
	return getStateValue(*_lookPhrases, _doorState);
}

string Door::getOpenPhrase(int& openSuccessValue)
{
	int	i = 0;
	int	n = 0;
	int	defaultLockedValue = getLockedValue();
	string	returnString;
	list<list<string>>::iterator nestedItr = _openPhrases->begin();



	while (n < _doorState)
	{
		++nestedItr;
		++n;
	}
	list<string>& singlePtr = *nestedItr;
	list<string>::iterator singleItr = singlePtr.begin();


	while (i < defaultLockedValue)
	{
		++singleItr;
		++i;
	}

	return *singleItr;
}

string Door::getUnlockPhrase(int& lockSuccessValue)
{
	return getStateValue(*_unlockPhrases, lockSuccessValue);
}


void Door::setStateValue(int& stateValue)
{
	_doorState = stateValue;
}

string Door::getStateValue(list<string>& aList, int& phraseState)
{
	list<string>::iterator	currentPhrase;
	string			statePhrase = "\n";

	if (unsigned(phraseState) < aList.size())
	{
		// Set currentPhrase to the beginning of the list
		currentPhrase = aList.begin();

		// Iterate to the desired location
		advance(currentPhrase, phraseState);

		// Display the look phrase for the item's current state
		statePhrase = *currentPhrase;
	}

	return statePhrase;
}

// Returns the int at the argument position in the argument list
// OR returns -1 for failure
int Door::getStateValue(list<int>& aList, int& phraseState)
{
	list<int>::iterator	currentPhrase;
	int			statePhrase = -1;

	if (unsigned(phraseState) < aList.size())
	{
		// Set currentPhrase to the beginning of the list
		currentPhrase = aList.begin();

		// Iterate to the desired location
		advance(currentPhrase, phraseState);

		// Display the look phrase for the item's current state
		statePhrase = *currentPhrase;
	}

	return statePhrase;
}