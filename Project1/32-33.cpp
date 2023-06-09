#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } } _;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))

/*
  Шаблоны классов. Класса Стек
*/

template <class T>
class Stack
{
private:
	T* Data;
	int Depth;
	int SP;
public:
	Stack(): Data(), Depth(), SP() {}
	Stack(int depth): Data (new T[depth]), Depth(depth), SP() {}
	//
	Stack(const Stack<T>& obj) :Stack() { *this = obj; }
	/*
	Stack(const Stack<T>& obj)
	{
		Data = new T[obj.Depth];
		SP = obj.SP;
		for (int i = 0; i < SP; i++)
		{
			Data[i] = obj.Data[i];
		}
	}
	*/
	Stack<T>& operator=(const Stack<T>& obj)
	{
		if (this == &obj) { return *this; }
		delete[] Data;
		Data = new T[obj.Depth];
		SP = obj.SP;
		for (int i = 0; i < SP; i++)
		{
			Data[i] = obj.Data[i];
		}
		return *this;

	}
	//
	~Stack() { delete[] Data; };

	int GetCount() const { return SP; }
	int GetDepth() const { return Depth; }

	bool IsEmpty() const
	{
		if (SP == 0)
			return true;
		else
			return false;
	}
	bool IsFull() const
	{
		if (SP == Depth)
			return true;
		else
			return false;
	}

	void SetDepth( int newDepth)
	{
		int minCount;
		T* mas = new T[newDepth];
		if (this-> SP < newDepth)
			minCount = this->SP;
		else
			minCount = newDepth;
		for (int i = 0; i < minCount; i++)
		{
			mas[i] = this->Data[i];
		}
		delete[] Data;
		Data = mas;
		Depth = newDepth;
		SP = minCount;

	}

	void push(T val)
	{
		if (IsFull())
		{
			cout << "Error!, Stack is Full " << endl;
			SetDepth(Depth * 1.5 + 1);
		}
			Data[SP] = val;
			SP++;
	}
	T pop()
	{
		if (IsEmpty())
		{
			cout << "Error!, Stack is Empty;" << endl;
			throw "Stack is Empty!";

		}
		SP--;
		return Data[SP];
	}
	T top() const
	{
		cout << "Error!, Stack is Empty " << endl;
		throw string("Stack is Empty!");
		return Data[SP - 1];
	}
	T& top()
	{
		if (IsEmpty())
		{
			cout << "Error!, Stack is Empty;" << endl;
			throw string ("Stack is Empty!");
		}
		return Data[SP -1];
	}

	friend ostream& operator << (ostream& os, const Stack<T>& obj)
	{
		os << "Depth = " << obj.Depth << endl;
		os << "SP = " << obj.SP << endl;
		for (int  i = 0; i < obj.SP; i++)
		{
			os << obj.Data[i] << endl;
		}
		return os;
	}

}; // class Stack<>;


int main()
{
	Stack<int> A;
	for (int i = 0; i < 10; i++)
	{
		int temp = RAND(1, 10);
		cout << temp << " ";
		A.push(temp);
	}
	cout << " \n-----------------------" << endl;
	cout << A;
	cout << "  \n----------------------" << endl;
	/*
	for (int i = 0; i < 10; i++)
	{
		int temp = A.pop();
		cout << temp << " ";
	}
	*/
	try 
	{

		while (!A.IsEmpty())
		{
			cout << A.top() << " ";
			A.pop();
		}
		A.top();
		cout << "OK" << endl;
	}
	catch (const char * message )
	{
		cout << "Exception:" << message << endl;
	}
	catch (string message)
	{
		cout << "Exception (string):" << message << endl;
	}
	cout << endl << "-----------------------" << endl;
	cout << A;
	cout << endl << "-----------------------" << endl;

}
