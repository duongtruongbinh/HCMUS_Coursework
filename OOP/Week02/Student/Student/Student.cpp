#include "Student.h"
#include <iostream>
using namespace std;

Student::Student()
{
	this->_id = 1;
	this->_fullname = (char*)"";
	this->_address = (char*)"";
	this->_gpa = 0;
}
Student::Student(int id)
{
	if (id < 1) id = 1;
	this->_id = id;
	this->_gpa = 0;
	this->_fullname = (char*)"";
	this->_address = (char*)"";
}

Student::Student(int id, double gpa)
{
	if (id < 1) id = 1;
	if (gpa < 0) gpa = 0;
	this->_id = id;
	this->_gpa = gpa;
	this->_fullname = (char*)"";
	this->_address = (char*)"";
}

Student::Student(int id, char* name, char* address, double gpa)
{
	if (id < 1) id = 1;
	if (gpa < 0) gpa = 0;
	this->_id = id;
	this->_gpa = gpa;
	this->_fullname = name;
	this->_address = address;
}

Student::Student(const Student& other)
{
	this->_id = other._id;
	this->_gpa = other._gpa;
	this->_address = other._address;
	this->_fullname = other._fullname;
}

Student::~Student()
{
	
	cout << "An object of class Student has been removed." << endl;
}

void Student::display()
{
	cout << "ID: " << this->_id << endl<<"GPA: " << this->_gpa << endl;
	if (this->_fullname != nullptr)
		cout << "Name: " << this->_fullname << endl;
	if (this->_address != nullptr)
		cout << "Address: " << this->_address << endl;
}