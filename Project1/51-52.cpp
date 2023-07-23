﻿

/*
Задание 1
Создать базовый класс с функцией - площадь.
Создать производные классы: прямоугольник, круг, прямоугольный треугольник, трапеция со своими функциями площади.
Для проверки определить массив ссылок на класс, которым присваиваются адреса различных объектов.

*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>  // файловые потоки
#include <iomanip>  // манипуляторы
#include <string>
#include <algorithm> // алгоритмические ф-ции STL
#include <math.h>
#include <time.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  Наследование.Множественное наследование

  Задание 3
Создать базовый класс с функцией - площадь.
Создать производные классы: прямоугольник, круг,
прямоугольный треугольник, трапеция со своими
функциями площади.
Для проверки определить массив ссылок на класс,
которым присваиваются адреса различных объектов.
*/

class Shape
{
private:
    string Type; // тип фигуры
protected:
    float S; // площадь фигуры
public:
    Shape() = delete; // Shape():S(){}
    Shape(string type) :Type(type), S() {}
    string GetType()const { return Type; }
    // сеттер для Type - запрещен
    virtual float GetS()const { return S; }
    // сеттер для S - ?
    virtual void Print()const {
        cout << typeid(*this).name() << endl;
        cout << "S = " << S << endl;
    }
    virtual void Input() {
        cout << typeid(*this).name();
        cout << " - This method is not released!\n";
    }
    virtual float GetSquare() { return S; }
    virtual ~Shape() {}

}; // class Shape;

// дочерний класс от базового Shape
class Rect : public Shape
{ // + тело class Shape (S)
private:
protected:
    float a, b; // стороны прямоугольника
public:
    Rect() : Shape("Прямоугольник"), a(), b() {}
    Rect(float a, float b)
        : Shape("Прямоугольник"), a(a), b(b) {}
    // вычисление площади фигуры
    virtual float GetSquare() override {
        S = a * b;
        return S;
    }
    virtual void Print() const override {
        Shape::Print(); // cout << S <<endl;
        cout << typeid(*this).name() << endl; // class Rect
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
    virtual void Input() override {
        cout << typeid(*this).name() << endl; // class Rect
        cout << "Enter a, b: ";
        (cin >> a >> b).ignore();
    }
}; // class Rect;

class Circle : public Shape
{
private:
protected:
    float R; // радиус круга
public:
    Circle() : Shape("Окружность"), R() {}
    //Circle(float r) : Shape("Круг"), R(r) {}
    Circle(float r) : Circle() {
        R = r;
    }
    virtual void Print() const override{
        Shape::Print(); // cout << S <<endl;
        cout << typeid(*this).name() << endl; // class Rect
        cout << "R = " << R << endl;
    }
    virtual void Input() override {
        cout << typeid(*this).name() << endl; // class Rect
        cout << "Enter R: ";
        (cin >> R).ignore();
    }
    virtual float GetSquare() override {
        S = M_PI * R * R; // площадь круга
        return S;
    }
    virtual ~Circle () override {}
}; // class Circle;

Shape* CreateShape(int type)
{
    switch (type)
    {
    case 1: return new Rect;
    case 2: return new Circle;
    //case 3: return new Triangle;
    return nullptr;

    }
}

int main()
{
    bool isExit = false;
    while (!isExit) // while (isExit == false)
    {
        cout << "-----------------------\n";
        // пользовательское меню
        cout << "Выберите фигуру:\n"
            << "1 - Прямоугольник\n"
            << "2 - Круг\n"
            << "3 - Квадрат\n"
            << "4 - Треугольник\n"
            << "0 - Выход\n";
        int choice;
        (cin >> choice).ignore();
        if (choice == 0) { break; }
        Shape* pShape = CreateShape(choice);
        if (pShape)
        {
            pShape->Input();
            pShape->GetSquare();
            pShape->Print();
            cout << "___________________";
            delete pShape;
        }
        else
            cout << "Error \n";
    } // while(true)
    cout << "Good bye...\n";
}
