#include "room.h"

using namespace std;

int main()
{
	//////////////////////////////////////////////////////////////////
	// Item testing
	string		itemNameBuffer = "Test Item Name";
	int		itemIDBuffer = 42069;
	int		itemStateBuffer = 0;
	list<string>	lookListBuffer{ "Look phrase 1", "Look phrase 2" };
	list<string>	takeListBuffer{ "Take phrase 1", "Take phrase 2" };
	list<string>	useListBuffer{ "Use phrase 1", "Use phrase 2" };

	Item	anItem(itemNameBuffer, itemIDBuffer, itemStateBuffer, lookListBuffer, takeListBuffer, useListBuffer);

	anItem.display();

	//////////////////////////////////////////////////////////////////
	// Room testing

	// Test key
	itemNameBuffer = "Test Key";
	itemIDBuffer = 1;
	itemStateBuffer = 0;
	lookListBuffer.clear();
	lookListBuffer = { "It looks like a key" };
	takeListBuffer = { "You take the key" };
	useListBuffer = { "The key does not fit the keyhole", "You use the key to open the door" };
	
	Item	key(itemNameBuffer, itemIDBuffer, itemStateBuffer, lookListBuffer, takeListBuffer, useListBuffer);

	int	doorID = 1;
	int	destinationRoomID = 0;
	int	locked = 1;

	Door	testDoor(doorID, destinationRoomID, locked);

	int	doorTestValue;
	int	keyValue;

	// Try to open the locked door
	doorTestValue = 0;
	doorTestValue = testDoor.openDoor();
	cout << endl;
	if (doorTestValue != 0)
	{
		cout << "You've opened the door!!" << endl;
	}
	else
	{
		cout << "You failed to open the door :(" << endl;
	}

	// Check to see if the door is locked
	doorTestValue = 0;
	doorTestValue = testDoor.isLocked();
	cout << endl;
	if (doorTestValue != 0)
	{
		cout << "The door is locked" << endl;
	}
	else
	{
		cout << "The door is not locked" << endl;
	}

	// Try to use a key to unlock the door
	doorTestValue = 0;
	keyValue = key.getItemID();
	doorTestValue = testDoor.tryKey(keyValue);
	cout << endl;
	if (doorTestValue == 0)
	{
		cout << "This key does not fit the lock" << endl;
	}
	else if (doorTestValue == -1)
	{
		cout << "This door was already unlocked" << endl;
	}
	else if (doorTestValue == 1)
	{
		cout << "You hear a click. The door was successfully unlocked!!" << endl;
	}

	// Try to open the unlocked door
	doorTestValue = 0;
	doorTestValue = testDoor.openDoor();
	cout << endl;
	if (doorTestValue != 0)
	{
		cout << "You've opened the door!!" << endl;
	}
	else
	{
		cout << "You failed to open the door :(" << endl;
	}

	return 0;
}