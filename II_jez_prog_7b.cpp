#include <iostream>
using namespace std;

class Animal
{
private:
    int nlegs;

protected:
    float age;
    string name;

public:
    float weight;
    void SetNLegs(int lin) { nlegs = lin; }
    Animal(string namein)
    {
        nlegs = 0;
        age = 0;
        weight = 0;
        name = namein;
        cout << "New animal: " << name << " created" << endl;
    }
    virtual ~Animal() { cout << "The animal was destroyed" << endl; }
    virtual void Describe()
    {
        cout << "Animal: " << name << ", " << nlegs << " legs, weight: " << weight << "kg, age: " << age << endl;
    }
    void Sleep() { cout << "The animal is sleeping now..." << endl; }
};

class Cat : public Animal
{
public:
    string coloration;
    Cat(string namein) : Animal(namein)
    {
        SetNLegs(4);
        coloration = "";
        cout << "New cat was created" << endl;
    }
    ~Cat() { cout << "The Cat was destroyed" << endl; }
    void Purr() { cout << "Mruuuuu..." << endl; }
    void Describe()
    {
        Animal::Describe();
        cout << "This cat has " << coloration << " coloration" << endl;
    }
};

class Bird : public Animal
{
public:
    void Fly() { cout << "The bird is flying right now..." << endl; }
    Bird(string namein) : Animal(namein)
    {
        SetNLegs(2);
        cout << "New Bird was created" << endl;
    }
    ~Bird() { cout << "The bird was destroyed" << endl; }
};

void Eat(Animal *who, Animal *whom)
{
    who->Describe();
    cout << " is eating  " << endl;
    whom->Describe();
    who->weight += whom->weight;
    delete whom;
}

int main()
{
    Animal *cow = new Animal("Mucka");
    cow->weight = 1000;
    cow->Describe();
    cow->Sleep();
    delete cow;

    Cat *cat = new Cat("Mruczek");
    cat->weight = 3.5;
    cat->coloration = "black";
    cat->Describe();
    cat->Sleep();
    cat->Purr();

    Bird *bird = new Bird("Parrot");
    bird->weight = 0.53;
    bird->Describe();
    cout << "===Consumption===" << endl;
    Eat(cat, bird);
    cout << "===Consumption completed===" << endl;
    cat->Describe();
    delete cat;

    return 0;
}