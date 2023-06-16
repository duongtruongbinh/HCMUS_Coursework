#pragma once
#include <string>
using namespace std;
class AddPrefixRule;

class AddPrefixRule
{
public:
    void setPrefix(string);
    string Rename(string);

private:
    string _prefix;
};
