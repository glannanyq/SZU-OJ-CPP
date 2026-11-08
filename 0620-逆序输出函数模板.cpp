#include <bits/stdc++.h>
using namespace std;

class CComplex {
private:
    int real;
    int imag;
public:
    CComplex(int r = 0, int i = 0) : real(r), imag(i) {}
    
    operator string() const {
        ostringstream os;
        os << imag;
        if (real >= 0) os << "+";
        os << real;
        return os.str();
    }
    
    friend istream& operator>>(istream& is, CComplex& c) {
        is >> c.real >> c.imag;
        return is;
    }
};

template <typename T>
void reversePrint(T data) {
    ostringstream os;
    os << data;
    string s = os.str();
    reverse(s.begin(), s.end());
    cout << s << endl;
}

template <>
void reversePrint<int>(int data) {
    ostringstream os;
    os << data;
    string s = os.str();
    reverse(s.begin(), s.end());
    int i = 0;
    while (i < (int)s.size() - 1 && s[i] == '0') i++;
    s = s.substr(i);
    cout << s << endl;
}

template <>
void reversePrint<double>(double data) {
    ostringstream os;
    os << fixed << setprecision(10) << data;
    string s = os.str();
    while (s.size() > 0 && s[s.size()-1] == '0') {
        s.erase(s.size() - 1, 1);
    }
    if (s.size() > 0 && s[s.size()-1] == '.') {
        s.erase(s.size() - 1, 1);
    }
    
    if (s[0] == '-') {
        s = s.substr(1);
        reverse(s.begin(), s.end());
        s = "-" + s;
    } else {
        reverse(s.begin(), s.end());
    }
    
    if (s[0] == '-') {
        int i = 1;
        while (i < (int)s.size() - 1 && s[i] == '0' && s[i+1] != '.') i++;
        if (i > 1) s = "-" + s.substr(i);
    } else {
        int i = 0;
        while (i < (int)s.size() - 1 && s[i] == '0' && s[i+1] != '.') i++;
        if (i > 0) s = s.substr(i);
    }
    cout << s << endl;
}

template <>
void reversePrint<string>(string data) {
    reverse(data.begin(), data.end());
    cout << data << endl;
}

template <>
void reversePrint<CComplex>(CComplex data) {
    string s = (string)data;
    cout << s << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        char type;
        cin >> type;
        
        if (type == 'I') {
            int data;
            cin >> data;
            reversePrint(data);
        } else if (type == 'D') {
            double data;
            cin >> data;
            reversePrint(data);
        } else if (type == 'S') {
            string data;
            cin >> data;
            reversePrint(data);
        } else if (type == 'C') {
            CComplex data;
            cin >> data;
            reversePrint(data);
        }
    }
    
    return 0;
}
