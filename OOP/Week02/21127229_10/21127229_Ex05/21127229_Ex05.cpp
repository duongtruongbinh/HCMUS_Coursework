#include "MyDate.h"
#include <iostream>
using namespace std;

int main()
{
	MyDate a;
	MyDate b(8);
	MyDate c(9, 12);
	MyDate d(7, 3, 2012);
	MyDate e(99);
	MyDate f(e);
	MyDate g(32, 5, 2001);
	MyDate h(30, 2, 2023);
	MyDate i = MyDate(99, 9, 2);
	a.display();
	b.display();
	c.display();
	d.display();
	e.display();
	f.display();
	g.display();
	h.display();
	i.display();
}