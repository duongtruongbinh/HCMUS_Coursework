#pragma once
#include "Object.h"
#include <vector>
#include <string>
using namespace std;

class Menu;

class Menu:public Object
{
public:
	Menu(string, vector<string>, vector<string>);
	
public:
	string toString();
	string title();
	vector<string> option();
	vector<string> instruction();
private:
	string _title;
	vector<string> _option;
	vector<string> _instruction;
};