#include "AVLtree.h"

AVLNode* get_node(){
	AVLNode *tmp = (AVLNode*)calloc(sizeof(AVLNode),1);

	return tmp;
}
int set_data(Data* dst, int no){
	dst->no = no;
	return 0;
}
int cpy_data(Data* dst, Data* src){
	(*dst) = (*src);
	return 0;
}
int compare_height(AVLNode* src1, AVLNode* src2){
	if(!src1 && !src2){ return 0;}
	else if(!src1) { return -src2->height;}
	else if(!src2) { return src1->height;}
	else
		return src1->height - src2->height;
}
int sub_rotate(AVLNode **cur, int index1, int index2){//(index1=0, index2=1)=rotate_right, (index1=1, index2=0)=rotate_left
	AVLNode* tmp = (*cur);
	
	(*cur) = (*cur)->link[index1];
	
	tmp->link[index1] = tmp->link[index1]->link[index2];
	(*cur)->link[index2] = tmp;
	return 0;
}
int rotate_chk(AVLNode *cur){			//높이차이는 한단계에 2이상씩 날수가 없다.
	int comp = compare_height(cur->link[0], cur->link[1]);
	if(comp>1){
		cur = cur->link[0];
		comp = compare_height(cur->link[0], cur->link[1]);
		if(comp>0){
			return LL;					//오른쪽으로 한번
		}else{
			return LR;					//왼쪽으로한번 오른쪽으로한번
		}
	}else if(comp<-1){
		cur = cur->link[1];
		comp = compare_height(cur->link[0], cur->link[1]);
		if(comp<0){
			return RR;					//왼쪽으로 한번
		}else{
			return RL;					//오른쪽으로한번 왼쪽으로한번
		}
	}
	return 0;							//not rotate
}
int rotate(AVLNode **cur, int c){
	switch (c){
	case LL:						//오른쪽
		sub_rotate(cur, 0, 1);
		printf("LL\n");
		break;
	case LR:						//왼쪽, 오른쪽
		sub_rotate(&(*cur)->link[0], 1, 0);
		sub_rotate(cur, 0, 1);
		printf("LR\n");
		break;
	case RR:						//왼쪽
		sub_rotate(cur, 1, 0);
		printf("RR\n");
		break;
	case RL:						//오른쪽,왼쪽
		sub_rotate(&(*cur)->link[1], 0, 1);
		sub_rotate(cur, 1, 0);
		printf("RL\n");
		break;
	}
	(*cur)->link[0]->height = get_height((*cur)->link[0]);
	(*cur)->link[1]->height = get_height((*cur)->link[1]);
	(*cur)->height = get_height((*cur));
	return c;
}
int get_height(AVLNode *cur){
	int max = 0;
	if(cur){
		if(cur->link[0])
			max = cur->link[0]->height;

		if(cur->link[1]){
			if(max < cur->link[1]->height)
				max = cur->link[1]->height;
		}
		return max+1;
	}
	return 0;
}
int insert_data(AVLNode **root, Data data){
	int rot_chk;
	int ret;
	if(!(*root)){
		(*root) = get_node();
		cpy_data(&(*root)->data, &data);
		ret = 0;
	}
	else if((*root)->data.no == data.no){
//		printf("already exist\n");
		return -100;
	}else if(data.no < (*root)->data.no){
		ret = insert_data(&(*root)->link[0], data);
	}else{
		ret = insert_data(&(*root)->link[1], data);
	}
	(*root)->height = get_height((*root));

	rot_chk = rotate_chk((*root));
	rot_chk ? rotate(root, rot_chk) : 0;

	return ret;
}
int insert_data(AVLNode **root, int no){
	Data data;
	set_data(&data, no);

	return insert_data(root, data);
}

void print_tree(AVLNode *root){
	sub_print_tree(root, 0, 5);
	getchar();
	system("cls");
}
int sub_print_tree(AVLNode *root,int x, int y){
	COORD pos;
	if(root){
		x = sub_print_tree(root->link[0], x, y+2);
		pos.X = x; pos.Y =y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		printf("%-2d", root->data.no);
		x = sub_print_tree(root->link[1], x+2, y+2);
	}
	return x;
}
int preorder(AVLNode *root){
	if(root){
		printf("%d ", root->data.no);
		preorder(root->link[0]);
		preorder(root->link[1]);
	}
	return 0;
}

AVLNode* del_queue(AVLNode* cur){
	AVLNode *tmp = (cur);
	if((cur)->link[0])
		(cur) = (cur)->link[0];
	else
		(cur) = (cur)->link[1];

	free(tmp);
	return cur;
}
int del_minOfChild(AVLNode **cur, Data* getMinData){
	int rot_chk = 0;
	int ret = 0;
	if((*cur)->link[0]){
		ret = del_minOfChild(&(*cur)->link[0], getMinData);

		(*cur)->height = get_height((*cur));//로테이트

		rot_chk = rotate_chk((*cur));
		rot_chk ? rotate(cur, rot_chk) : 0;
	}
	else{
		cpy_data(getMinData, &(*cur)->data);
		(*cur) = del_queue((*cur));
		ret = 0;
	}
	return ret;
}
int del_data(AVLNode** root, Data data){
	Data minData;
	int ret = 0;
	int rot_chk;
	if(!(*root)){
		printf("Not Found\n");
		return -1;
	}
	if((*root)->data.no == data.no){
		if((*root)->link[0] && (*root)->link[1]){
			ret = del_minOfChild(&(*root)->link[1], &minData);
			cpy_data(&(*root)->data, &minData);
		}else{					//queue삭제
			(*root) = del_queue((*root));
		}
	}else if(data.no < (*root)->data.no){
		ret = del_data(&(*root)->link[0], data);
	}else{
		ret = del_data(&(*root)->link[1], data);
	}
	if((*root)){				//로테이트
		(*root)->height = get_height((*root));

		rot_chk = rotate_chk((*root));
		rot_chk ? rotate(root, rot_chk) : 0;
	}
	return ret;
}
int del_data(AVLNode** root, int no){
	Data data;
	set_data(&data, no);
	
	return del_data(root, data);
}

