#include <iostream>

using namespace std;
/*
class Permanent
{
private:
	char name[20];
	int salary;

public:
	Permanent(char *_name, int sal);
	const char *GetName(void);
	int GetPay(void);
};
Permanent::Permanent(char *_name, int sal)
{
	strcpy(name, _name);
	salary = sal;
}
//const�Լ��� ��������� ���� ����� ���濡 ���� ��ȸ���� ���� �ʰڴٴ� �ǹ��� �Լ��̴�.
const char *Permanent::GetName(void)
{
	return name;
}
int Permanent::GetPay(void)
{
	return salary;
}


class Department
{
	Permanent *empList[10];
	int index;
public:
	Department(void):index(0) {};
	~Department(void);
	void AddEmployee(Permanent *emp);
	void Department::AddEmployee(char *_name, int _salary);
	void ShowList(void);
};
Department::~Department(void){
	for(int i=0; i<index; i++)
		delete empList[i];
}
void Department::AddEmployee(Permanent *emp)
{
	empList[index++] = emp;
}
void Department::AddEmployee(char *_name, int _salary)
{
	empList[index++] = new Permanent(_name, _salary);
}
void Department::ShowList(void)
{
	for(int i=0; i<index; i++)
	{
		cout << "name : " << empList[i]->GetName() << endl;
		cout << "salary : " << empList[i]->GetPay() << endl;
		cout << endl;
	}
}

int main(void){
	Department depart;
	
	depart.AddEmployee(new Permanent("Jo", 3000));
	depart.AddEmployee(new Permanent("Kim", 5000));
	depart.AddEmployee("Lee", 7000);

	depart.ShowList();
	return 0;
}*/

class Person
{
	int age;
	char name[20];
public:
	int GetAge(void) const
	{
		return age;
	}
	const char *GetName(void) const
	{
		return name;
	}
	Person(int _age=1, char *_name="noname")
	{
		age= _age;
		strcpy(name, _name);
	}
};

class Student : public Person
{
	char major[20];
public:
	/////////////�θ������� ���� �����ٶ� initializer�� ����Ҽ� �ִ�.
	//private�� ������ �����Ǿ������� �ڽĿ��� ������ ���ϱ⶧����.
	Student(int _age, char *_name, char *_major):Person(_age,_name)
	{
		strcpy(major, _major);
	}
	const char *GetMajor(void) const
	{
		return major;
	}
	void ShowData(void) const
	{
		//�θ��� private������ ���� ������ ���ϱ� ������ �Լ��� ���Ϲ޾� ���
		//�θ��� ������ protected�������� �ٲٸ� ���������Ͽ� ��°���.
		//cout << "name : " << name << endl;
		//cout << "age : " << age << endl;
		//���� ���� ����� �ڽĿ����� ����������.
		cout << "name : " << GetName() << endl;
		cout << "age : " << GetAge() << endl;
		cout << "major : " << GetMajor() << endl;
	}
};
/////�ݵ�� �ڽ��� ���� �״´�!
class A
{
private:
	int a;
protected:
	int b;
public:
	A(void)
	{
		cout << "A(void) Call" << endl;
	}
	A(int i)
	{
		cout << "A(int i) Call" << endl;
	}
	~A(void)
	{
		cout << "~A(void) Call" << endl;
	}
};

class B : public A
{
public:
	B(void)
	{
		cout << "B(void) Call" << endl;
	}
	B(int j)
	{
		cout << "B(int j) Call" << endl;
	}
	~B(void)
	{
		cout << "~B(void) Call" << endl;
	}
	void SetData(void)
	{
		//a = 10;
		b = 20;
	}
};

int main(void)
{
	/*
	char *test = "hi";
	int re = (int)test;
	printf("%x->%s\n", re, re);
	printf("%x->%s\n", test, test);

	//�������� "hi"�� �޸������ǰ� "bye"��� ���ο� ���������޸��� �ּҸ� test�� ����
	//*(char*)re = 'a'; // <- ����;
	test = "bye";
	printf("%x->%s\n", re, re);
	printf("%x->%s\n", test, test);
	*/
	
	Student Park(34, "Park Hyun Su", "Computer Science");
	Park.ShowData();
	
	/*
	cout << "Create Object 1" << endl;
	B b1;

	cout << "Create Object 2" << endl;
	B b2(10);
	*/
	/*
	cout << endl;
	B b;
	b.SetData();*/
	return 0;
}




/*
	���μ�����?
		���α׷��� �����ϵǾ� ���������� �� �� �޸𸮿� �ε�Ǿ� ��� �����ϰ� �ִ� ����.
*/

//Context Switching -> Multi-Tasking�� ���
/*
	CPU�� 1�� �̰�, ���α׷� 2(A, B)���� �ִٰ� �����ҋ�
	A�� ��� ���ְ�, B���� ��� ���ִ�(���� �������)
	�������ͻ��¸� �����س�鼭 A�����ߴٰ� B�����ߴٰ� �Ѵ�.
*/