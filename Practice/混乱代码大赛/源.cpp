#include<stdio.h>
#include<string.h>
#include"stdlib.h"
#include"conio.h"
#include"time.h"

void welcome();
void ControlTower();
int  Game(int);
void SetGame(int);
void menu();
void Right(int);
int  Reset();
void Aboat();
void Quit();
void WriteSet();
int  movetag(int, int, int*, int*);
void WriteScore();
void Assemb(int, int*, int*);
int  RandomBlock();
int  ReadControl();
int  direct();

int  initialize(int);

#define length 25
#define height 23
#define statlen 20

/* FILE * fpScore; */
int motherboard[height][length];
int play = 0;
int CLOCKSPERSEC = 19;
long lastscore;
long highestscore;
int autocolorkey = 1;
long score;
int nextblock;
int blockX[5], blockY[5];		/*location of the block*/
int nextx[5], nexty[5];


int  BackGdColor = 0;		/*main area background color 	*/
int  StatAreaColor = 1;	/*statistic area background color    */
int  BaseHeight = 0;		/*the height of baseblock height       */
int  BlockSpeed = 1;		/*normal block speed                   */
int  BlockColor = 2;		/*normal block color                   */
int  BlockShape = 64;		/*normal block shape                   */
int  BlockFade = 1;			/*the shape when block fade away       */
int  Rim = 3;				/*rim figure                           */

char left = 'a';	 /*control */
char up = 'w';
char down = 's';
char right = 'd';
char pause = ' ';
char change = 'j';
char fastdown = 'k';

int first = 0;
int setkey = 0;

int main()
{
	welcome();
	ControlTower();
	return 0;
}

void welcome()
{
	printf("welcome() excuted\n");
	printf("in this program ,when making choice in the menu, you don't always need to add key  ENTER \n");
	printf("sometime input of key  ENTER  will be regarded as an unattached input!\n");

	getch();
	play = ReadControl();
	direct();
	printf("press any to continue\n");
	getch();
}


int direct()
{
	//	system("cls");
	int clrscr();
	//printf("%d , direct() excuted\n", play);

	printf("left : %c    right : %c    down : %c    up : %c    pause : %c    change : %c    fastdown : %c\n",
		left, right, down, up, pause, change, fastdown);
	printf("BlockShape : %c      BlockFade : %c     Rim : %c\n",
		BlockShape, BlockFade, Rim);
	printf("BaseHeight : %d     BlockSpeed : %d\n",
		BaseHeight, BlockSpeed);

	printf("\nBackGroundColor : ");
	textbackground(BackGdColor);
	cprintf("\r\n\n");

	textbackground(BLACK);
	cprintf("StatAreaColor : ");
	textbackground(StatAreaColor);
	cprintf("   \r\n\n");

	textbackground(BLACK);
	cprintf("BlockColor : ");
	textbackground(BlockColor);
	cprintf("   \r\n\n");

	textbackground(BLACK);
	cprintf("current show finished.\r\n");

	return 0;
}

/* clean window first */
void menu()
{
	//	system("cls");
	clrscr();
	//printf("menu() excuted, choose type\n");
	printf("1.	Start a new game\n");
	printf("2.	Load saved game\n");
	printf("3.	Option\n");
	printf("4.	Aboat the game\n");
	printf("5.	Quit\n");
}

void ControlTower()
{
	char option;
	play = 1;
	while (play < 100)
	{
		menu();
		option = getch();
		while (option < '1' || option > '5')
		{
			printf("please read the menu and reinput \n");
			option = getch();
		}
		switch (option)
		{
		case '1':
			Game(1);
			break;
		case '2':
			Game(2);
			break;
		case '3':
			SetGame(2);
			break;
		case '4':
			Aboat();
			break;
		case '5':
			Quit();
			break;
		}
		play++;
	}
}

void BlocktoBoard(int m)
{
	int i, j, k;

	switch (m)
	{
	case 2:
		for (k = 1; k < 5; k++)
		{
			i = blockY[0] - blockY[k];
			j = blockX[0] + blockX[k];
			motherboard[i][j] = 2;
		}
		break;
	case 0:
		for (k = 1; k < 5; k++)
		{
			i = blockY[0] - blockY[k];
			j = blockX[0] + blockX[k];
			motherboard[i][j] = 0;
		}
		break;
	case 1:
		for (k = 1; k < 5; k++)
		{
			i = blockY[0] - blockY[k];
			j = blockX[0] + blockX[k];
			motherboard[i][j] = 1;
		}
		break;
	default:
		break;
	}
}

