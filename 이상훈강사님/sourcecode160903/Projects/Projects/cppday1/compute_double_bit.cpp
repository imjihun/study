#include <stdio.h>

void compute_double_bit(char *val, int size)
{
	int i=0, j=0;
	unsigned short comp = 0;

	printf("val = ");

	for(i=size-1; i>=0; i--)
	{
		comp = 128;
		for(j=1; j<=8; j++)
		{
			printf("%d", val[i] & comp ? 1 : 0);
			if(i == 7 && j == 1)
				printf(" ");
			if(i == 6 && j == 4)
				printf(" ");
			comp >>= 1;
		}
	}
	printf("\n");
}