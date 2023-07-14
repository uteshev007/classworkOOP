#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Direct
{
	Left, Right, Up, Down, MAX_Dir
};

class Image
{
	char Sym;
	int clrFon, clrSym;
public:
};

class BasicPlayer
{
protected:
	string Name;
	int Row, Col;
	int oldRow, oldCol;
	Image Img;
	int HPLife;
	Direct Dir;



};

class Enemy : virtual BasicPlayer
{

};