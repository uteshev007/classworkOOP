#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <vector>
#include <array>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/* std::vector<> */

ostream& operator << (ostream& os, const vector<int>& obj)
{
	os << obj.size() << ": ";
	for (size_t i = 0; i < obj.size(); i++)
	{
		os << obj[i] << " ";
	}
	return os << endl;
}
int main()
{

	array<int, 10> arr1;
	vector<int> arr2;
	for (int i = 0; i < arr1.size(); i++)
	{
		arr1[i] = RAND(1, 10);
		cout << arr1[i] << " ";
	}
	cout << endl;
	arr2.resize(10);
	for (int i = 0; i < arr2.size(); i++)
	{
		arr2[i] = RAND(10, 20);
		cout << arr2[i] << " ";
	}
	cout << endl;
	arr2.clear();
	cout << "Enter size: ";
	int Size;
	cin >> Size;
	for (int i = 0; i < Size; i++)
	{
		int temp = RAND(5,12);
		arr2.push_back(temp);

	}
	for (int i = 0; i < arr2.size(); i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	vector<int> copy_arr2 = arr2;

	cout << arr2 << endl;
	cout << copy_arr2 << endl;
}
