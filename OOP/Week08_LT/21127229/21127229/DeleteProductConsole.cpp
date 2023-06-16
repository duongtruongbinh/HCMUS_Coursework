#include "DeleteProductConsole.h"

int DeleteProductConsole::display(vector<Product>& productList, int index)
{
	system("cls");
	cout << "Selected product:" << endl;
	cout << "ID=" << productList[index].id() << ", Name=" << productList[index].name() << ", Price=" << productList[index].price() << endl << endl;
	cout << "Do you really want to delete this product? (Y/N)";
	char ch; cin >> ch;
	if (ch == 'n' || ch == 'N') return 0;
	
	return 1;


}