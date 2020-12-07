//==========================================================================================================================
// 주차 타워 관리 프로그램
//==========================================================================================================================
// 1층
// [][][][][]
// [][][][][]
// [][][][][]
// 2층
// [][][][][]
// [][][][][]
// [][][][][]
// 3층
// [][][][][]
// [][][][][]
// [][][][][]
//==========================================================================================================================
// 1) 3차원 배열
// int parking [3][3][5];
//==========================================================================================================================
// 2) 2+1 1+2
// struct Floor
//{
// int Parking[3][5];
//};
// Floor tower[3];
//==========================================================================================================================

// 옵션 --> 배열을 선언할때.. 매개변수로 넘길때를 제외하고 []는 사용할수 없다.
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
		printf("계속하시려면 아무키나 눌러주세요.\n");
		getch();
		system("cls");
	}


}

void menuDisplay()
{
	printf("[ 1. 입차 2. 출차 3. 현황 4. 나가기 ]\n");
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
	printf("몇 층에 주차하시겠습니까?\n");
	scanf("%d", &floor);
	printf("[ %d층 ]\n", floor);
	printf("%d층 상황\n", floor);
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
				printf("[ 차량 번호 : %d 차량 타입: %s ]", (*(*(*(parking + floor) + x) + y)).numb, (*(*(*(parking + floor) + x) + y)).type);
			}
		}
		puts("");
	}
	printf("어디가 주차하시겠습니까? 좌표를 알려주세요.\n");
	printf("x: ");
	scanf("%d", &x);
	printf("y: ");
	scanf("%d", &y);
	if ((*(*(*(parking + floor) + x) + y)).numb == 0)
	{
		printf("차량 번호를 입력해주세요 : ");
		scanf("%d", &(*(*(*(parking + floor) + x) + y)).numb);
		printf("차량 형태를 입력해주세요 : ");
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
		printf("현재 시간 : %d.%d.%d", time_->tm_hour, time_->tm_min, time_->tm_sec);
	}
	else
	{
		printf("이미 차있습니다.\n");
	}
}
void parkShow(CAR(*parking)[ROW][COLUMN])
{
	int i, j, k;
	for (i = 0; i < LEVEL; i++)
	{
		printf(" [%d층] \n", i);
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
					printf(" 차량 번호 : %d 차량 타입: %s 요금: %d", (*(*(*(parking + i) + j) + k)).numb, (*(*(*(parking + i) + j) + k)).type, money(parking, i, j, k));
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
	printf("나가실 차량 번호를 입력해주세요 : ");
	scanf("%d", &key);

	for (i = 0; i < LEVEL; i++)
	{

		for (j = 0; j < ROW; j++)
		{
			for (k = 0; k < COLUMN; k++)
			{
				if ((*(*(*(parking + i) + j) + k)).numb == key)
				{
					printf("요금 : %d\n", money(parking, i, j, k));
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