void screendelay(clock_t wait)
{
	clock_t goal;
	goal = wait + clock();
	while (goal > clock());
}

int initialize(int n)
{
	int i, j, k;
	FILE* ScorePt;
	char name[20];		/*the name of Save File */
	char list[100];
	char* stop;

	if (n == 1)                    /*start a new game , initializing*/
	{
		/*初始化空白区域*/
		for (i = BaseHeight + 1; i < height; i++)
		{
			for (j = 1; j < length - 1; j++)
			{
				motherboard[i][j] = 0;
			}
		}

		for (i = 0, j = 1; j < length - 1; j++)	         /* bottom line*/
			motherboard[i][j] = 3;
		for (i = height - 3, j = 1; j < length - 1; j++)    /*celling*/
			motherboard[i][j] = 0;
		for (j = 0, i = 0; i < height; i++)
			motherboard[i][j] = 3;
		for (j = length - 1, i = 0; i < height; i++)
			motherboard[i][j] = 3;

		srand((unsigned)time(NULL));
		for (i = 1; i <= BaseHeight; i++)
		{
			k = 1;
			for (j = 1; j <= length - 2; j++)
			{
				motherboard[i][j] = rand() % 2;
				if (motherboard[i][j] == 0)
					k = 0;
			}
			if (k == 1)
				i--;
		}
		k = RandomBlock();
		Assemb(k, blockX, blockY);
		BlocktoBoard(2);

		printf("initialize finished, press any to continue\n");
		getch();
	}

	else if (n == 2)      /*	read in save file     */
	{
		FILE* SavePt;
		printf("input the name of Save File:\n");
		printf("\n  notice:nonly this time ,you have to add enter after your input the file name\n");

		gets(name);
		strcat(name, ".txt");
		SavePt = fopen(name, "r");

		while (SavePt == NULL)                    /*	wrong name        */
		{
			printf("wrong name or you have put your save file in the wrong path\n");
			printf("input the name of Save File or input charater  /  to quit:\n");
			printf("\n notice:nonly this time ,you have to add enter after your input the file name\n");
			gets(name);
			if (name[0] == '/')
				return 0;

			strcat(name, ".txt");
			SavePt = fopen(name, "r");
		}

		for (i = 0; i < height; i++)
		{
			for (j = 0; j < length - 1; j++)
			{
				fscanf(SavePt, "%d,", &motherboard[i][j]);
			}
			fscanf(SavePt, "%d\n", &motherboard[i][j]);
		}
		fscanf(SavePt, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", &autocolorkey, &score, &highestscore, &lastscore, &BlockSpeed, &nextblock, &blockX[0],
			&blockY[0], &blockX[1], &blockY[1], &blockX[2], &blockY[2], &blockX[3], &blockY[3],
			&blockX[4], &blockY[4]);
	}
	ScorePt = fopen("SCORE.txt", "r");
	if (ScorePt == NULL || fgets(list, 100, ScorePt) == NULL)
	{
		WriteScore();
	}
	else
	{
		rewind(ScorePt);
		if (fgets(list, 100, ScorePt) != NULL)
		{
			highestscore = (int)strtol(list, &stop, 0);
		}
		if (fgets(list, 100, ScorePt) != NULL)
		{
			lastscore = (int)strtol(list, &stop, 0);
		}
	}
	return 0;
}

void WriteScore()
{
	FILE* ScorePt;
	ScorePt = fopen("SCORE.txt", "w");
	fprintf(ScorePt, "%d, %s\n", highestscore, "highest");
	fprintf(ScorePt, "%d, %s\n", lastscore, "lastscore");
}

void screen()
{
	int i, j;
	//system("cls");
	//clrscr();
	for (i = height - 3; i >= 0; i--)
	{
		for (j = 0; j < length; j++)
		{
			if (motherboard[i][j] == 3 || i == height - 3)
			{
				textbackground(BackGdColor);
				cprintf("%c", Rim);
			}
			else if (motherboard[i][j] == 2)
			{
				textbackground(BlockColor);
				cprintf("%c", BlockShape);
			}
			else if (motherboard[i][j] == 1)
			{
				textbackground(BackGdColor);
				cprintf("%c", BlockFade);
			}
			else if (motherboard[i][j] == 0)
			{
				textbackground(BackGdColor);
				cprintf(" ");
			}
		}
		for (j = length + 1; j < length + statlen; j++)
		{
			textbackground(StatAreaColor);
			cprintf(" ");
		}
		printf("\r\n");
	}
}

