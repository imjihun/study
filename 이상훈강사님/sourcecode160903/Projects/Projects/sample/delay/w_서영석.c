#include <stdio.h>

int main (void){
	
	int i;
	int a=3;
	int b=5;
	int c=7;

		for(i=1;i<=10;++i){
			a=a%10;b=b%10;c=c%10;
			printf("%d%d%d\n",a,b,c);{
			}
			a=a+2;
			b=b+2;
			c=c+2;
		}
	return 0;
}