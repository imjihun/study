#include "RBTree.h"


RBNode *get_node(){
	RBNode *tmp = (RBNode*)calloc(sizeof(RBNode),1);

	return tmp;
}


void cpy_data(Data *dst, Data *src){
	(*dst) = (*src);
}
void set_data(Data *data, int no){
	data->no = no;
}


void insert_data(RBNode **root, int no){
	Data data;
	set_data(&data, no);

	insert_data(root, data);
	if(*root)
		(*root)->color = BLACK;
}
int rot_chk(RBNode *cur){
	RBNode *tmp = NULL;
	if(cur){
		if(cur->link[0] && cur->link[0]->color == RED){
			tmp = cur->link[0];
			if(tmp && tmp->link[0] && tmp->link[0]->color == RED){
				return LL;
			}else if(tmp && tmp->link[1] && tmp->link[1]->color == RED){
				return LR;
			}
		}else if(cur->link[1] && cur->link[1]->color == RED){
			tmp = cur->link[1];
			if(tmp && tmp->link[0] && tmp->link[0]->color == RED){
				return RL;
			}else if(tmp && tmp->link[1] && tmp->link[1]->color == RED){
				return RR;
			}
		}
	}
	return NON;
}
void sub_rotate(RBNode **cur, int a, int b){
	RBNode *tmp = (*cur);
	(*cur) = (*cur)->link[a];
	(*cur)->parent = tmp->parent;

	tmp->link[a] = (*cur)->link[b];
	if(tmp->link[a])
		tmp->link[a]->parent = tmp;

	(*cur)->link[b] = tmp;
	tmp->parent = (*cur);
}
void rotate(RBNode **cur, int chk){
	int ind1=0, ind2=0;
	static int cnt = 0;
	if(chk){
		switch (chk){
		case RR:
			sub_rotate(cur, 1, 0);
			printf("RRrotate\n");
			break;
		case RL:
			sub_rotate(&(*cur)->link[1], 0, 1);
			sub_rotate(cur, 1, 0);
			printf("RLrotate\n");
			break;
		case LL:
			sub_rotate(cur, 0, 1);
			printf("LLrotate\n");
			break;
		case LR:
			sub_rotate(&(*cur)->link[0], 1, 0);
			sub_rotate(cur, 0, 1);
			printf("LRrotate\n");
			break;
		case NON:
			return ;
		}
	
		(*cur)->color = BLACK;
		if((*cur)->link[0])
			(*cur)->link[0]->color = RED;
		if((*cur)->link[1])
			(*cur)->link[1]->color = RED;
	
		//red노드의 갯수를 줄이는게 좋은가? 탐색에서의 시간이 logN에 가까워진다.
		/*
		(*cur)->color = RED;					
		(*cur)->link[0]->color = BLACK;
		(*cur)->link[1]->color = BLACK;
		*/
	
		cnt++;
		printf("((%d))", cnt);
	}
}
int chg_clr_chk(RBNode *cur){
	if(cur){
		if(cur->color == BLACK){
			if(cur->link[0] && cur->link[1] && cur->link[0]->color==RED && cur->link[1]->color==RED){
				return UP_CLRCHG;
			}
		}/*
		if(cur->color == RED){
			if(cur->link[0] && cur->link[1] && cur->link[0]->color==BLACK && cur->link[1]->color==BLACK){
				return DOWN_CLRCHG;
			}
		}*/
	}
	return NON;
}
void chg_color(RBNode *cur, int chk){
	if(chk == UP_CLRCHG){
		cur->color=RED;
		cur->link[0]->color = BLACK;
		cur->link[1]->color = BLACK;
		printf("upside color change\n");
	}else{
		cur->color=BLACK;
		cur->link[0]->color = RED;
		cur->link[1]->color = RED;
		printf("downside color change\n");
	}
}
int insert_data(RBNode **root, Data data){
	int chk, ret;
	if(!(*root)){
		(*root) = get_node();
		cpy_data(&(*root)->data, &data);
		(*root)->color = RED;
		return 0;
	}else{
		if(data.no < (*root)->data.no){
			ret = insert_data(&(*root)->link[0], data);
			(*root)->link[0]->parent = (*root);
		}else if(data.no > (*root)->data.no){
			ret = insert_data(&(*root)->link[1], data);
			(*root)->link[1]->parent = (*root);
		}else{
			printf("!!!!!!!!!already exist!!!!!!!!!!\n");
			return -1;
		}
	}
	chk = chg_clr_chk(*root);				//최소의 로테이션을 실행하기위해 색변환을 로테이션보다 먼저 해준다.
	if(chk)
		chg_color(*root, chk);
	chk = rot_chk(*root);
	if(chk)
		rotate(root, chk);
	return ret;
}

