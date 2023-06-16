#include "Lecturer.h"
#include <iostream>
using namespace std;

int main() {
	Lecturer a;
	Lecturer b(3);
	Lecturer c(4, "John");
	Lecturer d(8, "Mike", "BSc");
	Lecturer e(5, "Tysone", "PhD", 5);
	Lecturer f(-9, "Bill","",-9);
	a.display();
	b.display();
	c.display();
	d.display();
	e.display();
	f.display();

}