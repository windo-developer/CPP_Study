#include <iostream>
using namespace std;

class Knight
{
public:
	Knight() { cout << "Knight 持失切" << endl; }
	~Knight() { cout << "Knight 社瑚切" << endl; }

	void Attack()
	{
		if (_target != nullptr)
		{
			shared_ptr<Knight> sptr = _target;
			sptr->_hp -= _damage;
			cout << "HP: " << sptr->_hp << endl;
		}
	}
public:
	int _hp = 100;
	int _damage = 10;
	shared_ptr<Knight> _target = nullptr;
	// weak_ptr<Knight> _target;
};

class RefCountBlock
{
public:

public:
	int _refCount = 1;
	int _weakCount = 1;
};

template<typename T>
class SharedPtr
{
public:
	SharedPtr() {}
	SharedPtr(T* ptr) : _ptr(ptr)
	{
		if (_ptr != nullptr)
		{
			_block = new RefCountBlock();
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	SharedPtr(const SharedPtr& sptr) : _ptr(sptr._ptr), _block(sptr._block)
	{
		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	void operator=(const SharedPtr& sptr)
	{
		_ptr = sptr._ptr;
		_block = sptr._block;

		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	~SharedPtr()
	{
		if (_ptr != nullptr)
		{
			_block->_refCount--;
			cout << "RefCount : " << _block->_refCount << endl;

			if (_block->_refCount == 0)
			{
				delete _ptr;
				delete _block;
				cout << "Delete Data" << endl;
			}
		}
	}
public:
	T* _ptr;
	RefCountBlock* _block;
};

int main()
{
	/*Knight* k1 = new Knight();
	Knight* k2 = new Knight();

	k1->_target = k2;

	delete k2;

	k1->Attack();*/

	/*SharedPtr<Knight> k2;

	SharedPtr<Knight> k1(new Knight());
	k2 = k1;*/

	// shared_ptr
	shared_ptr<Knight> k1 = make_shared<Knight>();
	shared_ptr<Knight> k2 = make_shared<Knight>();

	k1->_target = k2;
	k2->_target = k1;

	k1->Attack();

	// k1->_target = nullptr;
	// k2->_target = nullptr;
	// weak_ptr, unique_ptr

	// unique_ptr<Knight> uptr = make_unique<Knight>();
	// unique_ptr<Knight> uptr2 = move(uptr);

	return 0;
}