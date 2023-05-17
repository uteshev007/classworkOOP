#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

/*
  Перегрузка операторов

    CatDog = Cat + Dog
    ? = Dog + Cat

*/

// Прототипы классов

class CatDog;
class Dog;
class Cat;

class Cat
{
private:
    string name;
    int age;
    string breed;
    int life;
public:
	Cat(): name("Murka"), age(1), breed("no"), life(13) {}
    Cat(string name, int age) : Cat()
    {
        this->name = name;
        this->age = age;
    }
    void SetName(string name) { this->name = name; }
    void SetAge(int age) { this->age = age; }
    void SetLife(int life) { this->life = life; }
    void SetBreed(string breed) { this->breed = breed; }
    string GetName() const { return name; }
    int GetAge() const { return age; }
    int GetLife() const { return life; }
    string GetBreed() const { return breed; }
    
    friend ostream& operator << (ostream & os, const Cat & obj)
    {
        os << "Name: " << obj.name << endl;
        os << "Age: " << obj.age << endl;
        os << "Life: " << obj.life << endl;
        os << "Breed: " << obj.breed << endl;
        return os;
    }
    friend istream& operator >> (istream& is, Cat& obj)
    {
        cout << "Input name: ";
        getline(is, obj.name);
        cout << "Input age: ";
        (is >> obj.age).ignore();
        cout << "Input Life: ";
        (is >> obj.life).ignore();
        cout << "Input Breed: ";
        getline(is, obj.breed);
        return is;
    }

};

class Dog
{
    private:
        string name;
        int age;
        string breed;
        int command;
    public:
        Dog() : name("Bobik"), age(1), breed("no"), command(13) {}
        Dog(string name, int age) : Dog()
        {
            this->name = name;
            this->age = age;
        }
        void SetName(string name) { this->name = name; }
        void SetAge(int age) { this->age = age; }
        void SetCommand(int command) { this->command = command; }
        void SetBreed(string breed) { this->breed = breed; }
        string GetName() const { return name; }
        int GetAge() const { return age; }
        int GetLife() const { return command; }
        int GetCommand() const { return command; }
        string GetBreed() const { return breed; }

        friend ostream& operator << (ostream& os, const Dog& obj)
        {
            os << "Name: " << obj.name << endl;
            os << "Age: " << obj.age << endl;
            os << "Command: " << obj.command << endl;
            os << "Breed: " << obj.breed << endl;
            return os;
        }
        friend istream& operator >> (istream& is, Dog& obj)
        {
            cout << "Input name: ";
            getline(is, obj.name);
            cout << "Input age: ";
            (is >> obj.age).ignore();
            cout << "Input Command: ";
            (is >> obj.command).ignore();
            cout << "Input Breed: ";
            getline(is, obj.breed);
            return is;
        }

};

class CatDog
{
private:
    string name;
    int age;
    string breed;
    int life;
    int command;
public:
    CatDog() : name("CotoPes"), age(1), breed("no"), life(), command(5) {}
    CatDog(string name, int age) : CatDog()
    {
        this->name = name;
        this->age = age;
    }
    void SetName(string name) { this->name = name; }
    void SetAge(int age) { this->age = age; }
    void SetLife(int life) { this->life = life; }
    void SetBreed(string breed) { this->breed = breed; }
    void SetCommand(int command) { this->command = command; }
    string GetName() const { return name; }
    int GetAge() const { return age; }
    int GetLife() const { return life; }
    string GetBreed() const { return breed; }

    friend ostream& operator << (ostream& os, const CatDog& obj)
    {
        os << "Name: " << obj.name << endl;
        os << "Age: " << obj.age << endl;
        os << "Life: " << obj.life << endl;
        os << "Breed: " << obj.breed << endl;
        os << "Command: " << obj.command << endl;
        return os;
    }
    friend istream& operator >> (istream& is, CatDog& obj)
    {
        cout << "Input name: ";
        getline(is, obj.name);
        cout << "Input age: ";
        (is >> obj.age).ignore();
        cout << "Input Life: ";
        (is >> obj.life).ignore();
        cout << "Input Breed: ";
        getline(is, obj.breed);
        cout << "Input Command: ";
        (is >> obj.command).ignore();
    }

};



CatDog operator + (const Cat& obj1, const Dog& obj2)
{
    CatDog res;
    res.SetName(obj1.GetName() + '-' + obj2.GetName());
    res.SetAge((obj1.GetAge() + obj2.GetAge()) / 2);
    res.SetBreed(obj1.GetBreed() + '-' + obj2.GetBreed());
    res.SetLife(obj1.GetLife());
    res.SetCommand(obj2.GetCommand());
    return res;
}

int main()
{
    Dog dog;
    Cat cat;

    cin >> cat >> dog;

    CatDog CD = cat + dog;

    cout << cat << endl;
    cout << dog << endl;
    cout << CD << endl;

    /*DogCat DC = dog + cat;
    cout << DC << endl;*/
}
