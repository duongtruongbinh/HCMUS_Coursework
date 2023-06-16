#include "Point2D.h"
using namespace std;

int main()
{
	Point2D a;
	Point2D b(7);
	Point2D c(8, 9.0);
	Point2D d(4, true);
	Point2D f(5, false);
	Point2D e(f);

	a.display();
	b.display();
	d.display();
	c.display();
	f.display();
	e.display();
}