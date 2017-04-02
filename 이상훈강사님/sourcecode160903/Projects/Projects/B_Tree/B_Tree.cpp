#include "B_Tree.h"

BtreeNode* get_node(void){
	BtreeNode* tmp = NULL;
	tmp = (BtreeNode*)calloc(sizeof(BtreeNode), 1);
	return tmp;
}
void cpy_data(Data *dst, Data *src){
	(*dst) = (*src);
}
void set_data(Data *data, int no){
	data->no = no;
	data->name[0] = '\0';
}
void set_node(BtreeNode* dst){
	int i;
	for(i=0; i<MAX_DEGREE-1; i++){
		set_data(&dst->data[i], 0);
		dst->link[i] = NULL;
	}
	dst->link[i] = NULL;
	dst->fill_cnt=0;
}
void print_tree(BtreeNode *root){
	sub_print_tree(root, 1, 1);
}
int sub_print_tree(BtreeNode *root,int x, int y){
	int i;
	if(root){
		for(i=0; i<root->fill_cnt; i++){
			x = sub_print_tree(root->link[i], x, y+1);
			COORD pos = {x, y};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			printf("%3d", root->data[i].no);
		}
		x = sub_print_tree(root->link[i], x, y+1);
		return x+5;
	}
	return x;
}
int insert_data(BtreeNode **root, int no){
	Data data;
	Data eData;
	BtreeNode *eLink=NULL, *tmp = NULL;
	int ret;

	set_data(&data, no);

	ret = insert_data(root, data, NULL, &eData, &eLink);
	if(ret == 1){
		new_root(root, eData, eLink);
		ret = 0;
	}
	return ret;
}
int insert_data(BtreeNode **root, Data data, BtreeNode *link, Data *eData, BtreeNode **eLink){
	int i, ret = 0;
	if(!(*root)){
		(*root) = get_node();
		cpy_data(&(*root)->data[0], &data);
		(*root)->fill_cnt++;
		return 0;
	}else if(!(*root)->link[0]){						///////leaf노드부터 삽입이 시작된다.
		ret = insert_data_toNode(root, data, link, eData, eLink);
		return ret;
	}else{				///////////////////////////////////else 재귀로 탐색
		for(i=0; i<(*root)->fill_cnt; i++){
			if(data.no < (*root)->data[i].no){
				ret = insert_data(&(*root)->link[i], data, link, eData, eLink);
			}else if(data.no == (*root)->data[i].no){
				printf("already exist\n");
				return -1;
			}else if(i == (*root)->fill_cnt-1){
				ret = insert_data(&(*root)->link[i+1], data, link, eData, eLink);
			}
		}
	}
	if(ret)												//재귀 돌아오면서 elevate값이 있으면 삽입
		ret = insert_data_toNode(root, *eData, *eLink, eData, eLink);
	
	return ret;
}
void new_root(BtreeNode **root, Data data, BtreeNode *link){
	BtreeNode* tmp = NULL;
	tmp = get_node();
	tmp->link[0] = *root;
	cpy_data(&tmp->data[0], &data);
	tmp->link[1] = link;
	tmp->fill_cnt++;
	(*root) = tmp;
}
void split(BtreeNode **cur, Data data, BtreeNode *link, Data *eData, BtreeNode **eLink){
	int cur_i;
	int big_i;
	Data bigData[MAX_DEGREE];
	BtreeNode *bigLink[MAX_DEGREE+1];
	////////////////////////////////create bignode
	for(cur_i = 0; cur_i<(*cur)->fill_cnt; cur_i++){
		if(data.no > (*cur)->data[cur_i].no){
			bigLink[cur_i] = (*cur)->link[cur_i];
			cpy_data(&bigData[cur_i],&(*cur)->data[cur_i]);
		}else{
			break;
		}
	}
	bigLink[cur_i] = (*cur)->link[cur_i];
	cpy_data(&bigData[cur_i], &data);
	bigLink[cur_i +1] = link;
	for(;  cur_i<(*cur)->fill_cnt; cur_i++){
		cpy_data(&bigData[cur_i +1], &(*cur)->data[cur_i]);
		bigLink[cur_i +2] = (*cur)->link[cur_i +1];
	}
	/////////////////////////////////end create bignode
	set_node((*cur));
	for(big_i = 0; big_i < MAX_DEGREE/2; big_i++){
		(*cur)->link[big_i] = bigLink[big_i];
		cpy_data(&(*cur)->data[big_i], &bigData[big_i]);
		(*cur)->fill_cnt++;
	}
	(*cur)->link[big_i] = bigLink[big_i];			//end 첫번째노드

	cpy_data(eData, &bigData[big_i]);
	(*eLink) = get_node();							//elevate값

	for(big_i += 1, cur_i=0; big_i<MAX_DEGREE; big_i++, cur_i++){
		(*eLink)->link[cur_i] = bigLink[big_i];
		cpy_data(&(*eLink)->data[cur_i], &bigData[big_i]);
		(*eLink)->fill_cnt++;
	}
	(*eLink)->link[cur_i] = bigLink[big_i];		//end 두번째노드
	return ;
}
int split_chk(BtreeNode *cur, BtreeNode* eLink){
	if(cur){
		if(cur->fill_cnt == MAX_DEGREE-1 && (!cur->link[0] || eLink))	//(cur가 리프노드이면서 꽉찼으면) or (elevate값이 있는데 꽉찼으면)
			return 1;
	}
	return 0;
}
int insert_data_toNode(BtreeNode **cur, Data data, BtreeNode *link, Data *eData, BtreeNode **eLink){
	int i, j;
	if(split_chk(*cur, link)){					///////자리가 없으면 스플릿&elevate
		split(cur, data, link, eData, eLink);
		return 1;
	}else{										///////데이터자리가 있으면 삽입
		for(i=0; i<(*cur)->fill_cnt; i++){
			if(data.no < (*cur)->data[i].no)
				break;
		}
		for(j=(*cur)->fill_cnt; j>i; j--){	///////i= 데이터 삽입할 인덱스
			cpy_data(&(*cur)->data[j], &(*cur)->data[j-1]);
		}
		cpy_data(&(*cur)->data[i], &data);
		(*cur)->fill_cnt++;

		(*eLink) = NULL;							//elevate되는 값은 없다.
		return 0;
	}
}