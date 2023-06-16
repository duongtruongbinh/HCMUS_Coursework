#include "Triangle.h"
#include "Point2D.h"
#include <iostream>
using namespace std;

int main() {
	Point2D A;
	Point2D B(10.2, 6.3);
	Point2D C(3, 9.0);
	Triangle t1(A,B,C);
	Triangle t2(B);
	Triangle t3;
	Triangle t4(C, B);
	t1.display();
	t2.display();
	t3.display();
	t4.display();
	
}