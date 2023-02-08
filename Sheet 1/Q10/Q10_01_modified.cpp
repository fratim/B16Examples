#include <iostream>
using namespace std;

class X // does not hold any variables and always evaluates to 1
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

class Prod : public X
{
public:
    Prod(X &x1, X &x2) : arg1(x1), arg2(x2) {}
    double Eval()
    {
        return arg1.Eval() * arg2.Eval();
    }

private:
    X &arg1;
    X &arg2;
};

class Neg : public X
{
public:
    Neg(double v) : val(v) {}
    double Eval() { return -val; }

private:
    double val;
};


int main(){
    Neg a(2.5), b(3.0), c(10.0);
    Prod d(a, b);
    Prod e(d, c);
    a.PrintValue();
    d.PrintValue();
    e.PrintValue();
}



// Solution

// int main(){
// 
    // Neg a(2.5), b(3.0), c(10.0);
    // Prod d(a, b); // holds 2.5 and 3
    // Prod e(d, c); // holds 7.5 and 10
    // a.PrintValue(); -2.5
    // d.PrintValue(); 7.5
    // e.PrintValue(); -75
// }