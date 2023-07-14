#include <iostream>
#include <fstream>  // файловые потоки
#include <sstream>  // строковый поток
#include <iomanip>  // манипуляторы
		
			// контейнеры
#include <string>
#include <vector> // std::vector<> - динамический массив
#include <array>  // std::array<> - аналог статического массива
#include <list>   // std::list<> - двусвязанный список
#include <set>    // std::set<> - бинарное дерево

#include <iterator>  // итераторы
#include <algorithm> // алгоритмические ф-ции STL

#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;



// 49-50. Виртуальные функции. Абстрактный класс // Перекрытие


/*
Задание 3
Создать базовый класс Employer (служащий) с методом Print().
Создайте три производных класса: President, Manager, Worker.
Переопределите функцию Print() для вывода информации, соответствующей каждому типу служащего.
*/

class Employer 
{
private: 
	string Type;
protected:
	string FIO;
	int Salary;
public:
	Employer() = delete;
	Employer(string type) :Type(type), Salary() {}
	Employer(string type, string fio) : Type(type), FIO(fio), Salary() {}
	virtual ~Employer() {}

	virtual string GetType() const { return Type; }
	virtual void Input()
	{
		cout << "Введите данные для " << typeid(*this).name() << endl;
		cout << "Type: ";
		getline(cin, Type);
		cout << "FIO: ";
		getline(cin, FIO);
		cout << "Salary: ";
		(cin >> Salary).ignore();
	}

	virtual void Print()
	{
		cout << "Данные для " << typeid(*this).name() << endl;
		cout << "Type: " << Type << endl;
		cout << "FIO: " << FIO << endl;
		cout << "Salary: " << Salary << endl;
	}

	friend ostream& operator << (ostream& os, const Employer& obj)
	{
		os << "Данные для " << typeid(obj).name() << endl;
		os << "Type: " << obj.Type << endl;
		os << "FIO: " << obj.FIO << endl;
		os << "Salary: " << obj.Salary << endl;
		return os;
	}

	friend istream& operator >> (istream& is, Employer& obj)
	{
		cout << "Введите данные для: " << typeid(obj).name() << endl;
		cout << "Type: ";
		getline(is, obj.Type);
		cout << "FIO: ";
		getline(is, obj.FIO);
		cout << "Salary: ";
		(is >> obj.Salary).ignore();
		return is;
	}
}; // class Employer

class President : virtual public Employer
{
private:
	//const string _type = "Президент";
	#define _type  "Президент"
protected:
	string Company;
public:
	President() : Employer(_type) {}
	President(string fio) : Employer(_type, fio) {}

	virtual void Input()
	{
		cout << "Введите данные для: " << typeid(*this).name() << endl;
		Employer::Input();
		cout << "Company: ";
		getline(cin, Company);
	}

	virtual void Print()
	{
		cout << "Данные для " << typeid(*this).name() << endl;
		Employer::Print();
		cout << "Company: " << Company << endl;
	}
	virtual ~President() override {}
};// class President

class Manager : virtual public Employer
{
private:
	//const string _type = "Менеджер";
protected:
public:
	Manager() : Employer(_type) {}
	Manager(string fio) : Employer(_type, fio) {}

	void Input()
	{
		cout << "Введите данные для: " << typeid(*this).name() << endl;
		Employer::Input();
	}

	void Print()
	{
		cout << "Данные для " << typeid(*this).name() << endl;
		Employer::Print();
	}
};// class Manager

class Worker : virtual public Employer
{
private:
	//const string _type = "Менеджер";
protected:
public:
	Worker() : Employer(_type) {}
	Worker(string fio) : Employer(_type, fio) {}

	void Input()
	{
		cout << "Введите данные для: " << typeid(*this).name() << endl;
		Employer::Input();
	}

	void Print()
	{
		cout << "Данные для " << typeid(*this).name() << endl;
		Employer::Print();
	}
};// class Worker

Employer* CreateEmployer()
{
	cout << "Выберите тип работника: \n";
	cout << "1 - President\n";
	cout << "2 - Manager\n";
	cout << "3 - Worker\n";
	cout << "0 - Exit\n";

	int choice;
	(cin >> choice).ignore();
	Employer* pEmpl = nullptr;
<<<<<<< HEAD
	switch (choice)
	{
	case 1: pEmpl = new President; break;
	case 2: pEmpl = new Manager; break;
	case 3: pEmpl = new Worker; break;
	case 0: pEmpl = nullptr; break;
	default:
		cout << "Ошибка выбора!"; break;
=======
	switch (choice)
	{
	case 1: pEmpl = new President; break;
	case 2: pEmpl = new Manager; break;
	case 3: pEmpl = new Worker; break;
	case 0: pEmpl = nullptr; break;
	default:
		cout << "Ошибка выбора!"; break;
>>>>>>> 21f57d53ba093969d333c10caac00086bdba2647
	} //switch (choice)
	return pEmpl;
} //CreateEmployer()

int main()
{
<<<<<<< HEAD
	while (true)
	{
		Employer* pEm = CreateEmployer();
		if (pEm != nullptr)
		{
			pEm->Input();
			cout << "-------------------\n";
			pEm->Print();
			cout << "-------------------\n";
			delete pEm;
		}
		else
			break;
=======
	while (true)
	{
		Employer* pEm = CreateEmployer();
		if (pEm != nullptr)
		{
			pEm->Input();
			cout << "-------------------\n";
			pEm->Print();
			cout << "-------------------\n";
			delete pEm;
		}
		else
			break;
>>>>>>> 21f57d53ba093969d333c10caac00086bdba2647
	}
	cout << "Good Bye...";
}

int oldmain()
{
	//Employer E("Директор");
	President P;
	Manager M;

	//E.Input();
	//E.Print();
	//cout << "-------------------\n";
	//P.Input();
	//P.Print();
	//cout << "-------------------\n";
	//M.Input();
	//M.Print();
	//cout << "-------------------\n";
	

	Employer* pEmpl = &M;
	pEmpl->Input();
	pEmpl->Print();
	cout << "-------------------\n";

	pEmpl = &P;
	pEmpl->Input();
	pEmpl->Print();
	cout << "-------------------\n";
	return 1;
}

