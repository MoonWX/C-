//���������������ʽS=������[p*(p-a)*(p-b)*(p-c)]
//p=(a+b+c)/2
//������C���Դ����˹����㣬�ﵽ���ټ����Ч����
#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c, p, S;
	printf("��һ���߳���\t");
	scanf_s("%f", &a);
	printf("�ڶ����߳���\t");
	scanf_s("%f", &b);
	printf("�������߳���\t");
	scanf_s("%f", &c);
	p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("\na = %f\tb = %f\tc= %f",a, b, c);
	printf("\nS= %f", S);
	return 0;
}