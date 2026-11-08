#include<iostream>
using namespace std;
/********** Write your code here! **********/

class Animal {
protected:
	int age;
public:
	Animal(int a) : age(a) {
		cout << "Animal constructed." << endl;
	}
	void display() {
		cout << "Animal age:" << age << endl;
	}
	~Animal() {
	}
};

class Bird : public Animal {
protected:
	float wingspan;
public:
	Bird(int a) : Animal(a) {
		cout << "Bird constructed." << endl;
	}
	void display() {
		cout << endl;
		cout << "Animal age:" << age << endl;
		cout << "Wingspan: " << wingspan << "m" << endl;
	}
};


/*******************************************/
void display1(Animal* obj) 
/********** Write your code here! **********/
{
	obj->display();
	cout << endl;
}

/*******************************************/
void display2(Animal* obj) 
/********** Write your code here! **********/
{
	Bird* bird = Bird(obj);
	if(bird != NULL) {
		bird->display();
	}
}

/*******************************************/
int main() {
	int a; float w; 
	cin >> a >> w;
	Bird obj(a, w);
	cout<<endl;
	display1(&obj);
	cout << endl;
    display2(&obj);
	return 0;
}
