#include "DairyCow.h"
#include <sstream>




DairyCow::DairyCow() : Animal()
{
	//_count++;
}

DairyCow::DairyCow(double age, double weight): Animal(age,weight)
{
	//_count++;
	
}

DairyCow::DairyCow(const DairyCow& other):Animal(other)
{
	
}


void DairyCow::ToString()
{
	stringstream builder;
	builder << "Cow Id = " << this->identifier() << endl << "Age = "<<this->age() << endl <<"Weight = "<< this->weight();
	cout << builder.str()<<endl;
}

DairyCow::~DairyCow()
{
	//Destructor
}