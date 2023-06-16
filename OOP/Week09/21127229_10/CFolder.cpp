#include "CFolder.h"
#include <iostream>
using namespace std;
CFolder::CFolder(string name):CItem(name)
{
	
}

void CFolder::add(CItem* item)
{
	this->_list.push_back(item);
}

int CFolder::size()
{
	int size = 0;
	for (int i = 0; i < _list.size(); i++)
		size += _list[i]->size();
	return size;
}
void CFolder::print(bool isPrintHidden)
{
	if (!(isPrintHidden || _hidden == false))	return;
	cout << "Folder: " << this->name() << endl;
	for (int i = 0; i < this->_list.size(); i++)
	{		
		_list[i]->print(isPrintHidden);
	}
}
CItem* CFolder::findByName(string name)
{
	if (name == _name) return this;
	CItem* result = nullptr;
	for (auto item: _list)
	{
		result = item->findByName(name);
		if (result != nullptr) break;
	}
	return result;
}

CItem* CFolder::removeByName(string name)
{
	CItem* result = nullptr;
	for (int i = 0; i < _list.size(); i++)
	{		
		if (_list[i]->name() == name)
		{
			result = _list[i];
			_list.erase(_list.begin() + i);
			break;
		}
	}
	return result;
}

void CFolder::setHidden(bool isHidden, bool isApplyToChild=false)
{
	_hidden = isHidden;
	if (isApplyToChild)
		for (auto item : _list)
			item->setHidden(isHidden, isApplyToChild);
}