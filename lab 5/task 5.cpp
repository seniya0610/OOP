#include <iostream>
using namespace std;

class TourGuide
{
private:
    string name;
    int experience; // in years
    string specialization;

public:
    TourGuide()
    {
        name = "";
        experience = 0;
        specialization = "";
    }

    TourGuide(string n, int e, string s)
    {
        name = n;
        experience = e;
        specialization = s;
    }

    string getName() const { return name; }
    string getSpecialization() const { return specialization; }
    int getExperience() const { return experience; }
};

class TravelAgency
{
private:
    string name;
    TourGuide *list;
    int count;
    int max = 100;

public:
    TravelAgency()
    {
        name = "";
        count = 0;
        list = new TourGuide[max];
    }

    TravelAgency(string s)
    {
        name = s;
        count = 0;
        list = new TourGuide[max];
    }

    void addGuide(TourGuide &guide)
    {
        if (count < max)
        {
            list[count] = guide;
            count++;
        }
        else
        {
            cout << "Cannot add more guides. List is full!" << endl;
        }
    }

    void display() const
    {
        cout << "Travel Agency: " << name << endl;
        cout << "Number of Tour Guides: " << count << endl;
        for (int i = 0; i < count; i++)
        {
            cout << endl;
            cout << "Tour Guide " << i + 1 << " Details: " << endl;
            cout << "Guide Name: " << list[i].getName() << endl;
            cout << "Experience: " << list[i].getExperience() << " years" << endl;
            cout << "Specialization: " << list[i].getSpecialization() << endl;
        }
    }

    ~TravelAgency()
    {
        delete[] list;
    }
};

int main()
{
    TravelAgency agency("World Explorer Tours");

    TourGuide guide1("Alice Johnson", 5, "Historical Tours");
    TourGuide guide2("Bob Smith", 8, "Adventure & Trekking");
    TourGuide guide3("Charlie Davis", 3, "Food & Culture");

    agency.addGuide(guide1);
    agency.addGuide(guide2);
    agency.addGuide(guide3);
    agency.display();

    return 0;
}