int RandomBlock()
{
	srand((unsigned)time(NULL));
	return (rand() % 22);
}

void Assemb(int ram, int x[], int y[])
{
	/*key point x*/
	x[0] = (int)length / 2;

	/*block first present*/
	switch (ram)
	{
		/*key point y the location of 1,2,3,4 four small unit of block*/
	case 0:
		y[0] = height - 1;
		x[1] = 0;
		y[1] = 0;
		x[2] = 0;
		y[2] = 1;
		x[3] = 0;
		y[3] = 2;
		x[4] = 0;
		y[4] = 3;
		break;
	case 1:
		y[0] = height - 1;
		x[1] = 0;
		y[1] = 0;
		x[2] = 0;
		y[2] = 1;
		x[3] = 0;
		y[3] = 2;
		x[4] = 1;
		y[4] = 2;
		break;
	case 2:
		y[0] = height - 1;
		x[1] = 0;
		y[1] = 2;
		x[2] = 1;
		y[2] = 0;
		x[3] = 1;
		y[3] = 1;
		x[4] = 1;
		y[4] = 2;
		break;
	case 3:
		y[0] = height - 1;
		x[1] = 0;
		y[1] = 0;
		x[2] = 1;
		y[2] = 0;
		x[3] = 1;
		y[3] = 1;
		x[4] = 1;
		y[4] = 2;
		break;
	case 4:
		y[0] = height - 1;
		x[1] = 0;
		y[1] = 0;
		x[2] = 0;
		y[2] = 1;
		x[3] = 0;
		y[3] = 2;
		x[4] = 1;
		y[4] = 0;
		break;
	case 5:
		y[0] = height - 1;
		x[1] = 0;
		y[1] = 0;
		x[2] = 0;
		y[2] = 1;
		x[3] = 0;
		y[3] = 2;
		x[4] = 1;
		y[4] = 1;
		break;
	case 6:
		y[0] = height - 1;
		x[1] = 0;
		y[1] = 1;
		x[2] = 1;
		y[2] = 0;
		x[3] = 1;
		y[3] = 1;
		x[4] = 1;
		y[4] = 2;
		break;
	case 7:
		y[0] = height - 1;
		x[1] = 0;
		y[1] = 0;
		x[2] = 0;
		y[2] = 1;
		x[3] = 1;
		y[3] = 1;
		x[4] = 1;
		y[4] = 2;
		break;
	case 8:
		y[0] = height - 1;
		x[1] = 0;
		y[1] = 1;
		x[2] = 0;
		y[2] = 2;
		x[3] = 1;
		y[3] = 0;
		x[4] = 1;
		y[4] = 1;
		break;
	case 9:
		y[0] = height - 2;
		x[1] = 0;
		y[1] = 0;
		x[2] = 1;
		y[2] = 0;
		x[3] = 2;
		y[3] = 0;
		x[4] = 2;
		y[4] = 1;
		break;
	case 10:
		y[0] = height - 2;
		x[1] = 0;
		y[1] = 0;
		x[2] = 0;
		y[2] = 1;
		x[3] = 1;
		y[3] = 0;
		x[4] = 2;
		y[4] = 0;
		break;
	case 11:
		y[0] = height - 2;
		x[1] = 0;
		y[1] = 1;
		x[2] = 1;
		y[2] = 1;
		x[3] = 2;
		y[3] = 0;
		x[4] = 2;
		y[4] = 1;
		break;
	case 12:
		y[0] = height - 2;
		x[1] = 0;
		y[1] = 0;
		x[2] = 0;
		y[2] = 1;
		x[3] = 1;
		y[3] = 1;
		x[4] = 2;
		y[4] = 1;
		break;
	case 13:
		y[0] = height - 2;
		x[1] = 0;
		y[1] = 1;
		x[2] = 1;
		y[2] = 0;
		x[3] = 1;
		y[3] = 1;
		x[4] = 2;
		y[4] = 1;
		break;
	case 14:
		y[0] = height - 2;
		x[1] = 0;
		y[1] = 0;
		x[2] = 1;
		y[2] = 0;
		x[3] = 1;
		y[3] = 1;
		x[4] = 2;
		y[4] = 0;
		break;
	case 15:
		y[0] = height - 2;
		x[1] = 0;
		y[1] = 0;
		x[2] = 1;
		y[2] = 0;
		x[3] = 1;
		y[3] = 1;
		x[4] = 2;
		y[4] = 1;
		break;
	case 16:
		y[0] = height - 2;
		x[1] = 0;
		y[1] = 1;
		x[2] = 1;
		y[2] = 0;
		x[3] = 1;
		y[3] = 1;
		x[4] = 2;
		y[4] = 0;
		break;
	case 17:
	case 18:
	case 19:
	case 20:
		y[0] = height - 2;
		x[1] = 0;
		y[1] = 0;
		x[2] = 0;
		y[2] = 1;
		x[3] = 1;
		y[3] = 0;
		x[4] = 1;
		y[4] = 1;
		break;
	case 21:
		y[0] = height - 3;
		x[1] = 0;
		y[1] = 0;
		x[2] = 1;
		y[2] = 0;
		x[3] = 2;
		y[3] = 0;
		x[4] = 3;
		y[4] = 0;
		break;
	}
}

