#pragma once
#include "CItem.h"

class CFolder;

class CFolder : public CItem
{
public:
	CFolder(string);
	void setHidden(bool, bool);
	int size();
public:
	void add(CItem*);
	void print(bool);
	CItem* removeByName(string);
	CItem* findByName(string);
private:
	vector <CItem*> _list;
};