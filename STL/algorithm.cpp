#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;
	vector<int>::iterator it;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// (1) number가 벡터에 있는지 체크
	int number = 50;
	bool found = false;

	for (int i = 0; i < v.size(); i++)
	{
		int data = v[i];
		if (data == number)
		{
			found = true;
			it = v.begin() + i;
			break;
		}
	}

	// (1) std::find를 활용한 구현 방법
	vector<int>::iterator itFind = find(v.begin(), v.end(), number);
	if (itFind == v.end())
	{
		cout << "cant find" << endl;
	}
	else
	{
		cout << "find" << endl;
	}

	// (2) 11로 나눠지는 숫자가 벡터에 있는지 체크
	for (int i = 0; i < v.size(); i++)
	{
		int data = v[i];
		if (data % 11 == 0)
		{
			found = true;
			it = v.begin() + i;
			break;
		}
	}

	// (2) std::find_if를 활용한 구현 방법
	struct CanDivideBy11
	{
		bool operator()(int n)
		{
			return (n % 11) == 0;
		}
	};

	vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivideBy11());
	if (itFind == v.end())
	{
		cout << "cant find" << endl;
	}
	else
	{
		cout << "find" << endl;
	}

	// (3) 홀수의 개수는?
	int count = 0;

	for (int i = 0; i < v.size(); i++)
	{
		int data = v[i];
		if (data % 2 != 0)
		{
			count++;
		}
	}

	// (3) std::count_if를 활용한 구현 방법
	struct IsOdd
	{
		bool operator()(int n)
		{
			return (n % 2) != 0;
		}
	};

	int n = count_if(v.begin(), v.end(), IsOdd());

	bool b1 = all_of(v.begin(), v.end(), IsOdd());	// 모든 데이터가 홀수?
	bool b2 = any_of(v.begin(), v.end(), IsOdd());	// 데이터가 하나라도 홀수?
	bool b3 = none_of(v.begin(), v.end(), IsOdd());	// 모든 데이터가 홀수가 아닙니까?

	// (4) 벡터에 있는 모든 숫자 *3
	for (int i = 0; i < v.size(); i++)
	{
		v[i] *= 3;
	}

	// (4) std::for_each를 활용한 구현 방법
	struct MultiplyBy3
	{
		void operator()(int& n)
		{
			n = n * 3;
		}
	};

	for_each(v.begin(), v.end(), MultiplyBy3());

	// (5) 홀수 데이터 일괄 삭제
	struct IsOdd
	{
		bool operator()(int n)
		{
			return (n % 2) != 0;
		}
	};

	vector<int>::iterator it = remove_if(v.begin(), v.end(), IsOdd());
	v.erase(it, v.end());

	// v.erase(remove_if(v.begin(), v.end(), IsOdd()), v.end());
	return 0;
}