#include "room.h"

Door::Door()
{
	_doorID = 0;
	_destinationRoomID = 0;
	_locked = 0;
}

Door::Door(int& doorID, int& destinationRoomID, int& locked)
{
	_doorID = doorID;
	_destinationRoomID = destinationRoomID;
	_locked = locked;
}


// Returns 0 if unlocked, 1 if locked
int Door::isLocked()
{
	return _locked;
}

int Door::tryKey(int& keyID)
{
	int	successValue = 0;

	// If the door is not already unlocked
	if (_locked != 0)
	{
		// If the keyID matches the _doorID unlock the door
		if (keyID == _doorID)
		{
			_locked = 0;
			successValue = 1;
		}
	}
	// Otherwise the door is already unlocked
	else
	{
		successValue - 1;
	}

	return successValue;
}


int Door::openDoor()
{
	int	successValue = 0;

	if (_locked != 1)
	{
		// TRIGGERS A CHANGEROOM GAMEEVENT
		// DON'T FORGET TO IMPLEMENT THIS AT SOME POINT 
		// ONCE GAME EVENTS EXIST!!!!!
		successValue = 1;
	}

	return successValue;
}


/*
	Rooms will have:
		- GameEvents
		- Objects

*/