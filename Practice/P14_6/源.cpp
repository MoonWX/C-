#include<stdio.h>

int main()
{
	int max(int x, int y, int z);
	int a, b, c, d;
	printf("�������1�����֣�\n");
	scanf_s("%d", &a);
	printf("�������2�����֣�\n");
	scanf_s("%d", &b);
	printf("�������3�����֣�\n");
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