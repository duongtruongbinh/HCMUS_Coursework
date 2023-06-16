
#include "Cat.h"
#include <iostream>
using namespace std;

void Cat::run() {
    _weight -= 1;
    cout << "A cat is running happily" << endl;
}

void Cat::sleep() {
    cout << "A cat is sleeping in peace" << endl;
}

void Cat::eat() {
    cout << "Nothing eat > Meaow" << endl;
}