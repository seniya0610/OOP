#include "book.h"

Book::Book(string t, string a, string i) {
    title = t;
    author = a;
    ISBN = i;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

string Book::getISBN() {
    return ISBN;
}
