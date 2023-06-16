#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

const int CONST_P = 23;
const unsigned long long MOD = 10e9 + 9;
const int HASH_TABLE_SIZE = 2000;

struct people
{
    string name;
    int height, weight;
};

unsigned long long pow(unsigned long long a, unsigned long long n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (n == 1)
        return a;

    unsigned long long temp = pow(a, n / 2) % MOD;

    if (n % 2)
        return ((temp * temp) % MOD * a) % MOD;
    else
        return (temp * temp) % MOD;
}

int *frequency(string s)
{
    int *a = new int[s.length()]{0};
    for (int i = 0; i < s.length(); i++)
    {

        for (int j = i - 1; j >= 0; j--)
            if (s[i] == s[j])
            {
                a[i] = a[j] + 1;
                break;
            }
    }
    return a;
}

unsigned long long hashName(people P)
{
    string s = P.name;
    int h = P.height;
    int *k = frequency(P.name);
    unsigned long long hash = 0;
    for (int i = 0; i < s.length(); i++)
    {
        unsigned long long temp = (unsigned long long)pow(CONST_P, int(sqrt(h) - i + k[i])) % MOD;
        hash += (int(s[i]) * temp) % MOD;
    }
    return hash;
}

vector<people> readFile()
{
    fstream file("people.txt");
    vector<people> a;
    while (!file.eof())
    {
        people temp;
        string tempString;
        getline(file, temp.name, '-');
        getline(file, tempString, '-');
        temp.height = stoi(tempString);
        getline(file, tempString);
        temp.weight = stoi(tempString);
        a.push_back(temp);
    }
    file.close();
    return a;
}

people *CreateHashTable(vector<people> list_people)
{
    people *a = new people[HASH_TABLE_SIZE];
    for (int i = 0; i < list_people.size(); i++)
    {
        int idx = hashName(list_people[i]) % HASH_TABLE_SIZE;
        while (!a[idx].name.empty())
            idx = (idx + 1) % HASH_TABLE_SIZE;
        a[idx] = list_people[i];
    }
    return a;
}

void Insert(people *&hash_table, people p)
{

    int idx = hashName(p) % HASH_TABLE_SIZE;
    while (!hash_table[idx].name.empty())
        idx = (idx + 1) % HASH_TABLE_SIZE;
    hash_table[idx] = p;
}

void Remove(people *&hash_table, people p)
{
}

int main()
{
    vector<people> a = readFile();
    people *arr = CreateHashTable(a);
    for (int i = 0; i < 2000; i++)
        cout << arr[i].name << endl;

    return 0;
}