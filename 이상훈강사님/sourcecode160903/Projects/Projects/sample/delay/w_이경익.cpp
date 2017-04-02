
    /*
	int randomNumber;
    int i;
	srand((unsigned int)time(NULL));
	for(i=0; i<=10; i++)
	{
    randomNumber = rand()%999+100;
    printf("%d\n", randomNumber);

    
	}
	return 0;
	*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
	/*
    int arr_lotto[1]; //1개의 번호를 저장하는 변수
    int i, j, k;
    int limit = 0; //자동으로 뽑을 로또 번호의 수
    int cnt = 0; //1줄에 번호를 뽑은 갯수
    int jb = 0; //중복 여부 검사
 
    srand(time(NULL) );
 
    printf("자동으로 몇개 : ");
    scanf("%d", &limit);
 
    for (i = 0; i < limit; i++) {
 
        do {//1번 이상 실행
            arr_lotto[cnt] = rand() % 899 + 100; //100~999 까지 랜덤하게 부여함
 
            if (cnt > 0) 
			{ //두번째 실행 부터
                for (j = 0; j < cnt; j++)
				{ 
						if (arr_lotto[j]/100==(arr_lotto[j]-(arr_lotto[j]/100)*100)/10)
						{
							jb++;
						}
                    }
                }
            
	
            if (jb == 0)
			{
                cnt++; //중복이 없을 경우에는 다음번호를 뽑고
            }
            else {
                jb = 0; //중복이 있으면 do while 다시 실행 (cnt는 바뀌지 않음)
            }
 
        } while (cnt < 1); //1줄 다 뽑을 때 까지 계속 실행
 
        for (j = 0; j < 1; j++) { //출력
            printf("%3d ", arr_lotto[j]);
        }
        printf("\t\n");
 
        cnt = 0; //limit만큼 뽑기 위해 cnt를 초기화
    }
 
 */
	int arr_lotto[1]; //1개의 번호를 저장하는 변수
    int i, j, k;
	int a, b, c;
    int limit = 0; //자동으로 뽑을 로또 번호의 수
    int cnt = 0; //1줄에 번호를 뽑은 갯수
    int jb = 0; //중복 여부 검사
 
    srand(time(NULL) );
 
    printf("자동으로 몇개 : ");
    scanf("%d", &limit);
 
    for (i = 0; i < limit; i++) {
 
        do {//1번 이상 실행
            arr_lotto[cnt] = rand() % 899 + 100; //100~999 까지 랜덤하게 부여함
 
            if (cnt > 0) 
			{ //두번째 실행 부터
                for (j = 0; j < cnt; j++)
				{ 
						if (arr_lotto[j]/100==(arr_lotto[j]-(arr_lotto[j]/100)*100)/10)
						{
							jb++;
						}
                    }
                }
            
	
            if (jb == 0)
			{
                cnt++; //중복이 없을 경우에는 다음번호를 뽑고
            }
            else {
                jb = 0; //중복이 있으면 do while 다시 실행 (cnt는 바뀌지 않음)
            }
 
        } while (cnt < 1); //1줄 다 뽑을 때 까지 계속 실행
 
        for (j = 0; j < 1; j++) { //출력
            printf("%3d ", arr_lotto[j]);
        }
        printf("\t\n");
 
        cnt = 0; //limit만큼 뽑기 위해 cnt를 초기화
    }
	return 0;
}



