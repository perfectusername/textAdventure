#include "door.h"

class Item;

class Inventory
{
public:
	Inventory();
	Inventory(const Inventory& anInventory);
	Inventory(const list<tuple<int, int>>& itemList);
	~Inventory();

	int addID(const tuple<int, int>& itemID);
	int removeSingle(const int& itemID);
	int removeAll(const int& itemID);
	// Removes item from source inventory and adds to calling inventory
	int moveSingle(Inventory& sourceInventory, const int& itemID);
	int moveAll(Inventory& sourceInventory, const tuple<int, int>& itemID);
	int checkForID(const int& itemID) const;

private:
	list<tuple<int, int>>*	_inventory; // itemID, qty

	int initialize(const list<tuple<int, int>>& itemIDlists);
	int deleteInventory();

	
}; 