#include<iostream>
#include<cstring>
using namespace std;

class Person {
private:


    char name[50];
    int age;
    char address[100];



public:


    Person(const char* n, int a, const char* addr) {
        strcpy(name, n);
        age = a;
        strcpy(address, addr);


    }

    void setName(const char* n) {
        
        strcpy(name, n); 
    
    }

    
    void setAge(int a) {
        
        
        age = a; 
    
    }


    void setAddress(const char* addr) { strcpy(address, addr); }

    const char* getName() 
    {
        
        return name;
    
    }

    int getAge() { 
        
        return age; 
    
    }

    const char* getAddress() 
    
    { 
        
        return address; 
    
    }

    void display() {

        cout << "Name: " << name << ", Age: " << age << ", Address: " << address << endl;


    }


};

int main() {
    int n;

    cout << "Enter number of persons: ";


    cin >> n;


    Person* persons[n];


    char name[50], address[100];


    int age;

    for(int i = 0; i < n; i++) {
        cout << "Enter details for Person " << i + 1 << ":" << endl;


        cout << "Name: ";
        cin >> name;


        cout << "Age: ";
        cin >> age;


        cout << "Address: ";
        cin >> address;

        
        persons[i] = new Person(name, age, address);
    }

    cout << "--- Person Details ---" << endl;
    for(int i = 0; i < n; i++) {


        persons[i]->display();


        delete persons[i];
        
    }

    return 0;
}