//���������������ʽS=������[p*(p-a)*(p-b)*(p-c)]
//p=(a+b+c)/2
//������C���Դ����˹����㣬�ﵽ���ټ����Ч����
#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c, p, S;
	printf("��һ���߳���");
	scanf_s("%lf", &a);
	printf("�ڶ����߳���");
	scanf_s("%lf", &b);
	printf("�������߳���");
	scanf_s("%lf", &c);
	p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("\na = %f\tb = %f\tc= %f",a, b, c);
	printf("\nS= %f", S);
	return 0;
}