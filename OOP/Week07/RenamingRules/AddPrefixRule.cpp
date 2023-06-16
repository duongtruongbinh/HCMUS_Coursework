#include "AddPrefixRule.h"

void AddPrefixRule::setPrefix(string pre)
{
    this->_prefix = pre;
}

string AddPrefixRule::Rename(string str)
{
    str = this->_prefix + " " + str;
    return str;
}