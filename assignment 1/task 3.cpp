#include <iostream>
#include <string.h>
using namespace std;

class User
{

private:
    int ID;
    string name;
    int age;
    string license;
    long long int contact_no;

public:
    User()
    {
        ID = 0000;
        name = "Full Name";
        age = 0;
        license = "Define Category";
        contact_no = 99999999999;
    }
    User(int id, string n, int a, string l, long long c)
    {
        ID = id;
        name = n;
        age = a;
        contact_no = c;
        license = l;
    }

    void display()
    {
        cout << "Details for the users:" << endl
             << "ID: " << ID << endl
             << "Name: " << name << endl
             << "Age: " << age << endl
             << "License Category: " << license << endl
             << "Contact Details: " << contact_no << endl;
    }

    void updateID(int id) { ID = id; }
    void updateName(string n) { name = n; }
    void updateAge(int a) { age = a; }
    void updateContantDetails(long long c) { contact_no = c; }
    void updateLiincese(int l) { license = l; }

    int getID() { return ID; }
    string getName() { return name; }
    int getAge() { return age; }
    string getLicense() { return license; }
    long long getContactDetails() { return contact_no; }
};

class Vehicle
{
private:
    string model;
    double rentalPrice;
    string eligibility;

public:
    Vehicle()
    {
        model = "";
        rentalPrice = 0.0;
        eligibility = "";
    }

    Vehicle(string m, double rp, string e)
    {
        model = m;
        rentalPrice = rp;
        eligibility = e;
    }

    void displayVehicle()
    {
        cout << "Model: " << model << endl;
        cout << "Rental Price: $" << rentalPrice << " per day" << endl;
        cout << "Eligibility: " << eligibility << " license required" << endl;
    }

    string getModel() { return model; }
    double getRentalPrice() { return rentalPrice; }
    string getEligibility() { return eligibility; }
};

class Company
{
private:
    User *userList;
    int Ucount;
    int maxUsers;
    Vehicle *carList;
    int Ccount;
    int maxC;

public:
    Company(int m1, int m2)
    {
        maxUsers = m1;
        Ucount = 0;
        maxC = m2;
        Ccount = 0;
        userList = new User[maxUsers];
        carList = new Vehicle[maxC];
    }

    ~Company()
    {
        delete[] userList;
        delete[] carList;
    }

    void addUser(User user)
    {
        if (Ucount < maxUsers)
        {
            userList[Ucount] = user;
            Ucount++;
            cout << "User added successfully!" << endl;
        }
        else
        {
            cout << "User list is full!" << endl;
        }
    }

    void addVehicle(Vehicle vehicle)
    {
        if (Ccount < maxC)
        {
            carList[Ccount] = vehicle;
            Ccount++;
            cout << "Vehicle added successfully!" << endl;
        }
        else
        {
            cout << "Vehicle list is full!" << endl;
        }
    }

    void displayUsers()
    {
        for (int i = 0; i < Ucount; i++)
        {
            cout << "User " << i << ": " << endl;
            userList[i].display();
            cout << endl;
        }
    }

    void displayVehicles()
    {
        for (int i = 0; i < Ccount; i++)
        {
            cout << "Vehical " << i << ": " << endl;
            carList[i].displayVehicle();
            cout << endl;
        }
    }

    void rentVehicle(int userID, string model)
    {
        bool founduser = false;
        User *user;
        for (int i = 0; i < Ucount; i++)
        {
            if (userID == userList->getID())
            {
                founduser = true;
                user = &userList[i];
                break;
            }
        }

        if (!founduser)
        {
            cout << "User not found!" << endl;
            return;
        }

        bool foundcar = false;
        Vehicle *Tcar;
        for (int i = 0; i < Ccount; i++)
        {
            if (carList[i].getModel() == model)
            {
                foundcar = true;
                Tcar = &carList[i];
                break;
            }
        }

        if (foundcar)
        {
            cout << "Car not found!" << endl;
            return;
        }

        if (user->getLicense() == Tcar->getEligibility())
        {
            cout << "Rental successful! " << user->getName() << " has rented the " << Tcar->getModel() << endl;
        }
        else
        {
            cout << "Not eligible." << endl;
        }
    }
};

int main()
{
    Company company(10, 10);

    User user1(1, "John Doe", 25, "Full", 1234567890);
    User user2(2, "Jane Smith", 22, "Learner", 9876543210);

    company.addUser(user1);
    company.addUser(user2);

    Vehicle car1("Toyota Corolla", 50.0, "Full");
    Vehicle car2("Honda Civic", 40.0, "Intermediate");
    Vehicle car3("Ford Fiesta", 30.0, "Learner");

    company.addVehicle(car1);
    company.addVehicle(car2);
    company.addVehicle(car3);

    cout << "Users:" << endl;
    company.displayUsers();
    cout << "Vehicles:" << endl;
    company.displayVehicles();

    company.rentVehicle(1, "Toyota Corolla");
    company.rentVehicle(2, "Ford Fiesta");   
    company.rentVehicle(1, "Ford Fiesta");

    return 0;
}
