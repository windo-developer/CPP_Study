#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Node
{
public:
	Node() : _next(nullptr), _prev(nullptr), _data(T())
	{
	}
	Node(const T& value) : _next(nullptr), _prev(nullptr), _data(value)
	{
	}

public:
	Node* _next;
	Node* _prev;
	T	  _data;

private:
};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{
	}

	Iterator(Node<T>* node) : _node(node)
	{
	}

	Iterator<T>& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Iterator<T>& operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	Iterator<T>& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Iterator<T>& operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& right)
	{
		return _node == right._node;
	}

	bool operator!=(const Iterator& right)
	{
		return _node != right._node;
	}

public:
	Node<T>* _node;
};

template<typename T>
class List
{
public:
	List() : _size(0)
	{
		_header = new Node<T>();
		_header->_next = _header;
		_header->_prev = _header;
	}

	~List()
	{
		while (_size > 0)
			pop_back();

		delete _header;
	}

	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* node = new Node<T>(value);

		Node<T>* prevNode = before->_prev;
		prevNode->_next = node;
		node->_prev = prevNode;

		node->_next = before;
		before->_prev = node;

		_size++;

		return node;
	}

	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}

	int size() { return _size; }

	void push_back(const T& value)
	{
		AddNode(_header, value);
	}

	void pop_back()
	{
		RemoveNode(_header->_prev);
	}

public:
	typedef Iterator<T> iterator;

	iterator begin() { return iterator(_header->_next); }
	iterator end() { return iterator(_header); }

	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

public:
	Node<T>* _header;
	int _size;
};

int main()
{
	List<int> li;

	List<int>::iterator eraseIt;

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseIt = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}
	}

	li.pop_back();
	li.erase(eraseIt);

	for (List<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << (*it) << endl;
	}

	return 0;
}