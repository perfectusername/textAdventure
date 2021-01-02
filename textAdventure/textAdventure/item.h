#include "inventory.h"

class Item
{
public:
	Item();
	Item(const Item& sourceItem);
	Item(const ItemCore& baseItemCore, 
			const Inventory& itemInventory);
	~Item();


private:

	ItemCore*	_baseItemCore;
	Inventory*	_itemInventory;

	int initialize(const ItemCore& baseItemCore,
			const Inventory& itemInventory);
	int deleteItem();
};