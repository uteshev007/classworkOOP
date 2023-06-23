﻿#include <iostream>
#include <fstream>
#include <string>  // STL C++ ==> class string
#include <time.h>
#include "BTree.h"  // class tree

/*    **********    *********   *************** БИНАРНОЕ ДЕРЕВО ****************    ******************/

using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

int main()
{
    Tree<int> t1;
    t1.push(5);
    t1.push(1);
    t1.push(4);
    t1.push(10);
    t1.push(1);
    t1.push(11);

    t1.Print(); 
    //cout << t1 << endl;

    cout << "Vvedite chislo dla poiska: ";
    int s;
    cin >> s;
    // Поиск без сохранения узла
    if (t1.Search(s)) {
        cout << "Найдено" << endl;
    }
    else {
        cout << "Таково значения в дереве нет!" << endl;
    }

    // Поиск с извлечением узла при поиске
    Node<int>* res = t1.Search(s);
    if (res) {
        cout << "Найдено: " << res->cnt << ":" << res->Key << endl;
    }
    else {
        cout << "Таково значения в дереве нет!" << endl;
    }

    // Поиск мин/макс
    cout << "Min = " << t1.Min()->Key << endl;
    Node<int>* pMax = t1.Max();
    cout << "Max = " << pMax->Key << endl;
}
