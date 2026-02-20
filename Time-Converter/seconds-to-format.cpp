#include <iostream>
using namespace std;

class TimeConverter {
public:
    void secondsToTime(int totalSeconds) {
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;

        cout << "HH:MM:SS => "
             << hours << ":"
             << minutes << ":"
             << seconds << endl;
    }
};

int main() {
    TimeConverter t;
    int totalSeconds;

    cout << "Enter total seconds: ";
    cin >> totalSeconds;

    t.secondsToTime(totalSeconds);

    return 0;
}
