#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cout << "Good bye...\n"; system("pause > nul"); } }_;

// ������������ ��� ��������� ����. ����� �
//  ��������� [Min, Max]
#define RND(Min,Max) ( rand()%((Max)-(Min)+1)+(Min) )


/*
  ������������, �����������

2) �������� ����� Book
���������� ������� ������:
�����, ��������, ������������,
���, ���������� �������.

������� ������ �������� - ����� Library. �������:
- ������ ���� ��������� ������;
- ������ ����, ���������� �������� �������������;
- ������ ����, ���������� ����� ��������� ����.
����������� explicit ����������� � �����������
�������-����� (��������, ��� ����������� ������
� ����� � �.�.)
*/

// ����������� ������ ������� - ������
//  ������� ��� ����. ������ � InitRand()
string AutorArr[]{
  "����",
  "��������",
  "������",
  "������",
  "�������",
  "�������",
  "�������",
};

// ���������� ����� ������������ ������� AutorArr[]
//  � ������� ��������� sizeof()
int sizeAutorArr =
sizeof(AutorArr) / sizeof(AutorArr[0]);

// ����� �����
class Book {
    string Autor;
    string Name;
    string Issue;
    int Year;
    int Pages;

public:
    void setAutor(string newAutor) { Autor = newAutor; }
    void setName(string newName) { Name = newName; }
    void setIssue(string newIssue) { Issue = newIssue; }
    void setYear(int newYear) { Year = newYear; }
    void setPages(int newPages) { Pages = newPages; }

    string getAutor() { return Autor; }
    string getName() { return Name; }
    string getIssue() { return Issue; }
    int getYear() { return Year; }
    int getPages() { return Pages; }

    Book() {
        setAutor("Unknown");
        setName("Noname");
        setIssue("");
        setYear(1648);
        setPages(0);
    }

    Book(string newAutor, string newName) {
        setAutor(newAutor);
        setName(newName);
        setIssue("");
        setYear(1648);
        setPages(0);
    }

    Book(string newAutor, string newName, int newYear,
        int newPages)
    {
        setAutor(newAutor);
        setName(newName);
        setIssue("");
        setYear(newYear);
        setPages(newPages);
    }

    void Print() {
        cout << "����� - " << getAutor() << endl;
        cout << "�������� - " << getName() << endl;
        cout << "������������ - " << getIssue() << endl;
        cout << "��� ������� - " << getYear() << endl;
        cout << "���-�� ������� - " << getPages() << endl;
    }

    // ����� ��� ���������� ������� Book ����������
    //  ����������
    void InitRand() {
        // ��������� ����� ������ �� ������ ������� AutorArr[]
        //int i = rand() % sizeAutorArr;
        //Autor = AutorArr[i];
        setAutor(AutorArr[rand() % sizeAutorArr]);

        // ���������� ������ ���������� ���������
        //int size = 5 + rand() % 12;
        int size = RND(5, 16);
        string temp;
        temp = RND('A', 'Z'); // ������ ����� ���������
        for (int i = 1; i < size; i++) {
            char symbol = RND('a', 'z');
            temp += symbol; // ����������� ������ ���������
        }
        //tolower()
        setName(temp); // ����. �������� �����

        size = RND(4, 12);
        temp = ""; // ��������� ������������� ���������� temp
        // ������� temp
        temp = RND('A', 'Z'); // ������ ����� ���������
        for (int i = 0; i < size - 1; i++) {
            temp += RND('a', 'z');
        }
        setIssue(temp); // ����. �������� ������������

        // 
        Year = RND(1638, 2023); // setYear( RND(1638, 2023) );
        Pages = RND(1, 3000);
    } // InitRand()

}; // class Book;

bool CompareBookYear(Book left, Book righ)
{
    if (left.getYear() < righ.getYear()) { return true; }
    {
        return false;
    }
}

// ��������� ������ ���������� Library
class Library
{
private:
    Book* Mas;  // ��������� �� ������������ ������ ����
    size_t Size; // ������ ������� ����
public:
    // ������������
    Library();
    Library(size_t size); // 
    Library(Book* books, size_t count);
    Library(Book book) : Library(&book, 1) {}

