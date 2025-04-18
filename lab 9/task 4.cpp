#include <iostream>
#include <string>
using namespace std;

class PaymentMethod
{
public:
    virtual bool processPayment(double amount) = 0; 
    virtual ~PaymentMethod() {}                     
};

class CreditCardPayment : public PaymentMethod
{
private:
    string cardNumber;
    string expiryDate;
    string cvv;

public:
    CreditCardPayment(const string &num, const string &exp, const string &c)
        : cardNumber(num), expiryDate(exp), cvv(c) {}

    bool processPayment(double amount) override
    {
        cout << "Processing credit card payment: $" << amount << endl;

        for (int i = cardNumber.length() - 4; i < cardNumber.length(); i++)
        {
            cout << cardNumber[i];
        }

        cout << "Expiry: " << expiryDate << endl;
        return true;
    }
};

class DigitalWalletPayment : public PaymentMethod
{
private:
    string walletType;
    string walletId;

public:
    DigitalWalletPayment(const string &type, const string &id)
        : walletType(type), walletId(id) {}

    bool processPayment(double amount) override
    {
        cout << "Processing " << walletType << " payment: $" << amount << endl;
        cout << "ID: " << walletId << endl;
        return true;
    }
};

int main()
{

    PaymentMethod *creditCard = new CreditCardPayment("1234567812345678", "12/25", "123");
    PaymentMethod *digitalWallet = new DigitalWalletPayment("PayPal", "user123");

    const double amount = 99.99;
    creditCard->processPayment(amount);
    digitalWallet->processPayment(amount);

    delete creditCard;
    delete digitalWallet;

    return 0;
}
