#include "room.h"

void look(Door& aDoor);
void open(Door& aDoor);
void unlock(Door& aDoor, Item& aKey);


int main()
{
	//////////////////////////////////////////////////////////////////
	// Item testing


	/*
		Item: Key

		States:	0 - Normal
	*/

	string		itemNameBuffer = "key";
	int		itemIDBuffer = 1;

	// state phrases will finish the sentence "You cannot search the [item] while it is [state phrase]."
	// if the state phrase for that state is empty, then it will read: "You cannot search the [item]."
	list<string>	statePhrasesBuffer{ "" };
	int		itemStateBuffer = 0;
	
	list<string>	lookPhrasesBuffer{ "You see a worn brass key with some etchings around the edge." };
	list<int>	lookFlagBuffer = { 1 };

	list<string>	takePhrasesBuffer{ "You take the key." };
	list<int>	takeFlagBuffer = { 1 };


	// Phrase, ID of usable item, usable state for that item state. 
	// IE: A chair can be used when it's not on fire, but not when it is on fire.
	
	list<list<tuple<int, string>>> usableWithListBuffer
	{
		{ 
			// State 0 (normal)
			{
				// Item 0: (the table itself)
				{
					42069,	"You put the key back onto the table."
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
		statePhrasesBuffer,
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
	*/

	itemNameBuffer = "table";
	itemIDBuffer = 42069;

	statePhrasesBuffer.clear();
	statePhrasesBuffer = { "", "on fire", "a pile of ashes"};
	itemStateBuffer = 0;

	lookPhrasesBuffer.clear();
	lookPhrasesBuffer = { "You see a small wooden table with a drawer.",
				"You see a table that is on fire.",
				"You see a pile of ashes that once was a table."};
	lookFlagBuffer.clear();
	lookFlagBuffer = { 1, 1, 1};

	takePhrasesBuffer.clear();
	takePhrasesBuffer = { "The table is too large to take.",
				"You cannot take the table because it is too large, and it is also on fire.",
				"You try to pick up some of the ashes but they get all over you, and you have nothing to put them in, so you drop them back onto the ground."};
	takeFlagBuffer.clear();
	takeFlagBuffer = { 0, 0, 0 };


	// Phrase, ID of usable item, usable state for that item state. 
	// IE: A chair can be used when it's not on fire, but not when it is on fire.
	usableWithListBuffer.clear();
	usableWithListBuffer = 
	{
		{ // State 0 (normal)
			{
				// This item cannot be used with anything in its 0 state so tehre is nothing in this list
			}
		},
		{ // State 1 (on fire)
			{
				// Item 1: (the table itself)
				{
					42069, "It's on fire, so you definitely can't use the table, but even if you could, you cannot use the table with itself."
				}
			}
		},
		{ // State 2 (pile of ashes)
			{
				// Item 0: (key)
				{
					1, "You touch the key to the pile of ashes."
				},
				// Item 1: (the table itself)
				{
					42069, "You smush one part of the pile of ashes into another part of the pile of ashes."
				}
			}
		}
	};


	searchPhrasesBuffer.clear();
	searchPhrasesBuffer = { "You open and search the drawer", // Finish with either: ". You see [a key] in the drawer." or ", but the drawer is empty."
				"You cannot search the drawer while the table is on fire.",
				"You search through the pile of hot ashes." };
	searchFlagBuffer.clear();
	searchFlagBuffer = { 1, 0, 1 };
	itemsContainedBuffer.clear();
	itemsContainedBuffer = { key };


	climbPhrasesBuffer.clear();
	climbPhrasesBuffer = { "You climb up onto the table and then you climb down.",
				"You can't climb on the table or you will catch fire."
				"You step on the pile of ashes and get soot all over your feet." };
	climbFlagBuffer.clear();
	climbFlagBuffer = { 1, 0, 1, 1 };


	equipPhrasesBuffer.clear();
	equipPhrasesBuffer = { "You cannot equip a table.", 
				"You cannot equip a burning table.",
				"You stick your hand in the ashes and swipe it across your face, making you look like a scary badass." };
	equipFlagBuffer.clear();
	equipFlagBuffer = { 0, 0 , 1, 0 };


	Item	table(
		itemNameBuffer,
		itemIDBuffer,
		statePhrasesBuffer,
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

	table.display();


	//////////////////////////////////////////////////////////////////
	// Room testing

	
	/*
		Door

		States:	0 - Normal
			1 - On fire
			2 - Pile of ashes
	*/
	int		doorIDBuffer = 1;

	list<string>	doorStatePhrasesBuffer{ "", "on fire", "a pile of ashes" };
	int		doorStateBuffer = 0;

	list<int>	destinationRoomIDBuffer{ 2, 0, 3 };
	list<int>	keyIDBuffer{ 1, 0, 0 };

	list<int>	defaultLockedBuffer{ 1, 1, 0 };
	list<int>	unlockedValueBuffer{ 0, 0, 0 };
	list<list<string>> openPhrasesBuffer{ { "You open the unlocked door and step through.",
						"You can't open the door because it's locked." },

						{ "The door is on fire and impassable.",
						"The door is on fire and impassable." },

						{"You step over the pile of ashes and step through the archway. \nHowever, the fire has weakened the floor and you fall through into a secret cavern." } };

	list<string>	unlockPhrasesBuffer{ "The door isn't locked.", 
						"You hear a click. The door is unlocked!!", 
						"This item does not fit the lock.",
						"The door is on fire and impassable." };

	lookPhrasesBuffer.clear();
	lookPhrasesBuffer = { "It's a normal wooden door.", 
				"It's a normal wooden door, but it's also on fire.", 
				"There is an open archway and a pile of ashes where the door once stood." };
	lookFlagBuffer = { 1 , 1 , 1 };

	Door	testDoor(doorIDBuffer,
				doorStatePhrasesBuffer,
				doorStateBuffer,
				destinationRoomIDBuffer,
				defaultLockedBuffer,
				unlockedValueBuffer,
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

	cout << endl;
	cout << "//////////////////////////////////" << endl;
	cout << "DOOR: LOOK" << endl << endl;
	//
	look(testDoor);
	cout << endl;
	//
	// Set state to 1 and look again
	doorStateBuffer = 1;
	testDoor.setStateValue(doorStateBuffer);
	look(testDoor);
	cout << endl;
	//
	// Set state to 2 and look again
	doorStateBuffer = 2;
	testDoor.setStateValue(doorStateBuffer);
	look(testDoor);
	cout << endl;


	cout << endl;
	cout << "//////////////////////////////////" << endl;
	cout << "DOOR: OPEN (DEFAULT STATE)" << endl << endl;;
	////////////////////////////////////////////////////////
	// Open Testing (default defaultLocked status)
	// set state to 0 and try to open it
	doorStateBuffer = 0;
	testDoor.setStateValue(doorStateBuffer);
	open(testDoor);
	cout << endl;
	//
	// Set state to 1 and try again
	doorStateBuffer = 1;
	testDoor.setStateValue(doorStateBuffer);
	open(testDoor);
	cout << endl;
	//
	// Set state to 2 and look again
	doorStateBuffer = 2;
	testDoor.setStateValue(doorStateBuffer);
	open(testDoor);
	cout << endl;


	cout << endl;
	cout << "//////////////////////////////////" << endl;
	cout << "DOOR: OPEN (UNLOCKED)" << endl << endl;
	//////////////////////////////////////////////
	// Open Testing (unlocked)
	// set state to 0 and try to open it
	doorStateBuffer = 0;
	testDoor.setToUnlocked();
	testDoor.setStateValue(doorStateBuffer);
	open(testDoor);
	cout << endl;
	//
	// Set state to 1 and try again
	doorStateBuffer = 1;
	testDoor.setStateValue(doorStateBuffer);
	open(testDoor);
	cout << endl;
	//
	// Set state to 2 and look again
	doorStateBuffer = 2;
	testDoor.setStateValue(doorStateBuffer);
	open(testDoor);
	cout << endl;


	///////////// Unlock Testing
	// WRONG key
	cout << endl;
	cout << "//////////////////////////////////" << endl;
	cout << "DOOR: UNLOCK (WRONG KEY)" << endl << endl;
	
	doorStateBuffer = 0;
	testDoor.setStateValue(doorStateBuffer);
	testDoor.setLockedToDefault();
	unlock(testDoor, table);
	cout << endl;

	doorStateBuffer = 1;
	testDoor.setStateValue(doorStateBuffer);
	testDoor.setLockedToDefault();
	unlock(testDoor, table);
	cout << endl;

	doorStateBuffer = 2;
	testDoor.setStateValue(doorStateBuffer);
	testDoor.setLockedToDefault();
	unlock(testDoor, table);
	cout << endl;



	// RIGHT key
	cout << endl;
	cout << "//////////////////////////////////" << endl;
	cout << "DOOR: UNLOCK (RIGHT KEY)" << endl;

	doorStateBuffer = 0;
	testDoor.setStateValue(doorStateBuffer);
	testDoor.setLockedToDefault();
	unlock(testDoor, key);
	cout << endl;

	doorStateBuffer = 1;
	testDoor.setStateValue(doorStateBuffer);
	testDoor.setLockedToDefault();
	unlock(testDoor, key);
	cout << endl;

	doorStateBuffer = 2;
	testDoor.setStateValue(doorStateBuffer);
	testDoor.setLockedToDefault();
	unlock(testDoor, key);
	cout << endl;


	////////////////////////////////////////////////////
	// Item testing
	cout << endl;
	cout << "//////////////////////////////////" << endl;
	cout << "ITEM: SEARCH" << endl;


	///////////// 




	
	return 0;
}



void look(Door& aDoor)
{
	string	statePhrase = aDoor.getStatePhrase();

	cout << "STATE " << aDoor.getDoorState() << ":";

	if (statePhrase != "")
	{
		cout << " (" << statePhrase << ")" << endl;
	}
	else
	{
		cout << endl;
	}

	cout << "===============" << endl;
	cout << "You look at the door: ";
	cout << aDoor.getLookPhrase() << endl;
}

void open(Door& aDoor)
{
	string	statePhrase = aDoor.getStatePhrase();

	cout << "STATE " << aDoor.getDoorState() << ":";

	if (statePhrase != "")
	{
		cout << " (" << statePhrase << ")" << endl;
	}
	else
	{
		cout << endl;
	}

	cout << "===============" << endl;
	cout << "You try to open the door: ";
	cout << aDoor.openDoor() << endl;
}

void unlock(Door& aDoor, Item& aKey)
{
	int	keyID = aKey.getItemID();
	string	statePhrase = aDoor.getStatePhrase();

	cout << "STATE " << aDoor.getDoorState() << ":";

	if (statePhrase != "")
	{
		cout << " (" << statePhrase << ")" << endl;
	}
	else
	{
		cout << endl;
	}

	cout << "==================" << endl;
	cout << "You try to unlock the door with a " << aKey.getItemName() << ". ";
	cout << aDoor.unlock(keyID) << endl;
}