#pragma once

class Point2D {
public:
	Point2D();
	Point2D(double);
	Point2D(double, double);
	Point2D(double, bool);
	Point2D(const Point2D& other);
	Point2D& operator=(const Point2D& other);
	~Point2D();
public:
	void display();
private:
	static int count;
	double _x;
	double _y;
};

class Circle {
public:
	Circle();
	Circle(Point2D);
	Circle(double);
	Circle(Point2D, double);
	Circle(const Circle& other);
	Circle& operator=(const Circle& other);
	~Circle();
public:
	void display();

private:
	Point2D _center;
	double _radius;
};


