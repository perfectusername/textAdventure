#include "door.h"

// Reference materials for lists
// https://www.techiedelight.com/initialize-std-list-cpp/
// https://thispointer.com/c-how-to-copy-clone-a-stl-list-or-sub-list/
// https://www.cplusplus.com/reference/list/list/




class Item
{
public:
	Item();
	Item(const string& itemName,
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
		const list<int>& equipFlag);
	Item(const Item& anItem);
	~Item();

	int getItemID();
	string getItemName();

	string getLookPhrase();
	string getTakePhrase();
	
	string useItemWith(Door& aDoor);
	string useItemWith(Item& anItem);

	int display();

private:

	string*		_itemName;
	int		_itemID;
	int		_itemState;

	list<string>*	_lookPhrases;	// List of look command outputs
	list<int>*	_lookFlag;

	list<string>*	_takePhrases;	// List of take command outputs
	list<int>*	_takeFlag;

	list<list<tuple<string, int, int>>>* _usableWithList;

	list<string>*	_searchPhrases;
	list<int>*	_searchFlag;
	list<Item>*	_itemsContained;

	list<string>*	_climbPhrases;
	list<int>*	_climbFlag;

	list<string>*	_equipPhrases;
	list<int>*	_equipFlag;

	

	int initialize(
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
		const list<int>& equipFlag);
	int deleteItem();

	string getStateValue(list<string>& aList, int& phraseState);

	// Flags

};

/*
	Rooms can have Text Sequences occur:

		- Attached to actions
			- When a character enters a certain grid coordinate
			- When a character picks up an item
			- On room entry
			- On room exit
			- etc..

		Actions will always have text sequences, even if
		the text sequence gives you no interaction options.

		Will every text sequence be attached to an action?
		Yes.
*/