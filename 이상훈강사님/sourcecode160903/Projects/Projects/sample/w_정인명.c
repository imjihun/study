/*

1. 연속해서 실행할 내용
2. 변하는 것과 변하지 않는 것
3. 어떻게 변하고 그 영향은 무엇인가
4. 언제까지 실행되어야 하는가.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void main(void)
{
	int num,flag=0; // num은 랜덤값 받는곳, flag는 출력된 3자리 정수가 10개 인지를 체크해 while문을 나가기 위한용도
	int first,second,third; // 각자리수를 담기위한 변수
	srand((int)time(NULL)); // 완전한 랜덤을 위해
	while(flag!=10) // 출력된 수가 10개가 될때까지 계속 while문 실행
	{
		num=rand()%1000;
		if(num/100!=0) // 첫째자리가 0이 아닐때만 뒤에코드를 실행
		{
			first = num/100; // num의 첫째 자리를 first에 담음
			num = num%100;   // num의 백의자리수를 없애줌
			second = num/10; // num의 둘째 자리를 second에 담음
			num = num%10;    // num의 둘째자리수를 없애줌
			third = num;	 // num의 마지막 자리수를 third에 담음

			if(first!=second&&first!=third) // 첫째자리수가 둘째자리나 셋째자리수와 같지 않다면
				if(second!=third)           // 둘째자리수가 셋째자리수와 같지 않다면
				{
					printf("%d%d%d\n",first,second,third); // 결국 이수는 각자리수와 중복되지 않은순수한수가 된다
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