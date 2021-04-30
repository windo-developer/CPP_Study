#include <iostream>
using namespace std;

class Knight
{
public:

public:
	int _hp = 100;
};

template<typename T>
void Print(T a)
{
	cout << a << endl;
}

// 템플릿 특수화
template<>
void Print(Knight a)
{
	cout << "Knight template" << endl;
	cout << a._hp << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << b << endl;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// 연산자 오버로딩
//ostream& operator<<(ostream& os, const Knight& k)
//{
//	os << k._hp;
//	return os;
//}

int main()
{
	Print<int>(50);
	Print(50.0f);
	Print("Test string");

	int result = Add(2, 3);
	float reuslt2 = Add<float>(2.0f, 3.7f);

	Knight k1;
	Print(k1);

	return 0;
}