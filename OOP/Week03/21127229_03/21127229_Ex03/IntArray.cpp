#include "IntArray.h"

IntArray::IntArray()
{
	this->_size = 0;
	this->_ptr = new int[this->_size];
}

IntArray::IntArray(int size)
{
	this->_size = size;
	this->_ptr = new int[this->_size]{0};
}

IntArray::IntArray(int* pointer, int size)
{
	this->_size = size;
	this->_ptr = new int[size];
	for (int i = 0; i < size; i++)
		this->_ptr[i] = *(pointer+i);
}

IntArray::IntArray(const IntArray& other)
{
	this->_size = other._size;
	this->_ptr = new int[this->_size];
	for (int i = 0; i < other._size; i++)
		this->_ptr[i] = other._ptr[i];
}

IntArray& IntArray::operator=(const IntArray& other)
{
	if (this == &other) return *this;
	this->_size = other._size;
	
	delete[] this->_ptr;
	this->_ptr = new int[this->_size];
	for (int i = 0; i < other._size; i++)
		this->_ptr[i] = other._ptr[i];
	return *this;
}

istream& operator>>(istream& is,  IntArray& array)
{
	cout << "N=";
	
	is >> array._size;

	delete[] array._ptr;
	array._ptr = new int[array._size];
	for (int i = 0; i < array._size; i++)
	{
		
		cout << "a[" << i << "]=";
		is >> array._ptr[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const IntArray& array)
{
	for (int i = 0; i < array._size; i++)
		os << array._ptr[i]<<" ";
	return os;
}

int& IntArray::operator[](int i)
{
	return this->_ptr[i];
}

IntArray::operator int()const
{
	return this->_size;
}

IntArray::~IntArray()
{
	cout << "Deleted.";
	if (this->_ptr != nullptr) {
		delete[] this->_ptr;
		
	}
}