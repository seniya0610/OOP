#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int age;
    int date; // 05032024
public:
    Employee(string n, int a, int d) : name(n), age(a), date(d) {}

    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Date: " << date << endl;
    }
};

class Developer : virtual public Employee
{
private:
    string role;

public:
    Developer(string n, int a, int d, string r) : Employee(n, a, d)
    {
        cout << "Enter role (FD = frontend developer, BD = backend developer): ";
        if (validate(r))
        {
            this->role = r;
        }
        else
        {
            cout << "Invalid role. Assigning unknown." << endl;
            role = "unknown";
        }
    }

    bool validate(string role) const
    {
        return (role == "FD" || role == "BD");
    }

    void display() const
    {
        cout << "Role: " << role << endl;
    }
};

class Debugger : virtual public Employee
{
private:
    string role;

public:
    Debugger(string n, int a, int d, string r) : Employee(n, a, d)
    {
        cout << "Enter role (MD = Manual Debugger, AD = Auto debugger): ";
        if (validate(r))
        {
            this->role = r;
        }
        else
        {
            cout << "Invalid role. Assigning unknown." << endl;
            role = "unknown";
        }
    }

    bool validate(string role) const
    {
        return (role == "MD" || role == "AD");
    }

    void display() const
    {
        cout << "Role: " << role << endl;
    }
};

class TeamLead : public Debugger, public Developer
{
public:
    TeamLead(string n, int a, int d, string devRole, string debugRole)
        : Employee(n, a, d), Developer(n, a, d, devRole), Debugger(n, a, d, debugRole) {}

    void display() const
    {
        Employee::display();
        Developer::display();
        Debugger::display();
    }
};

int main()
{
    TeamLead lead("John Doe", 30, 05032024, "FD", "MD");
    lead.display();

    return 0;
}
