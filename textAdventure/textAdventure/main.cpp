#include "item.h"

using namespace std;

int main()
{
	string		itemName = "Test Item Name";
	int		itemID = 42069;
	int		itemState = 2;
	list<string>	lookList{ "Look phrase 1", "Look phrase 2" };
	list<string>	takeList{ "Take phrase 1", "Take phrase 2" };
	list<string>	useList{ "Use phrase 1", "Use phrase 2" };

	Item		anItem(itemName, itemID, itemState, lookList, takeList, useList);

	anItem.display();

	return 0;
}