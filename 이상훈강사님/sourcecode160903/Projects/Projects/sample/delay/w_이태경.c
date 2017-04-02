
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10

	
	
int main (void){
	int index = 0;
	int asd = 0;
	

	srand(time(NULL));
	printf("ddd\n");
	for(asd=0; asd<MAX; asd++)
	{
		printf("%d",rand());
			
	}
	printf("_____________________________________________________\n");
	printf("임의의 정수 10개를 출력\n");
		for(index = 0; index <MAX ; index++){
			
			printf("%d",rand()%1000);
			printf("\n");
			
		}



	return 0;

}

