#include <iostream>
#include <fstream>
#include <string>  // STL C++ ==> class string
#include <time.h>
#include "BTree.h"  // class tree

using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

class Bus
{
private:
public:
	string Number;
	string Driver;
	int Line;
	int Seats;

	Bus() : Number()
	{
		Number += char(RAND('A', 'Z'));
		Number += char(RAND('A', 'Z'));
		Number += char(RAND('A', 'Z'));
		Number += '-';
		Number += char(RAND('0', '9'));
		Number += char(RAND('0', '9'));
		Number += char(RAND('0', '9'));

		int size = RAND(5, 8);
		for (int i = 0; i < size; i++)
		{
			Driver += char(RAND('A', 'Z'));
		}
		Line = RAND(1, 100);
		Seats = RAND(20, 120);
	}

	friend ostream& operator << (ostream& os, const Bus& obj)
	{
		os <<  obj.Number << " | "
			<< obj.Driver << " | "
			<< obj.Line << " | "
			<< obj.Seats << " | "
			<< endl;
		return os;
	}

	bool operator < (const Bus& right) 
	{
		return this->Number < right.Number;
	}

	bool operator > (const Bus& right) 
	{
		return this->Number > right.Number;
	}

	bool operator == (const Bus& right)
	{
		return this->Number == right.Number;
	}



};

int main()
{
	Tree <Bus> BusPark;
	cout << "Enter bus count: ";
	int size;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		Bus temp;
		BusPark.push(temp);
	}
	cout << "________________________\n";
	cout << "Number | Driver | Line | Seats \n";
	BusPark.Print();
}