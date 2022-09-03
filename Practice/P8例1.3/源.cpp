#include<stdio.h>
//主函数
int main()
{
	int x, y;
	int max(int x, int y);
	int a, b, c;
	scanf_s("%d,%d", &a, &b);
	c = max(a, b);
	printf("max=%d\n", c);
	return 0;
}
//求两个整数中的较大者的max函数
int max(int x, int y)
{
	int z;
	if (x > y)
		z = x;
	else
		z = y;
	return(z);
}