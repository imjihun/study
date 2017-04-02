#include "sample.h"

typedef struct Member{
	int seq;
	char *id;	//�ĺ���
	char *pw;
	char *name;
}*PMember; //<-���� ������

PMember *memberDB = NULL;	//Member* []
static int size = 0;		//board���������� size�Լ��� �־�� �ϹǷ� static�� �ٿ��� ������. (or �̸����ٲ۴�.)

PMember select(const char *id){//PMember�� ���⼭�� ���ǵǾ��⶧���� �����Լ�. �����Լ������� ������ PMember�� ��
	//const�� �������� �ʴ´ٴ� ����� ǥ�� �����
	PMember ptem;
	int i;

	for(i=0;i<size;i++){
		ptem = memberDB[i];
		if(strcmp(ptem->id, id) == 0){//���̸� ���� ���غ��� ����������� ���ڰ� �ٸ��� �˼��ִ�.
			return ptem;
		}
	}

	return 0;
}

int member_login(char* id, char* pw){
	PMember pt = select(id);

	if( pt == NULL){
		return 0;
	}
	else if( strcmp(pt->pw,pw) == 0)
		return 1;
	else return 0;
}
int member_idcheck(char* id){
	if(NULL == select(id)){
		return 1;//�ߺ����� ����.
	}
	return 0;//�ߺ����� �ִ�.
}
void member_insert(char *id, char *pw, char *name){
	PMember pMem = (PMember)malloc(sizeof(struct Member));
	pMem->seq = 0;
	if(id== NULL || id[0] == 0) return;
	else {
		pMem->id = (char*)calloc(strlen(id)+2,1);//calloc�� 0���� �ڵ��ʱ�ȭ
		strcpy(pMem->id, id);
	}
	if(pw== NULL || pw[0] == 0) return;
	else {
		pMem->pw = (char*)calloc(strlen(pw)+2,1);
		strcpy(pMem->pw, pw);
	}
	if(name== NULL || name[0] == 0) return;
	else {
		pMem->name = (char*)calloc(strlen(name)+2,1);
		strcpy(pMem->name, name);
	}
	
	memberDB = (PMember*)realloc(memberDB, sizeof(PMember)*(size+1));
	memberDB[size++] = pMem;
}
void member_update(int index, char *id, char *pw, char *name){
	
	PMember pMem = memberDB[index];
	if(pMem == NULL) {printf("error"); return;}
	pMem->seq = 0;
	if(id== NULL || id[0] == 0) ;
	else {
		free(pMem->id);
		pMem->id = (char*)calloc(strlen(id)+2,1);
		strcpy(pMem->id, id);
	}
	if(pw== NULL || pw[0] == 0) ;
	else {
		free(pMem->pw);
		pMem->pw = (char*)calloc(strlen(pw)+2,1);
		strcpy(pMem->pw, pw);
	}
	if(name== NULL || name[0] == 0) ;
	else {
		free(pMem->name);
		pMem->name = (char*)calloc(strlen(name)+2,1);
		strcpy(pMem->name, name);
	}
}