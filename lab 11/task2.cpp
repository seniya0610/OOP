#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
using namespace std;

class StackOverFlowException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "stack is full";
    }
};

class StackUnderFlowException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "stack is empty";
    }
};

template <typename T>
class Stack
{
    T array[5];
    int topIndex;

public:
    Stack()
    {
        topIndex = -1;
    }

    void push(T val)
    {
        if (topIndex >= 4)
        {
            throw StackOverFlowException();
        }
        array[++topIndex] = val;
    }

    T pop()
    {
        if (topIndex == -1)
        {
            throw StackUnderFlowException();
        }
        return array[topIndex--];
    }
};

int main()
{

    Stack<int> stack;
    try
    {
        for (int i = 0; i < 6; i++)
        { // Will throw on 5th push
            stack.push(i);
            cout << "Pushed: " << i << endl;
        }
    }
    catch (const StackOverFlowException &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    try
    {
        for (int i = 0; i < 6; i++)
        {
            cout << "Popped: " << stack.pop() << endl;
        }
    }
    catch (StackUnderFlowException &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}
