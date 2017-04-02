
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	int chpher = 3;			//자리수
	int number[10];			//정수를 저장할 배열
	int index = 0;			//정수를 저장할 배열의 인덱스 번호
	int num,i;

	for(i=0; i<10; i++){
		number[i]=0;
	}	//배열 초기화
	
	while(number[9] == 0){

		for(i=0; i<chpher; i++){
			int a, temp1, temp2;

			a = rand()%10;	//0 ~ 9까지의 정수 임의
			
			if(i==0){
				if(a==0){
					break;		//첫자리 숫자에 0이 들어가면 처음부터 다시
				}else{
					num = a*100;	//첫자리 숫자저장
					temp1 = a;		
				}
			}else if(i==1){

				if(temp1 == a){	//첫자리 숫자와 같은 숫자이면 처음부터 다시
					break;		
				}else{
					num += (a*10);	//둘째자리 숫자 저장
					temp2 = a;
				}

			}else if(i==2){
				if(temp1 == a || temp2 == a){	//첫 자리 숫자와 두째자리 숫자와 같으면 처음부터 다시
					break;
				}else{
					num += a;
					number[index]=num;		//완성된 3자리 숫자를 배열로 저장
					index++;				//다음번 저장할 index번호 증가
				}
			}
		}
	}// end while


	for(i=0; i<10; i++){
		printf("%d\n",number[i]);
	}	//값 출력

	
	
	
	return 0;
}