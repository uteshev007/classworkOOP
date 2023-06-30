#include <iostream>
#include <iomanip>  // манипуляторы
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  Наследование
*/

class Person
{
private:
	string Name;
protected:
	int Age;
public:
	Person() : Name("Vasya"), Age(20) {}
	bool operator == (const Person& right)
	{
		return this->Name = right.Name;
	}
};

class Student : public Person
{
private:
	string Name;
protected:
	string Spec;
public:
	Student()
	{
		Age = 22;
		Person::Age = 22;
	}

	void SetName(string newName)
	{
		Person::SetName(newName);
		SetName(newName);
	}
};

int main()
{
	Student B;
	B.SetName("Tanya");
}
