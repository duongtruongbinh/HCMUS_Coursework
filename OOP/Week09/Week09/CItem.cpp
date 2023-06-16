#include "CItem.h"

string CItem::name()
{
	return this->_name;
}

bool CItem::isHidden()
{
	return _hidden;

}

bool CItem::isReadOnly()
{
	return this->_readOnly;
}

CItem::CItem(string name) {
	this->_name = name;
}