#pragma once
#include "Console.h"
#include "Product.h"
class DeleteProductConsole;

class DeleteProductConsole : public Console
{
public:
	int display(vector<Product>&,int);
};