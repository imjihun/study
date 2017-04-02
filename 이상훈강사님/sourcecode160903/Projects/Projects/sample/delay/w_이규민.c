#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int a, b, c;
	int count=0;
	int input;

	srand(time(NULL));

	printf("정수 몇개 출력 ? ");
	scanf("%d", &input);

	while(count<input)
	{
			
		a = (rand() % 9) +1;
		b = rand() % 10;
		c = rand() % 10;

		if(a != b || a != c || b != c)
		{
			printf("%d", a);
			printf("%d", b);
			printf("%d", c);

			printf("\n");

			count++;
		}
		else
		{
			if(a == b || a == c)
			{
				a = (rand() % 9) +1;
			}
			else if(b == a || b == c)
			{
				b = rand() % 10;
			}
			else
			{
				c = rand() % 10;
			}

		}
	}
	
}