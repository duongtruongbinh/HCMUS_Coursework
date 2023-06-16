#include "DeleteProductFunction.h"
#include "File.h"
void DeleteProductFunction::run(int index)
{
	File file("Product.txt");
	vector<Product> productList = file.readFile();

	DeleteProductConsole deleteProductConsole;
	int choice = deleteProductConsole.display(productList, index);
	if (choice == 1) productList.erase(productList.begin() + index);
	file.writeFile(productList);
}