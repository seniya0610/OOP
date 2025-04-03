#include <iostream>
#include <string>
using namespace std;

class Assignment;
class User;
class Student;
class TA;
class Professor;

int generateHash(string s)
{
    int length = s.length();
    int hash = 5381;

    for (int i = 0; i < length; i++)
    {
        hash = hash * 33 + s[i];
    }

    return hash;
}

class Assignment
{
private:
    string title;
    int status;

public:
    Assignment() : title(""), status(0) {}
    Assignment(string t) : title(t), status(0) {}

    string getTitle() const { return title; }
    int getStatus() const { return status; }

    void setStatus(int s)
    {
        if (s == 0 || s == 1)
            status = s;
    }

    friend class Student;
    friend class TA;
};

class User
{
protected:
    string name;
    int id;
    string *PermissionsList;
    int permissionCount;
    string email;

private:
    int Password;

public:
    User(string n, int i, string *perms, int permCount, string e, string pass)
        : name(n), id(i), permissionCount(permCount), email(e)
    {
        PermissionsList = new string[permCount];
        for (int i = 0; i < permCount; i++)
        {
            PermissionsList[i] = perms[i];
        }
        Password = generateHash(pass);
    }

    virtual ~User()
    {
        delete[] PermissionsList;
    }

    virtual void display()
    {
        cout << "Name: " << name << "\nID: " << id << "\nEmail: " << email << endl;
        cout << "Permissions: ";
        for (int i = 0; i < permissionCount; i++)
        {
            cout << PermissionsList[i] << " ";
        }
        cout << endl;
    }

    bool authenticate(string pass)
    {
        return Password == generateHash(pass);
    }

    virtual bool hasPermission(string action)
    {
        for (int i = 0; i < permissionCount; i++)
        {
            if (PermissionsList[i] == action)
                return true;
        }
        return false;
    }

    int getPassword()
    {
        return Password;
    }
    string getname() { return name; }

    virtual bool access(string action)
    {
        if (hasPermission(action))
        {
            cout << name << " performing " << action << endl;
            return true;
        }
        cout << name << " does not have permission to perform " << action << endl;
        return false;
    }
};

class Professor : public User
{
public:
    Professor(string n, int i, string *perms, int pc, string e, string pass)
        : User(n, i, perms, pc, e, pass) {}

    void display() override
    {
        cout << "PROFESSOR INFORMATION:" << endl;
        User::display();
    }

    void CreateAssignment(Student &, Assignment);
    void CreateProject(TA &, string);
};

class Student : public User
{
protected:
    Assignment *assignments;
    int assignmentCount;
    int maxAssignments;

public:
    Student(string n, int i, string *perms, int permCount, string e, string pass, int maxAssign)
        : User(n, i, perms, permCount, e, pass), maxAssignments(maxAssign), assignmentCount(0)
    {
        assignments = new Assignment[maxAssignments];
        for (int i = 0; i < maxAssignments; i++)
        {
            assignments[i] = Assignment();
        }
    }

    ~Student()
    {
        delete[] assignments;
    }

    void submission(string title)
    {
        for (int i = 0; i < assignmentCount; i++)
        {
            if (assignments[i].getTitle() == title && assignments[i].getTitle() != "")
            {
                assignments[i].setStatus(1);
                cout << "Assignment Submitted" << endl;
                return;
            }
        }
        cout << "Assignment does not exist hence submission not recorded" << endl;
    }

    void submission(int index)
    {
        if (index >= assignmentCount || index < 0 || assignments[index].getTitle() == "")
        {
            cout << "Index does not exist" << endl;
            return;
        }
        assignments[index].setStatus(1);
        cout << "Assignment Submitted" << endl;
    }

    void toggleStatus(int index)
    {
        if (index >= assignmentCount || index < 0 || assignments[index].getTitle() == "")
        {
            cout << "Index does not exist" << endl;
            return;
        }
        assignments[index].setStatus(!assignments[index].getStatus());
        cout << "Status toggled successfully" << endl;
    }

    void display() override
    {
        cout << "STUDENT INFORMATION:" << endl;
        User::display();
        if (hasPermission("view_assignments"))
        {
            cout << "Assignments for Student " << name << endl;
            for (int i = 0; i < assignmentCount; i++)
            {
                if (assignments[i].getTitle() != "")
                {
                    cout << i << ": " << assignments[i].getTitle() << ": "
                         << (assignments[i].getStatus() ? "Submitted" : "Pending") << endl;
                }
            }
        } else {
            cout << "Access denied to view assignments" << endl;
        }
    }

    friend void Professor::CreateAssignment(Student &, Assignment);
    string getname() const { return name; }
};

class TA : public Student
{
private:
    Student *students[10]; // Max 10 students
    int studentCount;
    string projects[2]; // Max 2 projects
    int projectCount;

public:
    TA(string n, int i, string *perms, int pc, string e, string pass, int maxAssign)
        : Student(n, i, perms, pc, e, pass, maxAssign), studentCount(0), projectCount(0) {}

    bool addStudent(Student *s)
    {
        if (studentCount < 10 && hasPermission("manage_students"))
        {
            students[studentCount++] = s;
            cout << "Student " << s->getname() << " assigned to TA " << name << endl;
            return true;
        }
        cout << "Cannot assign more students (max 10) or missing permissions." << endl;
        return false;
    }

