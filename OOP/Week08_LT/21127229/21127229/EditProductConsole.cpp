#include "EditProductConsole.h"

Product EditProductConsole::display(vector<Product>& productList,int index)
{
	system("cls");
	cout << "Selected product:" << endl;
	cout << "ID=" << productList[index].id() << ", Name=" << productList[index].name() << ", Price=" << productList[index].price() << endl << endl;
	cout << "Do you want to edit? (Y/N)";
	char ch; cin >> ch;
	if (ch == 'n' || ch == 'N') return productList[index];
	cout << "Enter new name:";
	string name;
	cin.ignore();
	getline(cin, name);
	cout << "Enter new price: ";
	int price; cin >> price;
	return Product(productList[index].id(), name, price);
}