#include "pch.h"
#include <iostream>
#include "Vector.h"
int main()
{
	TVector <int> f(4, 2);
	cin >> f;
	TVector <int > f1(5,3);
	f1 = f;
	f1=f1;
	cout << f1;
}