#include "Animal.h"
#include <sstream>
#include <iostream>
using namespace std;

bool Animal::isValidAge(double age)
{
	bool result = age > 0;
	return result;
}

bool Animal::isValidWeight(double weight)
{
	bool result = weight > 0;
	return result;
}

double Animal::age()const
{
	return this->_age;
}

double Animal::weight()const
{
	return this->_weight;
}

int Animal::identifier()const
{
	return this->_identifier;
}

void Animal::setAge(double age)
{
	if (age <= 0) age = 1;
	this->_age = age;
}

void Animal::setIdentifier(int id)
{
	if (this->_identifier == 0) this->_identifier = id;
}

void Animal::setWeight(double weight)
{
	if (weight <= 0) weight = 1;
	this->_weight = weight;
}

Animal::Animal()
{
	_count++;
	this->setIdentifier(_count);
	this->setAge(1);
	this->setWeight(1);

}

Animal::Animal(double age, double weight)
{
	_count++;
	if (isValidAge(age) == false)
		age = 1;
	if (isValidWeight(weight) == false)
		weight = 1;
	this->setIdentifier(_count);
	this->setAge(age);
	this->setWeight(weight);
}

Animal::Animal(const Animal& other)
{
	_count++;
	this->setAge(other.age());
	this->setWeight(other.weight());
	this->setIdentifier(_count);
}

Animal& Animal::operator=(const Animal& other)
{
	_count++;
	this->setAge(other.age());
	this->setWeight(other.weight());
	this->setIdentifier(_count);
	return *this;
}

void Animal::ToString()
{
	stringstream builder;
	builder << "Cow Id = " << this->identifier() << endl << "Age = " << this->age() << endl << "Weight = " << this->weight();
	cout << builder.str() << endl;
}

Animal::~Animal()
{
	//Destructor
}