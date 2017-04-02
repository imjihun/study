#include "matrix.h"
#include "matrix3.h"
#include <time.h>
#include <Windows.h>
#include <iostream>
#include <iomanip>
#define CHECK_TIME_INIT		__int64 freq, start, end;
#define CHECK_TIME_START	if (QueryPerformanceFrequency((_LARGE_INTEGER*)&freq)) {QueryPerformanceCounter((_LARGE_INTEGER*)&start); 
#define CHECK_TIME_END(a,b)	QueryPerformanceCounter((_LARGE_INTEGER*)&end); a=(float)((double)(end - start)/freq*1000000000); b=TRUE; } else b=FALSE;
using namespace std;

void printMatrix(const CMatrix3& mat)
{
	cout.precision(5);
	cout << '\t' << setw(15) << mat.element[0] << setw(15) << mat.element[3] << setw(15) << mat.element[6] << endl;
	cout << '\t' << setw(15) << mat.element[1] << setw(15) << mat.element[4] << setw(15) << mat.element[7] << endl;
	cout << '\t' << setw(15) << mat.element[2] << setw(15) << mat.element[5] << setw(15) << mat.element[8] << endl;
}

int main(){
    double time_r, time_g;
	bool err_r, err_g;

	double tmp2[] = {2.0,	1.0,	2.0,
					1.0,	2.0,	-1.0,
					3.0,	-1.0,	3.0};
	double tmp[] = {2,		4,		6,
					3,		2,		0,
					4,		2,		6};
	Matrix m1(tmp2, 3);
	Matrix m2;
	Matrix m3;

	CMatrix3 matA(tmp2);
	CMatrix3 result;
	
CHECK_TIME_INIT;

CHECK_TIME_START;
	result = matA.Cramer();
CHECK_TIME_END(time_r, err_r);
CHECK_TIME_START;
	m3.setRevMatrixofGauss_Jordan(m1);
CHECK_TIME_END(time_g, err_g);
	cout <<"freq : " << freq << endl << "초단위 : ns" << endl;
	if(err_r)
		cout<<"수행시간Rev : "<< time_r <<endl;
	if(err_g)
		cout<<"수행시간Gau : "<< time_g <<endl;
	
	cout << "form" << endl << m1 << endl;
	cout << "rev" << endl << m2 << endl;
	cout << "GaussJordan Rev" << endl << m3 << endl;
	

	cout << endl;

	/*
	double array1[9] = {2.0,	1.0,	2.0,
						1.0,	2.0,	-1.0,
						3.0,	-1.0,	3.0};
	double array2[9] = {1.0,	3.0,	0.0,
						0.0,	1.0,	4.0,
						-2.0,	-1.0,	-2.0};
	CMatrix3 matA(array1), matB(array2);
	CMatrix3 result;

	cout << "Matrix A" << endl;
	printMatrix(matA);
	
	cout << "Matrix B" << endl;
	printMatrix(matB);
	
	cout << "Identity Matrix" << endl;
	result = matA;
	result.Identity();
	printMatrix(result);
	
	cout << "Transpose Matrix" << endl;
	result = matA;
	result.Transpose();
	printMatrix(result);

	cout << "Addition of Matrix" << endl;
	result = matA + matB;
	printMatrix(result);

	cout << "Subtraction of Matrix" << endl;
	result = matA - matB;
	printMatrix(result);

	cout << "Multiplication of Matrix" << endl;
	result = matA * matB;
	printMatrix(result);

	cout << "Scalar of Multiplication" << endl;
	result = matA;
	result.Scalar(3.0);
	printMatrix(result);
	
	cout << "Determinant" << endl;
	cout << matA.Det() << endl;
	
	cout << "Inverse Matrix" << endl;
	result = matB.Inverse();
	printMatrix(result);
	result = result * matB;
	printMatrix(result);
	
	cout << "Cramer Inverse Matrix" << endl;
	result.Identity();
	result = matB.Cramer(result);
	printMatrix(result);
	result = result * matB;
	printMatrix(result);
	*/
#if 1
	double arr3[9] =	{8.0,	-2.0,	0.0,
						2.0,	8.0,	-4.0,
						0.0,	-4.0,	4.0};
#endif

	CMatrix3 matC(arr3);
	CVector ans(0.0, 0.0, 36.0);
	CVector res;

	matC.Cramer_vector(ans, &res);

	cout.flush();
	return 0;
}