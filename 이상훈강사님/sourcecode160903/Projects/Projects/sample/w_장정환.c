#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (void)
{
	int i,j;
	int num=0;//°ª
	double digit=10;
	int count,count_max=10;//È½¼ö
	int max=3;//ÀÚ¸´¼ö
	int x[10];//Ä¡È¯°ª
	for(count=0;count<count_max;count++)
	{
	for(i=0;i<max;i++)
	{
		x[i]=rand()%10;
	}
		while(1)
		{
			if(x[max]==0)
			x[max]=rand()%10;
			else
			break;
		}
	while(1){
	for(i=0;i<max;i++)
	{
		for(j=i+1;j<max;j++)
		{
			if(x[i]==x[j])
				x[j]=rand()%10;
	}	
	}
	break;
		}
	for(i=0;i<max;i++)
	{
		num=num+x[i]*pow(digit,i);
	}
	printf("%d\n",num);
		num=0;
	}
	return 0;
}