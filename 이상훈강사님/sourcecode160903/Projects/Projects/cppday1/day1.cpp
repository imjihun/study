#include<iostream>

using namespace std;

#define SQUARE(x)	((x)*(x))

//����Ʈ �Ķ����(ex:�Լ��� �����⺻�� �����ҋ� )
int function(int len, int width =1, int height =1)
{
	return len * width * height;
}

//�ζ����Լ�
//�����Ͽ��� ������ ����(����������) ����� �Ѿ�� �����Ͽ���
//��ɺ��� �и��ϰ� ������ �Լ�ȣ��ÿ��� ������ ���� ��������
//�ζ����Լ��� ������ ���θ����� �ʰ� ������ڵ�������� �״�� �����Ѵ�.
//������ڵ忡�� �Լ������� �Ҹ��Ҷ� 10���������� ��ɾ ������ �ζ����� ������ ���� ������ �ʱ� ������ �����ӵ��� ������.
//�ݸ鿡 �Լ��� ��ɺ��� ����ȭ ��ų���ִ�.
//����������� �ڵ��� �Ҷ� �ٽ��Լ��̴�. �����ӵ��� ������ �ϰ�, �������� ���̱� ����
inline int SQUA(int x){
	return x*x;
}

////////////////////////////day3
class Academy
{
	char *name;
	char *phone;
public:
	Academy(char *_name, char *_phone);
	~Academy(void);
	void ShowData(void);
};

Academy::Academy(char *_name, char *_phone){
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);

	phone = new char[strlen(_phone) + 1];
	strcpy(phone, _phone);
}

Academy::~Academy(void){
	cout << "�Ҹ��� ȣ�� " << endl;
	delete []name;
	delete []phone;
}

void Academy::ShowData(void){
	cout << "name : " << name << endl;
	cout << "phone : " << phone << endl;
}

class Point{
	int x;
	int y;
public:
	Point(void){
		cout << "Point(void) call" << endl;
		x = y = 0;
	}
	Point(int _x, int _y){
		x = _x;
		y = _y;
	}
	int GetX(void){return x;}
	int GetY(void){return y;}
	void SetX(int _x){x = _x;}
	void SetY(int _y){y = _y;}
	void ShowData(void){
		cout << "x = " << x << ", y = " << y << endl;
	}
	Point *GetThis(void){
		return this;
	}
};

class Data{
	int a, b;
public:
	Data(int a, int b){
		this->a = a;
		this->b = b;
	}
	void printAll(void){
		cout << a << " " << b << endl;
	}
};

class Counter{
public:
	int val;
	Counter(void){
		val = 0;
	}
	void Print(void){
		cout << val << endl;
	}
	friend void SetVal(Counter &c, int val);
};
void SetVal(Counter& c, int val){
	c.val = val;
}

class A{
private:
	int data;
	friend class B;
};
class B{
public:
	void SetData(A& a, int data){
		a.data = data;
	}
};

class AA{
	int val;
public:
	AA(int n){
		val = n;
	}
	void ShowData(void){
		cout << val << endl;
	}
};

class AAA{
public:
	int a;
	AAA(void){
		cout << "A() Call" << endl;
		a=10;
	}
	AAA(int i){
		cout << "A(int i) Call" << endl;
		a=10;
	}
	AAA(const AAA& a){
		cout << "A(const AAA& a) Call" << endl;
	}
};

class Car{
private:
	int speed;
	char *color;
public:
	Car(void){
		speed = 0;
		color = new char[5];
		strcpy(color, "red");
	}
	Car(int _speed, char *_color){
		speed= _speed;
		color = new char[strlen(_color)+1];
		strcpy(color, _color);
	}
	~Car(void){
		if(color) delete[] color;
	}
	void setSpeed(int s){speed = s;}
	void setColor(char *c){
		if(color) delete[] color;
		color = new char[strlen(c)+1];
		strcpy(color, c);
	}
	void show(void){
		cout << "�ӵ� : " << speed << ", �� : " << color << endl;
	}
};

class Person{
	char *name;
	char *phone;
public:
	Person(char *_name, char *_phone);
	Person(const Person &p);
	~Person();
	void ShowData();
};

Person::Person(char *_name, char *_phone){
	name = new char[strlen(_name) +1];
	strcpy(name, _name);

	phone = new char[strlen(_phone) +1];
	strcpy(phone, _phone);
}
Person::Person(const Person &p){
	name = new char[strlen(p.name) +1];
	strcpy(name, p.name);

	phone = new char[strlen(p.phone) +1];
	strcpy(phone, p.phone);
}

Person::~Person(){
	delete []name;
	delete []phone;
}

void Person::ShowData(void){
	cout << "name : " << name << endl;
	cout << "phone : " << phone << endl;
}

class AAAA{
	int val;
public:
	AAAA(int i){
		cout << "A(int i) Call" << endl;
		val = i;
	}
	AAAA(const AAAA& a){
		cout << "A(const AAAA& a) Call" <<endl;
		val = a.val;
	}
	~AAAA(){
		cout << "(" << val << ")~A() Call"<<endl;
	}
	void ShowData(void){
		cout << "val : " << val << endl;
	}
};
void function(AAAA a){
	a.ShowData();
}
AAAA function2(void){
	AAAA a(10);
	return a;
}

