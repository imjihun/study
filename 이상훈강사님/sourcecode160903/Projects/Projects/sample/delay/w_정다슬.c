#include <stdio.h>
#include <time.h>
#include <stdlib.h>       //srand

/* W_���ٽ�.c
	������ ������ 10���̻� ��½�Ű�µ� 3�ڸ��� ������
	������ �������� �ߺ��� ������ϰ� ����� �䱸�� ���� �ڸ����� �����Ҽ� �־���Ѵ�. 
	��, 3�ڸ������� 4�ڸ��� ��� ���� �����ڸ��� ������ 1�̻��̿�����
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