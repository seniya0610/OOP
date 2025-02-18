#include <iostream>
#include <string>
using namespace std;

class Student;
class Mentor;
class Sport;
class Skill;

//skill class
class Skill {
private:
	int skillID;
	string skillName;
	string description;

public:

	Skill() { //default constructor
		skillID = 0;
		skillName = "";
		description = "";
	}

	Skill(int ID, string name, string d) { //parameterized constructor
		skillID = ID;
		skillName = name;
		description = d;
	}

	void display() const {
		cout << "Skill ID: " << skillID << endl;
		cout << "Skill Name: " << skillName << endl;
		cout << "Description: " << description << endl;
	}

	void updateSkillDescription(string newDescription) {
		description = newDescription;
		cout << "Skill description updated.\n";
	}

	int getSkillID() const {
		return skillID;
	}

	string getSkillName() const {
		return skillName;
	}

	string getSkillDescription() const {
		return description;
	}
};

class Sport {
private:
	int sportID;
	string name;
	string description;
	Skill requiredSkills[3];
	int skillCount;

public:

	Sport(int id, string n, string d) {
		sportID = id;
		name = n;
		description = d;
		skillCount = 0;
	}

	Sport() {
		sportID = 0;
		name = "";
		description = "";
		skillCount = 0;
	}

	string get_name() {
		return name;
	}

	void addSkill(Skill s) {
		if (skillCount < 3) {
			requiredSkills[skillCount] = s;
			skillCount++;
			cout << "Skill added to " << name << ".\n";
		} else {
			cout << "Cannot add more skills\n";
		}
	}

	void removeSkill(int sID) {
		for (int i = 0; i < skillCount; i++) {
			if (requiredSkills[i].getSkillID() == sID) {
				for (int j = i; j < skillCount - 1; j++) {
					requiredSkills[j] = requiredSkills[j + 1];
				}
				skillCount--;
				cout << "Skill removed.\n";
				return;
			}
		}
		cout << "Skill not found.\n";
	}

	void showSportDetails() const {
		cout << "Sport ID: " << sportID << endl;
		cout << "Name: " << name << endl;
		cout << "Description: " << description << endl;
		cout << "Required Skills:\n";
		for (int i = 0; i < skillCount; i++) {
			requiredSkills[i].display();
		}
	}

	int getSportID() const {
		return sportID;
	}
};

class Mentor {
private:
	int mentorID;
	string name;
	Sport sportsExpertise[3];
	int expertiseCount;
	int maxLearners;
	Student* assignedLearners[5];
	int learnerCount;

public:
	Mentor() {
		mentorID = 0;
		name = "Unknown Mentor";
		maxLearners = 5;
		learnerCount = 0;
		expertiseCount = 0;
		for (int i = 0; i < 5; i++) {
			assignedLearners[i] = 0;
		}
	}

	Mentor(int id, string N, Sport expertise[], int max, int e, int l) {
		mentorID = id;
		name = N;
		maxLearners = max;
		learnerCount = l;
		expertiseCount = e;
		for (int i = 0; i < expertiseCount; i++) {
			sportsExpertise[i] = expertise[i];
		}
		for (int i = 0; i < learnerCount; i++) {
			assignedLearners[i] = 0;
		}
	}

	void display()
	{
		cout << "Mentor Id: " << mentorID << endl << "Mentor Name: " << name << endl;
		for (int i = 0; i < expertiseCount; i++) {
			cout << "Mentor expertise " << i + 1 << ":" << sportsExpertise[i].get_name() << endl;
		}
	}
	void assignLearner(Student* s) {
		if (learnerCount < maxLearners) {
			assignedLearners[learnerCount++] = s;
			cout << "Student assigned to mentor.\n";
		} else {
			cout << "Cannot assign more learners.\n";
		}
    }

    void removeLearner(Student* s) {
        for (int i = 0; i < learnerCount; i++) {
            if (assignedLearners[i] == s) {
                for (int j = i; j < learnerCount - 1; j++) {
                    assignedLearners[j] = assignedLearners[j+1];
                }
                learnerCount--;
                assignedLearners[learnerCount] = nullptr; // Clear the last pointer
                cout << "Student removed from mentor.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void viewLearners();

	void provideGuidance() {

        cout << "Mentor " << name << " is providing guidance." << endl;

    }

	string get_name() {
		return name;
	}
};

class Student {
private:
	int studentID;
	string name;
	int age;
	Sport sportsInterest[3];
	int interestCount;
	Mentor* mentorAssigned;

public:
	Student() {
		studentID = 0;
		name = "Unknown Student";
		age = 0;
		interestCount = 0;
		for (int i = 0; i < 3; i++)
		{
			sportsInterest[i] = Sport();
		}
	}

	Student(int id, string n, int a, int c, Mentor *m) {
		studentID = id;
		name = n;
		age = a;
		interestCount = c;
		mentorAssigned = m;
		for (int i = 0; i < interestCount; i++) {
			sportsInterest[i] = Sport();
		}
	}

	void updateSportsInterest(Sport s)
	{
		sportsInterest[interestCount++] = s;

	}

    void display(){
        cout << "Student's ID: " << studentID << endl;
        cout << "Student's Name: " << name << endl;
        cout << "Age: " << age << endl;
    }


	void registerForMentorship(Mentor *m) {
		cout << "registering for mentorship under " << m->get_name() << endl;
		mentorAssigned = m;
	}
	void viewMentorDetails() {

		mentorAssigned->display();

	}

    string getName()
    {
        return name;
    }
};

void Mentor::viewLearners() {
    if (learnerCount == 0) {
        cout << "No learners assigned." << endl;
        return;
    }
    for (int i = 0; i < learnerCount; i++) {
        if (assignedLearners[i] != nullptr) {
            assignedLearners[i]->display();
        } else {
            cout << "Learner at index " << i << " is nullptr." << endl;
        }
    }
}

int main() {
	// Creating Skills
	Skill skill1(1, "Serving", "Learn how to serve accurately.");
	Skill skill2(2, "Forehand", "Master the forehand stroke.");
	Skill skill3(3, "Backhand", "Learn the backhand stroke.");
	Skill skill4(4, "Volley", "Learn how to volley effectively.");

	cout << "---- Skill Tests ----\n";
	skill1.display();
	skill1.updateSkillDescription("Improve accuracy in serving.");
	skill1.display();
	cout << endl;

	// Creating a Sport and adding skills
	cout << "---- Sport Tests ----\n";
	Sport tennis(101, "Tennis", "A racket sport played individually or in pairs.");
	tennis.addSkill(skill1);
	tennis.addSkill(skill2);
	tennis.addSkill(skill3);
	tennis.showSportDetails();

	// Removing a skill and displaying sport details again
	tennis.removeSkill(2);
	tennis.showSportDetails();
	cout << endl;

	// Creating another sport
	Sport basketball(102, "Basketball", "A sport involving dribbling, passing, and shooting.");
	basketball.addSkill(skill4);
	basketball.showSportDetails();
	cout << endl;

	// Creating a Mentor
	cout << "---- Mentor Tests ----\n";
	Sport mentorExpertise[] = {tennis, basketball};
	Mentor mentor1(201, "Coach John", mentorExpertise, 5, 2, 0);
	mentor1.display();
	cout << endl;

	// Creating a Student and registering for mentorship
	cout << "---- Student Tests ----\n";
	Student student1(301, "Alice", 20, 1, nullptr);
	student1.updateSportsInterest(tennis);
	student1.registerForMentorship(&mentor1);
	student1.viewMentorDetails();

	return 0;
}

