#include <iostream>
using namespace std;

class TimeConverter {
public:
    void timeToSeconds(int hours, int minutes, int seconds) {
        int totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
        cout << "Total seconds: " << totalSeconds << endl;
    }
};

int main() {
    TimeConverter t;
    int h, m, s;

    cout << "Enter hours: ";
    cin >> h;

    cout << "Enter minutes: ";
    cin >> m;

    cout << "Enter seconds: ";
    cin >> s;

    t.timeToSeconds(h, m, s);

    return 0;
}
