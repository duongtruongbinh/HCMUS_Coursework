#include <iostream>
#include <vector>
#include <string>
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "ParserFactory.h"
#include "Utils.h"

using namespace std;
using namespace Utils;
int main()
{
    vector<string> lines = {
        "Square: a=12",
        "Circle: r=12",
        "Square: a=7",
        "Rectangle: w=3, h=4",
        "Rectangle: w=6, h=8",
        "Circle: r=5",
        "Square: a=8"};

    ParserFactory factory;
    vector<IShape *> shapes;

    for (string line : lines)
    {
        // Example: line = "Square: a=12"
        vector<string> tokens = Utils::String::split(line, ": ");
        IParsable *parser = factory.create(tokens[0]);                    // "Square"=> SquareParser
        IShape *shape = dynamic_cast<IShape *>(parser->parse(tokens[1])); // "a=12" => Square(_a = 12)
        shapes.push_back(shape);
    }

    for (IShape *shape : shapes)
    { // Polymorphism
        cout << shape->toString() << ": area="
             << shape->area() << ", perimeter="
             << shape->perimeter() << endl;
    }
}