#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class CBook {
private:
    string name;
    string editor;
    double price;
    string publisher;
public:
    CBook() {}
    
    friend istream& operator>>(istream& is, CBook& book) {
        string line;
        is >> ws;
        getline(is, line);
        
        size_t pos1 = line.find(',');
        book.name = line.substr(0, pos1);
        
        size_t pos2 = line.find(',', pos1 + 1);
        book.editor = line.substr(pos1 + 1, pos2 - pos1 - 1);
        
        size_t pos3 = line.find(',', pos2 + 1);
        string priceStr = line.substr(pos2 + 1, pos3 - pos2 - 1);
        book.price = stod(priceStr);
        
        book.publisher = line.substr(pos3 + 1);
        
        return is;
    }
    
    friend ostream& operator<<(ostream& os, const CBook& book) {
        os << book.name << endl;
        os << book.editor << endl;
        os << fixed << setprecision(2) << book.price << endl;
        os << book.publisher;
        return os;
    }
    
    double getPrice() const {
        return price;
    }
    
    friend void find(CBook *book, int n, int &max1index, int &max2index);
};

void find(CBook *book, int n, int &max1index, int &max2index) {
    max1index = 0;
    max2index = -1;
    
    for (int i = 1; i < n; i++) {
        if (book[i].getPrice() > book[max1index].getPrice()) {
            max2index = max1index;
            max1index = i;
        } else if (book[i].getPrice() == book[max1index].getPrice()) {
            continue;
        } else if (max2index == -1 || book[i].getPrice() > book[max2index].getPrice()) {
            max2index = i;
        }
    }
    
    if (max2index == -1) {
        max2index = (max1index == 0) ? 1 : 0;
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        CBook* books = new CBook[n];
        
        for (int i = 0; i < n; i++) {
            cin >> books[i];
        }
        
        int max1, max2;
        find(books, n, max1, max2);
        
        cout << books[max1] << endl;
        cout << endl;
        cout << books[max2] << endl;
        if (t > 0) cout << endl;
    }
    
    return 0;
}
