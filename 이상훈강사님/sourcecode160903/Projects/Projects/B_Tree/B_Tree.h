#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

#define MAX_NAME_SIZE	80	//노드당 최대 이름데이터
#define MAX_DEGREE		4	//노드당 최대 차수


struct data{
	char name[MAX_NAME_SIZE];
	int no;
};
typedef struct data Data;
struct Btreenode{
	Data data[MAX_DEGREE-1];		//키값(차수-1)
	struct Btreenode *link[MAX_DEGREE];		//링크(차수)
	int fill_cnt;
};
typedef struct Btreenode BtreeNode;


int insert_data(BtreeNode **root, int no);
void print_tree(BtreeNode *root);
////////////////////////////////////////////////
int sub_print_tree(BtreeNode *root, int x, int y);
int insert_data(BtreeNode **root, Data data, BtreeNode *link, Data *eData, BtreeNode **eLink);
int insert_data_toNode(BtreeNode **cur, Data data, BtreeNode *link, Data *eData, BtreeNode **eLink);
int split_chk(BtreeNode *cur, BtreeNode* eLink);
void split(BtreeNode **cur, Data data, BtreeNode *link, Data *eData, BtreeNode **eLink);
void set_node(BtreeNode* dst);
BtreeNode* get_node(void);
void cpy_data(Data *dst, Data *src);
void set_data(Data *data, int no);
void new_root(BtreeNode **root, Data data, BtreeNode *link);
void cpy_node(BtreeNode* dst, BtreeNode* src);