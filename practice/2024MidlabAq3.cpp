#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    double balance;
    string creationDate;
    double lastWithdrawalAmount;

public:
    Account(double _balance, string _creationDate)
        : balance(_balance), creationDate(_creationDate), lastWithdrawalAmount(0) {}

    ~Account() {}

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            lastWithdrawalAmount = amount;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    double getBalance() const { return balance; }
    string getCreationDate() const { return creationDate; }
    double getLastWithdrawalAmount() const { return lastWithdrawalAmount; }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double _balance, string _creationDate)
        : Account(_balance, _creationDate) {}

    void calculateInsurancePremium() {
        if (balance >= 500 && lastWithdrawalAmount >= 0 && lastWithdrawalAmount <= 50) {
            cout << "Insurance premium calculated for Savings Account." << endl;
        } else {
            cout << "Insurance not available for this account." << endl;
        }
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double _balance, string _creationDate)
        : Account(_balance, _creationDate) {}
};

class BasicAccount : public Account {
public:
    BasicAccount(double _balance, string _creationDate)
        : Account(_balance, _creationDate) {}
};

int main() {
    // Create accounts
    SavingsAccount savings(1000, "2024-01-01");
    CheckingAccount checking(500, "2024-01-01");
    BasicAccount basic(200, "2024-01-01");

    // Perform withdrawals
    savings.withdraw(100);
    checking.withdraw(200);
    basic.withdraw(50);

    // Display account balances
    cout << "Savings Account Balance: " << savings.getBalance() << endl;
    cout << "Checking Account Balance: " << checking.getBalance() << endl;
    cout << "Basic Account Balance: " << basic.getBalance() << endl;

    // Calculate insurance premium for savings account
    savings.calculateInsurancePremium();

    return 0;
}
