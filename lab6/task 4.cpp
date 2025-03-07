#include <iostream>
using namespace std;

class Account
{
private:
    int num;
    float balance;

public:
    Account(int n, float b)
    {
        num = n;
        balance = b;
    }

    void DisplayDetails() const
    {
        cout << "Account Number: " << num << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account
{
private:
    float InterestRate;

public:
    SavingsAccount(int n, float b, float i) : Account(n, b), InterestRate(i) {}

    void DisplayDetails() const
    {
        Account ::DisplayDetails();
        cout << "Interest Rate: " << InterestRate << endl;
    }
};

class CheckingAccount : public Account
{
private:
    float OverDraftLimit;

public:
    CheckingAccount(int n, float b, float odl) : Account(n, b), OverDraftLimit(odl) {}
    void DisplayDetails() const
    {
        Account ::DisplayDetails();
        cout << "Over draft limit: " << OverDraftLimit << endl;
    }
};

int main()
{
    SavingsAccount s(1, 5000, 5);
    CheckingAccount c(2, 6000, 10);
    s.DisplayDetails();
    c.DisplayDetails();
}
