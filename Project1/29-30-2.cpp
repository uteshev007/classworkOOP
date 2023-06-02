#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


template <class T>
class Vector {
	T * Data;
	int Size;
public:
	Vector() : Data(), Size() {}
	Vector(const Vector<T>& V)
	{
		this->Data = new T[V.Size];
		this->Size = V.Size;
		for (int i = 0; i < V.Size; i++)
			this->Data[i] = V.Data[i];
	}
	~Vector() { delete[]this->Data; }

	// Установка размера массива
	void SetSize(int size);

	// Установка данных массива из Arr[]
	void SetData(const T* arr, int size);

	// A = B = C;  *this = B;
	Vector<T>& operator=(const Vector<T>& B)
	{
		if (this == &B)
		{
			cout << "Error. Selfcopy  \n";
			return *this;
		}
		/*
		delete[] this->Data;
		this->Data = new T[B.Size];
		for (int i = 0; i < Size; i++)
			this->Data[i] = B.Data[i];
		this->Size = B.Size;
		*/

		SetData(B.Data, B.Size);
		return *this;
	}

	// A + B ==> *this + B
	//operator+(Vector<>& B)

	// перегруженный оператор вывода
	friend ostream& operator << (ostream& os, const Vector<T>& vec)
	{
		os << "[" << vec.Size << "]: ";
		for (int i = 0; i < vec.Size; i++)
		{
			os << vec.Data[i] << " ";
		}
		return os << endl;
	}

	// перегруженный оператор ввода
	friend istream& operator>>(istream& is, Vector<T>& vec)
	{
		cout << "Enter Size of array: ";
		int temp;
		is >> temp;
		vec.SetSize(temp);
		for (int i = 0; i < vec.Size; i++)
		{
			cout << i + 1 << "->";
			is >> vec.Data[i];
		}
		return is;
	}

	// t = V[index] ==>  *this = &V
	// t = V.operator[]( index );
	// V[i] = t;
	// int  = int(t);
	T operator[](int index) const { return Data[index]; }
	T & operator[](int index) { return Data[index]; }
	int getSize() const { return Size; }
	const T* getData() const  { return Data; }

	//
	// Vector V; V()

	T operator()() const
	{
		T Summa = 0;
		for (int i = 0; i < Size; i++)
			Summa += Data[i];
		return Summa;
	}
	// Нахождение мин/макс значений
	// int vMin, vMax;
	// V(vMin, vMax);

	// Инициализация Vector случ. числами
	// Vector V; V(15) ==> V(15, 0, 10);
	//  V(15, -10);
	void operator()(T min, T max)
	{
		for (int i = 0; i < this->Size; i++)
		{
			this->Data[i] = RAND(min, max);
		}
	}

}; // class Vector;

// Установка размера массива
template <class T>
void Vector<T>::SetSize(int newSize)
{
	T* temp = new T[newSize];
		int MinSize = (Size < newSize) ? Size : newSize;
	for (int i = 0; i < MinSize; i++)
		temp[i] = this->Data[i];
	delete this->Data;
	this->Data = temp;
	this->Size = newSize;
}

// Установка данных массива из Arr[]
template <class T>
void Vector <T>::SetData(const T* arr, int size)
{
	delete[] this->Data;
	this->Data = new T[size];
	for (int i = 0; i < size; i++)
		this->Data = arr[i];
	this->Size = size;
}

int main()
{
	Vector <string> A;
	cin >> A;
	cin.ignore();
	cout << A << endl;
	A.SetSize(A.getSize() + 2);
	cout << "Enter 2 string: \n";
	for (int i = 2; i > 0; i--)
	{
		string temp;
		getline(cin, temp);
		A[A.getSize() - i] = temp;
		cout << A << endl;
		//cin >> A[A.getSize() - i];
	}

}

// перегруженный оператор вывода

int main_int()
{
	Vector<int> A;
	Vector <string> B;
	A.SetSize(5);
	cin >> A;
	cout << A;
	//A.getSize();
	const int* temp = A.getData();
	for (int i = 0; i < A.getSize(); i++)
	{
		cout << temp[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < A.getSize(); i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "---------------\n";

	Vector<int> A2 = A;
	cout << A2;
	A2.SetSize(12);
	A2(-5,8);
	cout << "A2 = " << A2 << endl;
	int Summa = A2();
	cout << "Summa = " << Summa << endl;
	return 0;
}