void Right(int showhide)
{
	int j;
	for (j = 1; j < 5; j++)
	{
		gotoxy(nextx[j] + length + (int)statlen / 2, nexty[j] + 2);
		cprintf("%c", BlockShape);
	}

	/*right part of the screen*/
	gotoxy(length + 1, 6);
	cprintf("current score:");
	gotoxy(length + 3, 7);
	cprintf("%d", score);

	gotoxy(length + 1, 8);
	cprintf("Personal Best:");
	gotoxy(length + 3, 9);
	cprintf("%d", highestscore);

	gotoxy(length + 1, 10);
	cprintf("Last score: ");
	gotoxy(length + 3, 11);
	cprintf("%d", highestscore);

	gotoxy(length + 1, 12);
	cprintf("Speed      : %d", BlockSpeed);
	gotoxy(length + 1, 13);
	cprintf("BaseHeight : %d", BaseHeight);

	if (showhide == 1)
	{
		gotoxy(length + 1, 14);
		cprintf("Pause Manu :");
		gotoxy(length + 1, 15);
		cprintf("1.Save");
		gotoxy(length + 1, 16);
		cprintf("2.Restart");
		gotoxy(length + 1, 17);
		cprintf("press %c to recover.", pause);
	}
	else if (showhide == 2)
	{
		gotoxy(length + 1, 18);
		cprintf("input save name:");
	}
	else if (showhide == 3)
	{
		gotoxy(length + 1, 19);
		cprintf("Enjoy Your Game !");
	}
	else if (showhide == 4)
	{
		gotoxy(length + 1, 19);
		cprintf("Level Up !");
	}
}

int hit()
{
	int i, j, k;
	if (movetag(-1, 0, blockY, blockX) == 0)
	{
		BlocktoBoard(1);
		screen();
		Right(0);
		return 1;
	}
	return 0;
}

void GameOver()
{
	lastscore = score;
	WriteScore();
	Right(3);
	getch();
}

void fadeboard(int i, int n)
{
	int j;
	for (j = 1; j < length - 1; j++)
	{
		motherboard[i][j] = n;
	}
}

