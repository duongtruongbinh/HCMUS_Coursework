#pragma once
#include<vector>
#include <string>
#include <fstream>
#include <tuple>
#include <iostream>
using namespace std;


namespace Utils {
	class Integer {
	public:
		vector<int> findNumbers(const vector<int>& array, bool (Utils::Integer::* condition)(int));
		int findMin(const vector<int>& array);
		int findMax(const vector<int>& array);
		double findAverage(const vector<int>& array);
		int findSum(const vector<int>& array);
		bool isEven(int value) { return value % 2 == 0; }
		bool isOdd(int value) { return value % 2 == 1; }
		bool isPrime(int value);
		bool isPalindromic(int value);
		bool isSquare(int value);
		bool isPerfect(int value);
		void printNumbers(const vector<int>& array);
		void printArray(const vector<int>& array, string typeNumber, bool(Utils::Integer::* condition)(int));
	};
	class File {
	public:
		tuple<vector<int>,int> readFile(string fileName);
		bool parse(string input);
	};
	
		
};