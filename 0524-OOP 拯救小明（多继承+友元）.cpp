#include <iostream>
#include <iomanip>
using namespace std;

class Date {
protected:
    int year, month, day;
public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
};

class Time {
protected:
    int hour, minute, second;
public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
    int getHour() { return hour; }
    int getMinute() { return minute; }
    int getSecond() { return second; }
};

class Work : public Date, public Time {
private:
    int ID;
public:
    Work(int id = 0, int y = 0, int m = 0, int d = 0, int h = 0, int mi = 0, int s = 0)
        : Date(y, m, d), Time(h, mi, s), ID(id) {}
    int getID() { return ID; }
    friend bool before(const Work& w1, const Work& w2);
};

bool before(const Work& w1, const Work& w2) {
    if (w1.year != w2.year) return w1.year < w2.year;
    if (w1.month != w2.month) return w1.month < w2.month;
    if (w1.day != w2.day) return w1.day < w2.day;
    if (w1.hour != w2.hour) return w1.hour < w2.hour;
    if (w1.minute != w2.minute) return w1.minute < w2.minute;
    return w1.second < w2.second;
}

int main() {
    int id, y, m, d, h, mi, s;
    Work earliest;
    bool first = true;
    
    while (cin >> id && id != 0) {
        cin >> y >> m >> d >> h >> mi >> s;
        Work w(id, y, m, d, h, mi, s);
        if (first || before(w, earliest)) {
            earliest = w;
            first = false;
        }
    }
    
    cout << "The urgent Work is No." << earliest.getID() << ": "
         << earliest.getYear() << "/" << earliest.getMonth() << "/" 
         << earliest.getDay() << " "
         << setw(2) << setfill('0') << earliest.getHour() << ":"
         << setw(2) << setfill('0') << earliest.getMinute() << ":"
         << setw(2) << setfill('0') << earliest.getSecond() << endl;

}
