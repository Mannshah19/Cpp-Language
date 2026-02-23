#include <iostream>
using namespace std;

class TimeConverter
{
public:

    void secondsToTime(int totalSeconds)
    {
        int h, m, s;

        h = totalSeconds / 3600;
        m = (totalSeconds % 3600) / 60;
        s = totalSeconds % 60;

        cout << "Time is: " << h << ":" << m << ":" << s << endl;
    }

    void timeToSeconds(int h, int m, int s)
    {
        int total;

        total = h * 3600 + m * 60 + s;

        cout << "Total seconds are: " << total << endl;
    }
};

int main()
{
    TimeConverter t;
    int choice;

    cout << "1. Seconds to Time" << endl;
    cout << "2. Time to Seconds" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            int totalSeconds;
            cout << "Enter total seconds: ";
            cin >> totalSeconds;

            t.secondsToTime(totalSeconds);
            break;
        }

        case 2:
        {
            int h, m, s;

            cout << "Enter hours: ";
            cin >> h;

            cout << "Enter minutes: ";
            cin >> m;

            cout << "Enter seconds: ";
            cin >> s;

            t.timeToSeconds(h, m, s);
            break;
        }

        default:
            cout << "Wrong choice entered." << endl;
    }

    return 0;
}
