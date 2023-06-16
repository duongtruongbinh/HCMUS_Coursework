#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct player
{
    string position, name, nation, club;
    int year;
};
int ConvertStringToInt(string s)
{
    int result = 0;
    for (int i = 0; i < s.length(); i++)
    {
        result = result * 10 + int(s[i] - '0');
    }
    return result;
}
void FindYearOfBirth(int n, const vector<player> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (n == a[i].year)
            cout << a[i].name << endl;
    }
}
void FindClub(string s, const vector<player> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (s == a[i].club)
            cout << a[i].name << endl;
    }
}
void SortbyLastNameAndYearOfBirth(vector<player> &a)
{
    for (int i = 0; i < a.size() - 1; i++)
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[i].year > a[j].year)
                swap(a[i], a[j]);
        }
    for (int i = 0; i < a.size(); i++)
        if (a[i].year == a[i + 1].year)
            if (a[i + 1].name < a[i].name)
                swap(a[i], a[i + 1]);
}
int main()
{
    ifstream players;
    vector<player> a;
    players.open("Players.txt");
    while (!players.eof())
    {
        player temp;
        string s, s1 = "";
        getline(players, s);
        int i = 0;
        while (i < s.length() && s[i] != '/')
        {
            s1 += s[i];
            i++;
        }
        temp.position = s1;
        s1 = "";
        i++;
        while (i < s.length() && s[i] != '/')
        {
            s1 += s[i];
            i++;
        }
        temp.name = s1;
        s1 = "";
        i++;
        while (i < s.length() && s[i] != '/')
        {
            s1 += s[i];
            i++;
        }
        temp.year = ConvertStringToInt(s1);
        s1 = "";
        i++;
        while (i < s.length() && s[i] != '/')
        {
            s1 += s[i];
            i++;
        }
        temp.nation = s1;
        s1 = "";
        i++;
        while (i < s.length() && s[i] != '/')
        {
            s1 += s[i];
            i++;
        }
        temp.club = s1;
        a.push_back(temp);
    }
    // FindYearOfBirth(1994, a);
    //  FindClub("Manchester United",a);
    //  for (int i = 0; i < a.size(); i++)
    //      if (a[i].club == "Manchester City" && a[i].position == "FW")
    //          cout << a[i].name << endl;
    SortbyLastNameAndYearOfBirth(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i].position << "/" << a[i].name << "/" << a[i].year << "/" << a[i].nation << "/" << a[i].club << endl;
    }
    return 0;
}