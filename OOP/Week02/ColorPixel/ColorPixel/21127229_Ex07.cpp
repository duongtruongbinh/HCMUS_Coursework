#include "ColorPixel.h"
#include <iostream>

using namespace std;

int main() {
	ColorPixel a;
	ColorPixel b(2);
	ColorPixel c(2, 6);
	ColorPixel d(54,51, 55);
	ColorPixel e(d);
	ColorPixel f(999);
	ColorPixel g(-9, 2);
	ColorPixel h = g;
	a.display();
	b.display();
	c.display();
	d.display();
	e.display();
	f.display();
	g.display();
	h.display();

}