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
	TMatrix(const TMatrix &mt); // копирование
	TMatrix(const TVector<TVector<T> > &mt); // преобразование типа
	int operator==(const TMatrix &mt)const; // сравнение
	int operator!=(const TMatrix &mt)const;
	TMatrix& operator= (const TMatrix &mt); // присваивание
	TMatrix operator+ (const TMatrix &mt); // сложение
	TMatrix operator- (const TMatrix &mt); // вычитание
	TMatrix operator* (const TMatrix &mt); // умножение
	// ввод / вывод
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
		this->pVector[i] = TVector<T>(s , i);
	}
}

template <class T>
TMatrix <T>::TMatrix(const TMatrix <T>&mt) : TVector<TVector<T>>(mt)
{
}

template <class T>
TMatrix <T>::TMatrix(const TVector<TVector<T> > &mt) : TVector<TVector<T>>(mt)
{
}

template <class T>
int TMatrix <T>:: operator == (const TMatrix <T>  &mt) const
{
	if (this->Size != mt.Size || this->StartIndex != mt.StartIndex)
	{
		return 0;
	}
	for (int i = 0; i < mt.Size - mt.StartIndex; i++)
	{
		if (this->pVector[i] != mt.pVector[i])
		{
			return 0;
		}
		return 1;
	}
}

template <class T>
int TMatrix <T>:: operator != (const TMatrix <T>  &mt) const
{
	if (*this == mt)
	{
		return 0;
	}
	return 1;
}

template <class T>
TMatrix <T> & TMatrix <T>:: operator = (const TMatrix <T>  &mt) 
{
	if (*this == mt)
	{
		return *this;
	}
	delete[] this->pVector;
	this->pVector = new TVector <T>[mt.Size - mt.StartIndex];
	for (int i = 0; i < mt.Size - mt.StartIndex; i++)
	{
		this->pVector[i] = mt.pVector[i];
	}
	this->Size = mt.Size;
	this->StartIndex = mt.StartIndex;
	return *this;
}

template <class T>
TMatrix <T> TMatrix <T>:: operator+ (const TMatrix &mt)
{ 
	if (this->Size != mt.Size || this->StartIndex != mt.StartIndex)
	{
		cout << "eror:different sizes of matrices";
		throw(0);
	}
	TMatrix <T> var(*this);
	for (int i = 0; i < this->Size; i++)
	{
		var.pVector[i] = var.pVector[i] + mt.pVector[i];
	}
	return var;
}

template <class T>
TMatrix <T> TMatrix <T>:: operator- (const TMatrix &mt)
{
	if (this->Size != mt.Size || this->StartIndex != mt.StartIndex)
	{
		cout << "eror:different sizes of matrices";
		throw(0);
	}
	TMatrix <T> var(*this);
	for (int i = 0; i < this->Size; i++)
	{
		var.pVector[i] = var.pVector[i] - mt.pVector[i];
	}
	return var;
}

template <class T>
TMatrix <T> TMatrix <T>:: operator * (const TMatrix <T> &mt)
{
	if (this->Size != mt.Size || this->StartIndex != mt.StartIndex)
	{
		cout << "eror:different sizes of matrices";
		throw(0);
	}
	TMatrix <T> var(mt.Size);
	for (int i = 0; i < mt.Size; i++)
	{
		for (int j = i; j < mt.Size; j++)
		{
			for (int k = 0; k < mt.Size; k++)
			{
				var[i][j] += (*this)[i][k] * mt[k][j];
			}
		}
	}
	return var;
}
