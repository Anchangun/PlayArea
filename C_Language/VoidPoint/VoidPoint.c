//======================================================================
//  void *  
//	-  � �ּҰ��̵� ������ ������ ������ !! 
//	-  ��� ������(�ּҰ�) 4byteũ��� ���� !! 
//  ������ ������ !! 
//   1) �������� �Ұ��� : void * ���ü(ũ��)�� ���� ������ �̱⶧���� ����������. 
//   2) ������ ����  �Ұ��� :  �����Ʈ�� �̵�? �о�������� �𸥴� !! 
//====================================================================== 
//  1) �Լ����� Ư�� �ּӰ��� �����Ҷ�.. 
//   ex)malloc -->  heap�� �Ҵ����ϰ� ���� �ּҸ� ���� !! 
//	 --> �Ҵ�Ǿ��� �޸��� ũ�⸦ �����Ҽ� ���� :  void * ���� !! 
//  2) �Ű������� �����Ҷ�..  �Ϲ�ȭ !! 
//	==> �ҽ��ڵ�� �����ϰ�.. �Ű������� Ÿ���� �ٸ����  
//  3) ����Ÿ�� ������ ���� �ʾ������ !! 
//	--> Ÿ���� �����Ǿ� ���� ���� ����Ÿ�� ������� �Ҷ�!! 
//==========================================================================

#include <stdio.h> 
#include <malloc.h>
#include <memory.h>
#include <string.h> 


typedef struct Point
{
	int x;
	int y;
}Point;


void input(void* Element, void* value, int size)
{
	memcpy(Element, value, size);
}

typedef struct Element
{
	void* data;
	int  size;
	void(*show)(Element*);	// ������ Ÿ�Կ� �´� ����� ���� !! 
}Element;

void showint(Element* pthis) { printf("%d\n", *(int*)pthis->data); }
void showchar(Element* pthis) { printf("%s\n", (char*)pthis->data); }
void showpoint(Element* pthis) { printf("%d  :  %d \n", ((Point*)pthis->data)->x, ((Point*)pthis->data)->y); }





void main()
{
	int value = 1234;
	char* str = "ABCasdasd";
	Point pt = { 1234, 5678 };
	Element Elements[3];
	Elements[0].data = malloc(sizeof(int));
	Elements[0].size = sizeof(int);
	Elements[0].show = showint;

	Elements[1].data = malloc(sizeof(char) * 16);
	Elements[1].size = 16;
	Elements[1].show = showchar;

	Elements[2].data = malloc(sizeof(Point));
	Elements[2].size = sizeof(Point);
	Elements[2].show = showpoint;

	input(Elements[0].data, &value, Elements[0].size);
	input(Elements[1].data, str, Elements[1].size);
	input(Elements[2].data, &pt, Elements[2].size);

	for (int i = 0; i < 3; i++)
	{
		Elements[i].show(Elements + i);

	}







	/*
	void * Elements[3];	 // 20
	int value = 4885;
	char  str[16] = "ABC";
	Point pt = { 1234, 5678 };

	Elements[0] = malloc(sizeof(int));
	Elements[1] = malloc(sizeof(char)* 16);
	Elements[2] = malloc(sizeof(Point));


	input(Elements[0], &value, sizeof(4885));
	input(Elements[1], str,  strlen(str)+1 );
	input(Elements[2], &pt , sizeof(Point));

	printf("%d\n",  *(int*)Elements[0]);
	printf("%s\n",  (char*)Elements[1]);
	printf("%d %d\n", ((Point*)Elements[2])->x, ((Point*)Elements[2])->y);
	*/



}


/* //  2) �Ű������� �����Ҷ�..  �Ϲ�ȭ !!
void Swap(int * x, int * y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}*/
/*
void Swap(void * x, void * y, int size)
{
	void * t = malloc(size);
	//	*x = *y;  --> void * ������ �Ұ��� !!
	memcpy(t, x, size);
	memcpy(x, y, size);
	memcpy(y, t, size);
	free(t);
}


void main()
{
	double x = 10 , y = 20;
	printf("%d %d \n", x, y);
	Swap(&x, &y, sizeof(double));
	printf("%d %d \n", x, y);

}
*/


