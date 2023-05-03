#include <iostream>
#include <string>
#include <time.h>

//      ************ KONSTRUKTOR KOPIROVANIYA *****************


using namespace std;
struct LC { LC() { system("color E"); system("chcp 1251 > nul"); srand(time(0)); }~LC() { system("pause > nul");} } _;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))

class Test {
private:
    int   size;
    int* mas; // ��������� �� ������������ ������
public:
    Test() : size(10), mas(new int[size]) {
        for (int i = 0; i < size; i++) {
            mas[i] = RAND(1, 10);
        }
    }

    // ����������� �����������
    // Test obj;
    // Test A(obj);  ����� ��������� � ������������ �����������
    // Test B = obj; ������� ��������� � ������������ �����������
    Test(const Test& obj)
    {
        cout << "����������� �����������\n";
        mas = new int[obj.size]; // ������� ����� ������ ��� �������� �������
        size = obj.size; // ������ ����� �� obj
        // ����������� ��������� �������
        for (int i = 0; i < size; i++) {
            mas[i] = obj.mas[i];
        }
    }

    // �������� �����������
    // Test A, obj;
    // A = obj; - ����� ��������� �����������
    // A.operator=( obj ) - ����� ��������� �����������
    Test& operator = (const Test& obj)
    {
        cout << "�������� �����������\n";
        delete[] mas; // ������� ������ ������ �������� �������
        mas = new int[obj.size]; // ������� ����� ������ ��� �������� �������
        size = obj.size; // ������ ����� �� obj
        // ����������� ��������� �������
        for (int i = 0; i < size; i++) {
            mas[i] = obj.mas[i];
        }
        // ���������� ������ �� ������� ������
        return *this;
    }

    ~Test() { delete[]mas; } // ���������� - �����������!

    void SetAt(int index, int val) { mas[index] = val; }

    void Print(string Title = "") {
        cout << Title << " : "; // ���������
        cout << mas << " : "; // ����� �������
        for (int i = 0; i < size; i++) {
            cout << mas[i] << " ";
        }
        cout << endl;
    }
}; // class Test

int main()
{
    Test A;
    A.Print("A");

    Test B(A); // �������� ����������� �����������
    B.Print("B");

    Test C = A; // �������� ����������� �����������
    C.Print("C");

    cout << "-----------\n";
    A.SetAt(1, 123);

    A.Print("A");
    B.Print("B");
    C.Print("C");

    cout << "-----------\n";
    Test D;
    D = A; // �������� �������� �����������
    //D.operator=(A); // ����� � ��� ������� �������� �����������

    A.SetAt(2, 123);

    A.Print("A");
    D.Print("D");
}