    void viewProjects()
    {
        if (hasPermission("view_projects"))
        {
            cout << "Projects assigned to TA " << name << ":" << endl;
            for (int i = 0; i < projectCount; i++)
            {
                cout << "- " << projects[i] << endl;
            }
        }
        else
        {
            cout << "Access denied to view projects" << endl;
        }
    }

    bool startProject(string projectName)
    {
        if (projectCount < 2 && hasPermission("view_projects"))
        {
            projects[projectCount++] = projectName;
            cout << "TA " << name << " started project: " << projectName << endl;
            return true;
        }
        cout << "Cannot start project (max 2) or missing permissions." << endl;
        return false;
    }

    bool removeStudent(Student *s)
    {
        if (hasPermission("manage_students"))
        {
            for (int i = 0; i < studentCount; i++)
            {
                if (students[i] == s)
                {
                    for (int j = i; j < studentCount - 1; j++)
                    {
                        students[j] = students[j + 1];
                    }
                    studentCount--;
                    cout << "Student " << s->getname() << " removed from TA " << name << endl;
                    return true;
                }
            }
            cout << "Student " << s->getname() << " not found under TA " << name << endl;
        }
        return false;
    }

    void display() override
    {
        cout << "TA INFORMATION:" << endl;
        Student::display();
        if (hasPermission("manage_students"))
        {
            cout << "Managing " << studentCount << " students:" << endl;
            for (int i = 0; i < studentCount; i++)
            {
                cout << "  " << i << ": " << students[i]->getname() << endl;
            }
        }
        viewProjects();
    }

    friend void Professor::CreateProject(TA &, string);
};

void Professor::CreateProject(TA &ta, string projectTitle)
{
    if (hasPermission("assign_projects"))
    {
        if (ta.projectCount < 2)
        {
            ta.projects[ta.projectCount++] = projectTitle;
            cout << "Project \"" << projectTitle << "\" assigned to TA "
                 << ta.getname() << " by Professor " << name << endl;
        }
        else
        {
            cout << "Cannot assign project to TA " << ta.getname()
                 << " - already has 2 projects" << endl;
        }
    }
    else
    {
        cout << "Permission denied" << endl;
    }
}

void Professor::CreateAssignment(Student &s, Assignment A)
{
    if (hasPermission("create_assignments"))
    {
        if (s.assignmentCount < s.maxAssignments)
        {
            s.assignments[s.assignmentCount++] = A;
            cout << "Assignment \"" << A.getTitle()
                 << "\" created for " << s.name << endl;
        }
        else
        {
            cout << "Cannot add more assignments for " << s.name
                 << " (maximum reached)" << endl;
        }
    }
    else
    {
        cout << "Permission denied (requires create_assignments)" << endl;
    }
}

bool authenticateAndPerformAction(User *user, string action, string password)
{
    if (!user->authenticate(password))
    {
        cout << "Authentication failed for " << user->getname() << endl;
        return false;
    }
    return user->access(action);
}

int main() {
    string studentPerms[] = {"submit_assignment", "view_assignments"};
    string taPerms[] = {"submit_assignment", "view_assignments", "view_projects", "manage_students"};
    string profPerms[] = {"assign_projects", "full_lab_access", "create_projects", 
                         "create_assignments", "submit_assignment", "view_assignments",
                         "view_projects", "manage_students"};

    // Create users with correct permission counts
    Student alice("Alice Smith", 1001, studentPerms, 2, "alice@uni.edu", "student123", 5);
    TA bob("Bob Johnson", 2001, taPerms, 4, "bob@uni.edu", "ta456", 5);
    Professor drLee("Dr. Lee", 3001, profPerms, 8, "lee@uni.edu", "prof789");
    cout << "\n--- Testing Authentication ---\n";
    cout << "Alice auth (correct): " << alice.authenticate("student123") << endl;
    cout << "Alice auth (wrong): " << alice.authenticate("wrongpass") << endl;

    cout << "\n--- Assignment Creation ---\n";
    authenticateAndPerformAction(&drLee, "create_assignments", "prof789");
    drLee.CreateAssignment(alice, Assignment("Lab 1"));
    drLee.CreateAssignment(alice, Assignment("Lab 2"));
    drLee.CreateAssignment(alice, Assignment("Final Project"));

    cout << "\n--- Assignment Submission ---\n";
    authenticateAndPerformAction(&alice, "submit_assignment", "student123");
    alice.submission("Lab 1");
    alice.submission(1); // Submit Lab 2 by index
    alice.display();

    cout << "\n--- TA Student Management ---\n";
    authenticateAndPerformAction(&bob, "manage_students", "ta456");
    bob.addStudent(&alice);
    bob.display();

    cout << "\n--- Project Assignment ---\n";
    authenticateAndPerformAction(&drLee, "assign_projects", "prof789");
    drLee.CreateProject(bob, "Compiler Design");
    drLee.CreateProject(bob, "AI Research");
    drLee.CreateProject(bob, "Database Systems"); 

    cout << "\n--- TA Project View ---\n";
    authenticateAndPerformAction(&bob, "view_projects", "ta456");
    bob.viewProjects();

    cout << "\n--- Permission Tests ---\n";
    authenticateAndPerformAction(&alice, "manage_students", "student123");
    authenticateAndPerformAction(&bob, "create_assignments", "ta456");
    authenticateAndPerformAction(&drLee, "submit_assignment", "prof789");

    cout << "\n--- Final User States ---\n";
    alice.display();
    cout << endl;
    bob.display();
    cout << endl;
    drLee.display();

    return 0;
}
