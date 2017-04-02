//�Լ� ó������ ��ȯŸ�� void
#include "sample.h"
//#�� ��ó�� 
//��ó��(#)�� ó���Ǵ� ���̵��� ;�� �ƴ϶� �ٹٲ����� �ν��ؼ� ;�� �ʿ�X
//�������� �����Ϸ��� ó��
//�����Ϸ��� ó���ϴ� ���̵��� ������ ;���� ��������

//C���� ����ü ���� �������Ҷ� �����ĺ��� �빮�ڷ� ex)FILE *fp;
//

//C++���� ù���ڸ� �빮���� �͵��� Ŭ���� ex)String str;
struct Content{
	int no;
	char title[80];
	char writer[80];
	char memo[512];
};
typedef struct Content* PContent; //���� ������ struct Content* -> PContent

PContent	db=NULL;
int size = 0;	//���簳���̸鼭 �ִ밳��
void board_list(){//�Լ��� ���鶧 �Ųٷ�(���۸���?)
	int i;
	PContent contentP;

	if(size == 0){ printf("empty\n"); return;}
	else{
		for(i=0;i<size;i++){
			contentP = &db[i]; // �ٷ��������� �迭�ȿ� �ִ� ��Ҹ� �ϳ� �������� ������ �׻� ������
			printf("%3d %s %s\n", contentP->no, contentP->title, contentP->writer);
		}
		return;
	}
}

int board_add(const char* title, char* memo, char* id){
	struct Content temp;//�迭���� �ٷ� ����������� �ϳ��� ���� �߰��ϴ°���! �ϳ��� ����°����� �׻󸸵���

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
