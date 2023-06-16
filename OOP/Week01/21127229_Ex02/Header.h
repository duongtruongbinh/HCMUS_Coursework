#pragma once
#include <string>
using namespace std;
class Point;
class Triangle;

class Point
{
	double _x;
	double _y;
public:
	void setX(double value) { this->_x = value; }
	void setY(double value) { this->_y = value; }
	double getX() { return this->_x; }
	double getY() { return this->_y; }

	void input();
	void output();

	double distanceTo(Point);
	double distanceToOx();
	double distanceToOy();
};

class Triangle 
{
	Point _pointA;
	Point _pointB;
	Point _pointC;
public:
	void input();
	void output();

	bool isValidTriangle();
	string typeOfTriangle();
	double getPerimeter();
	double getArea();
	Point getCenterG();
};