#include "inventory.h"

Inventory::Inventory()
{
	_inventory = nullptr;
}

Inventory::Inventory(const Inventory& anInventory)
{
	initialize(*anInventory._inventory);
}

Inventory::Inventory(const list<tuple<int, int>>& itemList)
{
	_inventory = nullptr;

	initialize(itemList);
}

Inventory::~Inventory()
{
	deleteInventory();
}

int Inventory::initialize(const list<tuple<int, int>>& itemList)
{
	int successValue = 0;

	if (_inventory != nullptr)
	{
		deleteInventory();
	}

	if (_inventory == nullptr)
	{
		_inventory = new list<tuple<int, int>>(itemList);
		_inventory->sort();
		successValue = 1;
	}

	return successValue;
}

int Inventory::deleteInventory()
{
	int successValue = 0;

	if (_inventory != nullptr)
	{
		_inventory->clear();
		delete _inventory;
	}

	if (_inventory == nullptr)
	{
		successValue = 1;
	}

	return successValue;
}

// Adds an item ID to the list. Returns 1 for success, 0 for failure.
int Inventory::addID(const tuple<int, int>& itemID)
{
	int				successValue = 0;
	list<tuple<int, int>>::iterator	inventoryItr;

	if (_inventory != nullptr)
	{
		inventoryItr = _inventory->begin();

		while (successValue != 1)
		{
			// If the itemID is already in this inventory
			if (get<0>(*inventoryItr) == get<0>(itemID))
			{
				// Increase the quantity by 1
				++get<1>(*inventoryItr);
				successValue = 1;
			}
			// If we are at the correct location insert ahead of the
			// current iterator
			else if (get<0>(*inventoryItr) < get<0>(itemID))
			{
				_inventory->insert(inventoryItr, itemID);
				successValue = 1;
			}
		}

	}
	// Otherwise the inventory is null so just initialize a new inventory
	// with the new information
	else
	{
		_inventory = new list<tuple<int, int>>{ itemID };
		successValue = 1;
	}

	return successValue;
}

// Returns 1 for success, 0 if list is empty, -1 if itemID is not on the list
int Inventory::removeSingle(const int& itemID)
{
	int			successValue = 0;
	list<tuple<int, int>>::iterator	inventoryItr;

	// Check if the list is empty
	if ((_inventory != nullptr) && (_inventory->size() > 0))
	{
		inventoryItr = _inventory->begin();

		// While the itemID at *inventoryItr is greater than itemID
		while ((successValue != -1) && (successValue != 1) && (inventoryItr != _inventory->end()))
		{
			if (get<0>(*inventoryItr) == itemID)
			{
				--get<1>(*inventoryItr);

				if (get<1>(*inventoryItr) == 0)
				{
					_inventory->erase(inventoryItr);
					successValue = 1;
				}
			}
			else if (get<0>(*inventoryItr) < itemID)
			{
				successValue = -1;
			}
			else
			{
				++inventoryItr;
			}
		}
		if (_inventory->size() <= 0)
		{
			deleteInventory();
		}
	}

	return successValue;
}

// Returns 1 for success, 0 if list is empty, -1 if itemID is not on the list
int Inventory::removeAll(const int& itemID)
{
	int			successValue = 0;
	list<tuple<int, int>>::iterator	inventoryItr;

	// Check if the list is empty
	if ((_inventory != nullptr) && (_inventory->size() > 0))
	{
		inventoryItr = _inventory->begin();

		while ((successValue != -1) && (successValue != 1) && (inventoryItr != _inventory->end()))
		{
			if (get<0>(*inventoryItr) == itemID)
			{
				_inventory->erase(inventoryItr);
				successValue = 1;
			}
			else if (get<0>(*inventoryItr) < itemID)
			{
				successValue = -1;
			}
			else
			{
				++inventoryItr;
			}
		}
		if (_inventory->size() <= 0)
		{
			deleteInventory();
		}
	}

	return successValue;
}

int Inventory::moveSingle(Inventory& sourceInventory, const int& itemID) 
{
	int successValue = 0;
	tuple<int, int>	newItemID;

	successValue = sourceInventory.removeSingle(itemID);

	if (successValue != 0)
	{
		newItemID = { itemID, 1 };
		successValue = addID(newItemID);
	}

	return successValue;
}

int Inventory::moveAll(Inventory& sourceInventory, const tuple<int, int>& itemID)
{
	int successValue = 0;

	successValue = sourceInventory.removeAll(get<0>(itemID));

	if (successValue != 0)
	{
		addID(itemID);
	}

	return successValue;
}

int Inventory::checkForID(const int& itemID) const
{
	int	successValue = 0;
	list<tuple<int, int>>::iterator	inventoryItr;

	if ((_inventory != nullptr) && (_inventory->size() > 0))
	{
		inventoryItr = _inventory->begin();
		while ((successValue != 1) && (successValue != -1) && (inventoryItr != _inventory->end()))
		{
			if (get<0>(*inventoryItr) == itemID)
			{
				successValue = 1;
			}
			else
			{
				++inventoryItr;
			}
		}
	}

	return successValue;
}

