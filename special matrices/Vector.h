#pragma once
#include "pch.h"
#include <iostream>
using namespace std;


template <class T>
class TVector
{
protected:
	T *pVector;
	int Size; // размер вектора
	int StartIndex; // индекс первого элемента вектора
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector &v); // конструктор копирования
	~TVector();
	int GetSize();// размер вектора
	int GetStartIndex(); // индекс первого элемента
	T & operator[](int pos)const ; // доступ
	int operator==(const TVector &v); // сравнение
	int operator!=(const TVector &v);
	TVector& operator= (const TVector  &v); // присванивание
	// скалярные операции
	TVector operator+ (const T &val); // прибавить скаляр
	TVector operator- (const T &val); // вычесть скаляр
	TVector operator* (const T &val); // умножить на скаляр
	// векторные операции
	TVector operator+ (const TVector &v); // сложение
	TVector operator- (const TVector &v); // вычитание
	T operator* (const TVector &v); // скалярное произведение
	// ввод-вывод
	friend istream& operator >> <T> (istream &in, TVector  &v);
	friend ostream& operator << <T> (ostream &out, const TVector  &v);
};

template <class T>
TVector <T>::TVector(int s, int si)
{
	if (si > s)
	{ 
		cout << "eror: StartIndex > Size" << endl;
		exit(1);
	}
	StartIndex = si;
	Size = s;
	pVector = new T[s - si];
	for (int i = 0; i < Size - StartIndex; i++)
	{
		pVector[i] = 0;
	}
}

template <class T>
TVector <T>::TVector(const TVector &v)
{
	StartIndex = v.StartIndex;
	Size = v.Size;
	pVector = new T[Size - StartIndex];
	for (int i = 0; i < Size - StartIndex; i++)
	{
		pVector[i] = v.pVector[i];
	}
}

template <class T>
TVector <T>::~TVector()
{
	delete[] pVector;
}



template <class T>
T & TVector <T>:: operator[](int pos)const
{
	T o = 0;
	if (pos > Size||pos<0)
	{
		cout << "eror:out of vector";
		throw(0);
	}
	if (pos < StartIndex)
	{
		return o;
	}
	return pVector[pos - StartIndex];
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
int TVector <T>:: operator!=(const TVector &v)
{
	if (Size != v.Size || StartIndex != v.StartIndex)
	{
		return 1;
	}
	for (int i = 0; i < Size - StartIndex; i++)
	{
		if (pVector[i] != v.pVector[i])
			return 1;
	}
	return 0;
}

template <class T>
TVector <T> & TVector <T>:: operator = (const TVector <T> &v)
{
	if (this == &v)
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
TVector <T> TVector <T>::operator+ (const T &val)
{

	TVector <T> var(Size,0);
	for (int i = 0; i <  StartIndex; i++)
	{
		var.pVector[i] = val;
	}
	for (int i = StartIndex; i < Size ; i++)
	{
		var.pVector[i] = pVector[i- StartIndex] + val;
	}
	return var;
}

template <class T>
TVector <T> TVector <T>::operator- (const T &val)
{

	TVector <T> var(Size, 0);
	for (int i = 0; i < StartIndex; i++)
	{
		var.pVector[i] = -val;
	}
	for (int i = StartIndex; i < Size; i++)
	{
		var.pVector[i] = pVector[i - StartIndex] - val;
	}
	return var;
}

template <class T>
TVector <T> TVector <T>::operator* (const T &val)
{
	TVector <T> var(*this);
	for (int i = 0; i < Size - StartIndex; i++)
	{
		var.pVector[i] *= val;
	}
	return var;
}

template <class T>
TVector <T> TVector <T>::operator+ (const TVector &v)
{
	if (Size != v.Size)
	{
		cout << "eror: different sizes of vectors, impossible to add" << endl;
		throw(0);
	}
	if (StartIndex > v.StartIndex)
	{
		TVector <T> var(Size, v.StartIndex);
		for (int i = 0; i < StartIndex - v.StartIndex; i++)
		{
			var.pVector[i] = v.pVector[i];
		}
		for (int i = 0; i < Size - StartIndex; i++)
		{
			var.pVector[i + StartIndex - v.StartIndex] = pVector[i] + v.pVector[i + StartIndex - v.StartIndex];
		}
		return var;
	}
	else
	{
		TVector <T> var(Size, StartIndex);
		for (int i = 0; i < v.StartIndex - StartIndex; i++)
		{
			var.pVector[i] = pVector[i];
		}
		for (int i = 0; i < Size - v.StartIndex; i++)
		{
			var.pVector[i + v.StartIndex - StartIndex] = v.pVector[i] + pVector[i + v.StartIndex - StartIndex];
		}
		return var;
	}
}

template <class T>
TVector <T> TVector <T>::operator- (const TVector &v)
{
	if (Size != v.Size)
	{
		cout << "eror: different sizes of vectors, impossible to deduct" << endl;
		throw(0);
	}
	if (StartIndex > v.StartIndex)
	{
		TVector <T> var(Size, v.StartIndex);
		for (int i = 0; i < StartIndex - v.StartIndex; i++)
		{
			var.pVector[i] = -v.pVector[i];
		}
		for (int i = 0; i < Size - StartIndex; i++)
		{
			var.pVector[i + StartIndex - v.StartIndex] = pVector[i] - v.pVector[i + StartIndex - v.StartIndex];
		}
		return var;
	}
	else
	{
		TVector <T> var(Size, StartIndex);
		for (int i = 0; i < v.StartIndex - StartIndex; i++)
		{
			var.pVector[i] = pVector[i];
		}
		for (int i = 0; i < Size - v.StartIndex; i++)
		{
			var.pVector[i + v.StartIndex - StartIndex] = -v.pVector[i] + pVector[i + v.StartIndex - StartIndex];
		}
		return var;
	}
}

template <class T>
T TVector <T>::operator* (const TVector &v)
{
	if (Size != v.Size )
	{
		cout << "eror: different sizes of vectors, unable to calculate scalar product" << endl;
		throw(0);
	}
	T var = 0;
	if (StartIndex > v.StartIndex)
	{
		for (int i = 0; i < Size - StartIndex; i++)
		{
			var += pVector[i] * v.pVector[i + StartIndex - v.StartIndex];
		}
	}
	else
	{
		for (int i = 0; i < Size - v.StartIndex; i++)
		{
			var += v.pVector[i] * pVector[i + v.StartIndex - StartIndex];
		}
	}
	return var;
}

template <class T>
istream &  operator>>(istream &in, TVector  <T> & v)
{
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
		out.width(4);
		out << 0 <<' ';
		
	}

	for (int i = 0; i < v.Size - v.StartIndex; i++)
	{
		out.width(4);
		out << v.pVector[i] << ' ';
	   
	}
	return out;
}