//삭제후에 트리밸런스를 맞춰줄때
//루트노드에서의 탐색반대방향의 자식노드가 
//검정색이면 빨간색으로 바꾸고 색깔체크와 로테이트체크(모든경로의 검은색노드의 수는 같아야한다)
//빨간색이면 자식노드는 둘다 검은색일수 밖에 없으므로 down색변환후에 강제적으로 빨간색으로 바꾸고 색체크와로테이트체크
//빨간노드의 자식은 없거나 두개다블랙인 조건을 맞춰줘야한다(항상)
void valance_chk(RBNode **cur){
	if((*cur)->color == RED){

	}
}
void del_data(RBNode **root, int no){
	Data data;
	set_data(&data, no);
	del_data(root, data);
}
int del_queue(RBNode **cur){
	int clr = (*cur)->color;
	RBNode *tmp = (*cur);
	if((*cur)->link[0]){
		(*cur) = (*cur)->link[0];
	}
	else{
		(*cur) = (*cur)->link[1];
	}
	if(*cur)
		(*cur)->parent = tmp->parent;
	free(tmp);
	return clr;
}
int del_max(RBNode **cur, Data *getMaxData){
	if((*cur)->link[1])
		return del_max(&(*cur)->link[1], getMaxData);
	else{
		cpy_data(getMaxData, &(*cur)->data);
		return del_queue(cur);
	}
}
int del_data(RBNode **root, Data data){
	int ret;
	Data getd;
	if(!(*root))
		return -1;
	else if((*root)->data.no == data.no){
		if((*root)->link[0] && (*root)->link[1]){
			del_max(&(*root)->link[0], &getd);
			cpy_data(&(*root)->data, &getd);
		}else{
			del_queue(root);
		}
		ret = 0;
	}else if(data.no < (*root)->data.no){
		ret = del_data(&(*root)->link[0], data);
	}else{
		ret = del_data(&(*root)->link[1], data);
	}

	return ret;
}

void print_tree(RBNode *root){
	sub_print_tree(root, 0, 5);
	getchar();
	system("cls");
}
int sub_print_tree(RBNode *root,int x, int y){
	COORD pos;
	if(root){
		x = sub_print_tree(root->link[0], x, y+3);
		pos.X = x; pos.Y =y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		if(root->color == RED)
			printf("(%2d)", root->data.no);
		else
			printf("%4d", root->data.no);
		x = sub_print_tree(root->link[1], x+3, y+3);
	}
	return x;
}






