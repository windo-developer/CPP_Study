#include <iostream>
using namespace std;

class Position
{
public:
	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;
		return pos;
	}

	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;
		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}

	Position& operator=(int arg)
	{
		_x = arg;
		_y = arg;

		return *this;
	}

	Position& operator=(const Position& arg)
	{
		_x = arg._x;
		_y = arg._y;

		return *this;
	}

	Position operator++()
	{
		_x++;
		_y++;
		return *this;
	}

	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;
		return ret;
	}

public:
	int _x;
	int _y;
};

int main()
{
	Position pos1;
	pos1._x = 0;
	pos1._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos1 + pos2;

	Position pos5;
	pos5 = (pos2 = 5);

	pos5 = pos3++;

	return 0;
}