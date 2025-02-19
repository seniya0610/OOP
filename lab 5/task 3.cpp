#include <iostream>
#include <string>

using namespace std;

class Professor {
private:
    string name;
    string department;

public:
    Professor(string n, string d) {
        name = n;
        department = d;
    }

    Professor() {
        name = "";
        department = "";
    }

    string getName() {
        return name;
    }

    string getDepartment() {
        return department;
    }
};

class University {
private:
    string name;
    Professor* professors;
    int count;
    int max = 100;

public:
    University(string n) {
        name = n;
        count = 0;
        professors = new Professor[max];
    }

    ~University() {
        delete[] professors;
    }

    void display() {
        cout << "University Details" << endl;
        cout << "Name: " << name << endl;
        cout << "Professor List: " << endl;
        for (int i = 0; i < count; i++) {
            cout << "Professor " << (i + 1) << ": " << endl;
            cout << "  Name: " << professors[i].getName() << endl;
            cout << "  Department: " << professors[i].getDepartment() << endl;
        }
    }

    void addProfessor(Professor& p) {
        if (count < max) {
            professors[count] = p;
            count++;
        } else {
            cout << "Cannot add more professors." << endl;
        }
    }
};

int main() {

    University uni("Fast");

    Professor p1("Talha Shahid", "Cyber Security");
    Professor p2("Muhammad Rahim", "Computer Science");

    uni.addProfessor(p1);
    uni.addProfessor(p2);

    uni.display();

    return 0;
}
