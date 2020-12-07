//==========================================================================================================================
// ���� Ÿ�� ���� ���α׷�
//==========================================================================================================================
// 1��
// [][][][][]
// [][][][][]
// [][][][][]
// 2��
// [][][][][]
// [][][][][]
// [][][][][]
// 3��
// [][][][][]
// [][][][][]
// [][][][][]
//==========================================================================================================================
// 1) 3���� �迭
// int parking [3][3][5];
//==========================================================================================================================
// 2) 2+1 1+2
// struct Floor
//{
// int Parking[3][5];
//};
// Floor tower[3];
//==========================================================================================================================

// �ɼ� --> �迭�� �����Ҷ�.. �Ű������� �ѱ涧�� �����ϰ� []�� ����Ҽ� ����.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#include<time.h>
#define LEVEL 3
#define ROW 3
#define COLUMN 5
typedef struct Stime
{
	int h;
	int m;
	int s;
}STIME;

typedef struct Point
{
	int x;
	int y;
}POINT;
typedef struct Car
{
	int numb;
	char type[20];
	POINT* point;
	STIME* stime;
}CAR;


void menuDisplay();

int Input();
void parkInput(CAR(*parking)[ROW][COLUMN]);
void parkShow(CAR(*parking)[ROW][COLUMN]);
void parkOutput(CAR(*parking)[ROW][COLUMN]);
int money(CAR(*parking)[ROW][COLUMN], int, int, int);
void parkEnd(CAR(*parking)[ROW][COLUMN]);
void main()
{
	CAR parking[LEVEL][ROW][COLUMN];

	memset(parking, 0, sizeof(parking));

	while (1)
	{
		menuDisplay();
		switch (Input())
		{
		case 1:
			parkInput(parking);
			break;
		case 2:
			parkOutput(parking);
			break;
		case 3:
			parkShow(parking);
			break;
		case 4:
			parkEnd(parking); exit(1);
		}
		printf("����Ͻ÷��� �ƹ�Ű�� �����ּ���.\n");
		getch();
		system("cls");
	}


}