class IDCard{
	const int id;
	int age;
	char name[20];
	char major[30];
public:
	///////////////////////////////////////////id(_id) -> ����Ʈ �Ķ���Ͷ� ���. -> id = _id;
	//id������ const�� ���ǵǰ� �ֱ� ������, ������ ȣ������ initialize �� �ʿ䰡 �ִ�.
	//�׷��� :id(_id)�� ���� const ������ initializer�� �̿��Ͽ� �ʱ�ȭ �ؾ��Ѵ�.
	IDCard(int _id, int _age, char *_name, char *_major):id(_id), age(_age)
	{
		//id = _id;
		//age = _age;
		strcpy(name, _name);
		strcpy(major, _major);
	}
	void ShowData(void)
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
		cout << "�й� : " << id << endl;
		cout << "�а� : " << major << endl;
	}
};

class A_5{
	int num;
public:
	A_5(int _num):num(_num){}
	void ShowData(void)
	{
		cout << "void ShowData(void) Call" << endl;
		cout << num << endl;
	}
	//��ü�� const�� ����ɽ� �� ��ü�� �Լ��� const�� ������ ������ �ȴ�.
	//�Լ��տ� const�ΰ��̶� �ٸ���. �̰��� �Լ������ε�!
	//const ��ü�� const �Լ��� ȣ���Ҽ� �ִ�.
	void ShowData(void) const
	{
		cout << "void ShowData(void) const Call" << endl;
		cout << num << endl;
	}
	void show(){ cout << num << endl; }
};

class Per{
	char name[20];
	int age;
	//static�̶� Ű����� �ܺο��� ������ ���ϰ� �Ѵ�.(����)
	static int count;
public:
	Per(char *_name, int _age){
		strcpy(name, _name);
		age = _age;
		cout << count++ << "��° Per��ü ����" << endl;
	}
	void ShowData(void){
		cout << "name : " << endl;
		cout << "age : " << endl;
	}
};
int Per::count = 1;

int main(void){
	//Academy aca("Bit", "02-111-2222");
	//aca.ShowData();
	/*
	Point arr[5];

	for(int i=0; i<5; i++){
		arr[i].SetX(i*2);
		arr[i].SetY(i*3);
	}
	for(int j=0; j<5; j++)
		arr[j].ShowData();
		*/
	/*
	Point *arr[5];
	Point a1;
	Point a2 = Point(2,3);
	Point a3(3,4);
	Point a4();
	a1.ShowData();
	a2.ShowData();
	cout<<endl;

	for(int i=0; i<5; i++){
		arr[i] = new Point(i*2, i*3);
	}
	for(int j=0; j<5; j++){
		arr[j]->ShowData();
	}
	for(int k=0; k<5; k++)
		delete arr[k];

	cout << "*****p1�� ���� *****" << endl;
	Point *p1 = new Point();
	cout << "Pointer p1 : " << p1 << endl;
	cout << "p1�� this : " << p1->GetThis() << endl;

	cout << "*****p2�� ���� *****" << endl;
	Point *p2 = new Point();
	cout << "Pointer p2 : " << p2 << endl;
	cout << "p2�� this : " << p2->GetThis() << endl;

	Data d(100, 200);
	d.printAll();

	Counter cnt;
	cnt.Print();
	SetVal(cnt, 2002);
	cnt.Print();
	cnt.val = 100;

	A a;
	B b;
	b.SetData(a, 10);

	AA a11 = 20;
	a11.ShowData();
	
	AAA obj1;
	AAA obj2(10);
	AAA obj3(obj2);
	cout<<endl;
	Car c1;
	Car c2(100, "���");
	c1.show();
	c2.show();
	
	c1.setColor("������");
	c1.setSpeed(50);
	c2.setColor("red");
	c2.setSpeed(130);
	c1.show();
	c2.show();
	*/
	/*
	Person p1("Jo", "010-9272-6523");
	Person p2 = p1;

	AAAA obj(30);
	//////////////////////////�Լ� ���ڷ� �����Ҷ� ��������� ȣ��!
	//1.��ü�� �����ҋ� ��������� ȣ��!! (���������)
	//2.�Լ����ڷ� �����Ҷ� ��������� ȣ��!! (���������)
	//3.�Լ��������� �����ҋ� ��������� ȣ��!!(���������->�Ҹ�޼ҵ�)
	function(obj);
	cout<<endl;
	/////////////////////////�Լ� ���������� �����ص� ��������� ȣ��!
	//����ü �������� �Ȱ��� ���ϵ����Ͱ� ����Ǽ� �����Լ��� ���޵ȴ�.
	function2().ShowData();

	cout << "endMain" << endl;
	cout << endl;
	
	IDCard Jo(2000, 22, "Jo Hyun Kyu", "Electronics");
	IDCard Hong(1999, 23, "Hong Ji Min", "Computer Science");

	Jo.ShowData();
	cout<<endl;
	Hong.ShowData();*/

	const A_5 a1(10);
	A_5 a2(70);
	a1.ShowData();
	a2.ShowData();
	a2.show();
	
	Per p1("Jo", 33);
	Per p2("Kim", 34);
	return 0;
}

/*
int main(void){
	int result=3;
	cout << function(7) << endl;
	cout << function(7, 3, 33) << endl;
	cout << SQUARE(5) <<endl;
	cout << SQUA(5) <<endl;
	return 0;
}*/