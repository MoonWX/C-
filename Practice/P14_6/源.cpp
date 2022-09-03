#include<stdio.h>
#include<stdlib.h>

int main()
{
	int max(int x, int y, int z);
	int a, b, c, d;
	printf("请输入第1个数字：\n");
	scanf_s("%d", &a);
	printf("请输入第2个数字：\n");
	scanf_s("%d", &b);
	printf("请输入第3个数字：\n");
	scanf_s("%d", &c);
	d = max(a, b, c);
	printf("max=%d\n", d);
	system("pause");
	return 0;
}
int max(int x, int y, int z)
{
	int m;
	if (x > y)
		m = x;
	else 
		m = y;
	if (m < z)
		m = z;
	return(m);
}