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
	printf("%c", a);//�ƽ�Ű�ڵ� 97�� a�� ��ġ��
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
/*�ε��Ҽ���
	IEEE 754 ����ǥ���� ����
	float�� 4����Ʈ double�� 8����Ʈ�� �Ҵ�ȴ�.
			(��ȣ/������/������)
	4����Ʈ (1/8/23)
	8����Ʈ (1/11/52)
	��ȣ : ��ȣ�� ���� �Ǵ� ��� �� ���� �ϳ��̹Ƿ� 1��Ʈ�� ������ �ȴ�. 0�� ����̰� 1�� �����̴�. �� ��ȣ�� �Ǽ� ��ü�� ��ȣ���� ��Ÿ���� ������ ��ȣ�� �ƴϴ�.
	���� : ������ n�̶�� ���� �� �����ο� 2^n�� ��������. ���� ������ ǥ���ؾ� �ϹǷ� ������ ��ü�� ��ȣ�� ���� ������ �ϴµ� �̶��� ��ȣ ��Ʈ�� ���� ���� �ʰ� 127�� ���̾�� �����Ѵ�. 
		������ ���̴� 8��Ʈ�̹Ƿ� 0~255������ ������ ������ ���̾ 127�� �����ϸ� ������ ǥ�� ������ -127~128�����̴�. �ּ� ���� -127�� �ִ� ���� 128�� 0�� ���Ѵ븦 ǥ���ϴ� 
		Ư���� �뵵�� ����Ǿ� �ִ�. �׷��� float���� �ִ� ǥ�� ������ 2^127�̸� �뷫 10^38�� �ȴ�.
	���� : 23���� ��Ʈ�� �����Ǿ� ������ �� �ڸ����� 2�� ���� �ŵ������ ����ġ�� �ο��Ǿ� �ִ�. ����ȭ ��Ģ�� ���� ������ �׻� ������ 1~2����(1.~~~)���� �ϸ� 
		�� ��Ģ�� �����ϱ� ���� ���� ���� ��Ʈ(2^0�ڸ�)�� �׻� 1�̶�� �����Ѵ�. �� ��Ʈ�� ������ �������� �ʴ� ��� ���е��� 2�� �� ��������.
*/

/////////n18
/*shortcut
	&& -> 0(����)�� ������ ���� ���Ǻ� ������ϰ� �������� ����
	|| -> 1(��)�� ������ ���� ���Ǻ� ������ϰ� ������ ����
*/

/////////n19
/*x&~(2^y -1)
	x���� ���Ͽ� ���� ������Ʈ���� y��Ʈ��ŭ 0���� set
*/

/////////n20
/*�Լ�����
	main �Լ����� ���������� �����ϵǹǷ� ���ǳ� ������ main�Ʒ��� ������ �������� ���Ѵ�.
*/

