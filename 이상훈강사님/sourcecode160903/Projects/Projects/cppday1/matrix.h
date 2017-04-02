#ifndef MY_MATRIX_HEADER
#define MY_MATRIX_HEADER
#include <iostream>
#include <math.h>
#define XMAX 3
#define YMAX 3
using namespace std;


//클래스 안에 포인터있으면 무조건 깊은복사구현
//복사생성자와 할당연산자에 대해서
class Matrix
{
	double *data;
	int size_i;
	int size_j;
public:
	Matrix(void);
	Matrix(int _size);
	Matrix(int _size_i, int _size_j);
	Matrix(double _data, int _size);
	Matrix(double *_data, int _size);
	Matrix(const Matrix& m);
	~Matrix(void);
	int getSize_i(void) const;
	int getSize_j(void) const;
	double getData(int x, int y) const;
	void setData(int x, int y, double _data);
	Matrix getRevMatrix(void);
	void setGauss_Jordan(Matrix& rsc);
	void setRevMatrixofGauss_Jordan(Matrix& rsc);

//	Matrix& operator=(int *data);
	Matrix operator+(double _data);
	Matrix operator+(Matrix& m);
	
	Matrix operator-(double _data);
	Matrix operator-(Matrix& m);
	
	Matrix operator*(double _data);
	Matrix operator*(Matrix& m);
	
	Matrix operator/(double _data);
	void operator=(Matrix& m);

//protected:
	double _getDeterminant(void);
	Matrix _getAdjoint(void);
};
ostream& operator<<(ostream& o,Matrix& m);
#endif