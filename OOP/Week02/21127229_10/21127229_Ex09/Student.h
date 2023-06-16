#pragma once

class Student
{
public:
	Student();
	Student(int);
	Student(int, double);
	Student(int, char*, char*, double);
	Student(const Student& other);
	~Student();
public:
	void display();
private:
	int _id;
	char* _fullname;
	char* _address;
	double _gpa;
};
