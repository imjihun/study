#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int a,b,c,count;
	

		for(count=0;count<20;count++)
		{
		a = rand()%10;
		b = rand()%10;
		c = rand()%10;
		if (a>=1)
			{
			if (!(a==b||b==c||c==a))
				{
				printf("%d%d%d\n",a,b,c);
				}
	
			}
		}
	return 0;
}

// 10개 출력 됬을때 브레이크?