#include <iostream>
#include <string>
using namespace std;

class Actor {
protected:
    string name;
    int age;
public:
    Actor(string n, int a) : name(n), age(a) {}
    virtual void perform() = 0;
    virtual ~Actor() {}
};

class King : public Actor {
public:
    King(string n, int a) : Actor(n, a) {}
    void perform() override {
        cout << "Hello, my name is " << name << ". I am " << age << ". I am the King." << endl;
    }
};

class Queen : public Actor {
public:
    Queen(string n, int a) : Actor(n, a) {}
    void perform() override {
        cout << "Hello, my name is " << name << ". I am " << age << ". I am the Queen." << endl;
    }
};

class Knight : public Actor {
public:
    Knight(string n, int a) : Actor(n, a) {}
    void perform() override {
        cout << "Hello, my name is " << name << ". I am " << age << ". I am a Knight." << endl;
    }
};

Actor* createActor(string type, string name, int age) {
    if (type == "King") {
        return new King(name, age);
    } else if (type == "Queen") {
        return new Queen(name, age);
    } else if (type == "Knight") {
        return new Knight(name, age);
    } else {
        return NULL;
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        string type, name;
        int age;
        cin >> type >> name >> age;
        
        Actor* actor = createActor(type, name, age);
        if (actor != NULL) {
            actor->perform();
            delete actor;
        } else {
            cout << "There is no " << type << "." << endl;
        }
    }

}
