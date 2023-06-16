#include "Student.h"
#include <iostream>
using namespace std;

int main() {
	Student a;
	Student b(3);
	Student c(3, 8);
	Student d(c);
	a.display();
	b.display();
	c.display();
	d.display();

}