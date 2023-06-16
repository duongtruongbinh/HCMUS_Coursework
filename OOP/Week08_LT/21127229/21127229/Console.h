#pragma once
#include <Windows.h>
#include <conio.h>
#include "Key.h"
#include "Color.h"
#include <iostream>
#include <iomanip>
#include "Menu.h"



class Console;
class Console
{
public:
	static void setColor(int, int);
	static void goTo(SHORT, SHORT);

};