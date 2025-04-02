#include <iostream>
using namespace std;

class HauntedHouse;
class Ghost;
class Visitor;

class Ghost
{
protected:
    string Name;
    int scarelevel;

public:
    Ghost(string n, int s) : Name(n), scarelevel(s)
    {
        if (s < 1 || s > 10)
        {
            scarelevel = 5;
        }
    }

    virtual ~Ghost() {}

    virtual void haunt() const
    {
        cout << Name << " appears as a generic ghost!" << endl;
    }

    Ghost operator+(const Ghost &obj) const
    {
        string newName = Name + " & " + obj.Name;
        int newScarelevel = scarelevel + obj.scarelevel;
        if (newScarelevel > 10)
        {
            newScarelevel = 10;
        }
        return Ghost(newName, newScarelevel);
    }

    int getScareLevel() const { return scarelevel; }
    string getWorkerName() const { return Name; }

    friend ostream &operator<<(ostream &c, const Ghost &ghost);
};

class Poltergeist : virtual public Ghost
{
public:
    Poltergeist(string name, int scare) : Ghost(name, scare) {}

    void haunt() const override
    {
        cout << "Poltergeist (" << Name << ") moves objects around the room!" << endl;
    }

    friend ostream &operator<<(ostream &c, const Ghost &ghost);
};

class Banshee : public Ghost
{
public:
    Banshee(string name, int scare) : Ghost(name, scare) {}

    void haunt() const override
    {
        cout << "Banshee (" << Name << ") lets out a piercing scream!" << endl;
    }

    friend ostream &operator<<(ostream &c, const Ghost &ghost);
};

class ShadowGhost : virtual public Ghost
{
public:
    ShadowGhost(string name, int scare) : Ghost(name, scare) {}

    void haunt() const override
    {
        cout << "ShadowGhost (" << Name << ") whispers creepy things in your ear!" << endl;
    }

    friend ostream &operator<<(ostream &c, const Ghost &ghost);
};

class ShadowPoltergeist : public ShadowGhost, public Poltergeist
{
public:
    ShadowPoltergeist(string name, int scare) : Ghost(name, scare), ShadowGhost(name, scare), Poltergeist(name, scare) {}

    void haunt() const override
    {
        ShadowGhost::haunt();
        Poltergeist::haunt();
    }

    friend ostream &operator<<(ostream &c, const Ghost &ghost);
    int getScareLevel() const
    {
        if ((ShadowGhost::getScareLevel() + Poltergeist::getScareLevel()) > 10)
        {
            return 10;
        }
        else
        {
            return (ShadowGhost::getScareLevel() + Poltergeist::getScareLevel());
        }
    }
};

ostream &operator<<(ostream &c, const Ghost &g)
{
    c << "Ghost: " << g.Name << " (Scare Level: " << g.scarelevel << ")";
    return c;
}

class Visitor
{
private:
    string PersonName;
    int bravery;

public:
    Visitor(string n, int b) : PersonName(n), bravery(b)
    {
        if (bravery < 1)
        {
            bravery = 1;
        }
        else if (bravery > 10)
        {
            bravery = 10;
        }
    }

    friend void Visit(Visitor *visitors, int visitorCount, const HauntedHouse &house);

    void reactToGhost(Ghost &ghost) const
    {
        cout << PersonName << " sees ";
        ghost.haunt();
        int ghostScare = ghost.getScareLevel();

        if (bravery <= 4)
        { // Cowardly
            if (ghostScare <= 4)
            {
                cout << PersonName << " nervously laughs but stays.\n"
                     << endl;
            }
            else
            {
                cout << PersonName << " SCREAMS and runs away!\n"
                     << endl;
            }
        }
        else if (bravery <= 7)
        { // Average
            if (ghostScare <= 3)
            {
                cout << PersonName << " laughs at the ghost.\n"
                     << endl;
            }
            else if (ghostScare <= 7)
            {
                cout << PersonName << " Voice shakes as they talk.\n"
                     << endl;
            }
            else
            {
                cout << PersonName << " Yells and backs away!\n"
                     << endl;
            }
        }
        else
        { // Fearless (8-10)
            if (ghostScare <= 6)
            {
                cout << PersonName << " Taunts ghost.\n"
                     << endl;
            }
            else if (ghostScare <= 9)
            {
                cout << PersonName << " Concerned.\n"
                     << endl;
            }
            else
            {
                cout << PersonName << " Shows fear!\n"
                     << endl;
            }
        }
    }
};

