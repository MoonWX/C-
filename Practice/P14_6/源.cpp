#include<stdio.h>

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
	printf("max=%d", d);
	return 0;
}
int max(int x, int y, int z)
{
	int m;
	if (x > y > z)
		m = x;
	else
		if (y > z)
			m = y;
		else
			m = z;
	return(m);
}