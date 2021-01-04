#include "inventory.h"

// Reference materials for lists
// https://www.techiedelight.com/initialize-std-list-cpp/
// https://thispointer.com/c-how-to-copy-clone-a-stl-list-or-sub-list/
// https://www.cplusplus.com/reference/list/list/

class Inventory;

class Item
{
public:
	Item();
	Item(const list<string>& itemName,
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
		const Inventory& inventory,
		const list<list<Item*>>& itemsContained,
		const list<string>& climbPhrases,
		const list<int>& climbFlag,
		const list<string>& equipPhrases,
		const list<int>& equipFlag);
	Item(const Item& anItem);
	~Item();

	void setItemState(int& newState);

	string getItemName();
	int getItemID();
	int getItemState();
	
	string getStatePhrase();
	string getLookPhrase();
	string getTakePhrase();
	
	string getSearchPhrase();
	string getClimbPhrase();
	string getEquipPhrase();
	string getListOfItemsContained();
	


	// Returns 0 if the item is not on the use list for this item state
	// Otherwise returns 1 and fills in the usePhrase with the appropriate success message
	// int getUsePhrase(int& itemID, string& usePhrase);

	//string useItemWith(Door& aDoor);
	//string useItemWith(Item& anItem, int& successValue);
	//string checkUseList(Item& anItem, int& successValue);
	
	int use(Item& withItem);

	int display();
	int copyItem(Item& sourceItem);

private:

	list<string>*	_itemName;
	int		_itemID;

	int		_itemState;
	list<string>*	_statePhrases;

	list<string>*	_lookPhrases;	// List of look command outputs
	list<int>*	_lookFlag;

	list<string>*	_takePhrases;	// List of take command outputs
	list<int>*	_takeFlag;

	list<list<int>>* _usableWithList;

	list<string>*	_searchPhrases;
	list<int>*	_searchFlag;
	Inventory*	_inventory;
	list<list<Item*>>*	_itemsContained;

	list<string>*	_climbPhrases;
	list<int>*	_climbFlag;

	list<string>*	_equipPhrases;
	list<int>*	_equipFlag;


	int initialize(const list<string>& itemName,
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
		const Inventory& inventory,
		const list<list<Item*>>& itemsContained,
		const list<string>& climbPhrases,
		const list<int>& climbFlag,
		const list<string>& equipPhrases,
		const list<int>& equipFlag);
	int initialize(const Item& anItem);
	int deleteItem();

	string getStateValue(list<string>& aList, int& phraseState);
	int getStateValue(list<int>& aList, int& listposition);

	int checkUseList(int& itemID);
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