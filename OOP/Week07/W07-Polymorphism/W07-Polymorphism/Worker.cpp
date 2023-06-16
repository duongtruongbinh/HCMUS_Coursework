#include "Worker.h"

Worker::Worker() : Employee()
{
	this->_numItem = 1;

}

Worker::Worker(int id) :Employee(id)
{
	this->_numItem = 1;

}

Worker::Worker(int id, int day) :Employee(id)
{
	this->_numItem = day;

}

Worker::Worker(int id, string name, int day) :Employee(id, name)
{
	this->_numItem = day;

}

Worker::Worker(int id, string name, Date date, string add, int day) :Employee(id, name, date, add)
{
	this->_numItem = day;

}

void Worker::input()
{
	Employee::input();
	cout << "Nhap so san pham lam: "; cin >> _numItem;

}

void Worker::output()
{
	Employee::output();
	cout << "So san pham lam: " << _numItem << endl;
	cout << "Tien luong moi san pham: " << _payPerItem << endl;
}

int Worker::salary()
{
	int result = _numItem * _payPerItem;
	return result;
}