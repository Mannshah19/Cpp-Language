#include<iostream>
using namespace std;

class P {

    protected :
    float temperature;


    public :

    void setTemperature(){

        cout << "Enter Temperature in Celsius: ";
        cin >> temperature;

    }
};


class Q : public P {

    protected:
    float fahrenheit;


    public:

    void toFahrenheit(){

        fahrenheit = (temperature * 9 / 5) + 32;

        cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
    }


};


class R : public Q {


    public:
    void toKelvin(){

    float kelvin;

    kelvin = ((fahrenheit - 32) * 5 / 9) + 273.15;
    cout << "Temperature in Kelvin: " << kelvin << endl;
    }
        


};

int main (){

    R obj;

    obj.setTemperature();  
    obj.toFahrenheit();     
    obj.toKelvin();         



    return 0;

}


