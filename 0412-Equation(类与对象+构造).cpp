#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Equation {
private:
    double a, b, c;
public:
    Equation();
    Equation(double a_val, double b_val, double c_val);
    void set(double a_val, double b_val, double c_val);
    void getRoot();
};

Equation::Equation()
{
    a = 1;
    b = 1;
    c = 0;
}

Equation::Equation(double a_val, double b_val, double c_val)
{
    a = a_val;
    b = b_val;
    c = c_val;
}

void Equation::set(double a_val, double b_val, double c_val)
{
    a = a_val;
    b = b_val;
    c = c_val;
}

void Equation::getRoot()
{
    double delta = b * b - 4 * a * c;
    
    if (delta > 1e-6)
    {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
//        if (x1 > x2)
//        {
//            swap(x1, x2);
//        }
        cout << fixed << setprecision(2) << "x1=" << x1 << " x2=" << x2 << endl;
    }
    else if (fabs(delta) < 1e-6)
    {
        double x = -b / (2 * a);
        cout << fixed << setprecision(2) << "x1=x2=" << x << endl;
    }
    else
    {
        double real = -b / (2 * a);
        double imag = sqrt(-delta) / (2 * a);
        cout << fixed << setprecision(2) << "x1=" << real << "+" << imag << "i x2=" << real << "-" << imag << "i" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        double a, b, c;
        cin >> a >> b >> c;
        Equation eq(a, b, c);
        eq.getRoot();
    }

}

