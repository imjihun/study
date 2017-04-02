#include "matrix3.h"
#include <cmath>
#include <memory.h>

CMatrix3::CMatrix3(void)
{
	::memset(element, '\0', sizeof(element));
}

CMatrix3::CMatrix3(const double rhs[9])
{
	::memcpy(element, rhs, sizeof(element));
}

CMatrix3::CMatrix3(const CMatrix3& rhs)
{
	::memcpy(element, rhs.element, sizeof(element));
}

CMatrix3& CMatrix3::operator=(const CMatrix3& rhs)
{
	if(this == &rhs)
		return *this;
	::memcpy(element, rhs.element, sizeof(element));
	return *this;
}


void CMatrix3::Identity(void)
{
	element[0] = 1.0;
	element[1] = 0.0;
	element[2] = 0.0;
	
	element[3] = 0.0;
	element[4] = 1.0;
	element[5] = 0.0;

	element[6] = 0.0;
	element[7] = 0.0;
	element[8] = 1.0;
}
void CMatrix3::Transpose(void)
{
	CMatrix3 mat(*this);
	//for문을 돌리는것보다 위에처럼 하드코딩을 하는것이 성능에 더욱 도움이 된다. 어셈블리 관점에서 for문을 돌리면 4줄정도가 추가된다.
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			element[j*3 +i] = mat.element[i*3 +j];
}
/*
CMatrix3& CMatrix3::operator+(void)
{
	return *this;
}
*/
CMatrix3 CMatrix3::operator-(void) const
{
	CMatrix3 mat(*this);
	mat.Scalar(-1.0);
	return mat;
}
CMatrix3 CMatrix3::operator+(const CMatrix3& rhs) const
{
	CMatrix3 mat(*this);
	for(int i=0; i<9; ++i)
		mat.element[i] += rhs.element[i];
	return mat;
}
CMatrix3& CMatrix3::operator+=(const CMatrix3& rhs)
{
	for(int i=0; i<9; i++)
		element[i] += rhs.element[i];
	return *this;
}
CMatrix3 CMatrix3::operator-(const CMatrix3& rhs) const
{
	CMatrix3 mat(*this);
	for(int i=0; i<9; i++)
		mat.element[i] -= rhs.element[i];
	return mat;
}
CMatrix3& CMatrix3::operator-=(const CMatrix3& rhs)
{
	for(int i=0; i<9; i++)
		element[i] -= rhs.element[i];
	return *this;
}
CMatrix3 CMatrix3::operator*(const CMatrix3& rhs) const
{
	CMatrix3 mat;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			for(int k=0; k<3; k++)
				mat.element[j*3 +i] += element[k*3 +i] * rhs.element[j*3 +k];
//				mat.element[i*3 +j] += element[i*3 +k] * rhs.element[k*3 +j];
	return mat;
}
CMatrix3& CMatrix3::operator*=(const CMatrix3& rhs)
{
	return (*this = *this * rhs);
}

void CMatrix3::Scalar(double k)
{
	for(int i=0; i<9; i++)
		element[i] *= k;
}
double CMatrix3::Det(void) const
{
	double det = 0;
	det = element[0]*element[4]*element[8] +  element[3]*element[7]*element[2] + element[6]*element[1]*element[5]
			- element[0]*element[7]*element[5] - element[3]*element[1]*element[8] - element[6]*element[4]*element[2];
	return det;
}
CMatrix3 CMatrix3::Inverse(void) const
{
	double det = Det();

	if(fabs(det) < 1.0e-5)
		return CMatrix3();

	CMatrix3 adjoint(Adjoint());
	adjoint.Scalar(1.0/det);
	return adjoint;
}

CMatrix3 CMatrix3::Adjoint(void) const
{
	CMatrix3 adjoint;
	adjoint.element[0] = element[4]*element[8] - element[7]*element[5];
	adjoint.element[1] = -element[1]*element[8] + element[7]*element[2];
	adjoint.element[2] = element[1]*element[5] - element[4]*element[2];
	adjoint.element[3] = -element[3]*element[8] + element[6]*element[5];
	adjoint.element[4] = element[0]*element[8] - element[6]*element[2];
	adjoint.element[5] = -element[0]*element[5] + element[3]*element[2];
	adjoint.element[6] = element[3]*element[7] - element[6]*element[4];
	adjoint.element[7] = -element[0]*element[7] + element[6]*element[1];
	adjoint.element[8] = element[0]*element[4] - element[3]*element[1];
	return adjoint;
}
void CMatrix3::Cramer_vector(CVector& ans, CVector* res) const
{
	CMatrix3 tmp;
	double det = Det();
	printf("det_tot = %lf\n", det);

	tmp = *this;
	tmp.element[0] = ans.x;
	tmp.element[1] = ans.y;
	tmp.element[2] = ans.z;
	res->x = tmp.Det();
	printf("det_x = %lf\n", res->x);
	res->x /= det;

	tmp = *this;
	tmp.element[3] = ans.x;
	tmp.element[4] = ans.y;
	tmp.element[5] = ans.z;
	res->y = tmp.Det();
	printf("det_y = %lf\n", res->y);
	res->y /= det;
	
	tmp = *this;
	tmp.element[6] = ans.x;
	tmp.element[7] = ans.y;
	tmp.element[8] = ans.z;
	res->z = tmp.Det();
	printf("det_z = %lf\n", res->z);
	res->z /= det;

	printf("x = %lf, y = %lf, z = %lf\n", res->x, res->y, res->z);
}
CMatrix3 CMatrix3::Cramer(CMatrix3& rhs) const
{
	CMatrix3 crm;
	CVector dst, src;

	for(int i=0; i<3; i++){
		src.x = rhs.element[i*3 +0];
		src.y = rhs.element[i*3 +1];
		src.z = rhs.element[i*3 +2];

		Cramer_vector(src, &dst);
		
		crm.element[i*3 +0] = dst.x;
		crm.element[i*3 +1] = dst.y;
		crm.element[i*3 +2] = dst.z;
	}
	return crm;
}

