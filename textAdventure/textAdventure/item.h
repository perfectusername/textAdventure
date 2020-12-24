#include "utilities.h"

// Reference materials for lists
// https://www.techiedelight.com/initialize-std-list-cpp/
// https://thispointer.com/c-how-to-copy-clone-a-stl-list-or-sub-list/
// https://www.cplusplus.com/reference/list/list/

struct Item
{
public:
	Item();
	Item(string& itemName, int& itemID, int& itemState, list<string>& lookList, list<string>& takeList, list<string>& useList);
	~Item();

	int getItemID();

	string getLookPhrase();
	string getTakePhrase();
	string getUsePhrase();
	string getUsePhrase(int& phraseState);
	string getStatePhrase(list<string>& aList, int& phraseState);

	int display();

private:

	string*		_itemName;
	int		_itemID;
	int		_itemState;

	list<string>*	_lookList;	// List of look command outputs
	list<string>*	_takeList;	// List of take command outputs
	list<string>*	_useList;	// List of use command outputs

	int initialize(string& itemName, int& itemID, int& itemState, list<string>& lookList, list<string>& takeList, list<string>& useList);
	int deleteItem();
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