#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(); // 缺省构造函数，设置实部与虚部为1
    Complex(double r, double i); // 有参构造函数
    Complex add(const Complex& c); // 加法运算
    Complex sub(const Complex& c); // 减法运算
    void print(); // 输出当前复数的值

private:
    double real;
    double imag;
};

// 缺省构造函数
Complex::Complex()
{
    real = 1;
    imag = 1;
}

// 有参构造函数
Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}

// 加法运算
Complex Complex::add(const Complex& c)
{
    Complex result;
    result.real = real + c.real;
    result.imag = imag + c.imag;
    return result;
}

// 减法运算
Complex Complex::sub(const Complex& c)
{
    Complex result;
    result.real = real - c.real;
    result.imag = imag - c.imag;
    return result;
}

// 输出当前复数的值
void Complex::print()
{
    if (real == 0 && imag == 0)
    {
        cout << 0;
    }
    else if (real == 0)
    {
        cout << imag << "i";
    }
    else if (imag == 0)
    {
        cout << real;
    }
    else
    {
        cout << real;
        if (imag == 1) {
        	cout << "+i";
		} 
        else if (imag > 0)
            cout << "+" << imag << "i";
        else
            cout << imag << "i";
    }
}

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        double r1, i1, r2, i2;
        cin >> r1 >> i1 >> r2 >> i2;
        
        Complex c1(r1, i1);
        Complex c2(r2, i2);
        
        Complex sum = c1.add(c2);
        Complex diff = c1.sub(c2);
        
        cout << "sum:";
        sum.print();
        cout << endl;
        
        cout << "remainder:";
        diff.print();
        cout << endl;
    }
    
    return 0;
}
