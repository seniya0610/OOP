#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom)
    {
        if (denominator == 0)
        {
            cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
            denominator = 1;
        }
    }

    Fraction operator+(const Fraction &f) const
    {
        int newnum = numerator * f.denominator + f.numerator * denominator;
        int newden = denominator * f.denominator;
        return Fraction(newnum, newden);
    }

    Fraction operator-(const Fraction &f) const
    {
        int newnum = numerator * f.denominator - f.numerator * denominator;
        int newden = denominator * f.denominator;
        return Fraction(newnum, newden);
    }

    Fraction operator*(const Fraction &f) const
    {
        return Fraction(numerator * f.numerator, denominator * f.denominator);
    }

    Fraction operator/(const Fraction &f) const
    {
        return Fraction(numerator * f.denominator, denominator * f.numerator);
    }

    friend ostream &operator<<(ostream &os, const Fraction &f);
};

ostream &operator<<(ostream &os, const Fraction &f)
{
    os << f.numerator << "/" << f.denominator;
    return os;
}

int main()
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    Fraction f3 = f1 + f2;
    cout << f3 << endl;

    Fraction f4 = f1 - f2;
    cout << f4 << endl;

    Fraction f5 = f1 * f2;
    cout << f5 << endl;

    Fraction f6 = f1 / f2;
    cout << f6 << endl;

    return 0;
}
