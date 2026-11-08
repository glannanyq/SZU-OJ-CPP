#include <iostream>
#include <iomanip>
using namespace std;

class MyClock {
private:
    int hour;
    int minute;
    int second;
    
public:
    MyClock(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
    
    MyClock& operator++() {
        second++;
        if (second >= 60) {
            second = 0;
            minute++;
            if (minute >= 60) {
                minute = 0;
                hour++;
                if (hour >= 12) {
                    hour = 0;
                }
            }
        }
        return *this;
    }
    
    MyClock operator--(int) {
        MyClock temp = *this;
        second--;
        if (second < 0) {
            second = 59;
            minute--;
            if (minute < 0) {
                minute = 59;
                hour--;
                if (hour < 0) {
                    hour = 11;
                }
            }
        }
        return temp;
    }
    
    void print() const {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

int main() {
    int h, m, s;
    cin >> h >> m >> s;
    MyClock clock(h, m, s);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        
        if (x > 0) {
            for (int j = 0; j < x; j++) {
                ++clock;
            }
        } else if (x < 0) {
            for (int j = 0; j < -x; j++) {
                clock--;
            }
        }
        
        clock.print();
    }
    
    return 0;
}
