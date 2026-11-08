#include <iostream>
#include <cstring>
using namespace std;

class Institute {
protected:
    char instituteName[50];
public:
    Institute() { 
        instituteName[0] = '\0'; 
    }
    Institute(const char* name) {
        strcpy(instituteName, name);
    }
    const char* getInstituteName() const { return instituteName; }
};

class Student : virtual public Institute {
private:
    char studentID[20];
    char studentName[30];
public:
    Student() : Institute() {
        studentID[0] = '\0';
        studentName[0] = '\0';
    }
    Student(const char* inst, const char* id, const char* name)
        : Institute(inst) {
        strcpy(studentID, id);
        strcpy(studentName, name);
    }
    const char* getStudentID() const { return studentID; }
    const char* getStudentName() const { return studentName; }
};

class Course : virtual public Institute {
private:
    char courseID[20];
    char courseName[30];
    int credit;
    char timeSlot[20];
public:
    Course() : Institute() {
        courseID[0] = '\0';
        courseName[0] = '\0';
        credit = 0;
        timeSlot[0] = '\0';
    }
    Course(const char* inst, const char* cid, const char* cname, int c, const char* t)
        : Institute(inst) {
        strcpy(courseID, cid);
        strcpy(courseName, cname);
        credit = c;
        strcpy(timeSlot, t);
    }
    const char* getCourseID() const { return courseID; }
    const char* getCourseName() const { return courseName; }
    int getCredit() const { return credit; }
    const char* getTimeSlot() const { return timeSlot; }
};

class Student_Course : public Student, public Course {
private:
    bool status;
public:
    Student_Course() : Institute(), Student(), Course(), status(false) {}
    
    Student_Course(const Student& s, const Course& c)
        : Institute(s.getInstituteName()), Student(s), Course(c), status(false) {}

    void setStatus(bool s) { status = s; }
    bool getStatus() const { return status; }

    void printInfo() const {
        cout << getInstituteName() << "," << getStudentName() << ","
             << getCourseName() << "," << getCredit() << "," << getTimeSlot() << endl;
    }

    bool isTimeConflict(const Student_Course& other) const {
        return (strcmp(getTimeSlot(), other.getTimeSlot()) == 0);
    }
    
    bool isSameStudent(const Student_Course& other) const {
        return (strcmp(getStudentID(), other.getStudentID()) == 0);
    }
};

class Administration {
private:
    Student_Course* records;
    int length;
public:
    Administration(int len) : length(len) {
        records = new Student_Course[length];
    }

    ~Administration() {
        delete[] records;
    }

    void setRecord(int index, const Student& s, const Course& c) {
        records[index] = Student_Course(s, c);
    }

    void process() {
        for (int i = 0; i < length; i++) {
            // 先检查学院是否相同
            if (strcmp(records[i].Student::getInstituteName(), 
                      records[i].Course::getInstituteName()) != 0) {
                records[i].setStatus(false);
                continue;
            }

            bool conflict = false;
            // 只检查已成功选课的同学习记录
            for (int j = 0; j < i; j++) {
                if (records[j].getStatus() && 
                    records[i].isSameStudent(records[j]) &&
                    records[i].isTimeConflict(records[j])) {
                    conflict = true;
                    break;
                }
            }
            
            if (conflict) {
                records[i].setStatus(false);
            } else {
                records[i].setStatus(true);
            }
        }
    }

    void print() const {
        for (int i = 0; i < length; i++) {
            if (records[i].getStatus()) {
                records[i].printInfo();
            }
        }
    }
};

int main() {
    int t1, t2, t3;

    // 输入学生
    cin >> t1;
    Student* students = new Student[t1];
    char inst[50], id[20], name[30];
    for (int i = 0; i < t1; i++) {
        cin >> inst >> id >> name;
        students[i] = Student(inst, id, name);
    }

    // 输入课程
    cin >> t2;
    Course* courses = new Course[t2];
    char cid[20], cname[30], timeSlot[20];
    int credit;
    for (int i = 0; i < t2; i++) {
        cin >> inst >> cid >> cname >> credit >> timeSlot;
        courses[i] = Course(inst, cid, cname, credit, timeSlot);
    }

    // 输入选课
    cin >> t3;
    Administration admin(t3);
    char sid[20], cid2[20];
    for (int i = 0; i < t3; i++) {
        cin >> sid >> cid2;
        // 查找学生和课程
        Student s;
        Course c;
        bool foundStudent = false, foundCourse = false;
        for (int j = 0; j < t1; j++) {
            if (strcmp(students[j].getStudentID(), sid) == 0) {
                s = students[j];
                foundStudent = true;
                break;
            }
        }
        for (int j = 0; j < t2; j++) {
            if (strcmp(courses[j].getCourseID(), cid2) == 0) {
                c = courses[j];
                foundCourse = true;
                break;
            }
        }
        if (foundStudent && foundCourse) {
            admin.setRecord(i, s, c);
        }
    }

    admin.process();
    admin.print();

    delete[] students;
    delete[] courses;
    return 0;
}
