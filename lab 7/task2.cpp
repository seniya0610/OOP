#include <iostream>
#include <string.h>
using namespace std;

class Shape
{
    int position;
    string color;
    float borderthickness;

public:
    Shape(int p, string c, float bw) : position(p), color(c), borderthickness(bw) {}

    virtual void draw()
    {
        cout << "rendering shape..." << endl;
    }

    virtual double calculateArea()
    {
        cout << "calculating area..." << endl;
        return 0.0;
    }

    virtual double calculatePerimeter()
    {
        cout << "calculating perimeter..." << endl;
        return 0.0;
    }
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(int p, string c, float bw, float r) : Shape(p, c, bw), radius(r) {}

    void draw() override
    {
        cout << "Drawing Circle with radius " << radius << endl;
    }

    double calculateArea() override
    {
        return 3.14159 * radius * radius;
    }

    double calculatePerimeter() override
    {
        return 2 * 3.14159 * radius;
    }
};

class Rectangle : public Shape
{
private:
    float width, height;

public:
    Rectangle(int p, string c, float bw, float w, float h) : Shape(p, c, bw), width(w), height(h) {}

    void draw() override
    {
        cout << "Drawing Rectangle with width " << width << " and height " << height << endl;
    }

    double calculateArea() override
    {
        return width * height;
    }

    double calculatePerimeter() override
    {
        return 2 * (width + height);
    }
};

class Triangle : public Shape
{
private:
    float base, height;

public:
    Triangle(int p, string c, float bw, float b, float h) : Shape(p, c, bw), base(b), height(h) {}

    void draw() override
    {
        cout << "Drawing Triangle with base " << base << " and height " << height << endl;
    }

    double calculateArea() override
    {
        return 0.5 * base * height;
    }

    double calculatePerimeter() override
    {
        return 3 * base;
    }
};

int main()
{
    Circle c1(20, "red", 2.5, 8);
    c1.draw();
    cout << "Area: " << c1.calculateArea() << endl;
    cout << "Perimeter: " << c1.calculatePerimeter() << endl;

    Rectangle rectangle(20, "Blue", 1.5, 4.0, 6.0);
    rectangle.draw();
    cout << "Area: " << rectangle.calculateArea() << endl;
    cout << "Perimeter: " << rectangle.calculatePerimeter() << endl;

    Triangle triangle(30, "Green", 2.0, 3.0, 4.0);
    triangle.draw();
    cout << "Area: " << triangle.calculateArea() << endl;
    cout << "Perimeter: " << triangle.calculatePerimeter() << endl;

    return 0;
}
