#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string word, temp_string;    
    int count = 0;
    getline(cin, word);
    ifstream input2;
    input2.open("input2.txt");
    ofstream output2;
    output2.open("output2.txt");
    while (!input2.eof())
    {
        getline(input2, temp_string);
        int found = temp_string.find(word);
        while (found < temp_string.length())
        {
            if (found != -1)
                count++;
            else
                break;
            found = temp_string.find(word, found + 1);
        }
    }
    output2 << count;
    input2.close();
    output2.close();
    return 0;
}