#include<stdio.h>
#include<math.h>
int main()
{
	float lat;
	char longi;
	printf("Please input latitude and longitude:\ne.g. 40 w\nLongitude includes:e(east),m(middle),w(west).\n");
	scanf_s("%f %c", &lat,&longi);
	if (lat <= 10.0 && lat>=0.0)
		printf("�ȴ���������");
	else if(lat<=90.0&&lat>70.0)
		printf("��������");
	else if(lat<=70.0&&lat>60.0)
		printf("�Ǻ�����½������");
	else
		switch (longi)
		{
		case 'w':if (lat <= 20.0 && lat > 10.0)
			printf("�ȴ���ԭ����");
				else if (lat <= 30.0 && lat > 20.0)
			printf("�ȴ�ɳĮ����");
				else if (lat <= 40.0 && lat > 30.0)
			printf("���к�����");
				else if (lat <= 60.0 && lat>40.0)
			printf("�´�����������");
			break;
		case'm':if (lat <= 20.0 && lat > 10.0)
			printf("�ȴ���ԭ����");
			   else if (lat <= 30.0 && lat > 20.0)
			printf("�ȴ�ɳĮ����");
			   else if (lat <= 60.0 && lat > 30.0)
			printf("�´���½������");
			break;
		case'e':if (lat <= 25.0 && lat > 10.0)
			printf("�ȴ���������");
			   else if (lat <= 35.0 && lat > 25.0)
			printf("���ȴ���������");
			   else if (lat <= 50.0 && lat > 35.0)
			printf("�´���������");
			   else if(lat<=60.0&&lat>50.0)
			printf("�Ǻ�����½������");
			break;
		default:printf("Error! Please enter correct data!\n");
		}
	return 0;
}