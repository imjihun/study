#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getpos(){
	//���������� �ּҸ� ��ȯ���� �ʴ´�! �迭�� ��������̱� ������ ��ȯ���� �ʴ´�. (�����ͺ����� �ȵ�)
	//�ּҸ� ��ȯ�ϰ� �ʹٸ�, ������ ������ �ִ� Heap������� �޸𸮰� �Ҵ�Ǵ� malloc���� �޸𸮸� �Ҵ��ϸ� �� �ּҸ� ��ȯ�ϸ� ����.(������ ��������)
	int value;
	value = 10;
	return &value;
}
int main(void){
	int* n = getpos();
	printf("%d \n", *n); //���������� n�� ����Ű�� �ִ� ���� �ٸ������ͷ� ������������ �ֱ� ������ �Ұ���. (�����ͺ����� �ȵ�)
	return 0;
}
	//int �� ������ ����Ű�� ������ ����
	//int *np = NULL;//NULL = (void*)0
	/*
	if(np == NULL){
		//����ų ������ �����ϰ� �� �ּҸ� �����Ѵ�.
		np = (int*)malloc(sizeof(int));//memory allocation
		//np = (int*)calloc(1,sizeof(int));//1���� intũ��޸� �Ҵ�
		//np = (int*)realloc(np, sizeof(int));// ������ġ(np)�� ���� �޸𸮸� �Ҵ��ض� (������ġ�� NULL�̸� �׳� ���� �޸� �Ҵ�)
											// realloc�� �޸𸮸� �ø� �� ���, ������ �����͸� ���λ����� �޸𸮷� ���� ī�����ش�.

	}
	*/
	//����� �� �ִ�.
	/*
	int ar[3][5];
	int (*p)[5] = ar;		//�迭�����ͺ���. �ΰ��� ����.
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