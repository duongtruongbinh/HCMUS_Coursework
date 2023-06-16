#include "OneSpaceRule.h"

string OneSpaceRule::Rename(string str)
{
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            str.erase(i + 1, 1);
            i--;
        }
    }
    return str;
}