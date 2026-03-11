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
        strcpy(name , n);
    }

    void setSound(const char s[])
    {
        strcpy(sound , s);
    }

    const char* getName()
    {
        return name;
    }

    const char* getSound()
    {
        return sound;
    }

    virtual void displayDetails() = 0;

};




class Dog : public Animal
{

public:

    void displayDetails()
    {
        cout<<"Animal: "<<getName()<<endl;
        cout<<"Sound: "<<getSound()<<endl;
    }

};




class Cat : public Animal
{

public:

    void displayDetails()
    {
        cout<<"Animal: "<<getName()<<endl;
        cout<<"Sound: "<<getSound()<<endl;
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


    Animal *a[2];

    a[0] = &d;
    a[1] = &c;


    for(int i=0;i<2;i++)
    {

        a[i]->displayDetails();

        cout<<endl;

    }


    return 0;
}