#include <iostream>
using namespace std;

class Vehicle
{
private:
    string model;
    double rate;

public:
    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;
    string getModel() const { return model; }
    void setModel(string m) { model = m; }
    double getRate() const { return rate; }
    void setRate(double r) { rate = r; }
};

class VroomVroom : public Vehicle
{
public:
    VroomVroom(string m, double r)
    {
        setRate(r);
        setModel(m);
    }
    double getDailyRate() override
    {
        return getRate();
    }
    void displayDetails() override
    {
        cout << "Model: " << getModel() << endl;
        cout << "Daily rate: $" << getDailyRate() << endl;
    }
};

class Bike : public Vehicle
{
public:
    Bike(string m, double r)
    {
        setRate(r);
        setModel(m);
    }
    double getDailyRate() override
    {
        return getRate();
    }
    void displayDetails() override
    {
        cout << "Model: " << getModel() << endl;
        cout << "Daily rate: $" << getDailyRate() << endl;
    }
};

int main()
{
    // Create an object of VroomVroom
    VroomVroom car("Vroom Vroom 3000", 150.0);
    Bike bike("bikey", 100.0);
    bike.displayDetails();
    car.displayDetails();

    return 0;
}
