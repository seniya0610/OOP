#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    float marks;
};

int main() {
    int count;
    
    cout << "Enter the number of students: ";
    cin >> count;

    Student* students = new Student[count];

    for (int i = 0; i < count; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "Marks: ";
        cin >> students[i].marks;
    }

    int i = 0;
    float highestMarks = students[0].marks;
    
    for (int index = 1; index < count; index++) {
        if (highestMarks < students[index].marks) {
            highestMarks = students[index].marks;
            i = index;
        }
    }

    cout << "\nStudent with the highest marks:\n";
    cout << "Name: " << students[i].name << "\n";
    cout << "Roll Number: " << students[i].rollNumber << "\n";
    cout << "Marks: " << students[i].marks << "\n";

    delete[] students;

    return 0;
}
