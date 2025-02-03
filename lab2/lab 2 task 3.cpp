#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string id;
    string name;
    string dept;
    double salary;
} Employee;

void display(Employee arr[], int count) {
    cout << "\nEmployee Details:\n";
    for (int i = 0; i < count; i++) {
        cout << "Employee " << i + 1 << ":\n";
        cout << "ID: " << arr[i].id << endl;
        cout << "Name: " << arr[i].name << endl;
        cout << "Department: " << arr[i].dept << endl;
        cout << "Salary: " << arr[i].salary << endl;
        cout << "\n";
    }
}

void search(Employee arr[], int count, string tofind) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (arr[i].id == tofind) {
            found = true;
            cout << "Employee " << i + 1 << ":\n";
            cout << "ID: " << arr[i].id << endl;
            cout << "Name: " << arr[i].name << endl;
            cout << "Department: " << arr[i].dept << endl;
            cout << "Salary: " << arr[i].salary << endl;
            cout << "\n";
        }
    }
    if (!found) {
        cout << "Employee not found" << endl;
    }
}

int main() {
    int count;

    cout << "Enter number of employees: ";
    cin >> count;
    cout << endl;

    Employee* arr = new Employee[count];

    for (int i = 0; i < count; i++) {
        cout << "Enter details for Employee " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> arr[i].id;
        cout << "Name: ";
        cin >> arr[i].name;
        cout << "Department: ";
        cin >> arr[i].dept;
        cout << "Salary: ";
        cin >> arr[i].salary;
        cout << endl;
    }

    display(arr, count);

    string tofind;
    cout << "Enter ID to search for: ";
    cin >> tofind;

    search(arr, count, tofind);

    delete[] arr;

    return 0;
}