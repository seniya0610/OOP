#include <iostream>
using namespace std;

class Book;
class Librarian;

class Book
{
private:
    string title;
    double price;

public:
    Book(string t, double p) : title(t), price(p) {}

    double getprice() { return price; }

    friend class Librarian;
};

class Librarian
{
private:
    string name;

public:
    Librarian(string n) : name(n) {}

    double ApplyDiscounts(Book b)
    {
        b.price -= 200; // discount of 20rps
        return b.price;
    }
};

int main()
{
    Book b("The Great Gatsby", 1000);
    Librarian L("linda");
    cout << "original Price: " << b.getprice() << endl;
    double newprice = L.ApplyDiscounts(b);
    cout << "New Price: " << newprice << endl;
}
