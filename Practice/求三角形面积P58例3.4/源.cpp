//根据三角形面积公式S=根号下[p*(p-a)*(p-b)*(p-c)]
//p=(a+b+c)/2
//可利用C语言代替人工计算，达到快速计算的效果！
#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c, p, S;
	printf("第一条边长：");
	scanf_s("%lf", &a);
	printf("第二条边长：");
	scanf_s("%lf", &b);
	printf("第三条边长：");
	scanf_s("%lf", &c);
	p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("\na = %f\tb = %f\tc= %f",a, b, c);
	printf("\nS= %f", S);
	return 0;
}