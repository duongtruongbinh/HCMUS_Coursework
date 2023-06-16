#include "MenuConsole.h"

int MenuConsole::display(Menu menu)
{
	int choice = 1;
	
	bool isContinue = true;
	while (isContinue)
	{
		Console::goTo(0, 0);
		cout << menu.title() << endl;
		for (int i = 0; i < menu.option().size(); i++)
		{
			if (coloredOption == i) Console::setColor(0, 1);
			cout << setw(4) << i << ". " << menu.option()[i] << endl;
			Console::setColor(0, 7);
		}

		for (int i = 0; i < menu.instruction().size(); i++)
			cout << menu.instruction()[i] << endl;
	
		char ch = _getch();
		switch (ch)
		{
		case Arrow:
			ch = _getch();
			switch (ch)
			{
			case Up:
				if (coloredOption == 0) coloredOption = menu.option().size() - 1;
				else coloredOption--;
				break;
			case Down:
				if (coloredOption == menu.option().size() - 1) coloredOption = 0;
				else coloredOption++;
				break;
			}
			break;
		case Enter:
			return coloredOption;
			break;
		case ESC:
			isContinue = false;
			return -1;
			break;
		}
	}
	
}