RBNode *_ins_val_chk(RBNode *cur){
	RBNode *p=NULL, *gp=NULL, *u=NULL;
	while(cur && cur->color == RED && cur->parent && cur->parent->color == RED){
		p = cur->parent;

		gp = p->parent;
		if(gp){
			if(gp->link[0] == p)
				u = gp->link[1];
			else
				u = gp->link[0];
			if(u && u->color == RED){
				chg_color(gp, UP_CLRCHG);
			}else{
				rotate(&gp, rot_chk(gp));
				if(gp->parent){
					if(gp->parent->data.no > gp->data.no)
						gp->parent->link[0] = gp;
					else
						gp->parent->link[1] = gp;
				}else{
					return gp;
				}
			}
			cur = cur->parent->parent;
		}
	}
	return 0;
}
int ins_data(RBNode **root, Data data){
	RBNode *cur = *root;
	if(!(*root)){
		(*root) = get_node();
		cpy_data(&(*root)->data, &data);
		return 0;
	}
	while(cur){
		if(!cur->link[0] && data.no < cur->data.no){
			cur->link[0] = get_node();
			cpy_data(&cur->link[0]->data, &data);
			cur->link[0]->color=RED;
			cur->link[0]->parent=cur;
			cur = cur->link[0];
			break;
		}else if(!cur->link[1] && data.no > cur->data.no){
			cur->link[1] = get_node();
			cpy_data(&cur->link[1]->data, &data);
			cur->link[1]->color=RED;
			cur->link[1]->parent=cur;
			cur = cur->link[1];
			break;
		}
		if(data.no < cur->data.no){
			cur = cur->link[0];
		}else if(data.no > cur->data.no){
			cur = cur->link[1];
		}else if(cur->data.no == data.no){
			return -1;
		}
	}
	if(cur = _ins_val_chk(cur)){
		(*root) = cur;
	}
	return 0;
}
int ins_data(RBNode **root, int no){
	Data data;
	set_data(&data, no);

	ins_data(root, data);
	(*root)->color = BLACK;
	return 0;
}
int _dele_val_chk(RBNode **root, RBNode *p, int clr, Data data){
	RBNode *c=NULL, *s=NULL;
	int dir;
	//c가 루트거나 레드를삭제했을때 필요없다.
	if(clr == RED || !p) return -1;

	//p도 존재. c경로의 검은노드를 하나 지웠으므로, s경로의 검은노드도 반드시존재. (리프노드까지의 검은노드수는 같으므로)
	
	if(data.no < p->data.no)
		dir = 0;
	else dir = 1;
	c=p->link[dir];
	s=p->link[!dir];

	while(p){
		//c경로만! 검은노드수를 하나 늘려야한다.
		if(c && c->color==RED){
			c->color=BLACK;
			break;
		}
		else if(p->color==RED){
			if(s && s->color==RED)
				chg_color(s, DOWN_CLRCHG);//s가 레드면 자식이있어야한다 검은색으로 반드시!c경로의 검은노드를 하나 지웠으므로, s경로의 검은노드도 반드시존재. (리프노드까지의 검은노드수는 같으므로)
			p->color=BLACK;
			if(s)
				s->color=RED;
			//red로 색변환을 해주면 레드가 중복되는지 반드시 검사해야함
			//c는 항상 검은색인 분기문이므로 무조건 로테이트
			if(p->parent){
				if(p->data.no < p->parent->data.no)
					rotate(&p->parent->link[0], rot_chk(p));
				else
					rotate(&p->parent->link[1], rot_chk(p));
			}else 
				rotate(root, rot_chk(p));
			break;
		}else{//p가 black
			if(!s || s->color==BLACK){
				if(s){
					s->color=RED;
					if(p->parent){
						if(p->data.no < p->parent->data.no){
							rotate(&p->parent->link[0], rot_chk(p));
							p = p->parent->link[0];
						}
						else{
							rotate(&p->parent->link[1], rot_chk(p));
							p = p->parent->link[1];
						}
					}else{
						rotate(root, rot_chk(p));
						p = NULL;
					}
				}
				c=p;
				if(p->parent)
					p= p->parent;
				if(p){
					if(c->data.no < p->data.no){
						s=p->link[1];
					}else
						s=p->link[0];
				}
				//다시반복
			}else{//s가 red일때
				if(p->parent){
					if(dir==0){
						if(p->data.no < p->parent->data.no)
							rotate(&p->parent->link[0], RR);
						else
							rotate(&p->parent->link[1], RR);
					}else{
						if(p->data.no < p->parent->data.no)
							rotate(&p->parent->link[0], LL);
						else
							rotate(&p->parent->link[1], LL);
					}
				}else{ 
					if(dir == 0)
						rotate(root, RR);
					else
						rotate(root, LL);
				}
				s = p->link[!dir];
				//다시반복
			}
		}
	}
	return 0;
}
int dele_data(RBNode **root, Data data){
	RBNode *cur = *root;
	RBNode *p = NULL;
	RBNode *subcur = NULL;
	int clr, dir;
	Data getd;
	while(1){
		if(!cur) return -1;
		else if(data.no < cur->data.no){
			p = cur;
			cur = cur->link[0];
		}else if(data.no > cur->data.no){
			p = cur;
			cur = cur->link[1];
		}else{
			if(cur->link[0] && cur->link[1]){
				p = cur;
				subcur=cur->link[0];
				while(subcur){
					if((subcur)->link[1]){
						p = subcur;
						(subcur) = (subcur)->link[1];
					}
					else break;
				}
				cpy_data(&cur->data, &(subcur)->data);
				if(subcur->parent){
					if(data.no < subcur->parent->data.no)
						clr = del_queue(&subcur->parent->link[0]);
					else
						clr = del_queue(&subcur->parent->link[1]);
				}else{
					clr = del_queue(root);
				}
			}
			else{
				if(cur->parent){
					if(data.no < cur->parent->data.no)
						clr = del_queue(&cur->parent->link[0]);
					else
						clr = del_queue(&cur->parent->link[1]);
				}else{
					clr = del_queue(root);
				}
			}
			break;
		}
	}
	return _dele_val_chk(root, p, clr, data);
}
int dele_data(RBNode **root, int no){
	Data data;
	set_data(&data, no);

	dele_data(root, data);
	if(*root)
		(*root)->color=BLACK;
	return 0;
}