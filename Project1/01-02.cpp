#include <iostream>
#include <string>
using namespace std;

// ********* V V E D E N I E     V     O O P   ************

// 1. INKAPSULACIYA
// 2. POLIMORFIZM
// 3. NASLEDOVANIE


/*
Задание 2
Реализуйте класс "Точка".
Необходимо хранить координаты x, y, z в переменных
- членах класса.
Реализуйте функции - члены класса для ввода данных,
вывода данных, реализуйте аксессоры для доступа
к переменным - членам, реализуйте сохранение
в файл и загрузку данных из файла
*/


class Point
{

private:
	int x, y, z;
protected:
	string Name;
public:
	void SetX(int newX)
	{
		x = newX;
	}
	void SetY(int newY)
	{
		y = newY;
	}
	void SetZ(int newZ)
	{
		if (newZ>=0)
			z = newZ;
		else
			cout << "Error: Z must be > 0 " << endl;
	}
	void SetXYZ(int newX, int newY, int newZ)
	{
		SetX(newX); // = newX;
		SetY(newY); // = newY;
		SetZ(newZ); // = newZ;
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	int GetZ()
	{
		return z;
	}
/*
	int * GetXYZ()
	{
		int* mas = new int[3];
		mas[0] = x, mas[1] = y, mas[2] = z;
		return mas;
	}
*/
	void GetXYZ(int& RetX, int& RetY, int& RetZ)
	{
		RetX = GetX();
		RetY = GetY();
		RetZ = GetZ();
	}
	void SetName(string newName)
	{
		Name = newName;
	}
	string GetName()
	{
		return Name;
	}
	void Print()
	{
		cout << Name << "(" << x << "; " << y << "; " << z << ")" << endl;
	}
	void Input()
	{
		cout << "Введите имя точки: ";
		getline(cin, Name);
		cout << "Введите x y z ";
		cin >> x >> y >> z;
		cin.ignore();
	}
};


int main()
{
	//setlocale(0, "rus");
	system("chcp 1251 > null");
	Point A;
//	A.SetX(10);	//A.x = 10;
	A.Input();
	A.Print();

	Point B;
	B.SetXYZ(10, 20, 30);
	B.Print();
	cout << "B.x = " << B.GetX() << endl;
	cout << "B.y = " << B.GetY() << endl;
	cout << "B.z = " << B.GetZ() << endl;
	B.Input();
	B.Print();
}




