#include "pch.h"
#include <iostream>
#pragma once
using namespace std;


template <class T>
class TVector
{
protected:
	T *pVector;
	int Size; // ������ �������
	int StartIndex; // ������ ������� �������� �������
public:
	TVector(int s, int si);
	TVector(const TVector &v); // ����������� �����������
	~TVector();
	int GetSize();// ������ �������
	int GetStartIndex(); // ������ ������� ��������
	//	ValType& GetValue(int pos); // ������ � ��������� �������
	T & operator[](int pos); // ������
	int operator==(const TVector &v); // ���������
	TVector& operator= (const TVector  &v); // �������������
	// ��������� ��������
	//TVector operator+ (const ValType &val); // ��������� ������
//	TVector operator- (const ValType &val); // ������� ������
//	TVector operator* (const ValType &val); // �������� �� ������
	// ��������� ��������
	//TVector operator+ (const TVector &v); // ��������
	//TVector operator- (const TVector &v); // ���������
	//TVector operator* (const TVector &v); // ��������� ������������
	// ����-�����
	friend istream& operator >> <T> (istream &in, TVector  &v);
	friend ostream& operator << <T> (ostream &out, const TVector  &v);
};

template <class T>
TVector <T>::TVector(int s, int si)
{
	StartIndex = si;
	Size = s;
	pVector = new T[s - si];
	for (int i = 0; i < Size - StartIndex; i++)
	{
		pVector[i] = 0;
	}
}

template <class T>
T & TVector <T>:: operator[](int pos)
{
	return *pVector[pos];
}

template <class T>
TVector <T>::TVector(const TVector &v)
{

		pVector = new T[v.Size - v.StartIndex];
		StartIndex = v.StartIndex;
		Size = v.Size;
	for (int i = 0; i < Size - StartIndex; i++)
	{
		pVector[i] = v.pVector[i];
	}
}

template <class T>
int TVector <T>::GetSize()
{
	return Size;
}

template <class T>
int TVector <T>::GetStartIndex()
{
	return StartIndex;
}

template <class T>
int TVector <T>:: operator==(const TVector &v)
{
	if (Size != v.Size || StartIndex != v.StartIndex)
	{
		return 0;
	}
	for (int i = 0; i < Size - StartIndex; i++)
	{
		if (pVector[i] != v.pVector[i])
			return 0;
	}
	return 1;
}

template <class T>
TVector <T> & TVector <T>:: operator = (const TVector <T> &v)
{
	if (this != &v)
	{
		return *this;
	}
if (Size != v.Size || StartIndex != v.StartIndex)
{
	delete[] pVector;
	pVector = new T[v.Size - v.StartIndex];
	StartIndex = v.StartIndex;
	Size = v.Size;
}
for (int i = 0; i < Size - StartIndex; i++)
{
	pVector[i] = v.pVector[i];
}
return *this;
}

template <class T>
istream &  operator>>(istream &in, TVector  <T> & v)
{
	cout << "enter";
	for (int i = 0; i < v.Size - v.StartIndex; i++)
	{
		in >> v.pVector[i];
	}
	return in;
}

template <class T>
ostream& operator<<(ostream &out, const TVector <T> & v)
{
	for (int i = 0; i < v.StartIndex; i++)
	{
		out << 0 << ' ';
	}
	for (int i = 0; i < v.Size - v.StartIndex; i++)
	{
		out << v.pVector[i] << ' ';
	}
	return out;
}

template <class T>
TVector <T>::~TVector()
{
	delete[] pVector;
}
