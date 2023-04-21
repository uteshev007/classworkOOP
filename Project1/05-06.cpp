//				*****	DESTRUKTOR		*****
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
struct LC
{
	LC()
	{
		system("chcp 1251 > nul");
		srand(time(0));
		system("color E");
	}

}_;

#define RND(Min, Max) (rand() % ((Max) - (Min) + 1) + (Min))

/*
  Конструкторы, деструкторы

a) Класс LC
b) #define RAND()
c) random_device, mt19937, mt19937_64
*/

/*
class LC
{
public: 
	LC() 
	{
		system("chcp 1251 > nul");
		srand(time(0));
		cout << "LC::LC(); \n";
		system("color E");
	}
	~LC()
	{
		cin.get(); cin.get();
		cout << "LC::~LC(); \n";
	}
}__________start;


int main()
{
	cout << "Hello, world!";
	
	
}
*/

/*
2) Создайте класс Book
Необходимо хранить данные: Автор, Название, Издательство,
Год, Количество, страниц.
Создать массив объектов - класс Library. Вывести:
- список книг заданного автора;
- список книг, выпущенных заданным издательством;
- список книг, выпущенных после заданного года.
Используйте explicit конструктор и константные
функции-члены (например, для отображения данных о книге и т.д.)
*/

string AuthorArr[]
{
"Абай", "Пушкин", "Булгаков", "Лермонтов", "Толкин","Ауезов", "Пратчет",
};
int SizeAuthorArr = sizeof(AuthorArr) / sizeof(AuthorArr[0]);


class Book
{
private:
	string Author;
	string Name;
	string Issue;
	int year;
	int pages;
public:
	void SetAuthor(string newAuthor)
	{
		Author = newAuthor;
	}
	void SetName(string newName)
	{
		Name = newName;
	}
	void SetIssue(string newIssue)
	{
		Issue = newIssue;
	}
	void Setyear(int newYear)
	{
		year = newYear;
	}
	void Setpages(int newPages)
	{
		pages = newPages;
	}

	string GetAuthor()
	{
		return Author;
	}
	string GetName()
	{
		return Name;
	}
	string GetIssue()
	{
		return Issue;
	}
	int Getyear()
	{
		return year;
	}
	int Getpages()
	{
		return pages;
	}

	Book()
	{
		SetAuthor("Unknown");
		SetName("noname");
		SetIssue("");
		Setyear(1648);
		Setpages(0);
	}
	Book(string newAuthor, string newName)
	{
		SetAuthor(newAuthor);
		SetName(newName);
		SetIssue("AlmatyKitap");
		Setyear(1648);
		Setpages(0);
	}
	Book(string newAuthor, string newName, int newYear, int newPages)
	{
		SetAuthor(newAuthor);
		SetName(newName);
		SetIssue("AlmatyKitap");
		Setyear(newYear);
		Setpages(newPages);
	}

	void Print()
	{
		cout << "Автор - " << GetAuthor() << endl;
		cout << "Название - " << GetName() << endl;
		cout << "Издательство - " << GetIssue() << endl;
		cout << "Год издания - " << Getyear() << endl;
		cout << "Кол-во страниц - " << Getpages() << endl;
	}
	void InitRand()
	{
		//int i = rand() % SizeAuthorArr;
		//Author = AuthorArr[i];
		SetAuthor(AuthorArr[rand() % SizeAuthorArr]);
		int size = RND(5, 16);
		string temp;
		temp = RND('A', 'Z');
		for (int i = 1; i < size; i++)
		{
			char sym = RND('a', 'z');
			temp += sym;
		}
		SetName(temp);
		size = RND(8, 20);
		temp = RND('A', 'Z');
		for (int i = 1; i < size; i++)
			temp += RND('a', 'z');
		SetIssue(temp);

		year = RND(1638, 2023);
		pages = RND(147, 943);
	}// InitRand
};//class Book

class Library
{
private:
	Book* Mas;
	size_t Size;
public:
	Library();
	Library(size_t size);
	Library(Book *books, size_t count);
	//Library(const Library& lib);

	void SetSize(size_t newSize)
	{

	}
	void SetMas(Book* newBooks, size_t newSize)
	{

	}
	size_t GetSize()
	{
		return Size;
	}

};


int main()
{
	Library Lib1(10);
	Book book[10];
	Library B
	Library temp = Lib1;
	
	Book A;
	A.InitRand();
	A.Print();

	cout << "---------------------" << endl;

	A.SetAuthor("Голдинг");
	A.SetName("Повелитель мух");
	A.SetIssue("Мектеп");
	A.Setyear(2003);
	A.Setpages(180);
	A.Print();


}