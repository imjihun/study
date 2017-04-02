#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pof_test1(float a, double b, int c){
	printf("called %8.1f %15s (%.1f, %.1lf, %d)\n", (a+b)/c, "pof_test1", a, b, c);
	return (a+b)/c;
}
float pof_test2(int a, int b){
	printf("called %8.1f %15s (%d, %d)\n", (float)a/(float)b, "pof_test2", a, b);
	return (float)a/(float)b;
}
int (*pof_test_main(float (*p)(int, int)))(float, double, int){
	printf("called %8x %15s (%x -> %.1f)\n", pof_test1, "pof_test_main", p, p(1,2));
	return pof_test1;
}

int subpof1(int a, int b){
	printf("called %8d %15s(%d, %d)\n", a+b, "pof1 ", a, b);
	return a+b;
}
int (*pof1(int a))(int, int){
	printf("called %8x %15s(%d)\n", pof1, "subpof1 ", a);
	return subpof1;
}
float pof2(int a, double b){
	printf("called %8.1f %15s(%d, %.1lf)\n", a+b, "pof2 ", a, b);
	return a+b;
}
int (*(*pof_test_main2(float (*p)(int, double)))(int))(int, int){
	printf("called %8x %15s(%x->%.1f)\n", subpof1, "pof_test_main ", p, p(4,5));
	return pof1;
}
int main(){
	printf("main1 : %d\n\n", pof_test_main(pof_test2)(3.7,4.3,2));
	printf("main2 : %d\n", pof_test_main2(pof2)(1)(2,3));
					//추가적인 함수포인터 사용
					//ex) num = pof2(a,b); ret = pof_test_main(num); -> pof2함수가 전역으로 선언되어 있지 않으면, pof_test_main 실행중에 pof2의 함수를 실행 못시킴
					//					   ret = pof_test_main(pof2);-> pof2함수가 전역으로 선언되어 있지 않아도, pof_test_main 실행중에 pof2의 함수 실행가능. 그리고 같은 코드에따라 다른함수로 계산하고 싶을때 인자만 바꾸어주면 한번에 바뀌는 코드 변경용이성
	return 0;
}
/*
int (* aaa(void))[2]{					//int(*)[2] aaa (void)
	static int a[2][2] = {10,20,30,40};
	printf("aaa called\n");
	return a;
}

int (*(* bbb(void))(void))[2]{			//int(*)[2] (*)(void) bbb(void)
										//배열포인터를 반환하고 void를 인자로 갖는 함수를 반환하는 bbb(void)함수
	printf("bbb called\n");
	return aaa;
}
int test(int a){
	printf("test called\n");
	return a;
}
int test1(){
	printf("test1 called\n");
	return 5;
}
int (*test2(int a))(){
	printf("test2 called\n");
	if(a>0)
		return test(9);
	else
		return test1();
}
int main(void){
	int i;
	int testnum[2];
	int (*test3[2])(int) = {test};
	int (* temp_test)(int) = test;//함수포인터
	int (*(* temp_a)(void))[2] = aaa ;//int(*)[2] (*)(void) temp_a

	int (*ret)[2];		//int (*ret)[2]		int 배열을 가리키는 포인터!!
						//int *ret[2]		포인터를 요소로하는 배열!
	/////// 1. 맨앞에서 (*를 찾는다
	/////// 2. 맨뒤에서 )~~~를 찾는다
	/////// 3. 1번과 2번을 붙인다
	/////// 4. 1~3을 반복한다.
	int (*(*(*p[][2])(void))(void))[2] = {{bbb, bbb}, {bbb, bbb}};
						//int(*)[2] (*)(void) (*)(void) p[][2];		배열포인터를 반환하는 함수의 주소를 반환하는 함수의 주소를 요소로 갖는 2차원배열
						
						//int (*(*(*p[][2])(void))(void))[2]
						//int (*)[2] (*(*p[][2])(void))(void)
						//int (*)[2] (*)(void) (*p[][2])(void)
						//int (*)[2] (*)(void) (*)(void) p[][2]
	int (*(*(*(*p1)[2])(void))(void))[2] = p;
						//int(*)[2] (*)(void) (*)(void) (*p1)[2];	배열포인터를 반환하는 함수의 주소를 반환하는 함수의 주소를 요소로 갖는 배열을 가리키는 포인터 (배열포인터)
	ret = ((*(*(*(*p1)[2])))()());
						// ret = (*(*(*(*p1)[2])))()()
	
						// ret = (*) (*(*(*p1)[2]))()()
						// ret = (*) (*) (*(*p1)[2])()()
						// ret = (*) (*) (*) (*p1)[2]()()
	ret = (*p1)[0]()();	//함수포인터는 주소에 대한 참조가 없기때문에 '*'을 여러개를 찍어도 같은 값이 나온다.
						//때문에 *을 모두 없애도 같은 값이 참조가되어 실행이 된다.
						//ex)printf("%x, %x, %x\n", &p1[0][0], p1[0][0], *p1[0][0]); 세개의 값이 모두 같은값으로 나온다.
						//값을 참조할때는 형식지정자의 *개수만큼 *을 붙여서 참조하는게 맞다.
						//ex)int **a; (*(*a)) = (int**)calloc(sizeof(int));
						//나의생각: 실제로 함수포인터 변수를 생성할때 리턴값의 *가 앞으로 빠진 이유는 함수로 계산하여 값을 할당할때 리턴값으로 받아오기에 *을 표시하여 연산하라는 명시적
	ret = (*((*p1)[0]))()();

	for(i=0; i<2; i++)
		printf("%d\n", (*ret)[i]);
	ret = temp_a();
	temp_test(5);
	printf("%d, %d\n%d, %d\n", temp_test, *temp_test, test2(1), test2(0));
	printf("%d", test3[0](5));
//	printf("%d, %d\n%d, %d\n", testnum, &testnum, *testnum, **testnum);
	return 0;
}*/
/*
void aaa(void){
	printf("aaa called\n");
}

void test (void){
	aaa();
	printf("test called\n");
	return aaa();
}
											//프로토타입이란? 함수의 생김새
void (* bbb(void(*p)(void)))(void){			// void (*)(void) bbb ( void(*)(void) )
	int t[10]={0};
	printf("%x, %x\n", t, &t);
	if(p == aaa)
		printf("%x, %x\n%x, %x\n", p, &p, aaa, &aaa);	//aaa는 배열과 같이 상수이며 &aaa와 aaa의 값은 똑같다.
														//p는 매개변수로 p는 aaa와 같지만, &p는 p변수의 주소이다.
	p = test;
	printf("bbb called\n");
	return p;
}


int main(void){
	bbb(aaa)();
	//test();
	return 0;
}*/
/*
void aaa(void){
	printf("aaa called\n");
}
int number(void){
	printf("number called\n");
	return 7;
}

void (*bbb(void))(void){	//[void (*) (void) ](리턴값)<- 리턴값이 함수포인터인 함수
							//프로토타입 -> void (*)(void) bbb(void)
	printf("bbb called\n");
	return aaa;
}
void ccc(void(*p)(void)){				//함수포인터를 매개변수로
	printf("ccc:I can call aaa!\n");
	p();
}
int (*ddd(int a))(void){	//프로토타입 -> int (*)(void) ddd(int a)
										//함수포인터를 리턴값으로
	printf("ddd : I can call number\n");
	return number;
}
int main(void){
	bbb()();
	printf("\n");
	ccc(aaa);
	printf("\n");
	ddd(10)();				//앞에 소괄호가 ddd의 매개변수
							//뒤에 소괄호가 number의 매개변수
	return 0;
}
*/
/*
void aaa(void){
	printf("aaa called\n");
}
void bbb(void (*p)(void)){				//인수로 받은 다양한 함수를 실행
	p();							
	printf("bbb called\n");
}
int main(void){
	bbb(aaa);			//함수포인터
						//불시에 일어난 매커니즘을 함수로 처리할때
						//(비동기 알고리즘 <특정한 조건을 맞추어야 동작>)
						//상황에 따라 다양한 함수 호출
						//Event 방식의 동작을 구현&이해할 수 있다. (C나 C++은 함수포인터 필수)
						//interrupt의 동작방식

	return 0;
}
*/