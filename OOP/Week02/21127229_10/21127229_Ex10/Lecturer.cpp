#include "Lecturer.h"
#include <iostream>
using namespace std;

Lecturer::Lecturer()
{
	this->_id = 1;
	this->_degree = "PhD";
	this->_fullname = "Nguyen Van A";
	this->_numberOfTakenCourse = 1;
}

Lecturer::Lecturer(int id)
{
	if (id < 1) id = 1;
	this->_id = id;
	this->_degree = "PhD";
	this->_fullname = "Nguyen Van A";
	this->_numberOfTakenCourse = 1;
}

Lecturer::Lecturer(int id, string fullname)
{
	if (id < 1) id = 1;
	if (fullname == "") fullname = "Nguyen Van A";
	this->_id = id;
	this->_degree = "PhD";
	this->_fullname = fullname;
	this->_numberOfTakenCourse = 1;
}

Lecturer::Lecturer(int id, string fullname,string degree)
{
	if (id < 1) id = 1;
	if (fullname == "") fullname = "Nguyen Van A";
	if (degree == "") degree = "PhD";
	this->_id = id;
	this->_degree = degree;
	this->_fullname = fullname;
	this->_numberOfTakenCourse = 1;
}

Lecturer::Lecturer(int id, string fullname, string degree,int numberOfTakenCourse)
{
	if (id < 1) id = 1;
	if (fullname == "") fullname = "Nguyen Van A";
	if (degree == "") degree = "PhD";
	if (numberOfTakenCourse < 1) numberOfTakenCourse = 1;
	this->_id = id;
	this->_degree = degree;
	this->_fullname = fullname;
	this->_numberOfTakenCourse = numberOfTakenCourse;
}

Lecturer::~Lecturer()
{
	cout << "An object of class Lecturer has been removed." << endl;
}

void Lecturer::display()
{
	cout << "ID: " << this->_id << endl << "Name: " << this->_fullname << endl;
	cout << "Degree: " << this->_degree << endl << "Number of taken courses : " << this->_numberOfTakenCourse << endl;
}

