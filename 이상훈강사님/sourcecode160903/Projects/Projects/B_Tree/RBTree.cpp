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
	
		//red����� ������ ���̴°� ������? Ž�������� �ð��� logN�� ���������.
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
	chk = chg_clr_chk(*root);				//�ּ��� �����̼��� �����ϱ����� ����ȯ�� �����̼Ǻ��� ���� ���ش�.
	if(chk)
		chg_color(*root, chk);
	chk = rot_chk(*root);
	if(chk)
		rotate(root, chk);
	return ret;
}

//�����Ŀ� Ʈ���뷱���� �����ٶ�
//��Ʈ��忡���� Ž���ݴ������ �ڽĳ�尡 
//�������̸� ���������� �ٲٰ� ����üũ�� ������Ʈüũ(������� ����������� ���� ���ƾ��Ѵ�)
//�������̸� �ڽĳ��� �Ѵ� �������ϼ� �ۿ� �����Ƿ� down����ȯ�Ŀ� ���������� ���������� �ٲٰ� ��üũ�ͷ�����Ʈüũ
//��������� �ڽ��� ���ų� �ΰ��ٺ��� ������ ��������Ѵ�(�׻�)
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
	//c�� ��Ʈ�ų� ���带���������� �ʿ����.
	if(clr == RED || !p) return -1;

	//p�� ����. c����� ������带 �ϳ� �������Ƿ�, s����� ������嵵 �ݵ������. (������������ ���������� �����Ƿ�)
	
	if(data.no < p->data.no)
		dir = 0;
	else dir = 1;
	c=p->link[dir];
	s=p->link[!dir];

	while(p){
		//c��θ�! ���������� �ϳ� �÷����Ѵ�.
		if(c && c->color==RED){
			c->color=BLACK;
			break;
		}
		else if(p->color==RED){
			if(s && s->color==RED)
				chg_color(s, DOWN_CLRCHG);//s�� ����� �ڽ����־���Ѵ� ���������� �ݵ��!c����� ������带 �ϳ� �������Ƿ�, s����� ������嵵 �ݵ������. (������������ ���������� �����Ƿ�)
			p->color=BLACK;
			if(s)
				s->color=RED;
			//red�� ����ȯ�� ���ָ� ���尡 �ߺ��Ǵ��� �ݵ�� �˻��ؾ���
			//c�� �׻� �������� �б⹮�̹Ƿ� ������ ������Ʈ
			if(p->parent){
				if(p->data.no < p->parent->data.no)
					rotate(&p->parent->link[0], rot_chk(p));
				else
					rotate(&p->parent->link[1], rot_chk(p));
			}else 
				rotate(root, rot_chk(p));
			break;
		}else{//p�� black
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
				//�ٽùݺ�
			}else{//s�� red�϶�
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
				//�ٽùݺ�
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