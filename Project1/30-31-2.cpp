#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <vector>
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
int sizeAutorArr = sizeof(AutorArr) / sizeof(AutorArr[0]);

// ����� �����
class Book {
private:
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

    string getAutor() const { return Autor; }
    string getName()  const { return Name; }
    string getIssue() const { return Issue; }
    int    getYear()  const { return Year; }
    int    getPages() const { return Pages; }

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

    void Print() const {
        cout << "����� - " << getAutor() << endl;
        cout << "�������� - " << getName() << endl;
        cout << "������������ - " << getIssue() << endl;
        cout << "��� ������� - " << getYear() << endl;
        cout << "���-�� ������� - " << getPages() << endl;
    }

    friend ostream& operator << (ostream& os, const Book& book)
    {
         os << left
            << setw(8) <<book.getAutor() << " | "
            << setw(16) << book.getName() << " | "
            << right
            << setw(4) << book.getYear() << " | "
            << setw(5) <<book.getPages() << " | "
            << left
            << setw(12) <<book.getIssue() <<" | ";
        return os << right;
    }

   bool operator < (const Book& right)
    {
       if (this->getName() < right.getName())
           return true;
       return false;
       // return (this->getName() < right.getName());
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
istream& operator >> (istream& is, Book& obj)
{
    return is;
}
istream& operator >> (istream& is, vector<Book>& obj)
{
    cout << "Enter size: ";
    size_t cnt;
    (cin >> cnt).ignore();
    obj.resize(cnt);
    for (size_t i = 0; i < obj.size(); i++)
    {
        obj[i].InitRand();
    }
    return is;
}

ostream& operator << (ostream& os, const vector<Book>& obj)
{
    //os << " Count: " << obj.size() << " books \n";
    os << "| " 
       << setw(3)   << "N"        << " | " 
       << setw(8)   << "Author"   << " | " 
       << setw(16)  << "Name"     << " | " 
       << setw(4)   << "Year"     << " | " 
       << setw(5)   << "Pages"    << " | " 
       << setw(12)  << "Issue"    << " | " << endl;
    for (size_t i = 0; i < obj.size(); i++)
    {
        os << "| " << setw(3) << i + 1 << " | " << obj[i] << endl;
    }
    return os;
}

int main()
{
    vector<Book> lib1;

    cin >> lib1;
    cout << lib1;
    sort(begin(lib1), end(lib1));
    cout << "-----------------\n";
    cout << lib1;
}
