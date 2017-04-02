#include <iostream>
using namespace std;

struct Data
{
	int data;
	void (*ShowData)(Data *);
	void (*Add)(Data *, int);
};

void ShowData(Data *THIS)
{
	cout << "Data : " << THIS->data << endl;
}
void Add(Data *THIS, int num)
{
	THIS->data += num;
}
void Sub(Data *THIS, int num)
{
	cout << "sub : " << THIS->data-num << endl;
}
void Mul(Data *THIS)
{
	cout << "Mul : " << THIS->data*THIS->data << endl;
}
///////////���Ƿ� ���� �����Լ����̺�
void (*s1[3])(Data *);
void (*s2[3])(Data *, int);
int s1_cnt=0;
int s2_cnt=0;
//Ŭ���������� �Լ����̺��� ���� ��Ī!
//C������ �Լ��� �Լ����̺�� ����!
//�� ��ü�� �����Լ����̺��� �־���Ѵ�. �Լ����̺��� �����������ִ°� ȿ���� ���ڴ�.
//Ŭ�����������δ� �Ŭ������ �Ҵ�޴��� �𸣱⶧���� �θ�ü�� �Ҵ��ϸ� �����Լ����� ȣ���̵ǾߵǱ⶧����
//�����Լ����̺�� �Լ������ּ� ������ �Ѵܰ� �� ���� �������� �����Ѵ�.
//������ Ŭ�����ȿ� �����Լ��� �����ϸ� ��ü�޸𸮻���� �ö󰣴�.
void backup_info(Data* THIS)
{
	s1[s1_cnt++] = THIS->ShowData;
	s2[s2_cnt++] = THIS->Add;
}
void restore_info(Data *THIS)
{
	THIS->ShowData=s1[--s1_cnt];
	THIS->Add=s2[--s2_cnt];
}
int main(void)
{
	//virtual �Լ��� ���ڷ� �Ѿ�� �Լ������Ͱ��� �ڽ�Ŭ������ �Լ������ͷ� �ٲ㼭 �������ش�
	//virtualŰ���带 ���� �����Լ����̺��� �����Ͽ� �θ���� �ڽ�Ŭ���������� ���� �����Լ����� �����س���, �������ڽ��� �Լ��� �����Ѵ�.
	//���� virtualŰ���带 ���� �Լ������ͷ� ������ ���� �����Լ����� �ٲپ� �����ϴ� ��ī�����̶� �Ȱ���.
	//�Ϲ������� �Լ�ȣ�� ��Ŀ������ �Լ���� �Լ��ڵ�����ּҸ� �����ϰ������� ��Ī�����־� �츮�� �Լ��������� ���Լ������ּҷ� �Ѿ �����̵ȴ�.(ex>mov eip, 0x�ڵ������ ���� �Լ������ּ�)
	//�����Լ��� �����ϰ������� �� ��ü���� �����Լ����̺��� ����� �װ�ü���� �Լ�ȣ���ϸ� �����Լ����̺��� �������κ��� �����Ѵ�.
	Data d1 = {10, ShowData, Add};
	d1.Add(&d1, 10);
	d1.ShowData(&d1);

	Data d2 = {1, ShowData, Add};
	d2.Add(&d2, 1);
	d2.ShowData(&d2);
	backup_info(&d2);
	d2.ShowData=Mul;
	d2.Add=Sub;
	d2.Add(&d2, 1);
	d2.ShowData(&d2);
	restore_info(&d2);
	d2.Add(&d2, 1);
	d2.ShowData(&d2);
	
	cout << endl;
	Data d3 = {5, Mul, Sub};
	d3.ShowData(&d3);
	d3.Add(&d3, 4);
	
	return 0;
}