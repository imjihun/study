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
///////////임의로 만든 가상함수테이블
void (*s1[3])(Data *);
void (*s2[3])(Data *, int);
int s1_cnt=0;
int s2_cnt=0;
//클래스에대한 함수테이블을 만들어서 매칭!
//C언어에서는 함수를 함수테이블로 관리!
//각 객체는 가상함수테이블은 있어야한다. 함수테이블은 통합적으로있는게 효율이 좋겠다.
//클래스선언만으로는 어떤클래스를 할당받는지 모르기때문에 부모객체를 할당하면 가상함수여도 호출이되야되기때문에
//가상함수테이블로 함수시작주소 접근을 한단계 더 만들어서 간접으로 접근한다.
//실제로 클래스안에 가상함수가 존재하면 객체메모리사이즈가 올라간다.
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
	//virtual 함수는 인자로 넘어가는 함수포인터값을 자식클래스의 함수포인터로 바꿔서 저장해준다
	//virtual키워드를 쓰면 가상함수테이블을 생성하여 부모부터 자식클래스까지의 같은 가상함수들을 저장해놓고, 마지막자식의 함수를 실행한다.
	//따라서 virtual키워드를 쓰면 함수포인터로 형식이 같은 여러함수들을 바꾸어 실행하는 메카니즘이랑 똑같다.
	//일반적으로 함수호출 메커니즘이 함수명과 함수코드시작주소를 컴파일과정에서 매칭시켜주어 우리가 함수명을쓰면 그함수시작주소로 넘어가 실행이된다.(ex>mov eip, 0x코드실행중 나온 함수시작주소)
	//가상함수는 컴파일과정에서 각 객체마다 가상함수테이블을 만들어 그객체에서 함수호출하면 가상함수테이블의 마지막부분을 실행한다.
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