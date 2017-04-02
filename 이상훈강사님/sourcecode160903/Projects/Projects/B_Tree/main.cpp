#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "AVLtree.h"
//#include "B_Tree.h"
#include "RBTree.h"
int main (void){
	/*
	//binary_tree
	int i;
	int arr[20] = {45, 27, 17, 62, 57, 73, 52, 65, 76, 69, 63, 64, 71};
	BinaryTreeNode* root = NULL;

	for(i=0; arr[i]; i++)
		insert_data(&root, arr[i]);
	
	preorder(root);
	printf("\n");
	root = del_tree(root, 62);
	preorder(root);
	printf("\n");
	*/
	/*
	//AVLtree
	int i;
	AVLNode* root = NULL;
	
	for(i=1; i<30; i++){
		insert_data(&root, i);
	}
	system("cls");
	print_tree(root);
	
	for(i=0; i<30; i++){
		del_data(&root, i);
		print_tree(root);
	}
	
	return 0;
	*/
	//RBTree
	int i;
	RBNode* root = NULL;
	for(i=1; i<25; i++){
	//	srand(time(NULL));
		ins_data(&root, i);
		//print_tree(root);
	}
	system("cls");
	print_tree(root);
	for(i=1; i<25; i++){
		dele_data(&root, i);
		print_tree(root);
	}
	
	/*
	for(i=1; i<25; i++){
		srand(time(NULL));
		del_data(&root, i);
		print_tree(root);
	}
	system("cls");
	print_tree(root);
	*/
	return 0;
	
	/*
	//Btree
	int i;
	int max = 50;
	BtreeNode *root = NULL;
	for(i=0; i<max; i++)
		insert_data(&root, rand()%max*10);

	print_tree(root);
    return 0;
	*/
}