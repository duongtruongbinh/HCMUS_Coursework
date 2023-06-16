#pragma once
#include <iostream>
using namespace std;

class IntArray
{
public:
	IntArray();
	IntArray(int);
	IntArray(int*, int);
	IntArray(const IntArray&);
	IntArray& operator=(const IntArray&);
	friend ostream& operator<<(ostream&, const IntArray&);
	friend istream& operator>>(istream&,  IntArray&);
	int& operator[](int);
	operator int() const;
	~IntArray();
private:
	int _size;
	int* _ptr;
};