int fade()
{
	int i, j, k;
	long levelscore;
	int fadeflag;
	int line[4] = { 0,0,0,0 };
	int scoretag = 0;
	for (k = 1; k < 5; k++)
	{
		fadeflag = 0;
		i = blockY[0] - blockY[k];
		for (j = 1; j < length - 1; j++)
		{
			if (motherboard[i][j] != 1)
			{
				fadeflag = 1;
				break;
			}
		}
		if (fadeflag == 0)
		{
			fadeboard(i, 2);
			line[k - 1] = i;
			scoretag++;
		}
	}
	screen();
	Right(0);
	screendelay(3);
	for (k = 0; k < 4; k++)
	{
		if (line[k] != 0)
			fadeboard(line[k], 1);
	}
	screen();
	Right(0);
	screendelay(3);

	for (k = 0; k < 4; k++)
	{
		if (line[k] != 0)
			for (i = line[k]; i < height - 3; i++)
				for (j = 1; j < length - 1; j++)
				{
					motherboard[i][j] = motherboard[i + 1][j];
				}
	}
	switch (scoretag)
	{
	case 1:score += 100; break;
	case 2:score += 300; break;
	case 3:score += 500; break;
	case 4:score += 1000; break;
	}
	if (score > highestscore)
		highestscore = score;

	if (score > BlockSpeed * 5000 && autocolorkey)
	{
		BlockSpeed++;
		BlockColor++;
		BlockColor = BlockColor % 16;
		BackGdColor++;
		BackGdColor = BlockColor % 16;
		StatAreaColor++;
		StatAreaColor = BlockColor % 16;
		screen();
		Right(4);
	}
	screen();
	Right(0);

	if (blockY[0] - scoretag > height - 4)
	{
		GameOver();
		return 100;
	}
	return 0;
}

int pausewait()
{
	char m;
	FILE* fp;
	char a[30];
	int i, j;

	Right(1);
	m = getch();
	while (m != 1 && m != 2 && m != pause)
	{
		m = getch();
	}
	if (m == 1)
	{
		Right(2);
		gets(a);
		strcat(a, ".txt");
		fp = fopen(a, "w");

		if (fp == NULL)
			printf("save file failed");
		else
		{
			for (i = 0; i < height; i++)
			{
				for (j = 0; j < length - 1; j++)
				{
					fprintf(fp, "%d,", motherboard[i][j]);
				}
				fprintf(fp, "%d\n", motherboard[i][j]);
			}
			fprintf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", autocolorkey
				, score, highestscore, lastscore, BlockSpeed, nextblock, blockX[0], blockY[0], blockX[
					1], blockY[1], blockX[2], blockY[2], blockX[3], blockY[3], blockX[4], blockY[4]);
		}
	}

	else if (m == 2)
	{
		return 100;
	}
}

int transtag(int* blockNX, int* blockNY)
{
	int i, j, k;
	int m, n;
	int transflag;
	int imax = 0, jmax = 0;

	/*假设变形，预处理*/
	for (i = 1; i < 5; i++)
	{
		if (blockNX[i] > imax) imax = blockNX[i];
		if (blockNY[i] > jmax) jmax = blockNY[i];
	}
	for (i = 1; i < 5; i++)
	{
		if (blockNY[i] == jmax)
		{
			blockNY[i] = blockNX[i];
			blockNX[i] = 0;
		}
		else if (blockNX[i] == imax)
		{
			blockNX[i] = jmax - blockNY[i];
			blockNY[i] = imax;
		}
		else if (blockNX[i] == 0)
		{
			blockNX[i] = jmax - blockNY[i];
			blockNY[i] = 0;
		}
		else if (blockNY[i] == 0)
		{
			blockNY[i] = blockNX[i];
			blockNX[i] = jmax;
		}
	}
	for (m = 0; m < 4; m++)					/*判断是否可以变形*/
	{
		for (n = 0; n < 4; n++)
		{
			transflag = movetag(0 - m, 0 - n, blockNY, blockNX);

			if (transflag == 1)
			{
				BlocktoBoard(0);
				blockY[0] -= m;
				blockX[0] -= n;
				for (i = 1; i < 5; i++)
				{
					blockX[i] = blockNX[i];
					blockY[i] = blockNY[i];
				}
				BlocktoBoard(2);
				screen();
				Right(0);
				return 1;
			}
		}
	}
}
void transfigure()			/* 变形 */
{
	int i;
	int tpblockX[5], tpblockY[5];
	for (i = 0; i < 5; i++)
	{
		tpblockX[i] = blockX[i];
		tpblockY[i] = blockY[i];
	}
	transtag(tpblockX, tpblockY);
}

int movetag(int m, int n, int blockYY[], int blockXX[])
{
	/* 返回 0 是检测到有障碍，1是没有障碍*/

	int i, j, k;
	for (k = 1; k < 5; k++)
	{
		i = blockYY[0] - blockYY[k];
		j = blockXX[0] + blockXX[k];
		if (motherboard[i + m][j + n] == 1 || motherboard[i + m][j + n] == 3)
		{
			return 0;
		}
	}
	return 1;
}

