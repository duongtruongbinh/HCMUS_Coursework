#include "DisplayProductFunction.h"
#include <fstream>
#include <string>
#include "DeleteProductFunction.h"
#include "EditProductFunction.h"
#include "File.h"
using namespace std;
void DisplayProductFunction::run()
{
	DisplayProductConsole displayProductConsole;
	vector<Product> data;
	vector<string> header = { "ID","Name","Price" };
	vector<int> width = { 3,30,10 };
	string title;
	vector<string> instruction = {
		"Use left and right arrow to go to next/previous page",
		"To delete a row, select then press del",
		"To view the detail of a product for editing, press enter",
		"Press escape to go back to main menu"
	};
	
	
	
	int choice = 0;
	while (choice != -1)
	{
		system("cls");
		File file("Product.txt");
		data = file.readFile();
		Table productTable(instruction, header, width, data);
		int index;
		choice = displayProductConsole.display(productTable,index);
		DeleteProductFunction deleteProductFunction;
		EditProductFunction editProductFunction;
		switch (choice)
		{
		case 1:
			deleteProductFunction.run(index);
			break;
		case 2:
			editProductFunction.run(index);
			break;
		}
	}
}