#pragma once
#include "pch.h"
#include <iostream>
#include "Vector.h"
using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T> >
{

public:
	TMatrix(int s = 10);
	//TMatrix(const TMatrix &mt); // �����������
	//TMatrix(const TVector<TVector<ValType> > &mt); // �������������� ����
	//TMatrix& operator==(const TMatrix &mt); // ���������
	//TMatrix& operator= (const TMatrix &mt); // ������������
	//TMatrix operator+ (const TMatrix &mt); // ��������
	//TMatrix operator- (const TMatrix &mt); // ���������
	//TMatrix operator* (const TMatrix &mt); // ���������
	// ���� / �����
	friend istream& operator>>(istream &in, TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
		{
			in >> mt.pVector[i];
		}
		return in;
	}
	friend ostream & operator<<(ostream &out, const TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
		{
			out << mt.pVector[i] << endl;
		}
		return out;
	}
};

template <class T>
TMatrix <T>::TMatrix(int s) : TVector<TVector<T>>(s,0)
{
	for (int i = 0; i < s; i++)
	{
		TVector<TVector<T>>::pVector[i] = TVector<T>(s , i);
	}
}
/*
template <class T>
istream& operator>>(istream &in, TMatrix <T> &mt)
{
	for (int i = 0; i < mt.Size; i++)
	{
		in >> mt.pVector[i];
	}
	return in;
}
*/
/*
template <class T>
ostream & operator<<(ostream &out, const TMatrix<T> &mt)
{
	for (int i = 0; i < mt.Size; i++)
	{
		out << mt.pVector[i]<<endl;
	}
	return out;
}*/