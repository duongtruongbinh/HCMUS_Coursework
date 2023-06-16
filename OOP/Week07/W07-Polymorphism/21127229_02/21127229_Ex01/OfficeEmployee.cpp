#include "OfficeEmployee.h"

OfficeEmployee::OfficeEmployee(): Employee()
{
	this->_workDay = 1;
	
}

OfficeEmployee::OfficeEmployee(int id) :Employee(id)
{
	this->_workDay = 1;
	
}

OfficeEmployee::OfficeEmployee(int id,int day) :Employee(id)
{
	this->_workDay = day;
	
}

OfficeEmployee::OfficeEmployee(int id,string name, int day) :Employee(id,name)
{
	this->_workDay = day;
	
}

OfficeEmployee::OfficeEmployee(int id, string name, Date date, string add, int day) :Employee(id, name, date, add)
{
	this->_workDay = day;
	
}

void OfficeEmployee::input()
{
	Employee::input();
	cout << "Nhap so ngay lam: "; cin >> _workDay;
	
}

void OfficeEmployee::output()
{
	Employee::output();
	cout << "So ngay lam: " << _workDay << endl;
	cout << "Tien luong moi ngay: " << _payPerDay<<endl;
}

int OfficeEmployee::salary()
{
	int result = _workDay * _payPerDay;
	return result;
}