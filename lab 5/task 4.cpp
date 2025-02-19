#include <iostream>
using namespace std;

class Battery
{
private:
    string name;
    int capacity;

public:
    Battery()
    {
        name = " ";
        capacity = 0;
    }
    Battery(string n, int c)
    {
        name = n;
        capacity = c;
    }

    int getCapacity() const { return capacity; }
    string getname() const { return name; }
};

class SmartPhone
{
private:
    Battery B;
    string CompanyName;
    string model;

public:
    SmartPhone()
    {
        CompanyName = "";
        model = "";
        B = Battery();
    }

    SmartPhone(string n, string m, Battery b)
    {
        CompanyName = n;
        model = m;
        B = b;
    }

    void display()
    {
        cout << "Smartphone Company: " << CompanyName << endl;
        cout << "Smartphone Model: " << model << endl;
        cout << "    Battery Details: " << endl;
        cout << "    Name: " << B.getname() << endl;
        cout << "    Capacity: " << B.getCapacity() << "mAh" << endl;
    }
};

int main()
{
    Battery battery1("Lithium-Ion", 5000);
    SmartPhone phone1("Samsung", "Galaxy S22", battery1);
    phone1.display();
}
