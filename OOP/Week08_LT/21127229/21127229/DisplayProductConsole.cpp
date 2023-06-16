#include "DisplayProductConsole.h"

int DisplayProductConsole::display(Table& productTable,int& choosedProduct)
{
	vector<Product> productList = productTable.data();
	vector<int> width = productTable.width();
	vector<string> header = productTable.header();
	vector<string> instruction = productTable.instruction();
	int numberProduct = productList.size();
	int numberOfPage = numberProduct / _numberProductPerPage + 1;
	int currentPage = 1;
	int coloredLine = 1;
	bool isPageChanged = false;
	while (true)
	{
		goTo(0, 0);
		if (isPageChanged) 
		{
			coloredLine = 1;
			system("cls");
		}
		isPageChanged = false;
		int numberProductDisplay = currentPage < numberOfPage ? _numberProductPerPage : numberProduct % _numberProductPerPage;
		cout << "All products. Page " << currentPage << "/" << numberOfPage << ". Displaying "<<numberProductDisplay<<"/" << numberProduct << " items" << endl;
		for (int i = 0; i < header.size(); i++)
		{
			cout << setw(width[i]) << header[i];
			if (i != header.size() - 1) cout << "|";
		}
		cout << setfill('-') << endl;
		for (int i = 0; i < header.size(); i++)
		{
			cout << setw(width[i]) << "-";
		}
		cout << "--";
		cout << setfill(' ') << endl;
		
		for (int i = 0; i < numberProductDisplay; i++)
		{
			if (i == coloredLine - 1) setColor(0, 1);
			int index = i + (currentPage - 1) * _numberProductPerPage;
			cout << setfill('0') << setw(width[0]) << productList[index].id()<<"|" << setfill(' ') << setw(width[1]) << productList[index].name() << "|" << setw(width[2]) << productList[index].price() << endl;
			setColor(0, 7);
		}
		cout << endl;
		for (int i = 0; i < instruction.size(); i++)
			cout << instruction[i] << endl;

		char ch = _getch();
		switch (ch)
		{
		case Arrow:
			ch = _getch();
			switch (ch)
			{
			case Up:
				if (coloredLine == 1) coloredLine = numberProductDisplay;
				else coloredLine -= 1;
				break;
			case Down:
				if (coloredLine == numberProductDisplay) coloredLine = 1;
				else coloredLine += 1;
				break;
			case Left:
				if (currentPage == 1) currentPage = numberOfPage;
				else currentPage -= 1;
				isPageChanged = true;
				break;
			case Right:
				if (currentPage == numberOfPage) currentPage = 1;
				else currentPage += 1;
				isPageChanged = true;
				break;
			case Delete:
				choosedProduct = coloredLine - 1 + (currentPage - 1) * _numberProductPerPage;
				return 1;
				break;
			}
			break;
		case Enter:
			choosedProduct = coloredLine - 1 + (currentPage - 1) * _numberProductPerPage;
			return 2;
			break;
		case ESC:
			return -1;
			break;
		
		}
	}
}

	
	
