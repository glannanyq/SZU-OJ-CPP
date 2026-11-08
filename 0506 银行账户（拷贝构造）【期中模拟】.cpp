#include <bits/stdc++.h>
using namespace std;

class BankAccount {
private:
    int number;
    char type;
    double balance;
    double rate;

public:
    BankAccount(int num, char t, double bal, double r) 
	: number(num), type(t), balance(bal), rate(r) {}

    BankAccount(BankAccount& other) 
    : number(other.number), type(other.type), 
    balance(other.balance), rate(other.rate) {}

    void calculateInterest() {
        double interest = balance * rate;
        balance += interest;
        cout << "Account=" << number << "--sum=" << static_cast<int>(balance) << endl;
    }

    void query() {
        string typeStr = (type == 'P') ? "Person" : "Enterprise";
        cout << "Account=" << number << "--" << typeStr 
             << "--sum=" << static_cast<int>(balance) 
             << "--rate=" << fixed << setprecision(3) << rate << endl;
    }

    int getNumber() { return number; }
    char getType() { return type; }
    double getBalance() { return balance; }
    double getRate() { return rate; }

    void setNumber(int num) { number = num; }
    void setBalance(double bal) { balance = bal; }
    void setRate(double r) { rate = r; }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(int num, char t, double bal) 
    : BankAccount(num, t, bal, 0.005) {}
};

class FixedAccount : public BankAccount {
public:
    FixedAccount(CurrentAccount& current) 
    : BankAccount(current) {
        setNumber(current.getNumber() + 50000000);
        setRate(0.015);
    }
};

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int number;
        char type;
        double balance;
        char op, opFixed;

        cin >> number >> type >> balance;
        cin >> op >> opFixed;

        CurrentAccount current(number, type, balance);
        FixedAccount fixed(current);

        if (op == 'C') {
            current.calculateInterest();
        } else if (op == 'P') {
            current.query();
        }

        if (opFixed == 'C') {
            fixed.calculateInterest();
        } else if (opFixed == 'P') {
            fixed.query();
        }
    }

}
