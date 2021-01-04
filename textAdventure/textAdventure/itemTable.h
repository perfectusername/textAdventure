#include "item.h"

class ItemTable
{
public:
	// Return the item ID for a matching itemName
	int getItemID(const string& itemName);

	// Fills in details for a matching itemID, and returns 1 for success
	// OR returns 0 if the item is not in the inventory
	int getItem(const int& itemID, Item& returnItem);

	// Fills in details for a matching itemName, and returns 1 for success
	// OR returns 0 if the item is not in the inventory
	int getItem(const string& itemName, Item& returnItem);
private:
	Item*	_itemTable;
};