#include "MyIntArray.h"
#include <iostream>
using namespace std;

int main() {
	MyIntArray a;
	MyIntArray b(15);
	MyIntArray c(10, new int[10]);
	MyIntArray d(c);
	a.display();
	b.display();

	c.display();
	d.display();

}