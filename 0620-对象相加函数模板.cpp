#include <iostream>
#include <string>
using namespace std;

class CClock {
private:
    int h, m, s;
public:
    CClock(int hour = 0, int minute = 0, int second = 0) : 
    h(hour), m(minute), s(second) {}
    
    CClock operator+(const CClock& other) const {
        int total_s = s + other.s;
        int total_m = m + other.m + total_s / 60;
        total_s %= 60;
        int total_h = h + other.h + total_m / 60;
        total_m %= 60;
        total_h %= 24;
        return CClock(total_h, total_m, total_s);
    }
    
    friend ostream& operator<<(ostream& os, const CClock& c) {
        os << c.h << " " << c.m << " " << c.s;
        return os;
    }
}; 

class CRmb {
private:
    int y, j, f;
public:
    CRmb(int yuan = 0, int jiao = 0, int fen = 0) : y(yuan), j(jiao), f(fen) {}
    
    CRmb operator+(const CRmb& other) const {
        int total_f = f + other.f;
        int total_j = j + other.j + total_f / 10;
        total_f %= 10;
        int total_y = y + other.y + total_j / 10;
        total_j %= 10;
        return CRmb(total_y, total_j, total_f);
    }
    
    friend ostream& operator<<(ostream& os, const CRmb& r) {
        os << r.y << " " << r.j << " " << r.f;
        return os;
    }
};

template <typename T>
T add(const T& a, const T& b, int base) {
    return a + b;
}

int main() {
    int h1, m1, s1;
    int h2, m2, s2;
    int y1, j1, f1;
    int y2, j2, f2;
    
    cin >> h1 >> m1 >> s1;
    cin >> h2 >> m2 >> s2;
    cin >> y1 >> j1 >> f1;
    cin >> y2 >> j2 >> f2;
    
    CClock c1(h1, m1, s1), c2(h2, m2, s2), c;
    c = add(c1, c2, 60);
    cout << c << endl;
    
    CRmb r1(y1, j1, f1), r2(y2, j2, f2), r;
    r = add(r1, r2, 10);
    cout << r << endl;

}
