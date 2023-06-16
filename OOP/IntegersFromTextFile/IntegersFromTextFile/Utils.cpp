#include "Utils.h"
#include <math.h>
#include <regex>
using namespace std;

vector<int> Utils::Integer::findNumbers(const vector<int>& array, bool (Utils::Integer::* condition)(int))
{
	vector<int> result;
	for (int i = 0; i < array.size(); i++)
		if ((this->*condition)(array[i])) result.push_back(array[i]);
	return result;
}

bool Utils::Integer::isPrime(int value)
{
	for (int i = 2; i <= sqrt(value); i++)
		if (value % i == 0) return false;
	return true;
}

bool Utils::Integer::isPalindromic(int value)
{
	int temp = value;
	int palind = 0;
	while (temp > 0)
	{
		palind = palind * 10 + temp % 10;
		temp /= 10;
	}
	return palind == value;
}

bool Utils::Integer::isSquare(int value)
{
	int temp = round(sqrt(value));
	return temp * temp == value;
}

bool Utils::Integer::isPerfect(int value)
{
	int sum = 0;
	for (int i = 1; i < value; i++)
		if (value % i == 0) sum += i;
	return sum == value;
}

tuple<vector<int>,int> Utils::File::readFile(string fileName)
{
	ifstream reader(fileName, ios::in);

	string buffer;
	getline(reader, buffer);
	int count = stoi(buffer);

	vector<int> array;
	

	for (int i = 1; i <= count; i++)
	{
		getline(reader, buffer);
		if (parse(buffer))
		{
			int number = stoi(buffer);
			array.push_back(number);
		}
	}

	reader.close();	
	auto result = make_tuple(array, count);
	return result;
}

void Utils::Integer::printNumbers(const vector<int>& array)
{
	if (array.size() < 1) return;
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << " ";
}

void Utils::Integer::printArray(const vector<int>& array,string typeNumber, bool(Utils::Integer::* condition)(int))
{
	vector<int>temp;
	Utils::Integer tempInteger;

	temp = tempInteger.findNumbers(array, condition);
	
	cout << "Found " << temp.size() << " " << typeNumber;
	if (temp.size() == 0) cout << " number";
	else cout << " numbers : ";
	tempInteger.printNumbers(temp);
	cout << endl;
}

int Utils::Integer::findMin(const vector<int>& array)
{
	int min = array[0];
	for (int i = 1; i < array.size(); i++)
		if (min > array[i]) min = array[i];
	return min;
}

int Utils::Integer::findMax(const vector<int>& array)
{
	int max = array[0];
	for (int i = 1; i < array.size(); i++)
		if (max < array[i]) max = array[i];
	return max;
}

int Utils::Integer::findSum(const vector<int>& array)
{
	int sum = 0;
	for (int i = 0; i < array.size(); i++)
		sum += array[i];
	return sum;
}

double Utils::Integer::findAverage(const vector<int>& array)
{
	return double(findSum(array)) / double(array.size());
}

bool Utils::File::parse(string input)
{
	bool result = true;
	regex digitPattern("\\d+");
	if (input.length() == 0) result = false;
	if (regex_match(input, digitPattern) == false) result = false;
	return result;
}

