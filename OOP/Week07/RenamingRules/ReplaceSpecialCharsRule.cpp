#include "ReplaceSpecialCharsRule.h"

ReplaceSpecialCharsRule::ReplaceSpecialCharsRule()
{
    // do nothing
}

vector<string> &ReplaceSpecialCharsRule::specialChars()
{
    return _array;
}

void ReplaceSpecialCharsRule::setReplacement(string replace)
{
    this->_replacement = replace;
}

string ReplaceSpecialCharsRule::Rename(string str)
{
    for (int i = 0; i < _array.size(); i++)
    {
        auto pos = str.find(_array[i]);

        while (pos != str.npos)
        {
            str.replace(pos, _replacement.size(), _replacement);
            pos = str.find(_array[i]);
        }
    }
    return str;
}