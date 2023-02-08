#include <iostream>
using namespace std;

class X
{
public:
    virtual double Eval()
    {
        return 1.0;
    }
    void PrintValue()
    {
        cout << Eval() << endl;
    }
};

class Y : public X
{
public:
    Y(X &x1, X &x2) : arg1(x1), arg2(x2) {}
    double Eval()
    {
        return arg1.Eval() * arg2.Eval();
    }

private:
    X &arg1;
    X &arg2;
};

class Z : public X
{
public:
    Z(double v) : val(v) {}
    double Eval() { return -val; }

private:
    double val;
};


int main(){

    // Z a(2.5), b(3.0), c(10.0);
    // Y d(a, b);
    // Y e(d, c);
    // a.PrintValue();
    // d.PrintValue();
    // e.PrintValue();
    
}