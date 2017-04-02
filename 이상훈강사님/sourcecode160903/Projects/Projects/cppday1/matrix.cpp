#include "matrix.h"


ostream& operator<<(ostream& o,Matrix& m){
	for(int i=0; i<XMAX; i++){
		for(int j=0; j<YMAX; j++){
			double t = m.getData(i,j);
			if(t > -0.000001 && t < 0.000001)
				printf("%.3lf\t", 0);
			else
				printf("%.3lf\t", t);
		}
		o << endl;
	}
	return o;
}

Matrix::Matrix(void)
{
	size_i=0;
	size_j=0;
	data=NULL;
}
Matrix::Matrix(const Matrix& m){
	int si = m.getSize_i();
	int sj = m.getSize_j();
	if(size_i != si || size_j != sj){
		data = new double[si*sj];
		size_i = si;
		size_j = sj;
	}
	for(int i=0; i<size_i; i++){
		for(int j=0; j<size_j; j++){
			data[i*size_j +j]=m.data[i*size_j +j];
		}
	}
}
Matrix::Matrix(int _size){
	size_i = size_j =_size;
	data = new double[size_i*size_j];
	for(int i=0;i<size_i;i++){
		for(int j=0; j<size_j; j++){
			if(i==j)
				data[i*size_j +j]=1;
			else
				data[i*size_j +j]=0;
		}
	}
}
Matrix::Matrix(int _size_i, int _size_j){
	size_i = _size_i;
	size_j = _size_j;

	data = new double[size_i*size_j];
}
Matrix::Matrix(double _data, int _size){
	size_i = size_j =_size;
	data = new double[size_i*size_j];
	for(int i=0; i<size_i; i++){
		for(int j=0; j<size_j; j++){
			data[i*size_j +j]=_data;
		}
	}
}
Matrix::Matrix(double *_data, int _size)
{
	size_i= size_j =_size;
	data = new double[size_i*size_j];
	if(_data){
		for(int i=0; i<size_i; i++){
			for(int j=0; j<size_j; j++){
				data[i*size_j +j]=_data[i*size_j+j];
			}
		}
	}else{
		for(int i=0; i<size_i; i++){
			for(int j=0; j<size_j; j++){
				data[i*size_j +j]=0;
			}
		}
	}
}
Matrix::~Matrix(){
	if(data)
		delete[] data;
}

double Matrix::getData(int x, int y) const
{
	if(x<size_i && y<size_j && x>-1 && y>-1)
		return data[x*size_j +y];
	return 0;
}
void Matrix::setData(int x, int y, double _data)
{
	if(x<size_i && y<size_j && x>-1 && y>-1)
		data[x*size_j +y]=_data;
}
int Matrix::getSize_i(void) const
{
	return size_i;
}
int Matrix::getSize_j(void) const
{
	return size_j;
}

Matrix Matrix::operator+(Matrix& m)
{
	Matrix tmp(size_i, size_j);
	for(int i=0; i<size_i; i++){
		for(int j=0; j<size_j; j++){
			tmp.setData(i, j, data[i*size_j +j] + m.getData(i,j));	
		}
	}
	return tmp;
}
Matrix Matrix::operator+(double _data)
{
	Matrix tmp(size_i, size_j);
	for(int i=0; i<size_i; i++){
		for(int j=0; j<size_j; j++){
			tmp.setData(i, j, data[i*size_j +j] + _data);	
		}
	}
	return tmp;
}
Matrix Matrix::operator-(Matrix& m)
{
	Matrix tmp(size_i, size_j);
	for(int i=0; i<size_i; i++){
		for(int j=0; j<size_j; j++){
			tmp.setData(i, j, data[i*size_j +j] - m.getData(i,j));	
		}
	}
	return tmp;
}
Matrix Matrix::operator-(double _data)
{
	Matrix tmp(size_i, size_j);
	for(int i=0; i<size_i; i++){
		for(int j=0; j<size_j; j++){
			tmp.setData(i, j, data[i*size_j +j] - _data);	
		}
	}
	return tmp;
}
Matrix Matrix::operator*(Matrix& m)
{
	Matrix tmp(size_i, size_j);
	for(int i=0; i<size_i; i++){
		for(int j=0; j<size_j; j++){
			tmp.setData(i,j,0);
			for(int k=0; k<size_j; k++)
				tmp.setData(i,j, tmp.getData(i,j) + data[i*size_j +k]*m.getData(k,j));
		}
	}

	return tmp;
}
Matrix Matrix::operator*(double _data)
{
	Matrix tmp(size_i, size_j);
	for(int i=0; i<size_i; i++){
		for(int j=0; j<size_j; j++){
			tmp.setData(i, j, data[i*size_j +j] * _data);	
		}
	}
	return tmp;
}
Matrix Matrix::operator/(double _data)
{
	Matrix tmp(size_i, size_j);
	for(int i=0; i<size_i; i++){
		for(int j=0; j<size_j; j++){
			tmp.setData(i, j, data[i*size_j +j] / _data);	
		}
	}
	return tmp;
}
void Matrix::operator=(Matrix& m)
{
	int si = m.getSize_i();
	int sj = m.getSize_j();
	if(size_i != si || size_j != sj){
		if(data)
			delete[] data;
		data = new double[si*sj];
		size_i = si;
		size_j = sj;
	}
	for(int i=0; i<size_i; i++)
		for(int j=0; j<size_j; j++)
			data[i*size_j +j] = m.getData(i, j);
}

