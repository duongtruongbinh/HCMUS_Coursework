#include "Circle.h"
#include <iostream>
using namespace std;

int main() {
	Circle a;
	Circle b(3.2);
	Circle c(Point2D(0, 3.0));
	Circle d(c);
	Circle e = c;
	Circle f(Point2D(8.0, 9.0), 4);
	Circle g(Point2D(3.2,8.9) ,-9);
	a.display();
	b.display();
	c.display();
	d.display();
	e.display();
	f.display();
	g.display();
}