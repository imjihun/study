
#include <stdio.h>
#include <malloc.h>

struct node{
	int data;
	struct node * link;
};
typedef struct node* pQueue;

/////////////////////////////

pQueue get_node();
int enQueue (pQueue *head, int data);
int sub_find_data(pQueue head, int data, int cnt);
int find_data(pQueue head, int data);

pQueue chg_node(pQueue head);
pQueue del_data(pQueue head, int data);
int pop (pQueue *head, int *data);
int print_queue(pQueue head);









/*
#include<stdio.h>
#include<malloc.h>
struct queueNode{
	int data;
	struct queueNode* link;
};
typedef struct queueNode QueueNode;

QueueNode* get_node(){
	QueueNode* tmp = (QueueNode*)calloc(sizeof(QueueNode),1);
	return tmp;
}
QueueNode* subenQueue(QueueNode *head, int data){
	if(!(head)){
		(head) = get_node();
		(head)->data = data;
	}else{
		(head)->link = subenQueue((head)->link, data);
	}
	return (head);
}
int enQueue(QueueNode **head, int data){
	(*head) = subenQueue ((*head), data);
	return 0;
}
int sub_print_queue(QueueNode *head){
	if(head){
		printf("%d  ", head->data);
		sub_print_queue(head->link);
	}else{
		return -1;
	}
	return 0;
}
int print_queue(QueueNode *head){
	if(sub_print_queue(head))
		printf("empty");
	printf("\n");
}
QueueNode* get_nextLink(QueueNode *head){
	QueueNode* tmp = head->link;
	free(head);
	return tmp;
}
QueueNode* sub_del_data(QueueNode *head, int data){
	if(!head){
		printf("Not Found\n");
	}
	else if(head->data==data){
		head = get_nextLink(head);
	}else{
		head->link = sub_del_data(head->link, data);
	}
	return head;
}
int del_data(QueueNode **head, int data){
	(*head) = sub_del_data(*head, data);
	return 0;
}
int main(void){
	QueueNode *head =NULL;
	int i;
	print_queue(head);
	for(i=0; i<8; i++){
		enQueue(&head, i*10);
	}
	print_queue(head);
	del_data(&head, 0);
	print_queue(head);
	del_data(&head, 70);
	print_queue(head);
	del_data(&head, 30);
	print_queue(head);
	del_data(&head, 50);
	print_queue(head);
	return 0;
}
*/
/*
int del_data(QueueNode **head, int data){
	QueueNode* prev = NULL, *cur = (*head);
	QueueNode* tmp = NULL;
	while(cur){
		if((cur)->data==data){
			if(!prev){
				tmp = (*head);
				(*head) = (*head)->link;
				free(tmp);
			}else{
				tmp = (cur);
				(prev)->link = (cur)->link;
				free(tmp);
			}
			return 0;
		}else{
			prev = cur;
			cur = cur->link;
		}
	}
	return -1;
}*/