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

	// (1) number�� ���Ϳ� �ִ��� üũ
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

	// (1) std::find�� Ȱ���� ���� ���
	vector<int>::iterator itFind = find(v.begin(), v.end(), number);
	if (itFind == v.end())
	{
		cout << "cant find" << endl;
	}
	else
	{
		cout << "find" << endl;
	}

	// (2) 11�� �������� ���ڰ� ���Ϳ� �ִ��� üũ
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

	// (2) std::find_if�� Ȱ���� ���� ���
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

	// (3) Ȧ���� ������?
	int count = 0;

	for (int i = 0; i < v.size(); i++)
	{
		int data = v[i];
		if (data % 2 != 0)
		{
			count++;
		}
	}

	// (3) std::count_if�� Ȱ���� ���� ���
	struct IsOdd
	{
		bool operator()(int n)
		{
			return (n % 2) != 0;
		}
	};

	int n = count_if(v.begin(), v.end(), IsOdd());

	bool b1 = all_of(v.begin(), v.end(), IsOdd());	// ��� �����Ͱ� Ȧ��?
	bool b2 = any_of(v.begin(), v.end(), IsOdd());	// �����Ͱ� �ϳ��� Ȧ��?
	bool b3 = none_of(v.begin(), v.end(), IsOdd());	// ��� �����Ͱ� Ȧ���� �ƴմϱ�?

	// (4) ���Ϳ� �ִ� ��� ���� *3
	for (int i = 0; i < v.size(); i++)
	{
		v[i] *= 3;
	}

	// (4) std::for_each�� Ȱ���� ���� ���
	struct MultiplyBy3
	{
		void operator()(int& n)
		{
			n = n * 3;
		}
	};

	for_each(v.begin(), v.end(), MultiplyBy3());

	// (5) Ȧ�� ������ �ϰ� ����
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