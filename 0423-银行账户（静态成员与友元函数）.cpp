#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Account {
public:
    Account(string accno, string name, float balance);
    ~Account();
    void Deposit(float amount);
    void Withdraw(float amount);
    float GetBalance();
    void Show();
    static int GetCount();
    static float GetInterestRate();
    static void SetInterestRate(float rate);
    friend void Update(Account& a);
    
private:
    static int count;
    static float InterestRate;
    string _accno, _accname;
    float _balance;
};

int Account::count = 0;
float Account::InterestRate = 0;

Account::Account(string accno, string name, float balance) {
    _accno = accno;
    _accname = name;
    _balance = balance;
    count++;
}

Account::~Account() {
    count--;
}

void Account::Deposit(float amount) {
    _balance += amount;
}

void Account::Withdraw(float amount) {
    _balance -= amount;
}

float Account::GetBalance() {
    return _balance;
}

void Account::Show() {
    cout << _accno << " " << _accname << " " << _balance;
}

int Account::GetCount() {
    return count;
}

float Account::GetInterestRate() {
    return InterestRate;
}

void Account::SetInterestRate(float rate) {
    InterestRate = rate;
}

void Update(Account& a) {
    a._balance = a._balance + a._balance * Account::GetInterestRate();
}

int main() {
    float rate;
    cin >> rate;
    Account::SetInterestRate(rate);
    
    int n;
    cin >> n;
    
    Account** accounts = new Account*[n];
    float total = 0;
    
    for (int i = 0; i < n; i++) {
        string accno, name;
        float balance, deposit, withdraw;
        cin >> accno >> name >> balance >> deposit >> withdraw;
        
        accounts[i] = new Account(accno, name, balance);
        accounts[i]->Deposit(deposit);
        cout << accno << " " << name << " " << accounts[i]->GetBalance() << " ";
        
        Update(*accounts[i]);
        cout << accounts[i]->GetBalance() << " ";
        
        accounts[i]->Withdraw(withdraw);
        cout << accounts[i]->GetBalance() << endl;
        
        total += accounts[i]->GetBalance();
    }
    
    cout << total << endl;
    
    for (int i = 0; i < n; i++) {
        delete accounts[i];
    }
    delete[] accounts;
    
    return 0;
}
