#include <iostream>
#include <vector>
using namespace std;

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item() {}
	Item(int itemId, Rarity rarity, ItemType type) : _itemId(itemId), _rarity(rarity), _type(type)
	{
	}

public:
	int _itemId = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};

int main()
{
	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	//
	/*struct IsUniqueItem
	{
		bool operator()(Item& item)
		{
			return item._rarity == Rarity::Unique;
		}
	};

	auto findIterator = find_if(v.begin(), v.end(), IsUniqueItem());

	if (findIterator != v.end())
		cout << "Item ID: " << findIterator->_itemId << endl;*/

		// lambda
	auto isUniqueLambda = [](Item& item) {return item._rarity == Rarity::Unique; };

	auto findIterator = find_if(v.begin(), v.end(), [](Item& item) {return item._rarity == Rarity::Unique; });

	if (findIterator != v.end())
		cout << "Item ID: " << findIterator->_itemId << endl;

	return 0;
}