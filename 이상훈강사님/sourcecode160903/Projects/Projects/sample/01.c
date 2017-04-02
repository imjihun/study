#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
	임의의 정수를 10개이상 출력하라
	3자리의 정수들
	각각의 정수들은 각각의 자리수가 중복없는 정수여야 한다.(정수끼리는 중복가능)
	사용자 요구에 따라서는 자리수를 변경할수 있어야한다.
*/
/*#include<stdio.h>
#include<stdlib.h>
#define cnt 10

int get_RandomNumber(int unit);
int main(void){
	int number;
	int getUnit=-1, i;
	
	printf("출력할 1~9까지의 자리수를 입력하라 : ");
	while (getUnit<1 || getUnit>9){
		getUnit = getc(stdin)-'0';
		fflush(stdin);
	}
	
	printf("\n");
	for(i=0; i<cnt; i++){
		number = get_RandomNumber(getUnit);
		printf("%d", number);
		printf("\n");
	}
}

int get_RandomNumber(int unit){
	int k, j;
	int dRandom;
	int result=0;
	int *number = (int*)malloc(sizeof(int)*unit);

	for(k=0; k<unit; k++){
		dRandom = rand()%10;
		if(k==0 && dRandom==0)
			k--;
		else{
			number[k] = dRandom;
			for(j=0; j<k; j++){
				if( number[j] == number[k]){
					k--;
					break;
				}
			}
		}
	}

	for (k=0; k<unit; k++){
		result = result*10 + number[k];
	}
	free(number);

	return result;
}
*/
int main(void){
	int dRandom, number[10];
	int getUnit=-1, i, k, j, cnt=10;
	
	while (getUnit<0 || getUnit>9){
		getUnit = getc(stdin)-'0';
		fflush(stdin);
	}
	
	for(i=0; i<cnt; i++){
		for(k=0; k<10; k++)
			number[i] = 0;

		for(k=0; k<getUnit; k++){
			dRandom = rand()%10;
			if(k==0 && dRandom==0)
				k--;
			else{
				number[k] = dRandom;
				for(j=0; j<k; j++){
					if( number[j] == number[k]){
						k--;
						break;
					}
				}
			}
		}
		for(k=0; k<getUnit; k++){
			printf("%d", number[k]);
		}
		printf("\n");
	}
}


/*
int xIndex, yIndex;
int k[4];
int i;

k[0]=0; k[1]=-38; k[2]=0; k[3]=0;
while(1){
	for(yIndex = 0; yIndex<20; yIndex++){
		for(xIndex = 0; xIndex<20; xIndex++){
			printf("%s",!(
				-yIndex==xIndex+k[0]||
				-yIndex==xIndex+k[1] ||
				-yIndex==-xIndex+k[2] ||
				-yIndex==-xIndex+k[3])
				?"  ":"■");
		}
		printf("\n");
	}// 20x20 출력
	//x = rand()%20;
	//y = rand()%20;
	if(k[0]==-10 && k[1]==-28 && k[2]==-10 && k[3]==10){}
	else{
		k[0]-=1;k[1]+=1;k[2]-=1;k[3]+=1;
		if(k[0]<-37)
			k[0]=0;
		if(k[1]>-1)
			k[1]=-38;
		if(k[2]<-18)
			k[2]=19;
		if(k[3]>18)
			k[3]=-19;
	}
	system("cls");
}//while(1)
return 0;
*/
/*

	int cnt_row=2;
	int s=2, e=19, c=9;
	int i, j, k;
	for(i=s; i<=e && cnt_row>0; i+=cnt_row){
		for(j=1; j<=c; j++){
			for(k=i; k<i+cnt_row && k<=e; k++)
				printf ("%2d * %2d = %4d     ", k, j, k*j);
			putc('\n', stdout);
		}
		putc('\n',stdout);
	}

	return 0;
	*/
/*

	char ch;
	int num = 0;
	int cnt = 0;
	int digit=1;
	int i;

	while((ch = getc(stdin)) != EOF){
		if ( ch >= '0' && ch <= '9'){//숫자면
			num = num*10 + (ch - '0');
			cnt++;
		}else{
			break;
		}
	}//end while()

	for(i=0; i<cnt-1; i++){
		digit *= 10;
	}
	while (digit >=1){
		putc(num/digit + '0', stdout);
		num = num-num/digit*digit;
		digit /=10;
	}

	return 0;
	*/

/*
	char ch;
	//출력한다. 문자를. 모니터로
	putc('A', stdout);
	putchar('B');

	//입력한다. 문자를. 키보드에서
	ch = getc(stdin);
	putchar(ch);// 변수에 저장된 값을 전달
	ch = getc(stdin);
	putchar(ch);// 변수에 저장된 값을 전달
	ch = getc(stdin);
	putchar(ch);// 변수에 저장된 값을 전달
	// 입력 시 버퍼에 대해 초기화한다.
	//fflush(stdin);
	
*/