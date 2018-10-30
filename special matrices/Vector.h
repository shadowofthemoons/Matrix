#include "pch.h"
#include <iostream>
#pragma once
using namespace std;


template <class T>
class TVector
{
protected:
	T *pVector;
	int Size; // размер вектора
	int StartIndex; // индекс первого элемента вектора
public:
	TVector(int s, int si);
	TVector(const TVector &v); // конструктор копирования
	~TVector();
	//	int GetSize() { return Size; } // размер вектора
	//	int GetStartIndex() { return StartIndex; } // индекс первого элемента
	//	ValType& GetValue(int pos); // доступ с контролем индекса
	T & operator[](int pos); // доступ
//	int operator==(const TVector &v); // сравнение
	//TVector& operator= (const TVector &v); // присванивание
	// скалярные операции
	//TVector operator+ (const ValType &val); // прибавить скаляр
//	TVector operator- (const ValType &val); // вычесть скаляр
//	TVector operator* (const ValType &val); // умножить на скаляр
	// векторные операции
	//TVector operator+ (const TVector &v); // сложение
	//TVector operator- (const TVector &v); // вычитание
	//TVector operator* (const TVector &v); // скалярное произведение
	// ввод-вывод
	friend istream& operator >> <T> (istream &in, TVector  &v);
	friend ostream& operator<< <T> (ostream &out, const TVector<T>  &v);
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
	if (Size != v.Size || StartIndex != v.StartIndex)
	{
		delete[] pVector;
		T *pVector = new T[v.Size - v.StartIndex];
		StartIndex = v.StartIndex;
		Size = v.Size;
	}
	for (int i = 0; i < Size - StartIndex; i++)
	{
		pVector[i] = v.pVector[i];
	}
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