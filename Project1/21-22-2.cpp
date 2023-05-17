﻿#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } } lc;

class Complex {
private:
	float real;
	float img;
public:
	Complex() : real(), img() {}
	Complex(float real, float img = 0)
	{
		this->real = real;
		this->img = img;

	}
	void SetReal(float real)
	{
		this->real = real;
	}
	void SetImg(float img)
	{
		this->img = img;
	}
	float GetReal() const { return real; }
	float GetImg() const { return img; }

	Complex operator + (const Complex& obj)
	{
		Complex res;

		res.real = this->real + obj.real;
		res.img = this->img + obj.img;
		return res;
	}

	Complex operator - (const Complex& obj)
	{
		Complex res;

		res.real = this->real - obj.real;
		res.img = this->img - obj.img;
		return res;
	}

	Complex operator * (const Complex& obj)
	{
		Complex res;

		res.real = this->real * obj.real - this->img * obj.img; 
		res.img = this->img * obj.img + this->img * obj.real;
		return res;
	}

	Complex operator / (const Complex& obj)
	{
		Complex res;
		float Module;
		Module = obj.real * obj.real + obj.img * obj.img;
		Complex temp = obj;
		temp.img = -temp.img;
		res = *this * temp;
		res.real /= Module;
		res.img /= Module;
		return res;
	}
}; // class Complex;

ostream& operator << (ostream& os, const Complex& obj)
{
	os << obj.GetReal() << " + " << obj.GetImg() << "*i";
	return os;
}
istream& operator >> (istream& is, Complex& obj)
{
	float resReal;
	float resImg;
	cout << "Enter Real and Img: ";
	is >> resReal >> resImg;
	obj.SetReal(resReal);
	obj.SetImg(resImg);
	return is;
}
int main()
{
	Complex A, B, C;
	cin >> A >> B;
	C = A + B;
	cout << "A + B = " << C << endl;
	cout << "----------------------\n";
	C = A - B;
	cout << "A - B = " << C << endl;
	cout << "----------------------\n";
	C = A * B;
	cout << "A * B = " << C << endl;
	cout << "----------------------\n";
	C = A / B;
	cout << "A / B = " << C << endl;
	cout << "**********************\n";
	C = A * B;
	cout << "C / A = " << C / A << endl;
	/*
	cout << endl << endl;
	
	// пример приведения Complex к string();
	string strA = string(A);
	string str;
	// создание полного выражения через string() - ложим числа 
	// и знаки в строку
	str = string(A) + " + " + string(B) + " = " + string(A + B);
	cout << str << endl;
	*/
}
 