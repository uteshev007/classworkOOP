﻿#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  Перегрузка операторов ++/--
*/

/*
Создать класс Airplane (самолет)
С помощью перегрузки операторов реализовать:
- Проверка на равенство типов самолетов (операция ==)
- Увеличение и уменьшение пассажиров в салоне самолета
  (операции ++ и -- в префиксной форме)
- Сравнение двух самолетов по максимально возможному
количеству пассажиров на борту (операция > )
*/
class Airplane {
private:
    string name;
    int MaxPassenger;
    int CurPassenger;

public:
    Airplane() : name("Boeing"), MaxPassenger(120), CurPassenger() {}
    Airplane(string name, int MaxPass, int CurPass)
        : name(name), MaxPassenger(MaxPass), CurPassenger(CurPass) {}
    Airplane& operator ++()
    {
        if (CurPassenger < MaxPassenger)
            CurPassenger++;
        else
            cout << "Error. No place" << endl;
        return *this;
    }
    Airplane operator++(int)
    {
        Airplane temp = *this;
        ++(*this);
        return temp;
    }
    Airplane& operator--()
    {
        if (CurPassenger > 0)
            CurPassenger--;
        else
            cout << "Error. Not enough passangers" << endl;
        return *this;
    }
    Airplane operator--(int)
    {
        Airplane temp = *this;
        --(*this);
        return temp;
    }
    friend ifstream& operator >> (ifstream& is, Airplane& obj)
    {

        getline(is, obj.name);
        is >> obj.MaxPassenger >> obj.CurPassenger;
        is.ignore();
        return is;
    }
    friend istream& operator >> (istream& is, Airplane& obj)
    {
        cout << "Enter Airplane name" << endl;
        getline(is, obj.name);
        cout << "Enter Maxpassenger" << endl;
        is >> obj.MaxPassenger;
        cout << "Enter Curpassenger" << endl;
        is >> obj.CurPassenger;
        is.ignore();
        return is;
    }
    friend ofstream& operator << (ofstream& os, const Airplane& obj)
    {
        os << obj.name << endl;
        os << obj.MaxPassenger << endl;
        os << obj.CurPassenger << endl;
        return os;
    }
    friend ostream& operator << (ostream& os, const Airplane& obj)
    {
        os << "Airplane name: " << obj.name << endl;
        os << "Max passengers: " << obj.MaxPassenger << endl;
        os << "Current passengers: " << obj.CurPassenger << endl;
        return os;
    }
    friend bool operator ==(const Airplane& left, const Airplane right)
    {
        if (left.name == right.name)
            return true;
        else
            return false;
        return (left.name == right.name);
    }
    bool operator > (const Airplane& right) const
    {
        //if (this->MaxPassenger > right.MaxPassenger)
        //    return true;
        //else
        //    return false;
        return(this->MaxPassenger > right.MaxPassenger);
    }

    Airplane& operator += (int addPass)
    {
        if (MaxPassenger + addPass <= MaxPassenger)
            CurPassenger += addPass;
        else
            cout << "Error. No place." << endl;
        return *this;
    }
    Airplane& operator -= (int delPass)
    {
        if (MaxPassenger - delPass > 0)
            CurPassenger -= delPass;
        else
            cout << "Error. No passengers." << endl;
        return *this;
    }
};


int main()
{
    Airplane A("Boeing", 320, 320);
    Airplane B;
    cin >> B;
    cout << "---------------" << endl;
    cout << A << endl << B << endl;
    cout << "А равен ли Б? " << (A == B) << endl;
    cout << "---------------" << endl;
    cout << "А больше ли Б? " << boolalpha << (A > B) << endl;
    A++;
    B--;
    A -= 10;
    B += 50;
    cout << "---------------" << endl;
    cout << A;
    cout << "---------------" << endl;
    cout << B;
    //Создать файл ofstream
    ofstream file("File.txt");
    if (file.is_open()) {
        file << A << endl;
        file << B << endl;
        file.close();
    }
    ifstream file2("file2.txt");
    if (file.is_open())
    {
        Airplane temp;
        file2 >> temp;
        cout << "----------------------------" << endl;
        cout << temp << endl;
        file2.close();
    }

}

