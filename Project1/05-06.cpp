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

};

#define RND(Min, Max) rand() % (Max - Min + 1) + Min

/*
  ������������, �����������

a) ����� LC
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
2) �������� ����� Book
���������� ������� ������: �����, ��������, ������������,
���, ����������, �������.
������� ������ �������� - ����� Library. �������:
- ������ ���� ��������� ������;
- ������ ����, ���������� �������� �������������;
- ������ ����, ���������� ����� ��������� ����.
����������� explicit ����������� � �����������
�������-����� (��������, ��� ����������� ������ � ����� � �.�.)
*/

string AuthorArr[]
{
"����" "������", "��������", "���������", "������","������", "�������",
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
		cout << "����� - " << GetAuthor() << endl;
		cout << "�������� - " << GetName() << endl;
		cout << "������������ - " << GetIssue() << endl;
		cout << "��� ������� - " << Getyear() << endl;
		cout << "���-�� ������� - " << Getpages() << endl;
	}
	void InitRand()
	{
		//int i = rand() % SizeAuthorArr;
		//Author = AuthorArr[i];
		SetAuthor(AuthorArr[rand() % SizeAuthorArr]);
		int size = RND(5, 16);
		string temp;
		for (int i = 0; i < size; i++)
		{
			char sym = RND('A', 'Z');
			temp += sym;
		}
		SetName(temp);
		size = RND(8, 20);
		temp = " ";
		for (int i = 0; i < size; i++)
		{
			char sym = RND('A', 'Z');
			temp += sym;
		}
		SetIssue(temp);
	}
};

int main()
{




}