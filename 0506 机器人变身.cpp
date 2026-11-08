#include <bits/stdc++.h>
using namespace std;

class Robot {
private:
	string name;
	char type;
	int level;
	int hp, damage, defense;
	
	void calculate() {
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
		calculate();
	}
	
	void print() {
		cout << name << "--" << type << "--" << level << "--" << 
		hp << "--" << damage << "--" << defense << endl;
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
			calculate();
		}
	}
	
	int getLevel() {
		return level;
	}
	
	void setLevel(int l) {
		level = l;
		
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

bool transform(Robot* robot, char newtype) {
	if (robot->getType() == newtype) {
    	return false;
	}
	robot->setType(newtype);
	return true;
}

int main() {
	int t;
	cin >> t;
	
	int count = 0;
	
	while (t--) {
		string name;
		char type, newtype;
		int level;
		cin >> name >> type >> level;
		cin >> newtype;
		
		Robot robot(name, type, level);
		
		if(transform(&robot, newtype)) {
			count++;
		}
		
		robot.print();
	} 
	
	cout << "The number of robot transform is " << count << endl;
}
