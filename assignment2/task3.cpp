#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string name;
    static int IDGenerator;
    int ID;
    double Speed;
    int capacity;
    static int activeDeliveries;
    double energyEfficiency; // 100% = 1, 90% = 0.9

public:
    Vehicle(string n, double speed, int cap, double efficiency)
        : name(n), Speed(speed), capacity(cap), energyEfficiency(efficiency)
    {
        IDGenerator++;
        ID = IDGenerator;
    }

    void addDelivery()
    {
        activeDeliveries++;
    }

    virtual void calculateRoute(string destination)
    {
        cout << "Calculating optimal route to " << destination << endl;
    }

    double calculateTime(double distance)
    { // in km
        return distance / Speed;
    }

    virtual void move()
    {
        cout << "Moving" << endl;
    }

    void command(string c, string id)
    {
        cout << "Executing command to " << c << " package with id " << id << endl;
    }

    virtual void command(string c, string id, int urgency)
    {
        cout << "Executing: " << c << " for " << id << " (urgency: " << urgency << ")\n";
    }

    int getID() const { return ID; }
    double getSpeed() const { return Speed; }
    int getCapacity() const { return capacity; }
    double getEfficiency() const { return energyEfficiency; }
    static int getActiveDeliveries() { return activeDeliveries; }

    bool operator==(const Vehicle &obj) const
    {
        return (Speed == obj.Speed) &&
               (capacity == obj.capacity) &&
               (energyEfficiency == obj.energyEfficiency);
    }

    virtual void display() const
    {
        cout << "Vehicle Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Speed: " << Speed << " km/h" << endl;
        cout << "Capacity: " << capacity << " kg" << endl;
        cout << "Energy Efficiency: " << energyEfficiency * 100 << "%" << endl;
        cout << "Active Deliveries: " << activeDeliveries << endl;
    }

    friend int compareVehicles(const Vehicle &v1, const Vehicle &v2);

    ~Vehicle()
    {
        activeDeliveries--;
    }
};

int Vehicle::activeDeliveries = 0;
int Vehicle::IDGenerator = 1000;

class RamzanDrone : public Vehicle
{
public:
    RamzanDrone(string name) : Vehicle(name, 120.0, 5, 0.9) {}
    using Vehicle::command;

    void calculateRoute(string destination) override
    {
        cout << "Calculating Aerial route to " << destination << " via Ramzan Drone" << endl;
    }

    void move() override
    {
        cout << "Flying with iftar meals" << endl;
    }

    void command(string c, string id, int urgencyLevel) override
    {
        if (urgencyLevel > 5)
        {
            cout << "Executing command to " << c << " package with id " << id << " in turbo mode" << endl;
        }
        else
        {
            cout << "Adjusting priorities..." << endl;
        }
    }
    void display() const override
    {
        cout << endl;
        Vehicle::display();
        cout << "Type: Delivery Drone" << endl;
        cout << "Specialty: Iftar meals" << endl;
    }
};

class RamzanTimeShip : public Vehicle
{
public:
    RamzanTimeShip(string name) : Vehicle(name, 9999.0, 20, 0.7) {}
    using Vehicle::command;

    void calculateRoute(string destination) override
    {
        cout << "Calculating temporal route to " << destination << " with historical validation" << endl;
    }

    void move() override
    {
        cout << "Time-jumping with historical packages" << endl;
    }

    void command(string c, string id, int urgencyLevel) override
    {
        if (urgencyLevel > 5)
        {
            cout << "Validating historical consistency for package " << id << endl;
        }
        cout << "Executing time-sensitive delivery..." << endl;
    }
    void display() const override
    {
        cout << endl;
        Vehicle::display();
        cout << "Type: Time Ship" << endl;
        cout << "Specialty: Historical deliveries" << endl;
    }
};

class RamzanHyperPod : public Vehicle
{
public:
    using Vehicle::command;
    RamzanHyperPod(string name) : Vehicle(name, 300.0, 100, 0.8) {}

    void calculateRoute(string destination) override
    {
        cout << "Calculating hyperloop route to " << destination << endl;
    }

    void move() override
    {
        cout << "Speeding through underground tunnels with bulk supplies" << endl;
    }

    void display() const override
    {
        cout << endl;
        Vehicle::display();
        cout << "Type: Hyper Pod" << endl;
        cout << "Specialty: Bulk supplies" << endl;
    }
};

int compareVehicles(const Vehicle &v1, const Vehicle &v2)
{
    int betterCount = 0;

    if (v1.Speed > v2.Speed)
        betterCount++;
    if (v1.capacity > v2.capacity)
        betterCount++;
    if (v1.energyEfficiency > v2.energyEfficiency)
        betterCount++;

    if (betterCount >= 2)
    {
        cout << v1.getID() << " is better than " << v2.getID() << endl;
        return 1;
    }
    else if (betterCount == 1)
    {
        cout << "Vehicles are comparable" << endl;
        return 0;
    }
    else
    {
        cout << v2.getID() << " is better than " << v1.getID() << endl;
        return -1;
    }
}

int main()
{
    RamzanDrone drone("Fast Drone");
    RamzanTimeShip timeship("Time Master");
    RamzanHyperPod pod("Heavy Lifter");

    drone.addDelivery();
    drone.display();

    timeship.addDelivery();
    timeship.display();

    pod.addDelivery();
    pod.display();

    cout << "Route Simulation" << endl;
    drone.calculateRoute("Central Mosque");
    timeship.calculateRoute("Ancient Mosque");
    pod.calculateRoute("Community Center");
    cout << endl;

    cout << "Movenment Simulation" << endl;
    drone.move();
    timeship.move();
    pod.move();
    cout << endl;

    cout << "Command Simulation" << endl;
    drone.command("Deliver", "IFTAR-001");
    drone.command("Deliver", "IFTAR-002", 6);    // High urgency
    timeship.command("Deliver", "SEHRI-001", 4); // Low urgency
    pod.command("Deliver", "BULK-001");
    cout << endl;

    cout << "Vehicle Comparisons" << endl;
    cout << "Comparing Drone vs Timeship:" << endl;
    int result1 = compareVehicles(drone, timeship);
    cout << "\nComparing Timeship vs HyperPod:" << endl;
    int result2 = compareVehicles(timeship, pod);
    cout << "\nComparing HyperPod vs Drone:" << endl;
    int result3 = compareVehicles(pod, drone);
    cout << endl;

    cout << "Equal test" << endl;
    if (drone == timeship)
    {
        cout << "Drone and Timeship are equal in specs" << endl;
    }
    else
    {
        cout << "Drone and Timeship have different specs" << endl;
    }
    return 0;
}
