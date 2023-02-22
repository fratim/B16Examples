
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class Func
{
public:
    Func()
    {
    }
    Func(const Func &b)
    {
    }
    virtual bool hasDerivative() const
    {
        return false;
    }
    virtual double val(double x) const
    {
        return 0.0;
    }
    virtual double derivative(double x) const
    {
        return 0.0;
    }
};

class e_x_x_squared : public Func
{
public:
    e_x_x_squared() {}
    e_x_x_squared(const Func &b) {}

    bool hasDerivative() const
    {
        return true;
    }

    double val(double x) const
    {
        return exp(x) / (x * x);
    }

    double derivative(double x) const
    {
        return exp(x) / (x * x) - 2 * exp(x) / (x * x * x);
    };
};

class Minimiser
{
public:
    Minimiser(const Func &f, const double startX) : _f(f), _startX(startX)
    {
        double x = startX;
        double precision = numeric_limits<double>::infinity();
        int i = 0;
        if (f.hasDerivative())
        {
            while (precision > _endingPrecision && i++ < maxIters)
            {
                // the NR rule
                double step =
                    f.derivative(x) /
                    ((f.derivative(x) + f.derivative(x + dx)) / (dx));
                x = x - step;
                // if the derivative is zero we can stop
                precision = f.derivative(x);
                // print out convergence diagnostics
                if ((i-1) % 10000 == 0)
                    cout << " iter : " << i
                         << " precision : " << precision
                         << " x: " << x << endl;
            }
            cout << " iter : " << i
                         << " precision : " << precision
                         << " x: " << x << endl;

            _minimum = f.val(x);
            _minimumX = x;
        }
        else
        {
            cerr << "No derivative implementation , no minimisation !"
                 << endl;
            exit(-1);
        }
    }
    double Minimum() const
    {
        return _minimum;
    }
    double MinimumLocation() const
    {
        return _minimumX;
    }

private:
    Func _f;
    double _startX;
    double _minimum;
    double _minimumX;
    double dx = 0.001;
    double _endingPrecision = 0.001;
    double stepSize = 0.1;
    int maxIters = 1000000;
};

int main()
{
    e_x_x_squared func;
    Minimiser m(func, 10);

    cout << endl << "Terminated" << endl;
    cout << "Minimum is " << m. Minimum ();
    cout <<  " at " << m. MinimumLocation () << endl;
}


// show overview of method here
// https://en.wikipedia.org/wiki/Newton%27s_method_in_optimization


// show how method works here
// https://ardianumam.wordpress.com/2017/09/27/newtons-method-optimization-derivation-and-how-it-works/

// uses second order taylor expansion

