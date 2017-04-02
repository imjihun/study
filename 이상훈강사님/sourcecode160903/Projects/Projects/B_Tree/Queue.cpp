#include "Queue.h"

pQueue get_node(){
	pQueue tmp;

	tmp = (pQueue)malloc(sizeof(struct node));
	tmp->data=0;
	tmp->link=NULL;
	return tmp;
}

int enQueue (pQueue *head, int data){
	/*
	pQueue tmp, cur;

	tmp = get_node();
	tmp->data=data;

	cur = (*head);
	if(cur == NULL){
		(*head) = tmp;
		return 0;
	}
	
	while(cur->link != NULL){
		cur = cur->link;
	}
	cur->link = tmp;
	*/
	if((*head) == NULL){
		(*head) = get_node();
		(*head)->data = data;
		return 0;
	}
	enQueue(&(*head)->link, data);
	return 0;
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
	/*
	pQueue cur = head;
	int cnt = 1;

	while(cur){
		if(cur->data == data){
			printf("%d번째에 위치\n", cnt);
			return cnt;
		}
		cur = cur->link;
		cnt++;
	}
	printf("Not Find\n");
	return -1;
	*/
	int cnt = 1;
	return sub_find_data(head, data, cnt);
}
pQueue chg_node(pQueue head){
	pQueue tmp = head->link;
	free(head);
	return tmp;
}
pQueue del_data(pQueue head, int data){	
	if(head == NULL)
	{
		printf("Not Found\n");
		return NULL;
	}
	else if(head->data != data){
		head->link = del_data(head->link, data);
	}else{
		head = chg_node(head);
	}
	return head;
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
}
/*
int main(void)
{
	pQueue head = NULL;
	int data=0;
	int i;
	
	enQueue(&head, 10);
	enQueue(&head, 20);
	enQueue(&head, 30);
	if(!pop(&head,&data))
		printf("%d\n", data);
	if(!pop(&head,&data))
		printf("%d\n", data);
	if(!pop(&head,&data))
		printf("%d\n", data);
	if(!pop(&head,&data))
		printf("%d\n", data);
		

	for(i=1; i<8; i++){
		enQueue(&head, i*10);
	}
	
	head = del_data(head,20);
	head = del_data(head,70);
	print_queue(head);
	find_data(head, 30);

	return 0;
}
*/