#include <iostream>
using namespace std;

template <typename T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr)
	{
	}

	Iterator(T* ptr) : _ptr(ptr)
	{
	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	Iterator operator-(const int count)
	{
		Iterator temp = *this;
		temp._ptr -= count;
		return temp;
	}

	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator temp = this;
		_ptr++;
		return temp;
	}

	Iterator& operator--()
	{
		_ptr--;
		return *this;
	}

	Iterator operator--(int)
	{
		Iterator temp = this;
		_ptr--;
		return temp;
	}

	bool operator==(const Iterator& right)
	{
		return _ptr == right._ptr;
	}

	bool operator!=(const Iterator& right)
	{
		return _ptr != right._ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

public:
	T* _ptr;
};

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

	T& operator[] (const int pos)
	{
		return _data[pos];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

public:
	typedef Iterator<T> iterator;
	iterator begin() { return iterator(&_data[0]); }
	iterator end() { return begin() + _size; }

	void clear() { _size = 0; }

private:
	T* _data;
	int _size;
	int _capacity;
};

int main()
{
	Vector<int> v;

	// v.reserve(100);

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << "=====iterator====" << endl;

	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}

	return 0;
}