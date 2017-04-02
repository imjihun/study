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
//const함수는 멤버변수에 대한 변경과 변경에 대한 기회조차 주지 않겠다는 의미의 함수이다.
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
	/////////////부모쪽으로 값을 전해줄때 initializer를 사용할수 있다.
	//private로 변수가 지정되어있으면 자식에서 접근을 못하기때문에.
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
		//부모의 private변수를 직접 참조를 못하기 때문에 함수로 리턴받아 출력
		//부모의 변수를 protected영역으로 바꾸면 직접참조하여 출력가능.
		//cout << "name : " << name << endl;
		//cout << "age : " << age << endl;
		//위와 같은 출력이 자식에서도 가능해진다.
		cout << "name : " << GetName() << endl;
		cout << "age : " << GetAge() << endl;
		cout << "major : " << GetMajor() << endl;
	}
};
/////반드시 자식이 먼저 죽는다!
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

	//지역변수 "hi"가 메모리해제되고 "bye"라는 새로운 지역변수메모리의 주소를 test에 저장
	//*(char*)re = 'a'; // <- 에러;
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
	프로세스란?
		프로그램이 컴파일되어 실행파일이 된 후 메모리에 로드되어 계속 상주하고 있는 상태.
*/

//Context Switching -> Multi-Tasking의 비밀
/*
	CPU는 1개 이고, 프로그램 2(A, B)개가 있다고 가정할떄
	A에 기계어가 써있고, B에도 기계어가 써있다(기계어 어셈블리어)
	레지스터상태를 저장해노면서 A실행했다가 B실행했다가 한다.
*/