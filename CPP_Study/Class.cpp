#include <iostream>
using namespace std;

class Knight
{
public:
	Knight();
	~Knight();

private:

public:
	int _hp = 0;
};

Knight::Knight()
{
}

Knight::~Knight()
{
}

int main()
{
	Knight knight;

	cout << knight._hp << endl;

	return 0;
}