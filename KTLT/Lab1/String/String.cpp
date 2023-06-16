#include <iostream>
#include <string>
using namespace std;
void inputString(string &s)
{
    getline(cin, s);
}
void printString(string s)
{
    cout << s << endl;
}
bool isPalindrome(string s)
{
    string temp;
    for (int i = s.length() - 1; i >= 0; i--)
        temp += s[i];
    return (temp == s);
}
int countCapital(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            count++;
    return count;
}
int countAppearence(string s, char c)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == c)
            count++;
    return count;
}
int countWord(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
        if ((s[i] >= 'A' && s[i] < 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            count++;
    return count;
}
int main()
{
    string s;  
    inputString(s);    
    cout << countWord(s);
    return 0;
}