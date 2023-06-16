#include <iostream>
#include <queue>
#include <ctime>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct NODE
{
    string name;
    vector<NODE *> child;
};

NODE *createNode(string data)
{
    NODE *a = new NODE;
    a->name = data;
    return a;
}

NODE *readFile()
{
    fstream file("input.txt");
    queue<NODE *> a;
    NODE *pRoot;
    NODE *temp = pRoot;
    a.push(pRoot);
    int n;
    file >> n;
    string tempString;
    getline(file, tempString);
    for (int i = 0; i < n; i++)
    {
        
        getline(file, tempString);
        stringstream ss(tempString);

        pRoot = a.front();
        getline(ss, pRoot->name, ' ');
        a.pop();
        char tempChar;
        ss >> tempChar >> tempChar;

        while (!ss.eof())
        {
            ss >> tempString;
            if (tempString[tempString.length() - 1])
                tempString = tempString.substr(0, tempString.length() - 2);
            NODE *tempNode = createNode(tempString);
            pRoot->child.push_back(tempNode);
            a.push(tempNode);
        }
    }

    file.close();
    return temp;
}

void LNR(NODE *pRoot)
{
    if (!pRoot)
        return;
    for (int i = 0; i < pRoot->child.size() / 2; i++)
        LNR(pRoot->child[i]);
    cout << pRoot->name << " ";
    for (int i = pRoot->child.size() / 2; i < pRoot->child.size(); i++)
        LNR(pRoot->child[i]);
}
int main()
{
    NODE *pRoot = readFile();
    LNR(pRoot);
    srand(time(0));

    return 0;
}