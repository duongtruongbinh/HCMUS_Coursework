#include "MyIntArray.h"
#include <iostream>
using namespace std;

MyIntArray::MyIntArray()
{
	this->_n = 10;
	this->_a = new int[this->_n];	
	for (int i = 0; i < _n; i++)
		_a[i] = 0;
}

MyIntArray::MyIntArray(int n)
{
	if (n < 1) n = 10;
	this->_n = n;
	this->_a = new int[n];
	for (int i = 0; i < _n; i++)
		_a[i] = 0;
}

MyIntArray::MyIntArray(int n, int* ptr)
{
	if (n < 1 ) 
		n = 10;	
	if (ptr == NULL)
	{
		ptr = new int[n];
		for (int i = 0; i < _n; i++)
			ptr[i] = 0;
	}
	this->_n = n;
	this->_a = ptr;
}

MyIntArray::MyIntArray(const MyIntArray& other)
{
	this->_n = other._n;
	this->_a = new int[other._n];
	for (int i = 0; i < this->_n; i++)
		this->_a[i] = other._a[i];
}

MyIntArray& MyIntArray::operator=(const MyIntArray& other)
{
	this->_n = other._n;
	this->_a = new int[other._n];
	for (int i = 0; i < this->_n; i++)
		this->_a[i] = other._a[i];
	return *this;
}

MyIntArray::~MyIntArray() {
	delete[] this->_a;
	cout << "An object of class MyIntArray has been removed." << endl;
}

void MyIntArray::display() {
	cout << "N = " << this->_n<<endl;
	for (int i = 0; i < this->_n; i++)
		cout << this->_a[i] << " ";
	cout << endl;
}