
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using std::cout, std::cin, std::endl;
using std::string, std::stringstream;
using std::vector;

class Vehicle;
class Car;

class Vehicle {
protected: // private
    string _brandName;
public:
    Vehicle() {}
    Vehicle(string);
    virtual ~Vehicle();
public:
    void start();
    void stop();
};

class Car : public Vehicle {
public:
    Car(string);
    ~Car();
public:
    string whoAmI();
    void start();
};

Vehicle::Vehicle(string name){
    _brandName = name;
    cout << "Vehicle's constructor" << endl;
}

Vehicle::~Vehicle() {
    cout << "Vehicle's destructor" << endl;
}

void Vehicle::start() {
    cout << "Vehicle " << _brandName << " is starting." << endl;
}

void Vehicle::stop() {
    cout << "Vehicle " << _brandName << " has stopped." << endl;
}

Car::Car(string name) : Vehicle(name) {
    _brandName = name;
    cout << "Car's constructor" << endl;
}

Car::~Car() {
    cout << "Car's destructor" << endl;
}

string Car::whoAmI() {
    string result = "I am a " + _brandName + " car";
    return result;
}

void Car::start() {
    cout << "A car has its own way to start the engine..." << endl;
    Vehicle::start();
}



class Point2D {
protected:
    double _x;
    double _y;
public:
    Point2D(double, double);
    string toString();
};

Point2D::Point2D(double x, double y) {
    this->_x = x;
    this->_y = y;
}

string Point2D::toString() {
    stringstream builder;
    builder << "(" << _x << ", " << _y << ")";

    string result = builder.str();
    return result;
}

class Point3D : public Point2D {
protected:
    double _z;
public:
    Point3D(double, double, double);
    string toString();
};

Point3D::Point3D(double a, double b, double c)
    : Point2D(a, b) {
    this->_z = c;
}

string Point3D::toString() {
    stringstream builder;
    builder << "(" << _x << 
        ", " << _y <<
        ", " << _z << ")";

    string result = builder.str();
    return result;
}

class Shape;
class Rectangle;

class IShape {
public:
    virtual double area() = 0; // cai dat tam
    virtual double perimeter() = 0;
};

class Rectangle : public IShape {
protected:
    double _width;
    double _height;
public:
    Rectangle(double a, double b);
    double area();
    double perimeter() { return 2 * (_width + _height); }
};

class Square: public IShape {
protected:
    double _a;
public:
    Square(double a) { _a = a; }
    double area() { return _a * _a; }
    double perimeter() { return 4 * _a; }
};

class Circle : public IShape {
public:
    static const int Pi = 3.14;
protected:
    double _r;
public:
    Circle(double r) { _r = r; }
    double area() { return Pi * _r * _r; }
    double perimeter() { return 2 * _r * Pi; }
};

/// <summary>
/// 
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
Rectangle::Rectangle(double a, double b) {
    this->_width = a;
    this->_height = b;
}

double Rectangle::area() {
    double result = _width * _height;
    return result;
}

int main()
{
    vector<IShape*> shapes = {
        new Rectangle(3, 5),
        new Circle(5),
        new Square(9),
        new Circle(7),
        new Circle(8),
        new Rectangle(3, 6)
    };

    for (int i = 0; i < shapes.size(); i++) {
        IShape* shape = shapes[i];
        cout << shape->area() << ", " << shape->perimeter() << endl;
    }
};