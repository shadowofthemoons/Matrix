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
	//TMatrix& operator==(const TMatrix &mt); // сравнение
	//TMatrix& operator= (const TMatrix &mt); // присваивание
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
		// добавить форматирование вывода 
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

template <class T>
TMatrix <T>::TMatrix(const TMatrix <T>&mt) : TVector<TVector<T>>(mt)
{
}

template <class T>
TMatrix <T>::TMatrix(const TVector<TVector<T> > &mt) : TVector<TVector<T>>(mt)
{
}

template <class T>
TMatrix <T> TMatrix <T>:: operator+ (const TMatrix &mt)
{
	// добавить проверку на размер и начальный элемент 
	TMatrix <T> var(*this);
	for (int i = 0; i < TVector<TVector<T>>::Size; i++)
	{
		var.pVector[i] = var.pVector[i] + mt.pVector[i];
	}
	return var;
}

template <class T>
TMatrix <T> TMatrix <T>:: operator- (const TMatrix &mt)
{
	// добавить проверку на размер и начальный элемент 
	TMatrix <T> var(*this);
	for (int i = 0; i < TVector<TVector<T>>::Size; i++)
	{
		var.pVector[i] = var.pVector[i] - mt.pVector[i];
	}
	return var;
}

template <class T>
TMatrix <T> TMatrix <T>:: operator * (const TMatrix <T> &mt)
{
	// добавить проверку на размер и начальный элемент 
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