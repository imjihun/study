#include <iostream>
using namespace std;

class Cudgel
{
public:
	void Swing(void)
	{
		cout << "Swing the Cudgel" << endl;
	}
};
/*
//���
class Police:public Cudgel
{
public:
	void UseWeapon(void)
	{
		Swing();
	}
};

int main(void)
{
	Police pol;
	pol.UseWeapon();
	return 0;
}
*/
/*
//has a
class Police
{
	//�����ͺ����� ������ ������ �������� police��ü�� 4����Ʈ�� �߰��ǹǷ�
	//L1ĳ�ø޸�(SRAM)�� ���� Ȱ���Ҽ� �ִ�.
	//ĳ�ø� �ʰ��ϴ� �뷮�� ������ ���ϵȴ�.
	Cudgel *cud;
public:
	Police(void)
	{
		cud = new Cudgel;
	}
	~Police(void)
	{
		delete cud;
	}
	void UseWeapon(void)
	{
		cud->Swing();
	}
};

int main(void)
{
	Police pol;
	pol.UseWeapon();
	return 0;
}
*/
/*
class Person
{
public:
	int a;
	void Sleep(void)
	{
		cout << "Sleep" << endl;
	}
};
class Student:public Person
{
public:
	int b;
	void Study(void)
	{
		a=3;
		cout << a << endl;
		cout << "Study" << endl;
	}
};
class PartTimeStd:public Student
{
public:
	int c;
	void Work(void)
	{
		cout << "Work" << endl;
	}
};

int main(void)
{
	Person *p1 = new Person;
	Person *p2 = new Student;
	Person *p3 = new PartTimeStd;
	Person p4;
	Student p5;
	PartTimeStd p6;
	char *a = new char[30];
	char b[30];
	p1->Sleep();
	((Student*)p1)->Study();
	((Student*)p1)->a = 59;
	//*(p1+10) = 50;
	cout << p1 << ", " << &((Student*)p1)->b << ", " << p2 << ", " << &((Student*)p2)->b << ", " << p3 << ", " << &((Student*)p3)->b << endl;
	cout << &p4 << ", " << sizeof(p4) << endl << &p5 << ", " << sizeof(p5) << ", " << &p5.b << endl << &p6 << ", " << sizeof(p6) << endl;
	cout << _msize((p1)) << endl;
	cout << _msize(((Student*)p1)) << endl;
	cout << _msize(p2) << endl;
	cout << _msize(a) << endl;
	cout << sizeof(b) << endl;
	cout << endl;
	p2->Sleep();
	((Student*)p2)->Study();

	p3->Sleep();

	cout << endl;
	PartTimeStd p;
	Student& ref1 = p;
	Person& ref2 = p;

	p.Sleep();
	ref1.Sleep();
	ref2.Sleep();
	delete p3;
	return 0;
}
*/
////////////////////////////////////////�����Լ�
/*
class A
{
public:
	virtual void fct(void)
	{
		cout << "A" << endl;
	}
};
class B:public A
{
public:
	//vitual�� ��� �θ�Ŭ�������� �����Լ��� �����������Ƿ� �ڵ����� �����Լ��� �ȴ�. 
	//�������� BŬ������ �Ҵ��ϸ� �θ�Ŭ���������ͷ� �����ϴ��� BŬ�����Լ��� ȣ��ȴ�.
	void fct(void)
	{
		A::fct();//�����Լ��� �����Լ����̺��� ����Ƿ� �����Լ����̺�� �����϶�� �ڵ�
		cout << "B" << endl;
	}
};
class C:public B
{
	void fct(void)
	{
		cout << "C" << endl;
	}
};

int main(void)
{
	
	B *b = new C;
	b->fct();

	A *a = b;
	a->fct();

	delete b;
	
	A *a = new B;
	a->fct();
	cout << endl;
	a->A::fct();
	delete a;
	return 0;
}
*/
/*
class Employee
{
protected:
	char name[20];

public:
	Employee(char *_name);
	const char *GetName(void);
	virtual int GetPay(void){ return 0; }
};
Employee::Employee(char *_name)
{
	strcpy(name, _name);
}
const char *Employee::GetName(void)
{
	return name;
}

class Permanent : public Employee
{
private:
	int salary;
public:
	Permanent(char *_name, int sal);
	int GetPay(void);
};
Permanent::Permanent(char *_name, int sal):Employee(_name)
{
	salary = sal;
}
int Permanent::GetPay(void)
{
	return salary;
}

class Temporary:public Employee
{
private:
	int time;
	int pay;
public:
	Temporary(char *_name, int _time, int _pay);
	int GetPay(void);
};
Temporary::Temporary(char *_name, int _time, int _pay):Employee(_name)
{
	time = _time;
	pay = _pay;
}
int Temporary::GetPay(void)
{
	return time * pay;
}

class Department
{
private:
	Employee *empList[20];
	int index;
public:
	Department(void):index(0){};
	~Department(void);
	void AddEmployee(Employee *emp);
	void ShowList(void);
};
void Department::AddEmployee(Employee *emp)
{
	empList[index++] = emp;
}
void Department::ShowList(void)
{
	for(int i=0; i<index; i++)
	{
		cout << "name : " << empList[i]->GetName() << endl;
		cout << "pay : " << empList[i]->GetPay() << endl;
		cout << endl;
	}
}
Department::~Department(void)
{
	for(int i=0; i<index; i++)
		delete empList[i];
	
}
int main(void)
{
	Department depart;
	
	depart.AddEmployee(new Permanent("Jo", 3600));
	depart.AddEmployee(new Permanent("Kim", 4800));
	depart.AddEmployee(new Permanent("Ma", 6000));
	depart.AddEmployee(new Permanent("Lee", 7200));
	depart.AddEmployee(new Temporary("TJo", 3, 3600));
	depart.AddEmployee(new Temporary("TKim", 4, 4800));
	depart.AddEmployee(new Temporary("TMa", 5, 6000));
	depart.AddEmployee(new Temporary("TLee", 6, 7200));

	depart.ShowList();
	return 0;
}
*/


