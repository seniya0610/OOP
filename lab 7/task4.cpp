#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int id;
    string address;
    long long int PhoneNumber;
    string email;

public:
    Person(string n, int ID, string a, long long int pn, string e)
        : name(n), id(ID), address(a), PhoneNumber(pn), email(e) {}

    void setName(const string &n)
    {
        name = n;
    }

    void setId(int i)
    {
        id = i;
    }

    void setAddress(const string &addr)
    {
        address = addr;
    }

    void setPhoneNumber(long long int phone)
    {
        PhoneNumber = phone;
    }

    void setEmail(const string &e)
    {
        email = e;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << PhoneNumber << endl;
        cout << "Email: " << email << endl;
    }
};

int main()
{
    Person person;
    person.display();
    return 0;
}
