#include <stdio.h>
#include <malloc.h>
#include <Windows.h>


#define RED				1
#define BLACK			2

#define NON				0
#define RR				11
#define RL				12
#define LL				13
#define LR				14
#define UP_CLRCHG		25
#define DOWN_CLRCHG		26
#define ROOT_ROTATE		30

struct data{
	int no;
};
typedef struct data Data;

struct rbnode{
	Data data;
	short color;
	struct rbnode *parent;
	struct rbnode *link[2];
};
typedef struct rbnode RBNode;

void set_data(Data *data, int no);
void cpy_data(Data *dst, Data *src);
int insert_data(RBNode **root, Data data);

int rot_chk(RBNode *cur);
void sub_rotate(RBNode **cur, int a, int b);
void rotate(RBNode **cur, int chk);
int chg_clr_chk(RBNode *cur);
void chg_color(RBNode *cur, int chk);
void print_tree(RBNode *root);
int sub_print_tree(RBNode *root,int x, int y);

int del_data(RBNode **root, Data data);
int del_max(RBNode **cur, Data* getMax);
int del_queue(RBNode **cur);


int ins_data(RBNode **root, Data data);
RBNode *_ins_val_chk(RBNode *cur);

int dele_data(RBNode **root, int no);
int dele_data(RBNode **root, Data data);
int _dele_val_chk(RBNode **root, RBNode *p, int clr, Data data);

void del_data(RBNode **root, int no);
void insert_data(RBNode **root, int no);
int ins_data(RBNode **root, int no);