/*捕捉用户操作，并调用相应的函数去实现，实际上为游戏里的第二控制中心 */
int Action()
{
	char gotpress;
	int k;
	clock_t start, end;
	start = clock();
	end = start + 10 - BlockSpeed;

	while (clock() < end)
	{
		k = kbhit();
		if (k == -1)
		{
			gotpress = getch();

			if (gotpress == left && movetag(0, -1, blockY, blockX))
			{
				BlocktoBoard(0);
				blockX[0]--;
				BlocktoBoard(2);
				screen();
				Right(0);
			}
			else if (gotpress == right && movetag(0, 1, blockY, blockX))
			{
				BlocktoBoard(0);
				blockX[0]++;
				BlocktoBoard(2);
				screen();
				Right(0);
			}
			else if (gotpress == down)
				end = start + 1;
			else if (gotpress == pause)
				return	pausewait();
			else if (gotpress == change)
				transfigure();
			else
				BlocktoBoard(2);
		}
	}

}

/* 游戏里的大循环控制，重心在这 */
int Game(int type)
{
	int i, k = 0;
	int j = 0;
	int t = 1;
	int hitflag;
	score = 0;
	/*	initialize	*/

	if (setkey == 0)
	{
		SetGame(1);				/*对游戏显示和隐式的控制属性进行初始化*/
	}
	else
	{
		direct();
	}

	initialize(type);

	/*	gets controlset	由全局变量在其他函数里完成了*/

	while (1)
	{
		/*	create next block */
		if (t > 1 || type != 2)
		{
			// 22 种方块形状
			nextblock = RandomBlock();
		}
		else
		{
			t++;
		}


		Assemb(nextblock, nextx, nexty);
		screen();
		Right(0);

		/*	transfer , move and hang up */

		/*	hit the ground */

		/*	calculate	*/

		/*	cancel	*/

		/*	dead	*/
		hitflag = 0;
		while (hitflag == 0)
		{
			hitflag = hit();
			if (hitflag == 1)
			{
				k = fade();
				if (k == 100)
					return 100;
			}
			else
			{
				if (movetag(-1, 0, blockY, blockX))
				{
					BlocktoBoard(0);
					blockY[0]--;
					BlocktoBoard(2);
					screen();
					Right(0);
				}
				k = Action();
				if (k == 100)
					return 100;
			}
		}

		for (i = 0; i < 5; i++)
		{
			blockX[i] = nextx[i];
			blockY[i] = nexty[i];
		}
		BlocktoBoard(2);
	}
	return type;
}

int Reset()		/* 用户按键重新设置 ， 包括菜单等都在这里完成 */
{
	char part;
	printf("which part do you want to reset ?\n    1.Key of control in the game.\n    2.Attribute of the game\n    3.Go back\n");

	part = getch();
	while (part != '1' && part != '2' && part != '3')
	{
		printf("wrong input , please input  1  ,  2  or  3 .\n");
		part = getch();
	}
	if (part == '1')
	{
		printf("set key of control in the game \n NOTICE : only charaters is allowed\n\n");
		printf("left : ");
		left = getch();

		printf("%c\nright : ", left);
		right = getch();

		printf("%c\ndown : ", right);
		down = getch();

		printf("%c\nup : ", down);
		up = getch();

		printf("%c\npause : ", up);
		pause = getch();

		printf("%c\nchange : ", pause);
		change = getch();

		printf("%c\nfastdown : ", change);
		fastdown = getch();

		printf("%c\n", fastdown);
		setkey = 1;
	}
	else if (part == '2')
	{
		if (autocolorkey == '0')
		{
			printf("autocolorkey is closed . input 1 to open it \n");
			scanf("%d", &autocolorkey);
		}
		else
		{
			printf("autocolorkey is open . input 0 to close it \n");
			scanf("%d", &autocolorkey);
		}

		printf("BlockShape %c : input a number between 1 and 6 is recommended\n",
			BlockShape);
		scanf("%d", &BlockShape);
		printf("new BlockShape is %c\n\n", BlockShape);

		printf("BlockFade %c : input a number between 1 and 6 is recommended\n",
			BlockFade);
		scanf("%d", &BlockFade);
		printf("new BlockFade is %c\n\n", BlockFade);

		printf("Rim %c : input a number between 1 and 6 is recommended \n", Rim);
		scanf("%d", &Rim);
		printf("new Rim is %c\n\n", Rim);

		printf("BlockSpeed %d: input a number between 1 and 10\n", BlockSpeed);
		scanf("%d", &BlockSpeed);
		printf("new BlockSpeed now is %d\n\n", BlockSpeed);

		printf("BaseHeight %d : input a number between 0 and 20\n", BaseHeight);
		scanf("%d", &BaseHeight);
		printf("new BaseHeight now is %d\n\n", BaseHeight);


		/*set color */
		textbackground(BackGdColor);
		cprintf("current BackGroundColor value is %d : input a number between 0 and15 : ",
			BackGdColor);
		scanf("%d", &BackGdColor);
		textbackground(BackGdColor);
		cprintf("\r\nnew text BackGdcolor %d , press any to continue .", BackGdColor)
			;

		textbackground(StatAreaColor);
		cprintf("\r\n");
		cprintf("current StatAreaColor value is %d : input a number between 0 and 15: ",
			StatAreaColor);
		scanf("%d", &StatAreaColor);
		textbackground(StatAreaColor);
		cprintf("\r\nnew text StatAreaColor is %d , press any to continue .",
			StatAreaColor);

		textbackground(BlockColor);
		cprintf("\r\n");
		cprintf("current BlockColor value is %d : input a number between 0 and 15 :",
			BlockColor);
		scanf("%d", &BlockColor);
		textbackground(BlockColor);
		cprintf("\r\nnew text BlockColor %d , press any to continue .",
			BlockColor);

		cprintf("\r\n");

		textbackground(0);
		cprintf("\r\nsetgame finished .\n");
		setkey = 1;
	}
	else return 1;
	printf("do you want to save your control set ? Y/N ?\n");
	part = getch();
	if (part == 'Y' || part == 'y')
		WriteSet();
}

