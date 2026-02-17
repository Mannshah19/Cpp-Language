#include <iostream>
using namespace std;

int main () {

    int n ;

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    
    cout << "Enter the elements of array: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Even numbers in array: "<< endl;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0){

            cout << arr[i] << " ";
        }
    }
    
    return 0;
    
}
