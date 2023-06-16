#pragma once
#include "Point2D.h"
class Triangle {
public:
	Triangle();
	Triangle(Point2D);
	Triangle(Point2D, Point2D);
	Triangle(Point2D, Point2D, Point2D);
	Triangle(const Triangle& other);
	Triangle& operator=(const Triangle& other);
	~Triangle();
public:
	void display();
	bool isValidTriangle(Point2D, Point2D, Point2D);
private:
	Point2D _pointA;
	Point2D _pointB;
	Point2D _pointC;
};