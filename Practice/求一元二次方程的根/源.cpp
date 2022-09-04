#include<stdio.h>
#include<math.h>
int main()
{
	double a, b, c, delta, x1, x2, p, q;//a为二次项系数，b为一次项系数，c为常数项，delta为判别式，x1,x2分别为方程的两个解
	                                          //p=-b/2a q=sqrt(b*b-4ac)/2a
	printf("请按\"a,b,c\"格式输入系数及常数项：\n");
	scanf_s("%lf,%lf,%lf", &a, &b, &c);
	delta = b * b - 4 * a * c;
	if (delta >= 0)
	{
		p = -b / (2 * a);
		q = sqrt(delta) / (2 * a);
		x1 = p + q; x2 = p - q;
		printf("x1=%7.2f\nx2=%7.2f\n", x1, x2);
	}
	else
		printf("此方程无实数根.");
	return 0;
}