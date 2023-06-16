﻿/*
  TList2.h
*/
#pragma once
#include <iostream>
#include <algorithm> // для std::sort()
using namespace std;

/*
 Шаблонн двусвязанного списка
  class TList
*/

// Шаблон структуры узла двусязного списка
template <class T>
struct Node
{
	// Область полезных данных
	T Data;
	// область ссылок на связанные элементы
	Node<T>* pNext; // Указатель на следующий элемент
	Node<T>* pPrev; // Указатель на предыдущий элемент

	// Конструкторы для узла
	Node() : Data(), pNext(), pPrev() {}
	Node(T data) : Data(data), pNext(), pPrev() {}

	// Методы для узла
	Node<T>*  GetNext() { return pNext; }
	Node<T>*  GetPrev() { return pPrev; }
	void SetNext(Node<T>* next) { pNext = next; }
	void SetPrev(Node<T>* prev) { pPrev = prev; }
};

// Шаблон класса двусвязанного списка
template <class T>
class TList {

	Node<T>* pHead; // голова списка
	Node<T>* pTail; // хвост списка
	int       Cnt;   // кол-во элементов в списке

public:
	// Конструкторы для списка
	TList(): pHead(), pTail(), Cnt() {}

	TList(const T& Val);

	// Копирование списков
	TList(const TList<T>& V);
	TList<T>& operator=(const TList<T>& V);

	// Деструктор
	~TList();

	// Методы
	int GetCnt();
	Node<T>* GetNode(int idx);

	Node<T>* GetHead();
	Node<T>* GetTail();

	// Метод для создания нового узла
	Node<T>* NewNode(const T& data);
	// Метод для создания нового узла
	Node<T>* NewNode(const T& data, Node<T>* next, Node<T>* prev);

	// void push_back(const T& data);
	void AddTail(const T& data);

	// void push_front(const T& data);
	void AddHead(const T& data);

	void Insert(const T& data, int idx);
	void Delete(int idx);

	T  GetAt(int idx) const;
	T& GetAt(int idx);
	T  operator[](int idx) const;
	T& operator[](int idx);

	// Найти данные в списке
	// Возвращает индекс найденного узла
	//  или -1, если таких данных в списке нет
	Search(const T& data);
	Clear();
	//Sort();

	template <class T>
	friend ostream& operator<<(ostream& os, const TList<T>& obj);

}; // class TList

// Реализация шаблона перегруженного оператора вывода в поток
//  для шаблонного объекта двусвязный список TList<>
template <class T>
ostream& operator<<(ostream& os, const TList<T>& obj)
{
}

