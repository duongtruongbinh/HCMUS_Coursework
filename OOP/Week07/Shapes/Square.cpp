#include "Square.h"
using namespace std;

Square::Square(double edge)
{
    edge = abs(edge);
    this->_edge = edge;
}

string Square::toString()
{
    stringstream builder;
    builder << "Edge = " << this->_edge;
    return builder.str();
}

double Square::area()
{
    double result = this->_edge * this->_edge;
    return result;
}

double Square::perimeter()
{
    double result = this->_edge * 4;
    return result;
}