#include <iostream>
using namespace std;

class Student;
class Teacher;

class Student
{
private:
    string name;
    string grade[3] = {}; // default initialization
public:
    Student(string n) : name(n) {}
    friend class Teacher;
    friend float Avg(Student &s);
};

class Teacher
{
private:
    string name;

public:
    Teacher(string n) : name(n) {}

    void updateGrades(Student &s, int i, string g)
    {
        if (i > -1 && i < 3)
        {
            s.grade[i] = g;
        }
    }

    void viewGrades(Student &s)
    {
        cout << "Grades for " << s.name << ":" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << s.grade[i] << endl;
        }
    }
};

float Avg(Student &s)
{
    cout << "Average for " << s.name << ":" << endl;

    float total = 0.0;
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        if (s.grade[i] == "A")
            total += 4.0;
        else if (s.grade[i] == "B")
            total += 3.0;
        else if (s.grade[i] == "C")
            total += 2.0;
        else if (s.grade[i] == "D")
            total += 1.0;
        else if (s.grade[i] == "F")
            total += 0.0;
        else
            continue;
        count++;
    }

    if (count == 0)
    {
        cout << "No valid grades available." << endl;
        return 0.0;
    }

    float avg = total / count;
    cout << "GPA: " << avg << endl;
    return avg;
}

int main()
{
    Student s("Sami");
    Teacher t("Talha");

    t.updateGrades(s, 0, "A");
    t.updateGrades(s, 1, "D");
    t.updateGrades(s, 2, "B");
    t.viewGrades(s);
    Avg(s);

    return 0;
}
