#include "utilities.h"

// Reference materials for lists
// https://www.techiedelight.com/initialize-std-list-cpp/
// https://thispointer.com/c-how-to-copy-clone-a-stl-list-or-sub-list/
// https://www.cplusplus.com/reference/list/list/

struct Item
{
public:
	Item();
	Item(string& itemName, int& itemID, list<string>& phraseList);
	~Item();

private:

	string*		_itemName;
	int		_itemID;
	list<string>*	_phraseList;	// List of phrases
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