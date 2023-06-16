#include "Company.h"

void Company::input()
{
	int numOfEmployee;
	cout << "Nhap so nhan vien: "; cin >> numOfEmployee;
	for (int i = 0; i < numOfEmployee; i++)
	{
		cout << "Nhap thong tin cho nhan vien thu " << i + 1 << endl;
		cout << "Nhan vien thuoc loai nao? (Nhap 0 => OfficeEmployee || Nhap 1 => Worker) ";
		int choice; cin >> choice;
		Employee* temp;
		if (choice == 0) temp = new OfficeEmployee;
		else temp = new Worker;
		temp->input();
		this->array.push_back(temp);
		
	}
}

void Company::output()
{
	cout << "Thong tin cua tat ca nhan vien trong cong ty" << endl;
	for (int i = 0; i < array.size(); i++)
	{
		cout << "==================================" << endl;
		cout << "Thong tin cua nhan vien thu " << i + 1 << endl;
		array[i]->output();
	}
}

void Company::outputSalary()
{
	int sum = 0;
	for (int i = 0; i < array.size(); i++)
		sum += array[i]->salary();
	cout << "Tien luong cong ty phai tra trong thang nay: " << sum << endl;
}

void Company::outputBiggestSalary()
{
	int max = 0;
	for (int i = 0; i < array.size(); i++)
		if (max < array[i]->salary()) max = array[i]->salary();
	cout << "Nhung nhan vien co tien luong cao nhat: " << endl;
	for (int i = 0; i < array.size(); i++)
		if (max == array[i]->salary()) array[i]->output();
}



Company::~Company()
{
	for (int i = 0; i < array.size(); i++)
		delete array[i];
	array.clear();

}