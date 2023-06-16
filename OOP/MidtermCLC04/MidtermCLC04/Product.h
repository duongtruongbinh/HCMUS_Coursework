#pragma once
#include <iostream>
#include <string>
using namespace std;
class Product;

class Product
{
public:
	Product();
	Product(const Product&);
public:
	void input();
	void output();
	double price();
	string producer();
	int id();
	string name();
	int cost();
private:
	int _id;
	string _name;
	string _producer;
	int _cost;
};