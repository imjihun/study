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
	//friend�� ���� �ٸ���ġ���� ���Լ��� �����Ҽ� �ְ� ���ֱ⶧����
	//�ٸ���ġ�� �ִ� Ŭ�������� �̿��Ͽ� ����� �Ϸ���
	//friend�� �Ἥ �Լ��� �����ѵ� �������̵� �Ҽ� �ְ� ����� �Ѵ�.

	//p+p2;
	friend Point operator+(const Point& p1, const Point& p2);

	//7+p�� �ذ��ϱ����� ��¿�� ���� friend�ۿ� ����.
	friend Point operator+(int val, Point& p);

	

	//���׿�����.
	//���������ڴ� ���ڸ� void(++p)
	//C++ ��Ģ
	//���������ڿ����ε� (�����ȵ�);
	Point& operator++(void);
	//���������ڿ����ε� (�����ȵ�!)
	friend Point& operator--(Point& p);
	//���޼ҵ带 �Ѵ� �������ָ� �Ѵ� ������ �ȴ�??
	//�ΰ��� ++���۷����� �����ε��̸� ��ȣ�ϴٰ� �����ߴµ�
	//������ ++ �Ʒ��� --�� �ϸ� �����ȶ߰� ���� �����ٵ� �ù�


	//���������ڴ� ���ڸ� int(p++)(�����ȵ�)
	//C++ ��Ģ
	//PointŬ������ �������־�� (p++).ShowPosition(); ���� ������ �����ϴ�!
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
//friend�� ����Ǿ� operator+(p1,p2)�� ���� ����
//�ٸ��͵��� p.operator+(p1)�� ����
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
���� ���� ���� ���� ����
��� 3x3
����, ����, ����, �����
���콺-�����ܼҰŹ�
ũ���Ӱ���
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
		//���⼭�� ostream�� �����ϰų� ostream&�� �����ϰų� �Ȱ���.
		//������ this����(�ڱ��ڽŸ���) (�ڱ��ڽŸ����̱⶧���� �޸𸮸��Ѱ��ֵ� �ּҰ����Ѱ��ֵ� ���������)
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