#pragma once
#include "Console.h"
#include "Product.h"
class EditProductConsole;

class EditProductConsole :public Console
{
public:
	Product display(vector<Product>&,int);
};