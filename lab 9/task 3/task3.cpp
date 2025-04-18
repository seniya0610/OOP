#include <iostream>
#include "book.h"
using namespace std;

class Library
{
private:
    Book *books[100]; // Fixed-size array
    int count;

public:
    Library() : count(0) {}

    void addBook(Book *book)
    {
        if (count < 100)
        {
            books[count] = book;
            count++;
        }
        else
        {
            cout << "Library is full!" << endl;
        }
    }

    void removeBook(string isbn)
    {
        bool found = false;
        for (int i = 0; i < count; i++)
        {
            if (books[i]->getISBN() == isbn)
            {
                for (int j = i; j < count - 1; j++)
                {
                    books[j] = books[j + 1];
                }
                count--;
                found = true;
                cout << "Book removed.\n";
                break;
            }
        }
        if (!found)
        {
            cout << "Book not found.\n";
        }
    }

    void searchBook(string title)
    {
        bool found = false;
        for (int i = 0; i < count; i++)
        {
            if (books[i]->getTitle() == title)
            {
                cout << "Book Found:\n";
                cout << "Title: " << books[i]->getTitle() << endl;
                cout << "Author: " << books[i]->getAuthor() << endl;
                cout << "ISBN: " << books[i]->getISBN() << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "Book not found.\n";
        }
    }
};

int main()
{
    Book book1("1984", "George Orwell", "9780451524935");

    cout << "Book Metadata:" << endl;
    cout << "Title: " << book1.getTitle() << endl;
    cout << "Author: " << book1.getAuthor() << endl;
    cout << "ISBN: " << book1.getISBN() << endl;

    Library lib;
    lib.addBook(&book1);
    lib.searchBook("1984");

    return 0;
}
