#pragma once
#include "pch.h"
#include <iostream>
#include "Vector.h"
using namespace std;

template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{

public:
	//TMatrix(int s = 10);
	//TMatrix(const TMatrix &mt); // �����������
	//TMatrix(const TVector<TVector<ValType> > &mt); // �������������� ����
	//TMatrix& operator==(const TMatrix &mt); // ���������
	//TMatrix& operator= (const TMatrix &mt); // ������������
	//TMatrix operator+ (const TMatrix &mt); // ��������
	//TMatrix operator- (const TMatrix &mt); // ���������
	//TMatrix operator* (const TMatrix &mt); // ���������
	// ���� / �����
	//friend istream& operator>>(istream &in, TMatrix &mt);
	//friend ostream & operator<<(ostream &out, const TMatrix &mt);
};