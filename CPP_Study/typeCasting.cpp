#include <iostream>
using namespace std;

class Knight
{
public:
	int _hp = 100;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(const Item& item) {
		cout << "Item(const item&)" << endl;
	}

	~Item()
	{
		cout << "~Item()" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {};
};

void TestItem(Item item) {

}

void TestItemPtr(Item* item)
{

}

int main()
{
	Knight* knight = new Knight();

	Item* item = (Item*)knight;

	return 0;
}