#include <iostream>

using namespace std;

class Animal
{
	int age;
	int x;
public:
	Animal(int _age, int _x);
	void move(int dis);
	void show(void);
};
Animal::Animal(int _age=1, int _x=0){
	age=_age;
	x=_x;
}
void Animal::move(int dis=0){
	x+=dis;
}
void Animal::show(void){
	cout << "나이 : " << age << "위치 : " << x << endl;
}
class Man : public Animal
{
	char* name;

public:
	Man(int _age, int _x, char *_name);
	~Man(void);
	void show(void);
};
Man::Man(int _age=1, int _x=0, char *_name="noname"):Animal(_age,_x){
	name = new char[strlen(_name)+1];
	strcpy(name, _name);
}
Man::~Man(void){
	delete[] name;
}
void Man::show(void){
	Animal::show();
	cout << "name : " << name << endl;
}
class Sparrow : public Animal
{
	int wing_size;
	int y;

public:
	Sparrow(int _age, int _x, int _y, int _wing_size);
	void move(int dis_x, int dis_y);
	void show(void);
};
Sparrow::Sparrow(int _age=1, int _x=0, int _y=0, int _wing_size=1):Animal(_age, _x){
	y=_y;
	wing_size=_wing_size;
}

void Sparrow::move(int dis_x=0, int dis_y=0){
	Animal::move(dis_x);

}
void Sparrow::show(void){
	Animal::show();
	cout << "공중위치 : " << y << "날개크기 : " << wing_size << endl;
}
class Cow : public Animal
{
	int grade;

public:
	Cow(int _age, int _x, int _grade);
	void show(void);
};
Cow::Cow(int _age = 1, int _x = 0, int _grade = 0):Animal(_age, _x)
{
	grade = _grade;
}
void Cow::show(void)
{
	Animal::show();
	cout << "등급 : " << grade << endl;
}


class Vehicle
{
public:
	Vehicle(void);
};
Vehicle::Vehicle(void)
{
	cout << "Vehicle(void) Call" << endl;
}
class Car : public Vehicle
{
public:
	Car(void);
};
Car::Car(void)
{
	cout << "Car(void) Call" << endl;
}
class Airplane: public Vehicle
{
	Airplane(void);
};
Airplane::Airplane(void)
{
	cout << "Airplane(void) Call" << endl;
}
class Bird: public Vehicle
{
	Bird(void);
};
Bird::Bird(void)
{
	cout << "Bird(void) Call" << endl;
}

int main(void){
	return 0;
}