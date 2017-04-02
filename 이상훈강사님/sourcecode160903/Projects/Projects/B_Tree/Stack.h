#include "B_Tree.h"

/////////////////////stack
struct Stackdata{
	BtreeNode* data;
	int th;
};
typedef struct Stackdata StackData;

struct Stacknode{
	StackData data;
	struct Stacknode* link;
};
typedef struct Stacknode StackNode;
/////////////////////stack

StackNode* get_stack_node(void);
int cpy_StackData(StackData* dst, StackData* src);
int push_stack(StackNode **header, StackData* data);
int pop_stack(StackNode **header, StackData* getData);
int set_StackData(StackData* dst, BtreeNode* src1);
int set_StackData(StackData* dst, BtreeNode* pBtree, int th);