#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Examinee
{
    string id;
    float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
        social_science, foreign_language;
};
Examinee readExaminee(string line_info)
{
    fstream data("data.txt");
    Examinee temp;
    string s;
    temp.id = line_info.substr(0, 9);

    s = "";
    int i = 11;
    while (i < line_info.length() && line_info[i] != ',')
        s += line_info[i++];
    temp.math = atof(s.c_str());

    s = "";
    i++;
    while (i < line_info.length() && line_info[i] != ',')
        s += line_info[i++];
    temp.literature = atof(s.c_str());

    s = "";
    i++;
    while (i < line_info.length() && line_info[i] != ',')
        s += line_info[i++];
    temp.physic = atof(s.c_str());

    s = "";
    i++;
    while (i < line_info.length() && line_info[i] != ',')
        s += line_info[i++];
    temp.physic = atof(s.c_str());

    s = "";
    i++;
    while (i < line_info.length() && line_info[i] != ',')
        s += line_info[i++];
    temp.chemistry = atof(s.c_str());

    s = "";
    i++;
    while (i < line_info.length() && line_info[i] != ',')
        s += line_info[i++];
    temp.biology = atof(s.c_str());

    s = "";
    i++;
    while (i < line_info.length() && line_info[i] != ',')
        s += line_info[i++];
    temp.history = atof(s.c_str());

    s = "";
    i++;
    while (i < line_info.length() && line_info[i] != ',')
        s += line_info[i++];
    temp.geography = atof(s.c_str());

    s = "";
    i++;
    while (i < line_info.length() && line_info[i] != ',')
        s += line_info[i++];
    temp.civic_education = atof(s.c_str());

    i += 2;
    temp.natural_science = temp.physic + temp.biology + temp.chemistry;
    temp.social_science = temp.geography + temp.history + temp.civic_education;

    s = "";

    while (i < line_info.length() && line_info[i] != ',')
        s += line_info[i++];
    temp.foreign_language = atof(s.c_str());

    data.close();
    return temp;
}

vector<Examinee> readExamineeList(string file_name)
{
    fstream file(file_name);
    vector<Examinee> a;
    string temp;
    getline(file, temp);
    while (!file.eof())
    {

        getline(file, temp);
        a.push_back(readExaminee(temp));
    }

    file.close();
    return a;
}

void writeTotal(vector<Examinee> examinee_list, string out_file_name)
{
    fstream out(out_file_name);
    for (int i = 0; i < examinee_list.size(); i++)
    {
        out << examinee_list[i].id << " " << examinee_list[i].math + examinee_list[i].literature + examinee_list[i].social_science + examinee_list[i].natural_science + examinee_list[i].foreign_language;
        out << endl;
    }
    out.close();
}
int main()
{
    vector<Examinee> a = readExamineeList("data.txt");
    writeTotal(a, "out.txt");

    return 0;
}