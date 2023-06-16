#pragma once
#include "CItem.h"
#include <iostream>
class CFile;

class CFile :public CItem
{public:
	CFile(string, int);
	int size();
	void setHidden(bool,bool);
public:
	void print(bool);
	CItem* findByName(string);
private:
	int _size;
	
};