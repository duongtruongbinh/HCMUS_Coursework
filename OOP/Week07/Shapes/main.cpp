#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<Rectangle*> rectangles = {
		new Rectangle(4, 7), // width + height
    new Rectangle(6, 8),
    new Rectangle(3, 2)
  };

  for(Rectangle* shape: rectangles){
    cout << shape->toString() << ": " 
         << shape->area() << " " << shape->perimeter()
         << endl;
  }

	vector<Square*> squares= {
		new Square(7),
    new Square(6),
    new Square(9)
  };

  for(Square* shape: squares){
    cout << shape->toString() << ": " 
			   << shape->area() << " " << shape->perimeter() 
				 << endl;
  }

   vector<Circle*> circles= {
		new Circle(4.3), // radius
    new Circle(5.5),
    new Circle(6.2)
  };

  for(Circle* shape: circles){
    cout << shape->toString() << ": " 
					<< shape->area() << " " << shape->perimeter() 
					<< endl;
  }
}