#include<iostream>
using namespace std;

class Base
{


};

class Derived : public Base
{

    public:

    void calculate  (int a , int b){
        if (b!= 0)
        cout << "DIvision: " << (float)a/b << endl;
        else cout << "Division with zero is not possible" << endl;


    }


    void calculate (int a, int b, int c){
        cout << "Subtraction: " << a-b-c << endl;
    }

    void calculate (int a , int b, int c, int d)
    {
        cout << "Multiplication: " << a*b*c*d << endl;
    }

    void calculate (int a , int b , int c , int d , int e)
    {

        
        cout << "Addition: " << a+b+c+d+e << endl;

    }

};


int main(){

    Derived obj;

    obj.calculate(20, 5);             
    obj.calculate(20, 5, 3);           
    obj.calculate(2, 3, 4, 5);       
    obj.calculate(1, 2, 3, 4, 5);     

    return 0;
}
