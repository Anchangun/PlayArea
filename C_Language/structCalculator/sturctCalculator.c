#include<stdio.h>
int Add(int x, int y) { return x + y; }
int Minus(int x, int y) { return x - y; }
int Multi(int x, int y) { return x + y; }
int Div(int x, int y) { return x + y; }
void CalcConstructor(CA* pthis);

typedef int(*CAL)(int, int);

typedef struct Calculator
{
	int a;
	int b;
	CAL PLUS;
	CAL MINUS;
	CAL MULTI;
	CAL DIV;
	void(*Constructor)(CA* pthis);// 초기화 작업 함수
}CA;
void CalcConstructor(CA* pthis)
{
	pthis->a = 0;
	pthis->b = 0;
	pthis->PLUS = Add;
	pthis->MINUS = Minus;
	pthis->MULTI = Multi;
	pthis->DIV = Div;
}
void main()
{
	// 계산기 객체 생성
	CA ca;
	ca.Constructor = CalcConstructor;
	ca.Constructor(&ca); // this
	char op;
	printf("1. + 2. - 3. * 4./\n");
	op = getchar();
	switch (op)
	{
	case '+':ca.PLUS(10, 10); break;
	case '-':ca.MINUS(10, 10); break;
	case '*':ca.MULTI(10, 10); break;
	case '/':ca.DIV(10, 10); break;
	}

}