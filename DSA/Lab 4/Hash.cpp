#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

struct Company
{
    string name;
    string profit_tax;
    string address;
};

vector<Company> ReadCompanyList(string file_name)
{
    fstream companyFile(file_name);
    getline(companyFile, file_name);

    vector<Company> a;
    Company temp;
    while (!companyFile.eof())
    {
        getline(companyFile, temp.name, '|');
        getline(companyFile, temp.profit_tax, '|');
        getline(companyFile, temp.address);
        a.push_back(temp);
    }

    companyFile.close();
    return a;
}

unsigned long long HashString(string company_name)
{
    string s;
    if (company_name.length() > 20)
        s = company_name.substr(company_name.length() - 20, 20);
    else
        s = company_name;
    int p = 31;
    unsigned long long m = pow(10, 9) + 9;
    unsigned long long result = 0;
    int temp = 1;
    for (int i = 0; i < s.length(); i++)
    {
        temp = temp % m;
        result += (int(s[i]) * temp);
        result %= m;
        temp = temp * p;
    }
    return result % m;
}

Company *CreateHashTable(vector<Company> list_company)
{
    Company *list = new Company[2000];
    for (int i = 0; i < list_company.size(); i++)
    {
        unsigned long long idx = HashString(list_company[i].name);
        int j = 0;
        while (!list[(idx + j) % 2000].name.empty())
            ++j;
        list[(idx + j) % 2000] = list_company[i];
    }
    return list;
}

void Insert(Company *hash_table, Company company)
{
    unsigned long long idx = HashString(company.name);
    int j = 0;
    while (hash_table[(idx + j) % 2000].name.empty())
        j++;
    hash_table[(idx + j) % 2000] = company;
}

Company *Search(Company *hash_table, string company_name)
{
    unsigned long long idx = HashString(company_name) % 2000;
    if (hash_table[idx].name.empty())
        return NULL;
    Company *a = new Company;
    *a = hash_table[idx];
    return a;
}

int main()
{
    vector<Company> a;
    a = ReadCompanyList("MST.txt");
    Company *hashTable = CreateHashTable(a);
    // for (int i = 0; i < 2000; i++)
    //     cout << hashTable[i].name << endl;
    Company *b = Search(hashTable, "CONG TY TNHH XAY DUNG VINH GIA PHAT");
    if (b)
        cout << b->address;
    delete b;
    return 0;
}