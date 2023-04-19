#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
Реализуйте класс Дробь.
Необходимо хранить числитель и знаменатель
в качестве переменных-членов.
Реализуйте функции-члены для ввода данных
в переменные-члены, для выполнения арифметических
операций (сложение, вычитание, умножение,
деление, и т.д.).
*/


class Drob
{
private: 
	int a, b;
	string Name;
public: 
	Drob()
	{
		cout << "Сработал конструктор " << endl;
		a = 0;
		b = 1;
		Name = "Unknown";
	}
	Drob(int newA, int newB)
	{
		cout << "Сработал конструктор c 2 параметрами " << endl;
		SetA(newA);
		SetB(newB);
		SetName("Unknow");
	}
	Drob(int _A, int _B, string _Name)
	{
		cout << "Сработал конструктор c 3 параметрами " << endl;
		SetA(_A);
		SetB(_B);
		SetName(_Name);
	}
	void SetA(int newA)
	{
		a = newA;
	}
	bool SetB(int newB)
	{
		if (newB != 0)
		{
			b = newB;
			return true;
		}
		else
		{
			cout << "Error: not 0";
			return false;
		}
	}
	void SetName(string newName)
	{
		Name = newName;
	}
	void Set(int newA, int newB, string newName)
	{
		SetA(newA);
		SetB(newB);
		SetName(newName);
	}

	int GetA()
	{
		return a;
	}
	int GetB()
	{
		return b;
	}
	string GetName()
	{
		return Name;
	}
	int GetInteger()
	{
		return a / b;
	}
	double GetDecimal()
	{
		return (double)a / b;
	}
	void Print()
	{
		cout << Name << ": " << a << " / " << b << endl;
	}
	void Input()
	{
		cout << "Введите имя дроби: ";
		string temp;
		getline(cin, temp);
		SetName(temp);
		cout << "Введите числитель: ";
		int temp2;
		cin >> temp2;
		SetA(temp2);
		cout << "Введите знаменаталь: ";
		while (true)
		{
			cin >> temp2;
			if (SetB(temp2) == true)
				{
					break;
				}
			cout << "Повторите ввод: " << endl;
		}
		cin.ignore();
	}

	void SaveToFile(string FileName)
	{
		ofstream file;
		file.open(FileName);
		if (file.is_open() == true)
		{
			file << GetName() << endl;
			file << GetA() << endl;
			file << GetB() << endl;
		}
		else
		{
			cout << "Error! Cannot to open a file!" << endl;
		}
	}
	void LoadFromFile(string FileName)
	{
		ifstream file(FileName);
		if (file.is_open())
		{
			string temp;
			getline(file, temp);
			SetName(temp);
			int temp2;
			file >> temp2;
			SetA(temp2);
			file >> temp2;
			SetB(temp2);
		}
		else
		{
			cout << "Error! Cannot to open a file!" << endl;
		}
	}

	





};

string CorrectFileName(string FileName)
{
	int dot_index = -1;
	for (int i = FileName.size() - 1; i >= 0; i--)
	{
		if (FileName[i] == '.')
		{
			dot_index = i;
			break;
		}
	}
	string result;
	if (dot_index == -1)
	{
		result = FileName + ".txt";
	}
	else
	{
		string ext = FileName.substr(dot_index);
		if (ext == ".txt")
		{
			result = FileName;
		}
		else
		{

			result = FileName.substr(0, dot_index);
			result += ".txt";
		}
	}
	return result;
}

int main()
{
	system("chcp 1251 > null");
	Drob A;
	Drob B(1, 2);
	Drob C(3, 5, "Drob C");
	A.Print();
	B.Print();
	C.Print();
}

void old_main()
{
	system("chcp 1251 > null");
	Drob A;
	//A.Input();
	A.Print();
	cout << "Целая часть = " << A.GetInteger() << endl;
	cout << "Десятичная часть = " << A.GetDecimal() << endl;
	string file_name;
	cout << "Введите имя файлы: ";
	getline(cin, file_name);
	file_name = CorrectFileName(file_name);
	A.SaveToFile(file_name);
	Drob B;
	B.LoadFromFile(file_name);
	B.Print();


}