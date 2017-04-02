#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
#include <time.h>
#define RR	1
#define RL	2
#define LL	3
#define LR	4

struct data{
	int no;
};
typedef struct data Data;

struct avlnode{
	Data data;
	int height;
	struct avlnode* link[2];
};
typedef struct avlnode AVLNode;

int insert_data(AVLNode **root, int no);
void print_tree(AVLNode *root);
int sub_print_tree(AVLNode *root,int x, int y);
int preorder(AVLNode *root);
int del_data(AVLNode** root, int no);
/////////////////////////////////
int rotate(AVLNode **cur, int index1, int index2);
int insert_data(AVLNode **root, Data data);
int sub_insert_data(AVLNode **root, int childIndex, Data data, int *ret_diff_height, int *diff_height);
int get_height(AVLNode *cur);
int compare_height(AVLNode* src1, AVLNode* src2);
int cpy_data(Data* dst, Data* src);
int set_data(Data* dst, int no);
AVLNode* get_node();


int insert_data_withteacher (AVLNode** root, Data data);
AVLNode* del_queue(AVLNode* cur);
int del_minOfChild(AVLNode **cur, Data* getMinData);
int del_data(AVLNode** root, Data data);