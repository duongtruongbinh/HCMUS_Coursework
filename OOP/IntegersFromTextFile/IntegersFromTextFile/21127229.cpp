#include "Utils.h"
#include <iostream>
using namespace std;

int main() {
	string fileName = "input.txt";
	

	cout << "Working with integer arrays from text files" << endl << endl;
	cout << "Reading data from  " << fileName << "." << endl;

	Utils::File inputFile;
	Utils::Integer tempInteger;

	tuple<vector<int>, int> result = inputFile.readFile(fileName);
	int count = get<1>(result);
	vector<int> array = get<0>(result);

	cout << "Expected to find " << count << " numbers." << endl;

	cout << "Found " << array.size() << " numbers: ";
	tempInteger.printNumbers(array);
	cout << endl;

	bool(Utils::Integer:: * condition)(int) = &Utils::Integer::isOdd;
	tempInteger.printArray(array, "odd", condition);

	condition = &Utils::Integer::isEven;
	tempInteger.printArray(array, "even", condition);
	
	condition = &Utils::Integer::isPalindromic;
	tempInteger.printArray(array, "palindromic", condition);

	condition = &Utils::Integer::isPrime;
	tempInteger.printArray(array, "prime", condition);

	condition = &Utils::Integer::isSquare;
	tempInteger.printArray(array, "square", condition);

	condition = &Utils::Integer::isPerfect;
	tempInteger.printArray(array, "perfect", condition);

	cout << "Minimum value: " << tempInteger.findMin(array)<<endl;
	cout << "Maximum value: " << tempInteger.findMax(array) << endl;
	cout << "Average value: " << tempInteger.findAverage(array) << endl;
	cout << "Sum of all numbers: " << tempInteger.findSum(array) << endl;


	cout << endl << "Program is exiting. Press enter to quit...";
	cin.get();
}