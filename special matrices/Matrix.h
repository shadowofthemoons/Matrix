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
	//TMatrix(const TMatrix &mt); // копирование
	//TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа
	//TMatrix& operator==(const TMatrix &mt); // сравнение
	//TMatrix& operator= (const TMatrix &mt); // присваивание
	//TMatrix operator+ (const TMatrix &mt); // сложение
	//TMatrix operator- (const TMatrix &mt); // вычитание
	//TMatrix operator* (const TMatrix &mt); // умножение
	// ввод / вывод
	//friend istream& operator>>(istream &in, TMatrix &mt);
	//friend ostream & operator<<(ostream &out, const TMatrix &mt);
};