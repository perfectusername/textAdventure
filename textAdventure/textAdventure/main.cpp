#include "room.h"

int main()
{
	//////////////////////////////////////////////////////////////////
	// Item testing


	/*
		Item: Key

		States:	0 - Normal
	*/

	string		itemNameBuffer = "Key";
	int		itemIDBuffer = 1;
	int		itemStateBuffer = 0;
	
	list<string>	lookPhrasesBuffer{ "You see a worn brass key with some etchings around the edge." };
	list<int>	lookFlagBuffer = { 1 };

	list<string>	takePhrasesBuffer{ "You take the key." };
	list<int>	takeFlagBuffer = { 1 };


	// Phrase, ID of usable item, usable state for that item state. 
	// IE: A chair can be used when it's not on fire, but not when it is on fire.
	
	list<list<tuple<string, int, int>>> usableWithListBuffer
	{
		{ // State 0 (normal)
			{
				// Item 0: (key)
				{
					"No, you can't use the key with itself" ,	// Phrase
					1,			// Item ID
					0			// Use flag
				},
				// Item 1: (the table itself)
				{
					"You put the key back onto the table.", //Phrase
					42069,					// Item ID
					1					// Use flag
				}
			}
		}
	};


	list<string>	searchPhrasesBuffer{ "You examine the markings on the key and see a row of elephants engraved along the outside edge." };
	list<int>	searchFlagBuffer{ 1 };
	list<Item>	itemsContainedBuffer{};

	list<string>	climbPhrasesBuffer{ "You put the key on the ground and stand on top of it for a while. Then you pick it back up." };
	list<int>	climbFlagBuffer{ 1 };

	list<string>	equipPhrasesBuffer{ "You can't equip the key. " };
	list<int>	equipFlagBuffer{ 0 };


	Item	key(itemNameBuffer,
		itemIDBuffer,
		itemStateBuffer,
		lookPhrasesBuffer,
		lookFlagBuffer,
		takePhrasesBuffer,
		takeFlagBuffer,
		usableWithListBuffer,
		searchPhrasesBuffer,
		searchFlagBuffer,
		itemsContainedBuffer,
		climbPhrasesBuffer,
		climbFlagBuffer,
		equipPhrasesBuffer,
		equipFlagBuffer);


	/*
		Item: Table
		
		States:	0 - Normal (drawer closed)
			1 - On fire
			2 - Pile of ashes
			3 - Normal (drawer open)
	*/

	itemNameBuffer = "Table";
	itemIDBuffer = 42069;
	itemStateBuffer = 0;


	lookPhrasesBuffer.clear();
	lookPhrasesBuffer = { "You see a small wooden table with a drawer.",
				"You see a table that is on fire.",
				"You see a pile of ashes that once was a table.",
				"You see a table with an open drawer." };
	lookFlagBuffer.clear();
	lookFlagBuffer = { 1, 1, 1, 1 };


	takePhrasesBuffer.clear();
	takePhrasesBuffer = { "The table is too large to take.",
				"You cannot take the table because it is too large, and it is also on fire.",
				"You try to pick up some of the ashes but they get all over you, and you have nothing to put them in, so you drop them back onto the ground.",
				"The table is too large to take." };
	takeFlagBuffer.clear();
	takeFlagBuffer = { 0, 0, 0, 0 };


	// Phrase, ID of usable item, usable state for that item state. 
	// IE: A chair can be used when it's not on fire, but not when it is on fire.
	usableWithListBuffer.clear();
	usableWithListBuffer = 
	{
		{ // State 0 (normal)
			{
				// Item 0: (key)
				{
					"You touch the key to the table" ,	// Phrase
					1,					// Item ID
					1					// Use flag
				},					
				// Item 1: (the table itself)
				{
					"You cannot use the table with itself.",//Phrase
					42069,					// Item ID
					0					// Use flag
				}
			}
		},
		{ // State 1 (on fire)
			{
				// Item 0: (key)
				{
					"You cannot get close enough to the table to touch the key to it because it is on fire.",	//Phrase
					1,	// Item ID
					0	// Use flag
				}, 
				// Item 1: (the table itself)
				{
					"It's on fire, so you definitely can't use the table, but even if you could, you cannot use the table with itself.",
					42069,	// Item ID
					0	// Use flag
				}
			}
		},
		{ // State 2 (pile of ashes)
			{
				// Item 0: (key)
				{
					"You touch the key to the pile of ashes.",	// Phrase
					1,						// Item ID
					1						// Use flag
				},
				// Item 1: (the table itself)
				{
					"You smush one part of the pile of ashes into another part of the pile of ashes.",	// Phrase
					42069,											// Item ID
					1											// Use flag
				}
			}
		},
		{ // State 3 (normal - drawer open)
			{
				// Item 0: (key)
				{
					"You touch the key to the table" ,	// Phrase
					1,					// Item ID
					1					// Use flag
				},
				// Item 1: (the table itself)
				{
					"You cannot use the table with itself.",//Phrase
					42069,					// Item ID
					0					// Use flag
				}
			}
		}
	};


	searchPhrasesBuffer.clear();
	searchPhrasesBuffer = { "You open the drawer and find a key.", 
				"You cannot search the drawer while the table is on fire.",
				"You search through the pile of hot ashes and find a key on the ground.",
				"The table contains only a drawer with a key. It is not a special table." };
	searchFlagBuffer.clear();
	searchFlagBuffer = { 1, 0, 1 , 1 };
	itemsContainedBuffer.clear();
	itemsContainedBuffer = { key };


	climbPhrasesBuffer.clear();
	climbPhrasesBuffer = { "You climb up onto the table and then you climb down.",
				"You can't climb on the table or you will catch fire."
				"You step on the pile of ashes and get soot all over your feet."
				"You climb up onto the table and then you climb down."};
	climbFlagBuffer.clear();
	climbFlagBuffer = { 1, 0, 1, 1 };


	equipPhrasesBuffer.clear();
	equipPhrasesBuffer = { "You cannot equip a table.", 
				"You cannot equip a burning table.",
				"You stick your hand in the ashes and swipe it across your face, making you look like a scary badass.",
				"You cannot equip a table." };
	equipFlagBuffer.clear();
	equipFlagBuffer = { 0, 0 , 1, 0 };


	Item	anItem(
		itemNameBuffer,
		itemIDBuffer,
		itemStateBuffer,
		lookPhrasesBuffer,
		lookFlagBuffer,
		takePhrasesBuffer,
		takeFlagBuffer,
		usableWithListBuffer,
		searchPhrasesBuffer,
		searchFlagBuffer,
		itemsContainedBuffer,
		climbPhrasesBuffer,
		climbFlagBuffer,
		equipPhrasesBuffer,
		equipFlagBuffer);

	anItem.display();


	//////////////////////////////////////////////////////////////////
	// Room testing

	
	/*
		Door

		States:	0 - Normal
			1 - On fire
			2 - Pile of ashes
	*/
	int	doorIDBuffer = 1;
	int	doorStateBuffer = 0;

	list<int>	destinationRoomIDBuffer{ 2, 0, 3 };
	list<int>	keyIDBuffer{ 1, 0, 0 };

	list<int>	lockedBuffer{ 1, 1, 0 };
	list<list<string>> openPhrasesBuffer{ { "You open the unlocked door and step through.",
						"You can't open the door because it's locked." },

						{ "The door is on fire and impassable.",
						"The door is on fire and impassable." },

						{"You step over the pile of ashes and step through the archway. \nHowever, the fire has weakened the floor and you fall through into a secret cavern." } };

	list<string>	unlockPhrasesBuffer{ "The door is already unlocked", 
						"You hear a click. The door is unlocked!!", 
						"This item does not fit the lock.",
						"The door is on fire and impassable." };

	lookPhrasesBuffer.clear();
	lookPhrasesBuffer = { "It's a normal wooden door.", 
				"It's a normal wooden door, but it's also on fire.", 
				"There is an open archway and a pile of ashes where the door once stood." };
	lookFlagBuffer = { 1 , 1 , 1 };

	Door	testDoor(
			doorIDBuffer,
			doorStateBuffer,
			destinationRoomIDBuffer,
			lockedBuffer,
			keyIDBuffer,
			openPhrasesBuffer,
			unlockPhrasesBuffer,
			lookPhrasesBuffer,
			lookFlagBuffer);

	string	doorTestValue;


	// Door testing
	/*
		Door

		States:	0 - Normal
			1 - On fire
			2 - Pile of ashes
	*/
	// Look
	cout << endl;
	cout << "STATE 0: (Normal)" << endl;
	cout << "===============" << endl;
	cout << "You look at the door:" << endl;
	cout << testDoor.getLookPhrase() << endl;
	//
	// Set state to 1 and look again
	doorStateBuffer = 1;
	testDoor.setStateValue(doorStateBuffer);
	cout << endl;
	cout << "STATE 1: (On fire)" << endl;
	cout << "==================" << endl;
	cout << "You look at the door:" << endl;
	cout << testDoor.getLookPhrase() << endl;
	//
	// Set state to 2 and look again
	doorStateBuffer = 2;
	testDoor.setStateValue(doorStateBuffer);
	cout << endl;
	cout << "STATE 2: (Pile of Ashes)" << endl;
	cout << "==================" << endl;
	cout << "You look at the door:" << endl;
	cout << testDoor.getLookPhrase() << endl;
	
	cout << endl;
	cout << endl;

	////////////////////////////////////////////////////////
	// Open Testing (default locked status)
	// set state to 0 and try to open it
	doorStateBuffer = 0;
	testDoor.setStateValue(doorStateBuffer);
	cout << endl;
	cout << "STATE 0: (Normal) (locked)" << endl;
	cout << "===============" << endl;
	cout << "You try to open the door:" << endl;
	cout << testDoor.openDoor() << endl;

	//
	// Set state to 1 and try again
	doorStateBuffer = 1;
	testDoor.setStateValue(doorStateBuffer);
	cout << endl;
	cout << "STATE 1: (On fire) (locked)" << endl;
	cout << "==================" << endl;
	cout << "You try to open the door:" << endl;
	cout << testDoor.openDoor() << endl;

	//
	// Set state to 2 and look again
	doorStateBuffer = 2;
	testDoor.setStateValue(doorStateBuffer);
	cout << endl;
	cout << "STATE 2: (Pile of Ashes) (locked)" << endl;
	cout << "==================" << endl;
	cout << "You try to open the door:" << endl;
	cout << testDoor.openDoor() << endl;

	//////////////////////////////////////////////
	// Open Testing (unlocked)
	// set state to 0 and try to open it
	doorStateBuffer = 0;
	testDoor.setToUnlocked();
	testDoor.setStateValue(doorStateBuffer);
	cout << endl;
	cout << "STATE 0: (Normal) (unlocked)" << endl;
	cout << "===============" << endl;
	cout << "You try to open the door:" << endl;
	cout << testDoor.openDoor() << endl;

	//
	// Set state to 1 and try again
	doorStateBuffer = 1;
	testDoor.setStateValue(doorStateBuffer);
	cout << endl;
	cout << "STATE 1: (On fire) (unlocked)" << endl;
	cout << "==================" << endl;
	cout << "You try to open the door:" << endl;
	cout << testDoor.openDoor() << endl;

	//
	// Set state to 2 and look again
	doorStateBuffer = 2;
	testDoor.setStateValue(doorStateBuffer);
	cout << endl;
	cout << "STATE 2: (Pile of Ashes) (unlocked)" << endl;
	cout << "==================" << endl;
	cout << "You try to open the door:" << endl;
	cout << testDoor.openDoor() << endl;

	/*
	// Unlock Testing

	Item* testKey;
	// Try to use the wrong key to unlock the door
	testKey = &anItem;
	cout << "You try to use a " << testKey->getItemName() << " on the door:" << endl;
	keyValue = testKey->getItemID();
	cout << testDoor.unlock(keyValue) << endl;
	cout << endl;

	// Try to use the right key to unlock the door
	testKey = &key;
	cout << "You try to use a " << testKey->getItemName() << " on the door:" << endl;
	keyValue = testKey->getItemID();
	cout << testDoor.unlock(keyValue) << endl;
	cout << endl;

	// Try to open the unlocked door
	cout << "You try to open the door:" << endl;
	cout << testDoor.openDoor() << endl;
	cout << endl;
	*/

	return 0;
}