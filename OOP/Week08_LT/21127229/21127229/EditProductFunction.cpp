#include "EditProductFunction.h"
#include "File.h"
void EditProductFunction::run(int index)
{
	File file("Product.txt");
	vector<Product> productList = file.readFile();

	EditProductConsole editProductConsole;
	productList[index] = editProductConsole.display(productList, index);
	file.writeFile(productList);
}