#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

//********** ПРИМЕР РАБОТЫ С УКАЗАТЕЛЯМИ ***************

int sum1(int arr[], int size)
{
	int sum = 0;
	int* p1 = arr, * p2 = &arr[size - 1];
	for (int i = 0; i < size/2; i++)
	{
		sum += *p1;
		sum += *p2;
		p1++;
		p2--;
	}
		if (p1 == p2)
			sum += *p1;
		return sum;
}
int sum2(int arr[], int size)
{
	int sum = 0;
	int* p1 = arr, * p2 = &arr[size - 1];
	while (p1<p2)
	{
		sum += *p1;
		sum += *p2;
		p1++;
		p2--;
	}
	if (p1 == p2)
		sum += *p1;
	return sum;
}

int main()
{
	int n;
	cout << "Enter size: ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = RAND(1, 9);
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Summ of array by for: " << sum1(arr, n) << endl;
	cout << "Summ of array by while: " << sum2(arr, n) << endl;
}