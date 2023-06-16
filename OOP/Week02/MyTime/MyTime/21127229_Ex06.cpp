#include <iostream>
#include "MyTime.h"

using namespace std;

int main() {
	MyTime a;
	MyTime b(1);
	MyTime c(4, 30);
	MyTime d(1, 9, 20);
	MyTime e(d);
	MyTime f = e;
	MyTime g(99, 99, 99);
	MyTime h(30, 2, 8);
	a.display();
	b.display();
	c.display();
	d.display();
	e.display();
	f.display();
	g.display();
	h.display();
}