//#include <iostream>
//using namespace std;
//int main()
//{
//	int i = 5;	
//	do
//	{
//		switch (i % 2 == 0)
//		{
//		case 0: i--; break;
//		case 1: i--; continue;
//		}
//		i--;
//		cout << i << '\t';
//	} while (i > 0);
//	cout << '\n';
//	return 0;
//}

//3 1 -1
#include <iostream>
using namespace std;
int main()
{
	int i = 1, j = 1;
	for (; j < 10; j++)
	{
		if(j>5)
		{
			i += 2;
			break;
		}
		if(j%2!=0)
		{
			j += 2;
			continue;
		}
		cout << i << '\t' << j << endl;
	}
	cout << i << '\t' << j << endl;
	return 0;
}
//1 4
//3 8