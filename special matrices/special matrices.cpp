#include "pch.h"
#include <iostream>
#include "Vector.h"
#include "Matrix.h"
int main()
{
	TMatrix <int> m(3);
	cin >> m;
	TMatrix <int> m1(3);
	cin >> m1;
	TMatrix <int> m2((m*m1));
	cout << m<<endl<<m1<<endl<<m2;
}