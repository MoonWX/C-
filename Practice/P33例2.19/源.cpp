#include<stdio.h>

int main()
{
	int sign = 1;
	double fenmu = 2.0, sum = 1.0, temp;
	while (fenmu <= 100)
	{
		sign = -sign;
		temp = sign / fenmu;
		sum = sum + temp;
		fenmu = fenmu++;
	}
	printf("%f\n", sum);
	return 0;
}