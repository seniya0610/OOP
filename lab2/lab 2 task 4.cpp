#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string rollnumber;
    int age;
    float marks[5];
};

struct Result {
    float average;
    char grade;
};

void display(Student arr[], int count, Result arr2[]) {
    cout << "\nStudent Details:\n";
    for (int i = 0; i < count; i++) {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << arr[i].name << endl;
        cout << "Roll Number: " << arr[i].rollnumber << endl;
        cout << "Age: " << arr[i].age << endl;
        cout << "Marks: ";
        for (int j = 0; j < 5; j++) {
            cout << "Subject " << j+1 << ": " << arr[i].marks[j] << endl;
        }
        cout << "Average: " << arr2[i].average << endl;
        cout << "Grade: " << arr2[i].grade << endl;
        cout << endl;
    }
}

Result* Results(Student arr[], int count) {
    
    Result* results = new Result[count];
    for (int i = 0; i < count; i++) {
        float sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += arr[i].marks[j];
        }
        results[i].average = sum / 5;

        if (results[i].average >= 90) {
            results[i].grade = 'A';
        } else if (results[i].average >= 80) {
            results[i].grade = 'B';
        } else if (results[i].average >= 70) {
            results[i].grade = 'C';
        } else if (results[i].average >= 60) {
            results[i].grade = 'D';
        } else {
            results[i].grade = 'F';
        }
    }

    return results;
}

int main() {
    int count;
    cout << "Enter number of students: ";
    cin >> count;

    Student* arr = new Student[count];

    for (int i = 0; i < count; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Roll Number: ";
        cin >> arr[i].rollnumber;
        cout << "Name: ";
        cin >> arr[i].name;
        cout << "Age: ";
        cin >> arr[i].age;
        for (int j = 0; j < 5; j++) {
            cout << "Marks for subject " << j + 1 << ": ";
            cin >> arr[i].marks[j];
        }
    }
    
    Result* Rarr = Results(arr, count);
    display(arr, count, Rarr);
    delete[] arr;
    delete[] Rarr;

    return 0;
}
