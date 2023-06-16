#include "Date.h"
#include <iostream>
using namespace std;

int main()
{
	Date d1; 				// Current date: 2/11/2012
	Date d2(2012); 			// 1/1/2012;
	Date d3(2012, 8);		// 01/08/2012
	Date d4(2012, 10, 17); 	// 17/10/2012
	Date d5(d2);
	Date d6;
	d6=d3;

	d6=d3.Tomorrow();
	d5=d2.Yesterday();

	 cout<<(d6==d4);
	 cout<<(d6!=d4);
	 cout<<(d6>=d4);
	 cout<<(d6<=d4);
	 cout<<(d6>d4);
	 cout<<(d6<d4);
	 cout << endl;

	 d3=d2+1;
	 d2=d3-2;
	 d4++;
	 ++d2;
	 d5--;
	 --d6;

	 cout<<d3<<endl;
	 cin>>d4;

	cout<<(int)d3<<endl;			// from the first day of current year

	cout<<(long)d4<<endl; 		// from 1/1/1

	
	Date d7;
	
	d7+=7;
	d2-=6;

	return 0;
}