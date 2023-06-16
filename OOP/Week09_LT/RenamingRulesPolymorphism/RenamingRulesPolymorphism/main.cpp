#include "ParserFactory.h"
#include "AddCurrentMonthParser.h"
#include "RemoveSpecialCharsParser.h"
#include "OneSpaceOnlyParser.h"
#include "AddPrefixParser.h"
#include "ReplaceParser.h"
#include <iostream>
using namespace std;
int main() {
    ParserFactory factory;
    factory.registerWith(new RemoveSpecialCharsParser());
    factory.registerWith(new OneSpaceOnlyParser());
    factory.registerWith(new AddCurrentMonthParser());
    factory.registerWith(new AddPrefixParser());
    factory.registerWith(new ReplaceParser());

    vector<string> hrRules = {
        "RemoveSpecialChars blacklist=-_+",
        "OneSpaceOnly",
        "AddCurrentMonth",
        "AddPrefix CV",
        "Replace pattern=773423, to=devops"
    };

    vector<string> filenames = {
        "+++Cao---Minh----Long 773423.pdf",
        "Tran    Huu  Nhan 773423.pdf",
        "Do-Diem-Minh 773423.pdf",
        "CAO.TRAN.LUC 773423.pdf",
        "Hoang___Tan___Minh 773423.pdf"
    };

    vector<IRule*> rules;

    // Recreated all the rules from preset file "hrRules.txt"
    for (auto line : hrRules) { // line = "RemoveSpecialChars blacklist=-_+"
        int splitPosition = line.find_first_of(" ");
        string type = line.substr(0, splitPosition); // type = "RemoveSpecialChars"
        IParsable* parser = factory.create(type);

        // data = "blacklist=-_+"
        string data = line.substr(splitPosition + 1, line.length() - splitPosition - 1);
        IRule* rule = dynamic_cast<IRule*>(parser->parse(data));
        rules.push_back(rule);
    }

    // Apply all rename rules to each filename
    vector<string> renamedFiles;

    for (auto filename : filenames) {
        string newName = filename;

        for (auto rule : rules) {
            newName = rule->rename(newName);
            
        }

        renamedFiles.push_back(newName);
    }

    // Print out all renamed files
    for (int i = 0; i < filenames.size(); i++) {
        cout << filenames[i] << " => " << renamedFiles[i] << endl;
    }
}