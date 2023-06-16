#include "MainFunction.h"

using namespace std;



void MainFunction::run()
{
	int choice=1;
	while (choice != -1) {
		vector<string> option = {
			"Display all products (paging support - table)",
			"Add a new product",
			"Delete a product by id"
		};
		string title = "MyShop App. Please select a function:";
		vector<string> instruction{
			"Press escape to quit"
		};

		Menu menu(title, option, instruction);
		MenuConsole menuConsole;
		choice = menuConsole.display(menu);
		if (choice == -1) return;
		system("cls");


		DisplayProductFunction displayProductFunction;
		AddProductFunction addProductFunction;
		DeleteProductByIDFunction deleteProductByIDFunction;
		switch (choice)
		{
		case 0:
			displayProductFunction.run();
			break;
		case 1:
			addProductFunction.run();
			break;
		case 2:
			deleteProductByIDFunction.run();
			break;
		}
		system("cls");
	}
}