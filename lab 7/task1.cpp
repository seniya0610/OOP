#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    string accountNumber;
    string accountHolderName;
    double balance;
    string accountType;

public:
    Account(string an, string ah, double b = 0.0, string Type = "")
        : accountNumber(an), accountHolderName(ah), balance(b), accountType(Type) {}

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
        else
        {
            cout << "Invalid amount" << endl;
        }
    }

    virtual void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "error" << endl;
        }
    }

    virtual double calculateInterest()
    {
        return 0.0;
    }

    virtual void printStatement()
    {
        cout << accountNumber << endl;
        cout << accountHolderName << endl;
        cout << balance << endl;
        cout << accountType << endl;
    }

    void getAccountInfo()
    {
        printStatement();
    }

    ~Account() {}
};

class SavingsAccount : public Account
{
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string an, string ah, double b, double rate, double minBal)
        : Account(an, ah, b, "S"), interestRate(rate), minimumBalance(minBal) {}

    double calculateInterest() override
    {
        return balance * interestRate / 100;
    }
    void printStatement() override
    {
        Account::printStatement();
        cout << interestRate << endl;
        cout << minimumBalance << endl;
    }

    void withdraw(double amount) override
    {
        if (balance - amount >= minimumBalance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Cannot withdraw" << endl;
        }
    }
};

class CheckingAccount : public Account
{
private:
    double interestRate;
    double minimumBalance;

public:
    CheckingAccount(string an, string ah, double b, double rate, double minBal)
        : Account(an, ah, b, "C"), interestRate(rate), minimumBalance(minBal) {}

    double calculateInterest() override
    {
        return balance * interestRate / 100;
    }
    void printStatement() override
    {
        Account::printStatement();
        cout << interestRate << endl;
        cout << minimumBalance << endl;
    }

    void withdraw(double amount) override
    {
        if (balance - amount >= minimumBalance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Cannot withdraw" << endl;
        }
    }
};

class FixedDepositAccount : public Account
{
private:
    string maturityDate;
    double fixedInterestRate;

public:
    FixedDepositAccount(string an, string ah, double b, string matDate, double fixRate)
        : Account(an, ah, b, "FD"), maturityDate(matDate), fixedInterestRate(fixRate) {}

    double calculateInterest() override
    {
        return balance * fixedInterestRate / 100;
    }

    void printStatement() override
    {
        Account::printStatement();
        cout << maturityDate << endl;
        cout << fixedInterestRate << endl;
    }

    void withdraw(double amount) override
    {
        cout << "Withdrawals not allowed before maturity in Fixed Deposit Account" << endl;
    }
};

int main()
{
    SavingsAccount savings("SA123", "Alice", 5000.0, 3.5, 1000.0);
    CheckingAccount checking("CA456", "Bob", 3000.0, 5.0, 1000.0);
    FixedDepositAccount fixedDeposit("FD789", "Charlie", 1000.0, "2025-12-31", 6.0);

    savings.deposit(1000);
    savings.withdraw(2000);
    cout << "Interest: " << savings.calculateInterest() << endl;
    savings.printStatement();

    checking.deposit(500);
    checking.withdraw(4000); // Should show insufficient funds
    checking.printStatement();

    fixedDeposit.deposit(2000);
    fixedDeposit.withdraw(5000); // Withdrawals not allowed
    cout << "Interest: " << fixedDeposit.calculateInterest() << endl;
    fixedDeposit.printStatement();

    return 0;
}
