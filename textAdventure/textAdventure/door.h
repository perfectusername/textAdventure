#include "utilities.h"



class Door
{
public:
	Door();
	Door(const int& doorID,
		const int& doorState,
		const list<int>& destinationRoomID,
		const list<int>& locked,
		const list<int>& keyID,
		const list<string>& openPhrases,
		const list<string>& unlockPhrases,
		const list<string>& lookPhrases,
		const list<int>& lookFlag);
	~Door();

	// LOCKING AND OPENING
	//
	// Returns: 0 if door is already unlocked, 1 if successfully unlocked, 2 if the key does not fit
	string unlock(int& keyID);
	//
	// Returns 0 if door cannot be opened, 1 if door successfully opens
	string openDoor();
	//
	string getLookPhrase();


private:
	int		_doorID;		// ID number of this door. Will match the keyID.
	int		_doorState;		// Similar to item state
	
	list<int>*	_destinationRoomID;	// _roomID of the room on the other side of the door
	list<int>*	_locked;		// Locked status: 0 if unlocked, 1 if locked
	list<int>*	_keyID;			// _itemID of teh key to the door, if any. If not lockable, _keyID = 0.
	list<string>*	_openPhrases;		// List of use command outputs
	list<string>*	_unlockPhrases;		// List of unlock command outputs

	list<string>*	_lookPhrases;	// List of look command outputs
	list<int>*	_lookFlag;

	
	

	int initialize(
		const int& doorID,
		const int& doorState,
		const list<int>& destinationRoomID,
		const list<int>& locked,
		const list<int>& keyID,
		const list<string>& openPhrases,
		const list<string>& unlockPhrases,
		const list<string>& lookPhrases,
		const list<int>& lookFlag);
	int deleteDoor();

	int setToUnlocked();

	// GET PHRASES
	//
	int getDestinationRoomID();
	int getLockedValue();
	int getKeyID();

	// Returns the string at the argument position within _unlockPhrases: 
	// 0 if door is already unlocked, 1 if successfully unlocked, 2 if the key does not fit
	string getUnlockPhrase(int& lockSuccessValue);
	//
	// Returns 
	// 0 if door cannot be opened, 1 if door successfully opens
	string getOpenPhrase(int& openSuccessValue);
	//
	// Returns the phrase at the numerical position in the list 
	// OR, if that phrase doesn't exist, it returns a single null character
	string getStateValue(list<string>& aList, int& phraseState);
	int getStateValue(list<int>& aList, int& phraseState);

	// NOTE: Keys will just be regular Item objects. The _itemID will match the _doorID that it opens
	//	 There will be more items than doors, so the _itemID should have its ID picked first
	//	 then the _doorID will be copied from it.
};