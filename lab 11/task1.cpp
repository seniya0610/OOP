#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
using namespace std;

class InvalidValueException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "invalid age";
    }
};

int main()
{
    try
    {
        int age;
        cout << "enter age" << endl;
        cin >> age;

        if (cin.fail())
        {
            cerr << "Error: Invalid input. Please enter a number." << endl;
            return 1;
        }
        
        if (age < 0 || age > 120)
        {
            throw InvalidValueException();
        }
        cout << "Age: " << age << endl;
    }
    catch (const InvalidValueException &e)
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown error" << endl;
        return 2;
    }

    return 0;
}
