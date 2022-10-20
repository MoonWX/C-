#include <stdio.h>
float x0, y0;
void intersect(float a, float b, float c, float d)
{
	x0 = (d - b) / (a - c);
	y0 = (a * d - b * c) / (a - c);
}
int main()
{
	float a, b, c, d;
	printf("Please input parameters of the first straight line.\n");
	printf("y=ax+b, inputting 7,3 ,which means a=7 b=3.\n");
	scanf_s("%f,%f", &a, &b);
	printf("Please input parameters of the second straight line.\n");
	printf("y=cx+d, inputting input 7,3 ,which means c=7 d=3.\n");
	scanf_s("%f,%f", &c, &d);
	intersect(a,b,c,d);
	printf("The intersection point is (%f,%f)",x0,y0);
	return 0;
}