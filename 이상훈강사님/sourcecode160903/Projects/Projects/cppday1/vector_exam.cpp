#include <stdio.h>
#include <iostream>
#include "vectorT.h"
#include "vector.h"

int main(void)
{
	CVector u(1.0, 1.0, 1.0);
	CVector u1(.0, 4.0, .0);
	CVector u2(2.0, 2.0, 1.0);
	CVector u3(1.0, 1.0, 1.0);
	CVector v(0.5, 0.8, 0.2);
	CVector result;
	double scalar_result = 0;
	
	printf("Vector u = [%.2lf %.2lf %.2lf]\n", u.x, u.y, u.z);
	printf("Vector v = [%.2lf %.2lf %.2lf]\n", v.x, v.y, v.z);

	result = u + v;
	printf("\nAddition of Vector : \
		   \nu + v = [%.2lf %.2lf %.2lf]\n", result.x, result.y, result.z);
	
	result = u - v;
	printf("\nSubtraction of Vector : \
		   \nu - v = [%.2lf %.2lf %.2lf]\n", result.x, result.y, result.z);
	
	result = u.Scalar(3.0);
	printf("\nSubtraction of Vector : \
		   \n3v = [%.2lf %.2lf %.2lf]\n", result.x, result.y, result.z);
	
	scalar_result = u.Dot(v);
	printf("\nSubtraction of Vector : \
		   \nu.v = %.2lf\n", scalar_result);

	result.Cross(u,v);
	printf("\nSubtraction of Vector : \
		   \nu + v = [%.2lf %.2lf %.2lf]\n", result.x, result.y, result.z);
	
	CVector *vector = new CVector[3];
	vector[0] = u1;
	vector[1] = u2;
	vector[2] = u3;
	CVector *r = new CVector[3];
	gram_schmidt(r,vector,3);
	printf("\n");
	printf("r[0] = [%.2lf %.2lf %.2lf]\n", r[0].x, r[0].y, r[0].z);
	printf("r[1] = [%.2lf %.2lf %.2lf]\n", r[1].x, r[1].y, r[1].z);
	printf("r[2] = [%.2lf %.2lf %.2lf]\n", r[2].x, r[2].y, r[2].z);

	Gramschmidt(vector, &r[0], &r[1], &r[2]);
	printf("vr[0] = [%.2lf %.2lf %.2lf]\n", vector[0].x, vector[0].y, vector[0].z);
	printf("vr[1] = [%.2lf %.2lf %.2lf]\n", vector[1].x, vector[1].y, vector[1].z);
	printf("vr[2] = [%.2lf %.2lf %.2lf]\n", vector[2].x, vector[2].y, vector[2].z);
	printf("\n");
	printf("r[0] = [%.2lf %.2lf %.2lf]\n", r[0].x, r[0].y, r[0].z);
	printf("r[1] = [%.2lf %.2lf %.2lf]\n", r[1].x, r[1].y, r[1].z);
	printf("r[2] = [%.2lf %.2lf %.2lf]\n", r[2].x, r[2].y, r[2].z);
	
	/*
	int size = sizeof(double);
	double val = 0.3;

	compute_double_bit((char *)&val, size);
	*/
	Vector tmp1(0,4,0);
	Vector tmp2(2,2,1);
	Vector tmp3(1,1,1);
	VectorSet tmpSet(3,3);
	tmpSet.setVector(0, tmp1);
	tmpSet.setVector(1, tmp2);
	tmpSet.setVector(2, tmp3);

	VectorSet res(4);
	res.setGramSchmidt(tmpSet);
	//GramSchmidt(&res, &tmpSet);

	cout << tmpSet<< endl;
	cout << res<< endl;

	return 0;
}

