#include <iostream>
#include <string>
#include <time.h>
#include <random>
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cout << "Good bye...\n"; system("pause"); } }_;

/*
a) #define RAND()
b) random_device, mt19937, mt19937_64
*/

// Макрофункция для генерации случ. числа в
//  диапазоне [Min, Max]
mt19937 mt;
random_device rd;
#define RND(Min, Max) rd()%(Max-Min+1)+Min
#define SIZE 20
#define SUM(a, b) (a + b)
#define MUL(a, b) (a * b)
#define PRINT_MAS(mas,size)					\
{											\
	for (size_t i = 0; i < (size); i++)		\
	{										\
		cout << (mas)[i] << " ";			\
	}										\
	cout << endl;							\
}


int main()
{
	int mas[SIZE] = { 1,2,3,4,5,6,7,8,9 };
	cout << SUM(1, 2) * 2 << endl;
	cout << MUL(2, 3) << endl;
	string s1 = "Hello";
	string s2 = "World";
	cout << SUM(s1, s2) << endl;
	PRINT_MAS(mas, SIZE);

	for (int i = 0; i < 10; i++)
	{
		cout << RND(123456, 87654321) << endl;
	}

	cout << "---------------------------------------" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << mt() << endl;
	}

}
