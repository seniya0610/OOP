#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double a, string c, string s, double r)
        : amount(a), currencyCode(c), currencySymbol(s), exchangeRate(r) {}

    virtual double convertToBase() {
        return amount * exchangeRate;
    }

    virtual double convertTo(double targetRate) {
        // Convert to target currency: (amount * exchangeRate) / targetRate
        return (amount * exchangeRate) / targetRate;
    }

    virtual void displayCurrency() {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() override {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.08) {} // 1 EUR = 1.08 USD

    void displayCurrency() override {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs", 0.0036) {} // 1 PKR = 0.0036 USD

    void displayCurrency() override {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

int main() {
    Dollar usd(100.0);
    Euro eur(100.0);
    Rupee pkr(100.0);

    usd.displayCurrency();
    cout << "Converted to base (USD): $" << usd.convertToBase() << endl;

    eur.displayCurrency();
    cout << "Converted to base (USD): $" << eur.convertToBase() << endl;
    cout << "Converted to PKR: Rs " << eur.convertTo(0.0036) << endl; // Convert EUR to PKR

    pkr.displayCurrency();
    cout << "Converted to base (USD): $" << pkr.convertToBase() << endl;
    cout << "Converted to EUR: €" << pkr.convertTo(1.08) << endl; // Convert PKR to EUR

    return 0;
}
