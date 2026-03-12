#include <iostream>
#include <string>
using namespace std;


class LibraryItem
{

private:        

    string title;
    string author;
    string dueDate;

public:

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getDueDate()
    {
        return dueDate;
    }

    void setTitle(string newTitle)
    {
        title = newTitle;
    }

    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }

    void setDueDate(string newDueDate)
    {
        dueDate = newDueDate;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

};





class Book : public LibraryItem
{

    int pages;

public:

    void setPages(int p)
    {
        if(p < 0)
        {
            throw p;
        }

        pages = p;
    }

    void checkOut()
    {
        cout<<"Book checked out\n";
    }

    void returnItem()
    {
        cout<<"Book returned\n";
    }

    void displayDetails()
    {
        cout<<"Type: Book\n";
        cout<<"Title: "<<getTitle()<<endl;
        cout<<"Author: "<<getAuthor()<<endl;
        cout<<"Due Date: "<<getDueDate()<<endl;
        cout<<"Pages: "<<pages<<endl;
    }

};



class DVD : public LibraryItem
{

    int duration;

public:

    void setDuration(int d)
    {
        if(d < 0)
        {
            throw d;
        }

        duration = d;
    }

    void checkOut()
    {
        cout<<"DVD checked out\n";
    }

    
    void returnItem()
    {
        cout<<"DVD returned\n";
    }

    void displayDetails()
    {
        cout<<"Type: DVD\n";
        cout<<"Title: "<<getTitle()<<endl;
        cout<<"Author: "<<getAuthor()<<endl;
        cout<<"Due Date: "<<getDueDate()<<endl;
        cout<<"Duration: "<<duration<<" mins\n";
    }

};




class Magazine : public LibraryItem
{

    int issueNumber;

public:

    void setIssue(int i)
    {
        if(i < 0)
        {
            throw i;
        }

        issueNumber = i;
    }

    void checkOut()
    {
        cout<<"Magazine checked out\n";


    }

    void returnItem()
    {
        cout<<"Magazine returned\n";
    }

    void displayDetails()
    {
        cout<<"Type: Magazine\n";
        cout<<"Title: "<<getTitle()<<endl;
        cout<<"Author: "<<getAuthor()<<endl;
        cout<<"Due Date: "<<getDueDate()<<endl;
        cout<<"Issue: "<<issueNumber<<endl;


    }



};






int main()
{

    const int MAX_ITEMS = 50;

    LibraryItem* libraryItems[MAX_ITEMS];

    int count = 0;

    int choice;

    do
    {

        cout<<"\n1 Add Book\n";
        cout<<"2 Add DVD\n";
        cout<<"3 Add Magazine\n";
        cout<<"4 Display All\n";
        cout<<"5 Check Out\n";
        cout<<"6 Return Item\n";
        cout<<"7 Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        if(choice == 1)
        {

            try
            {

                Book *b = new Book;

                string t,a,d;
                int p;

                cout<<"Enter title: ";
                cin>>t;

                cout<<"Enter author: ";
                cin>>a;

                cout<<"Enter due date: ";
                cin>>d;

                cout<<"Enter pages: ";
                cin>>p;

                b->setTitle(t);
                b->setAuthor(a);
                b->setDueDate(d);

                b->setPages(p);

                libraryItems[count] = b;
                count++;

            }

            catch(...)
            {
                cout<<"Invalid book data\n";
            }

        }

        else if(choice == 2)
        {

            try
            {

                DVD *d1 = new DVD;

                string t,a,d;
                int dur;

                cout<<"Enter title: ";
                cin>>t;

                cout<<"Enter author: ";
                cin>>a;

                cout<<"Enter due date: ";
                cin>>d;

                cout<<"Enter duration: ";
                cin>>dur;

                d1->setTitle(t);
                d1->setAuthor(a);
                d1->setDueDate(d);

                d1->setDuration(dur);

                libraryItems[count] = d1;
                count++;

            }

            catch(...)
            {
                cout<<"Invalid dvd data\n";
            }

        }

        else if(choice == 3)
        {

            try
            {

                Magazine *m = new Magazine;

                string t,a,d;
                int issue;

                cout<<"Enter title: ";
                cin>>t;

                cout<<"Enter author: ";
                cin>>a;

                cout<<"Enter due date: ";
                cin>>d;

                cout<<"Enter issue number: ";
                cin>>issue;

                m->setTitle(t);
                m->setAuthor(a);
                m->setDueDate(d);

                m->setIssue(issue);

                libraryItems[count] = m;
                count++;

            }

            catch(...)
            {
                cout<<"Invalid magazine data\n";
            }

        }

        else if(choice == 4)
        {

            for(int i=0;i<count;i++)
            {

                libraryItems[i]->displayDetails();

                cout<<endl;

            }

        }

        else if(choice == 5)
        {

            int id;

            cout<<"Enter item index: ";
            cin>>id;

            if(id >=0 && id < count)
            {
                libraryItems[id]->checkOut();
            }

        }

        else if(choice == 6)
        {

            int id;

            cout<<"Enter item index: ";
            cin>>id;

            if(id >=0 && id < count)
            {
                libraryItems[id]->returnItem();


            }

        }

    }

    while(choice != 7);



    for(int i=0;i<count;i++)
    {
        delete libraryItems[i];

    }


    return 0;





}