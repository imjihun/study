/*
//20160727
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_R	15
#define MAX_C	15
#define STAR	2
#define BLANK	0
#define BLOCK	1
#define UP		10
#define RIGHT	11
#define DOWN	12
#define LEFT	13
//#define STACK_MAX MAX_R*MAX_C

int main(void){
	char Map[MAX_R][MAX_C] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
							  2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
							  1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,
							  1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,
							  1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,
							  1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,
							  1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,
							  1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,
							  1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,
							  1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,
							  1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
							  1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
							  1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
							  1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
							  1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,};
//	int stack[STACK_MAX][2] = {0};
//	int spack_point=0;
	int y=1, x=0, left_dir=UP;
	while(!(y==14 && x==13)){
		if(display(Map) < 0 ) return -2;
		if(searchNextPositionOfLeft(Map, &x, &y, &left_dir)<0) return-4;
	}//end while(!(y==14 && x==13))
	if(display(Map) < 0 ) return -2;
	return 0;
}

int display(char (*Map)[MAX_R]){
	//display
	int r, c;
	system("cls");
	if(Map==NULL) return -1;
	for(r=0; r<MAX_R; r++){
		for(c=0; c<MAX_C; c++){
			if (Map[r][c] == STAR){
				printf("☆");
			}else if(Map[r][c] == BLANK){
				printf("  ");
			}else{
				printf("■");
			}
		}
		printf("\n");
	}
	//end display
	return 0;
}

int searchNextPositionOfLeft(char (*Map)[MAX_R], int *x, int *y, int *left_dir){
	// search nestart_xt position
	if( x == NULL || y == NULL || left_dir == NULL) return -3;
	Map[*y][*x]=BLANK;
	switch(*left_dir){
	case UP:
		if(Map[*y-1][*x]==BLANK) {*y-=1;*left_dir=LEFT;}
		else if(Map[*y][*x+1]==BLANK) {*x+=1;*left_dir=UP;}
		else if(Map[*y+1][*x]==BLANK) {*y+=1;*left_dir=RIGHT;}
		else if(Map[*y][*x-1]==BLANK) {*x-=1;*left_dir=DOWN;}
		break;
	case RIGHT:
		if(Map[*y][*x+1]==BLANK) {*x+=1;*left_dir=UP;}
		else if(Map[*y+1][*x]==BLANK) {*y+=1;*left_dir=RIGHT;}
		else if(Map[*y][*x-1]==BLANK) {*x-=1;*left_dir=DOWN;}
		else if(Map[*y-1][*x]==BLANK) {*y-=1;*left_dir=LEFT;}
		break;
	case DOWN:
		if(Map[*y+1][*x]==BLANK) {*y+=1;*left_dir=RIGHT;}
		else if(Map[*y][*x-1]==BLANK) {*x-=1;*left_dir=DOWN;}
		else if(Map[*y-1][*x]==BLANK) {*y-=1;*left_dir=LEFT;}
		else if(Map[*y][*x+1]==BLANK) {*x+=1;*left_dir=UP;}
		break;
	case LEFT:
		if(Map[*y][*x-1]==BLANK) {*x-=1;*left_dir=DOWN;}
		else if(Map[*y-1][*x]==BLANK) {*y-=1;*left_dir=LEFT;}
		else if(Map[*y][*x+1]==BLANK) {*x+=1;*left_dir=UP;}
		else if(Map[*y+1][*x]==BLANK) {*y+=1;*left_dir=RIGHT;}
		break;
	}
	Map[*y][*x]=STAR;
	return 0;
}
*/
/*
//20160726
#include<stdio.h>
#include<stdlib.h>
#define cnt		10
#define STRIKE	0
#define BALL	1

int team_4(int value, int action){
	static int answer = 0;

	if (action == 1) {
	}
	if (action == 2) {
	}
	if (action == 3) {
	}
	if (action == 4) {
	}
}

int get_RandomNumber(int unit, int* number);
int main(void){
	int* number;
	int getUnit=-1, i, j;
	
	printf("출력할 1~10까지의 자리수를 입력하라 : ");
	while (getUnit<1 || getUnit>10){
		scanf("%d", &getUnit);
		fflush(stdin);
	}
	number = (int*)malloc(sizeof(int)*getUnit);
	printf("\n");
	for(i=0; i<cnt; i++){
		get_RandomNumber(getUnit, number);
		for(j=0; j<getUnit; j++)
			printf("%d", number[j]);
		printf("\n");
	}
	free(number);
	{//random number solve
		{//question
			int (*cnt)[2];
			int* givNum = (int*)malloc(sizeof(int)*getUnit);
			get_RandomNumber(getUnit, givNum);

			free(givNum);
		}//end question
		{//respond
			int strCnt=0, balCnt=0;
			int* getNum = (int*)malloc(sizeof(int)*getUnit);
			int* corNum = (int*)malloc(sizeof(int)*getUnit);
			get_RandomNumber(getUnit, getNum);//질문숫자받음
			get_RandomNumber(getUnit, corNum);//정답숫자받음
			
			{//comparison
				int i, j;
				for(i=0; i<getUnit; i++){
					if(getNum[i] == corNum[i])
						strCnt++;
					else{
						for(j=0; j<getUnit; j++){
							if(getNum[i] == corNum[j]){
								balCnt++;
								break;
							}else{}
						}
					}
				}
			}//end comparison

			free(getNum);
			free(corNum);
		}//end respond
	}
}

int get_RandomNumber(int unit, int* number){
	int k, j;
	int dRandom;
	int result=0;

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

	return 1;
}
*/