#if !defined(_CMATRIX_HEADER_)
#define _CMATRIX_HEADER
#include "vectorT.h"
class CMatrix3
{
public:
	double element[9];
	
	CMatrix3();
	CMatrix3(const double rhs[9]);
	CMatrix3(const CMatrix3& rhs);

	CMatrix3& operator=(const CMatrix3& rhs);
	~CMatrix3(void){}

	void Identity(void);
	void Transpose(void);

	CMatrix3& operator+(void);
	CMatrix3 operator-(void) const;
	CMatrix3 operator+(const CMatrix3& rhs) const;
	CMatrix3& operator+=(const CMatrix3& rhs);
	CMatrix3 operator-(const CMatrix3& rhs) const;
	CMatrix3& operator-=(const CMatrix3& rhs);
	CMatrix3 operator*(const CMatrix3& rhs) const;
	CMatrix3& operator*=(const CMatrix3& rhs);

	void Scalar(double k);
	double Det(void) const;
	CMatrix3 Inverse(void) const;
	CMatrix3 Cramer(void) const;
	CMatrix3 Cramer(CMatrix3& rsc) const;
	void Cramer_vector(CVector& ans, CVector* res) const;
protected:
	CMatrix3 Adjoint(void) const;
};

#endif