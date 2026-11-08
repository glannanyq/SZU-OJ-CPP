#include <bits/stdc++.h>
using namespace std;

class Robot {
private:
	string name;
	char type;
	int level;
	int hp, damage, defense;
	
	void Calculate() {
		switch (type) {
			case 'N':
				hp = 5 * level;
				damage = 5 * level;
				defense = 5 * level;
				break;
			case 'A':
				hp = 5 * level;
				damage = 10 * level;
				defense = 5 * level;
				break;
			case 'D':
				hp = 5 * level;
				damage = 5 * level;
				defense = 10 * level;
				break;
			case 'H':
				hp = 50 * level;
				damage = 5 * level;
				defense = 5 * level;
				break;
			default:
				break;
		}
	}
	
public:
	Robot(string n, char t, int l) : name(n), type(t), level(l) {
		Calculate();
	}
	
	void print() {
		cout << name << "--" << type << "--" << level << "--" 
             << hp << "--" << damage << "--" << defense << endl;
	}
	
	string getName() {
		return name;
	}
	
	void setName(string n) {
		name = n;
	}
	
	char getType() {
		return type;
	}
	
	void setType(char t) {
		if (type != t) {
			type = t;
			Calculate();
		}
	}
	
	int getLevel() {
		return level; 
	}
	
	void setLevel(int l) {
		level = l;
		Calculate();
	}
	
	int getHp() {
		return hp;
	}
	
	int getDamage() {
		return damage;
	}
	
	int getDefense() {
		return defense;
	}
	
};

bool transform(Robot* robot, char newType) {
    if (robot->getType() == newType) {
        return false;
    }
    robot->setType(newType);
    return true;
}

int main() {
	int t;
	cin >> t;
	
	int count = 0;
	
	while (t--) {
		string name;
		char type;
		int level;
		char newType;
		cin >> name >> type >> level;
		cin >> newType;
		
		Robot robot(name, type, level);
		
		if (transform(&robot, newType)) {
			count++;
		}
		
		robot.print();
		
	}
	
	cout << "The number of robot transform is " << count << endl;
}