/////////n21
/*������ ��Ȯ�� ����
	����� ������ �޸𸮿� �Ҵ�� ����
*/
/////////n22
/*�����÷ο� ����÷ο�
	�Ҵ�� �޸𸮸� �ʰ��ϴ� ����
	ǥ���Ҽ��ִ� �ִ밪�� �ʰ��ϸ� �����÷ο�
	ǥ���Ҽ��ִ� �ּҰ����� �������� ����÷ο�
*/
/////////n24
/*~33 
	00100001
	11011110 = ~33

	2�Ǻ��� + 1
*/
/////////n25
/*�޸𸮱���
	stack - �������� �Լ����� ȣ���Ҷ� ���̴� ����
	heap  - �������� �����Ҵ���� �����Ҷ� ���̴� ����(�ּ�����)
	data  - static������ ������ �� ���̴� ����
	text  - ������ڵ带 ������ �� ���̴� ����
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
/*��Ʋ����� �򿣵��
	��Ʋ����� = �����ּҿ� ��������Ʈ���� ��� (Intel �迭)
	�򿣵�� = �����ּҿ� ��������Ʈ���� ��� (Sparc/RISC �迭)(ARM���μ���)
	�����������(ALU)���� �޸𸮸� �д� ����� �޸� �ּҰ� ���� �ʿ������� ���� ������ �б� ������ ��� ������ ������ �� ����. 
*/
/////////n35
/*stack ����
	
int main(void)
{
00324300  push        ebp  
�Լ��������� ebp���� �����ϱ����� ���ÿ� �����Ѵ�.ebp-4
00324301  mov         ebp,esp  
ebp�� esp�� ���������ν� ���û���� 0���� �����.
00324303  sub         esp,0E4h  
E4��ŭ(�����ϵ� �Լ��� ������ �Ҵ緮) ���Լ��� ���ð����� �Ҵ����ش�.
00324309  push        ebx  
0032430A  push        esi  
0032430B  push        edi  
�� �������Ͱ� �Լ����߿� ���ɼ��� �����Ƿ� �ʱⰪ�� ���ÿ� �����Ѵ�.
0032430C  lea         edi,[ebp-0E4h]  
00324312  mov         ecx,39h  
00324317  mov         eax,0CCCCCCCCh  
0032431C  rep stos    dword ptr es:[edi]  
eax�� �ִ� ���� ecx��ŭ edi�� �����Ѵ� (edi+4)
	int i, sum =0, result;
00CD431E  mov         dword ptr [sum],0  
���� �Ҵ�� ������ ���� ����
	for(i=0;i<5;i++)
00CD4325  mov         dword ptr [i],0  
00CD432C  jmp         main+37h (0CD4337h)
i�� 0�� �����ϰ� main�Լ��ּ�+37h�ΰ��� (i�� 5�� ���ϴ� ������ڵ� �ּ�->eip������)
00CD432E  mov         eax,dword ptr [i]  
00CD4331  add         eax,1  
00CD4334  mov         dword ptr [i],eax  
eax�� ���������� i��������ְ� +1�� �ϰ� i�� �ٽ� �����Ѵ�.
00CD4337  cmp         dword ptr [i],5  
00CD433B  jge         main+48h (0CD4348h)
i�� 5�� ���ؼ� i�� 5���� ũ�ų� ������ main+48h�� �����Ѵ�.(�ݺ��������ڵ� �ּ� -> eip����)
		sum+=i;
00CD433D  mov         eax,dword ptr [sum]  
00CD4340  add         eax,dword ptr [i]  
00CD4343  mov         dword ptr [sum],eax  
00CD4346  jmp         main+2Eh (0CD432Eh)  
���꿬���� �׻� eax���� �Ͼ�� ������ eax�� �̿��Ͽ� �������ϰ�
�ݺ���ó������ ���ư��� ��ɾ��ּҰ�->eip����
	result = mult2(sum);
00CD4348  mov         eax,dword ptr [sum]  
00CD434B  push        eax  
���ÿ� �μ��� ����. esp-4
00CD434C  call        mult2 (0CD129Eh)  
�Լ�ȣ�� eip=�Լ��ּҰ�
00CD4351  add         esp,4  
���ÿ� �μ�����
00CD4354  mov         dword ptr [result],eax  
���ϰ��� ����������
	return 0;
00CD4357  xor         eax,eax  
�Լ������������� eax0���� �ʱ�ȭ�ϰ�
}
00CD4359  pop         edi  
00CD435A  pop         esi  
00CD435B  pop         ebx  
�Լ��������� ���ÿ� �����س��� �������Ͱ��� ������.
00CD435C  add         esp,0E4h  
�Լ��� �Ҵ�� ���ñ����޸� ����
00CD4362  cmp         ebp,esp  
�Լ��� �Ҵ�� ���ñ����޸𸮰� �����ִ��� Ȯ��(����üũ)
00CD4364  call        @ILT+420(__RTC_CheckEsp) (0CD11A9h)  
Ȯ���� espüũ�Լ� ��
00CD4369  mov         esp,ebp  
esp�� ebp�� ���������ν� ���Լ��� �Ҵ�� ���ø޸� ��������
00CD436B  pop         ebp  
�Լ��������� �־��� ���ú��̽������͸� ������
00CD436C  ret  
ȣ���� ������ ���ư���
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
�Լ��������� ebp������ ���ý����ּ� �ʱ�ȭ
�Լ��� �Ҵ�� �޸𸮸� ���������ͷ� �Ҵ����ְ�
�������� ������
���ñ����� �Ҵ�� �޸� CCCCCCCC�� �ʱ�ȭ(10101010�� CPU��ɾ�� ������ɾ��)
	int i, sum=0;
00CD427E  mov         dword ptr [sum],0  
�޸𸮿� ���Ҵ�
	for(i=1; i<=1000; i++){
00CD4285  mov         dword ptr [i],1  
00CD428C  jmp         n32+37h (0CD4297h)  
i�� ���Ҵ��ϰ� for�� �����ϴ� ������ڵ�� �̵� (eip�� ��ɾ�����ּ�����)
00CD428E  mov         eax,dword ptr [i]  
00CD4291  add         eax,1  
00CD4294  mov         dword ptr [i],eax  
00CD4297  cmp         dword ptr [i],3E8h  
00CD429E  jg          n32+6Fh (0CD42CFh)  
i�� +1�� �ϱ����� eax�� �̿��Ͽ� +1�ϰ�, 3E8h(1000)�� ���Ͽ� i�� ũ�� for�� ������ ��ɾ��ּҷ� �̵�(eip�� �������ּ�����)
cmp�� ������ ���������̴� �÷��׷� ũ���
		if(i%4 == 1 && i%6 == 1)
00CD42A0  mov         eax,dword ptr [i]  
eax�� i�� ����
00CD42A3  and         eax,80000003h  
00CD42A8  jns         n32+4Fh (0CD42AFh)  
��ȣ �÷��װ� 1�� �ƴϸ�(����̸�) �ٷ� 1�� �񱳸� �ϱ����� �̵�.
00CD42AA  dec         eax  
00CD42AB  or          eax,0FFFFFFFCh  
00CD42AE  inc         eax  
��ȣ�÷��װ� 1�̸� 0���� �ʱ�ȭ�� �����ش�
00CD42AF  cmp         eax,1  
00CD42B2  jne         n32+6Dh (0CD42CDh)  
1�� ���Ͽ� ���� ������ �б⹮ ���������� �ڵ��ּҷ� ����(eip=�ּҰ�)
00CD42B4  mov         eax,dword ptr [i]  
00CD42B7  cdq  
32��Ʈ(ecx)�� �������� 64��Ʈ�� �������� �ʿ��ϴ�.
���� �������� ũ�⸦ edx:eax�� Ȯ��
00CD42B8  mov         ecx,6  
�������� ���� 6�� ecx�� ����
00CD42BD  idiv        eax,ecx  
��ȣ�ִ� �������� (eax/ecx) �Ͽ� ���� eax�� �������� adx�� ����
00CD42BF  cmp         edx,1  
00CD42C2  jne         n32+6Dh (0CD42CDh)  
edx�� 1�� ���Ͽ� ���� ������ �б⹮ ���������� �ڵ��ּҷ� ����(eip=�ּҰ�)
			sum += i;
00CD42C4  mov         eax,dword ptr [sum]  
00CD42C7  add         eax,dword ptr [i]  
00CD42CA  mov         dword ptr [sum],eax  
	}
00CD42CD  jmp         n32+2Eh (0CD428Eh)  
for�� �����ּҷ� ����
	printf("%d", sum);
00CD42CF  mov         esi,esp  
00CD42D1  mov         eax,dword ptr [sum]  
00CD42D4  push        eax  
00CD42D5  push        offset string "%d" (0CD58C0h)  
00CD42DA  call        dword ptr [__imp__printf (0CD82D4h)]  
printf �Լ� ȣ��
00CD42E0  add         esp,8  
�μ��� �ΰ��̹Ƿ� add8�� �����ش�.
00CD42E3  cmp         esi,esp  
00CD42E5  call        @ILT+420(__RTC_CheckEsp) (0CD11A9h)  
printf�Լ��� ������ ���������� üũ
}
00CD42EA  pop         edi  
00CD42EB  pop         esi  
00CD42EC  pop         ebx  
00CD42ED  add         esp,0D8h  
00CD42F3  cmp         ebp,esp  
00CD42F5  call        @ILT+420(__RTC_CheckEsp) (0CD11A9h)  
00CD42FA  mov         esp,ebp  
00CD42FC  pop         ebp  
�������͸� ���� ������ ������ �����ʱ�ȭ�� ���������� üũ�����ش� 
00CD42FD  ret  
�Լ����Ḯ��
*/
////////no36
/*goto��
	��ø �ݺ����� �ѹ��� ���������� ����ϸ� �����ϴ�.
	throw������ ������� �ִ�.
*/
////////no37
/*static Ű����
	���������� ����ϸ� data������ ����Ǿ� �Լ��� ����ǵ� ���� ������� �ʰ� �Ҽ��ִ�.
	���������� ����ϸ� �ܺ����Ͽ����� ������ ������ �� �ִ�.
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
	for�� ī��Ʈ�� ���鼭 �ݺ�������,
	while ���ǰ��� �ش��ϴ� ��쿡 �ݺ��� ������,
	if�������������� �Բ� ���Ҷ�
	switch���������б�� ������ ������ ���Ҷ�
*/
//////n40
/*�����
	break point -> F9 ���߰� �������� ���¸� ���������
	����� -> �����ϰ��� ���� ������ �������� �Է�
	�޸� -> �޸��ּҸ� ������ �޸𸮿� ��Ʋ��������� ������ִ� ������ ���������� �����ִ�.
	�������� -> �� ���������� ���¸� �˼��ִ�. �������Ϳ� �޸� �Ѵ� ����������� ������Ҷ� �����ϴ�
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
	printf("���� : ");
	scanf("%d", &a);
	fflush(stdin);
	printf("�Ǽ� : ");
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
����� ��Ʈ����	0			01111110				0x23
			��ȣ=0		����= -1 + bias(2^7-1)	����=1.000-> 00000 �տ� 1�� ������ 23��Ʈ
			1��Ʈ		8��Ʈ					23��Ʈ
			
	double b= 0.5;
01172167  fld         qword ptr [__real@3fe0000000000000 (1177848h)]  
����� ��Ʈ����	0			01111111110				0x52
			��ȣ=0		����= -1 + bias(2^10-1)	����=1.000-> 00000 �տ� 1�� ������ 23��Ʈ
			1��Ʈ		11��Ʈ					52��Ʈ
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