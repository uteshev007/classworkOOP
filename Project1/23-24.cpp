#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  Перегрузка операторов ++/--
*/

class CInt
{
private:
	int Data;


public:
	CInt() : Data() {};
	CInt& operator = (int val)
	{
		Data = val;
		return *this;
	}

	CInt operator + (const CInt& right) const
	{
		CInt res;
		res.Data = this->Data + right.Data;
		return res;
	}
	CInt & operator ++()
	{
		this->Data++;
		return *this;
	}
	CInt& operator --()
	{
		this->Data--;
		return *this;
	}
	CInt operator++(int k)
	{
		//cout << "k = " << k << endl;
		CInt oldVal;
		oldVal.Data = this->Data;
		this->Data++;
		return oldVal;
	}
	CInt operator--(int)
	{
		CInt oldVal = *this;
		this->Data--;
		return oldVal;
	}
	friend ostream& operator << (ostream& os, const CInt& obj)
	{
		return os << obj.Data;
	}

};


int main()
{
	//int a, b;
	CInt a, b;
	a = 1;
	b = a++; // постфиксный инкремент
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	a = 1;
	b = a++ + a++;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	a = 1;
	b = ++a; // префиксный инкремент
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	a = 1;
	b = ++a + ++a;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}
