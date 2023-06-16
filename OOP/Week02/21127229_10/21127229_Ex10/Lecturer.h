#pragma once
#include <string>
#include <iostream>
using namespace std;

class Lecturer {
public:
	Lecturer();
	Lecturer(int);
	Lecturer(int, string);
	Lecturer(int, string, string);
	Lecturer(int, string, string, int);
	~Lecturer();
public:
	void display();
private:
	int _id;
	string _fullname;
	string _degree; 
	int _numberOfTakenCourse;
};