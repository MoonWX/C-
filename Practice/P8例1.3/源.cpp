#include<stdio.h>
//������
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
//�����������еĽϴ��ߵ�max����
int max(int x, int y)
{
	int z;
	if (x > y)
		z = x;
	else
		z = y;
	return(z);
}