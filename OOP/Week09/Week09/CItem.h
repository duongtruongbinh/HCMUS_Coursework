#pragma once
#include <string>
#include <vector>
using namespace std;
class CItem;

class CItem
{public:
	CItem(string);
	virtual void setHidden(bool,bool) = 0;
	string name();
	virtual int size() = 0;
	bool isReadOnly();
	bool isHidden();
public:
	virtual void print(bool = true) = 0;
	virtual CItem* findByName(string) = 0;
protected:
	string _name;
	bool _readOnly;
	bool _hidden;
};