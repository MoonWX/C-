#include <iostream>
#include <string.h>
using namespace std;

int check(char* str)
{
	int i = 0;
	int j = strlen(str) - 1;
	while (i < j)
	{
		if (*(str + i) != *(str + j))
			return 0;
		i++;
		j--;
	}
	return 1;
}

void get_str(char* str)
{
	int n = strlen(str) - 1;

	char* p = new char[n + 1];
	strcpy(p, str);
	int i = 0;
	int j;
	for (; i < n; i++)
	{
		p += i;
		j = n - i;
		while (j > 0){
			*(p + j + 1) = '\0';
			if (check(p))
			{
				cout << p << "   ";
				cout << endl;
			}
			j--;
		}
		strcpy(p, str);
	}
}
int main()
{
	char s[505];
	cin.getline(s, 505);
	get_str(s);//test
	return 0;
}