#ifndef CVECTOR_HEADER
#define CVECTOR_HEADER

#include <math.h>
#include <iostream>

using namespace std;

class CVector
{
public:
	double x, y, z;
	CVector(void);
	CVector(double, double, double);
	CVector(const CVector&);
	~CVector(void);

	double Dot(const CVector&);
	void Cross(const CVector&, const CVector&);
	CVector Scalar(double);
	double Length(void);
	void friend gram_schmidt(CVector *get,CVector *VectorSet, int size);
	void friend Gramschmidt(CVector *arr, CVector *a, CVector *b, CVector *c);

	CVector operator+(const CVector&);
	CVector operator-(const CVector&);
	CVector operator=(const CVector&);
};

#endif