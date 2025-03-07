#include <iostream>
using namespace std;

class Device
{
protected:
    int deviceID;
    bool status;

public:
    Device(int id, bool st) : deviceID(id), status(st) {}

    void displayDetails() const
    {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : virtual public Device
{
protected:
    float screenSize;

public:
    SmartPhone(int id, bool st, float size) : Device(id, st), screenSize(size) {}

    void displayDetails() const
    {
        cout << "Screen Size: " << screenSize << endl;
    }
};

class SmartWatch : virtual public Device
{
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int id, bool st, bool hrm) : Device(id, st), heartRateMonitor(hrm) {}

    void displayDetails() const
    {
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch
{
private:
    int stepCounter;

public:
    SmartWearable(int id, bool st, float size, bool hrm, int steps)
        : Device(id, st), SmartPhone(id, st, size), SmartWatch(id, st, hrm), stepCounter(steps) {}

    void displayDetails() const
    {
        Device::displayDetails();
        SmartPhone::displayDetails();
        SmartWatch::displayDetails();
        cout << "Step Counter: " << stepCounter << endl;
    }
};

int main()
{
    SmartWearable d(12345, true, 1.5, true, 8000);
    d.displayDetails();

    return 0;
}