    // ����������� �����������
    //Library( const Library & lib );
    // set
    void SetSize(size_t newSize); // ������ ����� ������ ����������
    void SetMas(Book* newBooks, size_t newSize);
    // get
    size_t GetSize() { return Size; }
    Book* GetMas() { return Mas; }
    // �������� ������
    void Sort() // ����������
    {
        for (int i = 0; i < GetSize(); i++)
        {
            for (int j = GetSize() - 1; j > i; j--)
            {
                if (CompareBookYear(Mas[j], Mas[j-1]))
                {
                    swap(Mas[j], Mas[j - 1]);
                }
            }
        }
    }
    void SortName()
    {
        sort(Mas, Mas + Size, [](Book left, Book right)
            {
                if (left.getName() < right.getName())
                    return true;
                else
                    return false;
            });
    }
    void SortYear()
    {
        sort(Mas, Mas + Size, CompareBookYear);
    }
    // �������� ����� � ����� ����������
    void Add(Book book)
    {
        SetSize(Size + 1);
        Mas[Size - 1] = book;
    }
    // ������� ����� - �������� ����� � ��������
    //  ������� Index
    void Insert(Book book, size_t Index)
    {
        if (Index > Size)
        {
            cout << "Error";
            return;
        }
        else if (Index == Size)
        {
            Add(book);
            return;
        }
        Book* temp = new Book[Size + 1];
            for (size_t i = 0; i < Index; i++)
            {
                temp[i] = Mas[i];
            }
            for (size_t i = Index; i < Size; i++)
            {
                temp[i + 1] = Mas[i];
            }
            temp[Index] = book;
            delete[]Mas;
            Mas = temp;
            Size++;
    }
    // ������� ����� �� ������� Index
    void Delete(size_t Index)
    {
        if (Index >= Size)
        {
            cout << "Error";
            return;
        }
            Book* temp = new Book[Size - 1];
        for (size_t i = 0; i < Index; i++)
        {
            temp[i] = Mas[i];
        }
        for (size_t i = 0; i < Size - 1; i++)
        {
            temp[i] = Mas[i];
        }
        delete[]Mas;
        Mas = temp;
        Size--;
    }
    // ������� �� ���������� ��� ����� � ������� Autor
    void Delete(string Autor)
    {
        size_t index;
        //size_t index = SearchAutor(Autor);
        //if (index != -1)
        //{
        //    Delete(index);
        //}
        //else
        //    cout << "����� �� �������";
        while ((index = SearchAutor(Autor)) != -1)
            Delete(index);
    }
    // ������� �� ���������� ��� ����� � ��������� Name
    void DeleteName(string Name)
    {
        for (size_t i = Size - 1 ; i >= 0; i--)
        {
            if (Mas[i].getName() == Name)
                Delete(i);
        }
    }
    // �����
    size_t SearchName(string Name, size_t start = 0)
    {
        for (size_t i = start; i < Size; i++)
        {
            if (Mas[i].getName() == Name)
            {
                return i;
            }
        }
            return -1;
    }
    size_t SearchAutor(string Autor)
    {
        for (size_t i = 0; i < Size; i++)
        {
            if (Mas[i].getAutor() == Autor)
            {
                return i;
            }
        }
        return -1;
    }
    Book SearchYear(int Year)
    {
        for (size_t i = 0; i < Size; i++)
        {
            if (Mas[i].getYear() == Year) { return Mas[i]; }

        }
        throw "����� �� �������!";
    }

    // �������� ����� �� �������� �������
    Book GetAt(int Index)
    {
        return Mas[Index];
    }
    // �������� ����� �� �������� �������
    void SetAt(int index, Book newBook)
    {
        Mas[index] = newBook;
    }

    void Print()
    {
        for (size_t i = 0; i < Size; i++)
        {
            Mas[i].Print();
            cout << "-------------------" << endl;
        }
    }
    void InitRand()
    {
        for (size_t i = 0; i < Size; i++)
            Mas[i].InitRand();
    }

    void InitRand(size_t newsize)
    {
        SetSize(newsize);
        for (size_t i = 0; i < Size; i++)
            Mas[i].InitRand();
    }


    // ���������� - ������� ������������ ������ Mas,
    //  ����������� ������� �������
    ~Library();

}; // class Library

Library::~Library() { delete[]Mas; }
//
void Library::SetSize(size_t newSize)
{
    Book* temp = new Book[newSize];
    int MinSize = (Size < newSize) ? Size : newSize;
    //if (Size < newSize) { MinSize = Size; }
    //else                { MinSize = newSize; }
    for (size_t i = 0; i < MinSize; i++)
    {
        temp[i] = Mas[i];
    }
    //for (size_t i = 0; (i < Size) && (i < newSize); i++)
    //{
    //  temp[i] = Mas[i];
    //}
    delete[]Mas;
    Mas = temp;
    Size = newSize;
}

//
void Library::SetMas(Book* arr, size_t size)
{
    //delete[] nullptr;
    delete[] Mas; // ������� ������ ������
    Mas = new Book[size]; // ������� ����� ������
    // ������������ ������� 
    for (size_t i = 0; i < size; i++)
    {
        Mas[i] = arr[i];
    }
    Size = size; //
}

//
/*//Library::Library() : Mas(nullptr), Size(0)
Library::Library() : Mas(), Size()
{
  // nullptr - �������� ����� C++ - ������, ������ �����
  Mas  = nullptr; // ��� ����
  Size = 0;       // ������� ������
}*/
Library::Library() : Mas(), Size() {}

Library::Library(size_t newSize)
    : Mas(new Book[newSize]), Size(newSize)
{
    //Mas = new Book[newSize];
    //Size = newSize;
    //SetSize(newSize);
}

Library::Library(Book* mas, size_t size) : Library()
//: Mas(), Size()
{
    SetMas(mas, size);
}


int main()
{
    


    //Book A("autor", "name");
    //Book A(); - ������ ?
    Book A;
    A.InitRand();
    A.Print();
    cout << "---------\n";
    A.setAutor("�������");
    A.setName("���������� ���");
    A.setIssue("������");
    A.setPages(120);
    A.setYear(2020);
    A.Print();

    Library Lib;
    Lib.Add(A);
    A.InitRand();
    Lib.Insert(A, 0);
    Lib.Print();
}
