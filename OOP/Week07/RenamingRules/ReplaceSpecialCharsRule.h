#pragma once
#include <vector>
#include <string>
using namespace std;
class ReplaceSpecialCharsRule;

class ReplaceSpecialCharsRule
{
public:
    ReplaceSpecialCharsRule();

public:
    vector<string> &specialChars();
    void setReplacement(string);
    string Rename(string);

private:
    vector<string> _array;
    string _replacement;
};