//======================================================================
//  void *  
//	-  어떤 주소값이든 저장이 가능한 포인터 !! 
//	-  모든 포인터(주소값) 4byte크기로 동일 !! 
//  사용상의 주의점 !! 
//   1) 역참조가 불가능 : void * 대상체(크기)가 없는 포인터 이기때문에 읽을수없다. 
//   2) 포인터 연산  불가능 :  몇바이트를 이동? 읽어들일지를 모른다 !! 
//====================================================================== 
//  1) 함수에서 특정 주속값을 리턴할때.. 
//   ex)malloc -->  heap에 할당을하고 시작 주소를 리턴 !! 
//	 --> 할당되어진 메모리의 크기를 예측할수 없다 :  void * 리턴 !! 
//  2) 매개변수를 전달할때..  일반화 !! 
//	==> 소스코드는 동일하고.. 매개변수의 타입이 다른경우  
//  3) 데이타가 결정이 되지 않았을경우 !! 
//	--> 타입이 결정되어 있지 않은 데이타를 만들고자 할때!! 
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
	void(*show)(Element*);	// 각각에 타입에 맞는 출력을 구현 !! 
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


/* //  2) 매개변수를 전달할때..  일반화 !!
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
	//	*x = *y;  --> void * 역참조 불가능 !!
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


