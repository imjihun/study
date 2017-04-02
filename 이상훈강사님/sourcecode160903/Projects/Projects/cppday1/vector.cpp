#include "vector.h"


ostream& operator<<(ostream& os, Vector& v)
{
	for(int i=0; i<v.getDimention(); i++)
		printf("%.2lf\t", v.getdata(i));
	return os;
}

ostream& operator<<(ostream& os, VectorSet& vs){
	for(int i=0; i<vs.getSize(); i++)
		os << vs.getVector(i) << endl;
	return os;
}

Vector::Vector(int _d){
	dimention = _d;
	data = new double[dimention];
	for(int i=0; i<dimention; i++)
		data[i] = 0;
}
Vector::Vector(double x, double y, double z, int _d){
	dimention = _d;
	data = new double[dimention];
	data[0]=x;
	data[1]=y;
	data[2]=z;
}
Vector::Vector(Vector& _v){
	dimention = _v.getDimention();
	data = new double[dimention];
	for(int i=0; i<dimention; i++)
		data[i] = _v.getdata(i);
}
Vector::~Vector(void)
{
//	cout<< "~Vec() Call" << endl;
	delete[] data;
}
double Vector::getdata(int i)
{
	return data[i];
}
void Vector::setdata(int i, double _data)
{
	data[i] = _data;
}
int Vector::getDimention()
{
	return dimention;
}
double Vector::getScalarSquare(){
	double sum=0;
	for(int i=0; i<dimention; i++){
		sum += data[i]*data[i];
	}
	return sum;
}
Vector Vector::operator+(Vector& _data){
	Vector tmp(dimention);
	if(dimention == _data.getDimention()){
		for(int i=0; i<dimention; i++)
			tmp.setdata(i, data[i] + _data.getdata(i));
	}
	return tmp;
}
Vector Vector::operator-(Vector& _data){
	Vector tmp(dimention);
	if(dimention == _data.getDimention()){
		for(int i=0; i<dimention; i++)
			tmp.setdata(i, data[i] - _data.getdata(i));
	}
	return tmp;
}
	
double Vector::operator*(Vector& _data){
	double tmp =0;
	if(dimention == _data.getDimention()){
		for(int i=0; i<dimention; i++)
			tmp += data[i] * _data.getdata(i);
	}
	return tmp;
}
Vector Vector::operator*(double _data){
	Vector tmp(dimention);

	for(int i=0; i<dimention; i++)
		tmp.setdata(i, data[i] * _data);

	return tmp;
}
void Vector::operator=(Vector& v)
{
	for(int i=0; i<dimention; i++){
		data[i] = v.getdata(i);
	}
}
//위에 할당연산자를 오버로딩 하지않으면 heap데이터 영역에서 에러가 난다???


VectorSet::VectorSet(int _size, int _d){
	size = _size;
	vs = new Vector[size];
	if(_d != 3){
		for(int i=0; i<_size; i++)
			this->setVector(i, Vector(_d));
	}
}
VectorSet::VectorSet(VectorSet& _v)
{
	size = _v.getSize();
	vs = new Vector[size];
	int d = _v.getVector(0).getDimention();
	for(int i=0; i<size; i++)
		vs[i] = _v.getVector(i);
		//this->setVector(i, Vector(d));
}
VectorSet::~VectorSet()
{
//	cout<< "~VecSet() Call" << endl;
	delete[] vs;
}
Vector VectorSet::getVector(int i)
{
	return vs[i];
}
void VectorSet::setVector(int i, Vector& _v)
{	
//	memcpy(&vs[i],&_v,sizeof(_v));
	vs[i] = _v;
}
int VectorSet::getSize(void)
{
	return size;
}
void VectorSet::operator=(VectorSet& _vs)
{
	for(int i=0; i<size; i++){
		vs[i] = _vs.getVector(i);
	}
}

void VectorSet::setGramSchmidt(VectorSet& _vs){
	int _size = _vs.getSize();
	
	if(_size != size){
		delete[] vs;
		vs = new Vector[_size];
		size = _size;
	}
	for(int i=0; i<_size; i++){
		vs[i] = _vs.getVector(i);
		for(int j=0; j<i; j++){
			vs[i] = vs[i] - vs[j]* (_vs.getVector(i) * vs[j] * (1.0/vs[j].getScalarSquare()));
		}
		vs[i] = vs[i] * (1.0 / sqrt(vs[i].getScalarSquare()));
	}
}

/*
VectorSet VectorSet::newGramSchmidt(VectorSet& _vs){
	VectorSet tmp(_vs.getSize(), _vs.getVector(0).getDimention());
	int _size = tmp.getVector(0).getDimention();
	
	for(int i=0; i<_size; i++){
		tmp.setVector(i, _vs.getVector(i));
		for(int j=0; j<i; j++){
			tmp.setVector(i, tmp.getVector(i) - tmp.getVector(j)* (_vs.getVector(i) * tmp.getVector(j) * (1.0/tmp.getVector(j).getScalarSquare())));
		}
		tmp.setVector(i, tmp.getVector(i) * (1.0 / sqrt(tmp.getVector(i).getScalarSquare())));
	}
	return tmp;
}
*/
/*
void GramSchmidt(VectorSet *w, VectorSet *v){
	int _size = v->getSize();
	
	for(int i=0; i<_size; i++){
		w->setVector(i, v->getVector(i));
		for(int j=0; j<i; j++){
			w->setVector(i, w->getVector(i) - w->getVector(j)* (v->getVector(i) * w->getVector(j) * (1.0/w->getVector(j).getScalarSquare())));
		}
		w->setVector(i, w->getVector(i) * (1.0 / sqrt(w->getVector(i).getScalarSquare())));
	}
}
*/
