#include "Store.h"

Store::Store()
{

}

void Store::input()
{
	cout << "Nhap so san pham: ";
	int n; cin >> n;
	_list.resize(n);
	for (int i = 0; i < n; i++)
	{
		
		bool isContinue = true;
		while (isContinue)
		{ 
			isContinue = false;
			cout << "====================================" << endl;
			cout << "Nhap thong tin san pham thu " << i + 1 << endl;
			_list[i].input();
			for (int j = 0; j < i; j++)
				if (_list[i].id() == _list[j].id())
				{
					cout << "Trung ID, hay nhap lai." << endl;
					isContinue = true;
				}
			
		}
		
	}
}

void Store::output()
{
	int n = _list.size();
	cout << "So san pham: " << n << endl;
	for (int i = 0; i < n; i++)
	{	
		cout << "==============================" << endl;
		cout << "Thong tin san pham thu " << i + 1 << endl;
		_list[i].output();
	}
}

double Store::totalPrice()
{
	double sum = 0;
	for (auto i : _list)
	{
		sum += i.price();
	}
	return sum;
}

void Store::outputProductFromProducer(string producerName)
{
	ofstream file("output.txt",ios::out);
	for (auto i : _list)
		if (i.producer() == producerName)
		{
			file << i.id() << "-" << i.name() << "-" << i.producer() << "-" << i.cost();
			if (i.id() != _list.back().id()) file << endl;
		}
	
	file.close();
}

void Store::sort()
{
	for(int i=0;i<_list.size()-1;i++)
		for (int j = i + 1; j < _list.size(); j++)
		{
			if (_list[i].price() < _list[j].price()) swap(_list[i], _list[j]);
			if (_list[i].price() == _list[j].price() && _list[j].producer() < _list[i].producer()) swap(_list[i], _list[j]);
		}
}