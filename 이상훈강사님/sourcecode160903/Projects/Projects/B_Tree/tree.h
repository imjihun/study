
#include <stdio.h>
#include <malloc.h>
#define DEGREE 2
struct BinaryTreedata{
	int no;
};
typedef struct BinaryTreedata BinaryTreeData;

struct BinaryTreenode{
	BinaryTreeData data;
	struct BinaryTreenode *link[2];
};
typedef struct BinaryTreenode BinaryTreeNode;

/////////////////////////////

int insert_data (BinaryTreeNode** cur, int no);
int insert_data (BinaryTreeNode** head, BinaryTreeData data);
int preorder(BinaryTreeNode* cur);
int del_data(BinaryTreeNode** cur, int no);
BinaryTreeNode *del_tree(BinaryTreeNode *root, int data);

BinaryTreeNode* get_node();































/*#include<stdio.h>
#include<malloc.h>

struct treeNode{
	int data;
	struct treeNode* link[2];
};
typedef struct treeNode TreeNode;
int preorder(TreeNode* head){
	if(head){
		preorder(head->link[0]);
		printf("%d ", head->data);
		preorder(head->link[1]);
	}
}
TreeNode* get_node(){
	TreeNode* tmp = (TreeNode*)calloc(sizeof(TreeNode), 1);
	return tmp;
}
TreeNode* sub_insert_data(TreeNode* root, int data){
	if(root){
		if(data < (root)->data)
			root->link[0] = sub_insert_data((root)->link[0], data);
		else if(data > (root)->data)
			root->link[1] = sub_insert_data((root)->link[1], data);
		else{
			printf("already\n");
		}
	}else{
		(root) = get_node();
		(root)->data = data;
	}
	return root;
}
int insert_data(TreeNode** root, int data){
	(*root) = sub_insert_data(*root, data);
	return 0;
}
TreeNode* get_nextLink(TreeNode* root){
	TreeNode* tmp = NULL;
	if(root->link[0]){
		tmp = root->link[0];
	}else if(root->link[1]){
		tmp = root->link[1];
	}else{
		tmp = NULL;
	}
	free(root);
	return tmp;
}
TreeNode* get_max_node(TreeNode* root, int* data){
	if(root->link[1]){
		root->link[1] = get_max_node(root->link[1], data);
	}else{
		(*data) = root->data;
		root = get_nextLink(root);
	}
	return root;
}
TreeNode* sub_del_data(TreeNode* root, int data){
	int tmp;
	if(root){
		if(data < root->data){
			root->link[0] = sub_del_data(root->link[0], data);
		}else if(data > root->data){
			root->link[1] = sub_del_data(root->link[1], data);
		}else{
			if(root->link[0] && root->link[1]){
				root->link[0] =  get_max_node(root->link[0], &tmp);
				root->data = tmp;
			}else{
				root = get_nextLink(root);
			}
		}
	}else{
		printf("Not Found");
	}
	return root;
}
int del_data(TreeNode** root, int data){
	(*root) = sub_del_data(*root, data);
	return 0;
}
int main (void){
	int i;
	int arr[20] = {45, 27, 17, 62, 57, 73, 52, 65, 76, 69, 63, 64, 71};
	TreeNode* root = NULL;

	for(i=0; arr[i]; i++)
		insert_data(&root, arr[i]);
	
	preorder(root);
	printf("\n");
	del_data(&root, 17);
	preorder(root);
	printf("\n");
	return 0;
}*/