class A
{
	char *str1;
public:
	A(char *_str1)
	{
		str1 = new char[strlen(_str1)+1];
		strcpy(str1, _str1);
	}
	//�Ҹ��ڿ� virtualŰ���带 ���̸� A������(�θ�������)�� B��ü(�ڽİ�ü)�� ����Ų ���¿��� 
	//A�����͸� delete���ٶ� B�� �Ҹ��ڵ� �˾Ƽ� ȣ�����ش�.
	//����Ű���尡 �ֱ⶧���� ~A�� ȣ���ص� ~B���� ����� �ö�ͼ� ~A�� ȣ���Ѵ�.
	//�޼ҵ忡���� ����Ű���尡 ������ A�����ͷ� �޼ҵ带 ȣ���ص� �ڽĸ޼ҵ带 �����Ѵ�.
	//������ �ֱ� ������,
	//�Ҹ��ڿ����� ����Ű���带 �ᵵ �θ�Ҹ��ڵ� �������شٴ� ��Ŀ����.
	virtual ~A(void)
	{
		cout << "~A(void) Call" << endl;
		delete []str1;
	}
	virtual void ShowString(void)
	{
		cout << str1 << ' ';
	}
};

class B : public A
{
	char *str2;
public:
	B(char *_str1, char *_str2):A(_str1)
	{
		str2 = new char[strlen(_str2) + 1];
		strcpy(str2, _str2);
	}
	~B(void)
	{
		cout << "~B(void) Call" << endl;
		delete []str2;
	}
	virtual void ShowString(void)
	{
		A::ShowString();
		cout << str2 << endl;
	}
};

class C : public B
{
	char *str3;
public:
	C(char *_str1, char *_str2, char *_str3):B(_str1, _str2)
	{
		str3 = new char[strlen(_str2) + 1];
		strcpy(str3, _str3);
	}
	~C(void)
	{
		cout << "~B(void) Call" << endl;
		delete []str3;
	}
	virtual void ShowString(void)
	{
		B::ShowString();
		cout << str3 << endl;
	}
};

int main(void)
{
	A *a = new B("Good", "Evening");
	B *b = new B("Good", "Morning");
	a->ShowString();
	b->ShowString();
	cout << "��ü�Ҹ�����" << endl;
	delete a;
	delete b;
	return 0;
}
