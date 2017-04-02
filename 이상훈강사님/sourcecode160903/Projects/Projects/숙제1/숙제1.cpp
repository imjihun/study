#include <stdio.h>
#include <stdlib.h>
void n1(void){
	int a;
	float b, c;
}
void n2(void){
	int a, b;
	double c, d, e;
}
void n3(void){
	int a=3, b=7;
}
void n4(void){
	double a=3.3, b=7.7, c=37.3;
}
void n5(void){
	char a = 65;
}
void n6(void){
	char a = 97;
	printf("%c", a);//아스키코드 97은 a와 매치됨
}
void n7(void){
	int a=1, b=2, c=3;
	printf("%d, %d, %d", a, b, c);
}
void n8(void){
	double a= 1.1, b=2.2;
	printf("%lf, %lf", a, b);
}
void n9(void){
	int a=1, b=2;
	printf("%d, %d, %d, %d", a+b, a-b, a*b, a/b);
}
void n10(void){
	int a=1, b=2;
	int c=a+b;
	printf("%d", c);
}
void f(void){
	printf("Hello\n");
}
void n11(void){
	f();
}
int n12(int a){
	return a*2;
}
void n13(void){
	int a = n12(3);
	printf("%d", a);
}
float mul(double a, int b){
	return a*b;
}
void n14(void){
	double a;int b;
	scanf("%lf", &a);fflush(stdin);scanf("%d", &b);fflush(stdin);
	printf("%f * %d = %f",a,b, mul(a, b));
}
void bit(int a, int b){
	printf("%d", a<<b);
}
void n15(void){
	bit(1,2);
}
int geta(double a){	return a;}
double getb(double a){ int b=a; return a-b;}
void n16(void){
	double a = 3.75;
	printf("%f -> %d, %f",a, geta(a), getb(a));
}
/////////n17
/*부동소수점
	IEEE 754 국제표준을 따라서
	float은 4바이트 double은 8바이트씩 할당된다.
			(부호/지수부/가수부)
	4바이트 (1/8/23)
	8바이트 (1/11/52)
	부호 : 부호는 음수 또는 양수 둘 중의 하나이므로 1비트만 있으면 된다. 0이 양수이고 1이 음수이다. 이 부호는 실수 자체의 부호만을 나타내며 지수의 부호는 아니다.
	지수 : 지수를 n이라고 했을 때 가수부에 2^n이 곱해진다. 음수 지수도 표현해야 하므로 지수는 자체에 부호를 따로 가져야 하는데 이때는 부호 비트를 따로 쓰지 않고 127의 바이어스를 적용한다. 
		지수의 길이는 8비트이므로 0~255까지의 범위를 가지며 바이어스 127을 적용하면 지수의 표현 범위는 -127~128까지이다. 최소 지수 -127과 최대 지수 128은 0과 무한대를 표현하는 
		특별한 용도로 예약되어 있다. 그래서 float형의 최대 표현 범위는 2^127이며 대략 10^38이 된다.
	가수 : 23개의 비트로 구성되어 있으며 각 자리수에 2의 음수 거듭승으로 가중치가 부여되어 있다. 정규화 규칙에 의해 가수는 항상 이진수 1~2사이(1.~~~)여야 하며 
		이 규칙을 만족하기 위해 제일 왼쪽 비트(2^0자리)는 항상 1이라고 가정한다. 이 비트를 별도로 저장하지 않는 대신 정밀도는 2배 더 높아진다.
*/

/////////n18
/*shortcut
	&& -> 0(거짓)이 나오면 다음 조건비교 실행안하고 거짓으로 판정
	|| -> 1(참)이 나오면 다음 조건비교 실행안하고 참으로 판정
*/

/////////n19
/*x&~(2^y -1)
	x값에 대하여 가장 낮은비트부터 y비트만큼 0으로 set
*/

/////////n20
/*함수순서
	main 함수까지 순차적으로 컴파일되므로 정의나 선언이 main아래에 있으면 감지하지 못한다.
*/

