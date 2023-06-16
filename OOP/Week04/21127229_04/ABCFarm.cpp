#include "ABCFarm.h"
#include <sstream>

void ABCFarm::Input()
{
	double age, weight;
	bool option;
	
	do
	{
		string reader;
		cout << "Entering a cow:" << endl;
		cout << "Input age: "; getline(cin, reader);
		age = stof(reader); reader = "";
		cout << "Input weight: "; getline(cin,reader);
		weight = stof(reader); reader = "";
		cout << "Do you want to continue?(Y/N)"; getline(cin,reader);
		if (reader == "Y" || reader == "y") option = true;
		else option = false;
		this->cows.push_back(DairyCow(age,weight));
	} while (option == true);

	do
	{
		string reader;
		cout << "Entering a goat:" << endl;
		cout << "Input age: "; getline(cin, reader);
		age = stof(reader); reader = "";
		cout << "Input weight: "; getline(cin, reader);
		weight = stof(reader); reader = "";
		cout << "Do you want to continue?(Y/N)"; getline(cin, reader);
		if (reader == "Y" || reader == "y") option = true;
		else option = false;
		
		this->goats.push_back(Goat(age, weight));
	} while (option == true);
}

void ABCFarm::Output()
{
	cout << "List of dairy cows:" << endl;
	for (int i = 0; i < cows.size(); i++)
	{
		cout << "ID = " << cows[i].identifier() << endl;
		cout << "Age = " << cows[i].age() << endl;
		cout << "Weight = " << cows[i].weight() << endl << endl;
	}
	cout << "List of goats:" << endl;

	for (int i = 0; i < goats.size(); i++)
	{
		cout << "ID = " << goats[i].identifier() << endl;
		cout << "Age = " << goats[i].age() << endl;
		cout << "Weight = " << goats[i].weight() << endl << endl;
	}
	
}

void ABCFarm::OutputByAge(int min,int max)
{
	cout << "List of dairy cows:" << endl;
	for (int i = 0; i < cows.size(); i++)
		if (cows[i].age() >= min && cows[i].age() <= max) 
		{
			cout << "ID = " << cows[i].identifier() << endl;
			cout << "Age = " << cows[i].age() << endl;
			cout << "Weight = " << cows[i].weight() << endl << endl;
		}
	cout << "List of goats:" << endl;

	for (int i = 0; i < goats.size(); i++)
		if (goats[i].age() >= min && goats[i].age() <= max)
		{
			cout << "ID = " << goats[i].identifier() << endl;
			cout << "Age = " << goats[i].age() << endl;
			cout << "Weight = " << goats[i].weight() << endl << endl;
		}
}


