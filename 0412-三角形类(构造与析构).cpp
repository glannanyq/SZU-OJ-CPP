#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class CTriangle {
private:
    double a, b, c;
    string type;
public:
    CTriangle(double x, double y, double z);
    ~CTriangle();
    double getArea();
    void print();
};

/********** Write your code here! **********/
CTriangle::CTriangle(double x, double y, double z)
{
    a = x;
    b = y;
    c = z;
    
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        type = "no triangle";
        return;
    }
    
    bool isEquilateral = (a == b && b == c);
    bool isIsosceles = (a == b || b == c || a == c);
    bool isRight = (fabs(a*a + b*b - c*c) < 1) ||
                   (fabs(a*a + c*c - b*b) < 1) ||
                   (fabs(b*b + c*c - a*a) < 1);
    
    if (isEquilateral)
    {
        type = "equilateral triangle";
    }
    else if (isIsosceles && isRight)
    {
        type = "isosceles right triangle";
    }
    else if (isRight)
    {
        type = "right triangle";
    }
    else if (isIsosceles)
    {
        type = "isosceles triangle";
    }
    else
    {
        type = "general triangle";
    }
}

CTriangle::~CTriangle()
{
    a = 0;
    b = 0;
    c = 0;
    type = "none";
}

double CTriangle::getArea()
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void CTriangle::print()
{
    cout << type;
    if (type != "no triangle")
    {
        cout << ", " << fixed << setprecision(1) << getArea();
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        double x, y, z;
        cin >> x >> y >> z;
        CTriangle tri(x, y, z);
        tri.print();
    }
    
    return 0;
}
/*******************************************/
