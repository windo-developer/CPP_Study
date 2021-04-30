#include <iostream>
using namespace std;

template<typename T, int SIZE = 10>
class RandomBox
{
public:
	T GetRnadomData()
	{
		int index = rand() % SIZE;
		return _data[index];
	}
public:
	T _data[SIZE];

private:
};

template<int SIZE>
class RandomBox<double, SIZE>
{
public:
	double GetRnadomData()
	{
		int index = rand() % SIZE;
		return _data[index];
	}
public:
	double _data[SIZE];

private:
};

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	RandomBox<int, 10> rb1;
	for (int i = 0; i < 10; i++)
	{
		rb1._data[i] = i;
	}

	int value1 = rb1.GetRnadomData();

	RandomBox<double, 20> rb2;
	for (int i = 0; i < 20; i++)
	{
		rb2._data[i] = i + 0.5f;
	}

	float value2 = rb2.GetRnadomData();

	cout << value1 << endl;
	cout << value2 << endl;

	return 0;
}