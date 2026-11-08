#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int score;
    
public:
    Student(string n, int s) : name(n), score(s) {}
    
    friend class Teacher;
    
    void print() {
        cout << name << " " << score << endl;
    }
};

class Teacher {
public:
    void updateScore(Student &s, int newScore) {
        s.score = newScore;
    }
};

int main() {
    int M;
    cin >> M;
    
    Student** students = new Student*[M];
    
    for (int i = 0; i < M; i++) {
        string name;
        int score;
        cin >> name >> score;
        students[i] = new Student(name, score);
    }
    
    int N;
    cin >> N;
    
    Teacher teacher;
    
    for (int i = 0; i < N; i++) {
        string name;
        int newScore;
        cin >> name >> newScore;
        
        for (int j = 0; j < M; j++) {
            students[j]->print();
        }
        
        for (int j = 0; j < M; j++) {
            string studentName;
            int score;
        }
        
        for (int j = 0; j < M; j++) {
            students[j]->print();
        }
    }
    
    for (int i = 0; i < M; i++) {
        delete students[i];
    }
    delete[] students;

}
