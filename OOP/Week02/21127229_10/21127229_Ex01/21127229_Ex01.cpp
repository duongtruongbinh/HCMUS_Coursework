#include "Fraction.h"
using namespace std;

int main() {
	Fraction a;
	Fraction b(5,3);
	Fraction c(7);
	Fraction d(3, true);
	Fraction e(2, false);
	Fraction f(a);
	Fraction g(2, 0);
	a.display();
	b.display();
	c.display();
	d.display();
	e.display();
	f.display();
	g.display();
}