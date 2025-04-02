#include <iostream>
#include <string>
using namespace std;

class Passenger;
class Bus;
class Company;

static int currentDay = 0;

class Stop {
private:
    int stopID;
    string stopName;

public:
    Stop(int id = 0, string name = "") : stopID(id), stopName(name) {}

    bool operator==(const Stop& other) const {
        return this->stopID == other.stopID;
    }

    int getStopID() const { return stopID; }
    string getStopName() const { return stopName; }
};

class Passenger {
protected:
    int ID;
    string name;
    bool cardActive;
    double feePaid;
    int lastPaymentDay;

public:
    Passenger(int id, string n) : ID(id), name(n), cardActive(false), feePaid(0), lastPaymentDay(0) {}
    virtual ~Passenger() {}

    virtual void registerForTransportation() = 0;
    virtual bool makePayment(double amount) = 0;
    virtual void checkFeeStatus() = 0;

    void tapCard() {
        if (cardActive) {
            cout << "Attendance recorded for " << name << " (ID: " << ID << ")" << endl;
        } else {
            cout << "Card inactive. Please complete payment and registration." << endl;
        }
    }

    bool isActive() const { return cardActive; }
    int getID() const { return ID; }
    string getName() const { return name; }

    virtual string getType() const = 0;

    static void incrementDay() {
        currentDay++;
        cout << "\n--- Day " << currentDay << " ---\n";
    }
};

class Student : public Passenger {
private:
    const int semesterFee = 60;
    const int paymentPeriod = 120;

public:
    Student(int id, string n) : Passenger(id, n) {}

    void registerForTransportation() override {
        if (cardActive) {
            cout << "Student " << name << " is already registered." << endl;
        } else {
            cout << name << " needs to pay semester fee before registration." << endl;
        }
    }

    void checkFeeStatus() override {
        int daysSincePayment = currentDay - lastPaymentDay;
        if (daysSincePayment > paymentPeriod) {
            cout << "ALERT: " << name << "'s transport service expired "
                 << (daysSincePayment - paymentPeriod) << " days ago. Please renew!" << endl;
            cardActive = false;
        } else {
            int daysRemaining = paymentPeriod - daysSincePayment;
            cout << name << "'s service is active. " << daysRemaining
                 << " days remaining in payment period." << endl;
        }
    }

    bool makePayment(double amount) override {
        feePaid += amount;
        lastPaymentDay = currentDay;
        if (feePaid >= semesterFee) {
            cardActive = true;
            cout << "Semester fee paid. Card activated for " << name << endl;
            return true;
        }
        cout << "Insufficient payment. Remaining: " << (semesterFee - feePaid) << endl;
        return false;
    }

    string getType() const override { return "Student"; }
};

class Teacher : public Passenger {
private:
    const int monthlyFee = 30;
    const int paymentPeriod = 30;

public:
    Teacher(int id, string n) : Passenger(id, n) {}

    void registerForTransportation() override {
        if (cardActive) {
            cout << "Teacher " << name << " is already registered." << endl;
        } else {
            cout << name << " needs to pay monthly fee before registration." << endl;
        }
    }

    void checkFeeStatus() override {
        int daysSincePayment = currentDay - lastPaymentDay;
        if (daysSincePayment > paymentPeriod) {
            cout << "ALERT: " << name << "'s transport service expired "
                 << (daysSincePayment - paymentPeriod) << " days ago. Please renew!" << endl;
            cardActive = false;
        } else {
            int daysRemaining = paymentPeriod - daysSincePayment;
            cout << name << "'s service is active. " << daysRemaining
                 << " days remaining in payment period." << endl;
        }
    }

    bool makePayment(double amount) override {
        if (amount >= monthlyFee) {
            cardActive = true;
            feePaid = amount;
            lastPaymentDay = currentDay;
            cout << "Monthly fee paid. Card activated for " << name << endl;
            return true;
        }
        cout << "Insufficient payment. Required: " << monthlyFee << endl;
        return false;
    }

    string getType() const override { return "Teacher"; }
};

class Staff : public Passenger {
private:
    const int annualFee = 100;
    const int paymentPeriod = 365;

public:
    Staff(int id, string n) : Passenger(id, n) {}

    void registerForTransportation() override {
        if (cardActive) {
            cout << "Staff member " << name << " is already registered." << endl;
        } else {
            cout << name << " needs to pay annual fee before registration." << endl;
        }
    }

    void checkFeeStatus() override {
        int daysSincePayment = currentDay - lastPaymentDay;
        if (daysSincePayment > paymentPeriod) {
            cout << "ALERT: " << name << "'s transport service expired "
                 << (daysSincePayment - paymentPeriod) << " days ago. Please renew!" << endl;
            cardActive = false;
        } else {
            int daysRemaining = paymentPeriod - daysSincePayment;
            cout << name << "'s service is active. " << daysRemaining
                 << " days remaining in payment period." << endl;
        }
    }

    bool makePayment(double amount) override {
        if (amount >= annualFee) {
            cardActive = true;
            feePaid = amount;
            lastPaymentDay = currentDay;
            cout << "Annual fee paid. Card activated for " << name << endl;
            return true;
        }
        cout << "Insufficient payment. Required: " << annualFee << endl;
        return false;
    }

    string getType() const override { return "Staff"; }
};

