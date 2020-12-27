#include "item.h"




class Room
{
public:

private:
	int		_roomID;
	string		_roomDescription;

	list<Item>*	_itemList;
	list<Door>*	_doorList;
	//GameEvent* _gameEventList;
};

/*
	Rooms contain:
		- Items
		- Doors
		- GameEvents
		- NPC?
 
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