void menuDisplay()
{
	printf("[ 1. ���� 2. ���� 3. ��Ȳ 4. ������ ]\n");
	printf("[    ]\b\b");
}
int Input()
{
	int key = 0;
	scanf("%d", &key);
	return key;
}
void parkInput(CAR(*parking)[ROW][COLUMN])
{
	int floor = 0;
	int i, j, k;
	int x = 0, y = 0;
	time_t now;
	struct tm* time_;
	now = time(NULL);
	time_ = localtime(&now);
	printf("�� ���� �����Ͻðڽ��ϱ�?\n");
	scanf("%d", &floor);
	printf("[ %d�� ]\n", floor);
	printf("%d�� ��Ȳ\n", floor);
	for (j = 0; j < ROW; j++)
	{
		for (k = 0; k < COLUMN; k++)
		{
			if ((*(*(*(parking + floor) + x) + y)).numb == 0)
			{
				printf("[         ]");
			}
			else
			{
				printf("[ ���� ��ȣ : %d ���� Ÿ��: %s ]", (*(*(*(parking + floor) + x) + y)).numb, (*(*(*(parking + floor) + x) + y)).type);
			}
		}
		puts("");
	}
	printf("��� �����Ͻðڽ��ϱ�? ��ǥ�� �˷��ּ���.\n");
	printf("x: ");
	scanf("%d", &x);
	printf("y: ");
	scanf("%d", &y);
	if ((*(*(*(parking + floor) + x) + y)).numb == 0)
	{
		printf("���� ��ȣ�� �Է����ּ��� : ");
		scanf("%d", &(*(*(*(parking + floor) + x) + y)).numb);
		printf("���� ���¸� �Է����ּ��� : ");
		scanf("%s", &(*(*(*(parking + floor) + x) + y)).type);
		(*(*(*(parking + floor) + x) + y)).point = (POINT*)malloc(sizeof(POINT));
		(*(*(*(parking + floor) + x) + y)).stime = (STIME*)malloc(sizeof(STIME));
		memset((*(*(*(parking + floor) + x) + y)).point, 0, sizeof((*(*(*(parking + floor) + x) + y)).point));
		memset((*(*(*(parking + floor) + x) + y)).stime, 0, sizeof((*(*(*(parking + floor) + x) + y)).stime));
		(*(*(*(parking + floor) + x) + y)).point->x = x;
		(*(*(*(parking + floor) + x) + y)).point->y = y;
		(*(*(*(parking + floor) + x) + y)).stime->h = time_->tm_hour;
		(*(*(*(parking + floor) + x) + y)).stime->m = time_->tm_min;
		(*(*(*(parking + floor) + x) + y)).stime->s = time_->tm_sec;
		printf("���� �ð� : %d.%d.%d", time_->tm_hour, time_->tm_min, time_->tm_sec);
	}
	else
	{
		printf("�̹� ���ֽ��ϴ�.\n");
	}
}
void parkShow(CAR(*parking)[ROW][COLUMN])
{
	int i, j, k;
	for (i = 0; i < LEVEL; i++)
	{
		printf(" [%d��] \n", i);
		for (j = 0; j < ROW; j++)
		{
			for (k = 0; k < COLUMN; k++)
			{
				if ((*(*(*(parking + i) + j) + k)).numb == 0)
				{
					printf("[         ]");
				}
				else
				{
					printf(" ���� ��ȣ : %d ���� Ÿ��: %s ���: %d", (*(*(*(parking + i) + j) + k)).numb, (*(*(*(parking + i) + j) + k)).type, money(parking, i, j, k));
				}
			}
			puts("");
		}
	}

}
int money(CAR(*parking)[ROW][COLUMN], int i, int j, int k)
{
	time_t now;
	struct tm* time_;
	now = time(NULL);
	time_ = localtime(&now);
	int nh = 0, nm = 0, ns = 0;
	int nmoney = 0;
	nh = time_->tm_hour - (*(*(*(parking + i) + j) + k)).stime->h;
	nm = time_->tm_min - (*(*(*(parking + i) + j) + k)).stime->m;
	if (nm < 0)
	{
		nh = nh - 1;
		nm = nm + 60;
	}
	ns = time_->tm_sec - (*(*(*(parking + i) + j) + k)).stime->s;
	if (ns < 0)
	{
		nm = nm - 1;
		ns = ns + 60;
	}
	nmoney = ((nh * 60 * 60) + (nm * 60) + ns) * 10;
	return nmoney;

}
void parkOutput(CAR(*parking)[ROW][COLUMN])
{
	int key;
	int i, j, k;
	printf("������ ���� ��ȣ�� �Է����ּ��� : ");
	scanf("%d", &key);

	for (i = 0; i < LEVEL; i++)
	{

		for (j = 0; j < ROW; j++)
		{
			for (k = 0; k < COLUMN; k++)
			{
				if ((*(*(*(parking + i) + j) + k)).numb == key)
				{
					printf("��� : %d\n", money(parking, i, j, k));
					(*(*(*(parking + i) + j) + k)).numb = 0;
					memset((*(*(*(parking + i) + j) + k)).type, 0, sizeof((*(*(*(parking + i) + j) + k)).type));
					memset((*(*(*(parking + i) + j) + k)).point, 0, sizeof((*(*(*(parking + i) + j) + k)).point));
					memset((*(*(*(parking + i) + j) + k)).stime, 0, sizeof((*(*(*(parking + i) + j) + k)).stime));
				}
			}
		}
	}
}
void parkEnd(CAR(*parking)[ROW][COLUMN])
{
	int i, j, k;
	for (i = 0; i < LEVEL; i++)
	{

		for (j = 0; j < ROW; j++)
		{
			for (k = 0; k < COLUMN; k++)
			{
				if ((*(*(*(parking + i) + j) + k)).numb != 0)
				{
					free((*(*(*(parking + i) + j) + k)).point);
					free((*(*(*(parking + i) + j) + k)).stime);
				}
			}
		}
	}
}