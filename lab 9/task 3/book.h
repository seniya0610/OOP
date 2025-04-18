#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;

public:
    Book(string t, string a, string i);
    string getTitle();
    string getAuthor();
    string getISBN();
};

#endif
