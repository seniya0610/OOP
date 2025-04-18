#include <iostream>
using namespace std;

class SmartDevice // Pure abstract Class
{
protected:
    bool status;

public:
    SmartDevice(bool s = false) : status(s) {}
    virtual ~SmartDevice() = default;

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string getStatus() = 0;
};

class LightBulb : public SmartDevice
{
private:
    int brightness; // in %

public:
    LightBulb() : SmartDevice(false), brightness(50) {}

    void turnOn() override
    {
        status = true;
        brightness = 57;
    }

    void turnOff() override
    {
        status = false;
    }

    string getStatus() override
    {
        if (status)
        {
            cout << "Light is ON. Brightness: " << brightness << "%" << endl;
            return "on";
        }
        else
        {
            cout << "Light is OFF" << endl;
            return "off";
        }
    }
};

class Thermostat : public SmartDevice
{
private:
    double temperature;

public:
    Thermostat() : SmartDevice(false), temperature(24.0) {}

    void turnOn() override
    {
        status = true;
        temperature = 22.0;
    }

    void turnOff() override
    {
        status = false;
    }

    string getStatus() override
    {
        if (status)
        {
            cout << "Thermostat is ON. Temperature: " << temperature << "C" << endl;
            return "on";
        }
        else
        {
            cout << "Thermostat is OFF" << endl;
            return "off";
        }
    }
};

int main(){
    Thermostat t;
    LightBulb l;

    l.turnOn();
    t.turnOn();

    l.getStatus();
    t.getStatus();
}
