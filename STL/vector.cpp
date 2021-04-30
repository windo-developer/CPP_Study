#include <iostream>
using namespace std;

template <typename T>
class Vector
{
public:
	Vector() : _data(nullptr), _size(0), _capacity(0)
	{
	}

	~Vector()
	{
		if (_data)
			delete[] _data;
	}

	void push_back(const T& value)
	{
		if (_size == _capacity)
		{
			// add memory space
			int newCapacity = static_cast<int>(_capacity * 1.5);

			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		// save data
		_data[_size] = value;

		// increase data size
		_size++;
	}

	void reserve(int capacity)
	{
		_capacity = capacity;

		T* newData = new T[_capacity];

		// data copy
		if (_data)
		{
			for (int i = 0; i < _size; i++)
			{
				newData[i] = _data[i];
			}
		}

		// delete prev data
		if (_data)
			delete[] _data;

		_data = newData;
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T* _data;
	int _size;
	int _capacity;
};

int main()
{
	return 0;
}