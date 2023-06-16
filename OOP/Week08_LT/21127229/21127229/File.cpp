#include "File.h"

File::File(string fileName)
{
	this->_fileName = fileName;
}

vector<Product> File::readFile()
{
	vector<Product> data;
	ifstream file(_fileName);
	while (!file.eof())
	{
		int id, price; string name;
		string temp;
		getline(file, temp, ',');
		id = stoi(temp);
		getline(file, temp, ',');
		name = temp;
		getline(file, temp);
		price = stoi(temp);
		
		data.push_back(Product(id, name, price));

	}
	file.close();
	return data;
}

void File::writeFile(vector<Product> data)
{
	ofstream file(_fileName);
	for (int i = 0; i < data.size(); i++)
	{
		file << data[i].id() << "," << data[i].name() << "," << data[i].price();
		if (i != data.size() - 1) file << endl;
	}
	file.close();
}

string File::toString()
{
	return "File";
}