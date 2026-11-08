#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class CAccount {
private:
    long account;
    char name[10];
    float balance;
    
public:
	
    CAccount(long acc, const char* n, float bal) {
        account = acc;
        strcpy(name, n);
        balance = bal;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "saving ok!" << endl;
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "sorry! over limit!" << endl;
        } else {
            balance -= amount;
            cout << "withdraw ok!" << endl;
        }
    }

    void check() const {
        cout << name << "'s balance is " << fixed << setprecision(0) << balance << endl;
    }
};

int main() {

    long acc1;
    char name1[10];
    float balance1;
    float deposit1, withdraw1;

    cin >> acc1 >> name1 >> balance1;
    cin >> deposit1;
    cin >> withdraw1;

    CAccount account1(acc1, name1, balance1);

    account1.check();
    account1.deposit(deposit1);
    account1.check();
    account1.withdraw(withdraw1);
    account1.check();

    long acc2;
    char name2[10];
    float balance2;
    float deposit2, withdraw2;

    cin >> acc2 >> name2 >> balance2;
    cin >> deposit2;
    cin >> withdraw2;

    CAccount account2(acc2, name2, balance2);

    account2.check();
    account2.deposit(deposit2);
    account2.check();
    account2.withdraw(withdraw2);
    account2.check();

}
