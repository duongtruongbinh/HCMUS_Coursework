#pragma once
#include "Object.h"

class Product;

class Product : public Object
{
public:
    Product(int, string, int);
    Product& operator=(const Product&);

public:
    string name();
    int id();
    int price();
    string toString();

private:
    int _id;
    int _price;
    string _name;
};