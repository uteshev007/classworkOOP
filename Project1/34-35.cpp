﻿#include <iostream>
#include <fstream>
#include <string>  // STL C++ ==> class string
#include <stack>   // STL C++ ==> class stack
#include <time.h>
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } }_;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))


/*****   ОЧЕРЕДЬ        *****/


/*
Создайте класс Queue обычной очереди для работы
с целыми значениями.
Требуется создать реализации для типичных
операций над элементами:
 * IsEmpty - проверка очереди на пустоту
 * IsFull  - проверка очереди на заполнение
 * Enqueue - добавление элемента в очередь / push()
 * Dequeue - удаление элемента из очереди  / pop(), top()
 * Show - отображение всех элементов очереди на экран
        заменить на перегруженный оператор вывода << в поток
*/

template <class T>
class Queue {
private:
    T* Data; // рабочий массив очереди
    int  Size, Cnt; // максимальный размер очереди, кол-во полезных элементов
public:
    Queue() : Data(), Size(), Cnt() {}; // создать пустой объект
    Queue(int Size_) : Data(new T[Size_]), Size(Size_), Cnt(0) {}  // создать очередь заданного размера
    // Конструктор и оператор копирования, деструктор - ОБЯЗАТЕЛЬНО
        Queue(const Queue<T>& q) : Queue() { *this = q; }
    Queue<T>& operator=(const Queue<T>& q)
    {
        if (this == &q) { return *this; }
        delete[] this->Data;
        this->Data = new T[q.GetSize()];
        for (int i = 0; i < q.GetCount(); i++)
        {
            this->Data[i] = q.Data[i];
        }
        this->Size = q.GetSize();
        this->Cnt = q.GetCount();
        return *this;
    }
    ~Queue() { delete[] Data; };

    int GetCount() const { return Cnt; } // вернуть кол-во элементов в очереди
    int GetSize() const { return Size; }  // вернуть максимальный размер очереди
    bool IsEmpty() const { return Cnt == 0; }  // очередь пустая?
    bool IsFull() const { return Size == Cnt; }   // очередь полная?

    // Задать размер очереди - реализация за классом
    void SetSize(int newSize)
    {
        T* temp = new T[newSize];
        int minCnt = (newSize < Cnt) ? newSize : Cnt;
        for (int i = 0; i < minCnt; i++)
        {
            temp[i] = Data[i];
            delete[] Data;
            Data = temp;
            Size = newSize;
            Cnt = minCnt;
        }
    }

    void Clear() { Cnt = 0; } // Очистить очередь

    // постановка в очередь нового элемента - аналог метода push()
    void EnQueue(T val)
    {
        if (IsFull())
        {
            cout << "Error. Queue is full!" << endl;
            SetSize(Size * 1.5 + 1);
        }
        Data[Cnt++] = val;
    }

    // извлечение из очереди первого элемента (на обработку)
    //  с удалением из очереди аналог метода pop()
    T DeQueue()
    {
        if (IsEmpty())
        {
            cout << "Error. Queue is empty";
            throw "Queue is empty!";
        }
        T temp;
        temp = Data[0];
        for (int i = 0; i < Cnt - 1; i++)
        {
            Data[i] = Data[i] + 1;
        }
        return temp;
    }

    // возвращает первый элемент в очереди без удаления, top()
    T GetFirst() const
    {
        if (IsEmpty())
        {
            cout << "Error. Queue is empty";
            throw "Queue is empty!";
        }
        return Data[0];
    }

    // возвращает ссылку на первый элемент в очереди без удаления, top()
    T& GetFirst()
    {
        if (IsEmpty())
        {
            cout << "Error. Queue is empty";
            throw "Queue is empty!";
        }
        return Data[0];
    }

    friend ostream& operator<<(ostream& os, const Queue<T>& q)
    {
        os << "Size = " << q.GetSize() << endl;
        os << "Count = " << q.GetCount() << endl;
        for (int i = 0; i < q.GetCount(); i++)
        {
            os << q.Data[i] << endl;
        }
        return os;
    }

}; // class Queue<>


int main()
{
    Queue<int> q2(10);
    // цикл постановки в очередь
    for (int i = 0; i < 5; i++)
    {
        int temp = RAND(1, 20);
        cout << temp << " ";
        q2.EnQueue(temp);
    }
    cout << q2 << endl; // печать содержимого очереди на экран
    // цикл извлечения из очереди
    for (int i = 0; i < 5; i++)
    {
        int temp = q2.DeQueue();
        cout << temp << " ";
    }
    cout << q2 << endl; // печать содержимого очереди на экран


    /*
    Queue<string> q1( 5 );
    cout << "Input 5 strings:\n";
    for(int i = 0; i < 5; i++)
    {
      string temp;
      getline( cin, temp );
      q1.EnQueue( temp );
    }
    try {
      for(int i = 0; i < 6; i++) {
        cout << q1.DeQueue() << endl;
      }
    }
    catch(const char * err) {
      cout << "Catch: " << err << endl;
    }
    cout << q1 << endl;
    cout << endl;
    */

} // int main()




