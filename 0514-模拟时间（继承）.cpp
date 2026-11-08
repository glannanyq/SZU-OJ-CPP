#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Time {
protected:
    int hour, minute, second;
public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
};

class Time_12hours : public Time {
private:
    char interval[5];
    
public:
	Time_12hours(int type, int h, int m, int s) : Time(h, m, s){
		if (type == 121) {
			strcpy(interval, "AM");
		}
		else {
			strcpy(interval, "PM");
		}
	}
	
	void standard() {
    	while (second < 0) {
    		second += 60;
    		minute--;
		}
		while (minute < 0) {
			minute += 60;
			hour--;
		}
		while (hour < 0) {
			hour += 12;
			if (strcmp(interval, "AM") == 0) {
				strcpy(interval, "PM");
			}
			else{
				strcpy(interval, "AM");
			}
		}
		
		while (second >= 60) {
			second -= 60;
			minute++;
		}
		while (minute >= 60) {
			minute -= 60;
			hour++;
		}
		if (hour >= 24) {
			int cycles = hour / 24;
			hour %= 24;
			if (cycles % 2 == 1) {
				if (strcmp(interval, "AM") == 0) {
					strcpy(interval, "PM");
				}
				else {
					strcpy(interval, "AM");
				}
			}	
		}
		if (hour >= 12) {
			hour -= 12;
			if (strcmp(interval, "AM") == 0) {
				strcpy(interval, "PM");
			}
			else {
				strcpy(interval, "AM");
			}
		}
		
	} 
	
	void addSecond() {
		second++;
		standard();
	}
	
	void subSecond() {
		second--;
		standard();
	}
	
	void display() {
		cout << interval << " " << setw(2) << setfill('0') << hour << ":"
		<< setw(2) << setfill('0') << minute << ":" 
		<< setw(2) << setfill('0') << second << endl;
	}
};

int main() {
	int type;
	while (cin >> type && type != 0) {
		int h, m, s, count;
		char op;
		cin >> h >> m >> s >> op >> count;
		
		Time_12hours t(type, h, m, s);
		
		for (int i = 0; i < count; i++) {
			if (op == '+') {
				t.addSecond();
			}
			else {
				t.subSecond();
			} 
		} 
		
		t.display();
	}
}
