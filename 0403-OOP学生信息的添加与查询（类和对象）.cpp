#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
private:
    int zi;
    int mu;

public:
	int getGCD(int a, int b) {
	    a = abs(a);
	    b = abs(b);
	    while (b != 0) {
	        int temp = b;
	        b = a % b;
	        a = temp;
	    }
	    return a;
	}

	void simplify(Fraction &f) {
	    if (f.mu == 0) return;
	
	    if (f.mu < 0) {
	        f.zi = -f.zi;
	        f.mu = -f.mu;
	    }
	    
	    int gcd = getGCD(f.zi, f.mu);
	    f.zi /= gcd;
	    f.mu /= gcd;
	}

	void printFS(const Fraction &f) {
	    cout << f.zi << "/" << f.mu;
	}
	
	Fraction addFS(const Fraction &a, const Fraction &b) {
	    Fraction result;
	    result.zi = a.zi * b.mu + b.zi * a.mu;
	    result.mu = a.mu * b.mu;
	    simplify(result);
	    return result;
	}
};

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        Fraction f1, f2;
      
        cin >> f1.zi >> f1.mu;
        cin >> f2.zi >> f2.mu;

        Fraction result;

        result = addFS(f1, f2);
        printFS(result);
        cout << endl;

    }

}
