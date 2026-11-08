#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class TravelCard {
protected:
    int travel_id;
    int travel_points;
public:
    TravelCard(int id) : travel_id(id), travel_points(0) {}
    void addTravelPoints(int amount) {
        travel_points += amount;
    }
    int getTravelId() { return travel_id; }
    int getTravelPoints() { return travel_points; }
};

class CreditCard {
protected:
    int card_id;
    string name;
    int limit;
    float bill;
    int credit_points;
public:
    CreditCard(int cid, string n, int lim) : card_id(cid), name(n), limit(lim), bill(0), credit_points(0) {}
    
    bool consume(float m) {
        if (bill + m > limit) {
            return false;
        }
        bill += m;
        credit_points += (int)m;
        return true;
    }
    
    void refund(float m) {
        bill -= m;
        credit_points -= (int)m;
    }
    
    void addCreditPoints(int points) {
        credit_points += points;
    }
    
    int getCardId() { return card_id; }
    string getName() { return name; }
    float getBill() { return bill; }
    int getCreditPoints() { return credit_points; }
};

class TravelCreditCard : public TravelCard, public CreditCard {
public:
    TravelCreditCard(int tid, int cid, string n, int lim) 
        : TravelCard(tid), CreditCard(cid, n, lim) {}
    
    void order(float m) {
        addTravelPoints((int)m);
        consume(m);
    }
    
    void exchange(int points) {
        if (points <= credit_points) {
            credit_points -= points;
            travel_points += points / 2;
        }
    }
    
    void display() {
        cout << travel_id << " " << travel_points << endl;
        cout << card_id << " " << name << " " << fixed << setprecision(1) << bill << " " << credit_points << endl;
    }
};

int main() {
    int travel_id, card_id, limit;
    string name;
    cin >> travel_id >> card_id >> name >> limit;
    
    TravelCreditCard tcc(travel_id, card_id, name, limit);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        char op;
        float m;
        cin >> op >> m;
        
        if (op == 'o') {
            tcc.order(m);
        } else if (op == 'c') {
            tcc.consume(m);
        } else if (op == 'q') {
            tcc.refund(m);
        } else if (op == 't') {
            tcc.exchange((int)m);
        }
    }
    
    tcc.display();
    
    return 0;
}
