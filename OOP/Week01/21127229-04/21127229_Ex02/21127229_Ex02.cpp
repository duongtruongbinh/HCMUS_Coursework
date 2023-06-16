#include "Header.h"
#include <iostream>
using namespace std;
int main()
{
	Triangle a;
	a.input();
	cout << a.isValidTriangle() << " ";
	a.getCenterG().output();
	cout << a.getArea() << " " << endl
		 << "" << a.getPerimeter()<<endl;
	cout << a.typeOfTriangle();
}