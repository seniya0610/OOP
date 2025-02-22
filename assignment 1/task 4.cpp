#include <iostream>
#include <string>
using namespace std;

class Student;
class Bus;
class Company;

class Student
{
private:
    int ID;
    string name;
    int fee = 60;
    int payment = 0;
    bool Card = false;

public:
    Student()
    {
        ID = 0;
        name = "";
    }

    Student(int id, string n)
    {
        ID = id;
        name = n;
    }

    void registerForTransportation()
    {
        if (Card)
        {
            cout << "Student " << name << " (ID: " << ID << ") has registered for transportation." << endl;
        }
        else
        {
            cout << name << " Please complete payment before trying to register." << endl;
        }
    }

    bool paySemesterFee(double amount)
    {
        payment += amount;
        if (payment >= fee)
        {
            Card = true;
            cout << "Fee paid. Transportation card is now active for " << name << endl;
            return true;
        }
        else
        {
            cout << "Insufficient fee. Transportation card remains inactive for " << name << endl;
            return false;
        }
    }

    void tapCard()
    {
        if (Card)
        {
            cout << "Attendance has been recorded for: " << name << " (ID: " << ID << ")" << endl;
        }
        else
        {
            cout << "Transportation card is inactive. Please pay the semester fee." << endl;
        }
    }

    bool isActive() { return Card; }
    int getStudentID() { return ID; }
    string getName() { return name; }
};

class Bus
{
private:
    string name;
    int id;
    int route;
    string *stops;
    int countstops; // current count of stops
    int maxStops;   // max stops bus can handle
    int capacity;   // capacity of entire bus
    Student *students;
    int studentCount;

public:
    Bus()
    {
        name = "";
        id = 0;
        route = 0;
        maxStops = 0;
        stops = new string[maxStops];
        capacity = 0;
        countstops = 0;
        students = new Student[capacity];
        studentCount = 0;
    }

    Bus(string n, int ID, int r, int m, int c)
    {
        name = n;
        id = ID;
        route = r;
        capacity = c;
        maxStops = m;
        stops = new string[maxStops];
        countstops = 0;
        students = new Student[capacity];
        studentCount = 0;
    }

    ~Bus()
    {
        delete[] stops;
        delete[] students;
    }

    void addStop(string stop)
    {
        if (countstops < maxStops)
        {
            stops[countstops] = stop;
            countstops++;
            cout << "Stop " << stop << " added to bus " << name << endl;
        }
        else
        {
            cout << "Cannot add more stops to bus " << name << "." << endl;
        }
    }

    void assignStudent(Student student)
    {
        if (studentCount < capacity)
        {
            students[studentCount] = student;
            studentCount++;
            cout << "Student " << student.getName() << " assigned to bus " << name << endl;
        }
        else
        {
            cout << "Bus " << name << " is at full capacity. Cannot add more students." << endl;
        }
    }

    int getCapacity()
    {
        return capacity;
    }

    int GetNumberOfStops()
    {
        return countstops;
    }

    string *getStops()
    {
        return stops;
    }

    string getName(){
        return name;
    }
    void display()
    {
        cout << "Stops for bus " << name << ":" << endl;
        cout << "Route number " << route << endl;
        for (int i = 0; i < countstops; i++)
        {
            cout << " - " << stops[i] << endl;
        }
    }
};

class Company
{
private:
    string name;
    Student *studentArray;
    Bus *busArray;
    int studentCount; // current students in the company
    int maxS;         // max students company can handle
    int busCount;     // number of buses in the system currently
    int Bmax;         // max number of buses company can hold

public:
    Company(string n, int maxStudents, int maxBuses)
    {
        name = n;
        maxS = maxStudents;
        studentCount = 0;
        Bmax = maxBuses;
        busCount = 0;
        studentArray = new Student[maxS];
        busArray = new Bus[Bmax];
    }

    ~Company()
    {
        delete[] studentArray;
        delete[] busArray;
    }

    void addStudent(Student student)
    {
        if (studentCount < maxS)
        {
            studentArray[studentCount] = student;
            studentCount++;
            cout << "Student " << student.getName() << " added to the system." << endl;
        }
        else
        {
            cout << "Cannot add more students. Maximum capacity reached." << endl;
        }
    }

    void addStudentToBus(Student student, string stop)
    {
        for (int i = 0; i < busCount; i++)
        {
            for (int j = 0; j < busArray[i].GetNumberOfStops(); j++)
            {
                if (busArray[i].getStops()[j] == stop)
                {
                    busArray[i].assignStudent(student);
                    return;
                }
            }
        }
        cout << "No bus found stopping at " << stop << " for student " << student.getName() << endl;
    }

    void addBus(Bus bus)
    {
        if (busCount < Bmax)
        {
            busArray[busCount] = bus;
            busCount++;
            cout << bus.getName() << "(capacity = " << bus.getCapacity() << ") added to " << name << endl;
        }
        else
        {
            cout << "Cannot add more buses. Maximum capacity reached." << endl;
        }
    }

    void displayStudents()
    {
        cout << "Students in the system:" << endl;
        for (int i = 0; i < studentCount; i++)
        {
            cout << " - " << studentArray[i].getName() << " (ID: " << studentArray[i].getStudentID() << ")" << endl;
        }
    }

    void displayBuses()
    {
        cout << "Buses in the system:" << endl;
        for (int i = 0; i < busCount; i++)
        {
            busArray[i].display();
        }
    }
};

int main()
{
    Company company("weewoo", 10, 5);

    Student student1(1, "John Doe");
    Student student2(2, "Jane Smith");

    company.addStudent(student1);
    company.addStudent(student2);

    student1.paySemesterFee(60);
    student2.paySemesterFee(30);

    student1.registerForTransportation();
    student2.registerForTransportation();

    Bus bus1("Bus A", 1, 101, 5, 50);
    Bus bus2("Bus B", 2, 102, 5, 40);

    bus1.addStop("Main Gate");
    bus1.addStop("Library");
    bus2.addStop("Hostel");
    bus2.addStop("Cafeteria");

    company.addBus(bus1);
    company.addBus(bus2);

    company.displayStudents();
    company.displayBuses();

    company.addStudentToBus(student1, "Main Gate");
    company.addStudentToBus(student2, "Hostel");

    student1.tapCard();
    student2.tapCard();

    return 0;
}