/////////n21
/*변수의 정확한 정의
	입출력 가능한 메모리에 할당된 공간
*/
/////////n22
/*오버플로우 언더플로우
	할당된 메모리를 초과하는 연산
	표현할수있는 최대값을 초과하면 오버플로우
	표현할수있는 최소값보다 내려가면 언더플로우
*/
/////////n24
/*~33 
	00100001
	11011110 = ~33

	2의보수 + 1
*/
/////////n25
/*메모리구조
	stack - 지역변수 함수등을 호출할때 쓰이는 공간
	heap  - 전역변수 동적할당등을 저장할때 쓰이는 공간(주소참조)
	data  - static변수를 저장할 때 쓰이는 공간
	text  - 어셈블코드를 저장할 때 쓰이는 공간
*/
int doit(int a, int b){ return a%b;}
int letsgo(int a, int b){return a+b;}
void n26(void){
	int a=10, b=4;
	printf("%d", doit(a,b)*letsgo(a,b));
}
void n27(void){
	int a, b;
	scanf("%d", &a);
	fflush(stdin);
	scanf("%d", &b);
	fflush(stdin);
	
	printf("->%d", (a<b)*b | (a>b)*a);
}
int n28_1(int a, double b){
	return (int)(a+b);
}
void n28(void){
	printf("%d", n28_1(3, 7.7));
}
double n29_1(int p, int d){
	if(d>=3){
		return p*d*0.8;
	}else
		return p*d;
}
void n29(void){
	printf("%d", (int)n29_1(37500, 7));
}
void n30(int a){
	int i;
	for(i=1;i<=a; i++){
		if(a%i == 0){
			printf("%d ", i);
		}
	}
}
void n31(void){
	int i, sum=0;
	for(i=1; i<=1000; i++){
		if(i%3 == 0)
			sum += i;
	}
	printf("%d", sum);
}
void n32(void){
	int i, sum=0;
	for(i=1; i<=1000; i++){
		if(i%4 == 1 && i%6 == 1)
			sum += i;
	}
	printf("%d", sum);
}
void n33(int cnt){
	printf("%d", cnt*7);
}
/////////n34
/*리틀엔디안 빅엔디안
	리틀엔디안 = 낮은주소에 하위바이트부터 기록 (Intel 계열)
	빅엔디안 = 낮은주소에 상위바이트부터 기록 (Sparc/RISC 계열)(ARM프로세서)
	산술연산유닛(ALU)에서 메모리를 읽는 방식이 메모리 주소가 낮은 쪽에서부터 높은 쪽으로 읽기 때문에 산술 연산의 수행이 더 쉽다. 
*/
/////////n35
/*stack 구조
	
int main(void)
{
00324300  push        ebp  
함수시작전에 ebp값을 보존하기위해 스택에 복사한다.ebp-4
00324301  mov         ebp,esp  
ebp에 esp를 복사함으로써 스택사이즈를 0으로 만든다.
00324303  sub         esp,0E4h  
E4만큼(컴파일된 함수의 일정한 할당량) 이함수에 스택공간을 할당해준다.
00324309  push        ebx  
0032430A  push        esi  
0032430B  push        edi  
각 레지스터가 함수도중에 사용될수도 있으므로 초기값을 스택에 저장한다.
0032430C  lea         edi,[ebp-0E4h]  
00324312  mov         ecx,39h  
00324317  mov         eax,0CCCCCCCCh  
0032431C  rep stos    dword ptr es:[edi]  
eax에 있는 값을 ecx만큼 edi에 저장한다 (edi+4)
	int i, sum =0, result;
00CD431E  mov         dword ptr [sum],0  
값이 할당된 변수는 값을 저장
	for(i=0;i<5;i++)
00CD4325  mov         dword ptr [i],0  
00CD432C  jmp         main+37h (0CD4337h)
i에 0을 저장하고 main함수주소+37h로간다 (i와 5와 비교하는 어셈블리코드 주소->eip에저장)
00CD432E  mov         eax,dword ptr [i]  
00CD4331  add         eax,1  
00CD4334  mov         dword ptr [i],eax  
eax에 연산을위해 i값을집어넣고 +1을 하고 i에 다시 저장한다.
00CD4337  cmp         dword ptr [i],5  
00CD433B  jge         main+48h (0CD4348h)
i와 5를 비교해서 i가 5보다 크거나 같으면 main+48h로 점프한다.(반복문다음코드 주소 -> eip저장)
		sum+=i;
00CD433D  mov         eax,dword ptr [sum]  
00CD4340  add         eax,dword ptr [i]  
00CD4343  mov         dword ptr [sum],eax  
00CD4346  jmp         main+2Eh (0CD432Eh)  
가산연산은 항상 eax에서 일어나기 때문에 eax를 이용하여 연산을하고
반복문처음으로 돌아간다 명령어주소값->eip저장
	result = mult2(sum);
00CD4348  mov         eax,dword ptr [sum]  
00CD434B  push        eax  
스택에 인수를 저장. esp-4
00CD434C  call        mult2 (0CD129Eh)  
함수호출 eip=함수주소값
00CD4351  add         esp,4  
스택에 인수제거
00CD4354  mov         dword ptr [result],eax  
리턴값을 변수에저장
	return 0;
00CD4357  xor         eax,eax  
함수를끝내기위해 eax0으로 초기화하고
}
00CD4359  pop         edi  
00CD435A  pop         esi  
00CD435B  pop         ebx  
함수시작전에 스택에 보존해놨던 레지스터값을 꺼낸다.
00CD435C  add         esp,0E4h  
함수에 할당된 스택구조메모리 해제
00CD4362  cmp         ebp,esp  
함수에 할당된 스택구조메모리가 남아있는지 확인(에러체크)
00CD4364  call        @ILT+420(__RTC_CheckEsp) (0CD11A9h)  
확인후 esp체크함수 콜
00CD4369  mov         esp,ebp  
esp에 ebp를 저장함으로써 이함수에 할당된 스택메모리 완전해제
00CD436B  pop         ebp  
함수시작전에 있었던 스택베이스포인터를 꺼낸다
00CD436C  ret  
호출한 곳으로 돌아간다
///////////////////////////////////
void n32(void){
00CD4260  push        ebp  
00CD4261  mov         ebp,esp  
00CD4263  sub         esp,0D8h  
00CD4269  push        ebx  
00CD426A  push        esi  
00CD426B  push        edi  
00CD426C  lea         edi,[ebp-0D8h]  
00CD4272  mov         ecx,36h  
00CD4277  mov         eax,0CCCCCCCCh  
00CD427C  rep stos    dword ptr es:[edi]  
함수시작전에 ebp저장후 스택시작주소 초기화
함수에 할당된 메모리를 스택포인터로 할당해주고
레지스터 보존후
스택구조로 할당된 메모리 CCCCCCCC로 초기화(10101010은 CPU명령어로 디버깅명령어다)
	int i, sum=0;
00CD427E  mov         dword ptr [sum],0  
메모리에 값할당
	for(i=1; i<=1000; i++){
00CD4285  mov         dword ptr [i],1  
00CD428C  jmp         n32+37h (0CD4297h)  
i에 값할당하고 for문 시작하는 어셈블리코드로 이동 (eip에 명령어시작주소저장)
00CD428E  mov         eax,dword ptr [i]  
00CD4291  add         eax,1  
00CD4294  mov         dword ptr [i],eax  
00CD4297  cmp         dword ptr [i],3E8h  
00CD429E  jg          n32+6Fh (0CD42CFh)  
i에 +1을 하기위해 eax를 이용하여 +1하고, 3E8h(1000)과 비교하여 i가 크면 for문 끝나는 명령어주소로 이동(eip에 끝나는주소저장)
cmp는 실제로 뺄셈연산이다 플래그로 크기비교
		if(i%4 == 1 && i%6 == 1)
00CD42A0  mov         eax,dword ptr [i]  
eax에 i값 저장
00CD42A3  and         eax,80000003h  
00CD42A8  jns         n32+4Fh (0CD42AFh)  
부호 플래그가 1이 아니면(양수이면) 바로 1과 비교를 하기위해 이동.
00CD42AA  dec         eax  
00CD42AB  or          eax,0FFFFFFFCh  
00CD42AE  inc         eax  
부호플래그가 1이면 0으로 초기화를 시켜준다
00CD42AF  cmp         eax,1  
00CD42B2  jne         n32+6Dh (0CD42CDh)  
1과 비교하여 같지 않으면 분기문 빠져나가는 코드주소로 점프(eip=주소값)
00CD42B4  mov         eax,dword ptr [i]  
00CD42B7  cdq  
32비트(ecx)로 나누려면 64비트의 피제수가 필요하다.
따라서 피제수의 크기를 edx:eax로 확장
00CD42B8  mov         ecx,6  
나눗셈을 위한 6을 ecx에 저장
00CD42BD  idiv        eax,ecx  
부호있는 나눗셈을 (eax/ecx) 하여 몫은 eax에 나머지는 adx에 저장
00CD42BF  cmp         edx,1  
00CD42C2  jne         n32+6Dh (0CD42CDh)  
edx와 1과 비교하여 같지 않으면 분기문 빠져나가는 코드주소로 점프(eip=주소값)
			sum += i;
00CD42C4  mov         eax,dword ptr [sum]  
00CD42C7  add         eax,dword ptr [i]  
00CD42CA  mov         dword ptr [sum],eax  
	}
00CD42CD  jmp         n32+2Eh (0CD428Eh)  
for문 시작주소로 점프
	printf("%d", sum);
00CD42CF  mov         esi,esp  
00CD42D1  mov         eax,dword ptr [sum]  
00CD42D4  push        eax  
00CD42D5  push        offset string "%d" (0CD58C0h)  
00CD42DA  call        dword ptr [__imp__printf (0CD82D4h)]  
printf 함수 호출
00CD42E0  add         esp,8  
인수가 두개이므로 add8로 없애준다.
00CD42E3  cmp         esi,esp  
00CD42E5  call        @ILT+420(__RTC_CheckEsp) (0CD11A9h)  
printf함수가 끝난뒤 스택포인터 체크
}
00CD42EA  pop         edi  
00CD42EB  pop         esi  
00CD42EC  pop         ebx  
00CD42ED  add         esp,0D8h  
00CD42F3  cmp         ebp,esp  
00CD42F5  call        @ILT+420(__RTC_CheckEsp) (0CD11A9h)  
00CD42FA  mov         esp,ebp  
00CD42FC  pop         ebp  
레지스터를 원래 값으로 돌리고 스택초기화와 스택포인터 체크를해준다 
00CD42FD  ret  
함수종료리턴
*/
////////no36
/*goto문
	중첩 반복문을 한번에 빠져나갈때 사용하면 유리하다.
	throw동작을 만들수도 있다.
*/
////////no37
/*static 키워드
	지역변수에 사용하면 data영역에 저장되어 함수가 종료되도 값을 사라지지 않게 할수있다.
	전역변수에 사용하면 외부파일에서의 접근을 제한할 수 있다.
*/
void n38(void){
	int i, j, k;
	int max = 9;
	int dan = 3;
	for(i=1; i<=max; i+=dan){
		for(j=1; j<=max; j++){
			for(k=i; k<i+dan; k++)
				printf("%2d*%2d=%2d\t", k, j, k*j);
			printf("\n");
		}
		printf("\n");
	}
}
/////n39
/*for while if switch
	for문 카운트를 세면서 반복돌릴때,
	while 조건값이 해당하는 경우에 반복을 돌릴떄,
	if여러가지조건을 함께 비교할때
	switch여러가지분기로 나뉘는 조건을 비교할때
*/
//////n40
/*디버깅
	break point -> F9 멈추고 변수들의 상태를 보고싶을때
	조사식 -> 조사하고자 싶은 변수를 수동으로 입력
	메모리 -> 메모리주소를 가지고 메모리에 리틀엔디안으로 저장되있는 구조를 직관적으로 볼수있다.
	레지스터 -> 각 레지스터의 상태를 알수있다. 레지스터와 메모리 둘다 어셈블리수준의 디버깅할때 유리하다
*/
void n41(void){
	char a[100];
	int i;
	gets(a);
	for(i=0;i<100 && a[i];i++)
		if(i%2 == 0)
			printf("%c", a[i]);
}
//-----------------
void n42(void){
	int a[10]={3, 77, 10, 7, 4, 9, 1, 8, 21, 33};
	int i, cnt = 10, tmp;
	for(i=0;i<cnt; i++){
		printf("%2d ", a[i]);
	}
	printf("\n");
	for(i=0;i<cnt/2; i++){
		tmp = a[i]; 
		a[i] = a[cnt-i-1];
		a[cnt-i-1] = tmp;
	}
	for(i=0;i<cnt; i++){
		printf("%2d ", a[i]);
	}
}
void n43(void){
	int a[11]={3, 77, 10, 7, 4, 9, 1, 8, 21, 33};
	int sum1=0, sum2=0, i;
	for(i=0; i<10; i++){
		if(i%2)
			sum1 += a[i];
		else
			sum2 += a[i];
	}
	printf("%d", sum1*sum2);
}
void n44(void){
	int a;
	double b;
	printf("정수 : ");
	scanf("%d", &a);
	fflush(stdin);
	printf("실수 : ");
	scanf("%lf", &b);
	fflush(stdin);
	printf("+-> %f\n*-> %d", a+b, (int)(a*b));
}
void n45(void){
	int a = 2004016, i;
	int c = 0xFF;
	char b[5];
	for(i=0; i<4; i++){
		b[i] = a;
		a = a>>8;
	}
	b[i] = '\0';
	printf("%d\n%d, %d, %d, %d", a, b[0], b[1], b[2], b[3]);
}
void n46(void){
	float a = 0.5;
	double b= 0.5;
	return ;
}
/////n46
/*
	float a = 0.5;
0117215E  fld         dword ptr [__real@3f000000 (1177974h)]  
저장된 비트값은	0			01111110				0x23
			부호=0		지수= -1 + bias(2^7-1)	가수=1.000-> 00000 앞에 1을 제거한 23비트
			1비트		8비트					23비트
			
	double b= 0.5;
01172167  fld         qword ptr [__real@3fe0000000000000 (1177848h)]  
저장된 비트값은	0			01111111110				0x52
			부호=0		지수= -1 + bias(2^10-1)	가수=1.000-> 00000 앞에 1을 제거한 23비트
			1비트		11비트					52비트
*/
void n47(void){
	int a=1, b=2, c=3, flag=0;
	int *aa=&a, *bb=&b, *cc=&c, *tmp;
	while(1){
		printf("%d, %d, %d", *aa, *bb, *cc);
		getchar();
		if(flag){
			tmp = aa;
			aa = bb;
			bb = tmp;
			flag = 0;
		}else{
			tmp = cc;
			cc = bb;
			bb = tmp;
			flag = 1;
		}
	}
}
int n48_2(int a){
	return (a*3+4)*(a*3+4);
}
struct n48_1{
	int (*a)(int);
};
void n48(void){
	struct n48_1 *a = (struct n48_1*)calloc(sizeof(struct n48_1), 1);
	int b;
	a->a = n48_2;

	scanf("%d", &b);
	fflush(stdin);

	printf("%d", a->a(b));
}
struct node{
	int data;
	struct node *link;
};
typedef struct node Node;
Node* get_node(){ return (Node*)calloc(sizeof(Node), 1);}
void push(Node **root, int data){
	Node *tmp = (*root);
	tmp = (*root);
	(*root) = get_node();
	(*root)->data = data;
	(*root)->link = tmp;
}
int pop(Node **root){
	Node *tmp = (*root);
	int d = tmp->data;
	(*root) = (*root)->link;
	free(tmp);
	return d;
}
void n49(void){
	Node *root;
	int d[] = {1,2,3,4,5};
	int i;
	for(i=0;i<5;i++){
		push(&root, d[i]);
	}
	for(i=0;i<5;i++){
		printf("%d\n", pop(&root));
	}
}
/////n49
/*	
	1->2->3			<-root	push(4)
	1->2->3->4		<-root	push(5)
	1->2->3->4->5	<-root
	1->2->3->4		<-root	pop()
	1->2->3			<-root	pop()
	1->2			<-root	pop()
	1				<-root	pop()
	NULL			<-root	pop()
*/


Node *enqueue(Node *root, int data){
	if(!root){
		root = get_node();
		root->data = data;
		return root;
	}else{
		root->link = enqueue(root->link, data);
		return root;
	}
}
Node *del_queue(Node *root, int data){
	Node* tmp;
	if(root){
		if(root->data == data){
			tmp = root->link;
			free(root);
			return tmp;
		}else{
			root->link = del_queue(root->link, data);
			return root;
		}
	}
	return root;
}
void print_queue(Node *root){
	if(root){
		printf("%d ", root->data);
		print_queue(root->link);
	}
}
void n50(void){
	Node *root = NULL;
	int i;
	for(i=1;i<6;i++){
		root = enqueue(root, i);
		print_queue(root);
		printf("\n");
	}
	for(i=1;i<6;i++){
		root = del_queue(root, i);
		print_queue(root);
		printf("\n");
	}
}
/////n50
/*
	root->1->2->3->4	enqueue(5)
	root->1->2->3->4->5	enqueue(5)
	root->1->2->4->5	del(3)
*/
int main(void)
{
	n46();
	return 0;
}