#include "RandomIntegerGenerator.h"
#include "File.h"
using namespace std;

int main() {
	cout << "Working with randomly generated integers" << endl << endl;
	int n;
	shared_ptr<RandomIntegerGenerator> generator = RandomIntegerGenerator::instance();
	n = generator->next(5,10);
	cout << "Generating " << n << " integers: ";

	vector<int> arr;
	for (int i = 0; i < n; i++)
		arr.push_back(generator->next(10, 100));
	for (int i = 0; i < n - 1; i++)
		cout << arr[i] << ", ";
	cout << arr[n - 1];

	string fileName = "output.txt";
	cout << endl << "Writing all " << n << " integers into "<<fileName<<" file." << endl << endl;
	File file;
	file.writeFile(arr,fileName);

	cout << "Program is exiting. Press enter to quit..." ;
	cin.get();

}