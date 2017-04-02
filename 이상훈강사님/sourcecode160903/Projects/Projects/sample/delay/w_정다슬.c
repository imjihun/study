#include <stdio.h>
#include <time.h>
#include <stdlib.h>       //srand

/* W_정다슬.c
	임의의 정수를 10개이상 출력시키는데 3자리의 정수들
	각각의 정수들은 중복이 없어야하고 사용자 요구에 따라 자리수를 변경할수 있어야한다. 
	즉, 3자리수에서 4자리수 등과 같이 백의자리는 부조건 1이상이여야함
*/

int main(void)
{
	int num[10];
	int i, j, k;
	srand((int)time(NULL));

	for(i=0;i<10;i++)
	{
		num[i] = rand()%((999-100))+100;
		for(j=0;j<=i;j++)
		{
			for(k=0;k<=j;k++)
			{
				if(j!=k)
				{
					if(num[j] == num[k])
					{
						i-=1;
						j-=1;
						k-=1;
						num[i] = rand()%((999-100))+100;
					}
				}
			}
		}
	}

	for(i=0;i<=9;i++)
	{
		printf("%d\n",num[i]);
	}

	return 0;
}