CMatrix3 CMatrix3::Cramer(void) const
{
	CMatrix3 crm, tmp;
	double det = Det(), det_t;
	
	tmp.element[0] = 1.0;
	tmp.element[1] = 0.0;
	tmp.element[2] = 0.0;
	tmp.element[3] = element[3];
	tmp.element[4] = element[4];
	tmp.element[5] = element[5];
	tmp.element[6] = element[6];
	tmp.element[7] = element[7];
	tmp.element[8] = element[8];
	det_t = tmp.Det();
	crm.element[0] = det_t/det;
	
	tmp.element[0] = element[0];
	tmp.element[1] = element[1];
	tmp.element[2] = element[2];
	tmp.element[3] = 1;
	tmp.element[4] = 0;
	tmp.element[5] = 0;
	tmp.element[6] = element[6];
	tmp.element[7] = element[7];
	tmp.element[8] = element[8];
	det_t = tmp.Det();
	crm.element[1] = det_t/det;
	
	tmp.element[0] = element[0];
	tmp.element[1] = element[1];
	tmp.element[2] = element[2];
	tmp.element[3] = element[3];
	tmp.element[4] = element[4];
	tmp.element[5] = element[5];
	tmp.element[6] = 1;
	tmp.element[7] = 0;
	tmp.element[8] = 0;
	det_t = tmp.Det();
	crm.element[2] = det_t/det;
	
	tmp.element[0] = 0;
	tmp.element[1] = 1;
	tmp.element[2] = 0;
	tmp.element[3] = element[3];
	tmp.element[4] = element[4];
	tmp.element[5] = element[5];
	tmp.element[6] = element[6];
	tmp.element[7] = element[7];
	tmp.element[8] = element[8];
	det_t = tmp.Det();
	crm.element[3] = det_t/det;
	
	tmp.element[0] = element[0];
	tmp.element[1] = element[1];
	tmp.element[2] = element[2];
	tmp.element[3] = 0;
	tmp.element[4] = 1;
	tmp.element[5] = 0;
	tmp.element[6] = element[6];
	tmp.element[7] = element[7];
	tmp.element[8] = element[8];
	det_t = tmp.Det();
	crm.element[4] = det_t/det;
	
	tmp.element[0] = element[0];
	tmp.element[1] = element[1];
	tmp.element[2] = element[2];
	tmp.element[3] = element[3];
	tmp.element[4] = element[4];
	tmp.element[5] = element[5];
	tmp.element[6] = 0;
	tmp.element[7] = 1;
	tmp.element[8] = 0;
	det_t = tmp.Det();
	crm.element[5] = det_t/det;
	
	tmp.element[0] = 0;
	tmp.element[1] = 0;
	tmp.element[2] = 1;
	tmp.element[3] = element[3];
	tmp.element[4] = element[4];
	tmp.element[5] = element[5];
	tmp.element[6] = element[6];
	tmp.element[7] = element[7];
	tmp.element[8] = element[8];
	det_t = tmp.Det();
	crm.element[6] = det_t/det;
	
	tmp.element[0] = element[0];
	tmp.element[1] = element[1];
	tmp.element[2] = element[2];
	tmp.element[3] = 0;
	tmp.element[4] = 0;
	tmp.element[5] = 1;
	tmp.element[6] = element[6];
	tmp.element[7] = element[7];
	tmp.element[8] = element[8];
	det_t = tmp.Det();
	crm.element[7] = det_t/det;
	
	tmp.element[0] = element[0];
	tmp.element[1] = element[1];
	tmp.element[2] = element[2];
	tmp.element[3] = element[3];
	tmp.element[4] = element[4];
	tmp.element[5] = element[5];
	tmp.element[6] = 0;
	tmp.element[7] = 0;
	tmp.element[8] = 1;
	det_t = tmp.Det();
	crm.element[8] = det_t/det;
	
	return crm;
}