#pragma once

class MyIntArray {
public:
	MyIntArray();
	MyIntArray(int n);
	MyIntArray(int n, int* ptr);
	MyIntArray(const MyIntArray& other);
	MyIntArray& operator=(const MyIntArray&);
	~MyIntArray();
public:
	void display();
private:
	int* _a;
	int _n;
};
