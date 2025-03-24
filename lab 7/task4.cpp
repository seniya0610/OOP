#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int id;
    string address;
    long long int PhoneNumber;
    string email;

public:
    Person(string n, int ID, string a, long long int pn, string e)
        : name(n), id(ID), address(a), PhoneNumber(pn), email(e) {}

    void setName(string n) { name = n; }
    string getName() const { return name; }
    
    void setId(int i) { id = i; }
    int getId() const { return id; }
    
    void setAddress(string addr) { address = addr; }
    string getAddress() const { return address; }
    
    void setPhoneNumber(long long int phone) { PhoneNumber = phone; }
    long long int getPhoneNumber() const { return PhoneNumber; }
    
    void setEmail(string e) { email = e; }
    string getEmail() const { return email; }

    void updateinfo(string n, int ID, string a, long long int pn, string e)
    {
        name = n;
        id = ID;
        address = a;
        PhoneNumber = pn;
        email = e;
    }

    virtual void displayinfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << PhoneNumber << endl;
        cout << "Email: " << email << endl;
    }
};

class Student : public Person
{
private:
    string coursesEnrolled[5]; // assuming max 5 courses
    int numCourses;
    float GPA;
    int enrollmentYear;

public:
    Student(string n, int i, string addr, long long int phone, string mail, float gpa, int year)
        : Person(n, i, addr, phone, mail), GPA(gpa), enrollmentYear(year), numCourses(0) {}

    void enrollCourse(string course)
    {
        if (numCourses < 5)
        {
            coursesEnrolled[numCourses++] = course;
        }
        else
        {
            cout << "Cannot enroll in more courses!" << endl;
        }
    }

    void displayinfo() override
    {
        Person::displayinfo();
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Courses Enrolled: ";
        for (int i = 0; i < numCourses; i++)
        {
            cout << coursesEnrolled[i];
            if (i < numCourses - 1) cout << ", ";
        }
        cout << endl;
    }
};

class Professor : public Person
{
private:
    string department;
    string coursesTaught[3]; // max 3 courses
    int numCourses;
    double salary;

public:
    Professor(string n, int i, string addr, long long int phone, string mail, string dept, double sal)
        : Person(n, i, addr, phone, mail), department(dept), salary(sal), numCourses(0) {}

    void addCourse(string course)
    {
        if (numCourses < 3)
        {
            coursesTaught[numCourses++] = course;
        }
        else
        {
            cout << "Cannot teach more courses" << endl;
        }
    }

    void displayinfo() override
    {
        Person::displayinfo();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
        cout << "Courses Taught: ";
        for (int i = 0; i < numCourses; i++)
        {
            cout << coursesTaught[i];
            if (i < numCourses - 1) cout << ", ";
        }
        cout << endl;
    }
};

class Staff : public Person
{
private:
    string department;
    string position;
    double salary;

public:
    Staff(string n, int i, string addr, long long int phone, string mail, string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayinfo() override
    {
        Person::displayinfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Course
{
private:
    int courseId;
    string courseName;
    int credits;
    Professor *instructor;
    string schedule;
    Student *registeredStudents[10]; // max 10 students
    int numStudents;

public:
    Course(int id, string name, int cr, Professor *instr, string sched)
        : courseId(id), courseName(name), credits(cr), instructor(instr), schedule(sched), numStudents(0) {}
    
    void registerStudent(Student *student)
    {
        if (numStudents < 10)
        {
            registeredStudents[numStudents++] = student;
            student->enrollCourse(courseName);
        }
        else
        {
            cout << "Course is full!" << endl;
        }
    }

    void calculateGrades()
    {
        cout << "Calculating grades for course: " << courseName << endl;
        for (int i = 0; i < numStudents; i++)
        {
            cout << "Grade calculated for student: " << registeredStudents[i]->getId() << endl;
        }
    }

    void displayCourseInfo()
    {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor->getName() << endl;
        cout << "Schedule: " << schedule << endl;
        cout << "Registered Students: " << numStudents << endl;
    }
};

int main()
{
    Professor prof("Dr. Smith", 1001, "123 University Ave", 5551234567, "smith@uni.edu", "Computer Science", 80000);
    Student student1("John Doe", 2001, "456 College St", 5559876543, "john@uni.edu", 3.5, 2023);
    Student student2("Jane Smith", 2002, "789 Campus Rd", 5554567890, "jane@uni.edu", 3.8, 2022);

    Course cs101(101, "Introduction to Programming", 4, &prof, "Mon/Wed 10:00-11:30");
    
    cs101.registerStudent(&student1);
    cs101.registerStudent(&student2);
    
    cout << "\nProfessor Information:\n";
    prof.displayinfo();
    
    cout << "\nStudent Information:\n";
    student1.displayinfo();
    
    cout << "\nCourse Information:\n";
    cs101.displayCourseInfo();
    
    cout << "\nCalculating Grades:\n";
    cs101.calculateGrades();

    return 0;
}
