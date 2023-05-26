#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

//********** УКАЗАТЕЛИ ***************
void Power4(int a, int& a2, int& a3, int& a4);
int Power4(int a, int& a3, int& a4);
void Power4(int a, int res[3]);

int main()
{
	int data;
	cout << "Enter value: ";
	cin >> data;
	int d2, d3, d4;
	Power4(data, d2, d3, d4);
	cout << "-------------1--------------------" << endl;
	cout << data << "**2 = " << d2 << endl;
	cout << data << "**3 = " << d3 << endl;
	cout << data << "**4 = " << d4 << endl;
	cout << "--------------2-------------------" << endl;
	int t2, t3, t4;
	t2 = Power4(data, t3, t4);
	cout << data << "**2 = " << t2 << endl;
	cout << data << "**3 = " << t3 << endl;
	cout << data << "**4 = " << t4 << endl;
	cout << "------------3 Массив---------------------" << endl;
	int mas[5];
	Power4(data, mas);
	cout << data << "**2 = " << mas[0] << endl;
	cout << data << "**3 = " << mas[1] << endl;
	cout << data << "**4 = " << mas[2] << endl;

}

void Power4(int a, int &a2, int &a3, int &a4)
{
	a2 = a * a;
	a3 = a * a * a;
	a4 = a * a * a * a;
}

int Power4(int a, int& a3, int& a4)
{
	int a2 = a * a;
	a3 = a * a * a;
	a4 = a * a * a * a;
	return a2;
}

void Power4(int a, int res[3])
{
	res[0] = a * a;
	res[1] = a * a * a;
	res[2] = a * a * a * a;
}