#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 648
#define UNIT 3

struct No{
	int nums[UNIT];
	PNo next;
};
typedef No* PNo;

static int answerN=123;
static int res[700][3];
static PNo* header = NULL;
static int num_size = 0;

int initNumArea(){
	int i[UNIT], l;
	PNo c = NULL, prev = NULL;//c는 생성할것 prev는 방금생성된것

	header = (PNo*)calloc(sizeof(PNo),1);
	*header = NULL;

	for(i[0]=1; i[0]<9; i[0]++){//100
		for(i[1]=0; i[1]<10; i[1]++){//10
			for(i[2]=0; i[2]<10; i[2]++){//1
				if(i[0]==i[1] || i[0]==i[2] || i[1]==i[2]){}
				else{
					if(*header == NULL){
						*header = (PNo)calloc(sizeof(struct No),1);
						for(l=0; l<UNIT; l++){	
							(*header)->nums[l]=i[l];
						}
						(*header)->next=NULL;
						num_size +=1;

						prev = (*header);
					}else {
						c = (PNo)calloc(sizeof(struct No),1);
						for(l=0; l<UNIT; l++){	
							c->nums[l]=i[l];
						}
						c->next=NULL;
						prev->next = c;
						num_size +=1;

						prev = c;
						c=NULL;
					}
				}
			}//1
		}//10
	}//100
	return 0;
}
int disNum(int cur_num[], int value){
	cur_num[0] = value/100;
	cur_num[1] = (value/10) % 10;
	cur_num[2] = value%10;
}

int delNo(PNo cur, PNo pre){//노드삭제
	if(pre == NULL){//cur이 헤더일때
		(*header) = cur->next;
		free(cur);
	}else{
		pre->next = cur->next;
		free(cur);
	}
}

int analOut(int value){//결과가 아웃일때
	int i, k, j;
	int cur_num[UNIT];
	PNo c=(*header), p=NULL;

	disNum(cur_num, value);//cur_num[] = 결과를 초래한 숫자

	for(i=0; i<num_size; i++){
		for(k=0; k<UNIT; k++){
			for(j=0; j<UNIT; j++){
				if(c->nums[k]==cur_num[j]){
					delNo(c, p);//아웃값 삭제
				}
			}
		}
	}
}
int analBall(int){//결과가 볼일떄

}
int analStrike(){
}

int main(){
	int num[3]={9,8,7};
	int ret= 0;
	int retset[3]={0};

	ret = team_4(0,2);
	retset[2] = ret%10;
	retset[1] = (ret/10)%10;
	retset[0] = (ret/100)%10;
	
	while(1){
		if(num[0]==retset[0] && num[1]==retset[1] && num[2]==retset[2]){
			printf("%d번, %d\n", cnt, ret);
			break;
		}
		else{
			ret = team_4(0,2);
			retset[2] = ret%10;
			retset[1] = (ret/10)%10;
			retset[0] = (ret/100)%10;
		}
	}
	return 0;
}
int team_4(int value, int action){
	static int answer = 0;

	if (action == 1) {
	}
	if (action == 2) {
		return getnum();
	}
	if (action == 3) {
	}
	if (action == 4) {
	}
}

int getnum(){
	int numset[3]={0};
	int i, j;
	cnt++;
	
	numset[2] = answerN%10;
	numset[1] = (answerN/10)%10;
	numset[0] = (answerN/100)%10;
	for(i=0; i<3-1; i++){
		for(j=i+1; j<3; j++){
			if(numset[i] == numset[j]){
				answerN++;
				numset[2] = answerN%10;
				numset[1] = (answerN/10)%10;
				numset[0] = (answerN/100)%10;
				i=0;
				break;
			}
		}
	}
	return answerN++;
}