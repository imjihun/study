

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SET		0
#define CALL	1
#define RESP	2
#define LISTEN	3

static int answer; // 지역변수로 선언해도 값이 프로그램실행동안 유지
static short ball=0;
static short strike=0;
static int call=000;
static int strike_cnt = 0;
static int cnt=0;
static int step = 0;//1or2or0스텝
static int prev_step = 0;//1or2or0스텝
static int num[3]={0};
static int prev_retnum =0;
static int pprev_retnum =0;
static int retnum=102;
static int prev_str = 0;
static int each_cnt =0;
/*
void main(void)
{
	int max = 1;
	int i;
	int sum=0;
	for(i=0;i<max;i++){
		team_4(0,0);
		printf("%d\n", answer);
		while(strike !=3){
			team_4(team_4(team_4(0,1),2),3);
			printf("%d, %d%d%d\n", cnt, num[0],num[1],num[2]);
		}
		sum += cnt;
	}
	//printf("%lf\n", (double)sum/(double)max);
	
}
*/
int action_2(){
	if(prev_str > strike){
		prev_retnum = pprev_retnum;
		num[0] = prev_retnum/100;
		num[1] = (prev_retnum/10) %10;
		num[2] = prev_retnum%10;
		if( step == 2){
			prev_step = step;
			step = 0;}
		else{
			prev_step = step;
			step += 1;}
		each_cnt = 0;
	}else {
		if (prev_str < strike){
			if( step == 2){
				prev_step = step;
				step =0;
			}
			else{
				prev_step = step;
				step += 1;
			}
			each_cnt = 0;
		}else{prev_step = step;}
		pprev_retnum = prev_retnum;
		prev_retnum = retnum;
		num[0] = retnum/100;
		num[1] = (retnum/10) %10;
		num[2] = retnum%10;
	}
	
	do{
		if(step==2){
			if(each_cnt > 7){
				if( step == 2){
					prev_step = step;
					step =0;
				}
				else{
					prev_step = step;
					step += 1;
				}
				each_cnt = 0;
			}else {
				if(num[2] == 9)
					num[2] -= 9;
				else num[2] += 1;
				prev_step = step;
			}
		}
		if(step==1){
			if(each_cnt > 8){
				if( step == 2){
					prev_step = step;
					step =0;
				}
				else{
					prev_step = step;
					step += 1;
				}
				each_cnt = 0;
			}else {
				if(num[1] == 9)
					num[1] -= 9;
				else num[1] += 1;
				prev_step = step;
			}
		}
		if(step==0){
			if(each_cnt > 7){
				if( step == 2){
					prev_step = step;
					step =0;
				}
				else{
					prev_step = step;
					step += 1;
				}
				each_cnt = 0;
			}else {
				if(num[0] == 9)
					num[0] -= 8;
				else num[0] += 1;
				prev_step = step;
			}
		}
	}while(num[0]==num[1] || num[0]==num[2] || num[1]==num[2] || prev_step != step);
	
	retnum = 0;
	retnum = num[0]*100 + num[1]*10 + num[2];
	cnt += 1;
	each_cnt += 1;
	return retnum;
	/*
		if(strike_cnt==3 || (strike_cnt==2 && cnt ==9)){
			if(ball == 2 && strike_cnt==3)
				step=3;
			else//(ball == 3 or prev_step==1)
				step=2;
		}else{
			step=1;
		}

		switch(step){
		case 1:
			{
//				num[0]=cnt;num[1]=cnt;num[2]=cnt;
				prev_retnum = (9-cnt)*100 + (9-cnt)*10 + (9-cnt);
			}
			break;
		case 2://3ball
			{
				int temp;
				if(strike_cnt == 2){
					num[2] = 9;
					strike_cnt++;
				}else{}
				temp = num[0];
				num[0] = num[1];
				num[1] = num[2];
				num[2] = temp;
				prev_retnum = num[0]*100 + num[1]*10 + num[2];
			}
			break;
		case 3://2ball;
			{
				int temp;
				if(strike_cnt == 2){
					num[2] = 9;
					strike_cnt++;
				}else{}
				temp = num[0];
				num[0] = num[1];
				num[1] = temp;
				prev_retnum = num[0]*100 + num[1]*10 + num[2];
				step = 2;
				break;
			}
		}
		(cnt)++;
		return prev_retnum;*/
}


void action_4(int value){
	prev_str = strike;
	strike = value>>16;
	ball = value;
	/*
	if(step==1 && strike>0)
		strike_cnt += 1;
	if(strike + ball > 0 && step==1)
		num[strike_cnt-1] = prev_retnum/100;
		*/
}

int action_3(int value)
{
	int ac3[2][3];
	int temp[2];
	int i,j;
	short ball = 0, strike = 0;
	temp[0]=value;
	temp[1]=answer;
		
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			ac3[i][j]=temp[i]%10;
			temp[i]=temp[i]/10;
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(ac3[0][i]==ac3[1][j]){
				if(i==j){
					strike++;
				}else{
					ball++;
				}
			}
		}
	}
	value=(strike<<16)+ball;
	ball=0;
	strike=0;

	return value;
}
void init(){
	int i;
	answer=0; // 지역변수로 선언해도 값이 프로그램실행동안 유지
	ball=0;
	strike=0;
	call=000;
	strike_cnt = 0;
	cnt=0;
	step = 0;//1or2or3스텝
	for(i=0; i<3; i++)
	num[i]=0;
	prev_retnum=0;
}
void team_4_rand() {
	int first, second, third;//백,십,일의 자리 순
	do {
		srand(time(NULL));				//랜덤 난수 발생
		do {
			do {					//백의자리가 0이 나왔을 때 다시 rand돌림
				first = rand() % 10;
				second = rand() % 10;
				third = rand() % 10;
			} while (first == 0);
		} while (first == (second + 1) || first == (second - 1) || first == (third + 1)
			|| first == (third - 1) || second == (third + 1) || second == (third - 1)); //연속 안되게(1,2 1,3 2,3 +-1 차이 제거)
			
	} while (first == second || first == third || second == third);
	answer = (first * 100) + (second * 10) + (third * 1);// 중복 없는 3자리 정수
}

int team_4(int value, int action)
{

	if(action==SET)
	{
		init();
		//answer =  중복없는 3자리 정수를 저장
		team_4_rand();
	}
	
	if(action==CALL) // call
	{
		return action_2();
	}
	if(action==RESP) // 상대방이 부른값에 대답
	{
		return action_3(value);
	}
	if(action==LISTEN)  // 대답 가져오기 #############  내가 맡은 파트 ###########
	{
		action_4(value);
	}
	return 0;

}

