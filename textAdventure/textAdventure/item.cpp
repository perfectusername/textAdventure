#include "item.h"


Item::Item()
{
	_baseItemCore = nullptr;
	_itemInventory = nullptr;
}

Item::Item(const Item& sourceItem)
{
	_baseItemCore = nullptr;
	_itemInventory = nullptr;

	initialize(*sourceItem._baseItemCore, *sourceItem._itemInventory);
}

Item::Item(const ItemCore& baseItemCore, 
				const Inventory& itemInventory)
{	
	_baseItemCore = nullptr;
	_itemInventory = nullptr;

	initialize(baseItemCore, itemInventory);
}

Item::~Item()
{
	deleteItem();
}

int Item::initialize(const ItemCore& baseItemCore,
				const Inventory& itemInventory)
{
	int	successValue = 0;

	successValue = deleteItem();

	if (successValue != 0)
	{
		_baseItemCore = new ItemCore(baseItemCore);
		_itemInventory = new Inventory(itemInventory);

		successValue = 1;
	}

	return successValue;
}

int Item::deleteItem()
{
	int successValue = 0;

	if (_baseItemCore != nullptr)
	{
		delete _baseItemCore;
		_baseItemCore = nullptr;
	}

	if (_itemInventory != nullptr)
	{
		delete _itemInventory;
		_itemInventory = nullptr;
	}

	if ((_baseItemCore == nullptr) &&
		(_itemInventory == nullptr))
	{
		successValue = 1;
	}

	return successValue;
}
