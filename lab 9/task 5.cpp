#include <iostream>
#include <string>
using namespace std;

class Activity
{
public:
    virtual double calculateCaloriesBurned(float weight) = 0;
    virtual ~Activity() {}
    virtual string getActivityName() = 0;
};

class Running : public Activity
{
private:
    double distance;
    double time;
    string name;

public:
    Running(double dist, double t) : distance(dist), time(t), name("Running") {}

    double calculateCaloriesBurned(float weight) override
    {
        // Simplified formula: calories = distance * weight * factor
        return distance * weight * 1.036; // Assuming 70kg, factor 1.036
    }

    string getActivityName() override
    {
        return name;
    }
};

class Cycling : public Activity
{
private:
    double speed; // in km/h
    double time;  // in hours
    string name;

public:
    Cycling(double spd, double t) : speed(spd), time(t), name("Cycling") {}

    double calculateCaloriesBurned(float weight) override
    {
        // Simplified formula: calories = speed * time * weight * factor
        return speed * time * weight * 0.28; // Assuming 70kg, factor 0.28
    }

    string getActivityName() override
    {
        return name;
    }
};

int main()
{

    Activity *running = new Running(5.0, 30.0); // 5km in 30 mins
    Activity *cycling = new Cycling(20.0, 1.5); // 20km/h for 1.5 hours
    float w = 70;

    cout << "Activity: " << running->getActivityName()
         << "\nCalories burned: " << running->calculateCaloriesBurned(w)
         << " kcal\n";

    cout << "Activity: " << cycling->getActivityName()
         << "\nCalories burned: " << cycling->calculateCaloriesBurned(w)
         << " kcal\n";

    delete running;
    delete cycling;

    return 0;
}
