#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;




//////////  ШАБЛОНЫ КЛАССОВ //////////////////

template<typename T>

T Sum(T a, T b)
{
	T Result = a + b;
	return Result;
}



/*
Задание №1
Написать шаблон функции для поиска среднего арифметического значений массива.
*/

// double Average(long long* mas, size_t size);

template <class T>
double Average(T* mas, size_t size)
{
	T Sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		Sum += mas[i];
	}
	double aver = double(Sum) / double(size);
	return aver;
}

int main()
{
	int t1 = 1, t2 = 2;
	cout << "Sum(1,2) = " << Sum(t1, t2) << endl;
	string s1 = "Hello ", s2 = "World!";
	cout << "Sum(string) = " << Sum(s1, s2) << endl;
	cout << "Sum int (1,2.2) = " << Sum <int> (1, 2.2) << endl;
	cout << "Sum float (1,2.2) = " << Sum <float> (1, 2.2) << endl;
	cout << "-----ШАБЛОННЫЕ ФУНКЦИИ-----" << endl;

#define SIZE 10
	int mas[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		//mas[i] = RAND(1, 10);
		//cout << mas[i] << " ";
		cout << ( mas[i] = RAND(1, 10) ) << " ";
	}
	cout << endl;
	cout << "Average = " << Average(mas, SIZE) << endl;

	float mas2[SIZE];
	{
		for (size_t i = 0; i < SIZE; i++)
		{
			mas2[i] = RAND(100, 1000) / 100.0f;
			cout << mas[i] << " ";
		}
		cout << endl;
		cout << "Average = " << Average(mas2, SIZE) << endl;
		5.f;
	}

}