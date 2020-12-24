#include "item.h"

class Door
{
public:
	Door();
	Door(int& doorID, int& destinationRoomID, int& locked);

	//
	// Returns 0 if unlocked, 1 if locked
	int	isLocked();
	//
	// Returns 1 for success, -1 if door is not locked, and 0 if it is the wrong key (but it is locked)
	int	tryKey(int& keyID);
	//
	// Returns 0 if door cannot be opened, 1 if door successfully opens
	int	openDoor();

private:
	int	_doorID;		// ID number of this door. Will match the keyID.
	int	_destinationRoomID;	// _roomID of the room on the other side of the door
	int	_locked;		// Will be 0 if unlocked, 1 if locked

	// NOTE: Keys will just be regular Item objects
};


class Room
{
public:
	int addItemToRoom;
private:
	int		_roomID;
	string		_roomDescription;

	list<Item>*	_itemList;
	list<Door>*	_doorList;
	//GameEvent* _gameEventList;
};

/*
	Rooms contain:
		- objects
		- doors
		- events
		- npcs?
 
	Rooms offer a series of different gameEvents which can occur:

		- Game evenets are always triggerd by actions
			- When a character enters a certain grid coordinate
			- When a character picks up an item
			- On room entry
			- On room exit
			- Maybe even after a certain amount of time?
			- etc..

		Actions will always have text sequences, even if
		the text sequence gives you no interaction options.

		Will every text sequence be attached to an action?
		Yes.
*/