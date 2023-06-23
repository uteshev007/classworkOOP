/*
  BTree.h
  template<class T>
  class Tree;
*/

/*    **********    *********   *************** БИНАРНОЕ ДЕРЕВО ****************    ******************/

#pragma once
#include <iostream>

using namespace std;

// Шаблон структуры/класса узла бинарного дерева
template<class T>
struct Node
{
    T Key;    // Полезные данные
    int cnt;  // счетчик повторений
    // Указатели на родителя, левого и правого потомков
    Node<T>* pParent;
    Node<T>* pLeft, * pRight;

    // конструкторы узла
    Node() : Key(), cnt(), pParent(), pLeft(), pRight() {}
    Node(T key, Node<T>* parent) : Key(key), cnt(), pParent(parent), pLeft(), pRight() {}
}; // struct Node<>


// Шаблон класса бинарного дерева
template<class T>
class Tree
{
    Node<T>* pRoot;    // Корень
public:
    // Конструктор по умолчанию
    Tree() : pRoot() {}

    // Конструктор принимающий массив элементов
    Tree(T* mas, size_t size) : Tree()
    {
        for (size_t i = 0; i < size; i++)
        {
            push(mas[i]);
        }
    }

    // Деструктор
    //~Tree();

    // Получить корень дерева
    Node<T>* GetRoot() { return pRoot; }

    // Добавление элемента
    void push(const T& val) // add();
    {
        Node <T>* temp = pRoot;
        Node <T>* parent = nullptr;
        while (temp)
        {
            parent = temp;
            if (temp->Key < val)
                temp = temp->pRight;
            else if (temp->Key > val)
                temp = temp->pLeft;
            else
            {
                temp->cnt++;
                return;
            }
        }
        temp = new Node <T>(val, parent);
        if (parent == nullptr)
            pRoot = temp;
        else
        {
            if (parent->Key < val)
                parent->pRight = temp;
            else if (parent->Key > val)
                parent->pLeft = temp;
        }
    }

    // Отображение всего дерева
    void Print()
    {
        Print(pRoot);
    }
    // Отображение дерева с начального узла
    void Print(Node<T>* pNode)
    {
        if (pNode == nullptr) { return; }
        Print(pNode->pLeft);
        cout << pNode->cnt << ": " << pNode->Key << endl;
        Print(pNode->pRight);
    }

    // Поиск данных в узле 
    Node<T>* Search(T key) { return Search(pRoot, key); }
    Node<T>* Search(Node<T>* pNode, const T& key)
    {
        Node<T>* temp = pNode;
        if (!temp) { return nullptr; }
        while (temp)
        {
            if (temp->Key < key)
                temp = temp->pRight;
            else if (temp->Key > key)
                temp = temp->pLeft;
            else
                return temp;
        }
        return nullptr;
    }

    // Поиск минимума
    Node<T>* Min() { return Min(pRoot); }
    Node<T>* Min(Node<T>* pNode)
    {
        Node <T>* temp = pNode;
        if (!temp)
            return nullptr;
        while (temp->pLeft)
        {
            temp = temp->pLeft;
            return temp;
        }
    }

    // Поиск максимума
    Node<T>* Max() { return Max(pRoot); }
    Node<T>* Max(Node<T>* pNode)
    {
        if (!pNode) { return nullptr; }
        if (pNode->pParent)
            return Max(pNode->pRight);
        return pNode;
    }

    // Удаление узла/ветки
    //  (nullptr удаление всего дерева)
    //void Del(Node<T>* pNode = nullptr);
    //void Del(); // удаление всего дерева

}; // class Tree<>


/*
// Конструктор принимающий массив элементов
template<class T>
Tree<T>::Tree(T * mas, size_t size)
{
}

// Добавление элемента
template<class T>
void Tree<T>::push(const T& val)
{
}

// Отображение дерева с начального узла
// Рекурсивный вариант печати всего дерева
template<class T>
void Tree<T>::Print(Node<T>* pNode)
{
}

// Отображение всего дерева
template<class T>
void Tree<T>::Print()
{
}

// Поиск данных в узле
// Search(GetRoot(), key)
template<class T>
Node<T>* Tree<T>::Search(Node<T>* pNode, const T& key)
{
}

// Поиск минимума - самый левый узел
// Вариант с циклом
template<class T>
Node<T>* Tree<T>::Min(Node<T>* pNode)
{
}

// Поиск максимума - крайний правый узел
// Рекурсивный вариант
template<class T>
Node<T>* Tree<T>::Max(Node<T>* pNode)
{
}
*/

// Удаление узла/ветки (nullptr удаление всего дерева)
//template<class T>
//void Tree<T>::Del(Node<T>* Node) {
//}


/*
// перегруженный оператор для объекта бинарное дерево Tree<T>
template<class T>
ostream& operator << (ostream& os, const Tree<T>& obj)
{
}
*/

