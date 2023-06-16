#pragma once

class Animal {
	
public:
	Animal();
	Animal(double, double);
	Animal(const Animal&);
	Animal& operator=(const Animal&);
	~Animal();
public:
	double weight()const;
	void setWeight(double);
	double age()const;
	void setAge(double);
	int identifier()const;
	void setIdentifier(int);
	virtual void ToString();
	bool isValidAge(double);
	bool isValidWeight(double);

protected:
	inline static int _count = 0;
	//thay dung c++20 giup em a
	int _identifier = 0;
	double _weight;
	double _age;
	
};