#include<iostream>
using namespace std;
class Pump {
	double quantity;
	double price;
    bool isEmpty;

public:
    Pump(double initial, double unitPrice) {
        quantity = initial;
        price = unitPrice;
        isEmpty = (quantity <= 0);
    }

    void refuel(double request) {
        if (isEmpty) {
            cout << "empty" << endl;
            return;
        }

        cout << fixed;
        printf("before: %g %g\n", quantity, price); 
        //cout << "before:" << quantity << " " << price << endl;

        double actual;
        double totalPrice;

        if (request <= quantity) {
            actual = request;
            quantity -= actual;
        } else {
            actual = quantity;
            quantity = 0;
        }

        totalPrice = actual * price;
        
		printf("%g %g\n", actual, totalPrice); 
        //cout << actual << " " << totalPrice << endl;
		printf("after: %g %g\n\n", quantity, price); 
        //cout << "after: " << quantity << " " << price << endl;

        if (quantity <= 0) {
            isEmpty = true;
        }
    }

    bool isEmptyStatus() const {
        return isEmpty;
    }
};

int main() {
    double initial, unitPrice;
    int t;
    cin >> initial >> unitPrice;

    Pump pump(initial, unitPrice);

    cin >> t;

    for (int i = 0; i < t; i++) {
        double request;
        cin >> request;

        pump.refuel(request);

        if (pump.isEmptyStatus()) {
        	cout << "empty" << endl; 
            break;
        }
    }
	return 0;
}
