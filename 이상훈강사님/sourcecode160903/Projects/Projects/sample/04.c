#include "sample.h"

/** �Խ��� 20160728
*/

#define MAXBUF 512
int main (void){//����� ���, Ű���� �Է�
	//�����ϱ��� ó��
	char menu;
	char buf[MAXBUF];
	char sessionId[80]={0};
	
	//end ����

	while(1){//����ڰ� �����ϱ� ������ ��� ����.
	//	system("cls");
		printf("\n");
		if(sessionId[0] != 0)
			printf("Hi %s!\n", sessionId);
		board_list();//board_�� �ٸ��ҽ���.
		printf("[1]write [2]view [3]join [4]login [5]logout [0]exit\n");
		do{//do while -> �ùٸ��� ����Ǿ����� ��������, �ƴϸ� �ٽý���
			gets(buf);//������� �Է��� ����, Ű�����Է��� gets��
			fflush(stdin);
		}while(buf[0] == 0);//������� �Է��� ������ �ٽ� �Է��ϼ���.
		//char*�� �ּҰ��� 0(NULL)�� �ɼ��ִ�. ���� �ּҰ��� 0(NULL)�̸� �Ҵ�� �޸𸮰�����.ù��°���� 0(NULL)�̸� ���̾���
		//char[]�� ù��° ���� NULL�̸� ���� ����. �ּҴ� NULL�� �ƴϴ�. �̹��Ҵ�
		//strlen�� ������ �Լ��� �����ϸ� �غ��ϴµ� ���ð��� �ɸ��⶧���� ������ ǥ���� �� ������, �Ƚ�� �ӵ����鿡�� ���ȴ�.

		menu = buf[0];
		if (menu == '0') {break;}
		switch(menu){
		case '5':
			{
				sessionId[0] = 0;
				memset(sessionId, 0, 80);//byte������ �޸𸮿� ù��°�ּ�(sessionId)�� �����(0)���� ä����
				//memcpy�� �޸𸮸� ����Ʈ������ ī���ض�
			}
			break;
		case '4':
			{
				char id[80]={0};
				char pw[80]={0};
				printf("ID : ");
				gets(id);
				fflush(stdin);
				printf("pw : ");
				gets(pw);
				fflush(stdin);
				if(member_login(id, pw)){
					strcpy(sessionId, id);
					printf("Hi %s\n", sessionId);
				}
				else
					printf("Id or pw is error!\n", sessionId);
			}
			break;
		case '3':
			{//join
				char id[80]={0};
				char pw[80]={0};
				char name[80]={0};
				printf("ID : ");
				gets(id);
				fflush(stdin);
				if (member_idcheck(id) == 1) {
					printf("pw : ");
					gets(pw);
					fflush(stdin);
					printf("name : ");
					gets(name);
					fflush(stdin);
					member_insert(id, pw, name);
					strcpy(sessionId, id);
				}
				else{
					printf("Already exgisted ID\n");
				}
			}
			break;
		case '1':
			{
				char title[80];
				char memo[512];
				int error;

				if(sessionId[0]==NULL) break;
				printf("���� : ");
				gets(buf);
				fflush(stdin);
				if (buf[0] == 0) break;
				strncpy(title, buf,80);
				printf("���� : ");
				gets(buf);
				fflush(stdin);
				if (buf[0] == 0) break;
				strcpy(memo, buf);
				//error = board_add(title, memo, id);
				if(error = board_add(title, memo, sessionId)) printf("error=%d(fail)\n", error);
			}
			break;
		case '2':
			{
				int no;
				int i;

				printf("select no : ");
				gets(buf);
				fflush(stdin);
				sscanf(buf, "%d", &no);
				//for(i=0; buf[i]!=0; i++)
				//	no= no*10+(buf[i]-'0');

				board_view(no);
			}
			break;
		}
	}//end while(1)

	//�����ϱ��� ó��
	puts("Terminated");//�������
	//end ����
	return 0;
}