Matrix Matrix::getRevMatrix(void){
	double min = 0.00000001;
	double det=_getDeterminant();
	if(det < min && det > -min)
		return *this;

	Matrix cof(_getAdjoint());
	cof = cof/det;
	return cof;
}
Matrix Matrix::_getAdjoint(){
	Matrix tmp(size_i, size_j);
	double *subM = new double[(size_i-1) * (size_j-1)];
	for(int i=0; i<size_i; i++){
		for(int j=0; j<size_j; j++){
			int ii=0, jj=0;
			for(int subi=0; subi<size_i-1; subi++){
				//나머지요소에 대한 determinant를 구하기위한 배열만들기
				for(int subj=0; subj<size_j-1; subj++){
					ii=(subi+1)+i; jj=(subj+1)+j;
					if(ii >= size_i)
						ii=ii-size_i;
					if(jj >= size_j)
						jj=jj-size_j;
					subM[subi*(size_i-1) +subj] = data[ii*size_j +jj];
				}
			}
			tmp.setData(j,i, Matrix(subM, size_i-1)._getDeterminant());
		}
	}
	delete[] subM;
	return tmp;
}
double Matrix::_getDeterminant(){
	double d=0;

	if(size_i == 1){
		d = data[0];
	}else if(size_i == 2){
		d = data[0*size_j+0]*data[1*size_j+1] - data[0*size_j+1]*data[1*size_j+0];
	}else if(size_i == 3){
		d += data[0*size_j +0]*data[1*size_j +1]*data[2*size_j +2];
		d += data[0*size_j +1]*data[1*size_j +2]*data[2*size_j +0];
		d += data[0*size_j +2]*data[1*size_j +0]*data[2*size_j +1];

		d -= data[0*size_j +2]*data[1*size_j +1]*data[2*size_j +0];
		d -= data[0*size_j +1]*data[1*size_j +0]*data[2*size_j +2];
		d -= data[0*size_j +0]*data[1*size_j +2]*data[2*size_j +1];
	}
	return d;
	/*
	if(size>3){
		int mSize = m.getSize();
		for(int i=0; i<mSize; i++){
			for(int j=0; j<mSize; j++){
				d=m.data[i*size +j];
			}
		}
		return d;
	}*/
}

void Matrix::setRevMatrixofGauss_Jordan(Matrix& rsc){
	double min = 0.00000001;
	double det=rsc._getDeterminant();
	if(det < min && det > -min)
		return ;

	if(!data){
		size_i = rsc.getSize_i();
		size_j = rsc.getSize_j();
		data = new double[size_i * size_j];
	}

	Matrix tmp(rsc.getSize_i(), 2*rsc.getSize_j());

	for(int i=0; i<size_i; i++){
		for(int j=0; j<size_j; j++){
			tmp.setData(i, j, rsc.getData(i, j));
		}
		for(int j=0; j<size_j; j++){
			if(i==j)
				tmp.setData(i, j+size_i, 1);
			else
				tmp.setData(i, j+size_i, 0);
		}
	}

	tmp.setGauss_Jordan(tmp);

	for(int i=0; i<size_i; i++){
		for(int j=0; j<size_j; j++){
			data[i*size_j +j] = tmp.getData(i,j+size_i);
		}
	}
}
void Matrix::setGauss_Jordan(Matrix& rsc){
	if(!data){
		size_i = rsc.getSize_i();
		size_j = rsc.getSize_j();
		data = new double[size_i * size_j];
	}
		

	if( size_i != rsc.getSize_i())
		return;
	
	double tmp;
	
	for(int j=0; j<size_j; j++){
		for(int i=0; i<size_i; i++){
			data[i*size_j +j] = rsc.getData(i,j);
		}
	}
	//행렬정리
	for(int j=0, i_start=0; j<size_j; j++,i_start++){
		for(int i=i_start; i<size_i; i++){
			if(data[i*size_j +j] != 0)
				break;
			else{
				for(int ii=i+1; ii<size_i; ii++){
					if(data[ii*size_j +j] != 0){//swapRow
						tmp = data[i*size_j +j];
						data[i*size_j +j] = data[ii*size_j +j];
						data[ii*size_j +j] = tmp;
						goto NEXTCOLOMN;
					}
				}
				////여기로오면 j열의 모든행이 0임.
				i_start--;
			}
		}
NEXTCOLOMN:
		;
	}//end행렬정리
	//기약 행 사다리꼴
	for(int i=0, j; i<size_i; i++){
		///i행 첫열(j)의 데이터를 1로
		for(j=0; j<size_j; j++){
			tmp = data[i*size_j +j];
			if(tmp != 0){
				for(int k=j; k<size_j; k++){//k=subJ
					data[i*size_j +k] = data[i*size_j +k]/tmp;
				}
				break;
			}
		}
		///j열의 i행 아래놈들을 0으로
		for(int ii=i+1; ii<size_i; ii++){
			tmp = data[ii*size_j +j];
			if(tmp != 0){
				for(int k=j; k<size_j; k++){//k=subJ
					data[ii*size_j +k] = data[ii*size_j +k]+data[i*size_j +k]*(-tmp);
				}
			}
		}
		//end 행 사다리꼴
		//j열의 i행 윗놈들을 0으로
		for(int ii=i-1; ii>=0; ii--){
			tmp = data[ii*size_j +j];
			if(tmp != 0){
				for(int k=j; k<size_j; k++){//k=subj
					data[ii*size_j +k] = data[ii*size_j +k]+data[i*size_j +k]*(-tmp);
				}
			}
		}
	}//end기약 행 사다리꼴
}

