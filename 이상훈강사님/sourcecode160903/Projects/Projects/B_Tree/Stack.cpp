#include "Stack.h"
///////////////////////////stack
StackNode* get_stack_node(){
	StackNode* tmp = NULL;
	tmp = (StackNode*)calloc(sizeof(StackNode),1);

	return tmp;
}
int set_StackData(StackData* dst, BtreeNode* pBtree){
	dst->data = pBtree;
	dst->th=0;
}
int set_StackData(StackData* dst, BtreeNode* pBtree, int th){
	dst->data = pBtree;
	dst->th = th;
}
int cpy_StackData(StackData* dst, StackData* src){
	dst->data = src->data;
}

int push_stack(StackNode **header, StackData* data){
	StackNode *tmp = (*header);
	
	(*header) = get_stack_node();

	cpy_StackData(&(*header)->data,data);
	(*header)->link = tmp;

	return 0;
}

int pop_stack(StackNode **header, StackData* getData){
	StackNode* tmp = (*header);
	if(!tmp){
		//printf("Stack is empty!!!\n");
		return -1;
	}

	cpy_StackData(getData, &(tmp->data));
	(*header) = tmp->link;

	free(tmp);
	return 0;
}
//////////////////////////end_stack