#include "sample.h"

typedef struct Member{
	int seq;
	char *id;	//식별값
	char *pw;
	char *name;
}*PMember; //<-형명 재정의

PMember *memberDB = NULL;	//Member* []
static int size = 0;		//board페이지에도 size함수가 있어야 하므로 static을 붙여서 가린다. (or 이름을바꾼다.)

PMember select(const char *id){//PMember가 여기서만 정의되었기때문에 내부함수. 메인함수에서는 못쓴다 PMember를 모름
	//const는 수정하지 않는다는 명시적 표현 꼭써라
	PMember ptem;
	int i;

	for(i=0;i<size;i++){
		ptem = memberDB[i];
		if(strcmp(ptem->id, id) == 0){//길이를 먼저 비교해보면 적은비용으로 문자가 다른지 알수있다.
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
		return 1;//중복값이 없다.
	}
	return 0;//중복값이 있다.
}
void member_insert(char *id, char *pw, char *name){
	PMember pMem = (PMember)malloc(sizeof(struct Member));
	pMem->seq = 0;
	if(id== NULL || id[0] == 0) return;
	else {
		pMem->id = (char*)calloc(strlen(id)+2,1);//calloc은 0으로 자동초기화
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