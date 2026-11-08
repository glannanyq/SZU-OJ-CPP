#include <iostream>
#include <string>
using namespace std;

class Media {
private:
    int type;
    string name;
    int price;
    int status;

public:
	
    void init(int t, const string& n, int p, int s) {
        type = t;
        name = n;
        price = p;
        status = s;
    }

    void print() const {

        string typeStr;
        switch (type) {
            case 1: typeStr = "BF"; break;
            case 2: typeStr = "CD"; break;
            case 3: typeStr = "VCD"; break;
            case 4: typeStr = "DVD"; break;
        }
        
        cout << typeStr << "[" << name << "]";
        if (status == 1) {
            cout << "rented" << endl;
        } else {
            cout << "not rented" << endl;
        }
    }

    void fee(int days) const {
        if (status == 0) {
            cout << "No rental" << endl;
        } else {
            int total = price * days;
            cout << "Rental: " << total << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int type, price, status, command;
        string name;

        cin >> type >> name >> price >> status;

        Media media;
        media.init(type, name, price, status);

        cin >> command;

        if (command == 0) {
            media.print();
        } else {
            media.print();
            media.fee(command);
        }
    }
    
    return 0;
}
