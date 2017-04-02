#ifndef MY_VECTOR_HEADER
#define MY_VECTOR_HEACER
#include <iostream>

using namespace std;


class Vector
{
	double *data;
	int dimention;
public:
	Vector(int _d=3);
	Vector(double x, double y, double z, int _d=3);
	Vector(Vector& _v);
	~Vector(void);
	double getdata(int i);
	void setdata(int i, double _data);
	int getDimention();
	double getScalarSquare();
	Vector operator+(Vector& _data);
	Vector operator-(Vector& _data);
	
	double operator*(Vector& _data);
	Vector operator*(double _data);
	void operator=(Vector& v);
};
class VectorSet
{
	Vector *vs;
	int size;
public:
	VectorSet(int _size=1, int _d=3);
	VectorSet(VectorSet& _v);
	~VectorSet();
	Vector getVector(int i);
	void setVector(int i, Vector& _v);
	int getSize(void);
	
//	VectorSet newGramSchmidt(VectorSet& _vs);
	void setGramSchmidt(VectorSet& _vs);
//	void friend GramSchmidt(VectorSet* w, VectorSet* v);
	void operator=(VectorSet& v);
};

ostream& operator<<(ostream& os, VectorSet& vs);
ostream& operator<<(ostream& os, Vector& v);
#endif