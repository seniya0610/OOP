#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    static int nextEmployeeID;
    int EmployeeID;
    string EmployeeName;
    float salary;
    const float MAX_SALARY = 1000;

public:
    Employee()
    {
        EmployeeID = generateEmployeeID();
        EmployeeName = "";
        salary = 0;
    }

    Employee(float s, string n)
    {
        EmployeeID = generateEmployeeID();
        EmployeeName = n;
        salary = s;
    }

    static int generateEmployeeID()
    {
        return nextEmployeeID++;
    }

    void setName(string name)
    {
        EmployeeName = name;
    }

    void setSalary(float s)
    {
        if (s > MAX_SALARY)
        {
            salary = MAX_SALARY;
        }
        else
        {
            salary = s;
        }
    }

    void displayEmployeeInfo() const
    {
        cout << "Employee ID: " << EmployeeID << endl;
        cout << "Employee Name: " << EmployeeName << endl;
        cout << "Employee Salary: " << salary << endl;
    }
};

int Employee::nextEmployeeID = 1;

int main()
{
    Employee emp1(30, "hatim");
    Employee emp2(5000, "weewoo");
    emp1.displayEmployeeInfo();
    emp2.displayEmployeeInfo();
}
