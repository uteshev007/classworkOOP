#include <iostream>
#include <string>
using namespace std;

/*
������� 1
���������� ����� "�������".
���������� ������� � ����������-������ ������:
 ���, 
 ���� ��������,
 ���������� �������, 
 �����, 
 ������, 
 �������� �������� ���������, 
 �����
 � ������ (��� ��������� ������� ���������), 
 ����� ������.

���������� �������-����� ������ ��� ����� ������, ������ ������, ���������� ��������� ��� ������� � ��������� ����������-������.*/

class Student
{
	string FIO;
	string Group;
	size_t Age;

public:
	void SetFio(string newFIO)
	{
		FIO = newFIO;
	}
	void SetGroup(string newGroup)
	{
		Group = newGroup;
	}
	void SetAge(size_t newAge)
	{
		Age = newAge;
	}

	string GetFIO()
	{
		return FIO;
	}
	string GetGroup()
	{
		return Group;
	}
	size_t GetAge()
	{
		return Age;
	}

	void Print()
	{
		cout << "FIO: " << GetFIO() << endl;
		cout << "GROUP: " << GetGroup() << endl;
		cout << "Age: " << GetAge() << endl;
	}

	void Input()
	{
		cout << "Enter FIO: ";
		string temp;
		getline(cin, temp);
		SetFio(temp);

		cout << "Enter GROUP: ";
		getline(cin, temp);
		SetGroup(temp);

		cout << "Enter AGE: ";
		size_t temp2;
		cin >> temp2;
		SetAge(temp2);
		cin.ignore();
	}
};




int main()
{
	Student st1;
	st1.Input();
	st1.Print();
}