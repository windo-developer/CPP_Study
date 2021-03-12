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
		_pet = new Pet(*knight._pet); // 깊은 복사
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

	cout << "============== 복사 생성자 =============" << endl;
	Knight knight2 = knight; // 복사 생성자

	Knight knight3; // 기본 생성자
	cout << "============== 복사 대입 연산자 ============" << endl;
	knight3 = knight; // 복사 대입 생성자

	return 0;
}