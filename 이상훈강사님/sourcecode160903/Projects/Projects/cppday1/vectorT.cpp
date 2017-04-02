#include "vectorT.h"

CVector::CVector(void)
{
	x=.0;
	y=.0;
	z=.0;
}

CVector::CVector(double init_x, double init_y, double init_z)
{
	x=init_x;
	y=init_y;
	z=init_z;
}

CVector::CVector(const CVector& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}

CVector::~CVector(void)
{
}

double CVector::Dot(const CVector& rhs)
{
	return (x * rhs.x + y * rhs.y + z * rhs.z);
}

void CVector::Cross(const CVector& u, const CVector& v)
{
	x = u.y * v.z - u.z * v.y;
	y = u.z * v.x - u.x * v.z;
	z = u.x * v.y - u.y * v.x;
}

CVector CVector::Scalar(double k)
{
	return CVector(k*x, k*y, k*z);
}

double CVector::Length(void)
{
	return double(sqrt(x*x + y*y + z*z));
}

CVector CVector::operator+(const CVector& rhs)
{
	return CVector(x+rhs.x, y+rhs.y, z+rhs.z);
}
CVector CVector::operator-(const CVector& rhs)
{
	return CVector(x-rhs.x, y-rhs.y, z-rhs.z);
}

CVector CVector::operator=(const CVector& rhs)
{
	x=rhs.x;
	y=rhs.y;
	z=rhs.z;

	return rhs;
}
ostream& operator<<(ostream& os, CVector v)
{
	printf("%.2lf\t", v.x);
	printf("%.2lf\t", v.y);
	printf("%.2lf", v.z);
	return os;
}
void gram_schmidt(CVector *w, CVector *v, int size){
	for(int i=0; i<size; i++){
		w[i] = v[i];
		cout << w[i] << endl;
		for(int j=0; j<i; j++){
			 w[i] = w[i] - w[j].Scalar(v[i].Dot(w[j]) * (1.0 / pow(w[j].Length(),2)));
		}
		w[i] = w[i].Scalar(1.0 / w[i].Length());
	}
}

void Gramschmidt(CVector *arr, CVector *a, CVector *b, CVector *c)
{
	double scale1 = 1/arr[0].Length();
	double dot1;

	*a = arr[0].Scalar(scale1);

	dot1 = a->Dot(arr[1]);						//w0 dot v1
	scale1 = pow(a->Length(), 2);

	*b = arr[1] - a->Scalar(dot1/scale1);		//v1 - 2(w0)

	dot1 = a->Dot(arr[2]);						//w0 dot v2
	scale1 = pow(a->Length(), 2);

	*c = arr[2] - a->Scalar(dot1/scale1);
	
	dot1 = b->Dot(arr[2]);						//w1 dot v2
	scale1 = pow(b->Length(), 2);

	*c = *c - b->Scalar(dot1/scale1);
	
	*a = a->Scalar((1.0/a->Length()));
	*b = b->Scalar((1.0/b->Length()));
	*c = c->Scalar((1.0/c->Length()));
}