#include<iostream>

using namespace std;

#define SQUARE(x)	((x)*(x))

//디폴트 파라미터(ex:함수로 도형기본값 세팅할떄 )
int function(int len, int width =1, int height =1)
{
	return len * width * height;
}

//인라인함수
//컴파일에서 사이즈 지정(페이지단위) 사이즈를 넘어가면 컴파일에러
//기능별로 분리하고 싶은데 함수호출시에는 스택을 새로 만들지만
//인라인함수는 스택을 새로만들지 않고 어셈블리코드과정에서 그대로 진행한다.
//어셈블리코드에서 함수생성과 소멸할때 10줄정도씩의 명령어가 들어가지만 인라인은 스택을 따로 만들지 않기 때문에 구동속도가 빠르다.
//반면에 함수를 기능별로 세분화 시킬수있다.
//어셈블리수준의 코딩을 할때 핵심함수이다. 구동속도는 빠르게 하고, 가독성은 높이기 위해
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
	cout << "소멸자 호출 " << endl;
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
		cout << "속도 : " << speed << ", 색 : " << color << endl;
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
	///////////////////////////////////////////id(_id) -> 디폴트 파라매터랑 비슷. -> id = _id;
	//id변수가 const로 정의되고 있기 때문에, 생성자 호출전에 initialize 될 필요가 있다.
	//그래서 :id(_id)와 같이 const 변수는 initializer를 이용하여 초기화 해야한다.
	IDCard(int _id, int _age, char *_name, char *_major):id(_id), age(_age)
	{
		//id = _id;
		//age = _age;
		strcpy(name, _name);
		strcpy(major, _major);
	}
	void ShowData(void)
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
		cout << "학번 : " << id << endl;
		cout << "학과 : " << major << endl;
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
	//객체가 const로 선언될시 그 객체의 함수는 const된 것으로 실행이 된다.
	//함수앞에 const인것이랑 다르다. 이것은 함수오버로딩!
	//const 객체는 const 함수만 호출할수 있다.
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
	//static이란 키워드는 외부에서 참조를 못하게 한다.(정적)
	static int count;
public:
	Per(char *_name, int _age){
		strcpy(name, _name);
		age = _age;
		cout << count++ << "번째 Per객체 생성" << endl;
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

	cout << "*****p1의 정보 *****" << endl;
	Point *p1 = new Point();
	cout << "Pointer p1 : " << p1 << endl;
	cout << "p1의 this : " << p1->GetThis() << endl;

	cout << "*****p2의 정보 *****" << endl;
	Point *p2 = new Point();
	cout << "Pointer p2 : " << p2 << endl;
	cout << "p2의 this : " << p2->GetThis() << endl;

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
	Car c2(100, "흰색");
	c1.show();
	c2.show();
	
	c1.setColor("검정색");
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
	//////////////////////////함수 인자로 전달할때 복사생성자 호출!
	//1.객체를 대입할떄 복사생성자 호출!! (복사생성자)
	//2.함수인자로 전달할때 복사생성자 호출!! (복사생성자)
	//3.함수리턴으로 전달할떄 복사생성자 호출!!(복사생성자->소멸메소드)
	function(obj);
	cout<<endl;
	/////////////////////////함수 리턴형으로 전달해도 복사생성자 호출!
	//구조체 리턴형과 똑같이 리턴데이터가 복사되서 메인함수로 전달된다.
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