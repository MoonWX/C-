/*
��һ��������5λ����������Ҫ��
  1.������Ǽ�λ��
  2.�ֱ����ÿһλ����
  3.�����������λ����
  */
#include<stdio.h>
#include<math.h>
#include<Windows.h>

int main()
{
	int a,count=0,rev=0,t,m;
	printf("�����������:");
	scanf_s("%d", &a);
	m = a;
	printf("�����Ϊ��");
	while(a > 0)
	{   rev = a % 10;
		a = a / 10;
		count=count+1;
		printf("%d", rev);
	}
	t = count;
	printf("\nλ��Ϊ��%d\n", count);
	printf("�ֱ����Ϊ��");
	while (t != 0)
	{
		int i;
		double n;
		n = m / pow(10, t-1);
		i = floor(n);
		m = m - i * pow(10,t-1);
		printf("%d ", i);
		t--;
	}
	system("pause");
	return 0;
}
