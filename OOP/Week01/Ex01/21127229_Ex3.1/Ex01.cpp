#include "Fraction.h"
#include <iostream>
using namespace std;

int main() {
	Fraction a;
	Fraction b;
	Integer temp;
	
	a.input();
	/*b.input();
	Fraction c = a.divide(b);
	c.output();*/
	cout << a.isNegative();
}