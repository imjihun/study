#include "sample.h"

/** 게시판 20160728
*/

#define MAXBUF 512
int main (void){//모니터 출력, 키보드 입력
	//시작하기전 처리
	char menu;
	char buf[MAXBUF];
	char sessionId[80]={0};
	
	//end 시작

	while(1){//사용자가 종료하기 전까지 계속 실행.
	//	system("cls");
		printf("\n");
		if(sessionId[0] != 0)
			printf("Hi %s!\n", sessionId);
		board_list();//board_는 다른소스에.
		printf("[1]write [2]view [3]join [4]login [5]logout [0]exit\n");
		do{//do while -> 올바르게 실행되었으면 내려가고, 아니면 다시실행
			gets(buf);//사용자의 입력을 받음, 키보드입력은 gets로
			fflush(stdin);
		}while(buf[0] == 0);//사용자의 입력이 없으면 다시 입력하세요.
		//char*는 주소값도 0(NULL)이 될수있다. 따라서 주소값이 0(NULL)이면 할당된 메모리가없다.첫번째값이 0(NULL)이면 값이없다
		//char[]은 첫번째 값이 NULL이면 값이 없다. 주소는 NULL이 아니다. 이미할당
		//strlen도 있지만 함수를 실행하면 준비하는데 상당시간이 걸리기때문에 간단히 표현할 수 있으면, 안써야 속도측면에서 향상된다.

		menu = buf[0];
		if (menu == '0') {break;}
		switch(menu){
		case '5':
			{
				sessionId[0] = 0;
				memset(sessionId, 0, 80);//byte단위로 메모리에 첫번째주소(sessionId)에 가운데값(0)으로 채워라
				//memcpy는 메모리를 바이트단위로 카피해라
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
				printf("제목 : ");
				gets(buf);
				fflush(stdin);
				if (buf[0] == 0) break;
				strncpy(title, buf,80);
				printf("내용 : ");
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

	//종료하기전 처리
	puts("Terminated");//끝났어요
	//end 종료
	return 0;
}