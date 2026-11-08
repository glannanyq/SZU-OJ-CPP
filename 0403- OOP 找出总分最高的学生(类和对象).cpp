#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    string id;
    string name;
    int score1;
    int score2;
    int score3;
    int total;

public:

    void input() {
        cin >> id >> name >> score1 >> score2 >> score3;
    }

    void calculate() {
        total = score1 + score2 + score3;
    }
	
	int getTotal() const {
        return total;
    }

    string getName() const {
        return name;
    }

    string getId() const {
        return id;
    }
};

int main() {
	int n;
	cin >> n;
	
	Student* students = new Student[n];
	for (int i = 0; i < n; i++) {
		students[i].input();
		students[i].calculate();
	}
    
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].getTotal() > students[maxIndex].getTotal()) {
            maxIndex = i;
        }
    }

    cout << students[maxIndex].getName() << " " 
         << students[maxIndex].getId() << " " 
         << students[maxIndex].getTotal() << endl;
         
	delete[] students;

}