class HauntedHouse
{
private:
    string HouseName;
    Ghost **ghostList;
    int ghostCount; // current
    int maxGhostCount;

public:
    HauntedHouse(string n, int m) : HouseName(n), ghostCount(0), maxGhostCount(m)
    {
        ghostList = new Ghost *[maxGhostCount];
    }

    void addghosts(Ghost *g)
    {
        if (!g)
        {
            cout << "Cannot add null ghost!" << endl;
            return;
        }
        if (ghostCount < maxGhostCount)
        {
            ghostList[ghostCount++] = g;
        }
        else
        {
            cout << "Cannot add more ghosts to " << HouseName << endl;
        }
    }
    ~HauntedHouse()
    {
        delete[] ghostList;
    }

    string getName() { return HouseName; }
    int getGhostCount() { return ghostCount; }
    Ghost *getGhost(int index) const
    {
        if (index >= 0 && index < ghostCount)
            return ghostList[index];
        else
        {
            return nullptr;
        }
    }

    friend void Visit(Visitor *visitors, int visitorCount, const HauntedHouse &house);
};

void Visit(Visitor *visitors, int visitorCount, const HauntedHouse &house)
{
    cout << "Visiting house " << house.HouseName << endl;
    for (int i = 0; i < visitorCount; i++)
    {
        cout << visitors[i].PersonName << " entering" << endl;
        for (int j = 0; j < house.ghostCount; j++)
        {
            if (house.ghostList[j])
            {
                house.ghostList[j]->haunt();
                visitors[i].reactToGhost(*house.ghostList[j]);
            }
        }
        cout << endl;
    }
}

int main()
{
    cout << "HAUNTED HOUSE SIMULATION" << endl;
    cout << "Simulating ghosts..." << endl;

    // Create some ghosts
    Ghost genericGhost("Weewoo", 3);
    Poltergeist poltergeist("Floaty", 7);
    Banshee banshee("Churail", 9);
    ShadowGhost shadow("Night", 4);
    ShadowPoltergeist hybrid("Necromancer", 6);

    // Test ghost operations
    cout << genericGhost << endl;
    cout << poltergeist << endl;
    cout << banshee << endl;
    cout << shadow << endl;
    cout << hybrid << endl
         << endl;

    // Test ghost combination
    cout << "operator overloading +" << endl;
    Ghost combined = poltergeist + banshee;
    cout << "Combined ghost: " << combined << endl
         << endl;

    // Test haunting
    cout << "HAUNTINGS" << endl;
    genericGhost.haunt();
    poltergeist.haunt();
    banshee.haunt();
    shadow.haunt();
    hybrid.haunt();

    // Create haunted houses
    HauntedHouse manor("Manor", 5);
    HauntedHouse asylum("Asylum", 3);

    // Add ghosts to houses
    manor.addghosts(&genericGhost);
    manor.addghosts(&poltergeist);
    manor.addghosts(&banshee);
    manor.addghosts(&shadow);
    manor.addghosts(&hybrid); // Testing max capacity
    cout << endl;

    asylum.addghosts(&shadow);
    asylum.addghosts(&hybrid);
    cout << endl;

    // Create visitors with different bravery levels
    cout << "Simulating visitors..." << endl;
    Visitor visitors[] = {
        Visitor("Timid Tim", 2),     // Cowardly
        Visitor("Average Amy", 5),   // Average
        Visitor("Brave Bob", 8),     // Brave
        Visitor("Fearless Fran", 10) // Fearless
    };

    int visitorCount = 4;
    cout << endl;

    // Simulate visits
    cout << "Simulating visit... " << endl;
    Visit(visitors, visitorCount, manor);
    Visit(visitors, visitorCount, asylum);

    // Test edge cases
    cout << "Null pointer Test" << endl;
    // Null ghost test
    manor.addghosts(nullptr);

    // Invalid index test
    Ghost *testGhost = manor.getGhost(10);
    if (!testGhost)
    {
        cout << "Correctly handled invalid ghost index" << endl;
    }

    return 0;
}
