#include <bits/stdc++.h>
using namespace std;

class PhoneNumber {
private:
	int number;
    char type;

public:
    PhoneNumber(int num, char t) : number(num), type(t) {}

    int getNumber() {
        return number;
    }

    char getType() {
        return type;
    }

    void setNumber(int n) {
        number = n;
    }

    void setType(char t) {
        type = t;
    }
};

class Telephone {
private:
	PhoneNumber phonenum;
	int state;
	string owner;
	
public:
	Telephone(int num, char t, int st, const string& own) : 
	phonenum(num, t), state(st), owner(own) {
		cout << num << " constructed." << endl; 
	}
	
	~Telephone() {
		cout << phonenum.getNumber() << " destructed. " << endl;
	}
	
	void print() {
		cout << "Phone=" << phonenum.getNumber() 
             << "--Type=" << phonenum.getType() 
             << "--State=" << (state == 1 ? "use" : "unuse")
             << "--Owner=" << owner << endl;
	}
	
	int query(int num) {
		if (phonenum.getNumber() == num) {
			return 1;
		}
		return 0;
	}
};

int main() {

    int num1, num2, num3;
    char type1, type2, type3;
    int state1, state2, state3;
    string owner1, owner2, owner3;

    cin >> num1 >> type1 >> state1 >> owner1;
    cin >> num2 >> type2 >> state2 >> owner2;
    cin >> num3 >> type3 >> state3 >> owner3;

    Telephone tel1(num1, type1, state1, owner1);
    Telephone tel2(num2, type2, state2, owner2);
    Telephone tel3(num3, type3, state3, owner3);

    int t;
    cin >> t;

    Telephone* tels[] = { &tel1, &tel2, &tel3 };

    while (t--) {
        int queryNum;
        cin >> queryNum;

        bool found = false;
        for (int j = 0; j < 3; j++) {
            if (tels[j]->query(queryNum)) {
                tels[j]->print();
                found = true;
                break;
            }
          	
        }
      
      	if (!found) {
            cout << "wrong number." << endl;
        }
    }

}
