//함수 처음에는 반환타입 void
#include "sample.h"
//#은 전처리 
//전처리(#)로 처리되는 아이들은 ;이 아니라 줄바꿈으로 인식해서 ;이 필요X
//나머지는 컴파일러로 처리
//컴파일러로 처리하는 아이들은 무조건 ;으로 끝내야함

//C언어에서 구조체 형명 재정의할때 모든알파벳을 대문자로 ex)FILE *fp;
//

//C++에서 첫글자만 대문자인 것들은 클래스 ex)String str;
struct Content{
	int no;
	char title[80];
	char writer[80];
	char memo[512];
};
typedef struct Content* PContent; //형명 재정의 struct Content* -> PContent

PContent	db=NULL;
int size = 0;	//현재개수이면서 최대개수
void board_list(){//함수를 만들때 거꾸로(동작먼저?)
	int i;
	PContent contentP;

	if(size == 0){ printf("empty\n"); return;}
	else{
		for(i=0;i<size;i++){
			contentP = &db[i]; // 바로하지말고 배열안에 있는 요소를 하나 가져오는 과정을 항상 만들어라
			printf("%3d %s %s\n", contentP->no, contentP->title, contentP->writer);
		}
		return;
	}
}

int board_add(const char* title, char* memo, char* id){
	struct Content temp;//배열에다 바로 집어넣지말고 하나를 만들어서 추가하는과정! 하나를 만드는과정을 항상만들어라

	if (size == 0) {temp.no=1;}
	else {temp.no = db[size-1].no+1;}
	if(title[0] == 0 || title == NULL) return -1;
	else strcpy(temp.title, title);
	if(memo[0] == 0 || memo == NULL) return -2;
	else strcpy(temp.memo, memo);
	if(id[0] == 0 || id == NULL) return -3;
	else strcpy(temp.writer, id);

	db = (PContent)realloc(db,sizeof(struct Content)*(size+1));
	db[size++]=temp;

	return 0;
}
void board_view(int no){
	struct Content temp;
	int i;

	for (i=0;i<size;i++){
		if (no == db[i].no){
			temp = db[i];
			printf("%3d %s [%s]\n::::%s\n\n", temp.no, temp.title, temp.writer, temp.memo);
			return;
		}
	}
	printf("Not Found\n\n");
}
