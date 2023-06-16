#pragma once
#include "Console.h"

class MenuConsole;

class MenuConsole :public Console
{
private:
	int coloredOption = 1;
public:
	int display(Menu);
};