#include <iostream>
using namespace std;

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}
	~Pet()
	{
		cout << "~Pet()" << endl;
	}
	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}
};

class Player {
public:
	Player()
	{
		cout << "Player()" << endl;
	}

	Player(const Player& player)
	{
		cout << "Player(const Player&)" << endl;
	}

	Player& operator=(const Player& player)
	{
		cout << "operator=(const Player& player)" << endl;
	}

public:
	int _level = 0;
};

class Knight : public Player
{
public:
	Knight()
	{
		_pet = new Pet();
	}
	Knight(const Knight& knight) : Player(knight), _pet(knight._pet)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // ���� ����
	}
	Knight& operator=(const Knight& knight)
	{
		Player::operator=(knight);
		_pet = knight._pet;
		_hp = knight._hp;

		return *this;
	}
	~Knight()
	{
		delete _pet;
	}

public:
	int _hp = 100;
	Pet* _pet;
};


int main() {

	Knight knight;
	knight._hp = 200;
	knight._level = 100000;

	cout << "============== ���� ������ =============" << endl;
	Knight knight2 = knight; // ���� ������

	Knight knight3; // �⺻ ������
	cout << "============== ���� ���� ������ ============" << endl;
	knight3 = knight; // ���� ���� ������

	return 0;
}