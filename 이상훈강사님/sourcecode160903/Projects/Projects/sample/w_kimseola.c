#include <stdio.h>
#include <stdlib.h>


int main(void){

	int rdNum=0;
	int m = 10; //10���� ����
	int n;
	int j;
	int k=3; //�ڸ���

	for(m=0;m<10;m++){
		rdNum=rand()%9+1;
		for(n=1;n<k; n++){
		
			j=rand()%10;
			if(j!=rdNum){
				rdNum = rdNum*10 + j;
			}

		}
		printf("%d\n",rdNum);
	}
	




	return 0;
}