void WriteSet()		/* 写的实现 */
{
	FILE* fpcon = fopen("CONTROL.txt", "w");
	if (fpcon == NULL)
	{
		printf("write file Control.txt failed , maybe there are already there\n");

		exit(0);
	}
	fprintf(fpcon, "%c%c%c%c%c%c%c", left, right, down, up, pause, change, fastdown);
	fprintf(fpcon, ",%d,%d,%d,%d,%d,%d,%d,%d", BlockShape, BlockFade, Rim, BackGdColor,
		StatAreaColor, BlockSpeed, BlockColor, BaseHeight);

	printf("WriteSet() finished , press any key to continue\n");
}

int ReadControl()
{
	FILE* fpcon;
	char a[40];
	fpcon = fopen("CONTROL.txt", "r");
	if (fpcon == NULL || fgets(a, 10, fpcon) == NULL)
	{
		return 0;
	}
	else
	{
		rewind(fpcon);
		fscanf(fpcon, "%c%c%c%c%c%c%c", &left, &right, &down, &up, &pause, &change, &fastdown);
		fscanf(fpcon, ",%d,%d,%d,%d,%d,%d,%d,%d", &BlockShape, &BlockFade, &Rim, &BackGdColor, &StatAreaColor, &BlockSpeed, &BlockColor, &BaseHeight);
		rewind(fpcon);
		fscanf(fpcon, "%c", &left);
		return 1;
	}
}

void SetGame(int form)
{
	/*	char ConList[8];*/
	int p;
	printf("setgame() excuted \n");

	if (form == 1)			/* form = 1 是game 函数为了初始化游戏控制属性调用 */
	{
		ReadControl();
		direct();
	}
	else if (form == 2)		/* form = 2 是用户要进行按键设置自己调用它。*/
	{
		p = ReadControl();
		if (p == 0)
			WriteSet();
		direct();
		Reset();
	}

	printf("press any to continue\n");
	getch();
}
void Aboat()
{
	FILE* readcontrol = fopen("CONTROL.txt", "r");
	char p[10];
	int r = 0;
	//system("cls");
	clrscr();

	if (readcontrol == NULL || fgets(p, 10, readcontrol) == NULL)
	{
		direct();
		getch();
	}
	else
	{
		printf("enjoy every moment  %c\n", 1);
		printf("designed by [EJ]_leantist.	\n");

		printf("\n\ncurrent control set is  :\n");
		printf("if there are any key has no match , it matchs space or you have to reset the control\n");

		direct();

		printf("\npress any key to continue.\n");

		getch();
	}
}
void Quit()
{
	exit(0);
}
