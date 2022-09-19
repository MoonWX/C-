#include<stdio.h>
#include<math.h>
int main()
{
	float lat;
	char longi;
	printf("Please input latitude and longitude:\ne.g. 40 w\nLongitude includes:e(east),m(middle),w(west).\n");
	scanf_s("%f %c", &lat,&longi);
	if (lat <= 10.0 && lat>=0.0)
		printf("热带雨林气候");
	else if(lat<=90.0&&lat>70.0)
		printf("极地气候");
	else if(lat<=70.0&&lat>60.0)
		printf("亚寒带大陆性气候");
	else
		switch (longi)
		{
		case 'w':if (lat <= 20.0 && lat > 10.0)
			printf("热带草原气候");
				else if (lat <= 30.0 && lat > 20.0)
			printf("热带沙漠气候");
				else if (lat <= 40.0 && lat > 30.0)
			printf("地中海气候");
				else if (lat <= 60.0 && lat>40.0)
			printf("温带海洋性气候");
			break;
		case'm':if (lat <= 20.0 && lat > 10.0)
			printf("热带草原气候");
			   else if (lat <= 30.0 && lat > 20.0)
			printf("热带沙漠气候");
			   else if (lat <= 60.0 && lat > 30.0)
			printf("温带大陆性气候");
			break;
		case'e':if (lat <= 25.0 && lat > 10.0)
			printf("热带季风气候");
			   else if (lat <= 35.0 && lat > 25.0)
			printf("亚热带季风气候");
			   else if (lat <= 50.0 && lat > 35.0)
			printf("温带季风气候");
			   else if(lat<=60.0&&lat>50.0)
			printf("亚寒带大陆性气候");
			break;
		default:printf("Error! Please enter correct data!\n");
		}
	return 0;
}