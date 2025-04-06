#include <iostream>
using namespace std;

class Currency
{
private:
    string name;
    float money;

public:
    Currency(string s, float m) : name(s), money(m) {}

    Currency operator-() const
    {
        return Currency(name, -money);
    }

    Currency operator+(const Currency &c) const
    {
        return Currency(name, money + c.money);
    }

    Currency operator-(const Currency &c) const
    {
        return Currency(name, money - c.money);
    }

    Currency operator+=(const Currency &c)
    {
        money += c.money;
        return *this;
    }

    Currency operator-=(const Currency &c)
    {
        money -= c.money;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Currency &c);
};

ostream &operator<<(ostream &os, const Currency &c)
{
    os << c.name << "." << c.money << endl;
    return os;
}

int main()
{
    Currency a("RPS", 100.0);
    Currency b("RPS", 50.0);

    cout << a + b;
    cout << a - b;

    a += b;
    cout << a;
    cout << a << b;

    return 0;
}
