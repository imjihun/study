#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	int	cipher;				// 자릿수 변수;

	int i, j;					//

	int integer = 10;		// 출력하고자 하는 최대 갯수
	int random;				//임의의 정수를 의미하는 랜덤함수

	cipher = 3;

	for(j=0; j<integer; j++)
	{
		random = rand();
		printf("%d \n", random);
	}
}