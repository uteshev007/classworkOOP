﻿#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>  // std::stack<>
#include <time.h>
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } } _;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))

/*****   ОЧЕРЕДЬ        *****/

int RSum(int* mas, int sz)
{
	if (sz == 0) return 0;
	//return mas[sz - 1] + RSum(mas, sz - 1);
	int sum =  mas[sz - 1] + RSum(mas, sz - 1);
	return sum;
}

int main()
{
	int mas[] = { 1,2,3,4,5,6,7 };
	char str[] = "Hello World";
	double mas2[] = { 4.5, 78.65, 64.45, 77.4, 546.56 };
	int* arr = new int [5] {10, 20, 30, 40, 50};
	int size = sizeof(mas) / sizeof(mas[0]);
	int sum = RSum(mas, size);
	cout << "Summas = " << sum << endl;
	int proizv = 1;
	for (int i = 0; i < size; i++)
	{
		proizv *= mas[i];
	}
		cout << "P = " << proizv;
}