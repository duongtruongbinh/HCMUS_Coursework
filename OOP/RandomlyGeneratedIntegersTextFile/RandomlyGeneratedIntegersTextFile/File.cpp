#include "File.h"

void File::writeFile(vector<int> arr,string fileName)
{
	ofstream file(fileName, ios::out);
	for (int i = 0; i < arr.size()-1; i++)
		file << arr[i] << " ";
	file << arr[arr.size() - 1];
	file.close();
}