#include<iostream>
using namespace std;

class X {
    protected:
    int a , b , c;
};

class Y : public X {
    public:

    void setData(){
        cout<< "Enter First Number: ";
        cin>>a;

        cout<< "Enter second Number: ";
        cin>>b;

        cout<< "Enter Third Number: ";
        cin>>c;



    }

    void getData(){

        int sum;
        sum = (a * a * a) + (b * b * b) + (c * c * c);

        cout << "SUm Of Cubes is : " << sum << endl;


        

    }

};

int main(){

    Y obj;

    obj.setData();
    obj.getData();




    return 0;
}
