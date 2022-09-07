/*
给一个不多于5位的正整数，要求：
  1.求出它是几位数
  2.分别输出每一位数字
  3.按逆序输出各位数字
  */
#include<stdio.h>
#include<math.h>
#include<Windows.h>

int main()
{
	int a,count=0,rev=0,t,m;
	printf("给出你的数字:");
	scanf_s("%d", &a);
	m = a;
	printf("倒序后为：");
	while(a > 0)
	{   rev = a % 10;
		a = a / 10;
		count=count+1;
		printf("%d", rev);
	}
	t = count;
	printf("\n位数为：%d\n", count);
	printf("分别输出为：");
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
