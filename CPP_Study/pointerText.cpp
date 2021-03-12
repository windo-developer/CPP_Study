#include <iostream>
using namespace std;

int StrLen(const char* str)
{
	int count = 0;
	
	while (str[count] != '\0')
	{
		count++;
	}

	return count;
}

char* StrCpy(char* dest, char* src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return dest;
}

char* StrCpyOnlyPointer(char* dest, char* src)
{
	char* ret = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\n';

	return ret;
}

char* StrCat(char* dest, char* src)
{
	int len = StrLen(dest);
	int i = 0;

	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}

	dest[len + i] = '\0';

	return dest;
}

char* StrCatOnlyPointer(char* dest, char* src)
{
	char* ret = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	 
	return ret;
}

int StrCmp(char* a, char* b)
{
	int i = 0;

	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] > b[i])
			return 1;
		if (a[i] < b[i])
			return -1;
		i++;
	}

	return 0;
}

void ReverseStr(char* str)
{
	int len = StrLen(str);

	for (int i = 0; i < len / 2; i++)
	{
		int temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "World";

	// int len2 = StrLen(a); //int len = strlen(a);
	// StrCpy(b, a); // strcpy_s(b, a);
	// StrCat(a, b); // strcat_s(a, b);
	// StrCmp(a, b) // strcmp(a, b);
	
	return 0;
}