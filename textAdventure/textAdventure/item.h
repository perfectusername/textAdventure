/*
	Items will have:

	- A name
	- A list of words and phrases they can be associated with
	- Other things later...
*/

#include "utilities.h"


struct Item
{
public:

private:
	string		_itemName;
	string*		_associatedPhrases;	// A pointer to an array of associated phrases
};