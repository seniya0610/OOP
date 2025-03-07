#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	string name;
	int age;

public:
	Person(string n, int a) : name(n), age(a) {}

	void displaydetails() const
	{
		cout << "Name: " << name << ", Age: " << age << endl;
	}
};

class Teacher : virtual public Person
{
private:
	string subject;

public:
	Teacher(string s, string name, int age) : Person(name, age), subject(s) {}

	void displaydetails() const
	{
		Person::displaydetails();
		cout << "Subject: " << subject << endl;
	}
};


class Researcher : virtual public Person
{
private:
	string researchArea;

public:
	Researcher(string ra, string name, int age) : Person(name, age), researchArea(ra) {}

	void displaydetails() const
	{
		Person::displaydetails();
		cout << "Research Area: " << researchArea << endl;
	}
};

class Professor : public Teacher, public Researcher
{
private:
	int publications;

public:
	Professor(string name, int age, string subject, string researchArea, int pub)
		: Person(name, age), Teacher(subject, name, age), Researcher(researchArea, name, age), publications(pub) {}

	void displaydetails() const
	{
		Person::displaydetails();
		Teacher::displaydetails();
		Researcher::displaydetails();
		cout << "Publications: " << publications << endl;
	}
};

int main()
{
	Professor p1("Dr. Smith", 50, "Physics", "Quantum Mechanics", 30);
	p1.displaydetails();

	return 0;
}
