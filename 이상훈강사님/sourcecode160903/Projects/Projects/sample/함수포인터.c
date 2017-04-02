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
					//�߰����� �Լ������� ���
					//ex) num = pof2(a,b); ret = pof_test_main(num); -> pof2�Լ��� �������� ����Ǿ� ���� ������, pof_test_main �����߿� pof2�� �Լ��� ���� ����Ŵ
					//					   ret = pof_test_main(pof2);-> pof2�Լ��� �������� ����Ǿ� ���� �ʾƵ�, pof_test_main �����߿� pof2�� �Լ� ���డ��. �׸��� ���� �ڵ忡���� �ٸ��Լ��� ����ϰ� ������ ���ڸ� �ٲپ��ָ� �ѹ��� �ٲ�� �ڵ� ������̼�
	return 0;
}
/*
int (* aaa(void))[2]{					//int(*)[2] aaa (void)
	static int a[2][2] = {10,20,30,40};
	printf("aaa called\n");
	return a;
}

int (*(* bbb(void))(void))[2]{			//int(*)[2] (*)(void) bbb(void)
										//�迭�����͸� ��ȯ�ϰ� void�� ���ڷ� ���� �Լ��� ��ȯ�ϴ� bbb(void)�Լ�
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
	int (* temp_test)(int) = test;//�Լ�������
	int (*(* temp_a)(void))[2] = aaa ;//int(*)[2] (*)(void) temp_a

	int (*ret)[2];		//int (*ret)[2]		int �迭�� ����Ű�� ������!!
						//int *ret[2]		�����͸� ��ҷ��ϴ� �迭!
	/////// 1. �Ǿտ��� (*�� ã�´�
	/////// 2. �ǵڿ��� )~~~�� ã�´�
	/////// 3. 1���� 2���� ���δ�
	/////// 4. 1~3�� �ݺ��Ѵ�.
	int (*(*(*p[][2])(void))(void))[2] = {{bbb, bbb}, {bbb, bbb}};
						//int(*)[2] (*)(void) (*)(void) p[][2];		�迭�����͸� ��ȯ�ϴ� �Լ��� �ּҸ� ��ȯ�ϴ� �Լ��� �ּҸ� ��ҷ� ���� 2�����迭
						
						//int (*(*(*p[][2])(void))(void))[2]
						//int (*)[2] (*(*p[][2])(void))(void)
						//int (*)[2] (*)(void) (*p[][2])(void)
						//int (*)[2] (*)(void) (*)(void) p[][2]
	int (*(*(*(*p1)[2])(void))(void))[2] = p;
						//int(*)[2] (*)(void) (*)(void) (*p1)[2];	�迭�����͸� ��ȯ�ϴ� �Լ��� �ּҸ� ��ȯ�ϴ� �Լ��� �ּҸ� ��ҷ� ���� �迭�� ����Ű�� ������ (�迭������)
	ret = ((*(*(*(*p1)[2])))()());
						// ret = (*(*(*(*p1)[2])))()()
	
						// ret = (*) (*(*(*p1)[2]))()()
						// ret = (*) (*) (*(*p1)[2])()()
						// ret = (*) (*) (*) (*p1)[2]()()
	ret = (*p1)[0]()();	//�Լ������ʹ� �ּҿ� ���� ������ ���⶧���� '*'�� �������� �� ���� ���� ���´�.
						//������ *�� ��� ���ֵ� ���� ���� �������Ǿ� ������ �ȴ�.
						//ex)printf("%x, %x, %x\n", &p1[0][0], p1[0][0], *p1[0][0]); ������ ���� ��� ���������� ���´�.
						//���� �����Ҷ��� ������������ *������ŭ *�� �ٿ��� �����ϴ°� �´�.
						//ex)int **a; (*(*a)) = (int**)calloc(sizeof(int));
						//���ǻ���: ������ �Լ������� ������ �����Ҷ� ���ϰ��� *�� ������ ���� ������ �Լ��� ����Ͽ� ���� �Ҵ��Ҷ� ���ϰ����� �޾ƿ��⿡ *�� ǥ���Ͽ� �����϶�� �����
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
											//������Ÿ���̶�? �Լ��� �����
void (* bbb(void(*p)(void)))(void){			// void (*)(void) bbb ( void(*)(void) )
	int t[10]={0};
	printf("%x, %x\n", t, &t);
	if(p == aaa)
		printf("%x, %x\n%x, %x\n", p, &p, aaa, &aaa);	//aaa�� �迭�� ���� ����̸� &aaa�� aaa�� ���� �Ȱ���.
														//p�� �Ű������� p�� aaa�� ������, &p�� p������ �ּ��̴�.
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

void (*bbb(void))(void){	//[void (*) (void) ](���ϰ�)<- ���ϰ��� �Լ��������� �Լ�
							//������Ÿ�� -> void (*)(void) bbb(void)
	printf("bbb called\n");
	return aaa;
}
void ccc(void(*p)(void)){				//�Լ������͸� �Ű�������
	printf("ccc:I can call aaa!\n");
	p();
}
int (*ddd(int a))(void){	//������Ÿ�� -> int (*)(void) ddd(int a)
										//�Լ������͸� ���ϰ�����
	printf("ddd : I can call number\n");
	return number;
}
int main(void){
	bbb()();
	printf("\n");
	ccc(aaa);
	printf("\n");
	ddd(10)();				//�տ� �Ұ�ȣ�� ddd�� �Ű�����
							//�ڿ� �Ұ�ȣ�� number�� �Ű�����
	return 0;
}
*/
/*
void aaa(void){
	printf("aaa called\n");
}
void bbb(void (*p)(void)){				//�μ��� ���� �پ��� �Լ��� ����
	p();							
	printf("bbb called\n");
}
int main(void){
	bbb(aaa);			//�Լ�������
						//�ҽÿ� �Ͼ ��Ŀ������ �Լ��� ó���Ҷ�
						//(�񵿱� �˰��� <Ư���� ������ ���߾�� ����>)
						//��Ȳ�� ���� �پ��� �Լ� ȣ��
						//Event ����� ������ ����&������ �� �ִ�. (C�� C++�� �Լ������� �ʼ�)
						//interrupt�� ���۹��

	return 0;
}
*/