#include <iostream>
using namespace std;


class Shape
{

public:

    virtual void area() = 0;

    virtual void draw() = 0;



};



class Circle : public Shape
{

    float r;

public:

    Circle(float radius)
    {

        r = radius;


    }

    void area()
    {
        float a;

        a = 3.14 * r * r;

        cout<<"Circle Area: "<<a<<endl;


    }

    void draw()
    {
        cout<<"Drawing Circle"<<endl;
    }

};



class Rectangle : public Shape
{

    float l , w;

public:

    Rectangle(float length , float width)
    {
        l = length;
        w = width;


    }

    void area()
    {

        float a;

        a = l * w;

        cout<<"Rectangle Area: "<<a<<endl;

    }



    void draw()
    {


        cout<<"Drawing Rectangle"<<endl;


    }



};



int main()
{

    Shape *s[2];

    Circle c(5);
    Rectangle r(4 , 6);

    s[0] = &c;
    s[1] = &r;


    for(int i = 0 ; i < 2 ; i++)
    {

        s[i]->area();

        s[i]->draw();

        cout<<endl;

    }



    return 0;


    
}