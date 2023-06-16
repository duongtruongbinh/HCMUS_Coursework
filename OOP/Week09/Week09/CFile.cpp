#include "CFile.h"

CFile::CFile(string name, int size) :CItem(name)
{
	this->_size = size;
	this->_hidden = false;
	this->_readOnly = false;
}
int CFile::size()
{
	return this->_size;
}

void CFile::print(bool isPrintHidden = true)
{
	if (isPrintHidden || _hidden == false)	cout << "File Name: " << this->_name << " Size: " << this->_size << endl;
	
}

CItem* CFile::findByName(string name)
{
	if (name == _name) return this;
	else return nullptr;
}

void CFile::setHidden(bool isHidden, bool isApplyChild = false)
{
	_hidden = isHidden;
}