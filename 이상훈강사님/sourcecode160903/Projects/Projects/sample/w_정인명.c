/*

1. �����ؼ� ������ ����
2. ���ϴ� �Ͱ� ������ �ʴ� ��
3. ��� ���ϰ� �� ������ �����ΰ�
4. �������� ����Ǿ�� �ϴ°�.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void main(void)
{
	int num,flag=0; // num�� ������ �޴°�, flag�� ��µ� 3�ڸ� ������ 10�� ������ üũ�� while���� ������ ���ѿ뵵
	int first,second,third; // ���ڸ����� ������� ����
	srand((int)time(NULL)); // ������ ������ ����
	while(flag!=10) // ��µ� ���� 10���� �ɶ����� ��� while�� ����
	{
		num=rand()%1000;
		if(num/100!=0) // ù°�ڸ��� 0�� �ƴҶ��� �ڿ��ڵ带 ����
		{
			first = num/100; // num�� ù° �ڸ��� first�� ����
			num = num%100;   // num�� �����ڸ����� ������
			second = num/10; // num�� ��° �ڸ��� second�� ����
			num = num%10;    // num�� ��°�ڸ����� ������
			third = num;	 // num�� ������ �ڸ����� third�� ����

			if(first!=second&&first!=third) // ù°�ڸ����� ��°�ڸ��� ��°�ڸ����� ���� �ʴٸ�
				if(second!=third)           // ��°�ڸ����� ��°�ڸ����� ���� �ʴٸ�
				{
					printf("%d%d%d\n",first,second,third); // �ᱹ �̼��� ���ڸ����� �ߺ����� ���������Ѽ��� �ȴ�
					flag++;
				}
		}
	}

	/*
	int yIndex,xIndex;
	int x,y;
	x = 10;
	y = 10;
	while(1)
	{
		for(yIndex=0;yIndex<20;++yIndex)
		{
			for(xIndex=0;xIndex<20;++xIndex)
			{
				printf("%s",(!(x==xIndex&&y==yIndex))?"  ":"@");
			}
			printf("\n");
		}
		system("cls");
		x = rand()%20;
		y = rand()%20;
	}
	*/


	/*
	for(xIndex=0; xIndex<=19; ++xIndex)
		printf("%2d",xIndex);
	printf("\n");

	for(xIndex=0; xIndex<=19; ++xIndex)
	{
		if(xIndex==3)
			printf("@");
		else
			printf("  ",xIndex);
	}
	printf("\n");
	*/
}