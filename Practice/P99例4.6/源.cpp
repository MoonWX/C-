#include<stdio.h>

int main()
{
	char grade;
	printf("你的成绩次第：");
	scanf_s("%c", &grade);
	printf("你的成绩区间为：");
	switch (grade)
	{
	case 'A':printf("85~100\n"); break;
	case 'B':printf("70~84\n"); break;
	case 'C':printf("60~69\n"); break;
	case 'D':printf("<60\n"); break;
	default:printf("Error. Please check the data you entered.\n");
	}
	return 0;
}