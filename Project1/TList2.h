/*
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

	TList(const T& Val) : TList() 
	{
		AddHead(Val);
	}

	// Копирование списков
	TList(const TList<T>& V) : TList()
	{
		*this = V;
	}
	TList<T>& operator=(const TList<T>& V)
	{
		if (this == &V)
			return *this;
		Clear();
		//for (int i = 0; i < V.GetCnt; i++)
		//{
		//	AddTail(V[i]);
		//}

		Node <T>* temp = V.pHead;
		while (temp)
		{
			AddTail(temp->Data);
			temp = temp->pNext;
		}
		return *this;
	}

	// Деструктор
	~TList() { Clear(); }

	// Методы
	int GetCnt() const { return Cnt; }
	Node<T>* GetNode(int idx) const
	{
		if (idx < 0 || idx >= Cnt)
		{
			cout << "Error! Out of range of list" << endl;
			return nullptr;
		}

		Node <T>* temp = pHead;
		for (int i = 0; i < idx; i++)
		{
			temp = temp->pNext;
		}
		return temp;

	}

	Node<T>* GetHead() const { return pHead; }
	Node<T>* GetTail() const { return pTail; }

	// Метод для создания нового узла
	Node<T>* NewNode(const T& data)
	{
		Node <T>* temp = new Node <T>;
		temp->Data = data;
		temp->pNext = nullptr;
		temp->pPrev = nullptr;
		return temp;
	}
	// Метод для создания нового узла
	Node<T>* NewNode(const T& data, Node<T>* next, Node<T>* prev)
	{
		Node <T> temp = new Node <T>;
		temp->Data = data;
		temp->pNext = next;
		temp->pPrev = prev;
		return temp;
	}

	// void push_back(const T& data);
	void AddTail(const T& data)
	{
		Node <T>* temp = NewNode(data);
		temp->pPrev = pTail;
		if (pTail == nullptr)
			pHead = temp;
		else
			pTail->pNext = temp;

		Cnt++;
	}

	// void push_front(const T& data);
	void AddHead(const T& data)
	{
		Node <T>* temp = NewNode(data);
		temp->pNext = pHead;
		if (pHead == nullptr)
			pTail = temp;
		else
			pHead->pPrev = temp;
		pHead = temp;
		Cnt++;
	}

	void Insert(const T& data, int idx)
	{
		if (idx == 0)
			AddHead(data);
		else if (idx == Cnt)
			AddTail(data);
		else if (idx > 0 && idx < Cnt)
		{
			Node <T>* temp = NewNode(data);
			Node <T>* prev = GetNode(idx - 1);
			Node <T>* next = prev->pNext;
			temp->pNext = next;
			temp->pPrev = prev;
			prev->pNext = temp;
			next->pPrev = temp;
			Cnt++;
		}
		else
			cout << "Error!" << endl;
	}
	void Delete(int idx)
	{
		Node <T>* forDel = GetNode(idx);
		if (forDel == nullptr)
			return;
		Node <T>* prev = forDel->pPrev;
		Node <T>* next = forDel->pNext;
		if (prev)
			prev->pNext = next;
		else
			pHead = next;
		if (next)
			next->pPrev = prev;
		else
			pTail = prev;
		delete forDel;
		Cnt--;
	}

	T  GetAt(int idx) const
	{
		Node <T>* temp = GetNode(idx);
		if (temp == nullptr)
		{
			cout << "Error. Out of range of list" << endl;
			throw exception("Out of range of list");
		}
		return temp->Data;
	}
	T& GetAt(int idx)
	{
		Node <T>* temp = GetNode(idx);
		if (temp == nullptr)
		{
			cout << "Error. Out of range of list" << endl;
			throw exception("Out of range of list");
		}
		return temp->Data;
	}
	void SetAt(int idx, T data)
	{
		Node <T>* temp = GetNode(idx);
		if (temp == nullptr)
			cout << "Error. Out of range of list" << endl;
		else
			temp->Data = data;
	}
	T  operator[](int idx) const { return GetAt(idx); }
	T& operator[](int idx) { return GetAt(idx); }

	// Найти данные в списке
	// Возвращает индекс найденного узла
	//  или -1, если таких данных в списке нет
	int Search(const T& data)
	{
		Node <T>* temp = pHead;
		int idx = 0;
		while (temp)
		{
			if (temp->Data == data)
				return idx;
			temp = temp->pNext;
			idx++;
		}
		return -1;
	}
	void Clear()
	{
		while (pHead)
			Delete(0);
	}
	void Sort()
	{
		T* mas = new T[Cnt];
		Node <T>* temp = pHead;
		for (int i = 0; i < Cnt; i++)
		{
			mas[i] = temp->Data;
			temp = temp->pNext;
		}
		sort(mas, mas + Cnt);
		temp = pHead;
		for (int i = 0; i < Cnt; i++)
		{
			temp->Data = mas[i];
			temp = temp->pNext;
		}
	}

	friend ostream& operator<<(ostream& os, const TList<T>& obj)
	{
		os << "Cout = " << obj.Cnt << endl;
		for (int i = 0; i < obj.Cnt; i++)
		{
			os << obj[i] << endl;
		}
		return os;
	}

}; // class TList

// Реализация шаблона перегруженного оператора вывода в поток
//  для шаблонного объекта двусвязный список TList<>


