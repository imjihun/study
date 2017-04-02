#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getpos(){
	//지역변수의 주소를 반환하지 않는다! 배열명도 지역상수이기 때문에 반환하지 않는다. (데이터보존이 안됨)
	//주소를 반환하고 싶다면, 전역의 성질이 있는 Heap방식으로 메모리가 할당되는 malloc으로 메모리를 할당하면 그 주소를 반환하면 가능.(데이터 보존가능)
	int value;
	value = 10;
	return &value;
}
int main(void){
	int* n = getpos();
	printf("%d \n", *n); //가능하지만 n이 가르키고 있는 값이 다른데이터로 덮혀쓰여질수 있기 때문에 불가능. (데이터보존이 안됨)
	return 0;
}
	//int 형 변수를 가리키는 포인터 변수
	//int *np = NULL;//NULL = (void*)0
	/*
	if(np == NULL){
		//가리킬 공간을 생성하고 그 주소를 저장한다.
		np = (int*)malloc(sizeof(int));//memory allocation
		//np = (int*)calloc(1,sizeof(int));//1개의 int크기메모리 할당
		//np = (int*)realloc(np, sizeof(int));// 현재위치(np)에 새로 메모리를 할당해라 (현재위치가 NULL이면 그냥 새로 메모리 할당)
											// realloc은 메모리를 늘릴 때 사용, 기존의 데이터를 새로생성된 메모리로 값을 카피해준다.

	}
	*/
	//사용할 수 있다.
	/*
	int ar[3][5];
	int (*p)[5] = ar;		//배열포인터변수. 두개가 같다.
	printf("%d = %d\n", ar+0, p+0);
	printf("%d = %d\n", ar+1, p+1);
	*/
	/*
	int *global;
	{
		int local_a = 10;
		printf("%d\n", local_a);
		global = &local_a;
	}
	{
		printf("%d\n", *global);
		*global = 100;
		printf("%d\n", *global);
	}
	return 0;
	*/
/*

	double n=3000, k=0;
	double i=0;
	for(i=1; i<11; i++){
		k = i;
		printf("%lf\t%lf\n", n/(3000.0+n)*100.0, k*n/(3000.0*k+n)*100.0);
	}
	return 0;
	*/
/*
#define MAX (OBJ_CNT+2)*STU_CNT
#define OBJ_CNT 6
#define STU_CNT 30

int main(void){
	int score[MAX] = {0};
	int last=0;

	{
		int i, j;
		for(i=0; i<STU_CNT; i++){
			for(j=0; j<OBJ_CNT; j++){
				score[i*(OBJ_CNT+2)+j] = rand()%101;
				score[i*(OBJ_CNT+2)+OBJ_CNT] += score[i*(OBJ_CNT+2)+j];
			}
			score[i*(OBJ_CNT+2)+OBJ_CNT+1] = score[i*(OBJ_CNT+2)+OBJ_CNT]/OBJ_CNT;
		}
	}
	{
		int i, j;
		for(i=0; i<STU_CNT; i++){
			printf("No. %2d : ", i+1);
			for(j=0; j<OBJ_CNT+2; j++){
				if(j==OBJ_CNT) printf("-> ");
				printf("%3d\t", score[i*(OBJ_CNT+2)+j]);
			}
			printf("\n");
		}
	}

	return 0;
}
*/