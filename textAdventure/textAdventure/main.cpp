#include "item.h"

using namespace std;

int main()
{
	string		itemName = "Test Item Name";
	int		itemID = 42069;
	list<string>	phraseList{ "Phrase 1", "Phrase 2", "Phrase 3" };

	Item		anItem(itemName, itemID, phraseList);



	return 0;
}