/*
AVLNode* ll_rot(AVLNode *p, AVLNode *c){
	p->link[0] = c->link[1];
	c->link[1] = p;
	p->height = get_height(p);
	c->height = get_height(c);

	return c;
}
AVLNode* rl_rot(AVLNode *p, AVLNode *c){
	c = ll_rot(c, c->link[0]);

	return rr_rot(c, p);
}
AVLNode* rr_rot(AVLNode *p, AVLNode *c){
	p->link[1] = c->link[0];
	c->link[0] = p;
	p->height = get_height(p);
	c->height = get_height(c);

	return c;
}


int height_mod(AVLNode* cur){
	int max = 0;
	if(cur){
		if(cur->link[0])
			max = cur->link[0]->height;
		if(cur->link[1]){
			if(max < cur->link[1]->height)
				max = cur->link[1]->height;
		}
	}
	return max+1;
}
int height_chk(AVLNode *cur){
	if(cur->right && cur->left){ return cur->right->lev - cur->left->lev;}
	else if(cur->right) { return cur->right->lev;}
	else if(cur->left) { return -cur->left->lev;}
	else
		return 0;
}
int rot_chk(AVLNode *cur, Data data){
	if(lev_chk(root) < 0)
	{
		if(lev_chk(root->left) > -1)// && root->left->data < data)
			return LR;
		return LL;
	}
	else
	{
		if(lev_chk(root->right) < 1)// && root->left->data > data)
			return RL;
		return RR;
	}

	return 0;
}
AVLNode* rot(AVLNode *cur, int chk){
	switch (chk){
	case LL:
		return ll_rot(root, root->left);
		break;
	case LR:
		return lr_rot(root, root->left);
		break;
	case RR:
		return rr_rot(root, root->left);
		break;
	case RL:
		return rl_rot(root, root->left);
		break;
	}
	return 0;
}
int insert_data_withteacher (AVLNode** root, Data data){
	int abs;

	if(!(*root)){
		(*root) = get_node();
		cpy_data(&(*root)->data,&data);
//		(*root)->height = height_mod(*root);
		return 0;
	}else if(data.no < (*root)->data.no){
		insert_data_withteacher(&(*root)->link[0],data);
	}else{
		insert_data_withteacher(&(*root)->link[1],data);
	}
	(*root)->height = height_mod(*root);

	abs = height_chk(*root);
	abs = abs < 0 ? -abs : abs;

	if(abs > 1)
		*root = rot(*root, rot_chk(*root, data));
	return 0;
}
*/
/*
int rotate_right(AVLNode **cur){//a/b/c -> a/b\c
	AVLNode* tmp = (*cur);
	
	(*cur) = (*cur)->link[0];
	
	tmp->link[0] = tmp->link[0]->link[1];
	(*cur)->link[1] = tmp;
}
int rotate_linear_right(AVLNode **cur){//a\(b/c) -> a\b\c
	AVLNode* tmp = (*cur)->link[1]; 

	(*cur)->link[1] = (*cur)->link[1]->link[0];

	tmp->link[0] = tmp->link[0]->link[1];
	(*cur)->link[1]->link[1] = tmp;
}
*/
/*
int rotate_left(AVLNode **cur){//a\b\c -> a/b\c
	AVLNode* tmp = (*cur);
	
	(*cur) = (*cur)->link[1];
	
	tmp->link[1] = tmp->link[1]->link[0];
	(*cur)->link[0] = tmp;
}
int rotate_linear_left(AVLNode **cur){//(a\b)/c -> a/b/c
	AVLNode* tmp = (*cur)->link[0]; 

	(*cur)->link[0] = (*cur)->link[0]->link[1];

	tmp->link[1] = tmp->link[1]->link[0];
	(*cur)->link[0]->link[0] = tmp;
}*/




/*
int sub_insert_data(AVLNode **root, int childIndex, Data data, int *ret_diff_height, int *diff_height){
	*ret_diff_height = insert_data(&(*root)->link[childIndex], data);
	if(*ret_diff_height > -100){							//값이 존재하지 않으면 삽입됨
		(*root)->height = get_height((*root));
		*diff_height = compare_height((*root)->link[0], (*root)->link[1]);
		if(*diff_height > 1){							//leftchild가 rightchild보다 더 길다	->right회전
			if(*ret_diff_height < 0)							//단반향으로의 링크가 아닐시
				sub_rotate(&(*root)->link[0], 1, 0);				//자식을 반대로 돌려서 단반향으로
			sub_rotate(root, 0, 1);							//그리고 sub_rotate_right
			(*root)->link[0]->height = get_height((*root)->link[0]);
			(*root)->link[1]->height = get_height((*root)->link[1]);
			(*root)->height = get_height((*root));
			return (*diff_height)-1;
		}else if(*diff_height < -1){						//rightchild가 더 길다					->left회전
			if(*ret_diff_height > 0)							//단반향으로의 링크가 아닐시
				sub_rotate(&(*root)->link[1], 0, 1);				//자식을 반대로 돌려서 단반향으로
			sub_rotate(root, 1, 0);							//sub_rotate_left
			(*root)->link[0]->height = get_height((*root)->link[0]);
			(*root)->link[1]->height = get_height((*root)->link[1]);
			(*root)->height = get_height((*root));
			return (*diff_height)+1;
		}else{
			return *diff_height;
		}
	}else
		return -100;
}*/