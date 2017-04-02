#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char* a[] = {"apple", "banana", "peach", "mango", "watermelon", "cherry", "strawberry"};
	int i, j, cnt=0;
	int sum=0;
	int sumcol[10] = {0};

	for(i=0; i<7; i++){
		for(j=0; j<strlen(a[i]); j++){
			printf("%d+", a[i][j]);
			sum += a[i][j];
			sumcol[j] += a[i][j];
		}
		printf("\t%d\n", sum);
		sum=0;
	}
	for(i=0; i<10; i++)
		printf("%d ", sumcol[i]);
	
	printf("\n");
}




