#include<stdio.h>
#include<math.h>
int main()
{
	double a, b, c, delta, x1, x2, p, q;//aΪ������ϵ����bΪһ����ϵ����cΪ�����deltaΪ�б�ʽ��x1,x2�ֱ�Ϊ���̵�������
	                                          //p=-b/2a q=sqrt(b*b-4ac)/2a
	printf("�밴\"a,b,c\"��ʽ����ϵ���������\n");
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
		printf("�˷�����ʵ����.");
	return 0;
}