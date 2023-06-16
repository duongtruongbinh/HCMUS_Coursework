#include "Store.h"

using namespace std;

int main() {
	Store a;
	a.input();
	//a.output();
	a.sort();
	a.output();
	cout << "Price ="<<a.totalPrice();
	a.outputProductFromProducer("abc");
	return 0;
}