#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	int	cipher;				// �ڸ��� ����;

	int i, j;					//

	int integer = 10;		// ����ϰ��� �ϴ� �ִ� ����
	int random;				//������ ������ �ǹ��ϴ� �����Լ�

	cipher = 3;

	for(j=0; j<integer; j++)
	{
		random = rand();
		printf("%d \n", random);
	}
}