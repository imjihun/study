#include "tree.h"

BinaryTreeNode* get_node(){
	BinaryTreeNode* tmp = (BinaryTreeNode*)calloc(sizeof(BinaryTreeNode),1);

	return tmp;
}

int insert_data (BinaryTreeNode** head, BinaryTreeData data){

	return 0;
}
/*
BinaryTreeNode* find_position(BinaryTreeNode** cur, int no){
	if(!(*cur))
		return (*cur);
	else if(no < (*cur)->data.no){
		cur = &(*cur)->link[0];
	}else{
		cur = &(*cur)->link[1];
	}

	return find_position(cur, no);
}
*/
int insert_data (BinaryTreeNode** cur, int no){
	if(!(*cur)){
		(*cur) = get_node();
		(*cur)->data.no = no;
		return 0;
	}else if(no < (*cur)->data.no){
		cur = &(*cur)->link[0];
	}else{
		cur = &(*cur)->link[1];
	}
	insert_data(cur,no);
	return 0;
}
int preorder(BinaryTreeNode* cur){
	if(cur){	
		printf("%d  ", cur->data.no);
		preorder(cur->link[0]);
		preorder(cur->link[1]);
	}
	return 0;
}/*
int swap_link(BinaryTreeNode** dst, BinaryTreeNode** src){
	BinaryTreeNode* tmp[3];
	
	tmp[0] = (*dst);
	tmp[1] = (*dst)->link[0];
	tmp[2] = (*dst)->link[1];
	
	(*dst) = 
	(*dst)->link[0] = 
	(*dst)->link[1] = 
	
	(*dst) = tmp1[0];
	(*dst)->link[0] = tmp1[1];
	(*dst)->link[1] = tmp1[2];
	return 0;
}
int del_root(BinaryTreeNode** root){
	BinaryTreeNode** child = NULL;
	if(!((*root)->link[0]) && !((*root)->link[0])){
		free(*root);
		(*root)=NULL;
		return NULL;
	}
	if((*root)->link[0]){
		child = &(*root)->link[0];
		while((*child)->link[1])
			child = &(*child)->link[1];
	}else{
		child = &(*root)->link[1];
		while((*child)->link[0])
			child = &(*child)->link[0];
	}
	swap_link(root, child);
	del_root(child);
	return 0;
}
int del_data(BinaryTreeNode** root, int no){
	if(!(*root))
		return -1;
	
	while((*root)){
		if((*root)->data.no == no){
			del_root(root);
		}else if(no < (*root)->data.no){
			root = &(*root)->link[0];
		}else{
			root = &(*root)->link[1];
		}
	}
	return 0;
}*/

BinaryTreeNode *chg_node(BinaryTreeNode *root){
	BinaryTreeNode* tmp = NULL;
	if(root->link[0]){
		tmp = root->link[0];
	}
	else if(root->link[1]){
		tmp = root->link[1];
	}
	free(root);
	return tmp;
}
BinaryTreeNode *min_node(BinaryTreeNode *root, int *num){
	if(!(root->link[0])){
		(*num) = root->data.no;
		return chg_node(root);
	}
	root->link[0] = min_node(root->link[0], num);
	return root;
}
BinaryTreeNode *del_tree(BinaryTreeNode *root, int data){
	int num;

	if(root == NULL)
	{
		printf("Not Found\n");
		return NULL;
	}
	else if(root->data.no > data)
		root->link[0] = del_tree(root->link[0],data);
	else if(root->data.no < data)
		root->link[1] = del_tree(root->link[1], data);
	else if(root->link[0] && root->link[1])
	{
		root->link[1] = min_node(root->link[1], &num);
		root->data.no = num;
	}
	else
		root = chg_node(root);
	return root;
}

/*
pQueue chg_node(pQueue head){
	pQueue tmp = head->link;
	free(head);
	return tmp;
}
pQueue del_data(pQueue head, int data){
	if(head->data != data){
		head->link = del_data(head->link, data);
	}else{
		head = chg_node(head);
	}
	return head;
}
int sub_find_data(pQueue head, int data, int cnt){
	if(!(head)){
		printf("Not Find\n");
		return -1;
	}
	if(head->data == data){
		printf("%d번째에 위치\n", cnt);
		return cnt;
	}
	cnt++;
	return sub_find_data(head->link, data, cnt);
}
int find_data(pQueue head, int data){
	int cnt = 1;
	return sub_find_data(head, data, cnt);
}
int pop (pQueue *head, int *data){
	pQueue tmp;

	if((*head) == NULL){
		printf("Empty\n");
		(*data)=0;
		return -1;
	}
	tmp = (*head);
	(*head) = tmp->link;
	(*data) = tmp->data;
	free(tmp);
	return 0;
}
int print_queue(pQueue head){
	pQueue cur = head;

	while(cur){
		printf("data = %d\n", cur->data);
		cur= cur->link;
	}
	return 0;
}*/