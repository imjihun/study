#include <iostream>

using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int _x=0, int _y=0):x(_x), y(_y){}
	void ShowPosition(void);

	//p+3;
	Point operator + (int val);

	//p+p2;
	Point operator + (const Point& p);
	//friend를 쓰면 다른위치에서 이함수를 구현할수 있게 해주기때문에
	//다른위치에 있는 클래스등을 이용하여 계산을 하려면
	//friend를 써서 함수를 구현한뒤 오버라이딩 할수 있게 해줘야 한다.

	//p+p2;
	friend Point operator+(const Point& p1, const Point& p2);

	//7+p를 해결하기위해 어쩔수 없이 friend밖에 없다.
	friend Point operator+(int val, Point& p);

	

	//단항연산자.
	//전위연산자는 인자를 void(++p)
	//C++ 규칙
	//전위연산자오버로딩 (후위안됨);
	Point& operator++(void);
	//전위연산자오버로딩 (후위안됨!)
	friend Point& operator--(Point& p);
	//위메소드를 둘다 선언해주면 둘다 후위가 된다??
	//두개다 ++오퍼레이터 오버로딩이면 모호하다고 에러뜨는데
	//위에꺼 ++ 아래꺼 --로 하면 에러안뜨고 전위 후위다됨 시발


	//후위연산자는 인자를 int(p++)(전위안됨)
	//C++ 규칙
	//Point클래스를 리턴해주어야 (p++).ShowPosition(); 같은 구현이 가능하다!
	//Point operator++(int);
};
void Point::ShowPosition(void)
{
	cout << x << " " << y << endl;
}

Point Point::operator+(int val)
{
	Point tmp(x+val, y+val);
	return tmp;
}

Point Point::operator+(const Point& p)
{
	Point tmp(x+p.x, y+p.y);
	return tmp;
}


Point& Point::operator++(void)
{
	x++;
	y++;
	return *this;
}


Point& operator--(Point& p)
{
	p.x--;
	p.y--;
	return p;
}

/*
Point Point::operator++(int){
	Point temp(x,y);
	//++(*this);
	x++;
	y++;
	return temp;
}
*/
//friend로 선언되어 operator+(p1,p2)가 따로 동작
//다른것들은 p.operator+(p1)이 동작
Point operator+(const Point& p1, const Point& p2)
{
	Point temp(p1.x+p2.x, p1.y + p2.y);
	return temp;
}

Point operator+(int val, Point& p)
{
	return p+val;
}

/*
벡터 덧셈 뺄셈 내적 외적
행렬 3x3
덧셈, 뺄셈, 곱셈, 역행렬
가우스-조르단소거법
크래머공식
*/
int main(void)
{
	Point p(3,4);
	p.ShowPosition();
	p++;
	p.ShowPosition();
	++p;
	p.ShowPosition();
	p--;
	p.ShowPosition();
	--p;
	p.ShowPosition();
	/*
	Point p(3, 4);
	Point p2(5,6);
	Point p3 = p+p2;
	p.ShowPosition();

	p.operator+(10);
	p+10;
	p.ShowPosition();
	p3.ShowPosition();

	cout << endl;
	(++p).ShowPosition();
	p.ShowPosition();
	p++.ShowPosition();
	p.ShowPosition();*/
	return 0;
}

/*
int main(void)
{
	Point p(3, 7);
	++p;
	p.ShowPosition();

	--p;
	p.ShowPosition();

	++(++p);
	p.ShowPosition();

	p++;
	--(--p);
	p.ShowPosition();

	return 0;
}
*/

/*
namespace mystd
{
	class ostream
	{
	public:
		//여기서는 ostream을 리턴하거나 ostream&를 리턴하거나 똑같다.
		//어차피 this리턴(자기자신리턴) (자기자신리턴이기때문에 메모리를넘겨주든 주소값을넘겨주든 상관없을듯)
		ostream& operator<<(char *str)
		{
			printf("%s", str);
			return *this;
		}
		ostream& operator<<(int i)
		{
			printf("%d", i);
			return *this;
		}
		ostream& operator<<(double i)
		{
			printf("%lf", i);
			return *this;
		}
	};
	char *endl = "\n";
	ostream cout;
}

//using namespace mystd;
int main(void)
{
	mystd::cout << "Hello World\n";
	mystd::cout << 3.14 << mystd::endl;
	mystd::cout << mystd::endl;
	mystd::cout << 1 << mystd::endl;;
	mystd::cout << mystd::endl;
	return 0;
}*/