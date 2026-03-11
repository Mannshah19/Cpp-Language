#include <iostream>
#include <cstring>
using namespace std;


class Animal
{

private:

    char name[50];
    char sound[50];

public:

    void setName(const char n[])
    {

        strcpy(name,n);


    }

    void setSound(const char s[])
    {

        strcpy(sound,s);


    }

    const char* getName()
    {
        return name;


    }

    const char* getSound()
    {
        return sound;



    }



};



class Dog : public Animal
{

public:

    void makeSound()
    {
        cout<<getName()<<" says "<<getSound()<<endl;


    }

    
};



class Cat : public Animal
{

public:

    void makeSound()
    {
        cout<<getName()<<" says "<<getSound()<<endl;
    }



};



int main()
{

    Dog d;
    Cat c;

    d.setName("Dog");
    d.setSound("Bark");

    c.setName("Cat");
    c.setSound("Meow");


    
    d.makeSound();
    c.makeSound();


    return 0;




}