#include <iostream>
#include <iomanip>  // манипуляторы
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
Задание 1
Создайте класс Student, который будет содержать информацию о студенте.
С помощью механизма наследования, реализуйте класс Aspirant 
(аспирант - студент, который готовится к защите кандидатской работы) производный от Student.
*/

class Student
{
private:
	string Name;
protected:
	string Diplom;
	int Year;
public:
	Student() : Name(), Diplom(), Year() {}
	Student(string name) : Name(name), Diplom(), Year() {}
	Student(string name, string diplom, int year) : Name(name), Diplom(diplom), Year(year) {}

	void SetName(string name) { this->Name = name; }
	
	string GetName() const { return Name; }
	
	void Print() const
	{
		cout << "About Student: \n";
		cout << "Name :" << Name << endl;
		cout << "Diplom :" << Diplom << endl;
		cout << "Year :" << Year << endl;
	}

	friend ostream& operator << (ostream& os, const Student& obj)
	{
		os << "About Student: \n";
		os << "Name :" << obj.Name << endl;
		os << "Diplom :" << obj.Diplom << endl;
		os << "Year :" << obj.Year << endl;
		return os;
	}

	void Input()
	{
		cout << "Enter info for Student: \n";
		cout << "Name: "; getline(cin, Name);
		cout << "Diplom: "; getline(cin, Diplom);
		cout << "Year: "; cin >> Year;
		cin.ignore();
	}

	friend istream& operator >> (istream& is, Student& obj)
	{
		cout << "Enter info for Student: \n";
		cout << "Name: "; getline(is, obj.Name);
		cout << "Diplom: "; getline(is, obj.Diplom);
		cout << "Year: "; is >> obj.Year;
		return cin.ignore();
	}

}; // class Student;

class Aspirant : public Student
{

private:
	string Diser;
protected:
	int Year;
public:
	Aspirant() : Student(), Diser(), Year() {}
	Aspirant(string name) : Student(name), Diser(), Year() {}
	Aspirant(string name, string diser, int year) : Student(name), Diser(diser), Year(year) {}
	Aspirant (string name, string st_diplom, int st_year, string as_diser, int as_year) 
			: Student (name, st_diplom, st_year), Diser(as_diser), Year(as_year) {}

	void Print() const
	{
		cout << "About Aspirant: \n";
		Student::Print();
		cout << "Diser: " << Diser << endl;
		cout << "Year: " << Year << endl;
	}

	friend ostream& operator << (ostream& os, const Aspirant obj)
	{
		os << "About Aspirant: \n";
		os << (Student&)obj << endl;
		os << "Diser: " << obj.Diser << endl;
		os << "Year: " << obj.Year << endl;
		return os;
	}

	void Input()
	{
		cout << "Enter info about Aspirant: \n";
		Student::Input();
		//cin >> (Student&)(*this)
		cout << "Diser: "; getline(cin, Diser);
		cout << "Year: "; cin >> Year;
		cin.ignore();
	}

	friend istream& operator >> (istream& is, Aspirant& obj)
	{
		cout << "Enter info About Aspirant: \n";
		is >> (Student&)obj;
		cout << "Diser: "; getline(is, obj.Diser);
		cout << "Year: "; is >> obj.Year;
		return is.ignore();
	}

}; // class Aspirant

int main()
{
	Student St("Vasya", "Одновсвязные списки", 2020);
	cout << St << endl; 
	cout << "--------------------\n";
	cin >> St;
	cout << "--------------------\n";
	cout << St << endl; 
	cout << "--------------------\n";
	Aspirant As("Dima", "Наследование", 2021);
	cout << As << endl;
	cout << "--------------------\n";
	cin >> As;
	cout << "--------------------\n";
	cout << As << endl;
	cout << "--------------------\n";
	(Student&)As = St;
	cout << As << endl;
	cout << "--------------------\n";
}