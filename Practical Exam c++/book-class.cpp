#include<iostream>
#include<cstring>
using namespace std;

class Book{
private:

    char title[100];


    char author[50];


    int publishedYear;

public:


    Book(const char t[]="", const char a[]="", int year=0){


        strcpy(title, t);

        strcpy(author, a);

        publishedYear = year;




    }

    void display(){
        cout<<"Title: "<<title<<", Author: "<<author<<", Year: "<<publishedYear<<endl;


    }

    char* getTitle(){ return title; }
    char* getAuthor(){ return author; }
    int getYear(){ return publishedYear; }






};

int main(){
    Book books[3] = {
        Book("The Mann", "Mann Shah", 2000),
        Book("Law Of Human Behaviour", "Robert Frost", 1969),
        Book("FLow Of Money ", "Walter White", 1960)



    };

    cout<<"--- Displaying Books ---"<<endl;


    for(int i=0; i<3; i++){
        cout<<"Book "<<i+1<<": ";
        books[i].display();

        
    }

    cout<<"\n--- Accessing Attributes ---"<<endl;
    
    cout<<"First book title: "<<books[0].getTitle()<<endl;


    cout<<"Second book author: "<<books[1].getAuthor()<<endl;

    cout<<"Third book year: "<<books[2].getYear()<<endl;

    return 0;



}
