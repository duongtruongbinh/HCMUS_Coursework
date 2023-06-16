#include "Employee.h"
#include<iostream>

using namespace std;

Employee::Employee()
{
	this->_id = 1;
	this->_address = "227 Nguyen Van Cu";
	this->_hireDate = Date(1, 1, 1);
	this->_fullName = "Nguyen Van A";
}

Employee::Employee(int id)
{
	this->_id = id;
	this->_address = "227 Nguyen Van Cu";
	this->_hireDate = Date(1, 1, 1);
	this->_fullName = "Nguyen Van A";
}

Employee::Employee(int id,string name)
{
	this->_id = id;
	this->_address = "227 Nguyen Van Cu";
	this->_hireDate = Date(1, 1, 1);
	this->_fullName = name;
}

Employee::Employee(int id, string name,Date date)
{
	this->_id = id;
	this->_address = "227 Nguyen Van Cu";
	this->_hireDate = date;
	this->_fullName = name;
}

Employee::Employee(int id, string name, Date date,string add)
{
	this->_id = id;
	this->_address = add;
	this->_hireDate = date;
	this->_fullName = name;
}

void Employee::input()
{
	cout << "Nhap ID: "; cin >> this->_id;
	getline(cin, this->_address);
	cout << "Nhap ho ten: "; getline(cin, this->_fullName);
	//getline(cin, this->_address);
	cout << "Nhap dia chi: "; getline(cin,this->_address);
	int day, month, year;
	cout << "Nhap ngay thue: "; cin >> day;
	cout << "Nhap thang thue: "; cin >> month;
	cout << "Nhap nam thue: "; cin >> year;
	this->_hireDate = Date(day,month,year);
	
	
}

void Employee::output()
{
	cout << "ID: " << this->_id << endl;
	cout << "Ho ten: " << this->_fullName << endl;
	cout << "Dia chi: " << this->_address << endl;
	cout << "Ngay thue: " << this->_hireDate.toString() << endl;
}
