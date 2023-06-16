#include "Goat.h"
#include <sstream>




Goat::Goat() : Animal()
{
	//_count++;
}

Goat::Goat(double age, double weight) : Animal(age, weight)
{
	//_count++;

}

Goat::Goat(const Goat& other):Animal(other)
{
}


void Goat::ToString()
{
	stringstream builder;
	builder << "Goat Id = " << this->identifier() << endl << "Age = " << this->age() << endl << "Weight = " << this->weight();
	cout << builder.str() << endl;
}

Goat::~Goat()
{
	//Destructor
}