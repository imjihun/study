#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#define MAX 10

int main(void)


{
	int index = 0;
int i;
	
for (index = 0; index < MAX; index++)
{
	i = rand() % 300 * 2 + 100;
	printf("%3d\n", i);
}
	return 0;
	}
