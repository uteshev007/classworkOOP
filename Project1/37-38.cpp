﻿#include <iostream>
#include <iomanip>
#include <string>    // для string
#include <time.h>
#include "TList2.h"
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

// Списки
//  двусвязанный список

int main()
{
    TList< string > A("First value");
    string s = "Second value";
    A.AddHead(s);
    s = "Third value";
    A.AddTail(s);
    s = "Fourth value";
    A.Insert(s, 1);
    cout << A << endl;
    cout << endl;
    for (int i = 0; i < A.GetCnt(); i++) {
        //cout << i + 1 << ") " << A.GetAt(i) << endl;
        cout << i + 1 << ") " << A[i] << endl;
    }
}
