
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
    int arr_lotto[1]; //1���� ��ȣ�� �����ϴ� ����
    int i, j, k;
    int limit = 0; //�ڵ����� ���� �ζ� ��ȣ�� ��
    int cnt = 0; //1�ٿ� ��ȣ�� ���� ����
    int jb = 0; //�ߺ� ���� �˻�
 
    srand(time(NULL) );
 
    printf("�ڵ����� � : ");
    scanf("%d", &limit);
 
    for (i = 0; i < limit; i++) {
 
        do {//1�� �̻� ����
            arr_lotto[cnt] = rand() % 899 + 100; //100~999 ���� �����ϰ� �ο���
 
            if (cnt > 0) 
			{ //�ι�° ���� ����
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
                cnt++; //�ߺ��� ���� ��쿡�� ������ȣ�� �̰�
            }
            else {
                jb = 0; //�ߺ��� ������ do while �ٽ� ���� (cnt�� �ٲ��� ����)
            }
 
        } while (cnt < 1); //1�� �� ���� �� ���� ��� ����
 
        for (j = 0; j < 1; j++) { //���
            printf("%3d ", arr_lotto[j]);
        }
        printf("\t\n");
 
        cnt = 0; //limit��ŭ �̱� ���� cnt�� �ʱ�ȭ
    }
 
 */
	int arr_lotto[1]; //1���� ��ȣ�� �����ϴ� ����
    int i, j, k;
	int a, b, c;
    int limit = 0; //�ڵ����� ���� �ζ� ��ȣ�� ��
    int cnt = 0; //1�ٿ� ��ȣ�� ���� ����
    int jb = 0; //�ߺ� ���� �˻�
 
    srand(time(NULL) );
 
    printf("�ڵ����� � : ");
    scanf("%d", &limit);
 
    for (i = 0; i < limit; i++) {
 
        do {//1�� �̻� ����
            arr_lotto[cnt] = rand() % 899 + 100; //100~999 ���� �����ϰ� �ο���
 
            if (cnt > 0) 
			{ //�ι�° ���� ����
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
                cnt++; //�ߺ��� ���� ��쿡�� ������ȣ�� �̰�
            }
            else {
                jb = 0; //�ߺ��� ������ do while �ٽ� ���� (cnt�� �ٲ��� ����)
            }
 
        } while (cnt < 1); //1�� �� ���� �� ���� ��� ����
 
        for (j = 0; j < 1; j++) { //���
            printf("%3d ", arr_lotto[j]);
        }
        printf("\t\n");
 
        cnt = 0; //limit��ŭ �̱� ���� cnt�� �ʱ�ȭ
    }
	return 0;
}



