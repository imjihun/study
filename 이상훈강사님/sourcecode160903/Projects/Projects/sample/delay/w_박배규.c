#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int num;
	int i;
	int a=0,b=0,c=0;
	int x=0,y=0,z=0;
	char bnt;
	
	num=rand()%1000;
	if(num<=100){
	a=num/100;
	num=num%100;
	b=num/10;
	num=num%10;
	c=num;

	if(a!=b&&a!=c&&b!=c){
		printf("%d\n",(a*100)+(b*10)+c);
	}
	
	printf("�ڸ��� ����");
	x=(a*100)+(c*10)+b;
	y=(b*100)+(c*10)+a;
	z=(c*100)+(b*10)+a;
	printf("10���ڸ� ����=1,3�ڸ��� ����=2 �Ųٷ�=3\n");
	
	printf("10���ڸ� ����=%d\n",x);
	
	
	printf("3�ڸ��� ����=%d\n",y);

	printf("�Ųٷ�=%d\n",z);
	

	

	}
		
	return 0;

}
