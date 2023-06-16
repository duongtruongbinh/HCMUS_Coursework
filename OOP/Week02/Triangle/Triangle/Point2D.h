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
	double distanceTo(Point2D);
private:
	static int count;
	double _x;
	double _y;
};
