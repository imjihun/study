#include <stdio.h>
#include <stdlib.h>


int main(void)

{

	int i=0 , num=0;
	int rand_num;
	
	

	while(i<10){	
		rand_num = rand();
		if(rand_num/100 != rand_num%10  &&  (rand_num- ((rand_num/100)*100)) != (rand_num%10)  && rand_num/100 !=(rand_num- ((rand_num/100)*100))  ){// 자리 비교...잘모르겠습니다.

		if(100<rand_num && rand_num<1000)
		{
	


		printf("%3d \n",rand_num);
		i++;


		}
	}
	}

	return 0;


}