class Bus {
private:
    string name;
    int id;
    int route;
    Stop* stops;
    int countStops;
    int maxStops;
    int capacity;
    Passenger** passengers;
    int passengerCount;

public:
    Bus() : name("unknown"), id(0), route(0), maxStops(0), capacity(0),
            countStops(0), passengerCount(0), stops(nullptr), passengers(nullptr) {}

    Bus(string n, int ID, int r, int m, int c) : 
        name(n), id(ID), route(r), maxStops(m), capacity(c),
        countStops(0), passengerCount(0) {
        stops = new Stop[maxStops];
        passengers = new Passenger*[capacity];
    }

    ~Bus() {
        delete[] stops;
        delete[] passengers;
    }

    void addStop(const Stop& stop) {
        if (countStops < maxStops) {
            stops[countStops++] = stop;
            cout << "Stop " << stop.getStopName() << " (ID: " << stop.getStopID()
                 << ") added to bus " << name << endl;
        } else {
            cout << "Cannot add more stops to bus " << name << endl;
        }
    }

    bool hasStop(const Stop& stop) const {
        for (int i = 0; i < countStops; i++) {
            if (stops[i] == stop) {
                return true;
            }
        }
        return false;
    }

    void assignPassenger(Passenger* passenger) {
        if (!passenger) {
            cout << "Error: Null passenger pointer" << endl;
            return;
        }

        if (passengerCount < capacity) {
            passengers[passengerCount++] = passenger;
            cout << passenger->getType() << " " << passenger->getName()
                 << " assigned to bus " << name << endl;
        } else {
            cout << "Bus " << name << " is at full capacity." << endl;
        }
    }

    int getNumberOfStops() const { return countStops; }
    Stop* getStops() const { return stops; }
    string getName() const { return name; }
    int getRoute() const { return route; }
};

class Company {
private:
    string name;
    Passenger** passengers;
    Bus** buses;
    int passengerCount;
    int maxPassengers;
    int busCount;
    int maxBuses;

public:
    Company(string n, int maxP, int maxB) : 
        name(n), maxPassengers(maxP), maxBuses(maxB),
        passengerCount(0), busCount(0) {
        passengers = new Passenger*[maxPassengers];
        buses = new Bus*[maxBuses];
    }

    ~Company() {
        for (int i = 0; i < passengerCount; i++) {
            delete passengers[i];
        }
        for (int i = 0; i < busCount; i++) {
            delete buses[i];
        }
        delete[] passengers;
        delete[] buses;
    }

    void addPassenger(Passenger* p) {
        if (!p) {
            cout << "Error: Null passenger pointer" << endl;
            return;
        }

        if (passengerCount < maxPassengers) {
            passengers[passengerCount++] = p;
            cout << p->getType() << " " << p->getName() << " added to system." << endl;
        } else {
            cout << "Cannot add more passengers. System full." << endl;
        }
    }

    void addBus(Bus* bus) {
        if (busCount < maxBuses) {
            buses[busCount++] = bus;
            cout << bus->getName() << " added to company." << endl;
        } else {
            cout << "Cannot add more buses. Company at capacity." << endl;
        }
    }

    void addPassengerToBus(Passenger* p, const Stop& stop) {
        if (!p) {
            cout << "Error: Null passenger pointer" << endl;
            return;
        }

        for (int i = 0; i < busCount; i++) {
            if (buses[i]->hasStop(stop)) {
                buses[i]->assignPassenger(p);
                return;
            }
        }
        cout << "No bus found stopping at " << stop.getStopName() << " for "
             << p->getType() << " " << p->getName() << endl;
    }
};

int main() {
    Company company("FAST Transportation", 50, 10);

    Stop mainGate(1, "Main Gate");
    Stop library(2, "Library");
    Stop facultyBuilding(3, "Faculty Building");
    Stop adminBlock(4, "Admin Block");

    Bus* bus1 = new Bus("Campus Shuttle", 1, 101, 10, 30);
    bus1->addStop(mainGate);
    bus1->addStop(library);
    bus1->addStop(facultyBuilding);

    Bus* bus2 = new Bus("City Route", 2, 102, 5, 40);
    bus2->addStop(mainGate);
    bus2->addStop(adminBlock);

    company.addBus(bus1);
    company.addBus(bus2);

    Student* student1 = new Student(1, "John Doe");
    Teacher* teacher1 = new Teacher(101, "Dr. Smith");
    Staff* staff1 = new Staff(1001, "Mr. Johnson");

    company.addPassenger(student1);
    company.addPassenger(teacher1);
    company.addPassenger(staff1);

    cout << "\n--- Initial Setup (Day 0) ---\n";
    student1->makePayment(60);
    teacher1->makePayment(30);
    staff1->makePayment(100);

    company.addPassengerToBus(student1, mainGate);
    company.addPassengerToBus(teacher1, facultyBuilding);
    company.addPassengerToBus(staff1, adminBlock);

    student1->tapCard();
    teacher1->tapCard();
    staff1->tapCard();

    currentDay = 15;
    cout << "\n--- Day 15 Check ---\n";
    teacher1->checkFeeStatus();
    staff1->checkFeeStatus();

    currentDay = 31;
    cout << "\n--- Day 31 Check ---\n";
    teacher1->checkFeeStatus();
    teacher1->tapCard();
    teacher1->makePayment(30);
    teacher1->tapCard();

    currentDay = 100;
    cout << "\n--- Day 100 Check ---\n";
    teacher1->checkFeeStatus();
    staff1->checkFeeStatus();

    delete student1;
    delete teacher1;
    delete staff1;
    delete bus1;
    delete bus2;

    return 0;
}
