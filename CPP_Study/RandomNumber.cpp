#include <iostream>
using namespace std;


void Swap(int& a, int& b)
{
	int temp = a;

	a = b;
	b = temp;
}

void Sort(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		int temp = i;

		for (int j = i + 1; j < count; j++)
		{
			if (numbers[j] < numbers[temp])
				temp = j;
		}

		if (i != temp)
			Swap(numbers[i], numbers[temp]);
	}
}

void ChooseLotto(int numbers[])
{
	srand((unsigned)time(0));

	int count = 0;

	while (count != 6)
	{
		int randValue = 1 + (rand() % 45);
		bool found = false;

		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				found = true;
				break;
			}
		}

		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}
	}

	Sort(numbers, 6);
}

int main()
{
	int numbers[6];

	ChooseLotto(numbers);

	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << endl;
	}

	return 0;
}