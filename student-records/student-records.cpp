#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string *name;   // dynamic memory for deep copy
    int rollNo;
    float gpa;

public:

    // Default constructor
    Student()
    {
        name = new string("Unknown");
        rollNo = 0;
        gpa = 0.0;
    }

    // Parameterized constructor
    Student(string n, int r, float g)
    {
        name = new string(n);
        rollNo = r;
        gpa = g;
    }

    // Copy constructor (Deep Copy)
    Student(const Student &s)
    {
        name = new string(*(s.name));  // deep copy
        rollNo = s.rollNo;
        gpa = s.gpa;
    }

    // Destructor
    ~Student()
    {
        delete name;
    }

    // Getter methods
    string getName() const
    {
        return *name;
    }

    int getRollNo() const
    {
        return rollNo;
    }

    float getGPA() const
    {
        return gpa;
    }

    // Display function (using reference variable)
    void display() const
    {
        cout << "Name: " << *name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "GPA: " << gpa << endl;
        cout << "---------------------" << endl;
    }
};

class StudentRecordManager
{
private:
    Student *students;   // dynamic array
    int capacity;
    int count;

public:

    StudentRecordManager(int size)
    {
        capacity = size;
        count = 0;
        students = new Student[capacity];
    }

    ~StudentRecordManager()
    {
        delete[] students;
    }

    // Add student (using reference to avoid copying)
    void addStudent(const Student &s)
    {
        if (count < capacity)
        {
            students[count] = s;   // copy constructor used
            count++;
        }
        else
        {
            cout << "Record is full." << endl;
        }
    }

    // Display all students
    void displayAll() const
    {
        if (count == 0)
        {
            cout << "No records found." << endl;
            return;
        }

        for (int i = 0; i < count; i++)
        {
            students[i].display();
        }
    }

    // Search by roll number
    void searchStudent(int roll) const
    {
        for (int i = 0; i < count; i++)
        {
            if (students[i].getRollNo() == roll)
            {
                cout << "Student Found:" << endl;
                students[i].display();
                return;
            }
        }

        cout << "Student not found." << endl;
    }
};

int main()
{
    StudentRecordManager manager(5);

    // Creating students
    Student s1("Rahul", 101, 8.5);
    Student s2("Priya", 102, 9.1);
    Student s3("Amit", 103, 7.8);

    // Adding students
    manager.addStudent(s1);
    manager.addStudent(s2);
    manager.addStudent(s3);

    cout << "\nAll Student Records:\n";
    manager.displayAll();

    cout << "\nSearching for Roll No 102:\n";
    manager.searchStudent(102);

    return 0;
}