#pragma once

class ColorPixel
{
public:
	ColorPixel();
	ColorPixel(int);
	ColorPixel(int, int);
	ColorPixel(int, int, int);
	ColorPixel(const ColorPixel&);
	ColorPixel& operator=(const ColorPixel&);
	~ColorPixel();
public:
	bool isValidColor(int, int, int);
	void display();
private:
	int _red;
	int _green;
	int _blue;
};
