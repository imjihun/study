
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	int chpher = 3;			//�ڸ���
	int number[10];			//������ ������ �迭
	int index = 0;			//������ ������ �迭�� �ε��� ��ȣ
	int num,i;

	for(i=0; i<10; i++){
		number[i]=0;
	}	//�迭 �ʱ�ȭ
	
	while(number[9] == 0){

		for(i=0; i<chpher; i++){
			int a, temp1, temp2;

			a = rand()%10;	//0 ~ 9������ ���� ����
			
			if(i==0){
				if(a==0){
					break;		//ù�ڸ� ���ڿ� 0�� ���� ó������ �ٽ�
				}else{
					num = a*100;	//ù�ڸ� ��������
					temp1 = a;		
				}
			}else if(i==1){

				if(temp1 == a){	//ù�ڸ� ���ڿ� ���� �����̸� ó������ �ٽ�
					break;		
				}else{
					num += (a*10);	//��°�ڸ� ���� ����
					temp2 = a;
				}

			}else if(i==2){
				if(temp1 == a || temp2 == a){	//ù �ڸ� ���ڿ� ��°�ڸ� ���ڿ� ������ ó������ �ٽ�
					break;
				}else{
					num += a;
					number[index]=num;		//�ϼ��� 3�ڸ� ���ڸ� �迭�� ����
					index++;				//������ ������ index��ȣ ����
				}
			}
		}
	}// end while


	for(i=0; i<10; i++){
		printf("%d\n",number[i]);
	}	//�� ���

	
	
	
	return 0;
}