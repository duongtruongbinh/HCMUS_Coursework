#include <iostream>
#include "ABCFarm.h"
using namespace std;

int main()
{
	DairyCow a;
	DairyCow b(2, 30);
	DairyCow c(-2, 6);
	DairyCow d(3, -1);
	DairyCow e(d);
	c = d;
	a.ToString(); b.ToString(); c.ToString(); d.ToString(); e.ToString();
	cout << "=======================" << endl;
	Goat g1;
	Goat g2(4, 2);
	Goat g3 = g1;
	g2.setAge(50);
	g3.setWeight(100);
	g1.ToString();
	g2.ToString();
	g3.ToString();
	cout << "g1 age=" << g1.age() << endl;
	
	/*ABCFarm a;
	a.Input();
	a.Output();*/
	

}