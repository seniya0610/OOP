#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string ID;
    string title;
    string author;
    bool isAvailable;
} Book;

void display(Book books[], int bookcount) {
    for (int i = 0; i < bookcount; i++) {
        cout << "Book ID: " << books[i].ID << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Available: " << (books[i].isAvailable ? "Yes" : "No") << endl;
        cout << endl;
    }
}

Book* AddBook(Book* books, int& bookcount, Book newBook) {
    Book* newBooks = new Book[bookcount + 1];

    for (int i = 0; i < bookcount; i++) {
        newBooks[i] = books[i];
    }

    newBooks[bookcount] = newBook;
    bookcount++;

    delete[] books;

    return newBooks;
}

int search(Book books[], int count, string idToFind) {
    for (int i = 0; i < count; i++) {
        if (books[i].ID == idToFind) {
            cout << "Book found:\n";
            cout << "Book ID: " << books[i].ID << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Available: " << (books[i].isAvailable ? "Yes" : "No") << endl;
            cout << endl;
            return i;
        }
    }
    cout << "Book not found.\n";
    return -1;
}

Book* RemoveBook(Book* books, int& bookcount, string idToRemove) {
    int index = search(books, bookcount, idToRemove);
    
    if (index == -1) {
        cout << "Cannot remove: Book not found.\n";
        return books;
    }

    Book* newBooks = new Book[bookcount - 1];

    for (int i = 0, j = 0; i < bookcount; i++) {
        if (i != index) {
            newBooks[j++] = books[i];
        }
    }

    bookcount--;
    delete[] books;

    return newBooks;
}

int main() {
    int bookcount = 10;
    Book* books = new Book[bookcount] {
        {"B001", "The Great Gatsby", "F. Scott Fitzgerald", true},
        {"B002", "1984", "George Orwell", false},
        {"B003", "To Kill a Mockingbird", "Harper Lee", true},
        {"B004", "The Catcher in the Rye", "J.D. Salinger", true},
        {"B005", "Moby-Dick", "Herman Melville", false},
        {"B006", "Pride and Prejudice", "Jane Austen", true},
        {"B007", "The Hobbit", "J.R.R. Tolkien", false},
        {"B008", "The Odyssey", "Homer", true},
        {"B009", "Brave New World", "Aldous Huxley", false},
        {"B010", "Crime and Punishment", "Fyodor Dostoevsky", true}
    };

    cout << "Before adding a new book:\n";
    display(books, bookcount);

    Book newBook = {"B011", "The Lord of the Rings", "J.R.R. Tolkien", true};
    books = AddBook(books, bookcount, newBook);
    cout << "\nAfter adding a new book:\n";
    display(books, bookcount);

    string idToFind;
    cout << "Enter Book ID to find: ";
    cin >> idToFind;

    int index = search(books, bookcount, idToFind);

    if (index != -1) {
        cout << "\nRemoving book with ID: " << idToFind << endl;
        books = RemoveBook(books, bookcount, idToFind);
        cout << "\nAfter removal:\n";
        display(books, bookcount);
    }

    delete[] books;
    return 0;
}
