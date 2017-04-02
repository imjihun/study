

//20160726
#include<stdio.h>
#include<stdlib.h>
//#define cnt		10
#define STRIKE	0
#define BALL	1
#define STATE_INIT			1
#define STATE_111			10
#define STATE_11X			20
#define STATE_12X			30
#define	STATE_2XX			40
#define STATE_3XX			50
#define STATE_HR			60
/*
#define STATE_SIXTOTWO		4
#define STATE_FIVETOTWO		6
#define STATE_SIXTOTHREE	8
#define STATE_SEVENTOTHREE
#define STATE_
#define STATE_FORETOTHREE
*/


static int cnt = 0;
//static int exg_cnt=0;
static int stat= 1;
static int res[100][3]={0};
static int res_size = 0;
static int merged_p[2][3]={0};

int get_num(){
	switch(stat){
	case STATE_INIT:
		{
			stat = STATE_INIT+1;
			res[res_size][0] = 123;
			return res[res_size][0];
		}
			break;
	case STATE_INIT+1:
		{
			int i, bs_sum=0;
			for(i=0; i<res_size; i++){
				bs_sum += res[i][1]+res[i][2];
			}
			if(bs_sum<3){
				stat = STATE_INIT+2;
				res[res_size][0] = 456;
				return res[res_size][0];
			}else if(bs_sum == 3){
				stat = STATE_3XX;
				return get_num();
			}
		}
		break;
	case STATE_INIT+2:
		{
			int i, bs_sum = 0;
			int* bs_cnt = (int*)calloc(sizeof(int)*res_size,1);
			for(i=0; i<res_size; i++){
				bs_cnt[i] = res[i][1]+res[i][2];
				bs_sum += res[i][1]+res[i][2];
			}
			if(bs_sum<3){
				stat = STATE_INIT+3;
				res[res_size][0] = 789;
				return res[res_size][0];
			}else{
				if((bs_cnt[0] == 1 && bs_cnt[1] ==2) ||
					(bs_cnt[0] == 2 && bs_cnt[1] ==1)){
					stat = STATE_12X;
					return get_num();
				}
			}
		}
		break;
	case STATE_INIT+3:
		{
			int i, bs_sum = 0;
			int* bs_cnt = (int*)calloc(sizeof(int)*res_size,1);
			int zero_cnt=0;
			for(i=0; i<res_size; i++){
				bs_cnt[i] = res[i][1]+res[i][2];
				if(bs_cnt[i] == 0)
					zero_cnt++;
				bs_sum += res[i][1]+res[i][2];
			}
			if(bs_sum<3){
				if(zero_cnt == 1)
					stat = STATE_11X;
				else if(zero_cnt == 2)
					stat = STATE_2XX;
				return get_num();
			}else{
				if(zero_cnt == 0){
					stat = STATE_111;
					return get_num();
				}else if(zero_cnt == 1){
					stat = STATE_12X;
					return get_num();
				}else if(zero_cnt == 2){
					stat = STATE_3XX;
					return get_num();
				}
			}
		}
		break;
	case STATE_111://횟수3번
		{
			int ret_num = 0;
			int num[3] = {0};
			int *ball_p = (int*)calloc(sizeof(int)*res_size,1);
			int ball_cnt= 0;
			int *strike_p = (int*)calloc(sizeof(int)*res_size,1);
			int strike_cnt= 0;
			int i;
			int merge_src_ball1 = 0;
			int merge_src_ball2 = 0;
			int merge_src_strike1 = 0;
			int merge_src_strike2 = 0;
			for(i=0;i<res_size; i++){
				if(res[i][1] == 1){
					ball_p[ball_cnt++] = i;
				}else if (res[i][2] == 1){
					strike_p[strike_cnt++] = i;
				}
			}
			if(ball_cnt>0 && strike_cnt>0){
				merge_src_ball1 = res[ball_p[ball_cnt-1]][0];
				merge_src_strike1 = res[strike_p[strike_cnt-1]][0];
				num[2] = merge_src_strike1%10;//s
				num[1] = (merge_src_strike1/10)%10;//s
				num[0] = (merge_src_ball1/100)%10;//b
				merged_p[0][0] = res[ball_p[ball_cnt-1]][0];
				merged_p[0][1] = res[ball_p[ball_cnt-1]][1];
				merged_p[0][2] = res[ball_p[ball_cnt-1]][2];
				merged_p[1][0] = res[strike_p[strike_cnt-1]][0];
				merged_p[1][1] = res[strike_p[strike_cnt-1]][1];
				merged_p[1][2] = res[strike_p[strike_cnt-1]][2];

				ret_num = num[0]*100 + num[1]*10 + num[2];
				stat =dsa;
				return ret_num;
			}
			else if(ball_cnt == 0){
				merge_src_strike1 = res[strike_p[strike_cnt-1]][0];
				merge_src_strike2 = res[strike_p[strike_cnt-2]][0];
				num[2] = merge_src_strike1%10;//1
				num[1] = (merge_src_strike1/10)%10;//1
				num[0] = merge_src_strike2%10;//2
				merged_p[0][0] = res[strike_p[strike_cnt-1]][0];
				merged_p[0][1] = res[strike_p[strike_cnt-1]][1];
				merged_p[0][2] = res[strike_p[strike_cnt-1]][2];
				merged_p[1][0] = res[strike_p[strike_cnt-2]][0];
				merged_p[1][1] = res[strike_p[strike_cnt-2]][1];
				merged_p[1][2] = res[strike_p[strike_cnt-2]][2];
				
				ret_num = num[0]*100 + num[1]*10 + num[2];
				stat = STATE_111+1;
				return ret_num;
			}
			else if(strike_cnt == 0){
				merge_src_ball1 = res[ball_p[ball_cnt-1]][0];
				merge_src_ball2 = res[ball_p[ball_cnt-2]][0];
				num[2] = merge_src_ball1%10;//1
				num[1] = (merge_src_ball1/10)%10;//1
				num[0] = (merge_src_ball2/100)%10;//2
				merged_p[0][0] = res[ball_p[ball_cnt-1]][0];
				merged_p[0][1] = res[ball_p[ball_cnt-1]][1];
				merged_p[0][2] = res[ball_p[ball_cnt-1]][2];
				merged_p[1][0] = res[ball_p[ball_cnt-2]][0];
				merged_p[1][1] = res[ball_p[ball_cnt-2]][1];
				merged_p[1][2] = res[ball_p[ball_cnt-2]][2];

				ret_num = num[0]*100 + num[1]*10 + num[2];
				stat = dsa;
				return ret_num;
			}
		}
		break;
	case STATE_111+1:
		{
			int strike_cnt = 0;
			strike_cnt =res[res_size-1][2];
			if(res[res_size-1][1] == 0 && res[res_size-1][2] == 0){//전회차 out
				stat = STATE_111+5;
				return get_num();
			}else if(res[res_size-1][1] == 1){//전회차 1b
				mergedp[1][0]
			}
		}
		break;
	case STATE_3XX:
		{
			int i;
			int num[3]={0};
			int ret_num = 0;
			int temp = 0;
			for(i=0; i<res_size; i++){
				if(res[i][1] == 3){//3b
					temp = res[i][0]%10;
					ret_num = temp*100 + res[i][0]/10;
					stat = STATE_3XX+1;//->3b or 3s
					return ret_num;
				}
				else if(res[i][1] == 2){//2b1s
					num[2] = res[i][0]%10;
					num[1] = (res[i][0]/10)%10;
					num[0] = (res[i][0]/100)%10;

					ret_num =0;
					ret_num = ret_num*10+num[1];
					ret_num = ret_num*10+num[0];
					ret_num = ret_num*10+num[2];

					stat = STATE_3XX+1;//->3b or 3s
					return ret_num;
				}
			}
		}
		break;
	case STATE_3XX+1://3ball일때
		{
			int i;
			int num[3]={0};
			int ret_num = 0;
			int temp = 0;
			num[2] = res[res_size-1][0]%10;
			num[1] = (res[res_size-1][0]/10)%10;
			num[0] = (res[res_size-1][0]/100)%10;

			ret_num =0;
			ret_num = ret_num*10+num[2];
			ret_num = ret_num*10+num[0];
			ret_num = ret_num*10+num[1];

			stat = STATE_3XX+1;
			return ret_num;
		}
		break;
	case STATE_HR:
		break;
	}
	 
	cnt++;
}

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
/*
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