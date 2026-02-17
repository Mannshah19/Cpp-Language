#include <iostream>
using namespace std;

int main () {

    int y1 = 0 , y2 = 0;

    cout << "Enter First year: ";
    cin >> y1;


    cout << "Enter Second Year: ";
    cin >> y2;

    for (int i = y1; i < y2; i++)
    {
        if ( i % 4 == 0)
        {
            cout << i << " ";
        }
        
    }
    
}