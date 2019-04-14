//clang 3.8.0

#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

enum eAnimalType
{
    eDog = 1,
    eCat,
    eElephant,
    eTiger
};

class Animal
{
    const eAnimalType m_eType = eDog;
public:
    Animal(eAnimalType type) : m_eType(type) {}
    virtual void SayHello() = 0;
    void WaitAnswer()
    {
        cout << "Who is this animal? (Dog: 1, Cat: 2, Elephant: 3, Tiger: 4)" << endl;
        int answer = 0;
        cin >> answer;
        while(m_eType != answer)
        {
            cout << "Wrong! Try again!" << endl;
            cin >> answer;
        }
        cout << "Right! Congratulations!" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog() : Animal(eDog) {}
    void SayHello() override {cout << "GAV!" << endl;}
    void SitDown(){cout << "DOG Sit down!" << endl;}
};

class Cat : public Animal
{
public:
    Cat() : Animal(eCat) {}
    void SayHello() override {cout << "MEOW!" << endl;};
};

class Elephant : public Animal
{
public:
    Elephant() : Animal(eElephant) {}
    void SayHello() override {cout << "PRUUUU!" << endl;};
};

class Tiger : public Animal
{
public:
    Tiger() : Animal(eTiger) {}
    void SayHello() override {cout << "RRRRR!" << endl;}
};



int main()
{
   srand(time(NULL));
    
   const int size = 10;
   Animal *p[size];
    for(int i = 0; i < size; i++)
    {
        int choice = rand() % 4;
        switch(choice)
        {
            case 0: 
                p[i] = new Dog;
                break;
            case 1: 
                p[i] = new Cat;
                break;
            case 2: 
                p[i] = new Elephant;
                break;
	    case 3:
		p[i] = new Tiger;
		break;
        }
    }
    
    for(int i = 0; i < size; i++)
    {
        p[i]->SayHello();
        p[i]->WaitAnswer();
    }
}
